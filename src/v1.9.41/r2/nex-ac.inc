//Nex-AC by Nexius v1.9.41 (0.3.7-R2)

#if defined _nex_ac_included
	#endinput
#endif
#define _nex_ac_included

#include <a_samp>

#if !defined OnTrailerUpdate
	#error Please download SA-MP 0.3.7 R2 server package!
#endif

#if !defined FILTERSCRIPT

#if !defined DEBUG
	#define DEBUG
#endif

#if !defined NO_SUSPICION_LOGS
	//#define NO_SUSPICION_LOGS
#endif

#if defined NO_SUSPICION_LOGS
	#pragma unused SUSPICION_1
	#pragma unused SUSPICION_2
#endif

#if !defined _nex_ac_lang_included
	#include <nex-ac_en.lang>	//Localization
#endif

#define	NEX_AC_VERSION				"1.9.41"
#define AC_SERVER_VERSION			"0.3.7-R2"

#if !defined AC_CONFIG_FILE
	#define AC_CONFIG_FILE				"nex-ac_settings.cfg"
#endif

#if !defined AC_MAX_CLASSES
	#define AC_MAX_CLASSES				320
#endif

#if !defined AC_DEFAULT_COLOR
	#define AC_DEFAULT_COLOR			-1
#endif

#if !defined AC_USE_VENDING_MACHINES
	#define AC_USE_VENDING_MACHINES		true
#endif

#if !defined AC_USE_TUNING_GARAGES
	#define AC_USE_TUNING_GARAGES		true
#endif

#if !defined AC_USE_PICKUP_WEAPONS
	#define AC_USE_PICKUP_WEAPONS		true
#endif

#if !defined AC_USE_AMMUNATIONS
	#define AC_USE_AMMUNATIONS			true
#endif

#if !defined AC_USE_RESTAURANTS
	#define AC_USE_RESTAURANTS			true
#endif

#if !defined AC_USE_PAYNSPRAY
	#define AC_USE_PAYNSPRAY			true
#endif

#if !defined AC_USE_CASINOS
	#define AC_USE_CASINOS				true
#endif

#if !defined AC_USE_QUERY
	#define AC_USE_QUERY				true
#endif

#if !defined AC_MAX_CONNECTS_FROM_IP
	#define AC_MAX_CONNECTS_FROM_IP			1
#endif

#if !defined AC_MAX_RCON_LOGIN_ATTEMPT
	#define AC_MAX_RCON_LOGIN_ATTEMPT		1
#endif

#if !defined AC_MAX_MSGS_REC_DIFF
	#define AC_MAX_MSGS_REC_DIFF			800
#endif

#if !defined AC_MAX_PING
	#define AC_MAX_PING						500
#endif

#if !defined AC_MIN_TIME_RECONNECT
	#define AC_MIN_TIME_RECONNECT			12		//In seconds
#endif

#if !defined AC_SPEEDHACK_VEH_RESET_DELAY
	#define AC_SPEEDHACK_VEH_RESET_DELAY	3		//In seconds
#endif

#if !defined AC_MAX_NOP_WARNINGS
	#define AC_MAX_NOP_WARNINGS				8
#endif

#if !defined AC_MAX_NOP_TIMER_WARNINGS
	#define AC_MAX_NOP_TIMER_WARNINGS		3
#endif

#if !defined AC_MAX_PING_WARNINGS
	#define AC_MAX_PING_WARNINGS			8
#endif

#if !defined AC_MAX_AIR_WARNINGS
	#define AC_MAX_AIR_WARNINGS				3
#endif

#if !defined AC_MAX_AIR_VEH_WARNINGS
	#define AC_MAX_AIR_VEH_WARNINGS			3
#endif

#if !defined AC_MAX_FLYHACK_VEH_WARNINGS
	#define AC_MAX_FLYHACK_VEH_WARNINGS		3
#endif

#if !defined AC_MAX_FLYHACK_BIKE_WARNINGS
	#define AC_MAX_FLYHACK_BIKE_WARNINGS	5
#endif

#if !defined AC_MAX_CARSHOT_WARNINGS
	#define AC_MAX_CARSHOT_WARNINGS			4
#endif

#if !defined AC_MAX_PRO_AIM_WARNINGS
	#define AC_MAX_PRO_AIM_WARNINGS			2
#endif

#if !defined AC_MAX_AFK_GHOST_WARNINGS
	#define AC_MAX_AFK_GHOST_WARNINGS		2
#endif

#if !defined AC_MAX_RAPID_FIRE_WARNINGS
	#define AC_MAX_RAPID_FIRE_WARNINGS		16
#endif

#if !defined AC_MAX_AUTO_C_WARNINGS
	#define AC_MAX_AUTO_C_WARNINGS			8
#endif

#if !defined AC_MAX_GODMODE_WARNINGS
	#define AC_MAX_GODMODE_WARNINGS			2
#endif

#if !defined AC_MAX_GODMODE_VEH_WARNINGS
	#define AC_MAX_GODMODE_VEH_WARNINGS		2
#endif

#if !defined AC_MAX_SILENT_AIM_WARNINGS
	#define AC_MAX_SILENT_AIM_WARNINGS		2
#endif

#if !defined AC_MAX_FAKE_WEAPON_WARNINGS
	#define AC_MAX_FAKE_WEAPON_WARNINGS		1
#endif

#if !defined AC_MAX_FLYHACK_WARNINGS
	#define AC_MAX_FLYHACK_WARNINGS			2
#endif

#if !defined AC_MAX_SPEEDHACK_VEH_WARNINGS
	#define AC_MAX_SPEEDHACK_VEH_WARNINGS	(1 * AC_SPEEDHACK_VEH_RESET_DELAY)
#endif

#if !defined AC_MAX_SPEEDHACK_WARNINGS
	#define AC_MAX_SPEEDHACK_WARNINGS		4
#endif

#if !defined AC_MAX_CJ_RUN_WARNINGS
	#define AC_MAX_CJ_RUN_WARNINGS			3
#endif

#if !defined AC_MAX_MONEY_WARNINGS
	#define AC_MAX_MONEY_WARNINGS			2
#endif

#define ac_fpublic%0(%1) forward%0(%1); public%0(%1)
#define ac_AbsoluteAngle(%0) floatadd(floatround(%0, floatround_floor) % 360, floatfract(%0))
#define ac_abs(%0) (((%0) < 0) ? (-(%0)) : ((%0)))

//'ac_ACAllow' contains the default settings that will be set if no config file will be found
//Don't change these values if you already have 'scriptfiles\nex-ac_settings.cfg'
static bool:ac_ACAllow[] =
{
	true,	//0 Anti-AirBreak (onfoot)
	true,	//1 Anti-AirBreak (in vehicle)
	true,	//2 Anti-teleport hack (onfoot)
	true,	//3 Anti-teleport hack (in vehicle)
	true,	//4 Anti-teleport hack (into/between vehicles)
	true,	//5 Anti-teleport hack (vehicle to player)
	true,	//6 Anti-teleport hack (pickups)
	true,	//7 Anti-FlyHack (onfoot)
	true,	//8 Anti-FlyHack (in vehicle)
	true,	//9 Anti-SpeedHack (onfoot)
	true,	//10 Anti-SpeedHack (in vehicle)
	true,	//11 Anti-Health hack (in vehicle)
	true,	//12 Anti-Health hack (onfoot)
	true,	//13 Anti-Armour hack
	true,	//14 Anti-Money hack
	true,	//15 Anti-Weapon hack
	true,	//16 Anti-Ammo hack (add)
	true,	//17 Anti-Ammo hack (infinite)
	true,	//18 Anti-Special actions hack
	true,	//19 Anti-GodMode from bullets (onfoot)
	true,	//20 Anti-GodMode from bullets (in vehicle)
	true,	//21 Anti-Invisible hack
	true,	//22 Anti-lagcomp-spoof
	true,	//23 Anti-Tuning hack
	false,	//24 Anti-Parkour mod
	true,	//25 Anti-Quick turn
	true,	//26 Anti-Rapid fire
	true,	//27 Anti-FakeSpawn
	true,	//28 Anti-FakeKill
	true,	//29 Anti-Pro Aim
	true,	//30 Anti-CJ run
	true,	//31 Anti-CarShot
	true,	//32 Anti-CarJack
	false,	//33 Anti-UnFreeze
	true,	//34 Anti-AFK Ghost
	true,	//35 Anti-Full Aiming

	false,	//36 Anti-Fake NPC
	true,	//37 Anti-Reconnect
	true,	//38 Anti-High ping
	true,	//39 Anti-Dialog hack
	true,	//40 Protection from the sandbox
	true,	//41 Protection against an invalid version
	true,	//42 Anti-Rcon hack

	true,	//43 Anti-Tuning crasher
	true,	//44 Anti-Invalid seat crasher
	true,	//45 Anti-Dialog crasher
	true,	//46 Anti-Attached object crasher
	true,	//47 Anti-Weapon Crasher

	true,	//48 Flood protection connects to one slot
	true,	//49 Anti-flood callback functions
	true,	//50 Anti-flood change seat

	true,	//51 Anti-Ddos

	true	//52 Anti-NOP's
},

bool:ac_NOPAllow[] =
{
	true,	//0 Anti-NOP GivePlayerWeapon
	true,	//1 Anti-NOP SetPlayerAmmo
	true,	//2 Anti-NOP SetPlayerInterior
	true,	//3 Anti-NOP SetPlayerHealth
	true,	//4 Anti-NOP SetVehicleHealth
	true,	//5 Anti-NOP SetPlayerArmour
	true,	//6 Anti-NOP SetPlayerSpecialAction
	true,	//7 Anti-NOP PutPlayerInVehicle
	true,	//8 Anti-NOP TogglePlayerSpectating
	true,	//9 Anti-NOP SpawnPlayer
	true,	//10 Anti-NOP SetPlayerPos
	true	//11 Anti-NOP RemovePlayerFromVehicle
};

static const ac_Mtfc[][] =
{
	{150, 5},	//0 OnDialogResponse
	{800, 2},	//1 OnEnterExitModShop
	{250, 5},	//2 OnPlayerClickMap
	{450, 5},	//3 OnPlayerClickPlayer
	{50, 8},	//4 OnPlayerClickTextDraw
	{400, 5},	//5 OnPlayerCommandText
	{50, 8},	//6 OnPlayerEnterVehicle
	{50, 11},	//7 OnPlayerExitVehicle
	{150, 8},	//8 OnPlayerPickUpPickup
	{150, 8},	//9 OnPlayerRequestClass
	{150, 5},	//10 OnPlayerSelectedMenuRow
	{600, 5},	//11 OnPlayerStateChange
	{450, 2},	//12 OnVehicleMod
	{450, 2},	//13 OnVehiclePaintjob
	{450, 2},	//14 OnVehicleRespray
	{300, 1},	//15 OnVehicleDeath
	{450, 3},	//16 OnPlayerText
	{150, 8},	//17 OnPlayerEnterCheckpoint
	{150, 8},	//18 OnPlayerLeaveCheckpoint
	{150, 5},	//19 OnPlayerRequestSpawn
	{150, 5},	//20 OnPlayerExitedMenu
	{150, 8},	//21 OnPlayerEnterRaceCheckpoint
	{150, 8},	//22 OnPlayerLeaveRaceCheckpoint
	{50, 8},	//23 OnPlayerClickPlayerTextDraw
	{51, 9},	//24 OnVehicleDamageStatusUpdate
	{150, 8},	//25 OnVehicleSirenStateChange
	{150, 5},	//26 OnPlayerSelectObject
	{50, 8}		//27 Cross-public
},

ac_wSlot[] =
{
	0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 10, 10,
	10, 8, 8, 8, 0, 0, 0, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5,
	4, 6, 6, 7, 7, 7, 7, 8, 12, 9, 9, 9, 11, 11, 11
},

#if AC_USE_PICKUP_WEAPONS
	ac_wModel[] =
	{
		0, 331, 333, 334, 335, 336, 337, 338, 339, 341, 321, 322, 323, 324, 325,
		326, 342, 343, 344, 0, 0, 345, 346, 347, 348, 349, 350, 351, 352, 353, 355, 356,
		372, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 371
	},
#endif

ac_vType[] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
	0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 3, 2, 5, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0,
	1, 5, 5, 5, 0, 0, 0, 0, 5, 2, 0, 5, 3, 3, 0, 0, 1, 0, 0, 0,
	0, 4, 0, 0, 3, 0, 0, 2, 2, 0, 0, 0, 0, 3, 0, 0, 0, 2, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 1, 1, 1, 0, 0, 0, 0, 0, 1,
	1, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
	0, 5, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 1, 1, 0, 3, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
},

#if AC_USE_TUNING_GARAGES
	ac_cPrice[] =
	{
		400, 550, 200, 250, 100, 150, 80, 500, 500, 200, 1000, 220, 250, 100, 400,
		500, 200, 500, 350, 300, 250, 200, 150, 350, 50, 1000, 480, 480, 770, 680, 370,
		370, 170, 120, 790, 150, 500, 690, 190, 390, 500, 390, 1000, 500, 500, 510, 710,
		670, 530, 810, 620, 670, 530, 130, 210, 230, 520, 430, 620, 720, 530, 180, 550, 430,
		830, 850, 750, 250, 200, 550, 450, 550, 450, 1100, 1030, 980, 1560, 1620, 1200,
		1030, 900, 1230, 820, 1560, 1350, 770, 100, 1500, 150, 650, 450, 100, 750,
		350, 450, 350, 1000, 620, 1140, 1000, 940, 780, 830, 3250, 1610, 1540, 780, 780, 780,
		1610, 1540, 0, 0, 3340, 3250, 2130, 2050, 2040, 780, 940, 780, 940, 780, 860,
		780, 1120, 3340, 3250, 3340, 1650, 3380, 3290, 1590, 830, 800, 1500, 1000, 800,
		580, 470, 870, 980, 150, 150, 100, 100, 490, 600, 890, 1000, 1090, 840, 910,
		1200, 1030, 1030, 920, 930, 550, 1050, 1050, 950, 650, 450, 550, 850, 950,
		850, 950, 970, 880, 990, 900, 950, 1000, 900, 1000, 900, 2050, 2150, 2130,
		2050, 2130, 2040, 2150, 2040, 2095, 2175, 2080, 2200, 1200, 1040, 940, 1100
	},
#endif

ac_MaxPassengers[] =
{
	0x10331113, 0x11311131, 0x11331313, 0x80133301, 0x1381F110,
	0x10311103, 0x10001F10, 0x11113311, 0x13113311, 0x31101100,
	0x30002301, 0x11031311, 0x11111331, 0x10013111, 0x01131100,
	0x11111110, 0x11100031, 0x11130221, 0x33113311, 0x11111101,
	0x33101133, 0x10100550, 0x03133111, 0xFF11113F, 0x13330111,
	0xFF131111, 0x0000FF3F
},

ac_vMods[] =
{
	0x033C2700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x021A27FA, 0x00000000, 0x00FFFE00,
	0x00000007, 0x0003C000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x023B2785, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02BC4703, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x03BA278A, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x028E078A, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02310744, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x0228073A, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02BD4701, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x023A2780, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x0228077A, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x027A27CA, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x0282278A, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x023E07C0, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x03703730, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x031D2775, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02BE4788, 0x00000000, 0x00FFFE00,
	0x00000007, 0x0003C000, 0x00000000, 0x02010771, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x029A0FCE, 0x00000000, 0x00FFFE00, 0x00000007, 0x0000C000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x03382700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x023F8795, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x029F078C, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000, 0x029627EA, 0x00000000, 0x00FFFE00,
	0x00000007, 0x0003C000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x0236C782, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x029E1FCA, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0xFC000437, 0x00000000, 0x021C0000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x03FE6007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00001B87, 0x00000001, 0x01E00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x039E07D2, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x023CC700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00030000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x038E07D6, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x023D0709, 0x00000000, 0x00FFFE00, 0x00000007, 0x0000C000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x029E1F8A, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x029C077A, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000, 0x02BD076C, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0xFFFFFE00, 0x00000007, 0x00000000, 0x000001F8,
	0x02000700, 0x00000000, 0x00FFFFFE, 0x00000007, 0xC0000000, 0x00002007, 0xFE000700, 0x00000003, 0x00FFFE00,
	0x00000007, 0x00003C00, 0x00000600, 0xCE000700, 0xFF800000, 0x00FFFE01, 0x00000007, 0x3C000000, 0x00000000,
	0x02000700, 0x000003FC, 0x00FFFE00, 0x00000007, 0x003C0000, 0x00001800, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x007FE000, 0x00FFFE00, 0x00000007, 0x03C00000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000047, 0x0000003E, 0x3C000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00001C00, 0x00FFFE00,
	0x0000000F, 0x00000000, 0x0003C000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x000003C0, 0xC0000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x029607C2, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x03FFE7CF, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x031727F1, 0x00000000, 0x00FFFE00, 0x00000007, 0x00030000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x025627F0, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x039E07C2, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000, 0x02000700, 0x00000000, 0x00FFFE00,
	0x00000007, 0x00000000, 0x00000000
},

#if AC_USE_AMMUNATIONS
	ac_AmmuNationInfo[][] =
	{
		{200, 30}, {600, 30}, {1200, 15},
		{600, 15}, {800, 12}, {1000, 10},
		{500, 60}, {2000, 90}, {3500, 120},
		{4500, 150}, {300, 60}
	},

	Float:ac_AmmuNations[][] =
	{
		{296.5541, -38.5138, 1001.5156},
		{295.7008, -80.8109, 1001.5156},
		{290.1963, -109.7721, 1001.5156},
		{312.2592, -166.1385, 999.601}
	},
#endif

#if AC_USE_RESTAURANTS
	Float:ac_Restaurants[][] =
	{
		{374.0, -119.641, 1001.4922},
		{368.789, -6.857, 1001.8516},
		{375.566, -68.222, 1001.5151}
	},
#endif

#if AC_USE_PAYNSPRAY
	Float:ac_PayNSpray[][] =
	{
		{2064.2842, -1831.4736, 13.5469},
		{-2425.7822, 1021.1392, 50.3977},
		{-1420.5195, 2584.2305, 55.8433},
		{487.6401, -1739.9479, 11.1385},
		{1024.8651, -1024.087, 32.1016},
		{-1904.7019, 284.5968, 41.0469},
		{1975.2384, 2162.5088, 11.0703},
		{2393.4456, 1491.5537, 10.5616},
		{720.0854, -455.2807, 16.3359},
		{-99.9417, 1117.9048, 19.7417}
	},
#endif

#if AC_USE_VENDING_MACHINES
	Float:ac_vMachines[][] =
	{
		{-862.82, 1536.6, 21.98},
		{2271.72, -76.46, 25.96},
		{1277.83, 372.51, 18.95},
		{662.42, -552.16, 15.71},
		{201.01, -107.61, 0.89},
		{-253.74, 2597.95, 62.24},
		{-253.74, 2599.75, 62.24},
		{-76.03, 1227.99, 19.12},
		{-14.7, 1175.35, 18.95},
		{-1455.11, 2591.66, 55.23},
		{2352.17, -1357.15, 23.77},
		{2325.97, -1645.13, 14.21},
		{2139.51, -1161.48, 23.35},
		{2153.23, -1016.14, 62.23},
		{1928.73, -1772.44, 12.94},
		{1154.72, -1460.89, 15.15},
		{2480.85, -1959.27, 12.96},
		{2060.11, -1897.64, 12.92},
		{1729.78, -1943.04, 12.94},
		{1634.1, -2237.53, 12.89},
		{1789.21, -1369.26, 15.16},
		{-2229.18, 286.41, 34.7},
		{2319.99, 2532.85, 10.21},
		{2845.72, 1295.04, 10.78},
		{2503.14, 1243.69, 10.21},
		{2647.69, 1129.66, 10.21},
		{-2420.21, 984.57, 44.29},
		{-2420.17, 985.94, 44.29},
		{2085.77, 2071.35, 10.45},
		{1398.84, 2222.6, 10.42},
		{1659.46, 1722.85, 10.21},
		{1520.14, 1055.26, 10.0},
		{-1980.78, 142.66, 27.07},
		{-2118.96, -423.64, 34.72},
		{-2118.61, -422.41, 34.72},
		{-2097.27, -398.33, 34.72},
		{-2092.08, -490.05, 34.72},
		{-2063.27, -490.05, 34.72},
		{-2005.64, -490.05, 34.72},
		{-2034.46, -490.05, 34.72},
		{-2068.56, -398.33, 34.72},
		{-2039.85, -398.33, 34.72},
		{-2011.14, -398.33, 34.72},
		{-1350.11, 492.28, 10.58},
		{-1350.11, 493.85, 10.58},
		{2222.36, 1602.64, 1000.06},
		{2222.2, 1606.77, 1000.05},
		{2155.9, 1606.77, 1000.05},
		{2155.84, 1607.87, 1000.06},
		{2209.9, 1607.19, 1000.05},
		{2202.45, 1617.0, 1000.06},
		{2209.24, 1621.21, 1000.06},
		{2576.7, -1284.43, 1061.09},
		{330.67, 178.5, 1020.07},
		{331.92, 178.5, 1020.07},
		{350.9, 206.08, 1008.47},
		{361.56, 158.61, 1008.47},
		{371.59, 178.45, 1020.07},
		{374.89, 188.97, 1008.47},
		{-19.03, -57.83, 1003.63},
		{-36.14, -57.87, 1003.63},
		{316.87, -140.35, 998.58},
		{2225.2, -1153.42, 1025.9},
		{-15.1, -140.22, 1003.63},
		{-16.53, -140.29, 1003.63},
		{-35.72, -140.22, 1003.63},
		{373.82, -178.14, 1000.73},
		{379.03, -178.88, 1000.73},
		{495.96, -24.32, 1000.73},
		{500.56, -1.36, 1000.73},
		{501.82, -1.42, 1000.73},
		{-33.87, -186.76, 1003.63},
		{-32.44, -186.69, 1003.63},
		{-16.11, -91.64, 1003.63},
		{-17.54, -91.71, 1003.63}
	},
#endif

#if AC_USE_CASINOS
	Float:ac_Casinos[][] =
	{
		{2241.2878, 1617.1624, 1006.1797, 2.0},
		{2240.9736, 1604.6592, 1006.1797, 6.0},
		{2242.5427, 1592.8726, 1006.1836, 6.0},
		{2230.2124, 1592.1426, 1006.1832, 6.0},
		{2230.4717, 1604.484, 1006.186, 6.0},
		{2230.3298, 1616.9272, 1006.1799, 3.0},
		{2251.9407, 1586.1736, 1006.186, 1.0},
		{2218.6785, 1587.3448, 1006.1749, 1.0},
		{2219.2773, 1591.7467, 1006.1867, 1.0},
		{2218.5408, 1589.3229, 1006.184, 1.0},
		{2218.6477, 1593.6279, 1006.1797, 1.0},
		{2221.926, 1603.8285, 1006.1797, 1.0},
		{2218.5095, 1603.8385, 1006.1797, 1.0},
		{2219.9597, 1603.9216, 1006.1797, 1.0},
		{2216.3054, 1603.7996, 1006.1819, 1.0},
		{2218.731, 1619.8046, 1006.1794, 1.0},
		{2218.9407, 1617.8413, 1006.1821, 1.0},
		{2218.668, 1615.4681, 1006.1797, 1.0},
		{2218.6418, 1613.2629, 1006.1797, 1.0},
		{2252.4272, 1589.8412, 1006.1797, 5.0},
		{2252.4229, 1596.6169, 1006.1797, 5.0},
		{2255.1565, 1608.8784, 1006.186, 1.0},
		{2254.8496, 1610.8605, 1006.1797, 1.0},
		{2255.2917, 1612.9167, 1006.1797, 1.0},
		{2255.033, 1614.8892, 1006.1797, 1.0},
		{2255.1213, 1616.8284, 1006.1797, 1.0},
		{2255.2161, 1618.8005, 1006.1797, 1.0},
		{2268.5281, 1606.4894, 1006.1797, 1.0},
		{2270.4922, 1606.8539, 1006.1797, 1.0},
		{2272.5693, 1606.4473, 1006.1797, 1.0},
		{2274.5391, 1607.0122, 1006.1797, 1.0},
		{2271.8447, 1586.1633, 1006.1797, 1.0},
		{2261.4844, 1586.1724, 1006.1797, 1.0},
		{2257.4507, 1589.6555, 1006.1797, 5.0},
		{2267.8994, 1589.8672, 1006.1797, 5.0},
		{2262.8486, 1590.026, 1006.1797, 5.0},
		{2272.6458, 1589.7704, 1006.1797, 5.0},
		{2272.6533, 1596.5682, 1006.1797, 5.0},
		{2270.4895, 1596.4606, 1006.1797, 5.0},
		{2265.4441, 1596.4299, 1006.1797, 5.0},
		{2260.0308, 1596.7987, 1006.1797, 5.0},
		{2254.9907, 1596.241, 1006.1797, 5.0},
		{1956.9524, 988.2533, 992.4688, 2.0},
		{1961.6155, 993.0375, 992.4688, 2.0},
		{1963.7998, 998.4406, 992.4745, 2.0},
		{1936.2885, 987.1995, 992.4745, 2.0},
		{1944.9768, 986.3937, 992.4688, 2.0},
		{1940.7397, 990.9521, 992.4609, 2.0},
		{1940.0966, 1005.8996, 992.4688, 6.0},
		{1938.8785, 1014.1768, 992.4688, 6.0},
		{1938.8811, 1021.4434, 992.4688, 6.0},
		{1966.5975, 1006.6469, 992.4745, 6.0},
		{1966.5979, 1014.1024, 992.4688, 6.0},
		{1939.8351, 1029.912, 992.4688, 6.0},
		{1956.854, 1047.3718, 992.4688, 6.0},
		{1961.356, 1042.8112, 992.4688, 6.0},
		{1963.811, 1037.1263, 992.4745, 6.0},
		{1961.733, 1025.8929, 992.4688, 10.0},
		{1961.708, 1010.3194, 992.4688, 10.0},
		{1966.5989, 1029.7954, 992.4745, 6.0},
		{1961.4139, 1017.8281, 992.4688, 10.0},
		{1966.5985, 1021.7686, 992.4688, 6.0},
		{1128.7106, -1.9779, 1000.6797, 1.0},
		{1125.2388, 1.61, 1000.6797, 1.0},
		{1125.1249, -5.0489, 1000.6797, 1.0},
		{1127.4139, 3.0199, 1000.6797, 1.0},
		{1135.0634, -3.8695, 1000.6797, 1.0},
		{1135.0861, 0.6107, 1000.6797, 1.0},
		{1132.8943, -1.7139, 1000.6797, 1.0},
		{1125.3727, 3.0315, 1000.6797, 1.0},
		{1119.0272, -1.4916, 1000.6924, 1.0}
	},
#endif

#if AC_USE_PICKUP_WEAPONS
	ac_pAmmo[] =
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 8, 8, 8, 0, 0, 4, 30, 10, 10, 15,
		10, 10, 60, 60, 80, 80, 60, 20, 10, 4, 3,
		100, 500, 5, 1, 500, 500, 36, 1, 1, 1
	},
#endif

Float:ac_wRange[] =
{
	25.0, 25.0, 25.0, 30.0, 25.0, 35.0,
	25.0, 35.0, 40.0, 40.0, 25.0, 55.0,
	50.0, 50.0, 50.0, 4.0, 65.0
};

enum acInfo
{
	Float:acPosX,
	Float:acPosY,
	Float:acPosZ,
	Float:acDropJpX,
	Float:acDropJpY,
	Float:acDropJpZ,
	Float:acSpawnPosX,
	Float:acSpawnPosY,
	Float:acSpawnPosZ,
	Float:acSetVehHealth,
	Float:acSetPosX,
	Float:acSetPosY,
	Float:acSetPosZ,
	acSpeed,
	acHealth,
	acArmour,
	acMoney,
	acLastShot,
	acLastWeapon,
	acEnterVeh,
	acKickVeh,
	acVeh,
	acSeat,
	acDialog,
	acNextDialog,
	acInt,
	acAnim,
	acDmgRes,
	acSpecAct,
	acNextSpecAct,
	acLastSpecAct,
	acLastPickup,
	acReloadTime,
	acShotTime,
	acSpawnTime,
	acSetPosTime,
	acUpdateTime,
	acEnterVehTime,
	acSpawnWeapon1,
	acSpawnWeapon2,
	acSpawnWeapon3,
	acSpawnAmmo1,
	acSpawnAmmo2,
	acSpawnAmmo3,
	acSpawnRes,
	acTimerID,
	acKickTimerID,
	acParachute,
	acIntRet,
	acKicked,
	acIp[16],
	acSet[13],
	acGtc[18],
	acWeapon[13],
	acAmmo[13],
	acSetWeapon[13],
	acGiveAmmo[13],
	acGtcSetWeapon[13],
	acGtcGiveAmmo[13],
	acNOPCount[12],
	acCheatCount[20],
	acCall[sizeof ac_Mtfc],
	acFloodCount[sizeof ac_Mtfc],
	bool:acNOPAllow[sizeof ac_NOPAllow],
	bool:acACAllow[sizeof ac_ACAllow],
	bool:acStuntBonus,
	bool:acModShop,
	bool:acUnFrozen,
	bool:acOnline,
	bool:acDeathRes,
	bool:acVehDmgRes,
	bool:acSpawned,
	bool:acDead,
	bool:acTpToZ,
	bool:acIntEnterExits,
	bool:acSpec
}

enum acVehInfo
{
	Float:acVelX,
	Float:acVelY,
	Float:acVelZ,
	Float:acPosX,
	Float:acPosY,
	Float:acPosZ,
	Float:acSpawnPosX,
	Float:acSpawnPosY,
	Float:acSpawnPosZ,
	Float:acSpawnZAngle,
	Float:acPosDiff,
	Float:acZAngle,
	Float:acHealth,
	acSpeedDiff,
	acDriver,
	acInt,
	acPaintJob,
	bool:acSpawned
}

enum acPickInfo
{
	Float:acPosX,
	Float:acPosY,
	Float:acPosZ,
	acType,
	acWeapon,
	bool:acIsStatic
}

static
	Float:ac_ClassPos[AC_MAX_CLASSES][3],
	ac_ClassWeapon[AC_MAX_CLASSES][3][2],

	ac_sInfo[6],

	ACInfo[MAX_PLAYERS][acInfo],
	ACVehInfo[MAX_VEHICLES][acVehInfo],
	ACPickInfo[MAX_PICKUPS][acPickInfo],

	bool:ac_IntEnterExits = true,
	bool:ac_StuntBonus = true,
	bool:ac_VehFriendlyFire,
	bool:ac_LagCompMode,
	#if !AC_USE_QUERY
		bool:ac_QueryEnable,
	#endif
	bool:ac_RconEnable,
	bool:ac_PedAnims;

ac_fpublic ac_AddStaticVehicle(vehicleid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle)
{
	ACVehInfo[vehicleid][acInt] =
	ACVehInfo[vehicleid][acSpeedDiff] = 0;
	ACVehInfo[vehicleid][acPaintJob] = 3;
	ACVehInfo[vehicleid][acSpawned] = true;
	ACVehInfo[vehicleid][acHealth] = 1000.0;
	ACVehInfo[vehicleid][acPosDiff] =
	ACVehInfo[vehicleid][acVelX] =
	ACVehInfo[vehicleid][acVelY] =
	ACVehInfo[vehicleid][acVelZ] = 0.0;
	ACVehInfo[vehicleid][acSpawnPosX] =
	ACVehInfo[vehicleid][acPosX] = spawn_x;
	ACVehInfo[vehicleid][acSpawnPosY] =
	ACVehInfo[vehicleid][acPosY] = spawn_y;
	ACVehInfo[vehicleid][acSpawnPosZ] =
	ACVehInfo[vehicleid][acPosZ] = spawn_z;
	ACVehInfo[vehicleid][acSpawnZAngle] =
	ACVehInfo[vehicleid][acZAngle] = z_angle;
	ACVehInfo[vehicleid][acDriver] = INVALID_PLAYER_ID;
	return 1;
}

ac_fpublic ac_CreateVehicle(vehicleid, ac_vehicletype, Float:x, Float:y, Float:z, Float:rotation)
{
	ACVehInfo[vehicleid][acInt] =
	ACVehInfo[vehicleid][acSpeedDiff] = 0;
	ACVehInfo[vehicleid][acPaintJob] = 3;
	ACVehInfo[vehicleid][acHealth] = 1000.0;
	ACVehInfo[vehicleid][acPosDiff] =
	ACVehInfo[vehicleid][acVelX] =
	ACVehInfo[vehicleid][acVelY] =
	ACVehInfo[vehicleid][acVelZ] = 0.0;
	ACVehInfo[vehicleid][acSpawnPosX] =
	ACVehInfo[vehicleid][acPosX] = x;
	ACVehInfo[vehicleid][acSpawnPosY] =
	ACVehInfo[vehicleid][acPosY] = y;
	ACVehInfo[vehicleid][acSpawnPosZ] =
	ACVehInfo[vehicleid][acPosZ] = z;
	ACVehInfo[vehicleid][acSpawnZAngle] =
	ACVehInfo[vehicleid][acZAngle] = rotation;
	if(!(569 <= ac_vehicletype <= 570)) ACVehInfo[vehicleid][acSpawned] = true;
	ACVehInfo[vehicleid][acDriver] = INVALID_PLAYER_ID;
	return 1;
}

ac_fpublic ac_AddPlayerClass(ac_classid, Float:ac_spawn_x, Float:ac_spawn_y, Float:ac_spawn_z, ac_weapon1, ac_weapon1_ammo, ac_weapon2, ac_weapon2_ammo, ac_weapon3, ac_weapon3_ammo)
{
	if(ac_classid < AC_MAX_CLASSES)
	{
		#undef AC_MAX_CLASSES
		ac_ClassPos[ac_classid][0] = ac_spawn_x;
		ac_ClassPos[ac_classid][1] = ac_spawn_y;
		ac_ClassPos[ac_classid][2] = ac_spawn_z;
		ac_ClassWeapon[ac_classid][0][0] = ac_weapon1;
		ac_ClassWeapon[ac_classid][0][1] = ac_weapon1_ammo;
		ac_ClassWeapon[ac_classid][1][0] = ac_weapon2;
		ac_ClassWeapon[ac_classid][1][1] = ac_weapon2_ammo;
		ac_ClassWeapon[ac_classid][2][0] = ac_weapon3;
		ac_ClassWeapon[ac_classid][2][1] = ac_weapon3_ammo;
	}
	return 1;
}

ac_fpublic ac_SetSpawnInfo(playerid, ac_team, ac_skin, Float:ac_x, Float:ac_y, Float:ac_z, Float:ac_rotation, ac_weapon1, ac_weapon1_ammo, ac_weapon2, ac_weapon2_ammo, ac_weapon3, ac_weapon3_ammo)
{
	if(!SetSpawnInfo(playerid, ac_team, ac_skin, ac_x, ac_y, ac_z, ac_rotation, ac_weapon1, ac_weapon1_ammo, ac_weapon2, ac_weapon2_ammo, ac_weapon3, ac_weapon3_ammo)) return 0;
	ACInfo[playerid][acSpawnPosX] = ac_x;
	ACInfo[playerid][acSpawnPosY] = ac_y;
	ACInfo[playerid][acSpawnPosZ] = ac_z;
	ACInfo[playerid][acSpawnWeapon1] = ac_weapon1;
	ACInfo[playerid][acSpawnAmmo1] = ac_weapon1_ammo;
	ACInfo[playerid][acSpawnWeapon2] = ac_weapon2;
	ACInfo[playerid][acSpawnAmmo2] = ac_weapon2_ammo;
	ACInfo[playerid][acSpawnWeapon3] = ac_weapon3;
	ACInfo[playerid][acSpawnAmmo3] = ac_weapon3_ammo;
	return 1;
}

ac_fpublic ac_AddStaticPickup(pickupid, ac_model, ac_type, Float:ac_X, Float:ac_Y, Float:ac_Z)
{
	#if AC_USE_PICKUP_WEAPONS
		ACPickInfo[pickupid][acWeapon] = 0;
		switch(ac_type)
		{
			case 2, 3, 15, 22:
			{
				switch(ac_model)
				{
					case 370: ACPickInfo[pickupid][acType] = 2;
					case 1240: ACPickInfo[pickupid][acType] = 3;
					case 1242: ACPickInfo[pickupid][acType] = 4;
					case 321..326, 331, 333..339, 341..353, 355..369, 371, 372:
					{
						for(new ac_i = 46; ac_i >= 0; --ac_i)
						{
							if(ac_wModel[ac_i] == ac_model)
							{
								ACPickInfo[pickupid][acType] = 1;
								ACPickInfo[pickupid][acWeapon] = ac_i;
								break;
							}
						}
					}
				}
			}
		}
	#endif
	ACPickInfo[pickupid][acIsStatic] = true;
	ACPickInfo[pickupid][acPosX] = ac_X;
	ACPickInfo[pickupid][acPosY] = ac_Y;
	ACPickInfo[pickupid][acPosZ] = ac_Z;
	return 1;
}

ac_fpublic ac_CreatePickup(pickupid, ac_model, ac_type, Float:ac_X, Float:ac_Y, Float:ac_Z)
{
	#if AC_USE_PICKUP_WEAPONS
		ACPickInfo[pickupid][acWeapon] = 0;
		switch(ac_type)
		{
			case 2, 3, 15, 22:
			{
				switch(ac_model)
				{
					case 370: ACPickInfo[pickupid][acType] = 2;
					case 1240: ACPickInfo[pickupid][acType] = 3;
					case 1242: ACPickInfo[pickupid][acType] = 4;
					case 321..326, 331, 333..339, 341..353, 355..369, 371, 372:
					{
						for(new ac_i = 46; ac_i >= 0; --ac_i)
						{
							if(ac_wModel[ac_i] == ac_model)
							{
								ACPickInfo[pickupid][acType] = 1;
								ACPickInfo[pickupid][acWeapon] = ac_i;
								break;
							}
						}
					}
				}
			}
		}
	#endif
	ACPickInfo[pickupid][acIsStatic] = false;
	ACPickInfo[pickupid][acPosX] = ac_X;
	ACPickInfo[pickupid][acPosY] = ac_Y;
	ACPickInfo[pickupid][acPosZ] = ac_Z;
	return 1;
}

