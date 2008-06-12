/* 
 * Copyright (C) 2005,2006,2007 MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/** \file
    \ingroup u2w
*/
#include "common.h"
#include "Opcodes.h"


/// Correspondance between opcodes and their names
// this is an string array, for more opcode comments look to opcodes.h
// do not change order of lines!
// when renaming opcodes, replace old name by the new one
const char* worldOpcodeNames[] =
{
    "MSG_NULL_ACTION",
    "CMSG_BOOTME",
    "CMSG_DBLOOKUP",
    "SMSG_DBLOOKUP",
    "CMSG_QUERY_OBJECT_POSITION",
    "SMSG_QUERY_OBJECT_POSITION",
    "CMSG_QUERY_OBJECT_ROTATION",
    "SMSG_QUERY_OBJECT_ROTATION",
    "CMSG_WORLD_TELEPORT",
    "CMSG_TELEPORT_TO_UNIT",
    "CMSG_ZONE_MAP",
    "SMSG_ZONE_MAP",
    "CMSG_DEBUG_CHANGECELLZONE",
    "CMSG_EMBLAZON_TABARD_OBSOLETE",
    "CMSG_UNEMBLAZON_TABARD_OBSOLETE",
    "CMSG_RECHARGE",
    "CMSG_LEARN_SPELL",
    "CMSG_CREATEMONSTER",
    "CMSG_DESTROYMONSTER",
    "CMSG_CREATEITEM",
    "CMSG_CREATEGAMEOBJECT",
    "SMSG_CHECK_FOR_BOTS",
    "CMSG_MAKEMONSTERATTACKGUID",
    "CMSG_BOT_DETECTED2",
    "CMSG_FORCEACTION",
    "CMSG_FORCEACTIONONOTHER",
    "CMSG_FORCEACTIONSHOW",
    "SMSG_FORCEACTIONSHOW",
    "CMSG_PETGODMODE",
    "SMSG_PETGODMODE",
    "SMSG_DEBUGINFOSPELLMISS_OBSOLETE",
    "CMSG_WEATHER_SPEED_CHEAT",
    "CMSG_UNDRESSPLAYER",
    "CMSG_BEASTMASTER",
    "CMSG_GODMODE",
    "SMSG_GODMODE",
    "CMSG_CHEAT_SETMONEY",
    "CMSG_LEVEL_CHEAT",
    "CMSG_PET_LEVEL_CHEAT",
    "CMSG_SET_WORLDSTATE",
    "CMSG_COOLDOWN_CHEAT",
    "CMSG_USE_SKILL_CHEAT",
    "CMSG_FLAG_QUEST",
    "CMSG_FLAG_QUEST_FINISH",
    "CMSG_CLEAR_QUEST",
    "CMSG_SEND_EVENT",
    "CMSG_DEBUG_AISTATE",
    "SMSG_DEBUG_AISTATE",
    "CMSG_DISABLE_PVP_CHEAT",
    "CMSG_ADVANCE_SPAWN_TIME",
    "CMSG_PVP_PORT_OBSOLETE",
    "CMSG_AUTH_SRP6_BEGIN",
    "CMSG_AUTH_SRP6_PROOF",
    "CMSG_AUTH_SRP6_RECODE",
    "CMSG_CHAR_CREATE",
    "CMSG_CHAR_ENUM",
    "CMSG_CHAR_DELETE",
    "SMSG_AUTH_SRP6_RESPONSE",
    "SMSG_CHAR_CREATE",
    "SMSG_CHAR_ENUM",
    "SMSG_CHAR_DELETE",
    "CMSG_PLAYER_LOGIN",
    "SMSG_NEW_WORLD",
    "SMSG_TRANSFER_PENDING",
    "SMSG_TRANSFER_ABORTED",
    "SMSG_CHARACTER_LOGIN_FAILED",
    "SMSG_LOGIN_SETTIMESPEED",
    "SMSG_GAMETIME_UPDATE",
    "CMSG_GAMETIME_SET",
    "SMSG_GAMETIME_SET",
    "CMSG_GAMESPEED_SET",
    "SMSG_GAMESPEED_SET",
    "CMSG_SERVERTIME",
    "SMSG_SERVERTIME",
    "CMSG_PLAYER_LOGOUT",
    "CMSG_LOGOUT_REQUEST",
    "SMSG_LOGOUT_RESPONSE",
    "SMSG_LOGOUT_COMPLETE",
    "CMSG_LOGOUT_CANCEL",
    "SMSG_LOGOUT_CANCEL_ACK",
    "CMSG_NAME_QUERY",
    "SMSG_NAME_QUERY_RESPONSE",
    "CMSG_PET_NAME_QUERY",
    "SMSG_PET_NAME_QUERY_RESPONSE",
    "CMSG_GUILD_QUERY",
    "SMSG_GUILD_QUERY_RESPONSE",
    "CMSG_ITEM_QUERY_SINGLE",
    "CMSG_ITEM_QUERY_MULTIPLE",
    "SMSG_ITEM_QUERY_SINGLE_RESPONSE",
    "SMSG_ITEM_QUERY_MULTIPLE_RESPONSE",
    "CMSG_PAGE_TEXT_QUERY",
    "SMSG_PAGE_TEXT_QUERY_RESPONSE",
    "CMSG_QUEST_QUERY",
    "SMSG_QUEST_QUERY_RESPONSE",
    "CMSG_GAMEOBJECT_QUERY",
    "SMSG_GAMEOBJECT_QUERY_RESPONSE",
    "CMSG_CREATURE_QUERY",
    "SMSG_CREATURE_QUERY_RESPONSE",
    "CMSG_WHO",
    "SMSG_WHO",
    "CMSG_WHOIS",
    "SMSG_WHOIS",
    "CMSG_CONTACT_LIST",
    "SMSG_CONTACT_LIST",
    "SMSG_FRIEND_STATUS",
    "CMSG_ADD_FRIEND",
    "CMSG_DEL_FRIEND",
    "CMSG_SET_CONTACT_NOTES",
    "CMSG_ADD_IGNORE",
    "CMSG_DEL_IGNORE",
    "CMSG_GROUP_INVITE",
    "SMSG_GROUP_INVITE",
    "CMSG_GROUP_CANCEL",
    "SMSG_GROUP_CANCEL",
    "CMSG_GROUP_ACCEPT",
    "CMSG_GROUP_DECLINE",
    "SMSG_GROUP_DECLINE",
    "CMSG_GROUP_UNINVITE",
    "CMSG_GROUP_UNINVITE_GUID",
    "SMSG_GROUP_UNINVITE",
    "CMSG_GROUP_SET_LEADER",
    "SMSG_GROUP_SET_LEADER",
    "CMSG_LOOT_METHOD",
    "CMSG_GROUP_DISBAND",
    "SMSG_GROUP_DESTROYED",
    "SMSG_GROUP_LIST",
    "SMSG_PARTY_MEMBER_STATS",
    "SMSG_PARTY_COMMAND_RESULT",
    "UMSG_UPDATE_GROUP_MEMBERS",
    "CMSG_GUILD_CREATE",
    "CMSG_GUILD_INVITE",
    "SMSG_GUILD_INVITE",
    "CMSG_GUILD_ACCEPT",
    "CMSG_GUILD_DECLINE",
    "SMSG_GUILD_DECLINE",
    "CMSG_GUILD_INFO",
    "SMSG_GUILD_INFO",
    "CMSG_GUILD_ROSTER",
    "SMSG_GUILD_ROSTER",
    "CMSG_GUILD_PROMOTE",
    "CMSG_GUILD_DEMOTE",
    "CMSG_GUILD_LEAVE",
    "CMSG_GUILD_REMOVE",
    "CMSG_GUILD_DISBAND",
    "CMSG_GUILD_LEADER",
    "CMSG_GUILD_MOTD",
    "SMSG_GUILD_EVENT",
    "SMSG_GUILD_COMMAND_RESULT",
    "UMSG_UPDATE_GUILD",
    "CMSG_MESSAGECHAT",
    "SMSG_MESSAGECHAT",
    "CMSG_JOIN_CHANNEL",
    "CMSG_LEAVE_CHANNEL",
    "SMSG_CHANNEL_NOTIFY",
    "CMSG_CHANNEL_LIST",
    "SMSG_CHANNEL_LIST",
    "CMSG_CHANNEL_PASSWORD",
    "CMSG_CHANNEL_SET_OWNER",
    "CMSG_CHANNEL_OWNER",
    "CMSG_CHANNEL_MODERATOR",
    "CMSG_CHANNEL_UNMODERATOR",
    "CMSG_CHANNEL_MUTE",
    "CMSG_CHANNEL_UNMUTE",
    "CMSG_CHANNEL_INVITE",
    "CMSG_CHANNEL_KICK",
    "CMSG_CHANNEL_BAN",
    "CMSG_CHANNEL_UNBAN",
    "CMSG_CHANNEL_ANNOUNCEMENTS",
    "CMSG_CHANNEL_MODERATE",
    "SMSG_UPDATE_OBJECT",
    "SMSG_DESTROY_OBJECT",
    "CMSG_USE_ITEM",
    "CMSG_OPEN_ITEM",
    "CMSG_READ_ITEM",
    "SMSG_READ_ITEM_OK",
    "SMSG_READ_ITEM_FAILED",
    "SMSG_ITEM_COOLDOWN",
    "CMSG_GAMEOBJ_USE",
    "CMSG_GAMEOBJ_CHAIR_USE_OBSOLETE",
    "SMSG_GAMEOBJECT_CUSTOM_ANIM",
    "CMSG_AREATRIGGER",
    "MSG_MOVE_START_FORWARD",
    "MSG_MOVE_START_BACKWARD",
    "MSG_MOVE_STOP",
    "MSG_MOVE_START_STRAFE_LEFT",
    "MSG_MOVE_START_STRAFE_RIGHT",
    "MSG_MOVE_STOP_STRAFE",
    "MSG_MOVE_JUMP",
    "MSG_MOVE_START_TURN_LEFT",
    "MSG_MOVE_START_TURN_RIGHT",
    "MSG_MOVE_STOP_TURN",
    "MSG_MOVE_START_PITCH_UP",
    "MSG_MOVE_START_PITCH_DOWN",
    "MSG_MOVE_STOP_PITCH",
    "MSG_MOVE_SET_RUN_MODE",
    "MSG_MOVE_SET_WALK_MODE",
    "MSG_MOVE_TOGGLE_LOGGING",
    "MSG_MOVE_TELEPORT",
    "MSG_MOVE_TELEPORT_CHEAT",
    "MSG_MOVE_TELEPORT_ACK",
    "MSG_MOVE_TOGGLE_FALL_LOGGING",
    "MSG_MOVE_FALL_LAND",
    "MSG_MOVE_START_SWIM",
    "MSG_MOVE_STOP_SWIM",
    "MSG_MOVE_SET_RUN_SPEED_CHEAT",
    "MSG_MOVE_SET_RUN_SPEED",
    "MSG_MOVE_SET_RUN_BACK_SPEED_CHEAT",
    "MSG_MOVE_SET_RUN_BACK_SPEED",
    "MSG_MOVE_SET_WALK_SPEED_CHEAT",
    "MSG_MOVE_SET_WALK_SPEED",
    "MSG_MOVE_SET_SWIM_SPEED_CHEAT",
    "MSG_MOVE_SET_SWIM_SPEED",
    "MSG_MOVE_SET_SWIM_BACK_SPEED_CHEAT",
    "MSG_MOVE_SET_SWIM_BACK_SPEED",
    "MSG_MOVE_SET_ALL_SPEED_CHEAT",
    "MSG_MOVE_SET_TURN_RATE_CHEAT",
    "MSG_MOVE_SET_TURN_RATE",
    "MSG_MOVE_TOGGLE_COLLISION_CHEAT",
    "MSG_MOVE_SET_FACING",
    "MSG_MOVE_SET_PITCH",
    "MSG_MOVE_WORLDPORT_ACK",
    "SMSG_MONSTER_MOVE",
    "SMSG_MOVE_WATER_WALK",
    "SMSG_MOVE_LAND_WALK",
    "MSG_MOVE_SET_RAW_POSITION_ACK",
    "CMSG_MOVE_SET_RAW_POSITION",
    "SMSG_FORCE_RUN_SPEED_CHANGE",
    "CMSG_FORCE_RUN_SPEED_CHANGE_ACK",
    "SMSG_FORCE_RUN_BACK_SPEED_CHANGE",
    "CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK",
    "SMSG_FORCE_SWIM_SPEED_CHANGE",
    "CMSG_FORCE_SWIM_SPEED_CHANGE_ACK",
    "SMSG_FORCE_MOVE_ROOT",
    "CMSG_FORCE_MOVE_ROOT_ACK",
    "SMSG_FORCE_MOVE_UNROOT",
    "CMSG_FORCE_MOVE_UNROOT_ACK",
    "MSG_MOVE_ROOT",
    "MSG_MOVE_UNROOT",
    "MSG_MOVE_HEARTBEAT",
    "SMSG_MOVE_KNOCK_BACK",
    "CMSG_MOVE_KNOCK_BACK_ACK",
    "MSG_MOVE_KNOCK_BACK",
    "SMSG_MOVE_FEATHER_FALL",
    "SMSG_MOVE_NORMAL_FALL",
    "SMSG_MOVE_SET_HOVER",
    "SMSG_MOVE_UNSET_HOVER",
    "CMSG_MOVE_HOVER_ACK",
    "MSG_MOVE_HOVER",
    "CMSG_TRIGGER_CINEMATIC_CHEAT",
    "CMSG_OPENING_CINEMATIC",
    "SMSG_TRIGGER_CINEMATIC",
    "CMSG_NEXT_CINEMATIC_CAMERA",
    "CMSG_COMPLETE_CINEMATIC",
    "SMSG_TUTORIAL_FLAGS",
    "CMSG_TUTORIAL_FLAG",
    "CMSG_TUTORIAL_CLEAR",
    "CMSG_TUTORIAL_RESET",
    "CMSG_STANDSTATECHANGE",
    "CMSG_EMOTE",
    "SMSG_EMOTE",
    "CMSG_TEXT_EMOTE",
    "SMSG_TEXT_EMOTE",
    "CMSG_AUTOEQUIP_GROUND_ITEM",
    "CMSG_AUTOSTORE_GROUND_ITEM",
    "CMSG_AUTOSTORE_LOOT_ITEM",
    "CMSG_STORE_LOOT_IN_SLOT",
    "CMSG_AUTOEQUIP_ITEM",
    "CMSG_AUTOSTORE_BAG_ITEM",
    "CMSG_SWAP_ITEM",
    "CMSG_SWAP_INV_ITEM",
    "CMSG_SPLIT_ITEM",
    "CMSG_AUTOEQUIP_ITEM_SLOT",
    "OBSOLETE_DROP_ITEM",
    "CMSG_DESTROYITEM",
    "SMSG_INVENTORY_CHANGE_FAILURE",
    "SMSG_OPEN_CONTAINER",
    "CMSG_INSPECT",
    "SMSG_INSPECT",
    "CMSG_INITIATE_TRADE",
    "CMSG_BEGIN_TRADE",
    "CMSG_BUSY_TRADE",
    "CMSG_IGNORE_TRADE",
    "CMSG_ACCEPT_TRADE",
    "CMSG_UNACCEPT_TRADE",
    "CMSG_CANCEL_TRADE",
    "CMSG_SET_TRADE_ITEM",
    "CMSG_CLEAR_TRADE_ITEM",
    "CMSG_SET_TRADE_GOLD",
    "SMSG_TRADE_STATUS",
    "SMSG_TRADE_STATUS_EXTENDED",
    "SMSG_INITIALIZE_FACTIONS",
    "SMSG_SET_FACTION_VISIBLE",
    "SMSG_SET_FACTION_STANDING",
    "CMSG_SET_FACTION_ATWAR",
    "CMSG_SET_FACTION_CHEAT",
    "SMSG_SET_PROFICIENCY",
    "CMSG_SET_ACTION_BUTTON",
    "SMSG_ACTION_BUTTONS",
    "SMSG_INITIAL_SPELLS",
    "SMSG_LEARNED_SPELL",
    "SMSG_SUPERCEDED_SPELL",
    "CMSG_NEW_SPELL_SLOT",
    "CMSG_CAST_SPELL",
    "CMSG_CANCEL_CAST",
    "SMSG_CAST_FAILED",
    "SMSG_SPELL_START",
    "SMSG_SPELL_GO",
    "SMSG_SPELL_FAILURE",
    "SMSG_SPELL_COOLDOWN",
    "SMSG_COOLDOWN_EVENT",
    "CMSG_CANCEL_AURA",
    "SMSG_UPDATE_AURA_DURATION",
    "SMSG_PET_CAST_FAILED",
    "MSG_CHANNEL_START",
    "MSG_CHANNEL_UPDATE",
    "CMSG_CANCEL_CHANNELLING",
    "SMSG_AI_REACTION",
    "CMSG_SET_SELECTION",
    "CMSG_SET_TARGET_OBSOLETE",
    "CMSG_UNUSED",
    "CMSG_UNUSED2",
    "CMSG_ATTACKSWING",
    "CMSG_ATTACKSTOP",
    "SMSG_ATTACKSTART",
    "SMSG_ATTACKSTOP",
    "SMSG_ATTACKSWING_NOTINRANGE",
    "SMSG_ATTACKSWING_BADFACING",
    "SMSG_ATTACKSWING_NOTSTANDING",
    "SMSG_ATTACKSWING_DEADTARGET",
    "SMSG_ATTACKSWING_CANT_ATTACK",
    "SMSG_ATTACKERSTATEUPDATE",
    "SMSG_VICTIMSTATEUPDATE_OBSOLETE",
    "SMSG_DAMAGE_DONE_OBSOLETE",
    "SMSG_DAMAGE_TAKEN_OBSOLETE",
    "SMSG_CANCEL_COMBAT",
    "SMSG_PLAYER_COMBAT_XP_GAIN_OBSOLETE",
    "SMSG_SPELLHEALLOG",
    "SMSG_SPELLENERGIZELOG",
    "CMSG_SHEATHE_OBSOLETE",
    "CMSG_SAVE_PLAYER",
    "CMSG_SETDEATHBINDPOINT",
    "SMSG_BINDPOINTUPDATE",
    "CMSG_GETDEATHBINDZONE",
    "SMSG_BINDZONEREPLY",
    "SMSG_PLAYERBOUND",
    "SMSG_CLIENT_CONTROL_UPDATE",
    "CMSG_REPOP_REQUEST",
    "SMSG_RESURRECT_REQUEST",
    "CMSG_RESURRECT_RESPONSE",
    "CMSG_LOOT",
    "CMSG_LOOT_MONEY",
    "CMSG_LOOT_RELEASE",
    "SMSG_LOOT_RESPONSE",
    "SMSG_LOOT_RELEASE_RESPONSE",
    "SMSG_LOOT_REMOVED",
    "SMSG_LOOT_MONEY_NOTIFY",
    "SMSG_LOOT_ITEM_NOTIFY",
    "SMSG_LOOT_CLEAR_MONEY",
    "SMSG_ITEM_PUSH_RESULT",
    "SMSG_DUEL_REQUESTED",
    "SMSG_DUEL_OUTOFBOUNDS",
    "SMSG_DUEL_INBOUNDS",
    "SMSG_DUEL_COMPLETE",
    "SMSG_DUEL_WINNER",
    "CMSG_DUEL_ACCEPTED",
    "CMSG_DUEL_CANCELLED",
    "SMSG_MOUNTRESULT",
    "SMSG_DISMOUNTRESULT",
    "SMSG_PUREMOUNT_CANCELLED_OBSOLETE",
    "CMSG_MOUNTSPECIAL_ANIM",
    "SMSG_MOUNTSPECIAL_ANIM",
    "SMSG_PET_TAME_FAILURE",
    "CMSG_PET_SET_ACTION",
    "CMSG_PET_ACTION",
    "CMSG_PET_ABANDON",
    "CMSG_PET_RENAME",
    "SMSG_PET_NAME_INVALID",
    "SMSG_PET_SPELLS",
    "SMSG_PET_MODE",
    "CMSG_GOSSIP_HELLO",
    "CMSG_GOSSIP_SELECT_OPTION",
    "SMSG_GOSSIP_MESSAGE",
    "SMSG_GOSSIP_COMPLETE",
    "CMSG_NPC_TEXT_QUERY",
    "SMSG_NPC_TEXT_UPDATE",
    "SMSG_NPC_WONT_TALK",
    "CMSG_QUESTGIVER_STATUS_QUERY",
    "SMSG_QUESTGIVER_STATUS",
    "CMSG_QUESTGIVER_HELLO",
    "SMSG_QUESTGIVER_QUEST_LIST",
    "CMSG_QUESTGIVER_QUERY_QUEST",
    "CMSG_QUESTGIVER_QUEST_AUTOLAUNCH",
    "SMSG_QUESTGIVER_QUEST_DETAILS",
    "CMSG_QUESTGIVER_ACCEPT_QUEST",
    "CMSG_QUESTGIVER_COMPLETE_QUEST",
    "SMSG_QUESTGIVER_REQUEST_ITEMS",
    "CMSG_QUESTGIVER_REQUEST_REWARD",
    "SMSG_QUESTGIVER_OFFER_REWARD",
    "CMSG_QUESTGIVER_CHOOSE_REWARD",
    "SMSG_QUESTGIVER_QUEST_INVALID",
    "CMSG_QUESTGIVER_CANCEL",
    "SMSG_QUESTGIVER_QUEST_COMPLETE",
    "SMSG_QUESTGIVER_QUEST_FAILED",
    "CMSG_QUESTLOG_SWAP_QUEST",
    "CMSG_QUESTLOG_REMOVE_QUEST",
    "SMSG_QUESTLOG_FULL",
    "SMSG_QUESTUPDATE_FAILED",
    "SMSG_QUESTUPDATE_FAILEDTIMER",
    "SMSG_QUESTUPDATE_COMPLETE",
    "SMSG_QUESTUPDATE_ADD_KILL",
    "SMSG_QUESTUPDATE_ADD_ITEM",
    "CMSG_QUEST_CONFIRM_ACCEPT",
    "SMSG_QUEST_CONFIRM_ACCEPT",
    "CMSG_PUSHQUESTTOPARTY",
    "CMSG_LIST_INVENTORY",
    "SMSG_LIST_INVENTORY",
    "CMSG_SELL_ITEM",
    "SMSG_SELL_ITEM",
    "CMSG_BUY_ITEM",
    "CMSG_BUY_ITEM_IN_SLOT",
    "SMSG_BUY_ITEM",
    "SMSG_BUY_FAILED",
    "CMSG_TAXICLEARALLNODES",
    "CMSG_TAXIENABLEALLNODES",
    "CMSG_TAXISHOWNODES",
    "SMSG_SHOWTAXINODES",
    "CMSG_TAXINODE_STATUS_QUERY",
    "SMSG_TAXINODE_STATUS",
    "CMSG_TAXIQUERYAVAILABLENODES",
    "CMSG_ACTIVATETAXI",
    "SMSG_ACTIVATETAXIREPLY",
    "SMSG_NEW_TAXI_PATH",
    "CMSG_TRAINER_LIST",
    "SMSG_TRAINER_LIST",
    "CMSG_TRAINER_BUY_SPELL",
    "SMSG_TRAINER_BUY_SUCCEEDED",
    "SMSG_TRAINER_BUY_FAILED",
    "CMSG_BINDER_ACTIVATE",
    "SMSG_PLAYERBINDERROR",
    "CMSG_BANKER_ACTIVATE",
    "SMSG_SHOW_BANK",
    "CMSG_BUY_BANK_SLOT",
    "SMSG_BUY_BANK_SLOT_RESULT",
    "CMSG_PETITION_SHOWLIST",
    "SMSG_PETITION_SHOWLIST",
    "CMSG_PETITION_BUY",
    "CMSG_PETITION_SHOW_SIGNATURES",
    "SMSG_PETITION_SHOW_SIGNATURES",
    "CMSG_PETITION_SIGN",
    "SMSG_PETITION_SIGN_RESULTS",
    "MSG_PETITION_DECLINE",
    "CMSG_OFFER_PETITION",
    "CMSG_TURN_IN_PETITION",
    "SMSG_TURN_IN_PETITION_RESULTS",
    "CMSG_PETITION_QUERY",
    "SMSG_PETITION_QUERY_RESPONSE",
    "SMSG_FISH_NOT_HOOKED",
    "SMSG_FISH_ESCAPED",
    "CMSG_BUG",
    "SMSG_NOTIFICATION",
    "CMSG_PLAYED_TIME",
    "SMSG_PLAYED_TIME",
    "CMSG_QUERY_TIME",
    "SMSG_QUERY_TIME_RESPONSE",
    "SMSG_LOG_XPGAIN",
    "SMSG_AURACASTLOG",
    "CMSG_RECLAIM_CORPSE",
    "CMSG_WRAP_ITEM",
    "SMSG_LEVELUP_INFO",
    "MSG_MINIMAP_PING",
    "SMSG_RESISTLOG",
    "SMSG_ENCHANTMENTLOG",
    "CMSG_SET_SKILL_CHEAT",
    "SMSG_START_MIRROR_TIMER",
    "SMSG_PAUSE_MIRROR_TIMER",
    "SMSG_STOP_MIRROR_TIMER",
    "CMSG_PING",
    "SMSG_PONG",
    "SMSG_CLEAR_COOLDOWN",
    "SMSG_GAMEOBJECT_PAGETEXT",
    "CMSG_SETSHEATHED",
    "SMSG_COOLDOWN_CHEAT",
    "SMSG_SPELL_DELAYED",
    "CMSG_PLAYER_MACRO_OBSOLETE",
    "SMSG_PLAYER_MACRO_OBSOLETE",
    "CMSG_GHOST",
    "CMSG_GM_INVIS",
    "SMSG_INVALID_PROMOTION_CODE",
    "MSG_GM_BIND_OTHER",
    "MSG_GM_SUMMON",
    "SMSG_ITEM_TIME_UPDATE",
    "SMSG_ITEM_ENCHANT_TIME_UPDATE",
    "SMSG_AUTH_CHALLENGE",
    "CMSG_AUTH_SESSION",
    "SMSG_AUTH_RESPONSE",
    "MSG_GM_SHOWLABEL",
    "CMSG_PET_CAST_SPELL",
    "MSG_SAVE_GUILD_EMBLEM",
    "MSG_TABARDVENDOR_ACTIVATE",
    "SMSG_PLAY_SPELL_VISUAL",
    "CMSG_ZONEUPDATE",
    "SMSG_PARTYKILLLOG",
    "SMSG_COMPRESSED_UPDATE_OBJECT",
    "SMSG_PLAY_SPELL_IMPACT",
    "SMSG_EXPLORATION_EXPERIENCE",
    "CMSG_GM_SET_SECURITY_GROUP",
    "CMSG_GM_NUKE",
    "MSG_RANDOM_ROLL",
    "SMSG_ENVIRONMENTALDAMAGELOG",
    "CMSG_RWHOIS_OBSOLETE",
    "SMSG_RWHOIS",
    "MSG_LOOKING_FOR_GROUP",
    "CMSG_SET_LOOKING_FOR_GROUP",
    "CMSG_UNLEARN_SPELL",
    "CMSG_UNLEARN_SKILL",
    "SMSG_REMOVED_SPELL",
    "CMSG_DECHARGE",
    "CMSG_GMTICKET_CREATE",
    "SMSG_GMTICKET_CREATE",
    "CMSG_GMTICKET_UPDATETEXT",
    "SMSG_GMTICKET_UPDATETEXT",
    "SMSG_ACCOUNT_DATA_TIMES",
    "CMSG_REQUEST_ACCOUNT_DATA",
    "CMSG_UPDATE_ACCOUNT_DATA",
    "SMSG_UPDATE_ACCOUNT_DATA",
    "SMSG_CLEAR_FAR_SIGHT_IMMEDIATE",
    "SMSG_POWERGAINLOG_OBSOLETE",
    "CMSG_GM_TEACH",
    "CMSG_GM_CREATE_ITEM_TARGET",
    "CMSG_GMTICKET_GETTICKET",
    "SMSG_GMTICKET_GETTICKET",
    "CMSG_UNLEARN_TALENTS",
    "SMSG_GAMEOBJECT_SPAWN_ANIM_OBSOLETE",
    "SMSG_GAMEOBJECT_DESPAWN_ANIM",
    "MSG_CORPSE_QUERY",
    "CMSG_GMTICKET_DELETETICKET",
    "SMSG_GMTICKET_DELETETICKET",
    "SMSG_CHAT_WRONG_FACTION",
    "CMSG_GMTICKET_SYSTEMSTATUS",
    "SMSG_GMTICKET_SYSTEMSTATUS",
    "CMSG_SPIRIT_HEALER_ACTIVATE",
    "CMSG_SET_STAT_CHEAT",
    "SMSG_SET_REST_START",
    "CMSG_SKILL_BUY_STEP",
    "CMSG_SKILL_BUY_RANK",
    "CMSG_XP_CHEAT",
    "SMSG_SPIRIT_HEALER_CONFIRM",
    "CMSG_CHARACTER_POINT_CHEAT",
    "SMSG_GOSSIP_POI",
    "CMSG_CHAT_IGNORED",
    "CMSG_GM_VISION",
    "CMSG_SERVER_COMMAND",
    "CMSG_GM_SILENCE",
    "CMSG_GM_REVEALTO",
    "CMSG_GM_RESURRECT",
    "CMSG_GM_SUMMONMOB",
    "CMSG_GM_MOVECORPSE",
    "CMSG_GM_FREEZE",
    "CMSG_GM_UBERINVIS",
    "CMSG_GM_REQUEST_PLAYER_INFO",
    "SMSG_GM_PLAYER_INFO",
    "CMSG_GUILD_RANK",
    "CMSG_GUILD_ADD_RANK",
    "CMSG_GUILD_DEL_RANK",
    "CMSG_GUILD_SET_PUBLIC_NOTE",
    "CMSG_GUILD_SET_OFFICER_NOTE",
    "SMSG_LOGIN_VERIFY_WORLD",
    "CMSG_CLEAR_EXPLORATION",
    "CMSG_SEND_MAIL",
    "SMSG_SEND_MAIL_RESULT",
    "CMSG_GET_MAIL_LIST",
    "SMSG_MAIL_LIST_RESULT",
    "CMSG_BATTLEFIELD_LIST",
    "SMSG_BATTLEFIELD_LIST",
    "CMSG_BATTLEFIELD_JOIN",
    "SMSG_BATTLEFIELD_WIN_OBSOLETE",
    "SMSG_BATTLEFIELD_LOSE_OBSOLETE",
    "CMSG_TAXICLEARNODE",
    "CMSG_TAXIENABLENODE",
    "CMSG_ITEM_TEXT_QUERY",
    "SMSG_ITEM_TEXT_QUERY_RESPONSE",
    "CMSG_MAIL_TAKE_MONEY",
    "CMSG_MAIL_TAKE_ITEM",
    "CMSG_MAIL_MARK_AS_READ",
    "CMSG_MAIL_RETURN_TO_SENDER",
    "CMSG_MAIL_DELETE",
    "CMSG_MAIL_CREATE_TEXT_ITEM",
    "SMSG_SPELLLOGMISS",
    "SMSG_SPELLLOGEXECUTE",
    "SMSG_DEBUGAURAPROC",
    "SMSG_PERIODICAURALOG",
    "SMSG_SPELLDAMAGESHIELD",
    "SMSG_SPELLNONMELEEDAMAGELOG",
    "CMSG_LEARN_TALENT",
    "SMSG_RESURRECT_FAILED",
    "CMSG_TOGGLE_PVP",
    "SMSG_ZONE_UNDER_ATTACK",
    "MSG_AUCTION_HELLO",
    "CMSG_AUCTION_SELL_ITEM",
    "CMSG_AUCTION_REMOVE_ITEM",
    "CMSG_AUCTION_LIST_ITEMS",
    "CMSG_AUCTION_LIST_OWNER_ITEMS",
    "CMSG_AUCTION_PLACE_BID",
    "SMSG_AUCTION_COMMAND_RESULT",
    "SMSG_AUCTION_LIST_RESULT",
    "SMSG_AUCTION_OWNER_LIST_RESULT",
    "SMSG_AUCTION_BIDDER_NOTIFICATION",
    "SMSG_AUCTION_OWNER_NOTIFICATION",
    "SMSG_PROCRESIST",
    "SMSG_STANDSTATE_CHANGE_FAILURE_OBSOLETE",
    "SMSG_DISPEL_FAILED",
    "SMSG_SPELLORDAMAGE_IMMUNE",
    "CMSG_AUCTION_LIST_BIDDER_ITEMS",
    "SMSG_AUCTION_BIDDER_LIST_RESULT",
    "SMSG_SET_FLAT_SPELL_MODIFIER",
    "SMSG_SET_PCT_SPELL_MODIFIER",
    "CMSG_SET_AMMO",
    "SMSG_CORPSE_RECLAIM_DELAY",
    "CMSG_SET_ACTIVE_MOVER",
    "CMSG_PET_CANCEL_AURA",
    "CMSG_PLAYER_AI_CHEAT",
    "CMSG_CANCEL_AUTO_REPEAT_SPELL",
    "MSG_GM_ACCOUNT_ONLINE",
    "MSG_LIST_STABLED_PETS",
    "CMSG_STABLE_PET",
    "CMSG_UNSTABLE_PET",
    "CMSG_BUY_STABLE_SLOT",
    "SMSG_STABLE_RESULT",
    "CMSG_STABLE_REVIVE_PET",
    "CMSG_STABLE_SWAP_PET",
    "MSG_QUEST_PUSH_RESULT",
    "SMSG_PLAY_MUSIC",
    "SMSG_PLAY_OBJECT_SOUND",
    "CMSG_REQUEST_PET_INFO",
    "CMSG_FAR_SIGHT",
    "SMSG_SPELLDISPELLOG",
    "SMSG_DAMAGE_CALC_LOG",
    "CMSG_ENABLE_DAMAGE_LOG",
    "CMSG_GROUP_CHANGE_SUB_GROUP",
    "CMSG_REQUEST_PARTY_MEMBER_STATS",
    "CMSG_GROUP_SWAP_SUB_GROUP",
    "CMSG_RESET_FACTION_CHEAT",
    "CMSG_AUTOSTORE_BANK_ITEM",
    "CMSG_AUTOBANK_ITEM",
    "MSG_QUERY_NEXT_MAIL_TIME",
    "SMSG_RECEIVED_MAIL",
    "SMSG_RAID_GROUP_ONLY",
    "CMSG_SET_DURABILITY_CHEAT",
    "CMSG_SET_PVP_RANK_CHEAT",
    "CMSG_ADD_PVP_MEDAL_CHEAT",
    "CMSG_DEL_PVP_MEDAL_CHEAT",
    "CMSG_SET_PVP_TITLE",
    "SMSG_PVP_CREDIT",
    "SMSG_AUCTION_REMOVED_NOTIFICATION",
    "CMSG_GROUP_RAID_CONVERT",
    "CMSG_GROUP_ASSISTANT_LEADER",
    "CMSG_BUYBACK_ITEM",
    "SMSG_SERVER_MESSAGE",
    "CMSG_MEETINGSTONE_JOIN",
    "CMSG_MEETINGSTONE_LEAVE",
    "CMSG_MEETINGSTONE_CHEAT",
    "SMSG_MEETINGSTONE_SETQUEUE",
    "CMSG_MEETINGSTONE_INFO",
    "SMSG_MEETINGSTONE_COMPLETE",
    "SMSG_MEETINGSTONE_IN_PROGRESS",
    "SMSG_MEETINGSTONE_MEMBER_ADDED",
    "CMSG_GMTICKETSYSTEM_TOGGLE",
    "CMSG_CANCEL_GROWTH_AURA",
    "SMSG_CANCEL_AUTO_REPEAT",
    "SMSG_STANDSTATE_UPDATE",
    "SMSG_LOOT_ALL_PASSED",
    "SMSG_LOOT_ROLL_WON",
    "CMSG_LOOT_ROLL",
    "SMSG_LOOT_START_ROLL",
    "SMSG_LOOT_ROLL",
    "CMSG_LOOT_MASTER_GIVE",
    "SMSG_LOOT_MASTER_LIST",
    "SMSG_SET_FORCED_REACTIONS",
    "SMSG_SPELL_FAILED_OTHER",
    "SMSG_GAMEOBJECT_RESET_STATE",
    "CMSG_REPAIR_ITEM",
    "SMSG_CHAT_PLAYER_NOT_FOUND",
    "MSG_TALENT_WIPE_CONFIRM",
    "SMSG_SUMMON_REQUEST",
    "CMSG_SUMMON_RESPONSE",
    "MSG_MOVE_TOGGLE_GRAVITY_CHEAT",
    "SMSG_MONSTER_MOVE_TRANSPORT",
    "SMSG_PET_BROKEN",
    "MSG_MOVE_FEATHER_FALL",
    "MSG_MOVE_WATER_WALK",
    "CMSG_SERVER_BROADCAST",
    "CMSG_SELF_RES",
    "SMSG_FEIGN_DEATH_RESISTED",
    "CMSG_RUN_SCRIPT",
    "SMSG_SCRIPT_MESSAGE",
    "SMSG_DUEL_COUNTDOWN",
    "SMSG_AREA_TRIGGER_MESSAGE",
    "CMSG_TOGGLE_HELM",
    "CMSG_TOGGLE_CLOAK",
    "SMSG_MEETINGSTONE_JOINFAILED",
    "SMSG_PLAYER_SKINNED",
    "SMSG_DURABILITY_DAMAGE_DEATH",
    "CMSG_SET_EXPLORATION",
    "CMSG_SET_ACTIONBAR_TOGGLES",
    "UMSG_DELETE_GUILD_CHARTER",
    "MSG_PETITION_RENAME",
    "SMSG_INIT_WORLD_STATES",
    "SMSG_UPDATE_WORLD_STATE",
    "CMSG_ITEM_NAME_QUERY",
    "SMSG_ITEM_NAME_QUERY_RESPONSE",
    "SMSG_PET_ACTION_FEEDBACK",
    "CMSG_CHAR_RENAME",
    "SMSG_CHAR_RENAME",
    "CMSG_MOVE_SPLINE_DONE",
    "CMSG_MOVE_FALL_RESET",
    "SMSG_INSTANCE_SAVE_CREATED",
    "SMSG_RAID_INSTANCE_INFO",
    "CMSG_REQUEST_RAID_INFO",
    "CMSG_MOVE_TIME_SKIPPED",
    "CMSG_MOVE_FEATHER_FALL_ACK",
    "CMSG_MOVE_WATER_WALK_ACK",
    "CMSG_MOVE_NOT_ACTIVE_MOVER",
    "SMSG_PLAY_SOUND",
    "CMSG_BATTLEFIELD_STATUS",
    "SMSG_BATTLEFIELD_STATUS",
    "CMSG_BATTLEFIELD_PORT",
    "MSG_INSPECT_HONOR_STATS",
    "CMSG_BATTLEMASTER_HELLO",
    "CMSG_MOVE_START_SWIM_CHEAT",
    "CMSG_MOVE_STOP_SWIM_CHEAT",
    "SMSG_FORCE_WALK_SPEED_CHANGE",
    "CMSG_FORCE_WALK_SPEED_CHANGE_ACK",
    "SMSG_FORCE_SWIM_BACK_SPEED_CHANGE",
    "CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK",
    "SMSG_FORCE_TURN_RATE_CHANGE",
    "CMSG_FORCE_TURN_RATE_CHANGE_ACK",
    "MSG_PVP_LOG_DATA",
    "CMSG_LEAVE_BATTLEFIELD",
    "CMSG_AREA_SPIRIT_HEALER_QUERY",
    "CMSG_AREA_SPIRIT_HEALER_QUEUE",
    "SMSG_AREA_SPIRIT_HEALER_TIME",
    "CMSG_GM_UNTEACH",
    "SMSG_WARDEN_DATA",
    "CMSG_WARDEN_DATA",
    "SMSG_GROUP_JOINED_BATTLEGROUND",
    "MSG_BATTLEGROUND_PLAYER_POSITIONS",
    "CMSG_PET_STOP_ATTACK",
    "SMSG_BINDER_CONFIRM",
    "SMSG_BATTLEGROUND_PLAYER_JOINED",
    "SMSG_BATTLEGROUND_PLAYER_LEFT",
    "CMSG_BATTLEMASTER_JOIN",
    "SMSG_ADDON_INFO",
    "CMSG_PET_UNLEARN",
    "SMSG_PET_UNLEARN_CONFIRM",
    "SMSG_PARTY_MEMBER_STATS_FULL",
    "CMSG_PET_SPELL_AUTOCAST",
    "SMSG_WEATHER",
    "SMSG_PLAY_TIME_WARNING",
    "SMSG_MINIGAME_SETUP",
    "SMSG_MINIGAME_STATE",
    "CMSG_MINIGAME_MOVE",
    "SMSG_MINIGAME_MOVE_FAILED",
    "SMSG_RAID_INSTANCE_MESSAGE",
    "SMSG_COMPRESSED_MOVES",
    "CMSG_GUILD_INFO_TEXT",
    "SMSG_CHAT_RESTRICTED",
    "SMSG_SPLINE_SET_RUN_SPEED",
    "SMSG_SPLINE_SET_RUN_BACK_SPEED",
    "SMSG_SPLINE_SET_SWIM_SPEED",
    "SMSG_SPLINE_SET_WALK_SPEED",
    "SMSG_SPLINE_SET_SWIM_BACK_SPEED",
    "SMSG_SPLINE_SET_TURN_RATE",
    "SMSG_SPLINE_MOVE_UNROOT",
    "SMSG_SPLINE_MOVE_FEATHER_FALL",
    "SMSG_SPLINE_MOVE_NORMAL_FALL",
    "SMSG_SPLINE_MOVE_SET_HOVER",
    "SMSG_SPLINE_MOVE_UNSET_HOVER",
    "SMSG_SPLINE_MOVE_WATER_WALK",
    "SMSG_SPLINE_MOVE_LAND_WALK",
    "SMSG_SPLINE_MOVE_START_SWIM",
    "SMSG_SPLINE_MOVE_STOP_SWIM",
    "SMSG_SPLINE_MOVE_SET_RUN_MODE",
    "SMSG_SPLINE_MOVE_SET_WALK_MODE",
    "CMSG_GM_NUKE_ACCOUNT",
    "MSG_GM_DESTROY_CORPSE",
    "CMSG_GM_DESTROY_ONLINE_CORPSE",
    "CMSG_ACTIVATETAXIEXPRESS",
    "SMSG_SET_FACTION_ATWAR",
    "SMSG_GAMETIMEBIAS_SET",
    "CMSG_DEBUG_ACTIONS_START",
    "CMSG_DEBUG_ACTIONS_STOP",
    "CMSG_SET_FACTION_INACTIVE",
    "CMSG_SET_WATCHED_FACTION",
    "MSG_MOVE_TIME_SKIPPED",
    "SMSG_SPLINE_MOVE_ROOT",
    "CMSG_SET_EXPLORATION_ALL",
    "SMSG_INVALIDATE_PLAYER",
    "CMSG_RESET_INSTANCES",
    "SMSG_INSTANCE_RESET",
    "SMSG_INSTANCE_RESET_FAILED",
    "SMSG_UPDATE_LAST_INSTANCE",
    "MSG_RAID_TARGET_UPDATE",
    "MSG_RAID_READY_CHECK",
    "CMSG_LUA_USAGE",
    "SMSG_PET_ACTION_SOUND",
    "SMSG_PET_DISMISS_SOUND",
    "SMSG_GHOSTEE_GONE",
    "CMSG_GM_UPDATE_TICKET_STATUS",
    "SMSG_GM_TICKET_STATUS_UPDATE",
    "MSG_SET_DUNGEON_DIFFICULTY",
    "CMSG_GMSURVEY_SUBMIT",
    "SMSG_UPDATE_INSTANCE_OWNERSHIP",
    "CMSG_IGNORE_KNOCKBACK_CHEAT",
    "SMSG_CHAT_PLAYER_AMBIGUOUS",
    "MSG_DELAY_GHOST_TELEPORT",
    "SMSG_SPELLINSTAKILLLOG",
    "SMSG_SPELL_UPDATE_CHAIN_TARGETS",
    "CMSG_CHAT_FILTERED",
    "SMSG_EXPECTED_SPAM_RECORDS",
    "SMSG_SPELLSTEALLOG",
    "CMSG_LOTTERY_QUERY_OBSOLETE",
    "SMSG_LOTTERY_QUERY_RESULT_OBSOLETE",
    "CMSG_BUY_LOTTERY_TICKET_OBSOLETE",
    "SMSG_LOTTERY_RESULT_OBSOLETE",
    "SMSG_CHARACTER_PROFILE",
    "SMSG_CHARACTER_PROFILE_REALM_CONNECTED",
    "SMSG_DEFENSE_MESSAGE",
    "SMSG_INSTANCE_DIFFICULTY",
    "MSG_GM_RESETINSTANCELIMIT",
    "SMSG_MOTD",
    "SMSG_MOVE_SET_FLIGHT_OBSOLETE",
    "SMSG_MOVE_UNSET_FLIGHT_OBSOLETE",
    "CMSG_MOVE_FLIGHT_ACK_OBSOLETE",
    "MSG_MOVE_START_SWIM_CHEAT",
    "MSG_MOVE_STOP_SWIM_CHEAT",
    "SMSG_MOVE_SET_CAN_FLY",
    "SMSG_MOVE_UNSET_CAN_FLY",
    "CMSG_MOVE_SET_CAN_FLY_ACK",
    "CMSG_MOVE_SET_FLY",
    "CMSG_SOCKET_GEMS",
    "CMSG_ARENA_TEAM_CREATE",
    "SMSG_ARENA_TEAM_COMMAND_RESULT",
    "UMSG_UPDATE_ARENA_TEAM_OBSOLETE",
    "CMSG_ARENA_TEAM_QUERY",
    "SMSG_ARENA_TEAM_QUERY_RESPONSE",
    "CMSG_ARENA_TEAM_ROSTER",
    "SMSG_ARENA_TEAM_ROSTER",
    "CMSG_ARENA_TEAM_INVITE",
    "SMSG_ARENA_TEAM_INVITE",
    "CMSG_ARENA_TEAM_ACCEPT",
    "CMSG_ARENA_TEAM_DECLINE",
    "CMSG_ARENA_TEAM_LEAVE",
    "CMSG_ARENA_TEAM_REMOVE",
    "CMSG_ARENA_TEAM_DISBAND",
    "CMSG_ARENA_TEAM_LEADER",
    "SMSG_ARENA_TEAM_EVENT",
    "CMSG_BATTLEMASTER_JOIN_ARENA",
    "MSG_MOVE_START_ASCEND",
    "MSG_MOVE_STOP_ASCEND",
    "SMSG_ARENA_TEAM_STATS",
    "CMSG_LFG_SET_AUTOJOIN",
    "CMSG_LFG_CLEAR_AUTOJOIN",
    "CMSG_LFM_SET_AUTOFILL",
    "CMSG_LFM_CLEAR_AUTOFILL",
    "CMSG_ACCEPT_LFG_MATCH",
    "CMSG_DECLINE_LFG_MATCH",
    "CMSG_CANCEL_PENDING_LFG",
    "CMSG_CLEAR_LOOKING_FOR_GROUP",
    "CMSG_CLEAR_LOOKING_FOR_MORE",
    "CMSG_SET_LOOKING_FOR_MORE",
    "CMSG_SET_LFG_COMMENT",
    "SMSG_LFG_TIMEDOUT",
    "SMSG_LFG_OTHER_TIMEDOUT",
    "SMSG_LFG_AUTOJOIN_FAILED",
    "SMSG_LFG_AUTOJOIN_FAILED_NO_PLAYER",
    "SMSG_LFG_LEADER_IS_LFM",
    "SMSG_LFG_UPDATE",
    "SMSG_LFG_UPDATE_LFM",
    "SMSG_LFG_UPDATE_LFG",
    "SMSG_LFG_UPDATE_QUEUED",
    "SMSG_LFG_PENDING_INVITE",
    "SMSG_LFG_PENDING_MATCH",
    "SMSG_LFG_PENDING_MATCH_DONE",
    "SMSG_TITLE_EARNED",
    "CMSG_SET_TITLE",
    "CMSG_CANCEL_MOUNT_AURA",
    "SMSG_ARENA_ERROR",
    "MSG_INSPECT_ARENA_TEAMS",
    "SMSG_DEATH_RELEASE_LOC",
    "CMSG_CANCEL_TEMP_ENCHANTMENT",
    "SMSG_FORCED_DEATH_UPDATE",
    "CMSG_CHEAT_SET_HONOR_CURRENCY",
    "CMSG_CHEAT_SET_ARENA_CURRENCY",
    "MSG_MOVE_SET_FLIGHT_SPEED_CHEAT",
    "MSG_MOVE_SET_FLIGHT_SPEED",
    "MSG_MOVE_SET_FLIGHT_BACK_SPEED_CHEAT",
    "MSG_MOVE_SET_FLIGHT_BACK_SPEED",
    "SMSG_FORCE_FLIGHT_SPEED_CHANGE",
    "CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK",
    "SMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE",
    "CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK",
    "SMSG_SPLINE_SET_FLIGHT_SPEED",
    "SMSG_SPLINE_SET_FLIGHT_BACK_SPEED",
    "CMSG_MAELSTROM_INVALIDATE_CACHE",
    "SMSG_FLIGHT_SPLINE_SYNC",
    "CMSG_SET_TAXI_BENCHMARK_MODE",
    "SMSG_JOINED_BATTLEGROUND_QUEUE",
    "SMSG_REALM_SPLIT",
    "CMSG_REALM_SPLIT",
    "CMSG_MOVE_CHNG_TRANSPORT",
    "MSG_PARTY_ASSIGNMENT",
    "SMSG_OFFER_PETITION_ERROR",
    "SMSG_TIME_SYNC_REQ",
    "CMSG_TIME_SYNC_RESP",
    "CMSG_SEND_LOCAL_EVENT",
    "CMSG_SEND_GENERAL_TRIGGER",
    "CMSG_SEND_COMBAT_TRIGGER",
    "CMSG_MAELSTROM_GM_SENT_MAIL",
    "SMSG_RESET_FAILED_NOTIFY",
    "SMSG_REAL_GROUP_UPDATE",
    "SMSG_LFG_DISABLED",
    "CMSG_ACTIVE_PVP_CHEAT",
    "CMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY",
    "SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE",
    "SMSG_CHEAT_DUMP_ITEMS_DEBUG_ONLY_RESPONSE_WRITE_FILE",
    "SMSG_UPDATE_COMBO_POINTS",
    "SMSG_VOICE_SESSION_ROSTER_UPDATE",
    "SMSG_VOICE_SESSION_LEAVE",
    "SMSG_VOICE_SESSION_ADJUST_PRIORITY",
    "CMSG_VOICE_SET_TALKER_MUTED_REQUEST",
    "SMSG_VOICE_SET_TALKER_MUTED",
    "SMSG_INIT_EXTRA_AURA_INFO",
    "SMSG_SET_EXTRA_AURA_INFO",
    "SMSG_SET_EXTRA_AURA_INFO_NEED_UPDATE",
    "SMSG_CLEAR_EXTRA_AURA_INFO",
    "MSG_MOVE_START_DESCEND",
    "CMSG_IGNORE_REQUIREMENTS_CHEAT",
    "SMSG_IGNORE_REQUIREMENTS_CHEAT",
    "SMSG_SPELL_CHANCE_PROC_LOG",
    "CMSG_MOVE_SET_RUN_SPEED",
    "SMSG_DISMOUNT",
    "MSG_MOVE_UPDATE_CAN_FLY",
    "MSG_RAID_READY_CHECK_CONFIRM",
    "CMSG_VOICE_SESSION_ENABLE",
    "SMSG_VOICE_PARENTAL_CONTROLS",
    "CMSG_GM_WHISPER",
    "SMSG_GM_MESSAGECHAT",
    "MSG_GM_GEARRATING",
    "CMSG_COMMENTATOR_ENABLE",
    "SMSG_COMMENTATOR_STATE_CHANGED",
    "CMSG_COMMENTATOR_GET_MAP_INFO",
    "SMSG_COMMENTATOR_MAP_INFO",
    "CMSG_COMMENTATOR_GET_PLAYER_INFO",
    "SMSG_COMMENTATOR_GET_PLAYER_INFO",
    "SMSG_COMMENTATOR_PLAYER_INFO",
    "CMSG_COMMENTATOR_ENTER_INSTANCE",
    "CMSG_COMMENTATOR_EXIT_INSTANCE",
    "CMSG_COMMENTATOR_INSTANCE_COMMAND",
    "SMSG_CLEAR_TARGET",
    "CMSG_BOT_DETECTED",
    "SMSG_CROSSED_INEBRIATION_THRESHOLD",
    "CMSG_CHEAT_PLAYER_LOGIN",
    "CMSG_CHEAT_PLAYER_LOOKUP",
    "SMSG_CHEAT_PLAYER_LOOKUP",
    "SMSG_KICK_REASON",
    "MSG_RAID_READY_CHECK_FINISHED",
    "CMSG_COMPLAIN",
    "SMSG_COMPLAIN_RESULT",
    "SMSG_FEATURE_SYSTEM_STATUS",
    "CMSG_GM_SHOW_COMPLAINTS",
    "CMSG_GM_UNSQUELCH",
    "CMSG_CHANNEL_SILENCE_VOICE",
    "CMSG_CHANNEL_SILENCE_ALL",
    "CMSG_CHANNEL_UNSILENCE_VOICE",
    "CMSG_CHANNEL_UNSILENCE_ALL",
    "CMSG_TARGET_CAST",
    "CMSG_TARGET_SCRIPT_CAST",
    "CMSG_CHANNEL_DISPLAY_LIST",
    "CMSG_SET_ACTIVE_VOICE_CHANNEL",
    "CMSG_GET_CHANNEL_MEMBER_COUNT",
    "SMSG_CHANNEL_MEMBER_COUNT",
    "CMSG_CHANNEL_VOICE_ON",
    "CMSG_CHANNEL_VOICE_OFF",
    "CMSG_DEBUG_LIST_TARGETS",
    "SMSG_DEBUG_LIST_TARGETS",
    "SMSG_AVAILABLE_VOICE_CHANNEL",
    "CMSG_ADD_VOICE_IGNORE",
    "CMSG_DEL_VOICE_IGNORE",
    "CMSG_PARTY_SILENCE",
    "CMSG_PARTY_UNSILENCE",
    "MSG_NOTIFY_PARTY_SQUELCH",
    "SMSG_COMSAT_RECONNECT_TRY",
    "SMSG_COMSAT_DISCONNECT",
    "SMSG_COMSAT_CONNECT_FAIL",
    "SMSG_VOICE_CHAT_STATUS",
    "CMSG_REPORT_PVP_AFK",
    "CMSG_REPORT_PVP_AFK_RESULT",
    "CMSG_GUILD_BANKER_ACTIVATE",
    "CMSG_GUILD_BANK_QUERY_TAB",
    "SMSG_GUILD_BANK_LIST",
    "CMSG_GUILD_BANK_SWAP_ITEMS",
    "CMSG_GUILD_BANK_BUY_TAB",
    "CMSG_GUILD_BANK_UPDATE_TAB",
    "CMSG_GUILD_BANK_DEPOSIT_MONEY",
    "CMSG_GUILD_BANK_WITHDRAW_MONEY",
    "MSG_GUILD_BANK_LOG_QUERY",
    "CMSG_SET_CHANNEL_WATCH",
    "SMSG_USERLIST_ADD",
    "SMSG_USERLIST_REMOVE",
    "SMSG_USERLIST_UPDATE",
    "CMSG_CLEAR_CHANNEL_WATCH",
    "SMSG_INSPECT_TALENT",
    "SMSG_GOGOGO_OBSOLETE",
    "SMSG_ECHO_PARTY_SQUELCH",
    "CMSG_SET_TITLE_SUFFIX",
    "CMSG_SPELLCLICK",
    "SMSG_LOOT_LIST",
    "CMSG_GM_CHARACTER_RESTORE",
    "CMSG_GM_CHARACTER_SAVE",
    "SMSG_VOICESESSION_FULL",
    "MSG_GUILD_PERMISSIONS",
    "MSG_GUILD_BANK_MONEY_WITHDRAWN",
    "MSG_GUILD_EVENT_LOG_QUERY",
    "CMSG_MAELSTROM_RENAME_GUILD",
    "CMSG_GET_MIRRORIMAGE_DATA",
    "SMSG_MIRRORIMAGE_DATA",
    "SMSG_FORCE_DISPLAY_UPDATE",
    "SMSG_SPELL_CHANCE_RESIST_PUSHBACK",
    "CMSG_IGNORE_DIMINISHING_RETURNS_CHEAT",
    "SMSG_IGNORE_DIMINISHING_RETURNS_CHEAT",
    "CMSG_KEEP_ALIVE",
    "SMSG_RAID_READY_CHECK_ERROR",
    "CMSG_OPT_OUT_OF_LOOT",
    "MSG_QUERY_GUILD_BANK_TEXT",
    "CMSG_SET_GUILD_BANK_TEXT",
    "CMSG_SET_GRANTABLE_LEVELS",
    "CMSG_GRANT_LEVEL",
    "CMSG_REFER_A_FRIEND",
    "MSG_GM_CHANGE_ARENA_RATING",
    "CMSG_DECLINE_CHANNEL_INVITE",
    "CMSG_GROUPACTION_THROTTLED",
    "SMSG_OVERRIDE_LIGHT",
    "SMSG_TOTEM_CREATED",
    "CMSG_TOTEM_DESTROYED",
    "CMSG_EXPIRE_RAID_INSTANCE",
    "CMSG_NO_SPELL_VARIANCE",
    "CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY",
    "SMSG_QUESTGIVER_STATUS_MULTIPLE",
    "CMSG_SET_PLAYER_DECLINED_NAMES",
    "SMSG_SET_PLAYER_DECLINED_NAMES_RESULT",
    "CMSG_QUERY_SERVER_BUCK_DATA",
    "CMSG_CLEAR_SERVER_BUCK_DATA",
    "SMSG_SERVER_BUCK_DATA",
    "SMSG_SEND_UNLEARN_SPELLS",
    "SMSG_PROPOSE_LEVEL_GRANT",
    "CMSG_ACCEPT_LEVEL_GRANT",
    "SMSG_REFER_A_FRIEND_FAILURE",
    "SMSG_SPLINE_MOVE_SET_FLYING",
    "SMSG_SPLINE_MOVE_UNSET_FLYING",
    "SMSG_SUMMON_CANCEL",
    ""
};

const char *GetOpcodeName(unsigned int id)
{
    if(id > MAX_OPCODE_ID)
        return "";
    return worldOpcodeNames[id];
}

const unsigned int GetOpcodeID(const char *name)
{
    for(unsigned int i=0; strlen(worldOpcodeNames[i]); i++)
    {
        if(!stricmp(worldOpcodeNames[i], name))
        {
            return i;
        }
    }
    return -1; // invalid name
}
