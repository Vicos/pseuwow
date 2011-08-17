#include "common.h"
#include "PseuWoW.h"
#include "InstanceList.h"

InstanceList* InstanceList::get(void)
{
	static InstanceList *_singleton = NULL;
	if ( _singleton == NULL )
		_singleton = new InstanceList();

	return _singleton;
}

void InstanceList::quitproc(void)
{
	log("Waiting for all instances to finish... [%u]\n",_list.size());
	for(std::list<PseuInstanceRunnable*>::iterator i=_list.begin();i!=_list.end();i++)
		(*i)->GetInstance()->Stop();
}

void InstanceList::abortproc(void)
{
	log("Terminating all instances... [%u]\n",_list.size());
	for(std::list<PseuInstanceRunnable*>::iterator i=_list.begin();i!=_list.end();i++)
	{
		(*i)->GetInstance()->SetFastQuit(true);
		(*i)->GetInstance()->Stop();
	}
}