#if AC_USE_PICKUP_WEAPONS\
	&& defined Streamer_SetIntData
	#if defined STREAMER_ENABLE_TAGS
		ac_fpublic ac_CreateDynamicPickup(STREAMER_TAG_PICKUP pickupid, ac_modelid, ac_type)
	#else
		ac_fpublic ac_CreateDynamicPickup(pickupid, ac_modelid, ac_type)
	#endif
	{
		Streamer_SetIntData(STREAMER_TYPE_PICKUP, pickupid, E_STREAMER_EXTRA_ID, 0);
		switch(ac_type)
		{
			case 2, 3, 15, 22:
			{
				switch(ac_modelid)
				{
					case 370: Streamer_SetIntData(STREAMER_TYPE_PICKUP, pickupid, E_STREAMER_EXTRA_ID, 2);
					case 1240: Streamer_SetIntData(STREAMER_TYPE_PICKUP, pickupid, E_STREAMER_EXTRA_ID, 3);
					case 1242: Streamer_SetIntData(STREAMER_TYPE_PICKUP, pickupid, E_STREAMER_EXTRA_ID, 4);
					case 321..326, 331, 333..339, 341..353, 355..369, 371, 372:
					{
						for(new ac_i = 46; ac_i >= 0; --ac_i)
						{
							if(ac_wModel[ac_i] == ac_modelid)
							{
								Streamer_SetIntData(STREAMER_TYPE_PICKUP, pickupid, E_STREAMER_EXTRA_ID, ac_i + 100);
								break;
							}
						}
					}
				}
			}
		}
		return 1;
	}
#endif

#if defined Streamer_UpdateEx
	stock ac_Streamer_UpdateEx(playerid, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, type = -1, compensatedtime = -1, freezeplayer = 1)
	{
		if(!Streamer_UpdateEx(playerid, x, y, z, worldid, interiorid, type, compensatedtime, freezeplayer)) return 0;
		if(compensatedtime >= 0)
		{
			ACInfo[playerid][acSet][8] = 4;
			ACInfo[playerid][acNOPCount][10] = 0;
			ACInfo[playerid][acSetPosX] = x;
			ACInfo[playerid][acSetPosY] = y;
			ACInfo[playerid][acSetPosZ] = z;
			ACInfo[playerid][acSetPosTime] =
			ACInfo[playerid][acGtc][11] = GetTickCount() + 3250;
		}
		return 1;
	}

	#if defined _ALS_Streamer_UpdateEx
		#undef Streamer_UpdateEx
	#else
		#define _ALS_Streamer_UpdateEx
	#endif
	#define Streamer_UpdateEx ac_Streamer_UpdateEx
#endif

stock ac_GetPlayerVersion(playerid, version[], len)
{
	new ac_ret = GetPlayerVersion(playerid, version, len);
	for(new ac_i = ac_ret - 1; ac_i >= 0; --ac_i)
	{
		if(version[ac_i] == '%')
		{
			strdel(version, ac_i, ac_i + 1);
			ac_ret--;
		}
	}
	return ac_ret;
}

#if defined _ALS_GetPlayerVersion
	#undef GetPlayerVersion
#else
	#define _ALS_GetPlayerVersion
#endif
#define GetPlayerVersion ac_GetPlayerVersion

stock ac_GetPlayerFacingAngle(playerid, &Float:ang)
{
	if(!GetPlayerFacingAngle(playerid, ang)) return 0;
	if(floatcmp(ang, ang) != 0) ang = 0.0;
	ang = ac_AbsoluteAngle(ang);
	return 1;
}

#if defined _ALS_GetPlayerFacingAngle
	#undef GetPlayerFacingAngle
#else
	#define _ALS_GetPlayerFacingAngle
#endif
#define GetPlayerFacingAngle ac_GetPlayerFacingAngle

stock ac_GetVehicleZAngle(vehicleid, &Float:z_angle)
{
	if(!GetVehicleZAngle(vehicleid, z_angle)) return 0;
	if(floatcmp(z_angle, z_angle) != 0) z_angle = 0.0;
	z_angle = ac_AbsoluteAngle(z_angle);
	#undef ac_AbsoluteAngle
	return 1;
}

#if defined _ALS_GetVehicleZAngle
	#undef GetVehicleZAngle
#else
	#define _ALS_GetVehicleZAngle
#endif
#define GetVehicleZAngle ac_GetVehicleZAngle

ac_fpublic ac_DestroyVehicle(vehicleid)
{
	if(!DestroyVehicle(vehicleid)) return 0;
	ACVehInfo[vehicleid][acSpawned] = false;
	return 1;
}

ac_fpublic ac_DestroyPickup(pickupid)
{
	if(!DestroyPickup(pickupid)) return 0;
	ACPickInfo[pickupid][acType] = 0;
	return 1;
}

ac_fpublic ac_DisableInteriorEnterExits()
{
	ac_IntEnterExits = false;
	return DisableInteriorEnterExits();
}

ac_fpublic ac_UsePlayerPedAnims()
{
	ac_PedAnims = true;
	return UsePlayerPedAnims();
}

ac_fpublic ac_EnableVehicleFriendlyFire()
{
	ac_VehFriendlyFire = true;
	return EnableVehicleFriendlyFire();
}

ac_fpublic ac_EnableStuntBonusForAll(enable)
{
	ac_StuntBonus = !!enable;
	#if defined foreach
		foreach(new ac_i : Player) ACInfo[ac_i][acStuntBonus] = ac_StuntBonus;
	#else
		for(new ac_i = GetPlayerPoolSize(); ac_i >= 0; --ac_i)
		{
			if(IsPlayerConnected(ac_i)) ACInfo[ac_i][acStuntBonus] = ac_StuntBonus;
		}
	#endif
	return EnableStuntBonusForAll(enable);
}

ac_fpublic ac_EnableStuntBonusForPlayer(playerid, enable)
{
	if(!EnableStuntBonusForPlayer(playerid, enable)) return 0;
	ACInfo[playerid][acStuntBonus] = !!enable;
	return 1;
}

ac_fpublic ac_ShowPlayerDialog(playerid, ac_dialogid)
{
	ACInfo[playerid][acDialog] = ac_dialogid;
	return 1;
}

ac_fpublic ac_fs_ShowPlayerDialog(playerid, ac_dialogid)
{
	ACInfo[playerid][acNextDialog] = ac_dialogid;
	return 1;
}

ac_fpublic ac_TogglePlayerControllable(playerid, toggle)
{
	if(!TogglePlayerControllable(playerid, toggle)) return 0;
	ACInfo[playerid][acUnFrozen] = !!toggle;
	return 1;
}

ac_fpublic ac_TogglePlayerSpectating(playerid, toggle)
{
	if(!TogglePlayerSpectating(playerid, toggle)) return 0;
	if(GetPlayerState(playerid) == PLAYER_STATE_SPECTATING || ACInfo[playerid][acSet][6] != -1)
	{
		if(!toggle)
		{
			if(ACInfo[playerid][acDead]) ACInfo[playerid][acSet][7] = 4;
			else
			{
				ACInfo[playerid][acSet][3] =
				ACInfo[playerid][acSet][4] =
				ACInfo[playerid][acSet][6] =
				ACInfo[playerid][acSet][8] =
				ACInfo[playerid][acSet][9] =
				ACInfo[playerid][acNextSpecAct] = -1;
				for(new ac_i = 12; ac_i >= 0; --ac_i)
				{
					ACInfo[playerid][acSetWeapon][ac_i] = -1;
					ACInfo[playerid][acGiveAmmo][ac_i] = -65535;
				}
				ACInfo[playerid][acTpToZ] = false;
				ACInfo[playerid][acUnFrozen] = true;
				ACInfo[playerid][acSet][7] = 1;
			}
			ACInfo[playerid][acSpawnRes]++;
			ACInfo[playerid][acSpec] = false;
			ACInfo[playerid][acSpawnTime] = ACInfo[playerid][acNOPCount][9] = 0;
			ACInfo[playerid][acGtc][13] = GetTickCount() + 1650;
		}
	}
	else if(toggle)
	{
		ACInfo[playerid][acSet][6] = 1;
		ACInfo[playerid][acNOPCount][8] = 0;
		ACInfo[playerid][acGtc][12] = GetTickCount() + 1650;
	}
	return 1;
}

ac_fpublic ac_SpawnPlayer(playerid)
{
	if(!SpawnPlayer(playerid)) return 0;
	if(ACInfo[playerid][acDead]) ACInfo[playerid][acSet][7] = 5;
	else
	{
		ACInfo[playerid][acSet][3] =
		ACInfo[playerid][acSet][4] =
		ACInfo[playerid][acSet][8] =
		ACInfo[playerid][acSet][9] =
		ACInfo[playerid][acNextSpecAct] = -1;
		for(new ac_i = 12; ac_i >= 0; --ac_i)
		{
			ACInfo[playerid][acSetWeapon][ac_i] = -1;
			ACInfo[playerid][acGiveAmmo][ac_i] = -65535;
		}
		ACInfo[playerid][acTpToZ] = false;
		ACInfo[playerid][acUnFrozen] = true;
		ACInfo[playerid][acSet][7] = 2;
	}
	ACInfo[playerid][acSpawnRes]++;
	ACInfo[playerid][acSpawnTime] = ACInfo[playerid][acNOPCount][9] = 0;
	ACInfo[playerid][acGtc][13] = GetTickCount() + 1650;
	return 1;
}

ac_fpublic ac_SetPlayerHealth(playerid, Float:ac_health)
{
	if(!SetPlayerHealth(playerid, ac_health)) return 0;
	if(floatcmp(ac_health, 0.0) == -1) ac_health = 0.0;
	ACInfo[playerid][acNOPCount][3] = 0;
	ACInfo[playerid][acSet][1] = floatround(ac_health, floatround_tozero);
	ACInfo[playerid][acGtc][3] = GetTickCount() + 1650;
	return 1;
}

ac_fpublic ac_SetPlayerArmour(playerid, Float:ac_armour)
{
	if(!SetPlayerArmour(playerid, ac_armour)) return 0;
	if(floatcmp(ac_armour, 0.0) == -1) ac_armour = 0.0;
	ACInfo[playerid][acNOPCount][5] = 0;
	ACInfo[playerid][acSet][2] = floatround(ac_armour, floatround_tozero);
	ACInfo[playerid][acGtc][5] = GetTickCount() + 1650;
	return 1;
}

ac_fpublic ac_GivePlayerWeapon(playerid, ac_weaponid, ac_ammo)
{
	if(0 <= ac_weaponid <= 18 || 22 <= ac_weaponid <= 46)
	{
		new ac_s = ac_wSlot[ac_weaponid];
		ACInfo[playerid][acNOPCount][0] = ACInfo[playerid][acNOPCount][1] = 0;
		if(16 <= ac_weaponid <= 18 || 22 <= ac_weaponid <= 43)
		{
			if(3 <= ac_s <= 5 || (ACInfo[playerid][acSetWeapon][ac_s] == -1
			? ACInfo[playerid][acWeapon][ac_s] : ACInfo[playerid][acSetWeapon][ac_s]) == ac_weaponid)
			{
				ACInfo[playerid][acGiveAmmo][ac_s] =
				(ACInfo[playerid][acGiveAmmo][ac_s] == -65535 ? ACInfo[playerid][acAmmo][ac_s]
				: ACInfo[playerid][acGiveAmmo][ac_s]) + ac_ammo;
			}
			else ACInfo[playerid][acGiveAmmo][ac_s] = ac_ammo;
			if(ACInfo[playerid][acGiveAmmo][ac_s] < -32768) ac_ammo = ACInfo[playerid][acGiveAmmo][ac_s] = -32768;
			else if(ACInfo[playerid][acGiveAmmo][ac_s] > 32767) ac_ammo = ACInfo[playerid][acGiveAmmo][ac_s] = 32767;
			ACInfo[playerid][acSetWeapon][ac_s] = ACInfo[playerid][acSet][3] = ac_weaponid;
			ACInfo[playerid][acReloadTime] = 0;
		}
		else
		{
			ACInfo[playerid][acGiveAmmo][ac_s] = -65535;
			ACInfo[playerid][acSetWeapon][ac_s] = ACInfo[playerid][acSet][3] = ac_weaponid;
		}
		ACInfo[playerid][acGtcGiveAmmo][ac_s] =
		ACInfo[playerid][acGtcSetWeapon][ac_s] = ACInfo[playerid][acGtc][2] = GetTickCount() + 2650;
	}
	return GivePlayerWeapon(playerid, ac_weaponid, ac_ammo);
}

ac_fpublic ac_SetPlayerAmmo(playerid, ac_weaponslot, ac_ammo)
{
	if(ac_ammo < -32768) ac_ammo = -32768;
	else if(ac_ammo > 32767) ac_ammo = 32767;
	if(16 <= ac_weaponslot <= 43)
	{
		new ac_s = ac_wSlot[ac_weaponslot];
		if(ACInfo[playerid][acWeapon][ac_s] > 0 || ACInfo[playerid][acSetWeapon][ac_s] > 0)
		{
			ACInfo[playerid][acNOPCount][1] = 0;
			ACInfo[playerid][acGiveAmmo][ac_s] = ac_ammo;
			ACInfo[playerid][acGtcGiveAmmo][ac_s] = GetTickCount() + 1650;
		}
	}
	return SetPlayerAmmo(playerid, ac_weaponslot, ac_ammo);
}

ac_fpublic ac_SetPlayerArmedWeapon(playerid, ac_weaponid)
{
	if(!SetPlayerArmedWeapon(playerid, ac_weaponid)) return 0;
	if(0 <= ac_weaponid <= 18 || 22 <= ac_weaponid <= 46)
	{
		new ac_s = ac_wSlot[ac_weaponid];
		if((ac_weaponid == ACInfo[playerid][acWeapon][ac_s] || ac_weaponid == ACInfo[playerid][acSetWeapon][ac_s]) &&
		(ACInfo[playerid][acAmmo][ac_s] != 0 || ACInfo[playerid][acGiveAmmo][ac_s] != 0))
		{
			ACInfo[playerid][acNOPCount][0] = 0;
			ACInfo[playerid][acSet][3] = ac_weaponid;
			ACInfo[playerid][acGtc][2] = GetTickCount() + 2650;
		}
	}
	return 1;
}

ac_fpublic ac_ResetPlayerWeapons(playerid)
{
	if(!ResetPlayerWeapons(playerid)) return 0;
	for(new ac_i = 12; ac_i >= 0; --ac_i)
	{
		ACInfo[playerid][acWeapon][ac_i] = ACInfo[playerid][acAmmo][ac_i] = 0;
		ACInfo[playerid][acSetWeapon][ac_i] = -1;
		ACInfo[playerid][acGiveAmmo][ac_i] = -65535;
	}
	ACInfo[playerid][acSet][3] = -1;
	ACInfo[playerid][acGtc][7] = GetTickCount() + 1650;
	return 1;
}

ac_fpublic ac_GivePlayerMoney(playerid, ac_money)
{
	if(!GivePlayerMoney(playerid, ac_money)) return 0;
	ACInfo[playerid][acNOPCount][11] = AC_MAX_MONEY_WARNINGS;
	ACInfo[playerid][acMoney] += ac_money;
	#undef AC_MAX_MONEY_WARNINGS
	return 1;
}

ac_fpublic ac_ResetPlayerMoney(playerid)
{
	if(!ResetPlayerMoney(playerid)) return 0;
	ACInfo[playerid][acNOPCount][11] = 0;
	ACInfo[playerid][acMoney] = 0;
	return 1;
}

static bad_GetPlayerMoney(playerid) return GetPlayerMoney(playerid);

ac_fpublic ac_SetPlayerSpecialAction(playerid, ac_actionid)
{
	if(!SetPlayerSpecialAction(playerid, ac_actionid)) return 0;
	if(ac_actionid == SPECIAL_ACTION_USEJETPACK || SPECIAL_ACTION_CUFFED <= ac_actionid <= SPECIAL_ACTION_CARRY ||
	(ac_actionid == SPECIAL_ACTION_USECELLPHONE || ac_actionid == 68 || SPECIAL_ACTION_DANCE1 <= ac_actionid <= SPECIAL_ACTION_DANCE4) && ACInfo[playerid][acVeh] == 0 ||
	ac_actionid == SPECIAL_ACTION_STOPUSECELLPHONE && ACInfo[playerid][acSpecAct] == SPECIAL_ACTION_USECELLPHONE ||
	(ac_actionid == SPECIAL_ACTION_HANDSUP || SPECIAL_ACTION_DRINK_BEER <= ac_actionid <= SPECIAL_ACTION_DRINK_SPRUNK) && ACInfo[playerid][acSpecAct] != SPECIAL_ACTION_ENTER_VEHICLE && ACInfo[playerid][acVeh] == 0 ||
	ac_actionid == SPECIAL_ACTION_NONE && ACInfo[playerid][acSpecAct] != SPECIAL_ACTION_DUCK &&
	ACInfo[playerid][acSpecAct] != SPECIAL_ACTION_ENTER_VEHICLE && ACInfo[playerid][acSpecAct] != SPECIAL_ACTION_HANDSUP)
	{
		ACInfo[playerid][acNOPCount][6] = 0;
		if((ac_actionid == 68 || SPECIAL_ACTION_HANDSUP <= ac_actionid <= SPECIAL_ACTION_USECELLPHONE ||
		SPECIAL_ACTION_DRINK_BEER <= ac_actionid <= SPECIAL_ACTION_CARRY) && SPECIAL_ACTION_DANCE1 <= ACInfo[playerid][acSpecAct] <= SPECIAL_ACTION_DANCE4 ||
		SPECIAL_ACTION_DRINK_BEER <= ac_actionid <= SPECIAL_ACTION_CARRY && ACInfo[playerid][acSpecAct] == SPECIAL_ACTION_DUCK ||
		(ac_actionid == SPECIAL_ACTION_NONE || SPECIAL_ACTION_CUFFED <= ac_actionid <= SPECIAL_ACTION_CARRY) && ACInfo[playerid][acVeh] ||
		SPECIAL_ACTION_CUFFED <= ac_actionid <= SPECIAL_ACTION_CARRY && ACInfo[playerid][acSpecAct] == SPECIAL_ACTION_ENTER_VEHICLE) ACInfo[playerid][acNextSpecAct] = ac_actionid;
		else
		{
			if(ac_actionid == SPECIAL_ACTION_STOPUSECELLPHONE) ac_actionid = SPECIAL_ACTION_NONE;
			else if(ac_actionid == SPECIAL_ACTION_USEJETPACK || ac_actionid == SPECIAL_ACTION_HANDSUP ||
			ac_actionid == 68 || SPECIAL_ACTION_DANCE1 <= ac_actionid <= SPECIAL_ACTION_DANCE4 ||
			SPECIAL_ACTION_DRINK_BEER <= ac_actionid <= SPECIAL_ACTION_DRINK_SPRUNK) ACInfo[playerid][acNextSpecAct] = ACInfo[playerid][acSpecAct];
			else ACInfo[playerid][acNextSpecAct] = -1;
			ACInfo[playerid][acSet][4] = ac_actionid;
			ACInfo[playerid][acGtc][6] = GetTickCount() + 3250;
		}
	}
	return 1;
}

ac_fpublic ac_SetPlayerInterior(playerid, ac_interiorid)
{
	if(!SetPlayerInterior(playerid, ac_interiorid)) return 0;
	ACInfo[playerid][acNOPCount][2] = 0;
	ACInfo[playerid][acSet][0] = ac_interiorid % 256;
	ACInfo[playerid][acGtc][0] = GetTickCount() + 3250;
	return 1;
}

ac_fpublic ac_SetPlayerPos(playerid, Float:ac_x, Float:ac_y, Float:ac_z)
{
	if(!SetPlayerPos(playerid, ac_x, ac_y, ac_z)) return 0;
	ACInfo[playerid][acSet][8] = 1;
	ACInfo[playerid][acNOPCount][10] = 0;
	ACInfo[playerid][acSetPosX] = ac_x;
	ACInfo[playerid][acSetPosY] = ac_y;
	ACInfo[playerid][acSetPosZ] = ac_z;
	ACInfo[playerid][acSetPosTime] =
	ACInfo[playerid][acGtc][11] = GetTickCount() + 3250;
	return 1;
}

ac_fpublic ac_SetPlayerPosFindZ(playerid, Float:ac_x, Float:ac_y, Float:ac_z)
{
	if(!SetPlayerPosFindZ(playerid, ac_x, ac_y, ac_z)) return 0;
	ACInfo[playerid][acSet][8] = 2;
	ACInfo[playerid][acTpToZ] = true;
	ACInfo[playerid][acNOPCount][10] = 0;
	ACInfo[playerid][acSetPosX] = ac_x;
	ACInfo[playerid][acSetPosY] = ac_y;
	ACInfo[playerid][acSetPosTime] =
	ACInfo[playerid][acGtc][11] = GetTickCount() + 3250;
	return 1;
}

ac_fpublic ac_SetPlayerVelocity(playerid, Float:ac_X, Float:ac_Y, Float:ac_Z)
{
	if(!SetPlayerVelocity(playerid, ac_X, ac_Y, ac_Z)) return 0;
	ACInfo[playerid][acSpeed] = ac_GetSpeed(ac_X, ac_Y, ac_Z);
	ACInfo[playerid][acGtc][10] = GetTickCount() + 800;
	return 1;
}

ac_fpublic ac_PutPlayerInVehicle(playerid, ac_vehicleid, ac_seatid)
{
	if(!PutPlayerInVehicle(playerid, ac_vehicleid, ac_seatid)) return 0;
	if(!(SPECIAL_ACTION_DANCE1 <= ACInfo[playerid][acSpecAct] <= SPECIAL_ACTION_DANCE4) &&
	!(SPECIAL_ACTION_DRINK_BEER <= ACInfo[playerid][acSpecAct] <= SPECIAL_ACTION_DRINK_SPRUNK) &&
	GetPlayerVirtualWorld(playerid) == GetVehicleVirtualWorld(ac_vehicleid))
	{
		new ac_model = GetVehicleModel(ac_vehicleid);
		ACInfo[playerid][acNOPCount][7] = 0;
		ACInfo[playerid][acSet][9] = ac_vehicleid;
		if(ac_model == 431 || ac_model == 437 || ac_IsVehicleSeatOccupied(ac_vehicleid, ac_seatid) ||
		ac_seatid > ac_GetMaxPassengers(ac_model)) ACInfo[playerid][acSet][5] = -1;
		else ACInfo[playerid][acSet][5] = ac_seatid;
		ACInfo[playerid][acGtc][1] = GetTickCount() + 1650;
	}
	return 1;
}

ac_fpublic ac_RemovePlayerFromVehicle(playerid)
{
	if(!RemovePlayerFromVehicle(playerid)) return 0;
	ACInfo[playerid][acSet][11] = 1;
	ACInfo[playerid][acGtc][8] = GetTickCount() + 3650;
	return 1;
}

ac_fpublic ac_SetVehiclePos(vehicleid, Float:ac_x, Float:ac_y, Float:ac_z)
{
	if(!SetVehiclePos(vehicleid, ac_x, ac_y, ac_z)) return 0;
	new ac_driver = ACVehInfo[vehicleid][acDriver];
	if(ac_driver != INVALID_PLAYER_ID)
	{
		ACInfo[ac_driver][acSet][8] = 3;
		ACInfo[ac_driver][acNOPCount][10] = 0;
		ACInfo[ac_driver][acSetPosX] = ac_x;
		ACInfo[ac_driver][acSetPosY] = ac_y;
		ACInfo[ac_driver][acSetPosZ] = ac_z;
		ACInfo[ac_driver][acSetPosTime] =
		ACInfo[ac_driver][acGtc][11] = GetTickCount() + 3250;
	}
	return 1;
}

ac_fpublic ac_SetVehicleVelocity(vehicleid, Float:ac_X, Float:ac_Y, Float:ac_Z)
{
	if(!SetVehicleVelocity(vehicleid, ac_X, ac_Y, ac_Z)) return 0;
	new ac_driver = ACVehInfo[vehicleid][acDriver];
	if(ac_driver != INVALID_PLAYER_ID)
	{
		ACVehInfo[vehicleid][acVelX] = ac_X;
		ACVehInfo[vehicleid][acVelY] = ac_Y;
		ACVehInfo[vehicleid][acVelZ] = ac_Z;
		ACInfo[ac_driver][acGtc][9] = GetTickCount() + 800;
	}
	return 1;
}

ac_fpublic ac_SetVehicleAngularVelocity(vehicleid, Float:ac_X, Float:ac_Y, Float:ac_Z)
{
	if(!SetVehicleAngularVelocity(vehicleid, ac_X, ac_Y, ac_Z)) return 0;
	new ac_driver = ACVehInfo[vehicleid][acDriver];
	if(ac_driver != INVALID_PLAYER_ID)
	{
		ACVehInfo[vehicleid][acVelX] = ac_X;
		ACVehInfo[vehicleid][acVelY] = ac_Y;
		ACVehInfo[vehicleid][acVelZ] = ac_Z;
		ACInfo[ac_driver][acGtc][9] = GetTickCount() + 800;
	}
	return 1;
}

ac_fpublic ac_LinkVehicleToInterior(vehicleid, ac_interiorid)
{
	if(!LinkVehicleToInterior(vehicleid, ac_interiorid)) return 0;
	ACVehInfo[vehicleid][acInt] = ac_interiorid % 256;
	return 1;
}

ac_fpublic ac_ChangeVehiclePaintjob(vehicleid, ac_paintjobid)
{
	if(GetVehicleModel(vehicleid) > 0) ACVehInfo[vehicleid][acPaintJob] = ac_paintjobid;
	return ChangeVehiclePaintjob(vehicleid, ac_paintjobid);
}

ac_fpublic ac_SetVehicleHealth(vehicleid, Float:ac_health)
{
	if(!SetVehicleHealth(vehicleid, ac_health)) return 0;
	new ac_driver = ACVehInfo[vehicleid][acDriver];
	if(ac_driver != INVALID_PLAYER_ID)
	{
		ACInfo[ac_driver][acNOPCount][4] = 0;
		ACInfo[ac_driver][acSetVehHealth] = ac_health;
		ACInfo[ac_driver][acGtc][4] = GetTickCount() + 1650;
	}
	else ACVehInfo[vehicleid][acHealth] = ac_health;
	return 1;
}

ac_fpublic ac_RepairVehicle(vehicleid)
{
	if(!RepairVehicle(vehicleid)) return 0;
	new ac_driver = ACVehInfo[vehicleid][acDriver];
	if(ac_driver != INVALID_PLAYER_ID)
	{
		ACInfo[ac_driver][acNOPCount][4] = 0;
		ACInfo[ac_driver][acSetVehHealth] = 1000.0;
		ACInfo[ac_driver][acGtc][4] = GetTickCount() + 1650;
	}
	else ACVehInfo[vehicleid][acHealth] = 1000.0;
	return 1;
}

ac_fpublic ac_SetVehicleToRespawn(vehicleid)
{
	new ac_driver = ACVehInfo[vehicleid][acDriver];
	if(ac_driver != INVALID_PLAYER_ID) ACInfo[ac_driver][acGtc][9] = GetTickCount() + 800;
	return SetVehicleToRespawn(vehicleid);
}

ac_fpublic ac_EnableAntiCheat(code, enable)
{
	if(!(0 <= code < sizeof ac_ACAllow)) return 0;
	if(code == 42)
	{
		if(enable)
		{
			if(!ac_ACAllow[code])
			{
				#if !AC_USE_QUERY
					ac_QueryEnable = !!GetConsoleVarAsBool("query");
				#endif
				ac_RconEnable = !!GetConsoleVarAsBool("rcon");
			}
			#if !AC_USE_QUERY
				SendRconCommand("query 0");
			#endif
			SendRconCommand("rcon 0");
		}
		else
		{
			static ac_strtmp[9];
			#if !AC_USE_QUERY
				format(ac_strtmp, sizeof ac_strtmp, "query %b", ac_QueryEnable);
				SendRconCommand(ac_strtmp);
			#endif
			format(ac_strtmp, sizeof ac_strtmp, "rcon %b", ac_RconEnable);
			SendRconCommand(ac_strtmp);
		}
	}
	ac_ACAllow[code] = !!enable;
	if(enable)
	{
		#if defined foreach
			foreach(new ac_i : Player)
		#else
			for(new ac_i = GetPlayerPoolSize(); ac_i >= 0; --ac_i)
			{
				if(IsPlayerConnected(ac_i))
		#endif
		{
			ACInfo[ac_i][acACAllow][code] = ac_ACAllow[code];
			switch(code)
			{
				case 7: ACInfo[ac_i][acCheatCount][15] = 0;
				case 8: ACInfo[ac_i][acCheatCount][3] = 0;
				case 9: ACInfo[ac_i][acCheatCount][17] = 0;
				case 10: ACInfo[ac_i][acCheatCount][16] = 0;
				case 15: ACInfo[ac_i][acCheatCount][10] = 0;
				case 17: ACInfo[ac_i][acCheatCount][7] = 0;
				case 19: ACInfo[ac_i][acCheatCount][9] = 0;
				case 20: ACInfo[ac_i][acCheatCount][11] = 0;
				case 23: ACInfo[ac_i][acCheatCount][12] = 0;
				case 26: ACInfo[ac_i][acCheatCount][14] = ACInfo[ac_i][acCheatCount][8] = 0;
				case 29: ACInfo[ac_i][acCheatCount][13] = ACInfo[ac_i][acCheatCount][6] = 0;
				case 30: ACInfo[ac_i][acCheatCount][19] = 0;
				case 31: ACInfo[ac_i][acCheatCount][4] = 0;
				case 34: ACInfo[ac_i][acCheatCount][5] = 0;
				case 38: ACInfo[ac_i][acCheatCount][0] = 0;
				case 47: ACInfo[ac_i][acCheatCount][18] = 0;
			}
		}
		#if !defined foreach
			}
		#endif
	}
	else
	{
		#if defined foreach
			foreach(new ac_i : Player) ACInfo[ac_i][acACAllow][code] = ac_ACAllow[code];
		#else
			for(new ac_i = GetPlayerPoolSize(); ac_i >= 0; --ac_i)
			{
				if(IsPlayerConnected(ac_i)) ACInfo[ac_i][acACAllow][code] = ac_ACAllow[code];
			}
		#endif
	}
	return 1;
}

ac_fpublic ac_EnableAntiNOP(nopcode, enable)
{
	if(!(0 <= nopcode < sizeof ac_NOPAllow)) return 0;
	ac_NOPAllow[nopcode] = !!enable;
	#if defined foreach
		foreach(new ac_i : Player) ACInfo[ac_i][acNOPAllow][nopcode] = ac_NOPAllow[nopcode];
	#else
		for(new ac_i = GetPlayerPoolSize(); ac_i >= 0; --ac_i)
		{
			if(IsPlayerConnected(ac_i)) ACInfo[ac_i][acNOPAllow][nopcode] = ac_NOPAllow[nopcode];
		}
	#endif
	return 1;
}

ac_fpublic ac_EnableAntiCheatForPlayer(playerid, code, enable)
{
	if(!(0 <= code < sizeof ac_ACAllow)) return 0;
	ACInfo[playerid][acACAllow][code] = !!enable;
	if(enable)
	{
		switch(code)
		{
			case 7: ACInfo[playerid][acCheatCount][15] = 0;
			case 8: ACInfo[playerid][acCheatCount][3] = 0;
			case 9: ACInfo[playerid][acCheatCount][17] = 0;
			case 10: ACInfo[playerid][acCheatCount][16] = 0;
			case 15: ACInfo[playerid][acCheatCount][10] = 0;
			case 17: ACInfo[playerid][acCheatCount][7] = 0;
			case 19: ACInfo[playerid][acCheatCount][9] = 0;
			case 20: ACInfo[playerid][acCheatCount][11] = 0;
			case 23: ACInfo[playerid][acCheatCount][12] = 0;
			case 26: ACInfo[playerid][acCheatCount][14] = ACInfo[playerid][acCheatCount][8] = 0;
			case 29: ACInfo[playerid][acCheatCount][13] = ACInfo[playerid][acCheatCount][6] = 0;
			case 30: ACInfo[playerid][acCheatCount][19] = 0;
			case 31: ACInfo[playerid][acCheatCount][4] = 0;
			case 34: ACInfo[playerid][acCheatCount][5] = 0;
			case 38: ACInfo[playerid][acCheatCount][0] = 0;
			case 47: ACInfo[playerid][acCheatCount][18] = 0;
		}
	}
	return 1;
}

ac_fpublic ac_EnableAntiNOPForPlayer(playerid, nopcode, enable)
{
	if(!(0 <= nopcode < sizeof ac_NOPAllow)) return 0;
	ACInfo[playerid][acNOPAllow][nopcode] = !!enable;
	return 1;
}

ac_fpublic ac_IsAntiCheatEnabled(code)
{
	if(!(0 <= code < sizeof ac_ACAllow)) return 0;
	return ac_ACAllow[code];
}

ac_fpublic ac_IsAntiNOPEnabled(nopcode)
{
	if(!(0 <= nopcode < sizeof ac_NOPAllow)) return 0;
	return ac_NOPAllow[nopcode];
}

ac_fpublic ac_IsAntiCheatEnabledForPlayer(playerid, code)
{
	if(!(0 <= code < sizeof ac_ACAllow)) return 0;
	return ACInfo[playerid][acACAllow][code];
}

ac_fpublic ac_IsAntiNOPEnabledForPlayer(playerid, nopcode)
{
	if(!(0 <= nopcode < sizeof ac_NOPAllow)) return 0;
	return ACInfo[playerid][acNOPAllow][nopcode];
}

ac_fpublic ac_AntiCheatGetSpeed(playerid) return ACInfo[playerid][acSpeed];

ac_fpublic ac_AntiCheatGetAnimationIndex(playerid) return ACInfo[playerid][acAnim];

ac_fpublic ac_AntiCheatGetDialog(playerid) return ACInfo[playerid][acDialog];

ac_fpublic ac_AntiCheatGetMoney(playerid) return ACInfo[playerid][acMoney];

ac_fpublic ac_AntiCheatGetEnterVehicle(playerid) return ACInfo[playerid][acEnterVeh];

ac_fpublic ac_AntiCheatGetVehicleID(playerid) return ACInfo[playerid][acVeh];

ac_fpublic ac_AntiCheatGetWeapon(playerid) return ACInfo[playerid][acLastWeapon];

ac_fpublic ac_AntiCheatGetVehicleSeat(playerid) return ACInfo[playerid][acSeat];

ac_fpublic ac_AntiCheatGetSpecialAction(playerid) return ACInfo[playerid][acSpecAct];

ac_fpublic ac_AntiCheatGetLastSpecialActio(playerid) return ACInfo[playerid][acLastSpecAct];

ac_fpublic ac_AntiCheatGetLastShotWeapon(playerid) return ACInfo[playerid][acLastShot];

ac_fpublic ac_AntiCheatGetLastPickup(playerid) return ACInfo[playerid][acLastPickup];

ac_fpublic ac_AntiCheatGetLastUpdateTime(playerid) return ACInfo[playerid][acUpdateTime];

ac_fpublic ac_AntiCheatGetLastReloadTime(playerid) return ACInfo[playerid][acReloadTime];

ac_fpublic ac_AntiCheatGetLastEnteredVehTi(playerid) return ACInfo[playerid][acEnterVehTime];

ac_fpublic ac_AntiCheatGetLastShotTime(playerid) return ACInfo[playerid][acShotTime];

ac_fpublic ac_AntiCheatGetLastSpawnTime(playerid) return ACInfo[playerid][acSpawnTime];

ac_fpublic ac_AntiCheatIntEnterExitsIsEnab(playerid) return ACInfo[playerid][acIntEnterExits];

ac_fpublic ac_AntiCheatStuntBonusIsEnabled(playerid) return ACInfo[playerid][acStuntBonus];

ac_fpublic ac_AntiCheatIsInModShop(playerid) return ACInfo[playerid][acModShop];

ac_fpublic ac_AntiCheatIsFrozen(playerid) return !ACInfo[playerid][acUnFrozen];

ac_fpublic ac_AntiCheatIsDead(playerid) return ACInfo[playerid][acDead];

ac_fpublic ac_AntiCheatIsConnected(playerid) return ACInfo[playerid][acOnline];

ac_fpublic ac_AntiCheatKickWithDesync(playerid, code)
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	new ac_gpp = GetPlayerPing(playerid) + 150;
	#if defined SetPlayerTimerEx_
		ACInfo[playerid][acKickTimerID] = SetPlayerTimerEx_(playerid, "ac_KickTimer", 0, (ac_gpp > AC_MAX_PING ? AC_MAX_PING : ac_gpp), 1, "i", playerid);
	#else
		ACInfo[playerid][acKickTimerID] = SetTimerEx("ac_KickTimer", (ac_gpp > AC_MAX_PING ? AC_MAX_PING : ac_gpp), false, "i", playerid);
	#endif
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(code == 4) ACInfo[playerid][acKickVeh] = GetPlayerVehicleID(playerid);
		ACInfo[playerid][acKicked] = 2;
	}
	else ACInfo[playerid][acKicked] = 1;
	return 1;
}

ac_fpublic ac_AntiCheatIsKickedWithDecync(playerid) return ACInfo[playerid][acKicked];

ac_fpublic ac_AntiCheatGetNextDialog(playerid) return ACInfo[playerid][acNextDialog];

#endif

stock acc_AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2)
{
	new ac_vehicleid = AddStaticVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2);
	if(ac_vehicleid != INVALID_VEHICLE_ID)
	{
		#if defined FILTERSCRIPT
			CallRemoteFunction("ac_AddStaticVehicle", "iffff", ac_vehicleid, spawn_x, spawn_y, spawn_z, z_angle);
		#else
			ac_AddStaticVehicle(ac_vehicleid, spawn_x, spawn_y, spawn_z, z_angle);
		#endif
	}
	return ac_vehicleid;
}

#if defined _ALS_AddStaticVehicle
	#undef AddStaticVehicle
#else
	#define _ALS_AddStaticVehicle
#endif
#define AddStaticVehicle acc_AddStaticVehicle

stock acc_AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay, addsiren = 0)
{
	new ac_vehicleid = AddStaticVehicleEx(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay, addsiren);
	if(ac_vehicleid != INVALID_VEHICLE_ID)
	{
		#if defined FILTERSCRIPT
			CallRemoteFunction("ac_AddStaticVehicle", "iffff", ac_vehicleid, spawn_x, spawn_y, spawn_z, z_angle);
		#else
			ac_AddStaticVehicle(ac_vehicleid, spawn_x, spawn_y, spawn_z, z_angle);
		#endif
	}
	return ac_vehicleid;
}

#if defined _ALS_AddStaticVehicleEx
	#undef AddStaticVehicleEx
#else
	#define _ALS_AddStaticVehicleEx
#endif
#define AddStaticVehicleEx acc_AddStaticVehicleEx

stock acc_CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, addsiren = 0)
{
	new ac_vehicleid = CreateVehicle(vehicletype, x, y, z, rotation, color1, color2, respawn_delay, addsiren);
	if(ac_vehicleid != INVALID_VEHICLE_ID)
	{
		#if defined FILTERSCRIPT
			CallRemoteFunction("ac_CreateVehicle", "iiffff", ac_vehicleid, vehicletype, x, y, z, rotation);
		#else
			ac_CreateVehicle(ac_vehicleid, vehicletype, x, y, z, rotation);
		#endif
	}
	return ac_vehicleid;
}

#if defined _ALS_CreateVehicle
	#undef CreateVehicle
#else
	#define _ALS_CreateVehicle
