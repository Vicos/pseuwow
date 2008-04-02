#include "common.h"
#include "log.h"
#include "MapTile.h"
#include "MapMgr.h"

void MakeMapFilename(char *fn, uint32 m, uint32 x, uint32 y)
{
    sprintf(fn,"./data/maps/%u_%u_%u.adt",m,x,y);
}

bool TileExistsInFile(uint32 m, uint32 x, uint32 y)
{
    char buf[50];
    MakeMapFilename(buf,m,x,y);
    return GetFileSize(buf);
}


MapMgr::MapMgr()
{
    DEBUG(logdebug("Creating MapMgr with TILESIZE=%.3f CHUNKSIZE=%.3f UNITSIZE=%.3f",TILESIZE,CHUNKSIZE,UNITSIZE));
    _tiles = new MapTileStorage();
    _gridx = _gridy = _mapid = (-1);
    _mapsLoaded = false;
}

MapMgr::~MapMgr()
{
    Flush();
    delete _tiles;
}

void MapMgr::Update(float x, float y, uint32 m)
{
    if(m != _mapid)
    {
        Flush(); // we teleported to a new map, drop all loaded maps
        WDTFile *wdt = new WDTFile();
        char buf[100];
        sprintf(buf,"data/maps/%u.wdt",m);
        if(!wdt->Load(buf))
        {
            logerror("MAPMGR: Could not load WDT file '%s'",buf);
        }
        _tiles->ImportTileMap(wdt);
        delete wdt;
        _mapid = m;
        _gridx = _gridy = (-1); // must load tiles now
    }
    GridCoordPair gcoords = GetTransformGridCoordPair(x,y);
    if(gcoords.x != _gridx || gcoords.y != _gridy)
    {
        _gridx = gcoords.x;
        _gridy = gcoords.y;
        _LoadNearTiles(_gridx,_gridy,m);
        _UnloadOldTiles();
    }
}

void MapMgr::Flush(void)
{
    _mapsLoaded = false;
    for(uint32 i = 0; i < 4096; i++)
        _tiles->UnloadMapTile(i);
    logdebug("MAPMGR: Flushed all maps");
}

void MapMgr::_LoadNearTiles(uint32 gx, uint32 gy, uint32 m)
{
    logdebug("MAPMGR: Loading near tiles for (%u, %u) map %u",gx,gy,m);
    for(uint32 v = gy-1; v <= gy+1; v++)
    {
        for(uint32 h = gx-1; h <= gx+1; h++)
        {
            _LoadTile(h,v,m);
        }
    }
    _mapsLoaded = true;
}

void MapMgr::_LoadTile(uint32 gx, uint32 gy, uint32 m)
{
    if(!_tiles->TileExists(gx,gy))
    {
        if(TileExistsInFile(m,gx,gy))
        {
            logerror("MapMgr: Tile (%u, %u) exists not in WDT, but as file?!",gx,gy);
            // continue loading...
        }
        else
        {
            logerror("MAPMGR: Not loading MapTile (%u, %u) map %u, no entry in WDT tile map",gx,gy,m);
            return;
        }
    }

    if( !_tiles->GetTile(gx,gy) )
    {
        ADTFile *adt = new ADTFile();
        char buf[300];
        MakeMapFilename(buf,m,gx,gy);
        if(adt->Load(buf))
        {
            logdebug("MAPMGR: Loaded ADT '%s'",buf);
            MapTile *tile = new MapTile();
            tile->ImportFromADT(adt);
            _tiles->SetTile(tile,gx,gy);
            logdebug("MAPMGR: Imported MapTile (%u, %u) for map %u",gx,gy,m);
        }
        else
        {
            logerror("MAPMGR: Loading ADT '%s' failed!",buf);
        }
        delete adt;
    }
    else
    {
        logdebug("MAPMGR: No need to load MapTile (%u, %u) map %u",gx,gy,m);
    }
}

void MapMgr::_UnloadOldTiles(void)
{
    for(uint32 gy=0; gy<64; gy++)
    {
        for(uint32 gx=0; gx<64; gx++)
        {
            if( (_gridx < gx-1 || _gridx > gx+1) && (_gridy < gy-1 || _gridy > gy+1) )
            {
                if(_tiles->GetTile(gx,gy))
                {
                    logdebug("MAPMGR: Unloading old MapTile (%u, %u) map %u",gx,gy,_mapid);
                    _tiles->UnloadMapTile(gx,gy);
                }
            }
        }
    }
}

// Using forceLoad is VERY ineffective here, because the tile is removed again after the next Update() call!
MapTile *MapMgr::GetTile(uint32 xg, uint32 yg, bool forceLoad)
{
    MapTile *tile = _tiles->GetTile(xg,yg);
    if(!tile && forceLoad)
    {
        _LoadTile(xg,yg,_mapid);
        tile = _tiles->GetTile(xg,yg);
    }
    return tile;
}

MapTile *MapMgr::GetCurrentTile(void)
{
    return GetTile(_gridx,_gridy);
}

MapTile *MapMgr::GetNearTile(int32 xoffs, int32 yoffs)
{
    return GetTile(_gridx + xoffs, _gridy + yoffs);
}

uint32 MapMgr::GetGridCoord(float f)
{
    return (ZEROPOINT - f) / TILESIZE;
}

GridCoordPair MapMgr::GetTransformGridCoordPair(float x, float y)
{
    return GridCoordPair(GetGridCoord(y), GetGridCoord(x)); // yes, they are reversed. definitely.
}

uint32 MapMgr::GetLoadedMapsCount(void)
{
    uint32 counter = 0;
    for(uint32 i = 0; i < 4096; i++)
    {
        if(_tiles->GetTile(i))
        {
            counter++;
        }
    }
    return counter;
}

float MapMgr::GetZ(float x, float y)
{
    return -99999.0f; // for now return lowest possible number, GetZ() will be implemented correctly later
/*    GridCoordPair gcoords = GetTransformGridCoordPair(x,y);
    MapTile *tile = _tiles->GetTile(gcoords.x,gcoords.y);
    if(tile)
    {
#ifdef _DEBUG
        tile->DebugDumpToFile();
        logdebug("DEBUG: tile dumped");
#endif
        return tile->GetZ(x,y);
    }

    logerror("MapMgr::GetZ() called for not loaded MapTile (%u, %u) for (%f, %f)",gcoords.x,gcoords.y,x,y);
    return 0;*/
}
 