#endif
#define CreateVehicle acc_CreateVehicle

stock acc_AddPlayerClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new ac_classid = AddPlayerClass(modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	#if defined FILTERSCRIPT
		CallRemoteFunction("ac_AddPlayerClass", "ifffiiiiii", ac_classid, spawn_x, spawn_y, spawn_z, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	#else
		ac_AddPlayerClass(ac_classid, spawn_x, spawn_y, spawn_z, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	#endif
	return ac_classid;
}

#if defined _ALS_AddPlayerClass
	#undef AddPlayerClass
#else
	#define _ALS_AddPlayerClass
#endif
#define AddPlayerClass acc_AddPlayerClass

stock acc_AddPlayerClassEx(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new ac_classid = AddPlayerClassEx(teamid, modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	#if defined FILTERSCRIPT
		CallRemoteFunction("ac_AddPlayerClass", "ifffiiiiii", ac_classid, spawn_x, spawn_y, spawn_z, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	#else
		ac_AddPlayerClass(ac_classid, spawn_x, spawn_y, spawn_z, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	#endif
	return ac_classid;
}

#if defined _ALS_AddPlayerClassEx
	#undef AddPlayerClassEx
#else
	#define _ALS_AddPlayerClassEx
#endif
#define AddPlayerClassEx acc_AddPlayerClassEx

stock acc_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetSpawnInfo", "iiiffffiiiiii", playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	#else
		return ac_SetSpawnInfo(playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	#endif
}

#if defined _ALS_SetSpawnInfo
	#undef SetSpawnInfo
#else
	#define _ALS_SetSpawnInfo
#endif
#define SetSpawnInfo acc_SetSpawnInfo

stock acc_AddStaticPickup(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0)
{
	new ac_pickupid = CreatePickup(model, type, X, Y, Z, virtualworld);
	if(ac_pickupid != -1)
	{
		#if defined FILTERSCRIPT
			return CallRemoteFunction("ac_AddStaticPickup", "iiifff", ac_pickupid, model, type, X, Y, Z);
		#else
			return ac_AddStaticPickup(ac_pickupid, model, type, X, Y, Z);
		#endif
	}
	return 0;
}

#if defined _ALS_AddStaticPickup
	#undef AddStaticPickup
#else
	#define _ALS_AddStaticPickup
#endif
#define AddStaticPickup acc_AddStaticPickup

stock acc_CreatePickup(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0)
{
	new ac_pickupid = CreatePickup(model, type, X, Y, Z, virtualworld);
	if(ac_pickupid != -1)
	{
		#if defined FILTERSCRIPT
			CallRemoteFunction("ac_CreatePickup", "iiifff", ac_pickupid, model, type, X, Y, Z);
		#else
			ac_CreatePickup(ac_pickupid, model, type, X, Y, Z);
		#endif
	}
	return ac_pickupid;
}

#if defined _ALS_CreatePickup
	#undef CreatePickup
#else
	#define _ALS_CreatePickup
#endif
#define CreatePickup acc_CreatePickup

#if defined CreateDynamicPickup
	#if defined STREAMER_ENABLE_TAGS
		stock STREAMER_TAG_PICKUP acc_CreateDynamicPickup(modelid, type, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 200.0, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1, priority = 0)
		{
			new STREAMER_TAG_PICKUP ac_pickupid = CreateDynamicPickup(modelid, type, x, y, z, worldid, interiorid, playerid, streamdistance, areaid, priority);
	#else
		stock acc_CreateDynamicPickup(modelid, type, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 200.0, areaid = -1, priority = 0)
		{
			new ac_pickupid = CreateDynamicPickup(modelid, type, x, y, z, worldid, interiorid, playerid, streamdistance, areaid, priority);
	#endif
		if(_:ac_pickupid > 0)
		{
			#if defined FILTERSCRIPT
				CallRemoteFunction("ac_CreateDynamicPickup", "iii", ac_pickupid, modelid, type);
			#else
				#if AC_USE_PICKUP_WEAPONS
					ac_CreateDynamicPickup(ac_pickupid, modelid, type);
				#endif
			#endif
		}
		return ac_pickupid;
	}

	#if defined _ALS_CreateDynamicPickup
		#undef CreateDynamicPickup
	#else
		#define _ALS_CreateDynamicPickup
	#endif
	#define CreateDynamicPickup acc_CreateDynamicPickup
#endif

#if defined CreateDynamicPickupEx
	#if defined STREAMER_ENABLE_TAGS
		stock STREAMER_TAG_PICKUP acc_CreateDynamicPickupEx(modelid, type, Float:x, Float:y, Float:z, Float:streamdistance = 200.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, STREAMER_TAG_AREA areas[] = { STREAMER_TAG_AREA -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas)
		{
			new STREAMER_TAG_PICKUP ac_pickupid = CreateDynamicPickupEx(modelid, type, x, y, z, streamdistance, worlds, interiors, players, areas, priority, maxworlds, maxinteriors, maxplayers, maxareas);
	#else
			stock acc_CreateDynamicPickupEx(modelid, type, Float:x, Float:y, Float:z, Float:streamdistance = 200.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, areas[] = { -1 }, priority = 0, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players, maxareas = sizeof areas)
		{
			new ac_pickupid = CreateDynamicPickupEx(modelid, type, x, y, z, streamdistance, worlds, interiors, players, areas, priority, maxworlds, maxinteriors, maxplayers, maxareas);
	#endif
		if(_:ac_pickupid > 0)
		{
			#if defined FILTERSCRIPT
				CallRemoteFunction("ac_CreateDynamicPickup", "iii", ac_pickupid, modelid, type);
			#else
				#if AC_USE_PICKUP_WEAPONS
					ac_CreateDynamicPickup(ac_pickupid, modelid, type);
				#endif
			#endif
		}
		return ac_pickupid;
	}

	#if defined _ALS_CreateDynamicPickupEx
		#undef CreateDynamicPickupEx
	#else
		#define _ALS_CreateDynamicPickupEx
	#endif
	#define CreateDynamicPickupEx acc_CreateDynamicPickupEx
#endif

stock acc_DestroyVehicle(vehicleid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_DestroyVehicle", "i", vehicleid);
	#else
		return ac_DestroyVehicle(vehicleid);
	#endif
}

#if defined _ALS_DestroyVehicle
	#undef DestroyVehicle
#else
	#define _ALS_DestroyVehicle
#endif
#define DestroyVehicle acc_DestroyVehicle

stock acc_DestroyPickup(pickup)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_DestroyPickup", "i", pickup);
	#else
		return ac_DestroyPickup(pickup);
	#endif
}

#if defined _ALS_DestroyPickup
	#undef DestroyPickup
#else
	#define _ALS_DestroyPickup
#endif
#define DestroyPickup acc_DestroyPickup

stock acc_DisableInteriorEnterExits()
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_DisableInteriorEnterExits", "");
	#else
		return ac_DisableInteriorEnterExits();
	#endif
}

#if defined _ALS_DisableInteriorEnterExits
	#undef DisableInteriorEnterExits
#else
	#define _ALS_DisableInteriorEnterExits
#endif
#define DisableInteriorEnterExits acc_DisableInteriorEnterExits

stock acc_UsePlayerPedAnims()
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_UsePlayerPedAnims", "");
	#else
		return ac_UsePlayerPedAnims();
	#endif
}

#if defined _ALS_UsePlayerPedAnims
	#undef UsePlayerPedAnims
#else
	#define _ALS_UsePlayerPedAnims
#endif
#define UsePlayerPedAnims acc_UsePlayerPedAnims

stock acc_EnableVehicleFriendlyFire()
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_EnableVehicleFriendlyFire", "");
	#else
		return ac_EnableVehicleFriendlyFire();
	#endif
}

#if defined _ALS_EnableVehicleFriendlyFire
	#undef EnableVehicleFriendlyFire
#else
	#define _ALS_EnableVehicleFriendlyFire
#endif
#define EnableVehicleFriendlyFire acc_EnableVehicleFriendlyFire

stock acc_EnableStuntBonusForAll(enable)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_EnableStuntBonusForAll", "i", enable);
	#else
		return ac_EnableStuntBonusForAll(enable);
	#endif
}

#if defined _ALS_EnableStuntBonusForAll
	#undef EnableStuntBonusForAll
#else
	#define _ALS_EnableStuntBonusForAll
#endif
#define EnableStuntBonusForAll acc_EnableStuntBonusForAll

stock acc_EnableStuntBonusForPlayer(playerid, enable)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_EnableStuntBonusForPlayer", "ii", playerid, enable);
	#else
		return ac_EnableStuntBonusForPlayer(playerid, enable);
	#endif
}

#if defined _ALS_EnableStuntBonusForPlayer
	#undef EnableStuntBonusForPlayer
#else
	#define _ALS_EnableStuntBonusForPlayer
#endif
#define EnableStuntBonusForPlayer acc_EnableStuntBonusForPlayer

#if defined _inc_y_dialog || defined _INC_y_dialog
	stock ac_Dialog_Show(playerid, style, string:title[], string:caption[], string:button1[], string:button2[] = "", dialog = -1)
	{
		if(!(0 <= playerid < MAX_PLAYERS))
		{
			#if defined FILTERSCRIPT
				CallRemoteFunction("ac_fs_ShowPlayerDialog", "id", playerid, dialog);
			#else
				ac_ShowPlayerDialog(playerid, dialog);
			#endif
		}
		return Dialog_Show(playerid, style, title, caption, button1, button2, dialog);
	}

	#if defined _ALS_Dialog_Show
		#undef Dialog_Show
	#else
		#define _ALS_Dialog_Show
	#endif
	#define Dialog_Show ac_Dialog_Show
#endif

stock acc_ShowPlayerDialog(playerid, dialogid, style, caption[], info[], button1[], button2[])
{
	if(ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2))
	{
		#if defined FILTERSCRIPT
			return CallRemoteFunction("ac_fs_ShowPlayerDialog", "id", playerid, dialogid);
		#else
			return ac_ShowPlayerDialog(playerid, dialogid);
		#endif
	}
	return 0;
}

#if defined _ALS_ShowPlayerDialog
	#undef ShowPlayerDialog
#else
	#define _ALS_ShowPlayerDialog
#endif
#define ShowPlayerDialog acc_ShowPlayerDialog

stock acc_TogglePlayerControllable(playerid, toggle)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_TogglePlayerControllable", "ii", playerid, toggle);
	#else
		return ac_TogglePlayerControllable(playerid, toggle);
	#endif
}

#if defined _ALS_TogglePlayerControllable
	#undef TogglePlayerControllable
#else
	#define _ALS_TogglePlayerControllable
#endif
#define TogglePlayerControllable acc_TogglePlayerControllable

stock acc_TogglePlayerSpectating(playerid, toggle)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_TogglePlayerSpectating", "ii", playerid, toggle);
	#else
		return ac_TogglePlayerSpectating(playerid, toggle);
	#endif
}

#if defined _ALS_TogglePlayerSpectating
	#undef TogglePlayerSpectating
#else
	#define _ALS_TogglePlayerSpectating
#endif
#define TogglePlayerSpectating acc_TogglePlayerSpectating

stock acc_SpawnPlayer(playerid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SpawnPlayer", "i", playerid);
	#else
		return ac_SpawnPlayer(playerid);
	#endif
}

#if defined _ALS_SpawnPlayer
	#undef SpawnPlayer
#else
	#define _ALS_SpawnPlayer
#endif
#define SpawnPlayer acc_SpawnPlayer

stock acc_SetPlayerHealth(playerid, Float:health)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetPlayerHealth", "if", playerid, health);
	#else
		return ac_SetPlayerHealth(playerid, health);
	#endif
}

#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif
#define SetPlayerHealth acc_SetPlayerHealth

stock acc_SetPlayerArmour(playerid, Float:armour)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetPlayerArmour", "if", playerid, armour);
	#else
		return ac_SetPlayerArmour(playerid, armour);
	#endif
}

#if defined _ALS_SetPlayerArmour
	#undef SetPlayerArmour
#else
	#define _ALS_SetPlayerArmour
#endif
#define SetPlayerArmour acc_SetPlayerArmour

stock acc_GivePlayerWeapon(playerid, weaponid, ammo)
{
	if(!(0 <= playerid < MAX_PLAYERS)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_GivePlayerWeapon", "iid", playerid, weaponid, ammo);
	#else
		return ac_GivePlayerWeapon(playerid, weaponid, ammo);
	#endif
}

#if defined _ALS_GivePlayerWeapon
	#undef GivePlayerWeapon
#else
	#define _ALS_GivePlayerWeapon
#endif
#define GivePlayerWeapon acc_GivePlayerWeapon

stock acc_SetPlayerAmmo(playerid, weaponslot, ammo)
{
	if(!(0 <= playerid < MAX_PLAYERS)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetPlayerAmmo", "iid", playerid, weaponslot, ammo);
	#else
		return ac_SetPlayerAmmo(playerid, weaponslot, ammo);
	#endif
}

#if defined _ALS_SetPlayerAmmo
	#undef SetPlayerAmmo
#else
	#define _ALS_SetPlayerAmmo
#endif
#define SetPlayerAmmo acc_SetPlayerAmmo

stock acc_SetPlayerArmedWeapon(playerid, weaponid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetPlayerArmedWeapon", "ii", playerid, weaponid);
	#else
		return ac_SetPlayerArmedWeapon(playerid, weaponid);
	#endif
}

#if defined _ALS_SetPlayerArmedWeapon
	#undef SetPlayerArmedWeapon
#else
	#define _ALS_SetPlayerArmedWeapon
#endif
#define SetPlayerArmedWeapon acc_SetPlayerArmedWeapon

stock acc_ResetPlayerWeapons(playerid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_ResetPlayerWeapons", "i", playerid);
	#else
		return ac_ResetPlayerWeapons(playerid);
	#endif
}

#if defined _ALS_ResetPlayerWeapons
	#undef ResetPlayerWeapons
#else
	#define _ALS_ResetPlayerWeapons
#endif
#define ResetPlayerWeapons acc_ResetPlayerWeapons

stock acc_GivePlayerMoney(playerid, money)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_GivePlayerMoney", "id", playerid, money);
	#else
		return ac_GivePlayerMoney(playerid, money);
	#endif
}

#if defined _ALS_GivePlayerMoney
	#undef GivePlayerMoney
#else
	#define _ALS_GivePlayerMoney
#endif
#define GivePlayerMoney acc_GivePlayerMoney

stock acc_ResetPlayerMoney(playerid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_ResetPlayerMoney", "i", playerid);
	#else
		return ac_ResetPlayerMoney(playerid);
	#endif
}

#if defined _ALS_ResetPlayerMoney
	#undef ResetPlayerMoney
#else
	#define _ALS_ResetPlayerMoney
#endif
#define ResetPlayerMoney acc_ResetPlayerMoney

stock acc_GetPlayerMoney(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetMoney", "i", playerid);
	#else
		return ac_AntiCheatGetMoney(playerid);
	#endif
}

#if defined _ALS_GetPlayerMoney
	#undef GetPlayerMoney
#else
	#define _ALS_GetPlayerMoney
#endif
#define GetPlayerMoney acc_GetPlayerMoney

stock acc_SetPlayerSpecialAction(playerid, actionid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetPlayerSpecialAction", "ii", playerid, actionid);
	#else
		return ac_SetPlayerSpecialAction(playerid, actionid);
	#endif
}

#if defined _ALS_SetPlayerSpecialAction
	#undef SetPlayerSpecialAction
#else
	#define _ALS_SetPlayerSpecialAction
#endif
#define SetPlayerSpecialAction acc_SetPlayerSpecialAction

stock acc_SetPlayerInterior(playerid, interiorid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetPlayerInterior", "ii", playerid, interiorid);
	#else
		return ac_SetPlayerInterior(playerid, interiorid);
	#endif
}

#if defined _ALS_SetPlayerInterior
	#undef SetPlayerInterior
#else
	#define _ALS_SetPlayerInterior
#endif
#define SetPlayerInterior acc_SetPlayerInterior

stock acc_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetPlayerPos", "ifff", playerid, x, y, z);
	#else
		return ac_SetPlayerPos(playerid, x, y, z);
	#endif
}

#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif
#define SetPlayerPos acc_SetPlayerPos

stock acc_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetPlayerPosFindZ", "ifff", playerid, x, y, z);
	#else
		return ac_SetPlayerPosFindZ(playerid, x, y, z);
	#endif
}

#if defined _ALS_SetPlayerPosFindZ
	#undef SetPlayerPosFindZ
#else
	#define _ALS_SetPlayerPosFindZ
#endif
#define SetPlayerPosFindZ acc_SetPlayerPosFindZ

stock acc_SetPlayerVelocity(playerid, Float:X, Float:Y, Float:Z)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetPlayerVelocity", "ifff", playerid, X, Y, Z);
	#else
		return ac_SetPlayerVelocity(playerid, X, Y, Z);
	#endif
}

#if defined _ALS_SetPlayerVelocity
	#undef SetPlayerVelocity
#else
	#define _ALS_SetPlayerVelocity
#endif
#define SetPlayerVelocity acc_SetPlayerVelocity

stock acc_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_PutPlayerInVehicle", "iii", playerid, vehicleid, seatid);
	#else
		return ac_PutPlayerInVehicle(playerid, vehicleid, seatid);
	#endif
}

#if defined _ALS_PutPlayerInVehicle
	#undef PutPlayerInVehicle
#else
	#define _ALS_PutPlayerInVehicle
#endif
#define PutPlayerInVehicle acc_PutPlayerInVehicle

stock acc_RemovePlayerFromVehicle(playerid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_RemovePlayerFromVehicle", "i", playerid);
	#else
		return ac_RemovePlayerFromVehicle(playerid);
	#endif
}

#if defined _ALS_RemovePlayerFromVehicle
	#undef RemovePlayerFromVehicle
#else
	#define _ALS_RemovePlayerFromVehicle
#endif
#define RemovePlayerFromVehicle acc_RemovePlayerFromVehicle

stock acc_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetVehiclePos", "ifff", vehicleid, x, y, z);
	#else
		return ac_SetVehiclePos(vehicleid, x, y, z);
	#endif
}

#if defined _ALS_SetVehiclePos
	#undef SetVehiclePos
#else
	#define _ALS_SetVehiclePos
#endif
#define SetVehiclePos acc_SetVehiclePos

stock acc_SetVehicleVelocity(vehicleid, Float:X, Float:Y, Float:Z)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetVehicleVelocity", "ifff", vehicleid, X, Y, Z);
	#else
		return ac_SetVehicleVelocity(vehicleid, X, Y, Z);
	#endif
}

#if defined _ALS_SetVehicleVelocity
	#undef SetVehicleVelocity
#else
	#define _ALS_SetVehicleVelocity
#endif
#define SetVehicleVelocity acc_SetVehicleVelocity

stock acc_SetVehicleAngularVelocity(vehicleid, Float:X, Float:Y, Float:Z)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetVehicleAngularVelocity", "ifff", vehicleid, X, Y, Z);
	#else
		return ac_SetVehicleAngularVelocity(vehicleid, X, Y, Z);
	#endif
}

#if defined _ALS_SetVehicleAngularVelocity
	#undef SetVehicleAngularVelocity
#else
	#define _ALS_SetVehicleAngularVelocity
#endif
#define SetVehicleAngularVelocity acc_SetVehicleAngularVelocity

stock acc_LinkVehicleToInterior(vehicleid, interiorid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_LinkVehicleToInterior", "ii", vehicleid, interiorid);
	#else
		return ac_LinkVehicleToInterior(vehicleid, interiorid);
	#endif
}

#if defined _ALS_LinkVehicleToInterior
	#undef LinkVehicleToInterior
#else
	#define _ALS_LinkVehicleToInterior
#endif
#define LinkVehicleToInterior acc_LinkVehicleToInterior

stock acc_ChangeVehiclePaintjob(vehicleid, paintjobid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_ChangeVehiclePaintjob", "ii", vehicleid, paintjobid);
	#else
		return ac_ChangeVehiclePaintjob(vehicleid, paintjobid);
	#endif
}

#if defined _ALS_ChangeVehiclePaintjob
	#undef ChangeVehiclePaintjob
#else
	#define _ALS_ChangeVehiclePaintjob
#endif
#define ChangeVehiclePaintjob acc_ChangeVehiclePaintjob

stock acc_SetVehicleHealth(vehicleid, Float:health)
{
	if(floatcmp(health, 0.0) == -1) health = 0.0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_SetVehicleHealth", "if", vehicleid, health);
	#else
		return ac_SetVehicleHealth(vehicleid, health);
	#endif
}

#if defined _ALS_SetVehicleHealth
	#undef SetVehicleHealth
#else
	#define _ALS_SetVehicleHealth
#endif
#define SetVehicleHealth acc_SetVehicleHealth

stock acc_RepairVehicle(vehicleid)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_RepairVehicle", "i", vehicleid);
	#else
		return ac_RepairVehicle(vehicleid);
	#endif
}

#if defined _ALS_RepairVehicle
	#undef RepairVehicle
#else
	#define _ALS_RepairVehicle
#endif
#define RepairVehicle acc_RepairVehicle

stock acc_SetVehicleToRespawn(vehicleid)
{
	if(GetVehicleModel(vehicleid) > 0)
	{
		#if defined FILTERSCRIPT
			return CallRemoteFunction("ac_SetVehicleToRespawn", "i", vehicleid);
		#else
			return ac_SetVehicleToRespawn(vehicleid);
		#endif
	}
	return 0;
}

#if defined _ALS_SetVehicleToRespawn
	#undef SetVehicleToRespawn
#else
	#define _ALS_SetVehicleToRespawn
#endif
#define SetVehicleToRespawn acc_SetVehicleToRespawn

stock EnableAntiCheat(code, enable)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_EnableAntiCheat", "ii", code, enable);
	#else
		return ac_EnableAntiCheat(code, enable);
	#endif
}

stock EnableAntiNOP(nopcode, enable)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_EnableAntiNOP", "ii", nopcode, enable);
	#else
		return ac_EnableAntiNOP(nopcode, enable);
	#endif
}

stock EnableAntiCheatForPlayer(playerid, code, enable)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_EnableAntiCheatForPlayer", "iii", playerid, code, enable);
	#else
		return ac_EnableAntiCheatForPlayer(playerid, code, enable);
	#endif
}

stock EnableAntiNOPForPlayer(playerid, nopcode, enable)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_EnableAntiNOPForPlayer", "iii", playerid, nopcode, enable);
	#else
		return ac_EnableAntiNOPForPlayer(playerid, nopcode, enable);
	#endif
}

stock IsAntiCheatEnabled(code)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_IsAntiCheatEnabled", "i", code);
	#else
		return ac_IsAntiCheatEnabled(code);
	#endif
}

stock IsAntiNOPEnabled(nopcode)
{
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_IsAntiNOPEnabled", "i", nopcode);
	#else
		return ac_IsAntiNOPEnabled(nopcode);
	#endif
}

stock IsAntiCheatEnabledForPlayer(playerid, code)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_IsAntiCheatEnabledForPlayer", "ii", playerid, code);
	#else
		return ac_IsAntiCheatEnabledForPlayer(playerid, code);
	#endif
}

stock IsAntiNOPEnabledForPlayer(playerid, nopcode)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_IsAntiNOPEnabledForPlayer", "ii", playerid, nopcode);
	#else
		return ac_IsAntiNOPEnabledForPlayer(playerid, nopcode);
	#endif
}

stock AntiCheatGetSpeed(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetSpeed", "i", playerid);
	#else
		return ac_AntiCheatGetSpeed(playerid);
	#endif
}

stock AntiCheatGetAnimationIndex(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetAnimationIndex", "i", playerid);
	#else
		return ac_AntiCheatGetAnimationIndex(playerid);
	#endif
}

stock AntiCheatGetDialog(playerid)
{
	if(!IsPlayerConnected(playerid)) return -1;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetDialog", "i", playerid);
	#else
		return ac_AntiCheatGetDialog(playerid);
	#endif
}

stock AntiCheatGetMoney(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetMoney", "i", playerid);
	#else
		return ac_AntiCheatGetMoney(playerid);
	#endif
}

stock AntiCheatGetClass(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetClass", "i", playerid);
	#else
		return ac_AntiCheatGetClass(playerid);
	#endif
}

stock AntiCheatGetEnterVehicle(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetEnterVehicle", "i", playerid);
	#else
		return ac_AntiCheatGetEnterVehicle(playerid);
	#endif
}

stock AntiCheatGetVehicleID(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetVehicleID", "i", playerid);
	#else
		return ac_AntiCheatGetVehicleID(playerid);
	#endif
}

stock AntiCheatGetWeapon(playerid)
{
	if(!IsPlayerConnected(playerid)) return -1;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetWeapon", "i", playerid);
	#else
		return ac_AntiCheatGetWeapon(playerid);
	#endif
}

stock AntiCheatGetVehicleSeat(playerid)
{
	if(!IsPlayerConnected(playerid)) return -1;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetVehicleSeat", "i", playerid);
	#else
		return ac_AntiCheatGetVehicleSeat(playerid);
	#endif
}

stock AntiCheatGetSpecialAction(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetSpecialAction", "i", playerid);
	#else
		return ac_AntiCheatGetSpecialAction(playerid);
	#endif
}

stock AntiCheatGetLastSpecialAction(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetLastSpecialActio", "i", playerid);
	#else
		return ac_AntiCheatGetLastSpecialActio(playerid);
	#endif
}

stock AntiCheatGetLastShotWeapon(playerid)
{
	if(!IsPlayerConnected(playerid)) return -1;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetLastShotWeapon", "i", playerid);
	#else
		return ac_AntiCheatGetLastShotWeapon(playerid);
	#endif
}

stock AntiCheatGetLastPickup(playerid)
{
	if(!IsPlayerConnected(playerid)) return -1;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetLastPickup", "i", playerid);
	#else
		return ac_AntiCheatGetLastPickup(playerid);
	#endif
}

stock AntiCheatGetLastUpdateTime(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetLastUpdateTime", "i", playerid);
	#else
		return ac_AntiCheatGetLastUpdateTime(playerid);
	#endif
}

stock AntiCheatGetLastReloadTime(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetLastReloadTime", "i", playerid);
	#else
		return ac_AntiCheatGetLastReloadTime(playerid);
	#endif
}

stock AntiCheatGetLastEnteredVehTime(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetLastEnteredVehTi", "i", playerid);
	#else
		return ac_AntiCheatGetLastEnteredVehTi(playerid);
	#endif
}

stock AntiCheatGetLastShotTime(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetLastShotTime", "i", playerid);
	#else
		return ac_AntiCheatGetLastShotTime(playerid);
	#endif
}

stock AntiCheatGetLastSpawnTime(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatGetLastSpawnTime", "i", playerid);
	#else
		return ac_AntiCheatGetLastSpawnTime(playerid);
	#endif
}

stock AntiCheatIntEnterExitsIsEnabled(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatIntEnterExitsIsEnab", "i", playerid);
	#else
		return ac_AntiCheatIntEnterExitsIsEnab(playerid);
	#endif
}

stock AntiCheatStuntBonusIsEnabled(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatStuntBonusIsEnabled", "i", playerid);
	#else
		return ac_AntiCheatStuntBonusIsEnabled(playerid);
	#endif
}

stock AntiCheatIsInModShop(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatIsInModShop", "i", playerid);
	#else
		return ac_AntiCheatIsInModShop(playerid);
	#endif
}

stock AntiCheatIsFrozen(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatIsFrozen", "i", playerid);
	#else
		return ac_AntiCheatIsFrozen(playerid);
	#endif
}

stock AntiCheatIsDead(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatIsDead", "i", playerid);
	#else
		return ac_AntiCheatIsDead(playerid);
	#endif
}

stock AntiCheatIsConnected(playerid)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatIsConnected", "i", playerid);
	#else
		return ac_AntiCheatIsConnected(playerid);
	#endif
}

stock AntiCheatKickWithDesync(playerid, code)
{
	if(!IsPlayerConnected(playerid)) return 0;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatKickWithDesync", "ii", playerid, code);
	#else
		return ac_AntiCheatKickWithDesync(playerid, code);
	#endif
}

stock AntiCheatIsKickedWithDecync(playerid)
{
	if(!IsPlayerConnected(playerid)) return 3;
	#if defined FILTERSCRIPT
		return CallRemoteFunction("ac_AntiCheatIsKickedWithDecync", "i", playerid);
	#else
		return ac_AntiCheatIsKickedWithDecync(playerid);
	#endif
}

#if defined _inc_y_hooks || defined _INC_y_hooks
	DEFINE_HOOK_REPLACEMENT(SirenState, Siren);
	DEFINE_HOOK_REPLACEMENT(Vehicle, Veh);
#endif

#if defined FILTERSCRIPT

static fs_AntiCheatGetNextDialog(playerid)
{
	if(!IsPlayerConnected(playerid)) return -1;
	return CallRemoteFunction("ac_AntiCheatGetNextDialog", "i", playerid);
}

static fs_AntiCheatSetDialog(playerid, dialogid)
{
	if(!(0 <= playerid < MAX_PLAYERS)) return 0;
	return CallRemoteFunction("ac_ShowPlayerDialog", "id", playerid, dialogid);
}

static fs_AntiCheatSetNextDialog(playerid, dialogid)
{
	if(!(0 <= playerid < MAX_PLAYERS)) return 0;
	return CallRemoteFunction("ac_fs_ShowPlayerDialog", "id", playerid, dialogid);
}

#else

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnGameModeInit()
#else
	public OnGameModeInit()
#endif
{
	if(!ac_LoadCfg()) printf(CFG_OPENING_ERROR, AC_CONFIG_FILE);
	if(ac_ACAllow[42])
	{
		#if !AC_USE_QUERY
			ac_QueryEnable = !!GetConsoleVarAsBool("query");
			SendRconCommand("query 0");
		#endif
		#undef AC_USE_QUERY
		ac_RconEnable = !!GetConsoleVarAsBool("rcon");
		SendRconCommand("rcon 0");
	}
	#if AC_MAX_CONNECTS_FROM_IP > 1
		ac_ACAllow[37] = false;
	#endif
	ac_LagCompMode = !!GetConsoleVarAsInt("lagcompmode");
	print(" ");
	print("--------------------------------------");
	print(LOADED_MSG_1);
	printf(LOADED_MSG_2, NEX_AC_VERSION);
	print(LOADED_MSG_3);
	print("--------------------------------------\n");
	new ac_a = 1;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnGameModeInit
		ac_a = ac_OnGameModeInit();
	#endif
	static ac_strtmp[10];
	GetConsoleVarAsString("version", ac_strtmp, sizeof ac_strtmp);
	if(strcmp(ac_strtmp, AC_SERVER_VERSION)) print(VERSION_WARNING);
	#undef AC_SERVER_VERSION
	return ac_a;
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit ac_OnGameModeInit
	#if defined ac_OnGameModeInit
		forward ac_OnGameModeInit();
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnGameModeExit()
#else
	public OnGameModeExit()
#endif
{
	new ac_a = 1;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnGameModeExit
		ac_a = ac_OnGameModeExit();
	#endif
	print(" ");
	print("--------------------------------------");
	print(STATS_STRING_1);
	print(STATS_STRING_2);
	printf(STATS_STRING_3, ac_sInfo[0]);
	printf(STATS_STRING_4, ac_sInfo[1]);
	printf(STATS_STRING_5, ac_sInfo[2]);
	printf(STATS_STRING_6, ac_sInfo[3]);
	printf(STATS_STRING_7, ac_sInfo[4]);
	printf(STATS_STRING_8, ac_sInfo[5]);
	print("--------------------------------------\n");
	return ac_a;
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnGameModeExit
		#undef OnGameModeExit
	#else
		#define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit ac_OnGameModeExit
	#if defined ac_OnGameModeExit
		forward ac_OnGameModeExit();
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerConnect(playerid)
#else
	public OnPlayerConnect(playerid)
#endif
{
	ACInfo[playerid][acVeh] =
	ACInfo[playerid][acKicked] =
	ACInfo[playerid][acKickVeh] = 0;
	GetPlayerIp(playerid, ACInfo[playerid][acIp], 16);
	if(IsPlayerNPC(playerid))
	{
		if(ac_ACAllow[36] && strcmp(ACInfo[playerid][acIp], "127.0.0.1")) ac_KickWithCode(playerid, "", 0, 36);
		ACInfo[playerid][acTimerID] = 0;
	}
	else
	{
		if(ac_ACAllow[48] && ACInfo[playerid][acOnline]) ac_KickWithCode(playerid, "", 0, 48, 1);
		if(ac_ACAllow[41])
		{
			static ac_ver[24];
			GetPlayerVersion(playerid, ac_ver, sizeof ac_ver);
			if(!strcmp(ac_ver, "unknown", true))
			{
				#if defined DEBUG
					printf(DEBUG_CODE_2, playerid, ac_ver);
				#endif
				ac_KickWithCode(playerid, "", 0, 41);
			}
		}
		new ac_i = AC_MAX_CONNECTS_FROM_IP;
		if(ac_ACAllow[40])
		{
			#if defined foreach
				foreach(new ac_j : Player)
				{
					if(ac_j != playerid && !IsPlayerNPC(ac_j) && !strcmp(ACInfo[playerid][acIp], ACInfo[ac_j][acIp], false))
			#else
				for(new ac_j = GetPlayerPoolSize(); ac_j >= 0; --ac_j)
				{
					if(ac_j != playerid && IsPlayerConnected(ac_j) && !IsPlayerNPC(ac_j) &&
					!strcmp(ACInfo[playerid][acIp], ACInfo[ac_j][acIp], false))
			#endif
				{
					ac_i--;
					if(ac_i < 1)
					{
						#if defined DEBUG
							printf(DEBUG_CODE_3, playerid, AC_MAX_CONNECTS_FROM_IP);
						#endif
						#undef AC_MAX_CONNECTS_FROM_IP
						ac_KickWithCode(playerid, "", 0, 40);
						break;
					}
				}
			}
		}
		ACInfo[playerid][acSpec] =
		ACInfo[playerid][acSpawned] =
		ACInfo[playerid][acDeathRes] = false;
		ACInfo[playerid][acDead] = true;
		ACInfo[playerid][acIntEnterExits] = ac_IntEnterExits;
		ACInfo[playerid][acStuntBonus] = ac_StuntBonus;
		ACInfo[playerid][acCheatCount][0] =
		ACInfo[playerid][acLastWeapon] =
		ACInfo[playerid][acSpawnRes] =
		ACInfo[playerid][acMoney] =
		ACInfo[playerid][acAnim] =
		ACInfo[playerid][acInt] = 0;
		ACInfo[playerid][acSet][12] =
		ACInfo[playerid][acSet][10] =
		ACInfo[playerid][acSet][0] =
		ACInfo[playerid][acNextDialog] =
		ACInfo[playerid][acDialog] = -1;
		for(ac_i = 12; ac_i >= 0; --ac_i)
		{
			ACInfo[playerid][acSetWeapon][ac_i] = -1;
			ACInfo[playerid][acGiveAmmo][ac_i] = -65535;
		}
		for(ac_i = 27; ac_i >= 0; --ac_i) ACInfo[playerid][acFloodCount][ac_i] = 0;
		ACInfo[playerid][acDropJpX] = ACInfo[playerid][acDropJpY] = ACInfo[playerid][acDropJpZ] = 25000.0;
		memcpy(ACInfo[playerid][acNOPAllow], ac_NOPAllow, 0, sizeof(ac_NOPAllow) * 4, sizeof ac_NOPAllow);
		memcpy(ACInfo[playerid][acACAllow], ac_ACAllow, 0, sizeof(ac_ACAllow) * 4, sizeof ac_ACAllow);
		#if defined SetPlayerTimerEx_
			ACInfo[playerid][acTimerID] = SetPlayerTimerEx_(playerid, "ac_Timer", 0, 1000, 1, "i", playerid);
		#else
			ACInfo[playerid][acTimerID] = SetTimerEx("ac_Timer", 1000, false, "i", playerid);
		#endif
	}
	ACInfo[playerid][acOnline] = true;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerConnect
		return ac_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerConnect
		#undef OnPlayerConnect
	#else
		#define _ALS_OnPlayerConnect
	#endif
	#define OnPlayerConnect ac_OnPlayerConnect
	#if defined ac_OnPlayerConnect
		forward ac_OnPlayerConnect(playerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerDisconnect(playerid, reason)
#else
	public OnPlayerDisconnect(playerid, reason)
#endif
{
	ACInfo[playerid][acOnline] = false;
	if(!IsPlayerNPC(playerid))
	{
		#if defined KillPlayerTimer
			KillPlayerTimer(ACInfo[playerid][acTimerID]);
		#else
			KillTimer(ACInfo[playerid][acTimerID]);
		#endif
		if(ACInfo[playerid][acACAllow][37]) BlockIpAddress(ACInfo[playerid][acIp],
		(AC_MIN_TIME_RECONNECT * 1000) - (reason > 0 ? 0 : GetConsoleVarAsInt("playertimeout")));
		#undef AC_MIN_TIME_RECONNECT
	}
	#if defined KillPlayerTimer
		KillPlayerTimer(ACInfo[playerid][acKickTimerID]);
	#else
		KillTimer(ACInfo[playerid][acKickTimerID]);
	#endif
	new ac_vehid = ACInfo[playerid][acKickVeh];
	if(ac_vehid > 0)
	{
		if(ACVehInfo[ac_vehid][acDriver] == playerid) ACVehInfo[ac_vehid][acDriver] = INVALID_PLAYER_ID;
		if(ACInfo[playerid][acKicked] == 2)
		{
			LinkVehicleToInterior(ac_vehid, ACVehInfo[ac_vehid][acInt]);
			SetVehicleZAngle(ac_vehid, ACVehInfo[ac_vehid][acZAngle]);
			SetVehiclePos(ac_vehid, ACVehInfo[ac_vehid][acPosX], ACVehInfo[ac_vehid][acPosY], ACVehInfo[ac_vehid][acPosZ]);
			SetVehicleHealth(ac_vehid, ACVehInfo[ac_vehid][acHealth]);
			ChangeVehiclePaintjob(ac_vehid, ACVehInfo[ac_vehid][acPaintJob]);
		}
	}
	if((ac_vehid = ACInfo[playerid][acVeh]) > 0)
	{
		if(ACVehInfo[ac_vehid][acDriver] == playerid) ACVehInfo[ac_vehid][acDriver] = INVALID_PLAYER_ID;
		if(ACInfo[playerid][acKicked] == 2)
		{
			LinkVehicleToInterior(ac_vehid, ACVehInfo[ac_vehid][acInt]);
			SetVehicleZAngle(ac_vehid, ACVehInfo[ac_vehid][acZAngle]);
			SetVehiclePos(ac_vehid, ACVehInfo[ac_vehid][acPosX], ACVehInfo[ac_vehid][acPosY], ACVehInfo[ac_vehid][acPosZ]);
			SetVehicleHealth(ac_vehid, ACVehInfo[ac_vehid][acHealth]);
			ChangeVehiclePaintjob(ac_vehid, ACVehInfo[ac_vehid][acPaintJob]);
		}
	}
	if(ACInfo[playerid][acKicked] < 1) ACInfo[playerid][acKicked] = 3;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerDisconnect
		return ac_OnPlayerDisconnect(playerid, reason);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerDisconnect
		#undef OnPlayerDisconnect
	#else
		#define _ALS_OnPlayerDisconnect
	#endif
	#define OnPlayerDisconnect ac_OnPlayerDisconnect
	#if defined ac_OnPlayerDisconnect
		forward ac_OnPlayerDisconnect(playerid, reason);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerSpawn(playerid)
#else
	public OnPlayerSpawn(playerid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	if(!IsPlayerNPC(playerid))
	{
		new ac_i, ac_gtc = GetTickCount();
		if(ACInfo[playerid][acSpec] && ACInfo[playerid][acSet][7] < 2)
		{
			ACInfo[playerid][acSet][3] =
			ACInfo[playerid][acSet][4] =
			ACInfo[playerid][acSet][8] =
			ACInfo[playerid][acSet][9] = -1;
			ACInfo[playerid][acSpec] = false;
		}
		else
		{
			if(ACInfo[playerid][acACAllow][27] &&
			(ACInfo[playerid][acSpawnRes] < 1 || ac_gtc < ACInfo[playerid][acSpawnTime] + 1000))
			{
				#if defined DEBUG
					printf("[Nex-AC debug] Spawn res: %d, Respawn time: %d",
					ACInfo[playerid][acSpawnRes], ac_gtc - ACInfo[playerid][acSpawnTime]);
				#endif
				ac_KickWithCode(playerid, "", 0, 27);
				#if defined OnCheatDetected
					ACInfo[playerid][acSpawnRes] = 1;
				#endif
			}
			if(ACInfo[playerid][acSpawnRes] > 0) ACInfo[playerid][acSpawnRes]--;
			if(!(1 <= ACInfo[playerid][acSet][7] <= 2))
			{
				for(ac_i = 11; ac_i >= 0; --ac_i) ACInfo[playerid][acSet][ac_i] = -1;
				SetPlayerHealth(playerid, 100.0);
				SetPlayerArmour(playerid, 0.0);
				SetPlayerInterior(playerid, 0);
				ACInfo[playerid][acHealth] = 100;
				ACInfo[playerid][acArmour] =
				ACInfo[playerid][acInt] = 0;
			}
		}
		if(!(1 <= ACInfo[playerid][acSet][7] <= 2))
		{
			for(ac_i = 12; ac_i >= 0; --ac_i)
			{
				ACInfo[playerid][acSetWeapon][ac_i] = -1;
				ACInfo[playerid][acGiveAmmo][ac_i] = -65535;
			}
			ACInfo[playerid][acNextSpecAct] = -1;
			ACInfo[playerid][acUnFrozen] = true;
			ACInfo[playerid][acTpToZ] = false;
		}
		for(ac_i = 12; ac_i >= 0; --ac_i) ACInfo[playerid][acWeapon][ac_i] = ACInfo[playerid][acAmmo][ac_i] = 0;
		ACInfo[playerid][acModShop] =
		ACInfo[playerid][acDead] = false;
		ACInfo[playerid][acSpawned] = true;
		ACInfo[playerid][acLastPickup] =
		ACInfo[playerid][acSet][7] =
		ACInfo[playerid][acSeat] = -1;
		ACInfo[playerid][acCheatCount][5] =
		ACInfo[playerid][acCheatCount][6] =
		ACInfo[playerid][acCheatCount][7] =
		ACInfo[playerid][acCheatCount][8] =
		ACInfo[playerid][acCheatCount][9] =
		ACInfo[playerid][acCheatCount][13] =
		ACInfo[playerid][acCheatCount][14] =
		ACInfo[playerid][acCheatCount][16] =
		ACInfo[playerid][acCheatCount][18] =
		ACInfo[playerid][acLastSpecAct] =
		ACInfo[playerid][acLastWeapon] =
		ACInfo[playerid][acParachute] =
		ACInfo[playerid][acEnterVeh] =
		ACInfo[playerid][acLastShot] =
		ACInfo[playerid][acKickVeh] =
		ACInfo[playerid][acSpecAct] =
		ACInfo[playerid][acDmgRes] =
		ACInfo[playerid][acIntRet] =
		ACInfo[playerid][acSpeed] =
		ACInfo[playerid][acVeh] = 0;
		ACInfo[playerid][acSetPosTime] =
		ACInfo[playerid][acGtc][7] = ac_gtc + 1650;
		if(1 <= ACInfo[playerid][acSpawnWeapon1] <= 46)
		{
			ac_i = ac_wSlot[ACInfo[playerid][acSpawnWeapon1]];
			ACInfo[playerid][acWeapon][ac_i] = ACInfo[playerid][acSpawnWeapon1];
			ACInfo[playerid][acAmmo][ac_i] = ACInfo[playerid][acSpawnAmmo1];
		}
		if(1 <= ACInfo[playerid][acSpawnWeapon2] <= 46)
		{
			ac_i = ac_wSlot[ACInfo[playerid][acSpawnWeapon2]];
			ACInfo[playerid][acWeapon][ac_i] = ACInfo[playerid][acSpawnWeapon2];
			ACInfo[playerid][acAmmo][ac_i] = ACInfo[playerid][acSpawnAmmo2];
		}
		if(1 <= ACInfo[playerid][acSpawnWeapon3] <= 46)
		{
			ac_i = ac_wSlot[ACInfo[playerid][acSpawnWeapon3]];
			ACInfo[playerid][acWeapon][ac_i] = ACInfo[playerid][acSpawnWeapon3];
			ACInfo[playerid][acAmmo][ac_i] = ACInfo[playerid][acSpawnAmmo3];
		}
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerSpawn
		return ac_OnPlayerSpawn(playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerSpawn
		#undef OnPlayerSpawn
	#else
		#define _ALS_OnPlayerSpawn
	#endif
	#define OnPlayerSpawn ac_OnPlayerSpawn
	#if defined ac_OnPlayerSpawn
		forward ac_OnPlayerSpawn(playerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerDeath(playerid, killerid, reason)
#else
	public OnPlayerDeath(playerid, killerid, reason)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	if(ACInfo[playerid][acACAllow][28] &&
	(ACInfo[playerid][acDead] || !ACInfo[playerid][acDeathRes] &&
	reason != 255 && (reason != WEAPON_COLLISION || killerid != INVALID_PLAYER_ID)))
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Is dead: %d, Death res: %d, killerid: %d, reason: %d",
			ACInfo[playerid][acDead], ACInfo[playerid][acDeathRes], killerid, reason);
		#endif
		ac_KickWithCode(playerid, "", 0, 28);
	}
	ACInfo[playerid][acDead] = true;
	ACInfo[playerid][acDeathRes] = false;
	if(ACInfo[playerid][acSpawnRes] < 1) ACInfo[playerid][acSpawnTime] = GetTickCount();
	ACInfo[playerid][acSpawnRes] = 1;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerDeath
		return ac_OnPlayerDeath(playerid, killerid, reason);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerDeath
		#undef OnPlayerDeath
	#else
		#define _ALS_OnPlayerDeath
	#endif
	#define OnPlayerDeath ac_OnPlayerDeath
	#if defined ac_OnPlayerDeath
		forward ac_OnPlayerDeath(playerid, killerid, reason);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
#else
	public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	if(ACInfo[playerid][acACAllow][47] && !(3 <= bodypart <= 9))
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Issuerid: %d, amount: %f, weaponid: %d, bodypart: %d", issuerid, amount, weaponid, bodypart);
		#endif
		ac_KickWithCode(playerid, "", 0, 47, 4);
		return 1;
	}
	if(!ACInfo[playerid][acDead]) ACInfo[playerid][acDeathRes] = true;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerTakeDamage
		return ac_OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerTakeDamage
		#undef OnPlayerTakeDamage
	#else
		#define _ALS_OnPlayerTakeDamage
	#endif
	#define OnPlayerTakeDamage ac_OnPlayerTakeDamage
	#if defined ac_OnPlayerTakeDamage
		forward ac_OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
#else
	public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	if(ACInfo[playerid][acACAllow][47] && (!(0 <= damagedid < MAX_PLAYERS) || !(3 <= bodypart <= 9)))
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Damagedid: %d, amount: %f, weaponid: %d, bodypart: %d", damagedid, amount, weaponid, bodypart);
		#endif
		ac_KickWithCode(playerid, "", 0, 47, 3);
		return 1;
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerGiveDamage
		return ac_OnPlayerGiveDamage(playerid, damagedid, amount, weaponid, bodypart);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerGiveDamage
		#undef OnPlayerGiveDamage
	#else
		#define _ALS_OnPlayerGiveDamage
	#endif
	#define OnPlayerGiveDamage ac_OnPlayerGiveDamage
	#if defined ac_OnPlayerGiveDamage
		forward ac_OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart);
	#endif
#endif

#endif

#if defined FILTERSCRIPT

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
#else
	public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
#endif
{
	if(dialogid != AntiCheatGetDialog(playerid))
	{
		new ac_nd = fs_AntiCheatGetNextDialog(playerid);
		if(dialogid == ac_nd) fs_AntiCheatSetDialog(playerid, ac_nd);
	}
	fs_AntiCheatSetNextDialog(playerid, -1);
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_fs_OnDialogResponse
		return ac_fs_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnDialogResponse
		#undef OnDialogResponse
	#else
		#define _ALS_OnDialogResponse
	#endif
	#define OnDialogResponse ac_fs_OnDialogResponse
	#if defined ac_fs_OnDialogResponse
		forward ac_fs_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
	#endif
#endif

#else

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
#else
	public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	new ac_i = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_i < ACInfo[playerid][acCall][0] + ac_Mtfc[0][0]) ac_FloodDetect(playerid, 0);
		else if(ac_i < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][0] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	if(ACInfo[playerid][acACAllow][39] && (dialogid != ACInfo[playerid][acDialog] || listitem < -1))
	{
		#if defined DEBUG
			printf("[Nex-AC debug] AC dialog: %d, dialogid: %d, listitem: %d, playerid: %d",
			ACInfo[playerid][acDialog], dialogid, listitem, playerid);
		#endif
		ac_KickWithCode(playerid, "", 0, 39);
		return 1;
	}
	ACInfo[playerid][acDialog] = -1;
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][0] = ac_i;
	if(ACInfo[playerid][acACAllow][45])
	{
		for(ac_i = strlen(inputtext) - 1; ac_i >= 0; --ac_i)
		{
			if(inputtext[ac_i] == '%') strdel(inputtext, ac_i, ac_i + 1);
		}
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnDialogResponse
		return ac_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnDialogResponse
		#undef OnDialogResponse
	#else
		#define _ALS_OnDialogResponse
	#endif
	#define OnDialogResponse ac_OnDialogResponse
	#if defined ac_OnDialogResponse
		forward ac_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnEnterExitModShop(playerid, enterexit, interiorid)
#else
	public OnEnterExitModShop(playerid, enterexit, interiorid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	#if !AC_USE_TUNING_GARAGES
		if(ACInfo[playerid][acACAllow][23]) ac_KickWithCode(playerid, "", 0, 23, 1);
	#else
		if(ACInfo[playerid][acACAllow][23] &&
		(!(0 <= enterexit <= 1) || !(0 <= interiorid <= 3))) ac_KickWithCode(playerid, "", 0, 23, 7);
	#endif
	new ac_i = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_i < ACInfo[playerid][acCall][1] + ac_Mtfc[1][0]) ac_FloodDetect(playerid, 1);
		else if(ac_i < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][1] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	ACInfo[playerid][acModShop] = !!enterexit;
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][1] = ac_i;
	ACInfo[playerid][acSetPosTime] = ACInfo[playerid][acGtc][11] = ac_i + 3250;
	new ac_veh = ACInfo[playerid][acVeh];
	if(ACInfo[playerid][acKicked] < 1)
	{
		ac_i = interiorid % 256;
		ACVehInfo[ac_veh][acInt] = ac_i;
		#if defined foreach
			foreach(new ac_j : Player)
			{
				if(ACInfo[ac_j][acVeh] == ac_veh) ACInfo[ac_j][acInt] = ac_i;
			}
		#else
			for(new ac_j = GetPlayerPoolSize(); ac_j >= 0; --ac_j)
			{
				if(IsPlayerInVehicle(ac_j, ac_veh)) ACInfo[ac_j][acInt] = ac_i;
			}
		#endif
	}
	else
	{
		#if defined foreach
			foreach(new ac_j : Player)
			{
				if(ACInfo[ac_j][acVeh] == ac_veh)
				{
					if(ACInfo[ac_j][acUnFrozen]) ACInfo[ac_j][acIntRet] = 2;
					else ACInfo[ac_j][acIntRet] = 1;
				}
			}
		#else
			for(new ac_j = GetPlayerPoolSize(); ac_j >= 0; --ac_j)
			{
				if(IsPlayerInVehicle(ac_j, ac_veh))
				{
					if(ACInfo[ac_j][acUnFrozen]) ACInfo[ac_j][acIntRet] = 2;
					else ACInfo[ac_j][acIntRet] = 1;
				}
			}
		#endif
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnEnterExitModShop
		return ac_OnEnterExitModShop(playerid, enterexit, interiorid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnEnterExitModShop
		#undef OnEnterExitModShop
	#else
		#define _ALS_OnEnterExitModShop
	#endif
	#define OnEnterExitModShop ac_OnEnterExitModShop
	#if defined ac_OnEnterExitModShop
		forward ac_OnEnterExitModShop(playerid, enterexit, interiorid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
#else
	public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
#endif
{
	if(!(0 <= playerid < MAX_PLAYERS) || ACInfo[playerid][acKicked] > 0) return 0;
	if(ACInfo[playerid][acIntRet] > 0)
	{
		SetPlayerInterior(playerid, ACInfo[playerid][acInt]);
		if(ACInfo[playerid][acIntRet] == 2) TogglePlayerControllable(playerid, 1);
		ACInfo[playerid][acIntRet] = 0;
	}
	else if(newinteriorid != ACInfo[playerid][acSet][0])
	{
		if(ACInfo[playerid][acSet][0] == -1)
		{
			new ac_vehid = GetPlayerVehicleID(playerid);
			if(ac_vehid > 0)
			{
				if(ACInfo[playerid][acACAllow][3] && newinteriorid != ACInfo[playerid][acInt])
				{
					#if defined DEBUG
						printf("[Nex-AC debug] AC interior: %d, acInt (last): %d, newinteriorid: %d, oldinteriorid: %d, veh: %d",
						ACInfo[playerid][acSet][0], ACInfo[playerid][acInt], newinteriorid, oldinteriorid, ac_vehid);
					#endif
					ac_KickWithCode(playerid, "", 0, 3, 1);
				}
			}
			else if(ACInfo[playerid][acIntEnterExits])
			{
				GetPlayerPos(playerid, ACInfo[playerid][acPosX], ACInfo[playerid][acPosY], ACInfo[playerid][acPosZ]);
				ACInfo[playerid][acSetPosTime] = ACInfo[playerid][acGtc][11] = GetTickCount() + 3250;
			}
			else if(ACInfo[playerid][acACAllow][2] && newinteriorid != ACInfo[playerid][acInt])
			{
				#if defined DEBUG
					printf("[Nex-AC debug] AC interior: %d, acInt (last): %d, newinteriorid: %d, oldinteriorid: %d",
					ACInfo[playerid][acSet][0], ACInfo[playerid][acInt], newinteriorid, oldinteriorid);
				#endif
				ac_KickWithCode(playerid, "", 0, 2, 1);
			}
		}
	}
	else ACInfo[playerid][acSet][0] = -1;
	if(ACInfo[playerid][acKicked] < 1) ACInfo[playerid][acInt] = newinteriorid % 256;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerInteriorChange
		return ac_OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerInteriorChange
		#undef OnPlayerInteriorChange
	#else
		#define _ALS_OnPlayerInteriorChange
	#endif
	#define OnPlayerInteriorChange ac_OnPlayerInteriorChange
	#if defined ac_OnPlayerInteriorChange
		forward ac_OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnRconLoginAttempt(ip[], password[], success)
#else
	public OnRconLoginAttempt(ip[], password[], success)
#endif
{
	if(ac_ACAllow[42])
	{
		static ac_ipTables[MAX_PLAYERS][2], ac_ip_index;
		new ac_i, ac_current_ip = ac_IpToInt(ip);
		for(; ac_i < ac_ip_index && ac_i < sizeof ac_ipTables; ++ac_i)
		{
			if(ac_ipTables[ac_i][0] == ac_current_ip)
			{
				if(success) ac_ipTables[ac_i][1] = 0;
				else if(++ac_ipTables[ac_i][1] > AC_MAX_RCON_LOGIN_ATTEMPT)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_4, ip, password);
					#endif
					ac_ipTables[ac_i][1] = 0;
					ac_KickWithCode(INVALID_PLAYER_ID, ip, 1, 42, 1);
				}
				#if defined OnCheatWarning
					else OnCheatWarning(INVALID_PLAYER_ID, ip, 1, 42, 1, ac_ipTables[ac_i][1]);
				#endif
				ac_i = -1;
				break;
			}
		}
		if(ac_i != -1 && !success)
		{
			ac_ipTables[ac_ip_index][0] = ac_current_ip;
			if(++ac_ipTables[ac_ip_index][1] > AC_MAX_RCON_LOGIN_ATTEMPT)
			{
				#undef AC_MAX_RCON_LOGIN_ATTEMPT
				#if defined DEBUG
					printf(DEBUG_CODE_4, ip, password, ac_ipTables[ac_ip_index][1]);
				#endif
				ac_ipTables[ac_ip_index][1] = 0;
				ac_KickWithCode(INVALID_PLAYER_ID, ip, 1, 42, 2);
			}
			#if defined OnCheatWarning
				else OnCheatWarning(INVALID_PLAYER_ID, ip, 1, 42, 2, ac_ipTables[ac_ip_index][1]);
			#endif
			if(++ac_ip_index >= sizeof ac_ipTables) ac_ip_index = 0;
			ac_ipTables[ac_ip_index][1] = 0;
		}
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnRconLoginAttempt
		return ac_OnRconLoginAttempt(ip, password, success);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnRconLoginAttempt
		#undef OnRconLoginAttempt
	#else
		#define _ALS_OnRconLoginAttempt
	#endif
	#define OnRconLoginAttempt ac_OnRconLoginAttempt
	#if defined ac_OnRconLoginAttempt
		forward ac_OnRconLoginAttempt(ip[], password[], success);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerUpdate(playerid)
#else
	public OnPlayerUpdate(playerid)
#endif
{
	if(!(0 <= playerid < MAX_PLAYERS) || ACInfo[playerid][acKicked] > 0) return 0;
	new ac_gtc = GetTickCount(), ac_gpp;
	if(!IsPlayerNPC(playerid))
	{
		new ac_w, ac_sa = GetPlayerState(playerid);
		if(ac_sa != PLAYER_STATE_SPECTATING && (ac_w = GetPlayerWeapon(playerid)) != -1)
		{
			ac_gpp = GetPlayerPing(playerid);
			new ac_a = GetPlayerAmmo(playerid), ac_s = ac_wSlot[ac_w];
			if(ACInfo[playerid][acSet][3] != -1)
			{
				if(ACInfo[playerid][acSet][3] == ac_w)
				{
					ACInfo[playerid][acSet][3] =
					ACInfo[playerid][acSetWeapon][ac_s] = -1;
					ACInfo[playerid][acWeapon][ac_s] = ac_w;
				}
				else if(ACInfo[playerid][acGiveAmmo][ac_wSlot[ACInfo[playerid][acSet][3]]] == 0 ||
				ac_wSlot[ACInfo[playerid][acSet][3]] != ac_s && ac_gtc > ACInfo[playerid][acGtc][2] + ac_gpp) ACInfo[playerid][acSet][3] = -1;
				else if(!(PLAYER_STATE_DRIVER <= ac_sa <= PLAYER_STATE_PASSENGER) && ac_gtc > ACInfo[playerid][acGtc][2] + ac_gpp)
				{
					if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][0])
					{
						if(++ACInfo[playerid][acNOPCount][0] > AC_MAX_NOP_WARNINGS)
						{
							#if defined DEBUG
								printf(DEBUG_CODE_5, playerid, "SetPlayerArmedWeapon");
								printf("[Nex-AC debug] AC weapon: %d, weaponid: %d", ACInfo[playerid][acSet][3], ac_w);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 52, 1);
								if(ACInfo[playerid][acKicked] > 0) return 0;
								ACInfo[playerid][acSetWeapon][ac_s] = ACInfo[playerid][acSet][3] = -1;
							#else
								return ac_KickWithCode(playerid, "", 0, 52, 1);
							#endif
						}
						#if defined OnNOPWarning
							else OnNOPWarning(playerid, 1, ACInfo[playerid][acNOPCount][0]);
						#endif
					}
					else if(++ACInfo[playerid][acNOPCount][0] > AC_MAX_NOP_WARNINGS)
					{
						ACInfo[playerid][acSetWeapon][ac_s] =
						ACInfo[playerid][acSet][3] = -1;
					}
				}
			}
			if(ACInfo[playerid][acGiveAmmo][ac_s] != -65535)
			{
				if(ACInfo[playerid][acGiveAmmo][ac_s] == ac_a ||
				ACInfo[playerid][acGiveAmmo][ac_s] > ac_a && ac_gtc > ACInfo[playerid][acGtcGiveAmmo][ac_s] + ac_gpp)
				{
					ACInfo[playerid][acGiveAmmo][ac_s] = -65535;
					ACInfo[playerid][acAmmo][ac_s] = ac_a;
				}
				else if(ac_gtc > ACInfo[playerid][acGtcGiveAmmo][ac_s] + ac_gpp)
				{
					if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][1])
					{
						if(++ACInfo[playerid][acNOPCount][1] > AC_MAX_NOP_WARNINGS)
						{
							#if defined DEBUG
								printf(DEBUG_CODE_5, playerid, "SetPlayerAmmo");
								printf("[Nex-AC debug] AC ammo: %d, ammo: %d, weaponid: %d",
								ACInfo[playerid][acGiveAmmo][ac_s], ac_a, ac_w);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 52, 2);
								if(ACInfo[playerid][acKicked] > 0) return 0;
								ACInfo[playerid][acGiveAmmo][ac_s] = -65535;
							#else
								return ac_KickWithCode(playerid, "", 0, 52, 2);
							#endif
						}
						#if defined OnNOPWarning
							else OnNOPWarning(playerid, 2, ACInfo[playerid][acNOPCount][1]);
						#endif
					}
					else if(++ACInfo[playerid][acNOPCount][1] > AC_MAX_NOP_WARNINGS) ACInfo[playerid][acGiveAmmo][ac_s] = -65535;
				}
			}
			#if AC_USE_AMMUNATIONS || AC_USE_TUNING_GARAGES
				new ac_money = bad_GetPlayerMoney(playerid);
			#endif
			#if AC_USE_AMMUNATIONS
				if(ACInfo[playerid][acSet][10] != -1)
				{
					if(ac_money < ACInfo[playerid][acMoney] &&
					ACInfo[playerid][acSet][10] <= ACInfo[playerid][acMoney] - ac_money) ACInfo[playerid][acSet][10] = -1;
					else if(ac_gtc > ACInfo[playerid][acGtc][15] + ac_gpp)
					{
						if(ACInfo[playerid][acACAllow][15])
						{
							if(++ACInfo[playerid][acCheatCount][10] > AC_MAX_NOP_WARNINGS)
							{
								#if defined DEBUG
									printf("[Nex-AC debug] Money: %d, old money: %d, price: %d",
									ac_money, ACInfo[playerid][acMoney], ACInfo[playerid][acSet][10]);
								#endif
								#if defined OnCheatDetected
									ac_KickWithCode(playerid, "", 0, 15, 3);
									if(ACInfo[playerid][acKicked] > 0) return 0;
									ACInfo[playerid][acSet][10] = -1;
								#else
									return ac_KickWithCode(playerid, "", 0, 15, 3);
								#endif
							}
							#if defined OnCheatWarning
								else OnCheatWarning(playerid, "", 0, 15, 3, ACInfo[playerid][acCheatCount][10]);
							#endif
						}
						else if(++ACInfo[playerid][acCheatCount][10] > AC_MAX_NOP_WARNINGS) ACInfo[playerid][acSet][10] = -1;
					}
				}
			#endif
			new ac_i = GetPlayerInterior(playerid), Float:ac_X, Float:ac_Y, Float:ac_Z, Float:ac_tmp;
			GetPlayerPos(playerid, ac_X, ac_Y, ac_Z);
			if(ACInfo[playerid][acLastWeapon] != ac_w)
			{
				if(ACInfo[playerid][acWeapon][ac_s] != ac_w && ac_gtc > ACInfo[playerid][acGtc][7] + ac_gpp)
				{
					#if AC_USE_PICKUP_WEAPONS
						#if defined Streamer_GetDistanceToItem\
							&& defined Streamer_GetIntData
						if(ACInfo[playerid][acLastPickup] > MAX_PICKUPS) Streamer_GetDistanceToItem(ac_X, ac_Y, ac_Z, STREAMER_TYPE_PICKUP, ACInfo[playerid][acLastPickup] - MAX_PICKUPS, ac_tmp);
						if(0 <= ACInfo[playerid][acLastPickup] < MAX_PICKUPS && ACPickInfo[ACInfo[playerid][acLastPickup]][acWeapon] == ac_w &&
						ac_a <= (3 <= ac_s <= 5 ? ACInfo[playerid][acAmmo][ac_s] + ac_pAmmo[ac_w] : ac_pAmmo[ac_w]) &&
						IsPlayerInRangeOfPoint(playerid, 15.0, ACPickInfo[ACInfo[playerid][acLastPickup]][acPosX],
						ACPickInfo[ACInfo[playerid][acLastPickup]][acPosY], ACPickInfo[ACInfo[playerid][acLastPickup]][acPosZ]) ||
						ACInfo[playerid][acLastPickup] > MAX_PICKUPS &&
						Streamer_GetIntData(STREAMER_TYPE_PICKUP, ACInfo[playerid][acLastPickup] - MAX_PICKUPS, E_STREAMER_EXTRA_ID) == ac_w + 100 &&
						ac_a <= (3 <= ac_s <= 5 ? ACInfo[playerid][acAmmo][ac_s] + ac_pAmmo[ac_w] : ac_pAmmo[ac_w]) && floatcmp(ac_tmp, 15.0) <= 0)
						{
							ACInfo[playerid][acWeapon][ac_s] = ac_w;
							ACInfo[playerid][acAmmo][ac_s] = ac_a;
						}
						#else
						if(0 <= ACInfo[playerid][acLastPickup] < MAX_PICKUPS && ACPickInfo[ACInfo[playerid][acLastPickup]][acWeapon] == ac_w &&
						ac_a <= (3 <= ac_s <= 5 ? ACInfo[playerid][acAmmo][ac_s] + ac_pAmmo[ac_w] : ac_pAmmo[ac_w]) &&
						IsPlayerInRangeOfPoint(playerid, 15.0, ACPickInfo[ACInfo[playerid][acLastPickup]][acPosX],
						ACPickInfo[ACInfo[playerid][acLastPickup]][acPosY], ACPickInfo[ACInfo[playerid][acLastPickup]][acPosZ]))
						{
							ACInfo[playerid][acWeapon][ac_s] = ac_w;
							ACInfo[playerid][acAmmo][ac_s] = ac_a;
						}
						#endif
						else
						{
					#endif
						#if AC_USE_AMMUNATIONS
							if(22 <= ac_w <= 32 && ac_InAmmuNation(playerid, ac_i))
							{
								ACInfo[playerid][acCheatCount][10] = 0;
								if(ACInfo[playerid][acSet][10] != -1) ACInfo[playerid][acSet][10] += ac_AmmuNationInfo[ac_w - 22][0];
								else ACInfo[playerid][acSet][10] = ac_AmmuNationInfo[ac_w - 22][0];
								if(3 <= ac_s <= 5) ACInfo[playerid][acAmmo][ac_s] += ac_AmmuNationInfo[ac_w - 22][1];
								else ACInfo[playerid][acAmmo][ac_s] = ac_AmmuNationInfo[ac_w - 22][1];
								ACInfo[playerid][acWeapon][ac_s] = ac_w;
								ACInfo[playerid][acGtc][15] = ac_gtc + 2650;
							}
							else
							{
						#endif
							if(ac_w == 40 || ac_w == 46 && ACInfo[playerid][acVeh] > 0 && ACInfo[playerid][acParachute] > 0)
							{
								ACInfo[playerid][acWeapon][ac_s] = ac_w;
								ACInfo[playerid][acAmmo][ac_s] = ac_a;
								ACInfo[playerid][acParachute] = 0;
							}
							else if(ACInfo[playerid][acACAllow][15] && ACInfo[playerid][acSetWeapon][ac_s] == -1)
							{
								#if defined DEBUG
									printf("[Nex-AC debug] AC weaponid: %d, AC ammo: %d, weaponid: %d, ammo: %d",
									ACInfo[playerid][acWeapon][ac_s], ACInfo[playerid][acAmmo][ac_s], ac_w, ac_a);
								#endif
								#if defined OnCheatDetected
									ac_KickWithCode(playerid, "", 0, 15, 1);
									if(ACInfo[playerid][acKicked] > 0) return 0;
									ACInfo[playerid][acWeapon][ac_s] = ac_w;
									ACInfo[playerid][acAmmo][ac_s] = ac_a;
								#else
									return ac_KickWithCode(playerid, "", 0, 15, 1);
								#endif
							}
						#if AC_USE_AMMUNATIONS
							}
						#endif
					#if AC_USE_PICKUP_WEAPONS
						}
					#endif
				}
			}
			else if(ACInfo[playerid][acAmmo][ac_s] != ac_a)
			{
				switch(ac_w)
				{
					case 16..18, 35..37, 39, 41..43:
					{
						if(ac_sa != PLAYER_STATE_DRIVER && ac_gtc > ACInfo[playerid][acGtc][7] + ac_gpp)
						{
							if(ACInfo[playerid][acACAllow][16] &&
							(ACInfo[playerid][acAmmo][ac_s] == 0 || ac_a > ACInfo[playerid][acAmmo][ac_s] ||
							ac_a < 0 < ACInfo[playerid][acAmmo][ac_s]))
							{
								#if defined DEBUG
									printf("[Nex-AC debug] AC ammo: %d, ammo: %d, weaponid: %d",
									ACInfo[playerid][acAmmo][ac_s], ac_a, ac_w);
								#endif
								#if defined OnCheatDetected
									ac_KickWithCode(playerid, "", 0, 16, 1);
									if(ACInfo[playerid][acKicked] > 0) return 0;
								#else
									return ac_KickWithCode(playerid, "", 0, 16, 1);
								#endif
							}
							ACInfo[playerid][acAmmo][ac_s] = ac_a;
						}
					}
				}
			}
			GetPlayerHealth(playerid, ac_tmp);
			new ac_health = floatround(ac_tmp, floatround_tozero);
			if(ACInfo[playerid][acSet][1] != -1)
			{
				if(ACInfo[playerid][acSet][1] > 255)
				{
					ac_health += 256 * (((ACInfo[playerid][acSet][1] - (ACInfo[playerid][acSet][1] % 256)) / 256) - 1);
					if(ACInfo[playerid][acSet][1] > ac_health + 255) ac_health += 256;
				}
				if(ACInfo[playerid][acSet][1] == ac_health || ACInfo[playerid][acDmgRes] ||
				ACInfo[playerid][acSet][1] > ac_health && ac_gtc > ACInfo[playerid][acGtc][3] + ac_gpp)
				{
					ACInfo[playerid][acSet][1] = -1;
					ACInfo[playerid][acDmgRes] = 0;
				}
				else if(ac_gtc > ACInfo[playerid][acGtc][3] + ac_gpp)
				{
					if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][3])
					{
						if(++ACInfo[playerid][acNOPCount][3] > AC_MAX_NOP_WARNINGS)
						{
							#if defined DEBUG
								printf(DEBUG_CODE_5, playerid, "SetPlayerHealth");
								printf("[Nex-AC debug] AC health: %d, health: %d", ACInfo[playerid][acSet][1], ac_health);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 52, 3);
								if(ACInfo[playerid][acKicked] > 0) return 0;
								ACInfo[playerid][acSet][1] = -1;
							#else
								return ac_KickWithCode(playerid, "", 0, 52, 3);
							#endif
						}
						#if defined OnNOPWarning
							else OnNOPWarning(playerid, 3, ACInfo[playerid][acNOPCount][3]);
						#endif
					}
					else if(++ACInfo[playerid][acNOPCount][3] > AC_MAX_NOP_WARNINGS) ACInfo[playerid][acSet][1] = -1;
				}
			}
			else if(ACInfo[playerid][acACAllow][12])
			{
				if(ACInfo[playerid][acHealth] > 255)
				{
					ac_health += 256 * (((ACInfo[playerid][acHealth] - (ACInfo[playerid][acHealth] % 256)) / 256) - 1);
					if(ACInfo[playerid][acHealth] > ac_health + 255) ac_health += 256;
				}
				if(ac_health > ACInfo[playerid][acHealth])
				{
					#if AC_USE_RESTAURANTS
						if(ac_health > ACInfo[playerid][acHealth] + 70 || !ac_InRestaurant(playerid, ac_i))
						{
					#endif
						#if AC_USE_VENDING_MACHINES
							if(ac_health > ACInfo[playerid][acHealth] + 35 || !ac_NearVendingMachine(playerid, ac_i))
							{
						#endif
							#if defined DEBUG
								printf("[Nex-AC debug] AC health: %d, health: %d", ACInfo[playerid][acHealth], ac_health);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 12);
								if(ACInfo[playerid][acKicked] > 0) return 0;
							#else
								return ac_KickWithCode(playerid, "", 0, 12);
							#endif
						#if AC_USE_VENDING_MACHINES
							}
						#endif
					#if AC_USE_RESTAURANTS
						}
					#endif
				}
			}
			GetPlayerArmour(playerid, ac_tmp);
			new ac_armour = floatround(ac_tmp, floatround_tozero);
			if(ACInfo[playerid][acSet][2] != -1)
			{
				if(ACInfo[playerid][acSet][2] > 255)
				{
					ac_armour += 256 * (((ACInfo[playerid][acSet][2] - (ACInfo[playerid][acSet][2] % 256)) / 256) - 1);
					if(ACInfo[playerid][acSet][2] > ac_armour + 255) ac_armour += 256;
				}
				if(ACInfo[playerid][acSet][2] == ac_armour || ACInfo[playerid][acDmgRes] ||
				ACInfo[playerid][acSet][2] > ac_armour && ac_gtc > ACInfo[playerid][acGtc][5] + ac_gpp)
				{
					ACInfo[playerid][acSet][2] = -1;
					ACInfo[playerid][acDmgRes] = 0;
				}
				else if(ac_gtc > ACInfo[playerid][acGtc][5] + ac_gpp)
				{
					if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][5])
					{
						if(++ACInfo[playerid][acNOPCount][5] > AC_MAX_NOP_WARNINGS)
						{
							#if defined DEBUG
								printf(DEBUG_CODE_5, playerid, "SetPlayerArmour");
								printf("[Nex-AC debug] AC armour: %d, armour: %d", ACInfo[playerid][acSet][2], ac_armour);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 52, 4);
								if(ACInfo[playerid][acKicked] > 0) return 0;
								ACInfo[playerid][acSet][2] = -1;
							#else
								return ac_KickWithCode(playerid, "", 0, 52, 4);
							#endif
						}
						#if defined OnNOPWarning
							else OnNOPWarning(playerid, 4, ACInfo[playerid][acNOPCount][5]);
						#endif
					}
					else if(++ACInfo[playerid][acNOPCount][5] > AC_MAX_NOP_WARNINGS) ACInfo[playerid][acSet][2] = -1;
				}
			}
			else if(ACInfo[playerid][acACAllow][13])
			{
				if(ACInfo[playerid][acArmour] > 255)
				{
					ac_armour += 256 * (((ACInfo[playerid][acArmour] - (ACInfo[playerid][acArmour] % 256)) / 256) - 1);
					if(ACInfo[playerid][acArmour] > ac_armour + 255) ac_armour += 256;
				}
				if(ac_armour > ACInfo[playerid][acArmour])
				{
					#if AC_USE_AMMUNATIONS
						if(ac_InAmmuNation(playerid, ac_i))
						{
							ACInfo[playerid][acCheatCount][10] = 0;
							if(ACInfo[playerid][acSet][10] != -1) ACInfo[playerid][acSet][10] += 200;
							else ACInfo[playerid][acSet][10] = 200;
							ACInfo[playerid][acGtc][15] = ac_gtc + 2650;
						}
						else
						{
					#endif
						#if defined DEBUG
							printf("[Nex-AC debug] AC armour: %d, armour: %d", ACInfo[playerid][acArmour], ac_armour);
						#endif
						#if defined OnCheatDetected
							ac_KickWithCode(playerid, "", 0, 13);
							if(ACInfo[playerid][acKicked] > 0) return 0;
						#else
							return ac_KickWithCode(playerid, "", 0, 13);
						#endif
					#if AC_USE_AMMUNATIONS
						}
					#endif
				}
			}
			if(ac_health < ACInfo[playerid][acHealth] || ac_armour < ACInfo[playerid][acArmour])
			{
				ACInfo[playerid][acVehDmgRes] = false;
				ACInfo[playerid][acCheatCount][9] = ACInfo[playerid][acDmgRes] = 0;
			}
			else if(ACInfo[playerid][acACAllow][19] &&
			ACInfo[playerid][acDmgRes] && ac_gtc > ACInfo[playerid][acGtc][14] + ac_gpp)
			{
				ACInfo[playerid][acDmgRes] = 0;
				ACInfo[playerid][acVehDmgRes] = false;
				if(++ACInfo[playerid][acCheatCount][9] > AC_MAX_GODMODE_WARNINGS)
				{
					#undef AC_MAX_GODMODE_WARNINGS
					#if defined DEBUG
						printf("[Nex-AC debug] AC health: %d, health: %d, AC armour: %d, armour: %d",
						ACInfo[playerid][acHealth], ac_health, ACInfo[playerid][acArmour], ac_armour);
					#endif
					#if defined OnCheatDetected
						ac_KickWithCode(playerid, "", 0, 19);
						if(ACInfo[playerid][acKicked] > 0) return 0;
						ACInfo[playerid][acCheatCount][9] = 0;
					#else
						return ac_KickWithCode(playerid, "", 0, 19);
					#endif
				}
				#if defined OnCheatWarning
					else OnCheatWarning(playerid, "", 0, 19, 0, ACInfo[playerid][acCheatCount][9]);
				#endif
			}
			#if AC_USE_TUNING_GARAGES
			if(ACInfo[playerid][acSet][12] != -1)
			{
				if(ac_money < ACInfo[playerid][acMoney] &&
				ACInfo[playerid][acSet][12] <= ACInfo[playerid][acMoney] - ac_money) ACInfo[playerid][acSet][12] = -1;
				else if(ac_gtc > ACInfo[playerid][acGtc][17] + ac_gpp)
				{
					if(ACInfo[playerid][acACAllow][23])
					{
						if(++ACInfo[playerid][acCheatCount][12] > AC_MAX_NOP_WARNINGS)
						{
							#if defined DEBUG
								printf("[Nex-AC debug] Money: %d, old money: %d, component price: %d",
								ac_money, ACInfo[playerid][acMoney], ACInfo[playerid][acSet][12]);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 23, 3);
								if(ACInfo[playerid][acKicked] > 0) return 0;
								ACInfo[playerid][acSet][12] = -1;
							#else
								return ac_KickWithCode(playerid, "", 0, 23, 3);
							#endif
						}
						#if defined OnCheatWarning
							else OnCheatWarning(playerid, "", 0, 23, 3, ACInfo[playerid][acCheatCount][12]);
						#endif
					}
					else if(++ACInfo[playerid][acCheatCount][12] > AC_MAX_NOP_WARNINGS) ACInfo[playerid][acSet][12] = -1;
				}
			}
			#endif
			if(ACInfo[playerid][acSet][0] != -1 && ac_gtc > ACInfo[playerid][acGtc][0] + ac_gpp)
			{
				if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][2] && ac_i != ACInfo[playerid][acSet][0])
				{
					if(++ACInfo[playerid][acNOPCount][2] > AC_MAX_NOP_WARNINGS)
					{
						#if defined DEBUG
							printf(DEBUG_CODE_5, playerid, "SetPlayerInterior");
							printf("[Nex-AC debug] AC interior: %d, interiorid: %d", ACInfo[playerid][acSet][0], ac_i);
						#endif
						#if defined OnCheatDetected
							ac_KickWithCode(playerid, "", 0, 52, 5);
							if(ACInfo[playerid][acKicked] > 0) return 0;
							ACInfo[playerid][acSet][0] = -1;
						#else
							return ac_KickWithCode(playerid, "", 0, 52, 5);
						#endif
					}
					#if defined OnNOPWarning
						else OnNOPWarning(playerid, 5, ACInfo[playerid][acNOPCount][2]);
					#endif
				}
				else if(++ACInfo[playerid][acNOPCount][2] > AC_MAX_NOP_WARNINGS) ACInfo[playerid][acSet][0] = -1;
			}
			if(ACInfo[playerid][acSet][6] != -1 && ac_gtc > ACInfo[playerid][acGtc][12] + ac_gpp)
			{
				if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][8])
				{
					if(++ACInfo[playerid][acNOPCount][8] > AC_MAX_NOP_WARNINGS)
					{
						#if defined DEBUG
							printf(DEBUG_CODE_5, playerid, "TogglePlayerSpectating");
						#endif
						#if defined OnCheatDetected
							ac_KickWithCode(playerid, "", 0, 52, 6);
							if(ACInfo[playerid][acKicked] > 0) return 0;
							ACInfo[playerid][acSet][6] = -1;
						#else
							return ac_KickWithCode(playerid, "", 0, 52, 6);
						#endif
					}
					#if defined OnNOPWarning
						else OnNOPWarning(playerid, 6, ACInfo[playerid][acNOPCount][8]);
					#endif
				}
				else if(++ACInfo[playerid][acNOPCount][8] > AC_MAX_NOP_WARNINGS) ACInfo[playerid][acSet][6] = -1;
			}
			if(ACInfo[playerid][acSet][7] != -1 && ac_gtc > ACInfo[playerid][acGtc][13] + ac_gpp)
			{
				if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][9])
				{
					if(++ACInfo[playerid][acNOPCount][9] > AC_MAX_NOP_WARNINGS)
					{
						#if defined DEBUG
							printf(DEBUG_CODE_5, playerid, "SpawnPlayer");
							printf("[Nex-AC debug] acSet[7]: %d", ACInfo[playerid][acSet][7]);
						#endif
						#if defined OnCheatDetected
							ac_KickWithCode(playerid, "", 0, 52, 7);
							if(ACInfo[playerid][acKicked] > 0) return 0;
							ACInfo[playerid][acSet][7] = -1;
						#else
							return ac_KickWithCode(playerid, "", 0, 52, 7);
						#endif
					}
					#if defined OnNOPWarning
						else OnNOPWarning(playerid, 7, ACInfo[playerid][acNOPCount][9]);
					#endif
				}
				else if(++ACInfo[playerid][acNOPCount][9] > AC_MAX_NOP_WARNINGS) ACInfo[playerid][acSet][7] = -1;
			}
			new ac_vehid = GetPlayerVehicleID(playerid);
			if(ACInfo[playerid][acSet][11] != -1 && ac_vehid > 0 && ac_gtc > ACInfo[playerid][acGtc][8] + ac_gpp)
			{
				if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][11])
				{
					new Float:ac_vX, Float:ac_vY, Float:ac_vZ;
					GetVehicleVelocity(ac_vehid, ac_vX, ac_vY, ac_vZ);
					if(ac_GetSpeed(ac_vX, ac_vY, ac_vZ) <= 30)
					{
						#if defined DEBUG
							printf(DEBUG_CODE_5, playerid, "RemovePlayerFromVehicle");
							printf("[Nex-AC debug] Veh model: %d", GetVehicleModel(ac_vehid));
						#endif
						#if defined OnCheatDetected
							ac_KickWithCode(playerid, "", 0, 52, 8);
							if(ACInfo[playerid][acKicked] > 0) return 0;
							ACInfo[playerid][acSet][11] = -1;
						#else
							return ac_KickWithCode(playerid, "", 0, 52, 8);
						#endif
					}
				}
				else ACInfo[playerid][acSet][11] = -1;
			}
			ac_s = GetPlayerVehicleSeat(playerid);
			if(ACInfo[playerid][acSet][9] != -1)
			{
				if(ACInfo[playerid][acSet][9] == ac_vehid &&
				(ACInfo[playerid][acSet][5] == ac_s || ACInfo[playerid][acSet][5] == -1))
				{
					if(ACInfo[playerid][acVeh] > 0)
					{
						if(ac_IsAnAircraft(GetVehicleModel(ACInfo[playerid][acVeh]))) ACInfo[playerid][acParachute] = 2;
						if(ACVehInfo[ACInfo[playerid][acVeh]][acDriver] == playerid) ACVehInfo[ACInfo[playerid][acVeh]][acDriver] = INVALID_PLAYER_ID;
					}
					if(ac_s == 0)
					{
						ACVehInfo[ac_vehid][acDriver] = playerid;
						GetVehicleZAngle(ac_vehid, ACVehInfo[ac_vehid][acZAngle]);
						ACInfo[playerid][acSetVehHealth] = -1.0;
					}
					ACInfo[playerid][acEnterVeh] =
					ACInfo[playerid][acCheatCount][11] = 0;
					ACInfo[playerid][acVehDmgRes] = false;
					ACInfo[playerid][acSet][11] =
					ACInfo[playerid][acSet][9] =
					ACInfo[playerid][acSet][8] = -1;
					ACInfo[playerid][acSeat] = ac_s;
				}
				else if(GetVehicleModel(ACInfo[playerid][acSet][9]) < 400 ||
				!ACVehInfo[ACInfo[playerid][acSet][9]][acSpawned]) ACInfo[playerid][acSet][9] = -1;
				else if(ac_gtc > ACInfo[playerid][acGtc][1] + ac_gpp)
				{
					if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][7] && ACInfo[playerid][acSet][5] != -1)
					{
						if(++ACInfo[playerid][acNOPCount][7] > AC_MAX_NOP_WARNINGS)
						{
							#if defined DEBUG
								printf(DEBUG_CODE_5, playerid, "PutPlayerInVehicle");
								printf("[Nex-AC debug] AC veh: %d, veh: %d, AC seat: %d, seatid: %d",
								ACInfo[playerid][acSet][9], ac_vehid, ACInfo[playerid][acSet][5], ac_s);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 52, 9);
								if(ACInfo[playerid][acKicked] > 0) return 0;
								ACInfo[playerid][acSet][9] = -1;
							#else
								return ac_KickWithCode(playerid, "", 0, 52, 9);
							#endif
						}
						#if defined OnNOPWarning
							else OnNOPWarning(playerid, 9, ACInfo[playerid][acNOPCount][7]);
						#endif
					}
					else if(++ACInfo[playerid][acNOPCount][7] > AC_MAX_NOP_WARNINGS) ACInfo[playerid][acSet][9] = -1;
				}
			}
			else
			{
				new Float:ac_dist_set = 25000.0;
				if(ACInfo[playerid][acSet][8] != -1)
				{
					ac_dist_set = GetPlayerDistanceFromPoint(playerid, ACInfo[playerid][acSetPosX], ACInfo[playerid][acSetPosY], (ACInfo[playerid][acTpToZ] ? ac_Z : ACInfo[playerid][acSetPosZ]));
					if(floatcmp(ac_dist_set, 15.0) == -1)
					{
						ACInfo[playerid][acSet][8] = -1;
						ACInfo[playerid][acGtc][11] = 0;
						ACInfo[playerid][acTpToZ] = false;
						ACInfo[playerid][acPosX] = ac_X;
						ACInfo[playerid][acPosY] = ac_Y;
						ACInfo[playerid][acPosZ] = ac_Z;
					}
					else if(ac_gtc > ACInfo[playerid][acGtc][11] + ac_gpp)
					{
						if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][10])
						{
							if(++ACInfo[playerid][acNOPCount][10] > AC_MAX_NOP_WARNINGS)
							{
								#if defined DEBUG
									printf(DEBUG_CODE_5, playerid, "SetPlayerPos");
									printf("[Nex-AC debug] Dist: %f, acSet[8]: %d", ac_dist_set, ACInfo[playerid][acSet][8]);
								#endif
								#if defined OnCheatDetected
									ac_KickWithCode(playerid, "", 0, 52, 10);
									if(ACInfo[playerid][acKicked] > 0) return 0;
									ACInfo[playerid][acTpToZ] = false;
									ACInfo[playerid][acSet][8] = -1;
								#else
									return ac_KickWithCode(playerid, "", 0, 52, 10);
								#endif
							}
							#if defined OnNOPWarning
								else OnNOPWarning(playerid, 10, ACInfo[playerid][acNOPCount][10]);
							#endif
						}
						else if(++ACInfo[playerid][acNOPCount][10] > AC_MAX_NOP_WARNINGS)
						{
							ACInfo[playerid][acTpToZ] = false;
							ACInfo[playerid][acSet][8] = -1;
						}
					}
				}
				new Float:ac_vX, Float:ac_vY, Float:ac_vZ, ac_specact = GetPlayerSpecialAction(playerid),
				Float:ac_dist = GetPlayerDistanceFromPoint(playerid, ACInfo[playerid][acPosX], ACInfo[playerid][acPosY], ACInfo[playerid][acPosZ]);
				if(ac_vehid > 0)
				{
					if(ACInfo[playerid][acVeh] > 0)
					{
						if(ACInfo[playerid][acVeh] != ac_vehid)
						{
							if(ACInfo[playerid][acACAllow][4])
							{
								#if defined DEBUG
									printf("[Nex-AC debug] AC veh: %d, veh: %d", ACInfo[playerid][acVeh], ac_vehid);
								#endif
								#if defined OnCheatDetected
									ac_KickWithCode(playerid, "", 0, 4, 2);
									if(ACInfo[playerid][acKicked] > 0) return 0;
								#else
									return ac_KickWithCode(playerid, "", 0, 4, 2);
								#endif
							}
						}
						else if(ACInfo[playerid][acACAllow][50] && ACInfo[playerid][acSeat] != ac_s)
						{
							#if defined DEBUG
								printf("[Nex-AC debug] AC seat: %d, seatid: %d, veh: %d", ACInfo[playerid][acSeat], ac_s, ac_vehid);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 50);
								if(ACInfo[playerid][acKicked] > 0) return 0;
							#else
								return ac_KickWithCode(playerid, "", 0, 50);
							#endif
						}
					}
					if(ac_sa == PLAYER_STATE_DRIVER)
					{
						if(ACInfo[playerid][acACAllow][32] &&
						ACVehInfo[ac_vehid][acDriver] != INVALID_PLAYER_ID && ACVehInfo[ac_vehid][acDriver] != playerid)
						{
							#if defined DEBUG
								printf("[Nex-AC debug] AC driver: %d, driver: %d, veh: %d",
								ACVehInfo[ac_vehid][acDriver], playerid, ac_vehid);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 32);
								if(ACInfo[playerid][acKicked] > 0) return 0;
							#else
								return SetPlayerPos(playerid, ACInfo[playerid][acPosX], ACInfo[playerid][acPosY], ACInfo[playerid][acPosZ]);
							#endif
						}
						new Float:ac_vHealth;
						GetVehicleHealth(ac_vehid, ac_vHealth);
						if(floatcmp(ACInfo[playerid][acSetVehHealth], -1.0) != 0)
						{
							if(floatcmp(ACInfo[playerid][acSetVehHealth], ac_vHealth) == 0 ||
							floatcmp(ACInfo[playerid][acSetVehHealth], ac_vHealth) == 1 &&
							ac_gtc > ACInfo[playerid][acGtc][4] + ac_gpp)
							{
								ACInfo[playerid][acSetVehHealth] = -1.0;
								ACInfo[playerid][acVehDmgRes] = false;
							}
							else if(ac_gtc > ACInfo[playerid][acGtc][4] + ac_gpp)
							{
								if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][4])
								{
									if(++ACInfo[playerid][acNOPCount][4] > AC_MAX_NOP_WARNINGS)
									{
										#if defined DEBUG
											printf(DEBUG_CODE_5, playerid, "SetVehicleHealth");
											printf("[Nex-AC debug] AC veh health: %f, veh health: %f, veh: %d",
											ACInfo[playerid][acSetVehHealth], ac_vHealth, ac_vehid);
										#endif
										#if defined OnCheatDetected
											ac_KickWithCode(playerid, "", 0, 52, 11);
											if(ACInfo[playerid][acKicked] > 0) return 0;
											ACInfo[playerid][acSetVehHealth] = -1.0;
										#else
											return ac_KickWithCode(playerid, "", 0, 52, 11);
										#endif
									}
									#if defined OnNOPWarning
										else OnNOPWarning(playerid, 11, ACInfo[playerid][acNOPCount][4]);
									#endif
								}
								else if(++ACInfo[playerid][acNOPCount][4] > AC_MAX_NOP_WARNINGS) ACInfo[playerid][acSetVehHealth] = -1.0;
							}
						}
						else if(ACInfo[playerid][acACAllow][11] &&
						floatcmp(ac_vHealth, ACVehInfo[ac_vehid][acHealth]) == 1 &&
						!ACInfo[playerid][acModShop] && ac_vHealth)
						{
							#if AC_USE_PAYNSPRAY
								if(!ac_InPayNSpray(playerid, ac_i))
								{
							#endif
								#if defined DEBUG
									printf("[Nex-AC debug] AC veh health: %f, veh health: %f, veh: %d, playerid: %d",
									ACVehInfo[ac_vehid][acHealth], ac_vHealth, ac_vehid, playerid);
								#endif
								#if defined OnCheatDetected
									ac_KickWithCode(playerid, "", 0, 11);
									if(ACInfo[playerid][acKicked] > 0) return 0;
								#endif
								SetVehicleHealth(ac_vehid, ACVehInfo[ac_vehid][acHealth]);
							#if AC_USE_PAYNSPRAY
								}
							#endif
						}
						if(ACInfo[playerid][acVehDmgRes])
						{
							if(floatcmp(ac_vHealth, ACVehInfo[ac_vehid][acHealth]) == -1)
							{
								ACInfo[playerid][acVehDmgRes] = false;
								ACInfo[playerid][acCheatCount][11] = ACInfo[playerid][acDmgRes] = 0;
							}
							else if(ACInfo[playerid][acACAllow][20] && ac_gtc > ACInfo[playerid][acGtc][16] + ac_gpp)
							{
								ACInfo[playerid][acDmgRes] = 0;
								ACInfo[playerid][acVehDmgRes] = false;
								if(++ACInfo[playerid][acCheatCount][11] > AC_MAX_GODMODE_VEH_WARNINGS)
								{
									#undef AC_MAX_GODMODE_VEH_WARNINGS
									#if defined DEBUG
										printf("[Nex-AC debug] AC veh health: %f, veh health: %f, veh: %d",
										ACVehInfo[ac_vehid][acHealth], ac_vHealth, ac_vehid);
									#endif
									#if defined OnCheatDetected
										ac_KickWithCode(playerid, "", 0, 20);
										if(ACInfo[playerid][acKicked] > 0) return 0;
										ACInfo[playerid][acCheatCount][11] = 0;
									#else
										return ac_KickWithCode(playerid, "", 0, 20);
									#endif
								}
								#if defined OnCheatWarning
									else OnCheatWarning(playerid, "", 0, 20, 0, ACInfo[playerid][acCheatCount][11]);
								#endif
							}
						}
						GetVehicleVelocity(ac_vehid, ac_vX, ac_vY, ac_vZ);
						new Float:ac_zAngle, ac_vsp = ac_GetSpeed(ac_vX, ac_vY, ac_vZ);
						GetVehicleZAngle(ac_vehid, ac_zAngle);
						if(floatcmp(ac_dist, 0.8) == 1 && floatcmp(ac_dist_set, 0.8) == 1 &&
						ac_gtc > ACInfo[playerid][acGtc][11] + ac_gpp)
						{
							if(floatcmp(ac_dist, 80.0) >= 0 &&
							floatcmp(ac_dist, floatadd(ACVehInfo[ac_vehid][acPosDiff], floatmul(floatdiv(ac_dist, 2.6), 1.8))) == 1 &&
							floatcmp(ac_dist_set, 80.0) >= 0 &&
							floatcmp(ac_dist_set, floatadd(ACVehInfo[ac_vehid][acPosDiff], floatmul(floatdiv(ac_dist_set, 2.6), 1.8))) == 1)
							{
								if(ACInfo[playerid][acACAllow][3] && floatcmp(ACInfo[playerid][acPosZ], -95.0) == 1)
								{
									#if defined DEBUG
										printf("[Nex-AC debug] Dist: %f, dist set: %f, old pos diff: %f, speed: %d, veh: %d",
										ac_dist, ac_dist_set, ACVehInfo[ac_vehid][acPosDiff], ac_vsp, ac_vehid);
									#endif
									#if defined OnCheatDetected
										ac_KickWithCode(playerid, "", 0, 3, 2);
										if(ACInfo[playerid][acKicked] > 0) return 0;
									#else
										return ac_KickWithCode(playerid, "", 0, 3, 2);
									#endif
								}
							}
							else if(ACInfo[playerid][acACAllow][1] && ac_vsp < 12)
							{
								if(++ACInfo[playerid][acCheatCount][2] > AC_MAX_AIR_VEH_WARNINGS)
								{
									#undef AC_MAX_AIR_VEH_WARNINGS
									#if defined DEBUG
										printf("[Nex-AC debug] Speed: %d, dist: %f, dist set: %f, veh: %d",
										ac_vsp, ac_dist, ac_dist_set, ac_vehid);
									#endif
									#if defined OnCheatDetected
										ac_KickWithCode(playerid, "", 0, 1);
										if(ACInfo[playerid][acKicked] > 0) return 0;
										ACInfo[playerid][acCheatCount][2] = 0;
									#else
										return ac_KickWithCode(playerid, "", 0, 1);
									#endif
								}
								#if defined OnCheatWarning
									else OnCheatWarning(playerid, "", 0, 1, 0, ACInfo[playerid][acCheatCount][2]);
								#endif
							}
						}
						if(ac_gtc > ACInfo[playerid][acGtc][9] + ac_gpp)
						{
							ac_i = GetVehicleModel(ac_vehid);
							new ac_spDiff = ac_vsp - ac_GetSpeed(ACVehInfo[ac_vehid][acVelX], ACVehInfo[ac_vehid][acVelY], ACVehInfo[ac_vehid][acVelZ]);
							if(ACInfo[playerid][acACAllow][10])
							{
								if(ac_spDiff > 270)
								{
									#if defined DEBUG
										printf("[Nex-AC debug] Speed: %d, old speed: %d, veh model: %d",
										ac_vsp, ac_vsp - ac_spDiff, ac_i);
									#endif
									#if defined OnCheatDetected
										ac_KickWithCode(playerid, "", 0, 10, 3);
										if(ACInfo[playerid][acKicked] > 0) return 0;
									#else
										return ac_KickWithCode(playerid, "", 0, 10, 3);
									#endif
								}
								else if(ac_spDiff >= 20 &&
								ACVehInfo[ac_vehid][acSpeedDiff] <= ac_spDiff && floatcmp(ACVehInfo[ac_vehid][acHealth], ac_vHealth) <= 0 &&
								!((ac_i == 432 || ac_i == 449 || 537 <= ac_i <= 538) && ac_spDiff < 65 ||
								ac_IsABicycle(ac_i) && floatcmp(floatabs(ac_vX), 0.3) <= 0 && floatcmp(floatabs(ac_vY), 0.3) <= 0 && floatcmp(floatabs(ac_vZ), 0.3) <= 0 ||
								!(ac_IsABicycle(ac_i) || ac_i == 449 || 537 <= ac_i <= 538) && floatcmp(ACVehInfo[ac_vehid][acHealth], 250.0) == -1))
								{
									ACInfo[playerid][acCheatCount][16] += (1 * AC_SPEEDHACK_VEH_RESET_DELAY);
									if(ACInfo[playerid][acCheatCount][16] > AC_MAX_SPEEDHACK_VEH_WARNINGS)
									{
										#undef AC_MAX_SPEEDHACK_VEH_WARNINGS
										#undef AC_SPEEDHACK_VEH_RESET_DELAY
										#if defined DEBUG
											printf("[Nex-AC debug] Speed: %d, old speed: %d, veh model: %d",
											ac_vsp, ac_vsp - ac_spDiff, ac_i);
										#endif
										#if defined OnCheatDetected
											ac_KickWithCode(playerid, "", 0, 10, 1);
											if(ACInfo[playerid][acKicked] > 0) return 0;
											ACInfo[playerid][acCheatCount][16] = 0;
										#else
											return ac_KickWithCode(playerid, "", 0, 10, 1);
										#endif
									}
									#if defined OnCheatWarning
										else OnCheatWarning(playerid, "", 0, 10, 1, ACInfo[playerid][acCheatCount][16]);
									#endif
								}
							}
							if(ACInfo[playerid][acACAllow][25] &&
							ac_vsp > 15 && ac_abs(ac_spDiff) < 25 &&
							floatround(floatabs(floatsub(ac_zAngle, ACVehInfo[ac_vehid][acZAngle]))) == 180 &&
							(floatcmp(ac_vX, 0.0) == -1) != (floatcmp(ACVehInfo[ac_vehid][acVelX], 0.0) == -1) &&
							(floatcmp(ac_vY, 0.0) == -1) != (floatcmp(ACVehInfo[ac_vehid][acVelY], 0.0) == -1) &&
							(floatcmp(ac_vZ, 0.0) == -1) != (floatcmp(ACVehInfo[ac_vehid][acVelZ], 0.0) == -1))
							{
								#undef ac_abs
								#if defined DEBUG
									printf("[Nex-AC debug] Speed: %d, speed diff: %d, z angle: %f, old z angle: %f, veh: %d",
									ac_vsp, ac_spDiff, ac_zAngle, ACVehInfo[ac_vehid][acZAngle], ac_vehid);
								#endif
								#if defined OnCheatDetected
									ac_KickWithCode(playerid, "", 0, 25);
									if(ACInfo[playerid][acKicked] > 0) return 0;
								#else
									return ac_KickWithCode(playerid, "", 0, 25);
								#endif
							}
							if(ac_IsAnAircraft(ac_i))
							{
								if(ACInfo[playerid][acACAllow][10] && (ac_vsp = ac_GetSpeed(ac_vX, ac_vY)) > 270)
								{
									#if defined DEBUG
										printf("[Nex-AC debug] Speed (x, y): %d, veh model: %d", ac_vsp, ac_i);
									#endif
									#if defined OnCheatDetected
										ac_KickWithCode(playerid, "", 0, 10, 2);
										if(ACInfo[playerid][acKicked] > 0) return 0;
									#else
										return ac_KickWithCode(playerid, "", 0, 10, 2);
									#endif
								}
							}
							else if(ACInfo[playerid][acACAllow][8])
							{
								new Float:ac_zDiff = floatsub(ac_Z, ACInfo[playerid][acPosZ]);
								if(floatcmp(ac_vZ, 0.1) >= 0 && floatcmp(ac_vZ, ACVehInfo[ac_vehid][acVelZ]) == 1 &&
								floatcmp(floatabs(floatsub(ACInfo[playerid][acPosX], ac_X)), floatdiv(ac_zDiff, 2.0)) == -1 &&
								floatcmp(floatabs(floatsub(ACInfo[playerid][acPosY], ac_Y)), floatdiv(ac_zDiff, 2.0)) == -1)
								{
									if(++ACInfo[playerid][acCheatCount][3] > (ac_IsABicycle(ac_i) ? AC_MAX_FLYHACK_BIKE_WARNINGS : AC_MAX_FLYHACK_VEH_WARNINGS))
									{
										#undef AC_MAX_FLYHACK_BIKE_WARNINGS
										#if defined DEBUG
											printf("[Nex-AC debug] Vel z: %f, old vel z: %f, pos diff x, y, z: %f, %f, %f, veh: %d",
											ac_vZ, ACVehInfo[ac_vehid][acVelZ], floatsub(ACInfo[playerid][acPosX], ac_X), floatsub(ACInfo[playerid][acPosY], ac_Y), ac_zDiff, ac_vehid);
										#endif
										#if defined OnCheatDetected
											ac_KickWithCode(playerid, "", 0, 8, 1);
											if(ACInfo[playerid][acKicked] > 0) return 0;
											ACInfo[playerid][acCheatCount][3] = 0;
										#else
											return ac_KickWithCode(playerid, "", 0, 8, 1);
										#endif
									}
									#if defined OnCheatWarning
										else OnCheatWarning(playerid, "", 0, 8, 1, ACInfo[playerid][acCheatCount][3]);
									#endif
								}
								else ACInfo[playerid][acCheatCount][3] = 0;
							}
							ACVehInfo[ac_vehid][acSpeedDiff] = ac_spDiff;
						}
						ACVehInfo[ac_vehid][acPosX] = ac_X;
						ACVehInfo[ac_vehid][acPosY] = ac_Y;
						ACVehInfo[ac_vehid][acPosZ] = ac_Z;
						ACVehInfo[ac_vehid][acVelX] = ac_vX;
						ACVehInfo[ac_vehid][acVelY] = ac_vY;
						ACVehInfo[ac_vehid][acVelZ] = ac_vZ;
						ACVehInfo[ac_vehid][acPosDiff] = ac_dist;
						if(floatcmp(ACInfo[playerid][acSetVehHealth], -1.0) == 0) ACVehInfo[ac_vehid][acHealth] = ac_vHealth;
						ACVehInfo[ac_vehid][acZAngle] = ac_zAngle;
					}
					ACInfo[playerid][acSeat] = ac_s;
				}
				else
				{
					GetPlayerVelocity(playerid, ac_vX, ac_vY, ac_vZ);
					ac_s = ac_GetSpeed(ac_vX, ac_vY, ac_vZ);
					if(ACInfo[playerid][acAnim] != (ac_sa = GetPlayerAnimationIndex(playerid)))
					{
						if(ac_sa == -1)
						{
							if(ACInfo[playerid][acACAllow][24])
							{
								#if defined OnCheatDetected
									ac_KickWithCode(playerid, "", 0, 24);
									if(ACInfo[playerid][acKicked] > 0) return 0;
								#else
									return ac_KickWithCode(playerid, "", 0, 24);
								#endif
							}
						}
						else if(ACInfo[playerid][acACAllow][30] && !ac_PedAnims)
						{
							ac_i = GetPlayerSkin(playerid);
							if(ac_sa == 1231 && ac_w != 46 && 1 <= ac_i <= 311 && ac_i != 74)
							{
								if(++ACInfo[playerid][acCheatCount][19] > AC_MAX_CJ_RUN_WARNINGS)
								{
									#undef AC_MAX_CJ_RUN_WARNINGS
									#if defined DEBUG
										printf("[Nex-AC debug] Skin: %d, old anim: %d, weaponid: %d",
										ac_i, ACInfo[playerid][acAnim], ac_w);
									#endif
									#if defined OnCheatDetected
										ac_KickWithCode(playerid, "", 0, 30);
										if(ACInfo[playerid][acKicked] > 0) return 0;
										ACInfo[playerid][acCheatCount][19] = 0;
									#else
										return ac_KickWithCode(playerid, "", 0, 30);
									#endif
								}
								#if defined OnCheatWarning
									else OnCheatWarning(playerid, "", 0, 30, 0, ACInfo[playerid][acCheatCount][19]);
								#endif
							}
							else ACInfo[playerid][acCheatCount][19] = 0;
						}
					}
					else if(ACInfo[playerid][acACAllow][7])
					{
						if(ac_sa == 157 || ac_sa == 159 || ac_sa == 161 || ac_sa == 1058)
						{
							if(++ACInfo[playerid][acCheatCount][15] > AC_MAX_FLYHACK_WARNINGS)
							{
								#if defined DEBUG
									printf("[Nex-AC debug] Anim: %d, old anim: %d, old veh: %d",
									ac_sa, ACInfo[playerid][acAnim], ACInfo[playerid][acVeh]);
								#endif
								#if defined OnCheatDetected
									ac_KickWithCode(playerid, "", 0, 7, 2);
									if(ACInfo[playerid][acKicked] > 0) return 0;
									ACInfo[playerid][acCheatCount][15] = 0;
								#else
									return ac_KickWithCode(playerid, "", 0, 7, 2);
								#endif
							}
							#if defined OnCheatWarning
								else OnCheatWarning(playerid, "", 0, 7, 2, ACInfo[playerid][acCheatCount][15]);
							#endif
						}
						else if(1538 <= ac_sa <= 1544 && ac_s > 36 && ACInfo[playerid][acSpeed] < ac_s)
						{
							if(++ACInfo[playerid][acCheatCount][15] > AC_MAX_FLYHACK_WARNINGS)
							{
								#if defined DEBUG
									printf("[Nex-AC debug] Speed: %d, old speed: %d, anim: %d",
									ac_s, ACInfo[playerid][acSpeed], ac_sa);
								#endif
								#if defined OnCheatDetected
									ac_KickWithCode(playerid, "", 0, 7, 3);
									if(ACInfo[playerid][acKicked] > 0) return 0;
									ACInfo[playerid][acCheatCount][15] = 0;
								#else
									return ac_KickWithCode(playerid, "", 0, 7, 3);
								#endif
							}
							#if defined OnCheatWarning
								else OnCheatWarning(playerid, "", 0, 7, 3, ACInfo[playerid][acCheatCount][15]);
							#endif
						}
						else if(958 <= ac_sa <= 979 &&
						(floatcmp(ac_vZ, 0.08) == 1 || floatcmp(floatadd(floatmul(ac_vX, ac_vX), floatmul(ac_vY, ac_vY)), 0.9) == 1))
						{
							if(++ACInfo[playerid][acCheatCount][15] > AC_MAX_FLYHACK_WARNINGS)
							{
								#undef AC_MAX_FLYHACK_WARNINGS
								#if defined DEBUG
									printf("[Nex-AC debug] Anim: %d, old anim: %d, weaponid: %d, spec act: %d",
									ac_sa, ACInfo[playerid][acAnim], ac_w, ac_specact);
								#endif
								#if defined OnCheatDetected
									ac_KickWithCode(playerid, "", 0, 7, 1);
									if(ACInfo[playerid][acKicked] > 0) return 0;
									ACInfo[playerid][acCheatCount][15] = 0;
								#else
									return ac_KickWithCode(playerid, "", 0, 7, 1);
								#endif
							}
							#if defined OnCheatWarning
								else OnCheatWarning(playerid, "", 0, 7, 1, ACInfo[playerid][acCheatCount][15]);
							#endif
						}
						else ACInfo[playerid][acCheatCount][15] = 0;
					}
					if(ACInfo[playerid][acSet][4] != -1)
					{
						if(ac_specact == ACInfo[playerid][acSet][4]) ACInfo[playerid][acSet][4] = -1;
						else if(ac_gtc > ACInfo[playerid][acGtc][6] + ac_gpp)
						{
							if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][6] &&
							ac_specact != SPECIAL_ACTION_DUCK &&
							!(SPECIAL_ACTION_ENTER_VEHICLE <= ac_specact <= SPECIAL_ACTION_EXIT_VEHICLE))
							{
								if(++ACInfo[playerid][acNOPCount][6] > AC_MAX_NOP_WARNINGS)
								{
									#if defined DEBUG
										printf(DEBUG_CODE_5, playerid, "SetPlayerSpecialAction");
										printf("[Nex-AC debug] AC spec act: %d, spec act: %d", ACInfo[playerid][acSet][4], ac_specact);
									#endif
									#if defined OnCheatDetected
										ac_KickWithCode(playerid, "", 0, 52, 12);
										if(ACInfo[playerid][acKicked] > 0) return 0;
										ACInfo[playerid][acSet][4] = -1;
									#else
										return ac_KickWithCode(playerid, "", 0, 52, 12);
									#endif
								}
								#if defined OnNOPWarning
									else OnNOPWarning(playerid, 12, ACInfo[playerid][acNOPCount][6]);
								#endif
							}
							else if(++ACInfo[playerid][acNOPCount][6] > AC_MAX_NOP_WARNINGS) ACInfo[playerid][acSet][4] = -1;
							#undef AC_MAX_NOP_WARNINGS
						}
					}
					else if(ac_specact != ACInfo[playerid][acSpecAct])
					{
						if(ac_specact == ACInfo[playerid][acNextSpecAct]) ACInfo[playerid][acNextSpecAct] = -1;
						else if(ACInfo[playerid][acACAllow][18])
						{
							switch(ac_specact)
							{
								case SPECIAL_ACTION_NONE:
								{
									switch(ACInfo[playerid][acSpecAct])
									{
										case SPECIAL_ACTION_USECELLPHONE, SPECIAL_ACTION_CUFFED, SPECIAL_ACTION_CARRY:
										{
											#if defined OnCheatDetected
												ac_KickWithCode(playerid, "", 0, 18, 1);
												if(ACInfo[playerid][acKicked] > 0) return 0;
											#else
												return ac_KickWithCode(playerid, "", 0, 18, 1);
											#endif
										}
									}
								}
								case SPECIAL_ACTION_DUCK:
								{
									if(ACInfo[playerid][acSpecAct] > SPECIAL_ACTION_NONE &&
									!(SPECIAL_ACTION_DRINK_BEER <= ACInfo[playerid][acSpecAct] <= SPECIAL_ACTION_CUFFED))
									{
										#if defined DEBUG
											printf("[Nex-AC debug] AC spec act: %d, spec act: %d", ACInfo[playerid][acSpecAct], ac_specact);
										#endif
										#if defined OnCheatDetected
											ac_KickWithCode(playerid, "", 0, 18, 2);
											if(ACInfo[playerid][acKicked] > 0) return 0;
										#else
											return ac_KickWithCode(playerid, "", 0, 18, 2);
										#endif
									}
								}
								case SPECIAL_ACTION_USEJETPACK:
								{
									if(floatcmp((ac_tmp = GetPlayerDistanceFromPoint(playerid, ACInfo[playerid][acDropJpX], ACInfo[playerid][acDropJpY], ACInfo[playerid][acDropJpZ])), 15.0) == 1)
									{
										#if defined DEBUG
											printf("[Nex-AC debug] AC spec act: %d, spec act: %d, dist: %f",
											ACInfo[playerid][acSpecAct], ac_specact, ac_tmp);
										#endif
										#if defined OnCheatDetected
											ac_KickWithCode(playerid, "", 0, 18, 3);
											if(ACInfo[playerid][acKicked] > 0) return 0;
										#else
											return ac_KickWithCode(playerid, "", 0, 18, 3);
										#endif
									}
									else ACInfo[playerid][acNextSpecAct] = ACInfo[playerid][acSpecAct];
									ACInfo[playerid][acDropJpX] = ACInfo[playerid][acDropJpY] = ACInfo[playerid][acDropJpZ] = 25000.0;
								}
								case SPECIAL_ACTION_ENTER_VEHICLE:
								{
									switch(ACInfo[playerid][acSpecAct])
									{
										case SPECIAL_ACTION_DANCE1, SPECIAL_ACTION_DANCE2, SPECIAL_ACTION_DANCE3, SPECIAL_ACTION_DANCE4, SPECIAL_ACTION_USECELLPHONE, 68:
										{
											#if defined OnCheatDetected
												ac_KickWithCode(playerid, "", 0, 18, 4);
												if(ACInfo[playerid][acKicked] > 0) return 0;
											#else
												return ac_KickWithCode(playerid, "", 0, 18, 4);
											#endif
										}
									}
								}
								default:
								{
									if(!((SPECIAL_ACTION_DRINK_BEER <= ac_specact <= SPECIAL_ACTION_CUFFED &&
									ACInfo[playerid][acSpecAct] == SPECIAL_ACTION_DUCK ||
									ACInfo[playerid][acSpecAct] == SPECIAL_ACTION_ENTER_VEHICLE) &&
									ac_specact == ACInfo[playerid][acLastSpecAct]) &&
									(ACInfo[playerid][acVeh] == 0 || ac_specact != SPECIAL_ACTION_EXIT_VEHICLE &&
									!(SPECIAL_ACTION_CUFFED <= ac_specact <= SPECIAL_ACTION_CARRY) &&
									ac_specact != SPECIAL_ACTION_USECELLPHONE))
									{
										#if defined DEBUG
											printf("[Nex-AC debug] AC spec act: %d, spec act: %d, Last spec act: %d, old veh: %d",
											ACInfo[playerid][acSpecAct], ac_specact, ACInfo[playerid][acLastSpecAct], ACInfo[playerid][acVeh]);
										#endif
										#if defined OnCheatDetected
											ac_KickWithCode(playerid, "", 0, 18, 5);
											if(ACInfo[playerid][acKicked] > 0) return 0;
										#else
											return ac_KickWithCode(playerid, "", 0, 18, 5);
										#endif
									}
								}
							}
						}
						ACInfo[playerid][acLastSpecAct] = ACInfo[playerid][acSpecAct];
					}
					if(!IsVehicleStreamedIn(GetPlayerSurfingVehicleID(playerid), playerid) &&
					GetPlayerSurfingObjectID(playerid) == INVALID_OBJECT_ID)
					{
						if(floatcmp(ac_dist, 0.7) == 1 && floatcmp(ac_dist_set, 0.7) == 1)
						{
							if(floatcmp(ac_dist, 40.0) >= 0 && floatcmp(ac_dist_set, 40.0) >= 0)
							{
								if(ACInfo[playerid][acACAllow][2] &&
								!ACInfo[playerid][acIntEnterExits] && floatcmp(ACInfo[playerid][acPosZ], -95.0) == 1)
								{
									#if defined DEBUG
										printf("[Nex-AC debug] Dist: %f, dist set: %f, speed: %d, pos x, y, z: %f, %f, %f",
										ac_dist, ac_dist_set, ac_s, ACInfo[playerid][acPosX], ACInfo[playerid][acPosY], ACInfo[playerid][acPosZ]);
									#endif
									#if defined OnCheatDetected
										ac_KickWithCode(playerid, "", 0, 2, 2);
										if(ACInfo[playerid][acKicked] > 0) return 0;
									#else
										return ac_KickWithCode(playerid, "", 0, 2, 2);
									#endif
								}
							}
							else if(floatcmp(ac_s, floatmul(ac_dist, (floatcmp(ac_dist, 1.0) == -1 ? 14.0 : 5.0))) <= 0 &&
							floatcmp(ac_s, floatmul(ac_dist_set, (floatcmp(ac_dist_set, 1.0) == -1 ? 14.0 : 5.0))) <= 0 &&
							ac_gtc > ACInfo[playerid][acGtc][11] + ac_gpp)
							{
								if(ac_s < 3 && floatcmp(ac_dist, 15.0) >= 0 && floatcmp(ac_dist_set, 15.0) >= 0)
								{
									if(ACInfo[playerid][acACAllow][2])
									{
										#if defined DEBUG
											printf("[Nex-AC debug] Speed: %d, dist: %f, dist set: %f", ac_s, ac_dist, ac_dist_set);
										#endif
										#if defined OnCheatDetected
											ac_KickWithCode(playerid, "", 0, 2, 3);
											if(ACInfo[playerid][acKicked] > 0) return 0;
										#else
											return ac_KickWithCode(playerid, "", 0, 2, 3);
										#endif
									}
								}
								else if(ACInfo[playerid][acACAllow][0] &&
								(ac_s || floatcmp(ac_dist, 3.0) >= 0 && floatcmp(ac_dist_set, 3.0) >= 0))
								{
									if(++ACInfo[playerid][acCheatCount][1] > AC_MAX_AIR_WARNINGS)
									{
										#undef AC_MAX_AIR_WARNINGS
										#if defined DEBUG
											printf("[Nex-AC debug] Speed: %d, dist: %f, dist set: %f", ac_s, ac_dist, ac_dist_set);
										#endif
										#if defined OnCheatDetected
											ac_KickWithCode(playerid, "", 0, 0);
											if(ACInfo[playerid][acKicked] > 0) return 0;
											ACInfo[playerid][acCheatCount][1] = 0;
										#else
											return ac_KickWithCode(playerid, "", 0, 0);
										#endif
									}
									#if defined OnCheatWarning
										else OnCheatWarning(playerid, "", 0, 0, 0, ACInfo[playerid][acCheatCount][1]);
									#endif
								}
							}
						}
						if(ac_gtc > ACInfo[playerid][acGtc][10] + ac_gpp)
						{
							if(ACInfo[playerid][acACAllow][9] && ACInfo[playerid][acSpeed] < ac_s)
							{
								if(ac_s > 530)
								{
									#if defined DEBUG
										printf("[Nex-AC debug] Speed: %d, old speed: %d", ac_s, ACInfo[playerid][acSpeed]);
									#endif
									#if defined OnCheatDetected
										ac_KickWithCode(playerid, "", 0, 9, 1);
										if(ACInfo[playerid][acKicked] > 0) return 0;
									#else
										return ac_KickWithCode(playerid, "", 0, 9, 1);
									#endif
								}
								else if((ac_s > 257 || (ac_i = ac_GetSpeed(ac_vX, ac_vY)) > 128) &&
								ACInfo[playerid][acHealth] <= ac_health)
								{
									if(++ACInfo[playerid][acCheatCount][17] > AC_MAX_SPEEDHACK_WARNINGS)
									{
										#undef AC_MAX_SPEEDHACK_WARNINGS
										#if defined DEBUG
											printf("[Nex-AC debug] Speed: %d, speed x, y: %d, old speed: %d",
											ac_s, ac_i, ACInfo[playerid][acSpeed]);
										#endif
										#if defined OnCheatDetected
											ac_KickWithCode(playerid, "", 0, 9, 2);
											if(ACInfo[playerid][acKicked] > 0) return 0;
											ACInfo[playerid][acCheatCount][17] = 0;
										#else
											return ac_KickWithCode(playerid, "", 0, 9, 2);
										#endif
									}
									#if defined OnCheatWarning
										else OnCheatWarning(playerid, "", 0, 9, 2, ACInfo[playerid][acCheatCount][17]);
									#endif
								}
								else ACInfo[playerid][acCheatCount][17] = 0;
							}
							ACInfo[playerid][acSpeed] = ac_s;
						}
					}
					else ACInfo[playerid][acSpeed] = ac_s;
					ACInfo[playerid][acAnim] = ac_sa;
				}
				ACInfo[playerid][acSpecAct] = ac_specact;
				ACInfo[playerid][acHealth] = ac_health;
				ACInfo[playerid][acArmour] = ac_armour;
			}
			ACInfo[playerid][acVeh] = ac_vehid;
			if(ac_gtc > ACInfo[playerid][acGtc][7] + ac_gpp) ACInfo[playerid][acLastWeapon] = ac_w;
			ACInfo[playerid][acPosX] = ac_X;
			ACInfo[playerid][acPosY] = ac_Y;
			ACInfo[playerid][acPosZ] = ac_Z;
		}
	}
	ac_gpp = 1;
	ACInfo[playerid][acUpdateTime] = ac_gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerUpdate
		ac_gpp = ac_OnPlayerUpdate(playerid);
	#endif
	if(ACInfo[playerid][acACAllow][33] && ac_gpp) return ACInfo[playerid][acUnFrozen];
	return ac_gpp;
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerUpdate
		#undef OnPlayerUpdate
	#else
		#define _ALS_OnPlayerUpdate
	#endif
	#define OnPlayerUpdate ac_OnPlayerUpdate
	#if defined ac_OnPlayerUpdate
		forward ac_OnPlayerUpdate(playerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#else
	public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#endif
{
	if(!(0 <= playerid < MAX_PLAYERS) || ACInfo[playerid][acKicked] > 0) return 0;
	if(!IsPlayerNPC(playerid))
	{
		if((newkeys & KEY_SECONDARY_ATTACK) && ACInfo[playerid][acSpecAct] == SPECIAL_ACTION_USEJETPACK &&
		GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_USEJETPACK)
		{
			ACInfo[playerid][acDropJpX] = ACInfo[playerid][acPosX];
			ACInfo[playerid][acDropJpY] = ACInfo[playerid][acPosY];
			ACInfo[playerid][acDropJpZ] = ACInfo[playerid][acPosZ];
		}
		new ac_w = GetPlayerWeapon(playerid);
		if((newkeys & KEY_CROUCH) && (24 <= ac_w <= 25 || 33 <= ac_w <= 34)) ACInfo[playerid][acCheatCount][14] = 0;
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerKeyStateChange
		return ac_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerKeyStateChange
		#undef OnPlayerKeyStateChange
	#else
		#define _ALS_OnPlayerKeyStateChange
	#endif
	#define OnPlayerKeyStateChange ac_OnPlayerKeyStateChange
	#if defined ac_OnPlayerKeyStateChange
		forward ac_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
#else
	public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][2] + ac_Mtfc[2][0]) ac_FloodDetect(playerid, 2);
		else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][2] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][2] = ac_gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerClickMap
		return ac_OnPlayerClickMap(playerid, fX, fY, fZ);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerClickMap
		#undef OnPlayerClickMap
	#else
		#define _ALS_OnPlayerClickMap
	#endif
	#define OnPlayerClickMap ac_OnPlayerClickMap
	#if defined ac_OnPlayerClickMap
		forward ac_OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerClickPlayer(playerid, clickedplayerid, source)
#else
	public OnPlayerClickPlayer(playerid, clickedplayerid, source)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][3] + ac_Mtfc[3][0])
		{
			ac_FloodDetect(playerid, 3);
			return 1;
		}
		if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][3] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][3] = ac_gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerClickPlayer
		return ac_OnPlayerClickPlayer(playerid, clickedplayerid, source);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerClickPlayer
		#undef OnPlayerClickPlayer
	#else
		#define _ALS_OnPlayerClickPlayer
	#endif
	#define OnPlayerClickPlayer ac_OnPlayerClickPlayer
	#if defined ac_OnPlayerClickPlayer
		forward ac_OnPlayerClickPlayer(playerid, clickedplayerid, source);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerClickTextDraw(playerid, Text:clickedid)
#else
	public OnPlayerClickTextDraw(playerid, Text:clickedid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][4] + ac_Mtfc[4][0])
		{
			ac_FloodDetect(playerid, 4);
			return 1;
		}
		if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][4] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][4] = ac_gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerClickTextDraw
		return ac_OnPlayerClickTextDraw(playerid, clickedid);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerClickTextDraw
		#undef OnPlayerClickTextDraw
	#else
		#define _ALS_OnPlayerClickTextDraw
	#endif
	#define OnPlayerClickTextDraw ac_OnPlayerClickTextDraw
	#if defined ac_OnPlayerClickTextDraw
		forward ac_OnPlayerClickTextDraw(playerid, Text:clickedid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerCommandText(playerid, cmdtext[])
#else
	public OnPlayerCommandText(playerid, cmdtext[])
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	if(!IsPlayerNPC(playerid))
	{
		new ac_gtc = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_gtc < ACInfo[playerid][acCall][5] + ac_Mtfc[5][0])
			{
				ac_FloodDetect(playerid, 5);
				return 1;
			}
			if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][5] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][5] = ac_gtc;
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerCommandText
		return ac_OnPlayerCommandText(playerid, cmdtext);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerCommandText
		#undef OnPlayerCommandText
	#else
		#define _ALS_OnPlayerCommandText
	#endif
	#define OnPlayerCommandText ac_OnPlayerCommandText
	#if defined ac_OnPlayerCommandText
		forward ac_OnPlayerCommandText(playerid, cmdtext[]);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
#else
	public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
#endif
{
	if(!(0 <= playerid < MAX_PLAYERS) || ACInfo[playerid][acKicked] > 0) return 0;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][6] + ac_Mtfc[6][0]) ac_FloodDetect(playerid, 6);
		if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][6] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][6] = ac_gtc;
	new ac_model = GetVehicleModel(vehicleid);
	if(ACInfo[playerid][acACAllow][44] && !(569 <= ac_model <= 570) && !IsVehicleStreamedIn(vehicleid, playerid))
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Veh: %d, veh model: %d, ispassenger: %d", vehicleid, ac_model, ispassenger);
		#endif
		return ac_KickWithCode(playerid, "", 0, 44, 1);
	}
	new ac_doors, ac_tmp;
	GetVehicleParamsEx(vehicleid, ac_tmp, ac_tmp, ac_tmp, ac_doors, ac_tmp, ac_tmp, ac_tmp);
	if(ispassenger || ac_doors != VEHICLE_PARAMS_ON)
	{
		if(ACInfo[playerid][acEnterVeh] != vehicleid)
		{
			ACInfo[playerid][acEnterVeh] = vehicleid;
			if(ac_model == 570 || ac_IsABoat(ac_model)) ACInfo[playerid][acEnterVehTime] = 0;
			else ACInfo[playerid][acEnterVehTime] = ac_gtc;
		}
	}
	else ACInfo[playerid][acEnterVeh] = 0;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerEnterVehicle
		return ac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerEnterVehicle
		#undef OnPlayerEnterVehicle
	#else
		#define _ALS_OnPlayerEnterVehicle
	#endif
	#define OnPlayerEnterVehicle ac_OnPlayerEnterVehicle
	#if defined ac_OnPlayerEnterVehicle
		forward ac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerExitVehicle(playerid, vehicleid)
#else
	public OnPlayerExitVehicle(playerid, vehicleid)
#endif
{
	if(!(0 <= playerid < MAX_PLAYERS) || ACInfo[playerid][acKicked] > 0) return 0;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][7] + ac_Mtfc[7][0]) ac_FloodDetect(playerid, 7);
		if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][7] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][7] = ac_gtc;
	if(ACInfo[playerid][acACAllow][44] && !IsVehicleStreamedIn(vehicleid, playerid))
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Veh: %d, veh model: %d", vehicleid, GetVehicleModel(vehicleid));
		#endif
		return ac_KickWithCode(playerid, "", 0, 44, 5);
	}
	if(ac_IsAnAircraft(GetVehicleModel(ACInfo[playerid][acVeh]))) ACInfo[playerid][acParachute] = 1;
	else if(ACInfo[playerid][acParachute] != 2) ACInfo[playerid][acParachute] = 0;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerExitVehicle
		return ac_OnPlayerExitVehicle(playerid, vehicleid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerExitVehicle
		#undef OnPlayerExitVehicle
	#else
		#define _ALS_OnPlayerExitVehicle
	#endif
	#define OnPlayerExitVehicle ac_OnPlayerExitVehicle
	#if defined ac_OnPlayerExitVehicle
		forward ac_OnPlayerExitVehicle(playerid, vehicleid);
	#endif
#endif

#if defined OnPlayerPickUpDynamicPickup\
	&& defined Streamer_GetDistanceToItem\
	&& defined Streamer_GetIntData
	#if defined _inc_y_hooks || defined _INC_y_hooks
		#if defined STREAMER_ENABLE_TAGS
			hook OnPlayerPickUpDynPickup(playerid, STREAMER_TAG_PICKUP pickupid)
		#else
			hook OnPlayerPickUpDynPickup(playerid, pickupid)
		#endif
	#else
		#if defined STREAMER_ENABLE_TAGS
			public OnPlayerPickUpDynamicPickup(playerid, STREAMER_TAG_PICKUP pickupid)
		#else
			public OnPlayerPickUpDynamicPickup(playerid, pickupid)
		#endif
	#endif
	{
		if(!(0 <= playerid < MAX_PLAYERS) || ACInfo[playerid][acKicked] > 0) return 0;
		new ac_i = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_i < ACInfo[playerid][acCall][8] + ac_Mtfc[8][0]) ac_FloodDetect(playerid, 8);
			else if(ac_i < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][8] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		if(ACInfo[playerid][acACAllow][6])
		{
			new Float:ac_X, Float:ac_Y, Float:ac_Z, Float:ac_dist, Float:ac_dist_set;
			GetPlayerPos(playerid, ac_X, ac_Y, ac_Z);
			Streamer_GetDistanceToItem(ac_X, ac_Y, ac_Z, STREAMER_TYPE_PICKUP, pickupid, ac_dist);
			Streamer_GetDistanceToItem(ACInfo[playerid][acSetPosX], ACInfo[playerid][acSetPosY], (ACInfo[playerid][acTpToZ] ? ac_Z : ACInfo[playerid][acSetPosZ]), STREAMER_TYPE_PICKUP, pickupid, ac_dist_set);
			if(floatcmp(ac_dist, 15.0) == 1 && (ACInfo[playerid][acSet][8] == -1 || floatcmp(ac_dist_set, 15.0) == 1))
			{
				#if defined DEBUG
					printf("[Nex-AC debug] Pickupid: %d, dist: %f, dist set: %f, acSet[8]: %d, playerid: %d",
					_:pickupid, ac_dist, ac_dist_set, ACInfo[playerid][acSet][8], playerid);
				#endif
				#if defined OnCheatDetected
					ac_KickWithCode(playerid, "", 0, 6, 2);
				#endif
				return 0;
			}
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][8] = ac_i;
		#if AC_USE_PICKUP_WEAPONS
			switch((ac_i = Streamer_GetIntData(STREAMER_TYPE_PICKUP, pickupid, E_STREAMER_EXTRA_ID)))
			{
				case 2: ACInfo[playerid][acSpecAct] = SPECIAL_ACTION_USEJETPACK;
				case 3: ACInfo[playerid][acHealth] = 100;
				case 4: ACInfo[playerid][acArmour] = 100;
				default:
				{
					if(ac_i > 100)
					{
						ac_i -= 100;
						new ac_s = ac_wSlot[ac_i];
						if(ACInfo[playerid][acWeapon][ac_s] == ac_i ||
						3 <= ac_s <= 5 && ACInfo[playerid][acWeapon][ac_s] > 0) ACInfo[playerid][acAmmo][ac_s] += ac_pAmmo[ac_i];
					}
				}
			}
		#endif
		ACInfo[playerid][acLastPickup] = _:pickupid + MAX_PICKUPS;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnPlayerPickUpDynamicPickup
			return ac_OnPlayerPickUpDynamicPickup(playerid, pickupid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnPlayerPickUpDynamicPicku\
			|| defined _ALS_OnPlayerPickUpDynPickup\
			|| defined _ALS_OnPlayerPickUpDynamicPick || defined _ALS_OnPlayerPickUpDynamicPUp
			#undef OnPlayerPickUpDynamicPickup
		#else
			#define _ALS_OnPlayerPickUpDynPickup
		#endif
		#define OnPlayerPickUpDynamicPickup ac_OnPlayerPickUpDynamicPickup
		#if defined ac_OnPlayerPickUpDynamicPickup
			#if defined STREAMER_ENABLE_TAGS
				forward ac_OnPlayerPickUpDynamicPickup(playerid, STREAMER_TAG_PICKUP pickupid);
			#else
				forward ac_OnPlayerPickUpDynamicPickup(playerid, pickupid);
			#endif
		#endif
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerPickUpPickup(playerid, pickupid)
#else
	public OnPlayerPickUpPickup(playerid, pickupid)
#endif
{
	if(!(0 <= playerid < MAX_PLAYERS) || ACInfo[playerid][acKicked] > 0 || !(0 <= pickupid < MAX_PICKUPS)) return 0;
	#if defined Streamer_GetItemStreamerID\
		&& defined IsValidDynamicPickup
		#if defined STREAMER_ENABLE_TAGS
			new STREAMER_TAG_PICKUP streamerid = STREAMER_TAG_PICKUP Streamer_GetItemStreamerID(playerid, STREAMER_TYPE_PICKUP, pickupid);
		#else
			new streamerid = Streamer_GetItemStreamerID(playerid, STREAMER_TYPE_PICKUP, pickupid);
		#endif
		if(!IsValidDynamicPickup(streamerid))
		{
	#endif
		new ac_i = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_i < ACInfo[playerid][acCall][8] + ac_Mtfc[8][0]) ac_FloodDetect(playerid, 8);
			else if(ac_i < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][8] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		if(ACInfo[playerid][acACAllow][6])
		{
			new Float:ac_dist = GetPlayerDistanceFromPoint(playerid, ACPickInfo[pickupid][acPosX], ACPickInfo[pickupid][acPosY], ACPickInfo[pickupid][acPosZ]),
			Float:ac_dist_set = VectorSize(floatsub(ACInfo[playerid][acSetPosX], ACPickInfo[pickupid][acPosX]), floatsub(ACInfo[playerid][acSetPosY], ACPickInfo[pickupid][acPosY]), floatsub((ACInfo[playerid][acTpToZ] ? ACPickInfo[pickupid][acPosZ] : ACInfo[playerid][acSetPosZ]), ACPickInfo[pickupid][acPosZ]));
			if(floatcmp(ac_dist, 15.0) == 1 && (ACInfo[playerid][acSet][8] == -1 || floatcmp(ac_dist_set, 15.0) == 1))
			{
				#if defined DEBUG
					printf("[Nex-AC debug] Pickupid: %d, dist: %f, dist set: %f, playerid: %d",
					pickupid, ac_dist, ac_dist_set, playerid);
				#endif
				#if defined OnCheatDetected
					ac_KickWithCode(playerid, "", 0, 6, 1);
				#endif
				return 0;
			}
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][8] = ac_i;
		#if AC_USE_PICKUP_WEAPONS
			switch(ACPickInfo[pickupid][acType])
			{
				case 1:
				{
					ac_i = ACPickInfo[pickupid][acWeapon];
					new ac_s = ac_wSlot[ac_i];
					if(ACInfo[playerid][acWeapon][ac_s] == ac_i ||
					3 <= ac_s <= 5 && ACInfo[playerid][acWeapon][ac_s] > 0) ACInfo[playerid][acAmmo][ac_s] += ac_pAmmo[ac_i];
				}
				case 2: ACInfo[playerid][acSpecAct] = SPECIAL_ACTION_USEJETPACK;
				case 3: ACInfo[playerid][acHealth] = 100;
				case 4: ACInfo[playerid][acArmour] = 100;
			}
		#endif
		ACInfo[playerid][acLastPickup] = pickupid;
	#if defined Streamer_GetItemStreamerID\
		&& defined IsValidDynamicPickup
		}
	#endif
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerPickUpPickup
		#if defined Streamer_GetItemStreamerID\
			&& defined IsValidDynamicPickup
			if(IsValidDynamicPickup(streamerid) ||
			!ACPickInfo[pickupid][acIsStatic]) return ac_OnPlayerPickUpPickup(playerid, pickupid);
		#else
			if(!ACPickInfo[pickupid][acIsStatic]) return ac_OnPlayerPickUpPickup(playerid, pickupid);
		#endif
		return 1;
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerPickUpPickup
		#undef OnPlayerPickUpPickup
	#else
		#define _ALS_OnPlayerPickUpPickup
	#endif
	#define OnPlayerPickUpPickup ac_OnPlayerPickUpPickup
	#if defined ac_OnPlayerPickUpPickup
		forward ac_OnPlayerPickUpPickup(playerid, pickupid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerRequestClass(playerid, classid)
#else
	public OnPlayerRequestClass(playerid, classid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	if(!IsPlayerNPC(playerid))
	{
		new ac_gtc = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_gtc < ACInfo[playerid][acCall][9] + ac_Mtfc[9][0]) ac_FloodDetect(playerid, 9);
			else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][9] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		if(ACInfo[playerid][acDead]) ACInfo[playerid][acSpawned] = false;
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][9] = ac_gtc;
		ACInfo[playerid][acSpawnPosX] = ac_ClassPos[classid][0];
		ACInfo[playerid][acSpawnPosY] = ac_ClassPos[classid][1];
		ACInfo[playerid][acSpawnPosZ] = ac_ClassPos[classid][2];
		ACInfo[playerid][acSpawnWeapon1] = ac_ClassWeapon[classid][0][0];
		ACInfo[playerid][acSpawnAmmo1] = ac_ClassWeapon[classid][0][1];
		ACInfo[playerid][acSpawnWeapon2] = ac_ClassWeapon[classid][1][0];
		ACInfo[playerid][acSpawnAmmo2] = ac_ClassWeapon[classid][1][1];
		ACInfo[playerid][acSpawnWeapon3] = ac_ClassWeapon[classid][2][0];
		ACInfo[playerid][acSpawnAmmo3] = ac_ClassWeapon[classid][2][1];
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerRequestClass
		return ac_OnPlayerRequestClass(playerid, classid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerRequestClass
		#undef OnPlayerRequestClass
	#else
		#define _ALS_OnPlayerRequestClass
	#endif
	#define OnPlayerRequestClass ac_OnPlayerRequestClass
	#if defined ac_OnPlayerRequestClass
		forward ac_OnPlayerRequestClass(playerid, classid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerSelectedMenuRow(playerid, row)
#else
	public OnPlayerSelectedMenuRow(playerid, row)
#endif
{
	if(!(0 <= playerid < MAX_PLAYERS) || ACInfo[playerid][acKicked] > 0) return 0;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][10] + ac_Mtfc[10][0]) ac_FloodDetect(playerid, 10);
		else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][10] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][10] = ac_gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerSelectedMenuRow
		return ac_OnPlayerSelectedMenuRow(playerid, row);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerSelectedMenuRow
		#undef OnPlayerSelectedMenuRow
	#else
		#define _ALS_OnPlayerSelectedMenuRow
	#endif
	#define OnPlayerSelectedMenuRow ac_OnPlayerSelectedMenuRow
	#if defined ac_OnPlayerSelectedMenuRow
		forward ac_OnPlayerSelectedMenuRow(playerid, row);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerStateChange(playerid, newstate, oldstate)
#else
	public OnPlayerStateChange(playerid, newstate, oldstate)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	if(!IsPlayerNPC(playerid))
	{
		new ac_i = GetTickCount(), ac_s = GetPlayerPing(playerid);
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_i < ACInfo[playerid][acCall][11] + ac_Mtfc[11][0])
			{
				if(newstate != PLAYER_STATE_ONFOOT || oldstate != PLAYER_STATE_SPAWNED)
				{
					new ac_model;
					if(oldstate == PLAYER_STATE_DRIVER) ac_model = GetVehicleModel(ACInfo[playerid][acVeh]);
					else if(newstate == PLAYER_STATE_DRIVER) ac_model = GetVehicleModel(GetPlayerVehicleID(playerid));
					if(!ac_IsABoat(ac_model)) ac_FloodDetect(playerid, 11);
				}
			}
			else if(ac_i < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][11] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][11] = ac_i;
		switch(oldstate)
		{
			case PLAYER_STATE_NONE, PLAYER_STATE_WASTED:
			{
				if(ACInfo[playerid][acACAllow][48] && !(PLAYER_STATE_SPAWNED <= newstate <= PLAYER_STATE_SPECTATING))
				{
					#if defined DEBUG
						printf("[Nex-AC debug] Newstate: %d, oldstate: %d", newstate, oldstate);
					#endif
					ac_KickWithCode(playerid, "", 0, 48, 2);
				}
			}
			case PLAYER_STATE_DRIVER:
			{
				new ac_t;
				if(ACVehInfo[ACInfo[playerid][acVeh]][acDriver] == playerid) ACVehInfo[ACInfo[playerid][acVeh]][acDriver] = INVALID_PLAYER_ID;
				GetPlayerWeaponData(playerid, 4, ac_t, ac_t);
				if(ac_t < ACInfo[playerid][acAmmo][4] &&
				!(ac_t < 0 <= ACInfo[playerid][acAmmo][4])) ACInfo[playerid][acAmmo][4] = ac_t;
				ac_t = GetVehicleModel(ACInfo[playerid][acVeh]);
				if(1 <= ACInfo[playerid][acHealth] < 5 && ac_IsABike(ac_t)) ACInfo[playerid][acHealth] = 5;
				new Float:ac_vX, Float:ac_vY, Float:ac_vZ = ACInfo[playerid][acPosZ];
				if(ACInfo[playerid][acACAllow][2] && newstate == PLAYER_STATE_ONFOOT &&
				ACInfo[playerid][acSet][8] == -1 && ac_i > ACInfo[playerid][acGtc][11] + ac_s &&
				floatcmp(ACInfo[playerid][acPosZ], -95.0) == 1)
				{
					if(ac_IsAnAircraft(ac_t)) GetPlayerPos(playerid, ac_vX, ac_vY, ac_vZ);
					if(floatcmp((ac_vX = GetPlayerDistanceFromPoint(playerid, ACInfo[playerid][acPosX], ACInfo[playerid][acPosY], ac_vZ)), 50.0) >= 0)
					{
						#if defined DEBUG
							printf("[Nex-AC debug] Veh model: %d, dist: %f", ac_t, ac_vX);
						#endif
						ac_KickWithCode(playerid, "", 0, 2, 4);
					}
				}
				GetPlayerVelocity(playerid, ac_vX, ac_vY, ac_vZ);
				ACInfo[playerid][acSpeed] = ac_GetSpeed(ac_vX, ac_vY, ac_vZ);
				if(ACInfo[playerid][acSet][8] == 3) ACInfo[playerid][acSet][8] = -1;
				ACInfo[playerid][acGtc][10] = ac_i + 800;
			}
			case PLAYER_STATE_PASSENGER:
			{
				new Float:ac_vX, Float:ac_vY, Float:ac_vZ;
				if(ACInfo[playerid][acACAllow][2] && newstate == PLAYER_STATE_ONFOOT &&
				ACInfo[playerid][acSet][8] == -1 && ac_i > ACInfo[playerid][acGtc][11] + ac_s)
				{
					ac_s = ACVehInfo[ACInfo[playerid][acVeh]][acDriver];
					if(ac_s == INVALID_PLAYER_ID || ac_i < ACInfo[ac_s][acUpdateTime] + 2000)
					{
						new ac_model = GetVehicleModel(ACInfo[playerid][acVeh]);
						ac_vX = GetPlayerDistanceFromPoint(playerid, ACInfo[playerid][acPosX], ACInfo[playerid][acPosY], ACInfo[playerid][acPosZ]);
						if(!(ac_model == 449 || 537 <= ac_model <= 538 || 569 <= ac_model <= 570) && floatcmp(ac_vX, 50.0) >= 0)
						{
							#if defined DEBUG
								if(ac_s == INVALID_PLAYER_ID) printf("[Nex-AC debug] Veh model: %d, dist: %f", ac_model, ac_vX);
								else printf("[Nex-AC debug] Veh model: %d, driver AFK time: %d, dist: %f", ac_model, ac_i - ACInfo[ac_s][acUpdateTime], ac_vX);
							#endif
							ac_KickWithCode(playerid, "", 0, 2, 5);
						}
					}
				}
				GetPlayerVelocity(playerid, ac_vX, ac_vY, ac_vZ);
				ACInfo[playerid][acSpeed] = ac_GetSpeed(ac_vX, ac_vY, ac_vZ);
				ACInfo[playerid][acGtc][10] = ac_i + 800;
			}
		}
		switch(newstate)
		{
			case PLAYER_STATE_ONFOOT:
			{
				ACInfo[playerid][acSet][11] = -1;
				if(PLAYER_STATE_DRIVER <= oldstate <= PLAYER_STATE_PASSENGER) GetPlayerPos(playerid, ACInfo[playerid][acPosX], ACInfo[playerid][acPosY], ACInfo[playerid][acPosZ]);
			}
			case PLAYER_STATE_DRIVER, PLAYER_STATE_PASSENGER:
			{
				ACInfo[playerid][acSet][11] = -1;
				ACInfo[playerid][acCheatCount][3] =
				ACInfo[playerid][acCheatCount][4] = 0;
				new ac_vehid = GetPlayerVehicleID(playerid);
				ac_s = GetVehicleModel(ac_vehid);
				if(ACInfo[playerid][acSet][9] == -1)
				{
					if(ACInfo[playerid][acACAllow][4])
					{
						if(ACInfo[playerid][acEnterVeh] != ac_vehid || ac_i < ACInfo[playerid][acEnterVehTime] + 300)
						{
							#if defined DEBUG
								printf("[Nex-AC debug] Entered veh: %d, veh: %d, veh model: %d, enter time: %d",
								ACInfo[playerid][acEnterVeh], ac_vehid, ac_s, ac_i - ACInfo[playerid][acEnterVehTime]);
							#endif
							ac_KickWithCode(playerid, "", 0, 4, 1);
						}
						else
						{
							new Float:ac_dist = GetPlayerDistanceFromPoint(playerid, ACInfo[playerid][acPosX], ACInfo[playerid][acPosY], ACInfo[playerid][acPosZ]);
							if(newstate == PLAYER_STATE_DRIVER)
							{
								if(floatcmp(ac_dist, 25.0) == 1 || ac_s != 577 && ac_s != 592 && floatcmp(ac_dist, 15.0) == 1)
								{
									#if defined DEBUG
										printf("[Nex-AC debug] Veh model: %d, dist: %f", ac_s, ac_dist);
									#endif
									ac_KickWithCode(playerid, "", 0, 4, 3);
								}
							}
							else if(!(ac_s == 449 || 537 <= ac_s <= 538 || 569 <= ac_s <= 570) &&
							(floatcmp(ac_dist, 80.0) == 1 || ac_i >= ACInfo[playerid][acUpdateTime] + 1500 && floatcmp(ac_dist, 15.0) == 1))
							{
								#if defined DEBUG
									printf("[Nex-AC debug] Veh model: %d, AFK time: %d, dist: %f", ac_s, ac_i - ACInfo[playerid][acUpdateTime], ac_dist);
								#endif
								ac_KickWithCode(playerid, "", 0, 4, 4);
							}
						}
					}
					if(newstate == PLAYER_STATE_DRIVER && ACInfo[playerid][acKicked] < 1)
					{
						ACVehInfo[ac_vehid][acDriver] = playerid;
						GetPlayerPos(playerid, ACInfo[playerid][acPosX], ACInfo[playerid][acPosY], ACInfo[playerid][acPosZ]);
						ACInfo[playerid][acSetVehHealth] = -1.0;
						ACInfo[playerid][acCheatCount][11] = 0;
						ACInfo[playerid][acVehDmgRes] = false;
					}
					ACInfo[playerid][acEnterVeh] = 0;
				}
				if(ACInfo[playerid][acACAllow][44])
				{
					ac_i = GetPlayerVehicleSeat(playerid);
					if(ac_s < 400)
					{
						#if defined DEBUG
							printf("[Nex-AC debug] Veh model: %d, seatid: %d", ac_s, ac_i);
						#endif
						ac_KickWithCode(playerid, "", 0, 44, 2);
					}
					else if(ACInfo[playerid][acSet][9] == -1)
					{
						new ac_maxseats = ac_GetMaxPassengers(ac_s);
						if(newstate == PLAYER_STATE_DRIVER)
						{
							if(ac_i != 0 || ac_maxseats == 15)
							{
								#if defined DEBUG
									printf("[Nex-AC debug] Veh model: %d, seatid: %d", ac_s, ac_i);
								#endif
								ac_KickWithCode(playerid, "", 0, 44, 3);
							}
						}
						else if(ac_i < 1 || ac_maxseats == 15 || ac_i > ac_maxseats && ac_s != 431 && ac_s != 437 && ac_s != 570)
						{
							#if defined DEBUG
								printf("[Nex-AC debug] Veh model: %d, max seats: %d, seatid: %d", ac_s, ac_maxseats, ac_i);
							#endif
							ac_KickWithCode(playerid, "", 0, 44, 4);
						}
					}
				}
			}
			case PLAYER_STATE_SPAWNED:
			{
				ACInfo[playerid][acPosX] = ACInfo[playerid][acSpawnPosX];
				ACInfo[playerid][acPosY] = ACInfo[playerid][acSpawnPosY];
				ACInfo[playerid][acPosZ] = ACInfo[playerid][acSpawnPosZ];
			}
			case PLAYER_STATE_SPECTATING:
			{
				if(ACInfo[playerid][acACAllow][21] && !ACInfo[playerid][acSpec] &&
				ACInfo[playerid][acSet][6] == -1) ac_KickWithCode(playerid, "", 0, 21);
				if(ACInfo[playerid][acKicked] < 1)
				{
					ACInfo[playerid][acHealth] = 100;
					ACInfo[playerid][acSet][6] = -1;
					ACInfo[playerid][acSpec] = true;
				}
			}
		}
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerStateChange
		return ac_OnPlayerStateChange(playerid, newstate, oldstate);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerStateChange
		#undef OnPlayerStateChange
	#else
		#define _ALS_OnPlayerStateChange
	#endif
	#define OnPlayerStateChange ac_OnPlayerStateChange
	#if defined ac_OnPlayerStateChange
		forward ac_OnPlayerStateChange(playerid, newstate, oldstate);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
#else
	public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
#endif
{
	if(ACInfo[playerid][acKicked] > 0 || ACInfo[playerid][acDead]) return 0;
	if(ACInfo[playerid][acACAllow][22] && !ac_LagCompMode)
	{
		#if defined OnCheatDetected
			ac_KickWithCode(playerid, "", 0, 22);
		#endif
		return 0;
	}
	if(ACInfo[playerid][acACAllow][47] &&
	(!(BULLET_HIT_TYPE_NONE <= hittype <= BULLET_HIT_TYPE_PLAYER_OBJECT) ||
	hittype == BULLET_HIT_TYPE_PLAYER && !(0 <= hitid < MAX_PLAYERS) ||
	hittype == BULLET_HIT_TYPE_VEHICLE && !(1 <= hitid < MAX_VEHICLES) ||
	hittype == BULLET_HIT_TYPE_OBJECT && !(1 <= hitid < MAX_OBJECTS) ||
	hittype == BULLET_HIT_TYPE_PLAYER_OBJECT && !(1 <= hitid < MAX_OBJECTS) ||
	weaponid != 38 && !(22 <= weaponid <= 34)))
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Hittype: %d, hitid: %d, weaponid: %d", hittype, hitid, weaponid);
		#endif
		return ac_KickWithCode(playerid, "", 0, 47, 1);
	}
	new Float:ac_oX, Float:ac_oY, Float:ac_oZ, Float:ac_X, Float:ac_Y, Float:ac_Z;
	GetPlayerLastShotVectors(playerid, ac_oX, ac_oY, ac_oZ, ac_X, ac_Y, ac_Z);
	if(ACInfo[playerid][acACAllow][34])
	{
		new Float:ac_dist = GetPlayerDistanceFromPoint(playerid, ac_oX, ac_oY, ac_oZ);
		if(floatcmp(ac_dist, 50.0) == 1 || floatcmp(ac_dist, 15.0) == 1 && !IsPlayerInAnyVehicle(playerid) &&
		GetPlayerSurfingVehicleID(playerid) == INVALID_VEHICLE_ID && GetPlayerSurfingObjectID(playerid) == INVALID_OBJECT_ID)
		{
			if(++ACInfo[playerid][acCheatCount][5] > AC_MAX_AFK_GHOST_WARNINGS)
			{
				#undef AC_MAX_AFK_GHOST_WARNINGS
				#if defined DEBUG
					printf("[Nex-AC debug] Dist: %f", ac_dist);
				#endif
				#if defined OnCheatDetected
					ac_KickWithCode(playerid, "", 0, 34);
					if(ACInfo[playerid][acKicked] > 0) return 0;
					ACInfo[playerid][acCheatCount][5] = 0;
				#else
					return ac_KickWithCode(playerid, "", 0, 34);
				#endif
			}
			#if defined OnCheatWarning
				else OnCheatWarning(playerid, "", 0, 34, 0, ACInfo[playerid][acCheatCount][5]);
			#endif
		}
		else ACInfo[playerid][acCheatCount][5] = 0;
	}
	new ac_gtc = GetTickCount(), ac_gpp = GetPlayerPing(playerid);
	if(ACInfo[playerid][acACAllow][29])
	{
		if(hittype > BULLET_HIT_TYPE_NONE && !fX && !fY && !fZ)
		{
			if(++ACInfo[playerid][acCheatCount][13] > AC_MAX_SILENT_AIM_WARNINGS)
			{
				#undef AC_MAX_SILENT_AIM_WARNINGS
				#if defined DEBUG
					printf("[Nex-AC debug] Hittype: %d, weaponid: %d", hittype, weaponid);
				#endif
				#if defined OnCheatDetected
					ac_KickWithCode(playerid, "", 0, 29, 1);
					if(ACInfo[playerid][acKicked] > 0) return 0;
					ACInfo[playerid][acCheatCount][13] = 0;
				#else
					return ac_KickWithCode(playerid, "", 0, 29, 1);
				#endif
			}
			#if defined OnCheatWarning
				else OnCheatWarning(playerid, "", 0, 29, 1, ACInfo[playerid][acCheatCount][13]);
			#endif
		}
		else
		{
			ACInfo[playerid][acCheatCount][13] = 0;
			if(hittype == BULLET_HIT_TYPE_PLAYER && hitid != INVALID_PLAYER_ID &&
			!ACInfo[hitid][acDead] && ac_gtc > ACInfo[hitid][acSetPosTime] + ac_gpp &&
			ac_gtc < ACInfo[hitid][acUpdateTime] + 1500)
			{
				new Float:ac_dist = GetPlayerDistanceFromPoint(hitid, ac_X, ac_Y, ac_Z);
				if(floatcmp(ac_dist, 50.0) == 1 || floatcmp(ac_dist, 20.0) == 1 && !IsPlayerInAnyVehicle(hitid) &&
				GetPlayerSurfingVehicleID(hitid) == INVALID_VEHICLE_ID && GetPlayerSurfingObjectID(hitid) == INVALID_OBJECT_ID)
				{
					if(++ACInfo[playerid][acCheatCount][6] > AC_MAX_PRO_AIM_WARNINGS)
					{
						#undef AC_MAX_PRO_AIM_WARNINGS
						#if defined DEBUG
							printf("[Nex-AC debug] Dist: %f", ac_dist);
						#endif
						#if defined OnCheatDetected
							ac_KickWithCode(playerid, "", 0, 29, 2);
							if(ACInfo[playerid][acKicked] > 0) return 0;
							ACInfo[playerid][acCheatCount][6] = 0;
						#else
							return ac_KickWithCode(playerid, "", 0, 29, 2);
						#endif
					}
					#if defined OnCheatWarning
						else OnCheatWarning(playerid, "", 0, 29, 2, ACInfo[playerid][acCheatCount][6]);
					#endif
				}
				else ACInfo[playerid][acCheatCount][6] = 0;
			}
		}
	}
	new ac_i, ac_t, bool:ac_ur, bool:ac_ur2;
	switch(hittype)
	{
		case BULLET_HIT_TYPE_PLAYER:
		{
			if(hitid != INVALID_PLAYER_ID &&
			ACInfo[hitid][acACAllow][19] && ACInfo[hitid][acUnFrozen] &&
			!ACInfo[hitid][acDead] && ac_gtc > ACInfo[hitid][acSetPosTime] + ac_gpp &&
			IsPlayerInRangeOfPoint(hitid, ac_wRange[weaponid - 22], ac_oX, ac_oY, ac_oZ) &&
			!(SPECIAL_ACTION_ENTER_VEHICLE <= GetPlayerSpecialAction(hitid) <= SPECIAL_ACTION_EXIT_VEHICLE))
			{
				ac_t = GetPlayerTeam(playerid);
				if(ac_t == NO_TEAM || ac_t != GetPlayerTeam(hitid))
				{
					ac_i = GetPlayerInterior(hitid);
					#if AC_USE_RESTAURANTS
						if(!ac_InRestaurant(hitid, ac_i))
						{
					#endif
						#if AC_USE_AMMUNATIONS
							if(!ac_InAmmuNation(hitid, ac_i))
							{
						#endif
							#if AC_USE_CASINOS
								if(!ac_InCasino(hitid, ac_i))
								{
							#endif
								ac_ur = true;
							#if AC_USE_CASINOS
								}
							#endif
						#if AC_USE_AMMUNATIONS
							}
						#endif
					#if AC_USE_RESTAURANTS
						}
					#endif
				}
			}
		}
		case BULLET_HIT_TYPE_VEHICLE:
		{
			if(hitid != INVALID_VEHICLE_ID)
			{
				ac_i = ACVehInfo[hitid][acDriver];
				if(ac_i != INVALID_PLAYER_ID && ACInfo[ac_i][acACAllow][20] && ACInfo[ac_i][acUnFrozen] &&
				ac_gtc > ACInfo[ac_i][acSetPosTime] + ac_gpp && floatcmp(ACVehInfo[hitid][acHealth], 250.0) >= 0)
				{
					ac_t = GetPlayerTeam(playerid);
					if(!ac_VehFriendlyFire || ac_t == NO_TEAM || ac_t != GetPlayerTeam(ac_i))
					{
						ac_t = GetVehicleModel(hitid);
						new Float:ac_wX, Float:ac_wY, Float:ac_wZ;
						GetVehicleModelInfo(ac_t, VEHICLE_MODEL_INFO_WHEELSFRONT, ac_X, ac_Y, ac_Z);
						GetVehicleModelInfo(ac_t, VEHICLE_MODEL_INFO_WHEELSREAR, ac_oX, ac_oY, ac_oZ);
						GetVehicleModelInfo(ac_t, VEHICLE_MODEL_INFO_WHEELSMID, ac_wX, ac_wY, ac_wZ);
						if(floatcmp(VectorSize(floatsub(ac_X, fX), floatsub(ac_Y, fY), floatsub(ac_Z, fZ)), 1.2) == 1 &&
						floatcmp(VectorSize(floatsub(-ac_X, fX), floatsub(ac_Y, fY), floatsub(ac_Z, fZ)), 1.2) == 1 &&
						floatcmp(VectorSize(floatsub(ac_oX, fX), floatsub(ac_oY, fY), floatsub(ac_oZ, fZ)), 1.2) == 1 &&
						floatcmp(VectorSize(floatsub(-ac_oX, fX), floatsub(ac_oY, fY), floatsub(ac_oZ, fZ)), 1.2) == 1 &&
						(!ac_wX && !ac_wY && !ac_wZ || floatcmp(VectorSize(floatsub(ac_wX, fX), floatsub(ac_wY, fY), floatsub(ac_wZ, fZ)), 1.2) == 1 &&
						floatcmp(VectorSize(floatsub(-ac_wX, fX), floatsub(ac_wY, fY), floatsub(ac_wZ, fZ)), 1.2) == 1)) ac_ur2 = true;
					}
				}
			}
		}
	}
	if((ac_t = GetPlayerState(playerid)) != PLAYER_STATE_DRIVER)
	{
		new ac_s = GetPlayerWeapon(playerid);
		if(ACInfo[playerid][acACAllow][47] && ac_t != PLAYER_STATE_PASSENGER)
		{
			if(ac_s != weaponid)
			{
				if(++ACInfo[playerid][acCheatCount][18] > AC_MAX_FAKE_WEAPON_WARNINGS)
				{
					#undef AC_MAX_FAKE_WEAPON_WARNINGS
					#if defined DEBUG
						printf("[Nex-AC debug] Armed weapon: %d, weaponid: %d, state: %d", ac_s, weaponid, ac_t);
					#endif
					ac_KickWithCode(playerid, "", 0, 47, 2);
					#if defined OnCheatDetected
						ACInfo[playerid][acCheatCount][18] = 0;
					#endif
				}
				#if defined OnCheatWarning
					else OnCheatWarning(playerid, "", 0, 47, 2, ACInfo[playerid][acCheatCount][18]);
				#endif
				return 0;
			}
			else ACInfo[playerid][acCheatCount][18] = 0;
		}
		ac_s = ac_wSlot[weaponid];
		if(ACInfo[playerid][acACAllow][26])
		{
			ac_i = ac_gtc - ACInfo[playerid][acShotTime];
			if(ACInfo[playerid][acLastShot] == weaponid)
			{
				if(weaponid != 38 && ac_t != PLAYER_STATE_PASSENGER)
				{
					if(ac_gtc < ACInfo[playerid][acReloadTime] + 110)
					{
						#if defined DEBUG
							printf("[Nex-AC debug] Weaponid: %d, Reload time: %d, state: %d",
							weaponid, ac_gtc - ACInfo[playerid][acReloadTime], ac_t);
						#endif
						#if defined OnCheatDetected
							ac_KickWithCode(playerid, "", 0, 26, 4);
							if(ACInfo[playerid][acKicked] > 0) return 0;
							ACInfo[playerid][acReloadTime] = 0;
						#else
							return ac_KickWithCode(playerid, "", 0, 26, 4);
						#endif
					}
					else if(ac_i < 30 || ac_i < 50 && weaponid != 32 && !(28 <= weaponid <= 29))
					{
						if(++ACInfo[playerid][acCheatCount][8] > AC_MAX_RAPID_FIRE_WARNINGS)
						{
							#undef AC_MAX_RAPID_FIRE_WARNINGS
							#if defined DEBUG
								printf("[Nex-AC debug] Fire rate: %d, weaponid: %d", ac_i, weaponid);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 26, 1);
								if(ACInfo[playerid][acKicked] > 0) return 0;
								ACInfo[playerid][acCheatCount][8] = 0;
							#else
								return ac_KickWithCode(playerid, "", 0, 26, 1);
							#endif
						}
						#if defined OnCheatWarning
							else OnCheatWarning(playerid, "", 0, 26, 1, ACInfo[playerid][acCheatCount][8]);
						#endif
					}
					else ACInfo[playerid][acCheatCount][8] = 0;
					if(weaponid == 25 && ac_i < 600 || (weaponid == 24 || 33 <= weaponid <= 34) && ac_i < 380)
					{
						if(++ACInfo[playerid][acCheatCount][14] > AC_MAX_AUTO_C_WARNINGS)
						{
							#undef AC_MAX_AUTO_C_WARNINGS
							#if defined DEBUG
								printf("[Nex-AC debug] Fire rate: %d, weaponid: %d", ac_i, weaponid);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 26, 2);
								if(ACInfo[playerid][acKicked] > 0) return 0;
								ACInfo[playerid][acCheatCount][14] = 0;
							#else
								return ac_KickWithCode(playerid, "", 0, 26, 2);
							#endif
						}
						#if defined OnCheatWarning
							else OnCheatWarning(playerid, "", 0, 26, 2, ACInfo[playerid][acCheatCount][14]);
						#endif
					}
				}
			}
			else if(ac_i < 30)
			{
				#if defined DEBUG
					printf("[Nex-AC debug] Fire rate: %d, weaponid: %d, last weapon: %d",
					ac_i, weaponid, ACInfo[playerid][acLastShot]);
				#endif
				#if defined OnCheatDetected
					ac_KickWithCode(playerid, "", 0, 26, 3);
					if(ACInfo[playerid][acKicked] > 0) return 0;
				#else
					return ac_KickWithCode(playerid, "", 0, 26, 3);
				#endif
			}
			if(GetPlayerWeaponState(playerid) == WEAPONSTATE_LAST_BULLET) ACInfo[playerid][acReloadTime] = ac_gtc;
		}
		if(ACInfo[playerid][acACAllow][17] && ac_t != PLAYER_STATE_PASSENGER &&
		ACInfo[playerid][acGiveAmmo][ac_s] == -65535 && ac_gtc > ACInfo[playerid][acGtc][7] + ac_gpp)
		{
			ac_t = GetPlayerAmmo(playerid);
			if(ACInfo[playerid][acAmmo][ac_s] == 0)
			{
				#if defined DEBUG
					printf("[Nex-AC debug] Weaponid: %d, AC ammo: %d, ammo: %d", weaponid, ACInfo[playerid][acAmmo][ac_s], ac_t);
				#endif
				#if defined OnCheatDetected
					ac_KickWithCode(playerid, "", 0, 17, 1);
					if(ACInfo[playerid][acKicked] > 0) return 0;
					ACInfo[playerid][acAmmo][ac_s] = ac_t;
				#else
					return ac_KickWithCode(playerid, "", 0, 17, 1);
				#endif
			}
			if(ACInfo[playerid][acAmmo][ac_s] < ac_t)
			{
				switch(weaponid)
				{
					case 38:
					{
						if(++ACInfo[playerid][acCheatCount][7] > 8)
						{
							#if defined DEBUG
								printf("[Nex-AC debug] Weaponid: %d, AC ammo: %d, ammo: %d, acCheatCount[7]: %d",
								weaponid, ACInfo[playerid][acAmmo][ac_s], ac_t, ACInfo[playerid][acCheatCount][7]);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 17, 2);
								if(ACInfo[playerid][acKicked] > 0) return 0;
								ACInfo[playerid][acCheatCount][7] = 0;
								ACInfo[playerid][acAmmo][ac_s] = ac_t;
							#else
								return ac_KickWithCode(playerid, "", 0, 17, 2);
							#endif
						}
						#if defined OnCheatWarning
							else OnCheatWarning(playerid, "", 0, 17, 2, ACInfo[playerid][acCheatCount][7]);
						#endif
					}
					default:
					{
						if(ac_t - ACInfo[playerid][acAmmo][ac_s] > 3)
						{
							#if defined DEBUG
								printf("[Nex-AC debug] Weaponid: %d, AC ammo: %d, ammo: %d",
								weaponid, ACInfo[playerid][acAmmo][ac_s], ac_t);
							#endif
							#if defined OnCheatDetected
								ac_KickWithCode(playerid, "", 0, 17, 3);
								if(ACInfo[playerid][acKicked] > 0) return 0;
								ACInfo[playerid][acCheatCount][7] = 0;
								ACInfo[playerid][acAmmo][ac_s] = ac_t;
							#else
								return ac_KickWithCode(playerid, "", 0, 17, 3);
							#endif
						}
					}
				}
			}
			else ACInfo[playerid][acCheatCount][7] = 0;
		}
		if(ACInfo[playerid][acAmmo][ac_s] != 0)
		{
			ACInfo[playerid][acAmmo][ac_s]--;
			if(ACInfo[playerid][acAmmo][ac_s] == 0 &&
			ACInfo[playerid][acSet][3] == weaponid) ACInfo[playerid][acSet][3] = ACInfo[playerid][acSetWeapon][ac_s] = -1;
		}
		if(ACInfo[playerid][acAmmo][ac_s] < -32768) ACInfo[playerid][acAmmo][ac_s] += 65536;
	}
	ACInfo[playerid][acLastShot] = weaponid;
	ACInfo[playerid][acShotTime] = ac_gtc;
	ac_i = 1;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerWeaponShot
		ac_i = ac_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, fX, fY, fZ);
	#endif
	if(ac_i)
	{
		if(ac_ur)
		{
			if(ACInfo[hitid][acArmour] > 0) ACInfo[hitid][acDmgRes] = 2;
			else ACInfo[hitid][acDmgRes] = 1;
			ACInfo[hitid][acGtc][14] = ac_gtc + 165;
		}
		if(ac_ur2)
		{
			ACInfo[ACVehInfo[hitid][acDriver]][acVehDmgRes] = true;
			ACInfo[ACVehInfo[hitid][acDriver]][acGtc][16] = ac_gtc + 165;
		}
	}
	return ac_i;
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerWeaponShot
		#undef OnPlayerWeaponShot
	#else
		#define _ALS_OnPlayerWeaponShot
	#endif
	#define OnPlayerWeaponShot ac_OnPlayerWeaponShot
	#if defined ac_OnPlayerWeaponShot
		forward ac_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnVehicleMod(playerid, vehicleid, componentid)
#else
	public OnVehicleMod(playerid, vehicleid, componentid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	new ac_i = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_i < ACInfo[playerid][acCall][12] + ac_Mtfc[12][0]) return ac_FloodDetect(playerid, 12);
		if(ac_i < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][12] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	if(ACInfo[playerid][acACAllow][23] && !ACInfo[playerid][acModShop])
	{
		#if defined OnCheatDetected
			ac_KickWithCode(playerid, "", 0, 23, 2);
			if(ACInfo[playerid][acKicked] > 0) return 0;
		#else
			return ac_KickWithCode(playerid, "", 0, 23, 2);
		#endif
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][12] = ac_i;
	ACInfo[playerid][acGtc][17] = ac_i + 3250;
	if(ACInfo[playerid][acACAllow][43] && !ac_IsCompatible((ac_i = GetVehicleModel(vehicleid)), componentid))
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Veh model: %d, componentid: %d", ac_i, componentid);
		#endif
		return ac_KickWithCode(playerid, "", 0, 43, 1);
	}
	#if AC_USE_TUNING_GARAGES
		ac_i = componentid - 1000;
		if(ACInfo[playerid][acSet][12] != -1) ACInfo[playerid][acSet][12] += ac_cPrice[ac_i];
		else ACInfo[playerid][acSet][12] = ac_cPrice[ac_i];
		ACInfo[playerid][acCheatCount][12] = 0;
	#endif
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnVehicleMod
		return ac_OnVehicleMod(playerid, vehicleid, componentid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnVehicleMod
		#undef OnVehicleMod
	#else
		#define _ALS_OnVehicleMod
	#endif
	#define OnVehicleMod ac_OnVehicleMod
	#if defined ac_OnVehicleMod
		forward ac_OnVehicleMod(playerid, vehicleid, componentid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnVehiclePaintjob(playerid, vehicleid, paintjobid)
#else
	public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][13] + ac_Mtfc[13][0]) ac_FloodDetect(playerid, 13);
		else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][13] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	if(ACInfo[playerid][acACAllow][43] && !(0 <= paintjobid <= 2) && paintjobid != 255)
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Veh model: %d, paintjobid: %d", GetVehicleModel(vehicleid), paintjobid);
		#endif
		ac_KickWithCode(playerid, "", 0, 43, 2);
	}
	else if(ACInfo[playerid][acACAllow][23] && !ACInfo[playerid][acModShop]) ac_KickWithCode(playerid, "", 0, 23, 4);
	if(ACInfo[playerid][acKicked] < 1)
	{
		if(paintjobid == 255) ACVehInfo[vehicleid][acPaintJob] = 3;
		else ACVehInfo[vehicleid][acPaintJob] = paintjobid;
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][13] = ac_gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnVehiclePaintjob
		return ac_OnVehiclePaintjob(playerid, vehicleid, paintjobid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnVehiclePaintjob
		#undef OnVehiclePaintjob
	#else
		#define _ALS_OnVehiclePaintjob
	#endif
	#define OnVehiclePaintjob ac_OnVehiclePaintjob
	#if defined ac_OnVehiclePaintjob
		forward ac_OnVehiclePaintjob(playerid, vehicleid, paintjobid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnVehicleRespray(playerid, vehicleid, color1, color2)
#else
	public OnVehicleRespray(playerid, vehicleid, color1, color2)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][14] + ac_Mtfc[14][0]) return ac_FloodDetect(playerid, 14);
		if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][14] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	#if !AC_USE_TUNING_GARAGES && !AC_USE_PAYNSPRAY
		if(ACInfo[playerid][acACAllow][23])
		{
			#if defined DEBUG
				printf("[Nex-AC debug] Veh model: %d, color1: %d, color2: %d", GetVehicleModel(vehicleid), color1, color2);
			#endif
			#if defined OnCheatDetected
				ac_KickWithCode(playerid, "", 0, 23, 5);
				if(ACInfo[playerid][acKicked] > 0) return 0;
			#else
				return ac_KickWithCode(playerid, "", 0, 23, 5);
			#endif
		}
	#endif
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][14] = ac_gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnVehicleRespray
		return ac_OnVehicleRespray(playerid, vehicleid, color1, color2);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnVehicleRespray
		#undef OnVehicleRespray
	#else
		#define _ALS_OnVehicleRespray
	#endif
	#define OnVehicleRespray ac_OnVehicleRespray
	#if defined ac_OnVehicleRespray
		forward ac_OnVehicleRespray(playerid, vehicleid, color1, color2);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnVehicleSpawn(vehicleid)
#else
	public OnVehicleSpawn(vehicleid)
#endif
{
	ACVehInfo[vehicleid][acPaintJob] = 3;
	ACVehInfo[vehicleid][acSpawned] = true;
	ACVehInfo[vehicleid][acHealth] = 1000.0;
	ACVehInfo[vehicleid][acSpeedDiff] = 0;
	ACVehInfo[vehicleid][acPosDiff] =
	ACVehInfo[vehicleid][acVelX] =
	ACVehInfo[vehicleid][acVelY] =
	ACVehInfo[vehicleid][acVelZ] = 0.0;
	ACVehInfo[vehicleid][acPosX] = ACVehInfo[vehicleid][acSpawnPosX];
	ACVehInfo[vehicleid][acPosY] = ACVehInfo[vehicleid][acSpawnPosY];
	ACVehInfo[vehicleid][acPosZ] = ACVehInfo[vehicleid][acSpawnPosZ];
	ACVehInfo[vehicleid][acZAngle] = ACVehInfo[vehicleid][acSpawnZAngle];
	ACVehInfo[vehicleid][acDriver] = INVALID_PLAYER_ID;
	new ac_gtc = GetTickCount() + 800;
	#if defined foreach
		foreach(new ac_i : Player)
		{
			if(ACInfo[ac_i][acVeh] == vehicleid)
			{
				ACInfo[ac_i][acSetPosTime] =
				ACInfo[ac_i][acGtc][11] = ac_gtc;
			}
		}
	#else
		for(new ac_i = GetPlayerPoolSize(); ac_i >= 0; --ac_i)
		{
			if(IsPlayerInVehicle(ac_i, vehicleid))
			{
				ACInfo[ac_i][acSetPosTime] =
				ACInfo[ac_i][acGtc][11] = ac_gtc;
			}
		}
	#endif
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnVehicleSpawn
		return ac_OnVehicleSpawn(vehicleid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnVehicleSpawn
		#undef OnVehicleSpawn
	#else
		#define _ALS_OnVehicleSpawn
	#endif
	#define OnVehicleSpawn ac_OnVehicleSpawn
	#if defined ac_OnVehicleSpawn
		forward ac_OnVehicleSpawn(vehicleid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnVehicleDeath(vehicleid, killerid)
#else
	public OnVehicleDeath(vehicleid, killerid)
#endif
{
	if(killerid != INVALID_PLAYER_ID && !IsPlayerNPC(killerid))
	{
		new ac_gtc = GetTickCount();
		if(ACInfo[killerid][acACAllow][49])
		{
			if(ac_gtc < ACInfo[killerid][acCall][15] + ac_Mtfc[15][0]) ac_FloodDetect(killerid, 15);
			else if(ac_gtc < ACInfo[killerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(killerid, 27);
			else ACInfo[killerid][acFloodCount][15] = ACInfo[killerid][acFloodCount][27] = 0;
		}
		ACInfo[killerid][acCall][27] = ACInfo[killerid][acCall][15] = ac_gtc;
	}
	new Float:ac_vHealth;
	GetVehicleHealth(vehicleid, ac_vHealth);
	if(floatcmp(ac_vHealth, 250.0) == -1) ACVehInfo[vehicleid][acSpawned] = false;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnVehicleDeath
		return ac_OnVehicleDeath(vehicleid, killerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnVehicleDeath
		#undef OnVehicleDeath
	#else
		#define _ALS_OnVehicleDeath
	#endif
	#define OnVehicleDeath ac_OnVehicleDeath
	#if defined ac_OnVehicleDeath
		forward ac_OnVehicleDeath(vehicleid, killerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerText(playerid, text[])
#else
	public OnPlayerText(playerid, text[])
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	if(!IsPlayerNPC(playerid))
	{
		new ac_gtc = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_gtc < ACInfo[playerid][acCall][16] + ac_Mtfc[16][0]) return ac_FloodDetect(playerid, 16);
			if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][16] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][16] = ac_gtc;
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerText
		return ac_OnPlayerText(playerid, text);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerText
		#undef OnPlayerText
	#else
		#define _ALS_OnPlayerText
	#endif
	#define OnPlayerText ac_OnPlayerText
	#if defined ac_OnPlayerText
		forward ac_OnPlayerText(playerid, text[]);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerEnterCheckpoint(playerid)
#else
	public OnPlayerEnterCheckpoint(playerid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	if(!IsPlayerNPC(playerid))
	{
		new ac_gtc = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_gtc < ACInfo[playerid][acCall][17] + ac_Mtfc[17][0]) ac_FloodDetect(playerid, 17);
			else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][17] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][17] = ac_gtc;
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerEnterCheckpoint
		return ac_OnPlayerEnterCheckpoint(playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerEnterCheckpoint
		#undef OnPlayerEnterCheckpoint
	#else
		#define _ALS_OnPlayerEnterCheckpoint
	#endif
	#define OnPlayerEnterCheckpoint ac_OnPlayerEnterCheckpoint
	#if defined ac_OnPlayerEnterCheckpoint
		forward ac_OnPlayerEnterCheckpoint(playerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerLeaveCheckpoint(playerid)
#else
	public OnPlayerLeaveCheckpoint(playerid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	if(!IsPlayerNPC(playerid))
	{
		new ac_gtc = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_gtc < ACInfo[playerid][acCall][18] + ac_Mtfc[18][0]) ac_FloodDetect(playerid, 18);
			else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][18] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][18] = ac_gtc;
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerLeaveCheckpoint
		return ac_OnPlayerLeaveCheckpoint(playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerLeaveCheckpoint
		#undef OnPlayerLeaveCheckpoint
	#else
		#define _ALS_OnPlayerLeaveCheckpoint
	#endif
	#define OnPlayerLeaveCheckpoint ac_OnPlayerLeaveCheckpoint
	#if defined ac_OnPlayerLeaveCheckpoint
		forward ac_OnPlayerLeaveCheckpoint(playerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerRequestSpawn(playerid)
#else
	public OnPlayerRequestSpawn(playerid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	new ac_i;
	if(!IsPlayerNPC(playerid))
	{
		ac_i = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_i < ACInfo[playerid][acCall][19] + ac_Mtfc[19][0]) return ac_FloodDetect(playerid, 19);
			if(ac_i < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][19] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][19] = ac_i;
	}
	ac_i = 1;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerRequestSpawn
		ac_i = ac_OnPlayerRequestSpawn(playerid);
	#endif
	if(ac_i && !ACInfo[playerid][acSpawned])
	{
		ACInfo[playerid][acSet][7] = 3;
		ACInfo[playerid][acSpawnTime] =
		ACInfo[playerid][acNOPCount][9] = 0;
		ACInfo[playerid][acSpawnRes] = 1;
	}
	return ac_i;
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerRequestSpawn
		#undef OnPlayerRequestSpawn
	#else
		#define _ALS_OnPlayerRequestSpawn
	#endif
	#define OnPlayerRequestSpawn ac_OnPlayerRequestSpawn
	#if defined ac_OnPlayerRequestSpawn
		forward ac_OnPlayerRequestSpawn(playerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerExitedMenu(playerid)
#else
	public OnPlayerExitedMenu(playerid)
#endif
{
	if(!(0 <= playerid < MAX_PLAYERS) || ACInfo[playerid][acKicked] > 0) return 0;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][20] + ac_Mtfc[20][0]) ac_FloodDetect(playerid, 20);
		else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][20] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][20] = ac_gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerExitedMenu
		return ac_OnPlayerExitedMenu(playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerExitedMenu
		#undef OnPlayerExitedMenu
	#else
		#define _ALS_OnPlayerExitedMenu
	#endif
	#define OnPlayerExitedMenu ac_OnPlayerExitedMenu
	#if defined ac_OnPlayerExitedMenu
		forward ac_OnPlayerExitedMenu(playerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerEnterRaceCP(playerid)
#else
	public OnPlayerEnterRaceCheckpoint(playerid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	if(!IsPlayerNPC(playerid))
	{
		new ac_gtc = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_gtc < ACInfo[playerid][acCall][21] + ac_Mtfc[21][0]) ac_FloodDetect(playerid, 21);
			else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][21] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][21] = ac_gtc;
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerEnterRaceCheckpoint
		return ac_OnPlayerEnterRaceCheckpoint(playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerEnterRaceCheckpoin\
		|| defined _ALS_OnPlayerEnterRaceCP
		#undef OnPlayerEnterRaceCheckpoint
	#else
		#define _ALS_OnPlayerEnterRaceCP
	#endif
	#define OnPlayerEnterRaceCheckpoint ac_OnPlayerEnterRaceCheckpoint
	#if defined ac_OnPlayerEnterRaceCheckpoint
		forward ac_OnPlayerEnterRaceCheckpoint(playerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerLeaveRaceCP(playerid)
#else
	public OnPlayerLeaveRaceCheckpoint(playerid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	if(!IsPlayerNPC(playerid))
	{
		new ac_gtc = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_gtc < ACInfo[playerid][acCall][22] + ac_Mtfc[22][0]) ac_FloodDetect(playerid, 22);
			else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][22] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][22] = ac_gtc;
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerLeaveRaceCheckpoint
		return ac_OnPlayerLeaveRaceCheckpoint(playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerLeaveRaceCheckpoin\
		|| defined _ALS_OnPlayerLeaveRaceCP
		#undef OnPlayerLeaveRaceCheckpoint
	#else
		#define _ALS_OnPlayerLeaveRaceCP
	#endif
	#define OnPlayerLeaveRaceCheckpoint ac_OnPlayerLeaveRaceCheckpoint
	#if defined ac_OnPlayerLeaveRaceCheckpoint
		forward ac_OnPlayerLeaveRaceCheckpoint(playerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
#else
	public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][23] + ac_Mtfc[23][0])
		{
			ac_FloodDetect(playerid, 23);
			return 1;
		}
		if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][23] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][23] = ac_gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerClickPlayerTextDraw
		return ac_OnPlayerClickPlayerTextDraw(playerid, playertextid);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerClickPlayerTextDra\
		|| defined _ALS_OnPlayerClickPlayerTD
		#undef OnPlayerClickPlayerTextDraw
	#else
		#define _ALS_OnPlayerClickPlayerTD
	#endif
	#define OnPlayerClickPlayerTextDraw ac_OnPlayerClickPlayerTextDraw
	#if defined ac_OnPlayerClickPlayerTextDraw
		forward ac_OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnVehDamageStatusUpd(vehicleid, playerid)
#else
	public OnVehicleDamageStatusUpdate(vehicleid, playerid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][24] + ac_Mtfc[24][0]) ac_FloodDetect(playerid, 24);
		else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][24] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][24] = ac_gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnVehicleDamageStatusUpdate
		return ac_OnVehicleDamageStatusUpdate(vehicleid, playerid);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnVehicleDamageStatusUpdat\
		|| defined _ALS_OnVehicleDamageStatusUpd
		#undef OnVehicleDamageStatusUpdate
	#else
		#define _ALS_OnVehicleDamageStatusUpd
	#endif
	#define OnVehicleDamageStatusUpdate ac_OnVehicleDamageStatusUpdate
	#if defined ac_OnVehicleDamageStatusUpdate
		forward ac_OnVehicleDamageStatusUpdate(vehicleid, playerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnVehicleSirenChange(playerid, vehicleid, newstate)
#else
	public OnVehicleSirenStateChange(playerid, vehicleid, newstate)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	if(!IsPlayerNPC(playerid))
	{
		new ac_gtc = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_gtc < ACInfo[playerid][acCall][25] + ac_Mtfc[25][0]) ac_FloodDetect(playerid, 25);
			else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][25] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][25] = ac_gtc;
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnVehicleSirenStateChange
		return ac_OnVehicleSirenStateChange(playerid, vehicleid, newstate);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnVehicleSirenStateChange
		#undef OnVehicleSirenStateChange
	#else
		#define _ALS_OnVehicleSirenStateChange
	#endif
	#define OnVehicleSirenStateChange ac_OnVehicleSirenStateChange
	#if defined ac_OnVehicleSirenStateChange
		forward ac_OnVehicleSirenStateChange(playerid, vehicleid, newstate);
	#endif
#endif

#if defined OnPlayerSelectDynamicObject
	#if defined _inc_y_hooks || defined _INC_y_hooks
		#if defined STREAMER_ENABLE_TAGS
			hook OnPlayerSelectDynObject(playerid, STREAMER_TAG_OBJECT objectid, modelid, Float:x, Float:y, Float:z)
		#else
			hook OnPlayerSelectDynObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
		#endif
	#else
		#if defined STREAMER_ENABLE_TAGS
			public OnPlayerSelectDynamicObject(playerid, STREAMER_TAG_OBJECT objectid, modelid, Float:x, Float:y, Float:z)
		#else
			public OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
		#endif
	#endif
	{
		if(ACInfo[playerid][acKicked] > 0) return 0;
		new ac_gtc = GetTickCount();
		if(ACInfo[playerid][acACAllow][49])
		{
			if(ac_gtc < ACInfo[playerid][acCall][26] + ac_Mtfc[26][0]) ac_FloodDetect(playerid, 26);
			else if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
			else ACInfo[playerid][acFloodCount][26] = ACInfo[playerid][acFloodCount][27] = 0;
		}
		ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][26] = ac_gtc;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnPlayerSelectDynamicObject
			return ac_OnPlayerSelectDynamicObject(playerid, objectid, modelid, x, y, z);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnPlayerSelectDynamicObjec\
			|| defined _ALS_OnPlayerSelectDynObject || defined _ALS_OnPlayerSelectDynamicObj
			#undef OnPlayerSelectDynamicObject
		#else
			#define _ALS_OnPlayerSelectDynObject
		#endif
		#define OnPlayerSelectDynamicObject ac_OnPlayerSelectDynamicObject
		#if defined ac_OnPlayerSelectDynamicObject
			#if defined STREAMER_ENABLE_TAGS
				forward ac_OnPlayerSelectDynamicObject(playerid, STREAMER_TAG_OBJECT objectid, modelid, Float:x, Float:y, Float:z);
			#else
				forward ac_OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z);
			#endif
		#endif
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ)
#else
	public OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	new ac_gtc = GetTickCount();
	if(ACInfo[playerid][acACAllow][49])
	{
		if(ac_gtc < ACInfo[playerid][acCall][26] + ac_Mtfc[26][0])
		{
			ac_FloodDetect(playerid, 26);
			return 1;
		}
		if(ac_gtc < ACInfo[playerid][acCall][27] + ac_Mtfc[27][0]) ac_FloodDetect(playerid, 27);
		else ACInfo[playerid][acFloodCount][26] = ACInfo[playerid][acFloodCount][27] = 0;
	}
	ACInfo[playerid][acCall][27] = ACInfo[playerid][acCall][26] = ac_gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerSelectObject
		return ac_OnPlayerSelectObject(playerid, type, objectid, modelid, fX, fY, fZ);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerSelectObject
		#undef OnPlayerSelectObject
	#else
		#define _ALS_OnPlayerSelectObject
	#endif
	#define OnPlayerSelectObject ac_OnPlayerSelectObject
	#if defined ac_OnPlayerSelectObject
		forward ac_OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnUnoccupiedVehicleUpd(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z)
#else
	public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	if(ACInfo[playerid][acACAllow][31] &&
	(floatcmp(new_x, new_x) != 0 || floatcmp(new_y, new_y) != 0 || floatcmp(new_z, new_z) != 0 ||
	floatcmp(vel_x, vel_x) != 0 || floatcmp(vel_y, vel_y) != 0 || floatcmp(vel_z, vel_z) != 0 ||
	floatcmp(floatabs(new_x), 25000.0) >= 0 || floatcmp(floatabs(new_y), 25000.0) >= 0 || floatcmp(floatabs(new_z), 25000.0) >= 0 ||
	floatcmp(floatabs(vel_x), 100.0) >= 0 || floatcmp(floatabs(vel_y), 100.0) >= 0 || floatcmp(floatabs(vel_z), 100.0) >= 0))
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Pos x, y, z: %f, %f, %f, vel x, y, z: %f, %f, %f", new_x, new_y, new_z, vel_x, vel_y, vel_z);
		#endif
		return ac_KickWithCode(playerid, "", 0, 31, 2);
	}
	new Float:ac_X, Float:ac_Y, Float:ac_Z, Float:ac_dist = GetVehicleDistanceFromPoint(vehicleid, new_x, new_y, new_z);
	GetVehiclePos(vehicleid, ac_X, ac_Y, ac_Z);
	if(passenger_seat > 0)
	{
		new Float:ac_zDiff = floatsub(new_z, ac_Z);
		if(ACInfo[playerid][acACAllow][31] &&
		((floatcmp(vel_z, ACVehInfo[vehicleid][acVelZ]) == 1 || floatcmp(ac_zDiff, -0.8) >= 0) &&
		(floatcmp(floatabs(vel_x), floatabs(ACVehInfo[vehicleid][acVelX])) >= 0 && floatcmp(floatabs(ACVehInfo[vehicleid][acVelX]), 0.3) >= 0 ||
		floatcmp(floatabs(vel_y), floatabs(ACVehInfo[vehicleid][acVelY])) >= 0 && floatcmp(floatabs(ACVehInfo[vehicleid][acVelY]), 0.3) >= 0) ||
		floatcmp(ac_zDiff, -5.0) >= 0 && (floatcmp(floatabs(floatsub(new_x, ac_X)), 15.0) >= 0 ||
		floatcmp(floatabs(floatsub(new_y, ac_Y)), 15.0) >= 0)))
		{
			if(++ACInfo[playerid][acCheatCount][4] > AC_MAX_CARSHOT_WARNINGS)
			{
				#undef AC_MAX_CARSHOT_WARNINGS
				#if defined DEBUG
					printf("[Nex-AC debug] Vel x, y: %f, %f, old vel x, y: %f, %f, pos diff z: %f, veh: %d",
					vel_x, vel_y, ACVehInfo[vehicleid][acVelX], ACVehInfo[vehicleid][acVelY], ac_zDiff, vehicleid);
				#endif
				#if defined OnCheatDetected
					ac_KickWithCode(playerid, "", 0, 31, 1);
					if(ACInfo[playerid][acKicked] > 0) return 0;
					ACInfo[playerid][acCheatCount][4] = 0;
				#else
					return ac_KickWithCode(playerid, "", 0, 31, 1);
				#endif
			}
			#if defined OnCheatWarning
				else OnCheatWarning(playerid, "", 0, 31, 1, ACInfo[playerid][acCheatCount][4]);
			#endif
		}
		else if(ACInfo[playerid][acACAllow][8] &&
		floatcmp(vel_z, 0.1) >= 0 && floatcmp(vel_z, ACVehInfo[vehicleid][acVelZ]) == 1 &&
		floatcmp(floatabs(floatsub(ac_X, new_x)), floatdiv(ac_zDiff, 2.0)) == -1 && floatcmp(floatabs(floatsub(ac_Y, new_y)), floatdiv(ac_zDiff, 2.0)) == -1)
		{
			if(++ACInfo[playerid][acCheatCount][3] > AC_MAX_FLYHACK_VEH_WARNINGS)
			{
				#undef AC_MAX_FLYHACK_VEH_WARNINGS
				#if defined DEBUG
					printf("[Nex-AC debug] Vel z: %f, old vel z: %f, pos diff x, y, z: %f, %f, %f, veh: %d",
					vel_z, ACVehInfo[vehicleid][acVelZ], floatsub(ac_X, new_x), floatsub(ac_Y, new_y), ac_zDiff, vehicleid);
				#endif
				#if defined OnCheatDetected
					ac_KickWithCode(playerid, "", 0, 8, 2);
					if(ACInfo[playerid][acKicked] > 0) return 0;
					ACInfo[playerid][acCheatCount][3] = 0;
				#else
					return ac_KickWithCode(playerid, "", 0, 8, 2);
				#endif
			}
			#if defined OnCheatWarning
				else OnCheatWarning(playerid, "", 0, 8, 2, ACInfo[playerid][acCheatCount][3]);
			#endif
		}
		else
		{
			if(ACInfo[playerid][acCheatCount][4] > 0) ACInfo[playerid][acCheatCount][4]--;
			ACInfo[playerid][acCheatCount][3] = 0;
		}
	}
	if(ACInfo[playerid][acACAllow][5] &&
	floatcmp(ac_dist, 15.0) >= 0 && floatcmp(ac_Z, -45.0) == 1 &&
	floatcmp(ac_dist, floatadd(ACVehInfo[vehicleid][acPosDiff], floatmul(floatdiv(ac_dist, 3.0), 1.6))) == 1)
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Dist: %f, old pos diff: %f, pos z: %f, veh: %d, playerid: %d",
			ac_dist, ACVehInfo[vehicleid][acPosDiff], ac_Z, vehicleid, playerid);
		#endif
		#if defined OnCheatDetected
			ac_KickWithCode(playerid, "", 0, 5);
		#endif
		GetVehicleZAngle(vehicleid, ACVehInfo[vehicleid][acZAngle]);
		SetVehicleZAngle(vehicleid, ACVehInfo[vehicleid][acZAngle]);
		SetVehiclePos(vehicleid, ac_X, ac_Y, ac_Z);
		return 0;
	}
	new ac_a = 1;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnUnoccupiedVehicleUpdate
		ac_a = ac_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, new_x, new_y, new_z, vel_x, vel_y, vel_z);
	#endif
	if(ac_a)
	{
		ACVehInfo[vehicleid][acSpeedDiff] = ac_GetSpeed(vel_x, vel_y, vel_z) - ac_GetSpeed(ACVehInfo[vehicleid][acVelX], ACVehInfo[vehicleid][acVelY], ACVehInfo[vehicleid][acVelZ]);
		ACVehInfo[vehicleid][acPosDiff] = ac_dist;
		ACVehInfo[vehicleid][acPosX] = new_x;
		ACVehInfo[vehicleid][acPosY] = new_y;
		ACVehInfo[vehicleid][acPosZ] = new_z;
		ACVehInfo[vehicleid][acVelX] = vel_x;
		ACVehInfo[vehicleid][acVelY] = vel_y;
		ACVehInfo[vehicleid][acVelZ] = vel_z;
	}
	return ac_a;
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnUnoccupiedVehicleUpdate
		#undef OnUnoccupiedVehicleUpdate
	#else
		#define _ALS_OnUnoccupiedVehicleUpdate
	#endif
	#define OnUnoccupiedVehicleUpdate ac_OnUnoccupiedVehicleUpdate
	#if defined ac_OnUnoccupiedVehicleUpdate
		forward ac_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnTrailerUpdate(playerid, vehicleid)
#else
	public OnTrailerUpdate(playerid, vehicleid)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 0;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnTrailerUpdate
		return ac_OnTrailerUpdate(playerid, vehicleid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnTrailerUpdate
		#undef OnTrailerUpdate
	#else
		#define _ALS_OnTrailerUpdate
	#endif
	#define OnTrailerUpdate ac_OnTrailerUpdate
	#if defined ac_OnTrailerUpdate
		forward ac_OnTrailerUpdate(playerid, vehicleid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerEditAttachedObj(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
#else
	public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
#endif
{
	if(ACInfo[playerid][acKicked] > 0) return 1;
	if(ACInfo[playerid][acACAllow][46] && 384 <= modelid <= 393)
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Object modelid: %d", modelid);
		#endif
		ac_KickWithCode(playerid, "", 0, 46);
		return 1;
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerEditAttachedObject
		return ac_OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerEditAttachedObject
		#undef OnPlayerEditAttachedObject
	#else
		#define _ALS_OnPlayerEditAttachedObject
	#endif
	#define OnPlayerEditAttachedObject ac_OnPlayerEditAttachedObject
	#if defined ac_OnPlayerEditAttachedObject
		forward ac_OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ);
	#endif
#endif

#if defined PAWNRAKNET_INC_
	#if defined _inc_y_hooks || defined _INC_y_hooks
		hook OnIncomingPacket(playerid, packetid, BitStream:bs)
	#else
		public OnIncomingPacket(playerid, packetid, BitStream:bs)
	#endif
	{
		if(0 <= playerid < MAX_PLAYERS)
		{
			if(ACInfo[playerid][acKicked] > 0) return 0;
			if(packetid == 209)
			{
				new uData[PR_UnoccupiedSync];
				BS_IgnoreBits(bs, 8);
				BS_ReadUnoccupiedSync(bs, uData);
				if(floatcmp(uData[PR_roll][0], uData[PR_roll][0]) != 0 ||
				floatcmp(uData[PR_roll][1], uData[PR_roll][1]) != 0 ||
				floatcmp(uData[PR_roll][2], uData[PR_roll][2]) != 0 ||
				floatcmp(uData[PR_direction][0], uData[PR_direction][0]) != 0 ||
				floatcmp(uData[PR_direction][1], uData[PR_direction][1]) != 0 ||
				floatcmp(uData[PR_direction][2], uData[PR_direction][2]) != 0 ||
				floatcmp(uData[PR_angularVelocity][0], uData[PR_angularVelocity][0]) != 0 ||
				floatcmp(uData[PR_angularVelocity][1], uData[PR_angularVelocity][1]) != 0 ||
				floatcmp(uData[PR_angularVelocity][2], uData[PR_angularVelocity][2]) != 0 ||
				floatcmp(floatabs(uData[PR_roll][0]), 1.0) >= 0 ||
				floatcmp(floatabs(uData[PR_roll][1]), 1.0) >= 0 ||
				floatcmp(floatabs(uData[PR_roll][2]), 1.0) >= 0 ||
				floatcmp(floatabs(uData[PR_direction][0]), 1.0) >= 0 ||
				floatcmp(floatabs(uData[PR_direction][1]), 1.0) >= 0 ||
				floatcmp(floatabs(uData[PR_direction][2]), 1.0) >= 0 ||
				floatcmp(floatabs(uData[PR_angularVelocity][0]), 1.0) >= 0 ||
				floatcmp(floatabs(uData[PR_angularVelocity][1]), 1.0) >= 0 ||
				floatcmp(floatabs(uData[PR_angularVelocity][2]), 1.0) >= 0) return 0;
			}
		}
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnIncomingPacket
			return ac_OnIncomingPacket(playerid, packetid, bs);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnIncomingPacket
			#undef OnIncomingPacket
		#else
			#define _ALS_OnIncomingPacket
		#endif
		#define OnIncomingPacket ac_OnIncomingPacket
		#if defined ac_OnIncomingPacket
			forward ac_OnIncomingPacket(playerid, packetid, BitStream:bs);
		#endif
	#endif

	#if defined _inc_y_hooks || defined _INC_y_hooks
		hook OnIncomingRPC(playerid, rpcid, BitStream:bs)
	#else
		public OnIncomingRPC(playerid, rpcid, BitStream:bs)
	#endif
	{
		if(0 <= playerid < MAX_PLAYERS && ACInfo[playerid][acKicked] > 0 && ACInfo[playerid][acOnline]) return 0;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnIncomingRPC
			return ac_OnIncomingRPC(playerid, rpcid, bs);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnIncomingRPC
			#undef OnIncomingRPC
		#else
			#define _ALS_OnIncomingRPC
		#endif
		#define OnIncomingRPC ac_OnIncomingRPC
		#if defined ac_OnIncomingRPC
			forward ac_OnIncomingRPC(playerid, rpcid, BitStream:bs);
		#endif
	#endif
#endif

ac_fpublic ac_Timer(playerid)
{
	if(!IsPlayerConnected(playerid) || ACInfo[playerid][acKicked] > 0) return 0;
	new ac_gpp;
	if(ACInfo[playerid][acACAllow][51] && (ac_gpp = NetStats_MessagesRecvPerSecond(playerid)) > AC_MAX_MSGS_REC_DIFF)
	{
		#if defined DEBUG
			printf("[Nex-AC debug] Max msgs per sec: %d, msgs per sec: %d", AC_MAX_MSGS_REC_DIFF, ac_gpp);
		#endif
		#undef AC_MAX_MSGS_REC_DIFF
		ac_KickWithCode(playerid, "", 0, 51);
	}
	ac_gpp = GetPlayerPing(playerid);
	if(ACInfo[playerid][acACAllow][38])
	{
		if(ac_gpp > AC_MAX_PING && ac_gpp != 65535)
		{
			if(++ACInfo[playerid][acCheatCount][0] > AC_MAX_PING_WARNINGS)
			{
				#if defined DEBUG
					printf("[Nex-AC debug] Max ping: %d, ping: %d", AC_MAX_PING, ac_gpp);
				#endif
				#undef AC_MAX_PING
				#undef AC_MAX_PING_WARNINGS
				ac_KickWithCode(playerid, "", 0, 38);
				#if defined OnCheatDetected
					ACInfo[playerid][acCheatCount][0] = 0;
				#endif
			}
			#if defined OnCheatWarning
				else OnCheatWarning(playerid, "", 0, 38, 0, ACInfo[playerid][acCheatCount][0]);
			#endif
		}
		else ACInfo[playerid][acCheatCount][0] = 0;
	}
	new ac_gtc = GetTickCount();
	if(ac_gtc < ACInfo[playerid][acUpdateTime] + 1500)
	{
		new ac_t, ac_s;
		#if AC_USE_AMMUNATIONS || AC_USE_CASINOS
			new ac_int = GetPlayerInterior(playerid);
		#endif
		#if AC_USE_PICKUP_WEAPONS\
			&& defined Streamer_GetDistanceToItem\
			&& defined Streamer_GetIntData
			new Float:ac_dist;
			if(ACInfo[playerid][acLastPickup] > MAX_PICKUPS)
			{
				new Float:ac_X, Float:ac_Y, Float:ac_Z;
				GetPlayerPos(playerid, ac_X, ac_Y, ac_Z);
				Streamer_GetDistanceToItem(ac_X, ac_Y, ac_Z, STREAMER_TYPE_PICKUP, ACInfo[playerid][acLastPickup] - MAX_PICKUPS, ac_dist);
				ac_t = Streamer_GetIntData(STREAMER_TYPE_PICKUP, ACInfo[playerid][acLastPickup] - MAX_PICKUPS, E_STREAMER_EXTRA_ID) - 100;
			}
		#endif
		if(!ACInfo[playerid][acDead] && (ac_s = GetPlayerWeapon(playerid)) != -1 && ac_gtc > ACInfo[playerid][acGtc][7] + ac_gpp)
		{
			#if AC_USE_AMMUNATIONS
				new ac_m;
			#endif
			ac_s = ac_wSlot[ac_s];
			for(new ac_i, ac_w, ac_a, bool:ac_cw; ac_i <= 12; ++ac_i)
			{
				GetPlayerWeaponData(playerid, ac_i, ac_w, ac_a);
				if(ac_w == 39) ac_cw = true;
				if(ac_s != ac_i)
				{
					if(ACInfo[playerid][acSetWeapon][ac_i] != -1)
					{
						if(ACInfo[playerid][acSetWeapon][ac_i] == ac_w)
						{
							if(ACInfo[playerid][acSet][3] == ac_w) ACInfo[playerid][acSet][3] = -1;
							ACInfo[playerid][acSetWeapon][ac_i] = -1;
							ACInfo[playerid][acWeapon][ac_i] = ac_w;
						}
						else if(ac_gtc > ACInfo[playerid][acGtcSetWeapon][ac_i] + ac_gpp)
						{
							if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][0])
							{
								if(++ACInfo[playerid][acNOPCount][0] > AC_MAX_NOP_TIMER_WARNINGS)
								{
									#if defined DEBUG
										printf(DEBUG_CODE_5, playerid, "GivePlayerWeapon");
										printf("[Nex-AC debug] AC weapon: %d, weaponid: %d", ACInfo[playerid][acSetWeapon][ac_i], ac_w);
									#endif
									ac_KickWithCode(playerid, "", 0, 52, 13);
									#if defined OnCheatDetected
										ACInfo[playerid][acSetWeapon][ac_i] = -1;
									#endif
								}
								#if defined OnNOPWarning
									else OnNOPWarning(playerid, 13, ACInfo[playerid][acNOPCount][0]);
								#endif
							}
							else if(++ACInfo[playerid][acNOPCount][0] > AC_MAX_NOP_TIMER_WARNINGS) ACInfo[playerid][acSetWeapon][ac_i] = -1;
						}
					}
					else
					{
						if(ACInfo[playerid][acWeapon][ac_i] != ac_w)
						{
							#if AC_USE_PICKUP_WEAPONS
								#if defined Streamer_GetDistanceToItem\
									&& defined Streamer_GetIntData
								if(0 <= ACInfo[playerid][acLastPickup] < MAX_PICKUPS &&
								ACPickInfo[ACInfo[playerid][acLastPickup]][acWeapon] == ac_w &&
								ac_a <= (3 <= ac_i <= 5 ? ACInfo[playerid][acAmmo][ac_i] + ac_pAmmo[ac_w] : ac_pAmmo[ac_w]) &&
								IsPlayerInRangeOfPoint(playerid, 15.0, ACPickInfo[ACInfo[playerid][acLastPickup]][acPosX],
								ACPickInfo[ACInfo[playerid][acLastPickup]][acPosY], ACPickInfo[ACInfo[playerid][acLastPickup]][acPosZ]) ||
								ACInfo[playerid][acLastPickup] > MAX_PICKUPS && ac_t == ac_w &&
								ac_a <= (3 <= ac_i <= 5 ? ACInfo[playerid][acAmmo][ac_i] + ac_pAmmo[ac_w] : ac_pAmmo[ac_w]) && floatcmp(ac_dist, 15.0) <= 0)
								{
									ACInfo[playerid][acWeapon][ac_i] = ac_w;
									ACInfo[playerid][acAmmo][ac_i] = ac_a;
								}
								#else
								if(0 <= ACInfo[playerid][acLastPickup] < MAX_PICKUPS &&
								ACPickInfo[ACInfo[playerid][acLastPickup]][acWeapon] == ac_w &&
								ac_a <= (3 <= ac_i <= 5 ? ACInfo[playerid][acAmmo][ac_i] + ac_pAmmo[ac_w] : ac_pAmmo[ac_w]) &&
								IsPlayerInRangeOfPoint(playerid, 15.0, ACPickInfo[ACInfo[playerid][acLastPickup]][acPosX],
								ACPickInfo[ACInfo[playerid][acLastPickup]][acPosY], ACPickInfo[ACInfo[playerid][acLastPickup]][acPosZ]))
								{
									ACInfo[playerid][acWeapon][ac_i] = ac_w;
									ACInfo[playerid][acAmmo][ac_i] = ac_a;
								}
								#endif
								else
								{
							#endif
								if(ac_w == 0 || ac_w == 40 && ac_cw ||
								ac_w == 46 && ACInfo[playerid][acVeh] > 0 && ACInfo[playerid][acParachute] > 0)
								{
									ACInfo[playerid][acWeapon][ac_i] = ac_w;
									ACInfo[playerid][acAmmo][ac_i] = ac_a;
									ACInfo[playerid][acParachute] = 0;
								}
								else if(ACInfo[playerid][acACAllow][15] && !(16 <= ac_w <= 43 && ac_a == 0))
								{
									#if defined DEBUG
										printf("[Nex-AC debug] AC weaponid: %d, AC ammo: %d, weaponid: %d, ammo: %d",
										ACInfo[playerid][acWeapon][ac_i], ACInfo[playerid][acAmmo][ac_i], ac_w, ac_a);
									#endif
									ac_KickWithCode(playerid, "", 0, 15, 2);
									#if defined OnCheatDetected
										if(ACInfo[playerid][acKicked] < 1)
										{
											ACInfo[playerid][acWeapon][ac_i] = ac_w;
											ACInfo[playerid][acAmmo][ac_i] = ac_a;
										}
									#endif
								}
							#if AC_USE_PICKUP_WEAPONS
								}
							#endif
							#undef AC_USE_PICKUP_WEAPONS
						}
						if(ACInfo[playerid][acGiveAmmo][ac_i] != -65535)
						{
							if(ACInfo[playerid][acGiveAmmo][ac_i] == ac_a ||
							ACInfo[playerid][acGiveAmmo][ac_i] > ac_a && ac_gtc > ACInfo[playerid][acGtcGiveAmmo][ac_i] + ac_gpp)
							{
								ACInfo[playerid][acGiveAmmo][ac_i] = -65535;
								ACInfo[playerid][acAmmo][ac_i] = ac_a;
							}
							else if(ac_gtc > ACInfo[playerid][acGtcGiveAmmo][ac_i] + ac_gpp)
							{
								if(ACInfo[playerid][acACAllow][52] && ACInfo[playerid][acNOPAllow][1])
								{
									if(++ACInfo[playerid][acNOPCount][1] > AC_MAX_NOP_TIMER_WARNINGS)
									{
										#if defined DEBUG
											printf(DEBUG_CODE_5, playerid, "SetPlayerAmmo");
											printf("[Nex-AC debug] AC ammo: %d, ammo: %d, weaponid: %d",
											ACInfo[playerid][acGiveAmmo][ac_i], ac_a, ac_w);
										#endif
										ac_KickWithCode(playerid, "", 0, 52, 14);
										#if defined OnCheatDetected
											ACInfo[playerid][acGiveAmmo][ac_i] = -65535;
										#endif
									}
									#if defined OnNOPWarning
										else OnNOPWarning(playerid, 14, ACInfo[playerid][acNOPCount][1]);
									#endif
								}
								else if(++ACInfo[playerid][acNOPCount][1] > AC_MAX_NOP_TIMER_WARNINGS) ACInfo[playerid][acGiveAmmo][ac_i] = -65535;
							}
						}
						else if(16 <= ac_w <= 43)
						{
							if(ac_a == 0) ACInfo[playerid][acAmmo][ac_i] = 0;
							else if(ACInfo[playerid][acACAllow][16] && ac_w != 40 &&
							(ac_a > ACInfo[playerid][acAmmo][ac_i] || ac_a < 0 <= ACInfo[playerid][acAmmo][ac_i]) &&
							(!ac_LagCompMode || ac_w != 38 && !(22 <= ac_w <= 34) || ac_gtc > ACInfo[playerid][acShotTime] + 3650))
							{
								#if defined DEBUG
									printf("[Nex-AC debug] AC ammo: %d, ammo: %d, weaponid: %d",
									ACInfo[playerid][acAmmo][ac_i], ac_a, ac_w);
								#endif
								ac_KickWithCode(playerid, "", 0, 16, 2);
								#if defined OnCheatDetected
									if(ACInfo[playerid][acKicked] < 1) ACInfo[playerid][acAmmo][ac_i] = ac_a;
								#endif
							}
						}
					}
				}
				else if(ac_w == 38 || 22 <= ac_w <= 34)
				{
					if((ac_a > ACInfo[playerid][acAmmo][ac_i] || ac_a < 0 <= ACInfo[playerid][acAmmo][ac_i]) &&
					ACInfo[playerid][acGiveAmmo][ac_i] == -65535)
					{
						#if AC_USE_AMMUNATIONS
							if(22 <= ac_w <= 32 && ac_InAmmuNation(playerid, ac_int) &&
							(ac_m = ac_a - ACInfo[playerid][acAmmo][ac_i]) % ac_AmmuNationInfo[ac_w - 22][1] == 0)
							{
								if(ACInfo[playerid][acSet][10] != -1) ACInfo[playerid][acSet][10] += ac_AmmuNationInfo[ac_w - 22][0] * (ac_m / ac_AmmuNationInfo[ac_w - 22][1]);
								else ACInfo[playerid][acSet][10] = ac_AmmuNationInfo[ac_w - 22][0] * (ac_m / ac_AmmuNationInfo[ac_w - 22][1]);
								ACInfo[playerid][acAmmo][ac_i] += ac_m;
								ACInfo[playerid][acGtc][15] = ac_gtc + 2650;
								ACInfo[playerid][acCheatCount][10] = 0;
							}
							else
							{
						#endif
							if(ACInfo[playerid][acACAllow][16] && (!ac_LagCompMode || ac_gtc > ACInfo[playerid][acShotTime] + 3650))
							{
								#if defined DEBUG
									printf("[Nex-AC debug] AC ammo: %d, ammo: %d, weaponid: %d",
									ACInfo[playerid][acAmmo][ac_i], ac_a, ac_w);
								#endif
								ac_KickWithCode(playerid, "", 0, 16, 3);
								#if defined OnCheatDetected
									if(ACInfo[playerid][acKicked] < 1) ACInfo[playerid][acAmmo][ac_i] = ac_a;
								#endif
							}
						#if AC_USE_AMMUNATIONS
							}
						#endif
					}
					else if(ACInfo[playerid][acAmmo][ac_i] != 0) ACInfo[playerid][acAmmo][ac_i] = ac_a;
				}
			}
		}
		if(ACInfo[playerid][acACAllow][35] && GetPlayerState(playerid) == PLAYER_STATE_DRIVER &&
		GetPlayerCameraMode(playerid) == 55) ac_KickWithCode(playerid, "", 0, 35);
		ac_t = bad_GetPlayerMoney(playerid);
		#if AC_USE_AMMUNATIONS
			if(ACInfo[playerid][acSet][10] != -1)
			{
				if(ac_t < ACInfo[playerid][acMoney] &&
				ACInfo[playerid][acSet][10] <= ACInfo[playerid][acMoney] - ac_t) ACInfo[playerid][acSet][10] = -1;
				else if(ac_gtc > ACInfo[playerid][acGtc][15] + ac_gpp)
				{
					if(ACInfo[playerid][acACAllow][15])
					{
						if(++ACInfo[playerid][acCheatCount][10] > AC_MAX_NOP_TIMER_WARNINGS)
						{
							#if defined DEBUG
								printf("[Nex-AC debug] Money: %d, old money: %d, price: %d",
								ac_t, ACInfo[playerid][acMoney], ACInfo[playerid][acSet][10]);
							#endif
							ac_KickWithCode(playerid, "", 0, 15, 4);
							#if defined OnCheatDetected
								ACInfo[playerid][acSet][10] = -1;
							#endif
						}
						#if defined OnCheatWarning
							else OnCheatWarning(playerid, "", 0, 15, 4, ACInfo[playerid][acCheatCount][10]);
						#endif
					}
					else if(++ACInfo[playerid][acCheatCount][10] > AC_MAX_NOP_TIMER_WARNINGS) ACInfo[playerid][acSet][10] = -1;
				}
			}
		#endif
		#if AC_USE_TUNING_GARAGES
			if(ACInfo[playerid][acSet][12] != -1)
			{
				if(ac_t < ACInfo[playerid][acMoney] &&
				ACInfo[playerid][acSet][12] <= ACInfo[playerid][acMoney] - ac_t) ACInfo[playerid][acSet][12] = -1;
				else if(ac_gtc > ACInfo[playerid][acGtc][17] + ac_gpp)
				{
					if(ACInfo[playerid][acACAllow][23])
					{
						if(++ACInfo[playerid][acCheatCount][12] > AC_MAX_NOP_TIMER_WARNINGS)
						{
							#if defined DEBUG
								printf("[Nex-AC debug] Money: %d, old money: %d, component price: %d",
								ac_t, ACInfo[playerid][acMoney], ACInfo[playerid][acSet][12]);
							#endif
							ac_KickWithCode(playerid, "", 0, 23, 6);
							#if defined OnCheatDetected
								ACInfo[playerid][acSet][12] = -1;
							#endif
						}
						#if defined OnCheatWarning
							else OnCheatWarning(playerid, "", 0, 23, 6, ACInfo[playerid][acCheatCount][12]);
						#endif
					}
					else if(++ACInfo[playerid][acCheatCount][12] > AC_MAX_NOP_TIMER_WARNINGS) ACInfo[playerid][acSet][12] = -1;
				}
			}
		#endif
		#undef AC_USE_TUNING_GARAGES
		#undef AC_MAX_NOP_TIMER_WARNINGS
		if(ACInfo[playerid][acNOPCount][11] > 0) ACInfo[playerid][acNOPCount][11]--;
		else
		{
			if(ACInfo[playerid][acACAllow][14] &&
			ac_t > ACInfo[playerid][acMoney] && (!ACInfo[playerid][acStuntBonus] || ACInfo[playerid][acVeh] == 0))
			{
				#if AC_USE_CASINOS
					if(!ac_InCasino(playerid, ac_int))
					{
				#endif
					#if defined DEBUG
						printf("[Nex-AC debug] AC money: %d, money: %d, stunt bonus: %d, veh: %d, playerid: %d",
						ACInfo[playerid][acMoney], ac_t, ACInfo[playerid][acStuntBonus], ACInfo[playerid][acVeh], playerid);
					#endif
					#if defined OnCheatDetected
						ac_KickWithCode(playerid, "", 0, 14);
					#endif
					ac_t = ACInfo[playerid][acMoney];
					ResetPlayerMoney(playerid);
					GivePlayerMoney(playerid, ac_t);
				#if AC_USE_CASINOS
					}
				#endif
			}
			ACInfo[playerid][acMoney] = ac_t;
		}
	}
	ACInfo[playerid][acCheatCount][1] = ACInfo[playerid][acCheatCount][2] = 0;
	if(ACInfo[playerid][acCheatCount][16] > 0) ACInfo[playerid][acCheatCount][16]--;
	#if defined SetPlayerTimerEx_
		ACInfo[playerid][acTimerID] = SetPlayerTimerEx_(playerid, "ac_Timer", 0, 1000, 1, "i", playerid);
	#else
		ACInfo[playerid][acTimerID] = SetTimerEx("ac_Timer", 1000, false, "i", playerid);
	#endif
	return 1;
}

//Don't make changes in this public
//To customize the punishments, declare 'OnCheatDetected' in your script
ac_fpublic ac_OnCheatDetected(playerid, ip_address[], type, code)
{
	if(type) BlockIpAddress(ip_address, 0);
	else
	{
		switch(code)
		{
			case 40: SendClientMessage(playerid, AC_DEFAULT_COLOR, MAX_CONNECTS_MSG);
			case 41: SendClientMessage(playerid, AC_DEFAULT_COLOR, UNKNOWN_CLIENT_MSG);
			default:
			{
				static ac_strtmp[sizeof KICK_MSG];
				format(ac_strtmp, sizeof ac_strtmp, KICK_MSG, code);
				SendClientMessage(playerid, AC_DEFAULT_COLOR, ac_strtmp);
				#undef AC_DEFAULT_COLOR
			}
		}
		AntiCheatKickWithDesync(playerid, code);
	}
	return 1;
}

ac_fpublic ac_KickTimer(playerid) return Kick(playerid);

#undef ac_fpublic

stock AntiCheatGetHealth(playerid, &Float:health)
{
	if(!IsPlayerConnected(playerid)) return 0;
	health = ACInfo[playerid][acHealth];
	return 1;
}

stock AntiCheatGetArmour(playerid, &Float:armour)
{
	if(!IsPlayerConnected(playerid)) return 0;
	armour = ACInfo[playerid][acArmour];
	return 1;
}

stock AntiCheatGetVehicleHealth(vehicleid, &Float:health)
{
	if(GetVehicleModel(vehicleid) < 400) return 0;
	health = ACVehInfo[vehicleid][acHealth];
	return 1;
}

stock AntiCheatGetWeaponData(playerid, slot, &weapons, &ammo)
{
	if(!IsPlayerConnected(playerid)) return 0;
	weapons = ACInfo[playerid][acWeapon][slot];
	ammo = ACInfo[playerid][acAmmo][slot];
	return 1;
}

stock AntiCheatGetSpawnPos(playerid, &Float:x, &Float:y, &Float:z)
{
	if(!IsPlayerConnected(playerid)) return 0;
	x = ACInfo[playerid][acSpawnPosX];
	y = ACInfo[playerid][acSpawnPosY];
	z = ACInfo[playerid][acSpawnPosZ];
	return 1;
}

stock AntiCheatGetSpawnWeapon(playerid, &weapon1, &weapon1_ammo, &weapon2, &weapon2_ammo, &weapon3, &weapon3_ammo)
{
	if(!IsPlayerConnected(playerid)) return 0;
	weapon1 = ACInfo[playerid][acSpawnWeapon1];
	weapon1_ammo = ACInfo[playerid][acSpawnAmmo1];
	weapon2 = ACInfo[playerid][acSpawnWeapon2];
	weapon2_ammo = ACInfo[playerid][acSpawnAmmo2];
	weapon3 = ACInfo[playerid][acSpawnWeapon3];
	weapon3_ammo = ACInfo[playerid][acSpawnAmmo3];
	return 1;
}

stock AntiCheatGetPos(playerid, &Float:x, &Float:y, &Float:z)
{
	if(!IsPlayerConnected(playerid)) return 0;
	x = ACInfo[playerid][acPosX];
	y = ACInfo[playerid][acPosY];
	z = ACInfo[playerid][acPosZ];
	return 1;
}

stock AntiCheatGetVehicleVelocity(vehicleid, &Float:x, &Float:y, &Float:z)
{
	if(GetVehicleModel(vehicleid) < 400) return 0;
	x = ACVehInfo[vehicleid][acVelX];
	y = ACVehInfo[vehicleid][acVelY];
	z = ACVehInfo[vehicleid][acVelZ];
	return 1;
}

static ac_IsAnAircraft(modelid) return (417 <= modelid <= 593 && 1 <= ac_vType[modelid - 400] <= 2);

static ac_IsABoat(modelid) return (430 <= modelid <= 595 && ac_vType[modelid - 400] == 3);

static ac_IsABicycle(modelid) return (481 <= modelid <= 510 && ac_vType[modelid - 400] == 4);

static ac_IsABike(modelid) return (448 <= modelid <= 586 && 4 <= ac_vType[modelid - 400] <= 5);

static ac_GetSpeed(Float:ac_x, Float:ac_y, Float:ac_z = 0.0) return floatround(floatmul(VectorSize(ac_x, ac_y, ac_z), 179.28625));

static ac_IsVehicleSeatOccupied(vehicleid, seat)
{
	#if defined foreach
		foreach(new ac_i : Player)
		{
			if(ACInfo[ac_i][acVeh] == vehicleid && ACInfo[ac_i][acSeat] == seat) return 1;
		}
	#else
		for(new ac_i = GetPlayerPoolSize(); ac_i >= 0; --ac_i)
		{
			if(IsPlayerInVehicle(ac_i, vehicleid) && ACInfo[ac_i][acSeat] == seat) return 1;
		}
	#endif
	return 0;
}

#if AC_USE_RESTAURANTS
	static ac_InRestaurant(playerid, interiorid)
	{
		new ac_i;
		switch(interiorid)
		{
			case 5: ac_i = 0;
			case 9: ac_i = 1;
			case 10: ac_i = 2;
			default: return 0;
		}
		return IsPlayerInRangeOfPoint(playerid, 3.0, ac_Restaurants[ac_i][0], ac_Restaurants[ac_i][1], ac_Restaurants[ac_i][2]);
	}
#endif
#undef AC_USE_RESTAURANTS

#if AC_USE_AMMUNATIONS
	static ac_InAmmuNation(playerid, interiorid)
	{
		new ac_i, ac_s;
		switch(interiorid)
		{
			case 1: ac_i = 0, ac_s = -1;
			case 4: ac_i = 1, ac_s = 0;
			case 6: ac_i = 3, ac_s = 1;
			default: return 0;
		}
		for(; ac_i > ac_s; --ac_i)
		{
			if(IsPlayerInRangeOfPoint(playerid, 3.0, ac_AmmuNations[ac_i][0],
			ac_AmmuNations[ac_i][1], ac_AmmuNations[ac_i][2])) return 1;
		}
		return 0;
	}
#endif
#undef AC_USE_AMMUNATIONS

#if AC_USE_PAYNSPRAY
	static ac_InPayNSpray(playerid, interiorid)
	{
		if(interiorid == 0)
		{
			for(new ac_i = sizeof(ac_PayNSpray) - 1; ac_i >= 0; --ac_i)
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.5, ac_PayNSpray[ac_i][0], ac_PayNSpray[ac_i][1], ac_PayNSpray[ac_i][2])) return 1;
			}
		}
		return 0;
	}
#endif
#undef AC_USE_PAYNSPRAY

#if AC_USE_VENDING_MACHINES
	static ac_NearVendingMachine(playerid, interiorid)
	{
		new ac_i, ac_s;
		switch(interiorid)
		{
			case 0: ac_i = 44, ac_s = -1;
			case 1: ac_i = 51, ac_s = 44;
			case 2: ac_i = 52, ac_s = 51;
			case 3: ac_i = 58, ac_s = 52;
			case 6: ac_i = 60, ac_s = 58;
			case 7: ac_i = 61, ac_s = 60;
			case 15: ac_i = 62, ac_s = 61;
			case 16: ac_i = 65, ac_s = 62;
			case 17: ac_i = 72, ac_s = 65;
			case 18: ac_i = 74, ac_s = 72;
			default: return 0;
		}
		for(; ac_i > ac_s; --ac_i)
		{
			if(IsPlayerInRangeOfPoint(playerid, 1.5, ac_vMachines[ac_i][0], ac_vMachines[ac_i][1], ac_vMachines[ac_i][2])) return 1;
		}
		return 0;
	}
#endif
#undef AC_USE_VENDING_MACHINES

#if AC_USE_CASINOS
	static ac_InCasino(playerid, interiorid)
	{
		new ac_i, ac_s;
		switch(interiorid)
		{
			case 1: ac_i = 41, ac_s = -1;
			case 10: ac_i = 61, ac_s = 41;
			case 12: ac_i = 70, ac_s = 61;
			default: return 0;
		}
		for(; ac_i > ac_s; --ac_i)
		{
			if(IsPlayerInRangeOfPoint(playerid, ac_Casinos[ac_i][3], ac_Casinos[ac_i][0],
			ac_Casinos[ac_i][1], ac_Casinos[ac_i][2])) return 1;
		}
		return 0;
	}
#endif
#undef AC_USE_CASINOS

static ac_IsCompatible(modelid, componentid)
{
	if(modelid > 0)
	{
		switch(componentid)
		{
			case 1000..1191:
			{
				componentid -= 1000;
				if(ac_vMods[(modelid - 400) * 6 + (componentid >>> 5)] & 1 << (componentid & 0b00011111)) return 1;
			}
			case 1192, 1193:
			{
				if(modelid == 576) return 1;
			}
		}
	}
	return 0;
}

static ac_GetMaxPassengers(modelid)
{
	if(modelid > 0)
	{
		modelid -= 400;
		return ((ac_MaxPassengers[modelid >>> 3] >>> ((modelid & 7) << 2)) & 0xF);
	}
	return 0xF;
}

static ac_IpToInt(const s_szIP[])
{
	new ac_aiBytes[1], ac_iPos;
	ac_aiBytes{0} = strval(s_szIP[ac_iPos]);
	while(ac_iPos < 15 && s_szIP[ac_iPos++] != '.'){}
	ac_aiBytes{1} = strval(s_szIP[ac_iPos]);
	while(ac_iPos < 15 && s_szIP[ac_iPos++] != '.'){}
	ac_aiBytes{2} = strval(s_szIP[ac_iPos]);
	while(ac_iPos < 15 && s_szIP[ac_iPos++] != '.'){}
	ac_aiBytes{3} = strval(s_szIP[ac_iPos]);
	return ac_aiBytes[0];
}

static ac_FloodDetect(playerid, publicid)
{
	if(ACInfo[playerid][acKicked] < 1)
	{
		if(++ACInfo[playerid][acFloodCount][publicid] > ac_Mtfc[publicid][1])
		{
			#if defined DEBUG
				printf(DEBUG_CODE_1, playerid, ac_Mtfc[publicid][1], publicid);
				#if !defined mysql_included
					#undef DEBUG
				#endif
			#endif
			#if defined OnCheatDetected
				ac_KickWithCode(playerid, "", 0, 49, publicid);
				ACInfo[playerid][acFloodCount][publicid] = ACInfo[playerid][acFloodCount][27] = 0;
			#else
				return ac_KickWithCode(playerid, "", 0, 49, publicid);
			#endif
		}
		#if defined OnFloodWarning
			else OnFloodWarning(playerid, publicid, ACInfo[playerid][acFloodCount][publicid]);
		#endif
		ACInfo[playerid][acCall][publicid] = ACInfo[playerid][acCall][27] = GetTickCount();
	}
	return 0;
}

static ac_KickWithCode(playerid, ip_address[], type, code, code2 = 0)
{
	if(type == 0 && (!IsPlayerConnected(playerid) || ACInfo[playerid][acKicked] > 0)) return 0;
	ac_sInfo[5]++;
	switch(code)
	{
		case 0..35, 37, 39, 51: ac_sInfo[0]++;
		case 36, 38, 40, 41, 50: ac_sInfo[4]++;
		case 42: ac_sInfo[1]++;
		case 47..49: ac_sInfo[3]++;
		case 43..46: ac_sInfo[2]++;
	}
	#if defined NO_SUSPICION_LOGS
		#pragma unused code2
	#else
		new ac_strtmp[6];
		if(code2) format(ac_strtmp, sizeof ac_strtmp, " (%d)", code2);
		if(type) printf(SUSPICION_2, ip_address, code, ac_strtmp);
		else printf(SUSPICION_1, playerid, code, ac_strtmp);
	#endif
	#if defined OnCheatDetected
		OnCheatDetected(playerid, ip_address, type, code);
	#else
		ac_OnCheatDetected(playerid, ip_address, type, code);
	#endif
	return 0;
}

static ac_LoadCfg()
{
	static ac_strtmp[10];
	new ac_i, ac_string[415], File:ac_cfgFile;
	if(fexist(AC_CONFIG_FILE))
	{
		if((ac_cfgFile = fopen(AC_CONFIG_FILE, io_read)))
		{
			#if defined sscanf
				new ac_j;
			#endif
			while(fread(ac_cfgFile, ac_string) > 0)
			{
				#if defined sscanf
					sscanf(ac_string, "i'//'i", ac_j, ac_i);
					ac_ACAllow[ac_i] = !!ac_j;
				#else
					if((ac_i = strfind(ac_string, "//")) != -1)
					{
						strmid(ac_strtmp, ac_string, ac_i + 2, strlen(ac_string));
						if(0 <= (ac_i = strval(ac_strtmp)) < sizeof ac_ACAllow) ac_ACAllow[ac_i] = !!strval(ac_string);
					}
				#endif
			}
			fclose(ac_cfgFile);
		}
		else return 0;
	}
	else if((ac_cfgFile = fopen(AC_CONFIG_FILE, io_write)))
	{
		#undef AC_CONFIG_FILE
		for(; ac_i < sizeof ac_ACAllow; ++ac_i)
		{
			format(ac_strtmp, sizeof ac_strtmp, "%d //%d\r\n", ac_ACAllow[ac_i], ac_i);
			strcat(ac_string, ac_strtmp);
		}
		fwrite(ac_cfgFile, ac_string);
		fclose(ac_cfgFile);
	}
	else return 0;
	return 1;
}

#endif
