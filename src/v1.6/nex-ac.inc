//Nex-AC by Nexius v1.6 (0.3.7-R2)

#if defined _nex_ac_included
	#endinput
#endif
#define _nex_ac_included

#include <a_samp>

#if !defined GetConsoleVarAsInt
	#error Please download SA-MP 0.3.7 R2 server package!
#endif

#if !defined FILTERSCRIPT

//#define DEBUG

#include <nex-ac_en.lang>	//Localization

#define	NEX_AC_VERSION				"1.6"
#define AC_SERVER_VERSION			"0.3.7-R2"

#define CONFIG_FILE					"nex-ac_settings.cfg"
#define MAX_CLASSES					319
#define DEFAULT_COLOR				-1

#define USE_VENDING_MACHINES		true
#define USE_TUNING_GARAGES			true
#define USE_AMMUNATIONS				true
#define USE_RESTAURANTS				true
#define USE_PAYNSPRAY				true
#define USE_CASINOS					true

#define USE_QUERY					true

#define MAX_CONNECTS_FROM_IP		1
#define MAX_RCON_LOGIN_ATTEMPT		1
#define MAX_MSGS_REC_DIFF			799
#define MAX_PING					500
#define MIN_TIME_RECONNECT			12		//In seconds

#define MAX_NOP_WARNINGS			2
#define MAX_PING_WARNINGS			1
#define MAX_AIR_WARNINGS			2
#define MAX_AIR_VEH_WARNINGS		2
#define MAX_FLYHACK_VEH_WARNINGS	3
#define MAX_FLYHACK_BIKE_WARNINGS	5
#define MAX_CARSHOT_WARNINGS		3
#define MAX_PRO_AIM_WARNINGS		2
#define MAX_AFK_GHOST_WARNINGS		2
#define MAX_RAPID_FIRE_WARNINGS		2
#define MAX_GODMODE_WARNINGS		2
#define MAX_GODMODE_VEH_WARNINGS	2
#define MAX_SILENT_AIM_WARNINGS		2

#define GetSpeed(%0,%1,%2) floatround(VectorSize(%0, %1, %2) * 179.28625)
#define fpublic:%0(%1) forward %0(%1); public %0(%1)
#define abs(%1) (((%1) < 0) ? (-(%1)) : ((%1)))

static bool:ACAllow[] =
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
	true,	//24 Anti-Parkour mod
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

	true,	//36 Anti-Fake NPC
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
};

static const Mtfc[][] =
{
	{250, 3},	//0 OnDialogResponse
	{800, 2},	//1 OnEnterExitModShop
	{250, 3},	//2 OnPlayerClickMap
	{450, 2},	//3 OnPlayerClickPlayer
	{150, 3},	//4 OnPlayerClickTextDraw
	{400, 3},	//5 OnPlayerCommandText
	{150, 3},	//6 OnPlayerEnterVehicle
	{150, 3},	//7 OnPlayerExitVehicle
	{800, 5},	//8 OnPlayerPickUpPickup
	{150, 3},	//9 OnPlayerRequestClass
	{250, 3},	//10 OnPlayerSelectedMenuRow
	{600, 3},	//11 OnPlayerStateChange
	{530, 2},	//12 OnVehicleMod
	{530, 2},	//13 OnVehiclePaintjob
	{530, 2},	//14 OnVehicleRespray
	{300, 1},	//15 OnVehicleDeath
	{450, 2},	//16 OnPlayerText
	{500, 2},	//17 OnPlayerEnterCheckpoint
	{500, 2},	//18 OnPlayerLeaveCheckpoint
	{150, 3},	//19 OnPlayerRequestSpawn
	{250, 3},	//20 OnPlayerExitedMenu
	{500, 2},	//21 OnPlayerEnterRaceCheckpoint
	{500, 2},	//22 OnPlayerLeaveRaceCheckpoint
	{150, 3},	//23 OnPlayerClickPlayerTextDraw
	{51, 9},	//24 OnVehicleDamageStatusUpdate
	{150, 5},	//25 OnVehicleSirenStateChange
	{150, 3},	//26 OnPlayerSelectObject
	{150, 3}	//27 Cross-public
},

WeaponSlots[] =
{
	0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 10, 10,
	10, 8, 8, 8, 0, 0, 0, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5,
	4, 6, 6, 7, 7, 7, 7, 8, 12, 9, 9, 9, 11, 11, 11
},

WeaponModels[] =
{
	0, 331, 333, 334, 335, 336, 337, 338, 339, 341, 321, 322, 323, 324, 325,
	326, 342, 343, 344, 0, 0, 0, 346, 347, 348, 349, 350, 351, 352, 353, 355, 356,
	372, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 371
},

VehicleTypes[] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
	0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0, 0, 0, 3, 3,
	3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3, 3, 0, 0, 1, 0, 0, 0, 0,
	2, 0, 0, 3, 0, 0, 1, 1, 0, 0, 0, 0, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
},

ComponentPrices[] =
{
	400, 550, 200, 250, 100, 150, 80, 500, 500, 200, 1000, 220, 250, 100, 400,
	500, 200, 500, 350, 300, 250, 200, 150, 350, 50, 1000, 480, 0, 770, 680, 0,
	370, 170, 120, 790, 150, 500, 690, 190, 390, 0, 0, 1000, 500, 500, 510, 710,
	670, 530, 810, 620, 0, 0, 130, 210, 230, 520, 430, 620, 720, 530, 180, 0, 0,
	830, 850, 750, 250, 200, 550, 450, 0, 0, 1100, 1030, 980, 1560, 1620, 1200,
	1030, 900, 1230, 820, 1560, 1350, 770, 100, 1500, 150, 650, 450, 100, 750,
	350, 0, 0, 1000, 620, 1140, 0, 940, 0, 0, 3250, 1610, 1540, 780, 0, 780,
	1610, 1540, 0, 0, 3340, 3250, 2130, 2050, 2040, 780, 940, 0, 0, 780, 860,
	0, 1120, 3340, 3250, 3340, 1650, 3380, 3290, 1590, 830, 800, 1500, 1000, 0,
	580, 470, 870, 980, 0, 150, 0, 100, 490, 600, 890, 1000, 1090, 840, 910,
	1200, 1030, 1030, 920, 930, 550, 1050, 1050, 950, 650, 450, 550, 850, 950,
	850, 950, 970, 880, 990, 900, 950, 1000, 900, 1000, 900, 2050, 2150, 2130,
	2050, 2130, 2040, 2150, 2040, 2095, 2175, 2080, 2200, 1200, 1040, 940, 1100
},

MaxPassengers[] =
{
	0x10331113, 0x11311131, 0x11331313, 0x80133301, 0x1381F110,
	0x10311103, 0x10001F10, 0x11113311, 0x13113311, 0x31101100,
	0x30001301, 0x11031311, 0x11111331, 0x10013111, 0x01131100,
	0x11111110, 0x11100031, 0x11130221, 0x33113311, 0x11111101,
	0x33101133, 0x101001F0, 0x03133111, 0xFF11113F, 0x13330111,
	0xFF131111, 0x0000FF3F
},

VehicleMods[] =
{
	0x033C2700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x021A27FA, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x023B2785, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02BC4703, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x03BA278A, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x028E078A, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02310744, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x0228073A, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02BD4701, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x023A2780, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x0228077A, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x027A27CA, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x0282278A, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x023E07C0, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x03703730, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x031D2775, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02BE4788, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x02010771, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x029A0FCE, 0x00000000, 0x00FFFE00, 0x00000007, 0x0000C000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x03382700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x023F8795, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x029F078C, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x029627EA, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x0236C782, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x029E1FCA, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0xFC000437, 0x00000000, 0x021C0000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x03FE6007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00001B87, 0x00000001, 0x01E00000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x039E07D2, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x023CC700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00030000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x038E07D6, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x023D0709, 0x00000000, 0x00FFFE00, 0x00000007, 0x0000C000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x029E1F8A, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x029C077A, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x02BD076C, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0xFFFFFE00, 0x00000007, 0x00000000, 0x000001F8,
	0x02000700, 0x00000000, 0x00FFFFFE, 0x00000007, 0xC0000000, 0x00002007,
	0xFE000700, 0x00000003, 0x00FFFE00, 0x00000007, 0x00003C00, 0x00000600,
	0xCE000700, 0xFF800000, 0x00FFFE01, 0x00000007, 0x3C000000, 0x00000000,
	0x02000700, 0x000003FC, 0x00FFFE00, 0x00000007, 0x003C0000, 0x00001800,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x007FE000, 0x00FFFE00, 0x00000007, 0x03C00000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000047, 0x0000003E, 0x3C000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00001C00, 0x00FFFE00, 0x0000000F, 0x00000000, 0x0003C000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x000003C0, 0xC0000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x029607C2, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x03FFE7CD, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x031727F1, 0x00000000, 0x00FFFE00, 0x00000007, 0x00030000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x025627F0, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x039E07C2, 0x00000000, 0x00FFFE00, 0x00000007, 0x0003C000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000,
	0x02000700, 0x00000000, 0x00FFFE00, 0x00000007, 0x00000000, 0x00000000
},

#if USE_AMMUNATIONS
	AmmuNationInfo[][] =
	{
		{200, 30},	//22 9mm
		{600, 30},	//23 Silenced 9mm
		{1200, 10},	//24 Desert Eagle
		{600, 15},	//25 Shotgun
		{800, 12},	//26 Sawnoff Shotgun
		{1000, 10},	//27 Combat Shotgun
		{500, 60},	//28 Micro SMG/Uzi
		{2000, 90},	//29 MP5
		{3500, 120},//30 AK-47
		{4500, 90},	//31 M4
		{300, 60}	//32 Tec-9
	},

	Float:AmmuNations[][] =
	{
		{296.5541, -38.5138, 1001.5156},
		{295.7008, -80.8109, 1001.5156},
		{290.1963, -109.7721, 1001.5156},
		{312.2592, -166.1385, 999.601}
	},
#endif

#if USE_RESTAURANTS
	Float:Restaurants[][] =
	{
		{374.0, -119.641, 1001.4922},
		{368.789, -6.857, 1001.8516},
		{375.566, -68.222, 1001.5151}
	},
#endif

#if USE_PAYNSPRAY
	Float:PayNSpray[][] =
	{
		{2064.2842, -1831.4736, 13.5469},
		{-2425.7822, 1022.1392, 50.3977},
		{-1420.5195, 2584.2305, 55.8433},
		{487.6401, -1739.9479, 11.1385},
		{1024.8651, -1024.087, 32.1016},
		{-1904.7019, 284.5968, 41.0469},
		{1975.2384, 2162.5088, 11.0703},
		{2393.4456, 1491.5537, 10.5616},
		{720.0854, -457.8807, 16.3359},
		{-99.9417, 1117.9048, 19.7417}
	},
#endif

#if USE_VENDING_MACHINES
	Float:VendingMachines[][] =
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

#if USE_CASINOS
	Float:Casinos[][] =
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

PickupAmmo[] =
{
	1,		//0 Fist
	1,		//1 Brass Knuckles
	1,		//2 Golf Club
	1,		//3 Nightstick
	1,		//4 Knife
	1,		//5 Baseball Bat
	1,		//6 Shovel
	1,		//7 Pool Cue
	1,		//8 Katana
	1,		//9 Chainsaw
	1,		//10 Purple Dildo
	1,		//11 Dildo
	1,		//12 Vibrator
	1,		//13 Silver Vibrator
	1,		//14 Flowers
	1,		//15 Cane
	8,		//16 Grenade
	8,		//17 Tear Gas
	8,		//18 Molotov Cocktail
	0,		//19
	0,		//20
	0,		//21
	30,		//22 9mm
	10,		//23 Silenced 9mm
	10,		//24 Desert Eagle
	15,		//25 Shotgun
	10,		//26 Sawnoff Shotgun
	10,		//27 Combat Shotgun
	60,		//28 Micro SMG/Uzi
	60,		//29 MP5
	80,		//30 AK-47
	80,		//31 M4
	60,		//32 Tec-9
	20,		//33 Country Rifle
	10,		//34 Sniper Rifle
	4,		//35 RPG
	3,		//36 HS Rocket
	100,	//37 Flamethrower
	100,	//38 Minigun
	5,		//39 Satchel Charge
	1,		//40 Detonator
	500,	//41 Spraycan
	200,	//42 Fire Extinguisher
	32,		//43 Camera
	1,		//44 Night Vis Goggles
	1,		//45 Thermal Goggles
	1		//46 Parachute
};

enum ACInfo
{
	Float:acPos[3],
	Float:acDropJP[3],
	Float:acSetPos[3],
	Float:acSetVehHealth,
	Float:acSpeed,
	acHealth,
	acArmour,
	acMoney,
	acClassid,
	acLastShot,
	acLastWeapon,
	acEnterVehTime,
	acEnterVeh,
	acVeh,
	acSeat,
	acDialog,
	acAnim,
	acReload,
	acDmgRes,
	acSpecAct,
	acNextSpecAct,
	acLastSpecAct,
	acLastPickup,
	acShotTime,
	acSpawnTime,
	acLastUpdate,
	acTimerID,
	acKicked,
	acIp[16],
	acSet[14],
	acGtc[18],
	acWeapon[13],
	acAmmo[13],
	acSetWeapon[13],
	acGiveAmmo[13],
	acSpawnWeapon[3],
	acSpawnAmmo[3],
	acGtcSetWeapon[13],
	acGtcGiveAmmo[13],
	acNOPCount[11],
	acCheatCount[14],
	acCall[sizeof Mtfc],
	acFloodCount[sizeof Mtfc],
	bool:acACAllow[sizeof ACAllow],
	bool:acStuntBonus,
	bool:acModShop,
	bool:acFreeze,
	bool:acOnline,
	bool:acSpawnRes,
	bool:acDeathRes,
	bool:acVehDmgRes,
	bool:acDead,
	bool:acTpToZ,
	bool:acPicked,
	bool:acParachute,
	bool:acIntEnterExits
}

enum ACVehInfo
{
	Float:acVel[3],
	Float:acSpeedDiff,
	Float:acPosDiff,
	Float:acZAngle,
	Float:acHealth,
	acDriver,
	acInt,
	acPaintJob,
	bool:acSpawned
}

enum ACPickInfo
{
	Float:acPos[3],
	acType,
	acWeapon,
	bool:acIsStatic
}

enum ACDPickInfo
{
	Float:acPos[3],
	acType,
	acWeapon
}

static
	StatsInfo[6],
	Class[MAX_CLASSES][3][2],
	AntiCheatInfo[MAX_PLAYERS][ACInfo],
	AntiCheatVehInfo[MAX_VEHICLES][ACVehInfo],
	AntiCheatPickInfo[MAX_PICKUPS][ACPickInfo],
	AntiCheatDPickInfo[MAX_PICKUPS][ACDPickInfo],
	bool:IntEnterExits = true,
	bool:StuntBonus = true,
	bool:VehFriendlyFire,
	bool:LagCompMode,
	#if !USE_QUERY
		bool:QueryEnable,
	#endif
	bool:RconEnable,
	bool:PedAnims;

fpublic: ac_AddStaticVehicle(vehicleid)
{
	AntiCheatVehInfo[vehicleid][acInt] = 0;
	AntiCheatVehInfo[vehicleid][acPaintJob] = 3;
	AntiCheatVehInfo[vehicleid][acSpawned] = true;
	AntiCheatVehInfo[vehicleid][acHealth] = 1000.0;
	AntiCheatVehInfo[vehicleid][acSpeedDiff] =
	AntiCheatVehInfo[vehicleid][acPosDiff] =
	AntiCheatVehInfo[vehicleid][acVel][0] =
	AntiCheatVehInfo[vehicleid][acVel][1] =
	AntiCheatVehInfo[vehicleid][acVel][2] = 0.0;
	AntiCheatVehInfo[vehicleid][acDriver] = 65535;
	return 1;
}

fpublic: ac_CreateVehicle(vehicleid, vehicletype)
{
	AntiCheatVehInfo[vehicleid][acInt] = 0;
	AntiCheatVehInfo[vehicleid][acPaintJob] = 3;
	AntiCheatVehInfo[vehicleid][acHealth] = 1000.0;
	AntiCheatVehInfo[vehicleid][acSpeedDiff] =
	AntiCheatVehInfo[vehicleid][acPosDiff] =
	AntiCheatVehInfo[vehicleid][acVel][0] =
	AntiCheatVehInfo[vehicleid][acVel][1] =
	AntiCheatVehInfo[vehicleid][acVel][2] = 0.0;
	if(!(568 < vehicletype < 571)) AntiCheatVehInfo[vehicleid][acSpawned] = true;
	AntiCheatVehInfo[vehicleid][acDriver] = 65535;
	return 1;
}

fpublic: ac_AddPlayerClass(classid, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	Class[classid][0][0] = weapon1;
	Class[classid][0][1] = weapon1_ammo;
	Class[classid][1][0] = weapon2;
	Class[classid][1][1] = weapon2_ammo;
	Class[classid][2][0] = weapon3;
	Class[classid][2][1] = weapon3_ammo;
	return 1;
}

fpublic: ac_SetSpawnInfo(playerid, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	AntiCheatInfo[playerid][acSpawnWeapon][0] = weapon1;
	AntiCheatInfo[playerid][acSpawnAmmo][0] = weapon1_ammo;
	AntiCheatInfo[playerid][acSpawnWeapon][1] = weapon2;
	AntiCheatInfo[playerid][acSpawnAmmo][1] = weapon2_ammo;
	AntiCheatInfo[playerid][acSpawnWeapon][2] = weapon3;
	AntiCheatInfo[playerid][acSpawnAmmo][2] = weapon3_ammo;
	return 1;
}

fpublic: ac_AddStaticPickup(pickupid, model, type, Float:X, Float:Y, Float:Z)
{
	AntiCheatPickInfo[pickupid][acWeapon] = 0;
	switch(type)
	{
		case 2, 3, 15, 22:
		{
			switch(model)
			{
				case 370: AntiCheatPickInfo[pickupid][acType] = 2;
				case 1240: AntiCheatPickInfo[pickupid][acType] = 3;
				case 1242: AntiCheatPickInfo[pickupid][acType] = 4;
				case 321..369, 371, 372:
				{
					for(new i = 46; i != -1; --i)
					{
						if(WeaponModels[i] == model)
						{
							AntiCheatPickInfo[pickupid][acType] = 1;
							AntiCheatPickInfo[pickupid][acWeapon] = i;
							break;
						}
					}
				}
			}
		}
	}
	AntiCheatPickInfo[pickupid][acIsStatic] = true;
	AntiCheatPickInfo[pickupid][acPos][0] = X;
	AntiCheatPickInfo[pickupid][acPos][1] = Y;
	AntiCheatPickInfo[pickupid][acPos][2] = Z;
	return 1;
}

fpublic: ac_CreatePickup(pickupid, model, type, Float:X, Float:Y, Float:Z)
{
	AntiCheatPickInfo[pickupid][acWeapon] = 0;
	switch(type)
	{
		case 2, 3, 15, 22:
		{
			switch(model)
			{
				case 370: AntiCheatPickInfo[pickupid][acType] = 2;
				case 1240: AntiCheatPickInfo[pickupid][acType] = 3;
				case 1242: AntiCheatPickInfo[pickupid][acType] = 4;
				case 321..369, 371, 372:
				{
					for(new i = 46; i != -1; --i)
					{
						if(WeaponModels[i] == model)
						{
							AntiCheatPickInfo[pickupid][acType] = 1;
							AntiCheatPickInfo[pickupid][acWeapon] = i;
							break;
						}
					}
				}
			}
		}
	}
	AntiCheatPickInfo[pickupid][acIsStatic] = false;
	AntiCheatPickInfo[pickupid][acPos][0] = X;
	AntiCheatPickInfo[pickupid][acPos][1] = Y;
	AntiCheatPickInfo[pickupid][acPos][2] = Z;
	return 1;
}

#if defined STREAMER_ENABLE_TAGS
	fpublic: STREAMER_TAG_PICKUP ac_CreateDynamicPickup(pickupid, modelid, type, Float:x, Float:y, Float:z)
#else
	fpublic: ac_CreateDynamicPickup(pickupid, modelid, type, Float:x, Float:y, Float:z)
#endif
{
	switch(type)
	{
		case 2, 3, 15, 22:
		{
			switch(modelid)
			{
				case 370: AntiCheatDPickInfo[pickupid][acType] = 2;
				case 1240: AntiCheatDPickInfo[pickupid][acType] = 3;
				case 1242: AntiCheatDPickInfo[pickupid][acType] = 4;
				case 321..369, 371, 372:
				{
					for(new i = 46; i != -1; --i)
					{
						if(WeaponModels[i] == modelid)
						{
							AntiCheatDPickInfo[pickupid][acType] = 1;
							AntiCheatDPickInfo[pickupid][acWeapon] = i;
							break;
						}
					}
				}
			}
		}
	}
	AntiCheatDPickInfo[pickupid][acPos][0] = x;
	AntiCheatDPickInfo[pickupid][acPos][1] = y;
	AntiCheatDPickInfo[pickupid][acPos][2] = z;
}

fpublic: ac_DestroyVehicle(vehicleid)
{
	AntiCheatVehInfo[vehicleid][acSpawned] = false;
	return 1;
}

fpublic: ac_DestroyPickup(pickup)
{
	AntiCheatPickInfo[pickup][acType] = 0;
	return 1;
}

#if defined STREAMER_ENABLE_TAGS
	fpublic: ac_DestroyDynamicPickup(STREAMER_TAG_PICKUP pickupid)
#else
	fpublic: ac_DestroyDynamicPickup(pickupid)
#endif
{
	AntiCheatDPickInfo[pickupid][acType] = 0;
	return 1;
}

fpublic: ac_DestroyAllDynamicPickups()
{
	#if defined Streamer_GetUpperBound
		#if defined STREAMER_ENABLE_TAGS
			for(new STREAMER_TAG_PICKUP i = Streamer_GetUpperBound(1); i != -1; --i)
		#else
			for(new i = Streamer_GetUpperBound(1); i != -1; --i)
		#endif
	#else
		#if defined STREAMER_ENABLE_TAGS
			for(new STREAMER_TAG_PICKUP i = MAX_PICKUPS; i != -1; --i)
		#else
			for(new i = MAX_PICKUPS; i != -1; --i)
		#endif
	#endif
	{
		AntiCheatDPickInfo[i][acType] = 0;
	}
			return 1;
}

fpublic: ac_DisableInteriorEnterExits()
{
	IntEnterExits = false;
	return 1;
}

fpublic: ac_UsePlayerPedAnims()
{
	PedAnims = true;
	return 1;
}

fpublic: ac_EnableVehicleFriendlyFire()
{
	VehFriendlyFire = true;
	return 1;
}

fpublic: ac_EnableStuntBonusForAll(enable)
{
	StuntBonus = !!enable;
	#if defined foreach
		foreach(new i : Player)
	#else
		for(new i = GetPlayerPoolSize(); i != -1; --i)
		{
			if(IsPlayerConnected(i))
	#endif
	{
		AntiCheatInfo[i][acStuntBonus] = StuntBonus;
	}
	#if !defined foreach
		}
	#endif
	return 1;
}

fpublic: ac_EnableStuntBonusForPlayer(playerid, enable)
{
	AntiCheatInfo[playerid][acStuntBonus] = !!enable;
	return 1;
}

fpublic: ac_ShowPlayerDialog(playerid, dialogid)
{
	AntiCheatInfo[playerid][acDialog] = dialogid;
	return 1;
}

fpublic: ac_TogglePlayerControllable(playerid, toggle)
{
	AntiCheatInfo[playerid][acFreeze] = !!toggle;
	return 1;
}

fpublic: ac_TogglePlayerSpectating(playerid, toggle)
{
	if(GetPlayerState(playerid) == 9)
	{
		if(!toggle)
		{
			AntiCheatInfo[playerid][acSet][6] = 1;
			AntiCheatInfo[playerid][acNOPCount][8] = 0;
			AntiCheatInfo[playerid][acGtc][12] = GetTickCount();
			AntiCheatInfo[playerid][acSet][7] = 1;
			AntiCheatInfo[playerid][acNOPCount][9] = 0;
			AntiCheatInfo[playerid][acGtc][13] = AntiCheatInfo[playerid][acGtc][12];
		}
	}
	else if(toggle)
	{
		AntiCheatInfo[playerid][acSet][6] = 1;
		AntiCheatInfo[playerid][acNOPCount][8] = 0;
		AntiCheatInfo[playerid][acGtc][12] = GetTickCount();
	}
	return 1;
}

fpublic: ac_SpawnPlayer(playerid)
{
	AntiCheatInfo[playerid][acSet][7] = 1;
	AntiCheatInfo[playerid][acNOPCount][9] = 0;
	AntiCheatInfo[playerid][acGtc][13] = GetTickCount();
	return 1;
}

fpublic: ac_SetPlayerHealth(playerid, Float:health)
{
	if(health < 0.0) health = 0.0;
	AntiCheatInfo[playerid][acNOPCount][3] = 0;
	AntiCheatInfo[playerid][acSet][1] = floatround(health, floatround_tozero);
	AntiCheatInfo[playerid][acGtc][3] = GetTickCount();
	return 1;
}

fpublic: ac_SetPlayerArmour(playerid, Float:armour)
{
	if(armour < 0.0) armour = 0.0;
	AntiCheatInfo[playerid][acNOPCount][5] = 0;
	AntiCheatInfo[playerid][acSet][2] = floatround(armour, floatround_tozero);
	AntiCheatInfo[playerid][acGtc][5] = GetTickCount();
	return 1;
}

fpublic: ac_GivePlayerWeapon(playerid, weaponid, ammo)
{
	if(!(!AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]] && !ammo))
	{
		AntiCheatInfo[playerid][acNOPCount][0] =
		AntiCheatInfo[playerid][acNOPCount][1] = 0;
		if(15 < weaponid < 44)
		{
			if(2 < WeaponSlots[weaponid] < 6
			|| (AntiCheatInfo[playerid][acSetWeapon][WeaponSlots[weaponid]] ==
			-1 ? AntiCheatInfo[playerid][acWeapon][WeaponSlots[weaponid]]
			: AntiCheatInfo[playerid][acSetWeapon][WeaponSlots[weaponid]]) == weaponid)
			{
				AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[weaponid]] =
				(AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[weaponid]] == -65535
				? AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]]
				: AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[weaponid]]) + ammo;
			}
			else AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[weaponid]] = ammo;
			if(AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[weaponid]] < -32768) ammo =
			AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[weaponid]] = -32768;
			else if(AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[weaponid]] > 32767) ammo =
			AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[weaponid]] = 32767;
		}
		else AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[weaponid]] = -65535;
		AntiCheatInfo[playerid][acSet][3] =
		AntiCheatInfo[playerid][acSetWeapon][WeaponSlots[weaponid]] = weaponid;
	}
	GivePlayerWeapon(playerid, weaponid, ammo);
	AntiCheatInfo[playerid][acGtcGiveAmmo][WeaponSlots[weaponid]]
	= AntiCheatInfo[playerid][acGtcSetWeapon][WeaponSlots[weaponid]] =
	AntiCheatInfo[playerid][acGtc][2] = GetTickCount();
	return 1;
}

fpublic: ac_SetPlayerAmmo(playerid, weaponslot, ammo)
{
	if(ammo < -32768) ammo = -32768;
	else if(ammo > 32767) ammo = 32767;
	SetPlayerAmmo(playerid, weaponslot, ammo);
	if(15 < weaponslot < 44
	&& AntiCheatInfo[playerid][acWeapon][WeaponSlots[weaponslot]])
	{
		AntiCheatInfo[playerid][acNOPCount][1] = 0;
		AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[weaponslot]] = ammo;
		AntiCheatInfo[playerid][acGtcGiveAmmo][WeaponSlots[weaponslot]] = GetTickCount();
	}
	return 1;
}

fpublic: ac_SetPlayerArmedWeapon(playerid, weaponid)
{
	if(weaponid == AntiCheatInfo[playerid][acWeapon][WeaponSlots[weaponid]])
	{
		AntiCheatInfo[playerid][acNOPCount][0] = 0;
		AntiCheatInfo[playerid][acSet][3] = weaponid;
		AntiCheatInfo[playerid][acGtc][2] = GetTickCount();
	}
	return 1;
}

fpublic: ac_ResetPlayerWeapons(playerid)
{
	for(new i = 12; i != -1; --i)
	{
		AntiCheatInfo[playerid][acWeapon][i] =
		AntiCheatInfo[playerid][acAmmo][i] = 0;
		AntiCheatInfo[playerid][acSetWeapon][i] = -1;
		AntiCheatInfo[playerid][acGiveAmmo][i] = -65535;
	}
	AntiCheatInfo[playerid][acSet][3] = 0;
	AntiCheatInfo[playerid][acGtc][7] = GetTickCount();
	return 1;
}

fpublic: ac_GivePlayerMoney(playerid, money)
{
	AntiCheatInfo[playerid][acMoney] += money;
	return 1;
}

fpublic: ac_ResetPlayerMoney(playerid)
{
	AntiCheatInfo[playerid][acMoney] = 0;
	return 1;
}

fpublic: ac_GetPlayerMoney(playerid) return AntiCheatInfo[playerid][acMoney];

fpublic: ac_SetPlayerSpecialAction(playerid, actionid)
{
	if(actionid == 2 || actionid == 68 || 4 < actionid < 9
	|| 9 < actionid < 12 || 19 < actionid < 26 || !actionid
	&& AntiCheatInfo[playerid][acSpecAct] != 10 || actionid ==
	13 && AntiCheatInfo[playerid][acSpecAct] == 11)
	{
		AntiCheatInfo[playerid][acNOPCount][6] = 0;
		if((actionid == 68 || 9 < actionid < 12 || 19 <
		actionid < 26) && 4 < AntiCheatInfo[playerid][acSpecAct] <
		9) AntiCheatInfo[playerid][acNextSpecAct] = actionid;
		else
		{
			if(actionid == 13) actionid = 0;
			else if(actionid == 2) AntiCheatInfo[playerid][acNextSpecAct] =
			AntiCheatInfo[playerid][acSpecAct];
			else AntiCheatInfo[playerid][acNextSpecAct] = -1;
			AntiCheatInfo[playerid][acSet][4] = actionid;
			AntiCheatInfo[playerid][acGtc][6] = GetTickCount();
			if(AntiCheatInfo[playerid][acSpecAct] ==
			11) AntiCheatInfo[playerid][acGtc][6] += 2500;
		}
	}
	return 1;
}

fpublic: ac_SetPlayerInterior(playerid, interiorid)
{
	while(interiorid < 0) interiorid += 256;
	if(interiorid != GetPlayerInterior(playerid))
	{
		AntiCheatInfo[playerid][acNOPCount][2] = 0;
		if(AntiCheatInfo[playerid][acDead]) AntiCheatInfo[playerid][acSet][12] = interiorid;
		else AntiCheatInfo[playerid][acSet][0] = interiorid;
		AntiCheatInfo[playerid][acGtc][0] = GetTickCount();
	}
	return 1;
}

fpublic: ac_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
	AntiCheatInfo[playerid][acSet][8] = 1;
	AntiCheatInfo[playerid][acNOPCount][10] = 0;
	AntiCheatInfo[playerid][acSetPos][0] = AntiCheatInfo[playerid][acPos][0] = x;
	AntiCheatInfo[playerid][acSetPos][1] = AntiCheatInfo[playerid][acPos][1] = y;
	AntiCheatInfo[playerid][acSetPos][2] = AntiCheatInfo[playerid][acPos][2] = z;
	AntiCheatInfo[playerid][acGtc][11] = GetTickCount();
	return 1;
}

fpublic: ac_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z)
{
	AntiCheatInfo[playerid][acSet][8] = 1;
	AntiCheatInfo[playerid][acTpToZ] = true;
	AntiCheatInfo[playerid][acNOPCount][10] = 0;
	AntiCheatInfo[playerid][acSetPos][0] = AntiCheatInfo[playerid][acPos][0] = x;
	AntiCheatInfo[playerid][acSetPos][1] = AntiCheatInfo[playerid][acPos][1] = y;
	AntiCheatInfo[playerid][acGtc][11] = GetTickCount();
	return 1;
}

fpublic: ac_SetPlayerVelocity(playerid, Float:X, Float:Y, Float:Z)
{
	AntiCheatInfo[playerid][acSpeed] = GetSpeed(X,Y,Z);
	AntiCheatInfo[playerid][acGtc][10] = GetTickCount();
	return 1;
}

fpublic: ac_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
	if(AntiCheatVehInfo[vehicleid][acSpawned])
	{
		new model = GetVehicleModel(vehicleid) - 400;
		AntiCheatInfo[playerid][acNOPCount][7] = 0;
		AntiCheatInfo[playerid][acSet][9] = vehicleid;
		if(seatid > MaxPassengers[model >>> 3] >>> ((model
		& 7) << 2) & 0xF) AntiCheatInfo[playerid][acSet][5] = -1;
		else AntiCheatInfo[playerid][acSet][5] = seatid;
		AntiCheatInfo[playerid][acGtc][1] = GetTickCount();
	}
	return 1;
}

fpublic: ac_RemovePlayerFromVehicle(playerid)
{
	AntiCheatInfo[playerid][acSet][11] = 1;
	AntiCheatInfo[playerid][acGtc][8] = GetTickCount();
	return 1;
}

fpublic: ac_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z)
{
	AntiCheatVehInfo[vehicleid][acVel][0] =
	AntiCheatVehInfo[vehicleid][acVel][1] =
	AntiCheatVehInfo[vehicleid][acVel][2] = 0.0;
	if(AntiCheatVehInfo[vehicleid][acDriver] != 65535)
	{
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acSet][8] = 1;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acNOPCount][10] = 0;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acSetPos][0] =
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acPos][0] = x;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acSetPos][1] =
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acPos][1] = y;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acSetPos][2] =
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acPos][2] = z;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acGtc][11] =
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acGtc][9] = GetTickCount();
	}
	return 1;
}

fpublic: ac_SetVehicleVelocity(vehicleid, Float:X, Float:Y, Float:Z)
{
	if(AntiCheatVehInfo[vehicleid][acDriver] != 65535)
	{
		AntiCheatVehInfo[vehicleid][acVel][0] = X;
		AntiCheatVehInfo[vehicleid][acVel][1] = Y;
		AntiCheatVehInfo[vehicleid][acVel][2] = Z;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acGtc][9] = GetTickCount();
	}
	return 1;
}

fpublic: ac_SetVehicleAngularVelocity(vehicleid, Float:X, Float:Y, Float:Z)
{
	if(AntiCheatVehInfo[vehicleid][acDriver] != 65535)
	{
		AntiCheatVehInfo[vehicleid][acVel][0] = X;
		AntiCheatVehInfo[vehicleid][acVel][1] = Y;
		AntiCheatVehInfo[vehicleid][acVel][2] = Z;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acGtc][9] = GetTickCount();
	}
	return 1;
}

fpublic: ac_ChangeVehiclePaintjob(vehicleid, paintjobid)
{
	AntiCheatVehInfo[vehicleid][acPaintJob] = paintjobid;
	return 1;
}

fpublic: ac_SetVehicleHealth(vehicleid, Float:health)
{
	if(AntiCheatVehInfo[vehicleid][acDriver] != 65535)
	{
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acNOPCount][4] = 0;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acSetVehHealth] = health;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acGtc][4] = GetTickCount();
	}
	return 1;
}

fpublic: ac_RepairVehicle(vehicleid)
{
	if(AntiCheatVehInfo[vehicleid][acDriver] != 65535)
	{
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acNOPCount][4] = 0;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acSetVehHealth] = 1000.0;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][acDriver]][acGtc][4] = GetTickCount();
	}
	return 1;
}

#endif

stock acc_AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2)
{
	new vehicleid = AddStaticVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2);
	if(vehicleid != 65535) CallRemoteFunction("ac_AddStaticVehicle", "i", vehicleid);
	return vehicleid;
}

#if defined _ALS_AddStaticVehicle
	#undef AddStaticVehicle
#else
	#define _ALS_AddStaticVehicle
#endif
#define AddStaticVehicle acc_AddStaticVehicle

stock acc_AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay, addsiren = 0)
{
	new vehicleid = AddStaticVehicleEx(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay, addsiren);
	if(vehicleid != 65535) CallRemoteFunction("ac_AddStaticVehicle", "i", vehicleid);
	return vehicleid;
}

#if defined _ALS_AddStaticVehicleEx
	#undef AddStaticVehicleEx
#else
	#define _ALS_AddStaticVehicleEx
#endif
#define AddStaticVehicleEx acc_AddStaticVehicleEx

stock acc_CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, addsiren = 0)
{
	new vehicleid = CreateVehicle(vehicletype, x, y, z, rotation, color1, color2, respawn_delay, addsiren);
	if(vehicleid != 65535) CallRemoteFunction("ac_CreateVehicle", "ii", vehicleid, vehicletype);
	return vehicleid;
}

#if defined _ALS_CreateVehicle
	#undef CreateVehicle
#else
	#define _ALS_CreateVehicle
#endif
#define CreateVehicle acc_CreateVehicle

stock acc_AddPlayerClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new classid = AddPlayerClass(modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	if(classid < MAX_CLASSES) CallRemoteFunction("ac_AddPlayerClass", "iiiiiii", classid, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	return classid;
}

#if defined _ALS_AddPlayerClass
	#undef AddPlayerClass
#else
	#define _ALS_AddPlayerClass
#endif
#define AddPlayerClass acc_AddPlayerClass

stock acc_AddPlayerClassEx(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new classid = AddPlayerClassEx(teamid, modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	if(classid < MAX_CLASSES) CallRemoteFunction("ac_AddPlayerClass", "iiiiiii", classid, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	#if defined MAX_CLASSES
		#undef MAX_CLASSES
	#endif
	return classid;
}

#if defined _ALS_AddPlayerClassEx
	#undef AddPlayerClassEx
#else
	#define _ALS_AddPlayerClassEx
#endif
#define AddPlayerClassEx acc_AddPlayerClassEx

stock acc_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	if(!SetSpawnInfo(playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)) return 0;
	return CallRemoteFunction("ac_SetSpawnInfo", "iiiiiii", playerid, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

#if defined _ALS_SetSpawnInfo
	#undef SetSpawnInfo
#else
	#define _ALS_SetSpawnInfo
#endif
#define SetSpawnInfo acc_SetSpawnInfo

stock acc_AddStaticPickup(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0)
{
	new pickupid = CreatePickup(model, type, X, Y, Z, virtualworld);
	if(pickupid != -1) return CallRemoteFunction("ac_AddStaticPickup", "iiifff", pickupid, model, type, X, Y, Z);
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
	new pickupid = CreatePickup(model, type, X, Y, Z, virtualworld);
	if(pickupid != -1) CallRemoteFunction("ac_CreatePickup", "iiifff", pickupid, model, type, X, Y, Z);
	return pickupid;
}

#if defined _ALS_CreatePickup
	#undef CreatePickup
#else
	#define _ALS_CreatePickup
#endif
#define CreatePickup acc_CreatePickup

#if defined CreateDynamicPickup
	#if defined STREAMER_ENABLE_TAGS
		stock STREAMER_TAG_PICKUP acc_CreateDynamicPickup(modelid, type, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 100.0)
		{
			new STREAMER_TAG_PICKUP pickupid = CreateDynamicPickup(modelid, type, x, y, z, worldid, interiorid, playerid, streamdistance);
	#else
		stock acc_CreateDynamicPickup(modelid, type, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 100.0)
		{
			new pickupid = CreateDynamicPickup(modelid, type, x, y, z, worldid, interiorid, playerid, streamdistance);
	#endif
		if(pickupid > 0) CallRemoteFunction("ac_CreateDynamicPickup", "iiifff", pickupid, modelid, type, x, y, z);
		return pickupid;
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
		stock STREAMER_TAG_PICKUP acc_CreateDynamicPickupEx(modelid, type, Float:x, Float:y, Float:z, Float:streamdistance = 100.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players)
		{
			new STREAMER_TAG_PICKUP pickupid = CreateDynamicPickupEx(modelid, type, x, y, z, streamdistance, worlds, interiors, players, maxworlds, maxinteriors, maxplayers);
	#else
			stock acc_CreateDynamicPickupEx(modelid, type, Float:x, Float:y, Float:z, Float:streamdistance = 100.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players)
		{
			new pickupid = CreateDynamicPickupEx(modelid, type, x, y, z, streamdistance, worlds, interiors, players, maxworlds, maxinteriors, maxplayers);
	#endif
		if(pickupid > 0) CallRemoteFunction("ac_CreateDynamicPickup", "iiifff", pickupid, modelid, type, x, y, z);
		return pickupid;
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
	if(DestroyVehicle(vehicleid)) return CallRemoteFunction("ac_DestroyVehicle", "i", vehicleid);
	return 0;
}

#if defined _ALS_DestroyVehicle
	#undef DestroyVehicle
#else
	#define _ALS_DestroyVehicle
#endif
#define DestroyVehicle acc_DestroyVehicle

stock acc_DestroyPickup(pickup)
{
	if(DestroyPickup(pickup)) return CallRemoteFunction("ac_DestroyPickup", "i", pickup);
	return 0;
}

#if defined _ALS_DestroyPickup
	#undef DestroyPickup
#else
	#define _ALS_DestroyPickup
#endif
#define DestroyPickup acc_DestroyPickup

#if defined DestroyDynamicPickup
	#if defined STREAMER_ENABLE_TAGS
		stock acc_DestroyDynamicPickup(STREAMER_TAG_PICKUP pickupid)
	#else
		stock acc_DestroyDynamicPickup(pickupid)
	#endif
	{
		if(DestroyDynamicPickup(pickupid)) return CallRemoteFunction("ac_DestroyDynamicPickup", "i", pickupid);
		return 0;
	}

	#if defined _ALS_DestroyDynamicPickup
		#undef DestroyDynamicPickup
	#else
		#define _ALS_DestroyDynamicPickup
	#endif
	#define DestroyDynamicPickup acc_DestroyDynamicPickup
#endif

#if defined DestroyAllDynamicPickups
	stock acc_DestroyAllDynamicPickups()
	{
		if(DestroyAllDynamicPickups()) return CallRemoteFunction("ac_DestroyAllDynamicPickups", "");
		return 0;
	}

	#if defined _ALS_DestroyAllDynamicPickups
		#undef DestroyAllDynamicPickups
	#else
		#define _ALS_DestroyAllDynamicPickups
	#endif
	#define DestroyAllDynamicPickups acc_DestroyAllDynamicPickups
#endif

stock acc_DisableInteriorEnterExits() return CallRemoteFunction("ac_DisableInteriorEnterExits", ""), DisableInteriorEnterExits();

#if defined _ALS_DisableInteriorEnterExits
	#undef DisableInteriorEnterExits
#else
	#define _ALS_DisableInteriorEnterExits
#endif
#define DisableInteriorEnterExits acc_DisableInteriorEnterExits

stock acc_UsePlayerPedAnims() return CallRemoteFunction("ac_UsePlayerPedAnims", ""), UsePlayerPedAnims();

#if defined _ALS_UsePlayerPedAnims
	#undef UsePlayerPedAnims
#else
	#define _ALS_UsePlayerPedAnims
#endif
#define UsePlayerPedAnims acc_UsePlayerPedAnims

stock acc_EnableVehicleFriendlyFire() return CallRemoteFunction("ac_EnableVehicleFriendlyFire", ""), EnableVehicleFriendlyFire();

#if defined _ALS_EnableVehicleFriendlyFire
	#undef EnableVehicleFriendlyFire
#else
	#define _ALS_EnableVehicleFriendlyFire
#endif
#define EnableVehicleFriendlyFire acc_EnableVehicleFriendlyFire

stock acc_EnableStuntBonusForAll(enable) return CallRemoteFunction("ac_EnableStuntBonusForAll", "i", enable), EnableStuntBonusForAll(enable);

#if defined _ALS_EnableStuntBonusForAll
	#undef EnableStuntBonusForAll
#else
	#define _ALS_EnableStuntBonusForAll
#endif
#define EnableStuntBonusForAll acc_EnableStuntBonusForAll

stock acc_EnableStuntBonusForPlayer(playerid, enable)
{
	if(EnableStuntBonusForPlayer(playerid, enable)) return CallRemoteFunction("ac_EnableStuntBonusForPlayer", "ii", playerid, enable);
	return 0;
}

#if defined _ALS_EnableStuntBonusForPlayer
	#undef EnableStuntBonusForPlayer
#else
	#define _ALS_EnableStuntBonusForPlayer
#endif
#define EnableStuntBonusForPlayer acc_EnableStuntBonusForPlayer

#if defined Dialog_Show
	stock ac_Dialog_Show(playerid, style, string:title[], string:caption[], string:button1[], string:button2[] = "", dialog = -1)
	{
		if(IsPlayerConnected(playerid)) CallRemoteFunction("ac_ShowPlayerDialog", "id", playerid, dialog);
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
	if(ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2)) return CallRemoteFunction("ac_ShowPlayerDialog", "id", playerid, dialogid);
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
	if(TogglePlayerControllable(playerid, toggle)) return CallRemoteFunction("ac_TogglePlayerControllable", "ii", playerid, toggle);
	return 0;
}

#if defined _ALS_TogglePlayerControllable
	#undef TogglePlayerControllable
#else
	#define _ALS_TogglePlayerControllable
#endif
#define TogglePlayerControllable acc_TogglePlayerControllable

stock acc_TogglePlayerSpectating(playerid, toggle)
{
	if(TogglePlayerSpectating(playerid, toggle)) return CallRemoteFunction("ac_TogglePlayerSpectating", "ii", playerid, toggle);
	return 0;
}

#if defined _ALS_TogglePlayerSpectating
	#undef TogglePlayerSpectating
#else
	#define _ALS_TogglePlayerSpectating
#endif
#define TogglePlayerSpectating acc_TogglePlayerSpectating

stock acc_SpawnPlayer(playerid)
{
	if(SpawnPlayer(playerid)) return CallRemoteFunction("ac_SpawnPlayer", "i", playerid);
	return 0;
}

#if defined _ALS_SpawnPlayer
	#undef SpawnPlayer
#else
	#define _ALS_SpawnPlayer
#endif
#define SpawnPlayer acc_SpawnPlayer

stock acc_SetPlayerHealth(playerid, Float:health)
{
	if(health > 16777250.0) health = 16777250.0;
	if(SetPlayerHealth(playerid, health)) return CallRemoteFunction("ac_SetPlayerHealth", "if", playerid, health);
	return 0;
}

#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif
#define SetPlayerHealth acc_SetPlayerHealth

stock acc_SetPlayerArmour(playerid, Float:armour)
{
	if(armour > 16777250.0) armour = 16777250.0;
	if(SetPlayerArmour(playerid, armour)) return CallRemoteFunction("ac_SetPlayerArmour", "if", playerid, armour);
	return 0;
}

#if defined _ALS_SetPlayerArmour
	#undef SetPlayerArmour
#else
	#define _ALS_SetPlayerArmour
#endif
#define SetPlayerArmour acc_SetPlayerArmour

stock acc_GivePlayerWeapon(playerid, weaponid, ammo)
{
	if(IsPlayerConnected(playerid)) return CallRemoteFunction("ac_GivePlayerWeapon", "iid", playerid, weaponid, ammo);
	return 0;
}

#if defined _ALS_GivePlayerWeapon
	#undef GivePlayerWeapon
#else
	#define _ALS_GivePlayerWeapon
#endif
#define GivePlayerWeapon acc_GivePlayerWeapon

stock acc_SetPlayerAmmo(playerid, weaponslot, ammo)
{
	if(IsPlayerConnected(playerid)) return CallRemoteFunction("ac_SetPlayerAmmo", "iid", playerid, weaponslot, ammo);
	return 0;
}

#if defined _ALS_SetPlayerAmmo
	#undef SetPlayerAmmo
#else
	#define _ALS_SetPlayerAmmo
#endif
#define SetPlayerAmmo acc_SetPlayerAmmo

stock acc_SetPlayerArmedWeapon(playerid, weaponid)
{
	if(SetPlayerArmedWeapon(playerid, weaponid)) return CallRemoteFunction("ac_SetPlayerArmedWeapon", "ii", playerid, weaponid);
	return 0;
}

#if defined _ALS_SetPlayerArmedWeapon
	#undef SetPlayerArmedWeapon
#else
	#define _ALS_SetPlayerArmedWeapon
#endif
#define SetPlayerArmedWeapon acc_SetPlayerArmedWeapon

stock acc_ResetPlayerWeapons(playerid)
{
	if(ResetPlayerWeapons(playerid)) return CallRemoteFunction("ac_ResetPlayerWeapons", "i", playerid);
	return 0;
}

#if defined _ALS_ResetPlayerWeapons
	#undef ResetPlayerWeapons
#else
	#define _ALS_ResetPlayerWeapons
#endif
#define ResetPlayerWeapons acc_ResetPlayerWeapons

stock acc_GivePlayerMoney(playerid, money)
{
	if(GivePlayerMoney(playerid, money)) return CallRemoteFunction("ac_GivePlayerMoney", "id", playerid, money);
	return 0;
}

#if defined _ALS_GivePlayerMoney
	#undef GivePlayerMoney
#else
	#define _ALS_GivePlayerMoney
#endif
#define GivePlayerMoney acc_GivePlayerMoney

stock acc_ResetPlayerMoney(playerid)
{
	if(ResetPlayerMoney(playerid)) return CallRemoteFunction("ac_ResetPlayerMoney", "i", playerid);
	return 0;
}

#if defined _ALS_ResetPlayerMoney
	#undef ResetPlayerMoney
#else
	#define _ALS_ResetPlayerMoney
#endif
#define ResetPlayerMoney acc_ResetPlayerMoney

static stock bad_GetPlayerMoney(playerid) return GetPlayerMoney(playerid);

stock acc_GetPlayerMoney(playerid)
{
	if(IsPlayerConnected(playerid)) return CallRemoteFunction("ac_GetPlayerMoney", "i", playerid);
	return 0;
}

#if defined _ALS_GetPlayerMoney
	#undef GetPlayerMoney
#else
	#define _ALS_GetPlayerMoney
#endif
#define GetPlayerMoney acc_GetPlayerMoney

stock acc_SetPlayerSpecialAction(playerid, actionid)
{
	if(SetPlayerSpecialAction(playerid, actionid)) return CallRemoteFunction("ac_SetPlayerSpecialAction", "ii", playerid, actionid);
	return 0;
}

#if defined _ALS_SetPlayerSpecialAction
	#undef SetPlayerSpecialAction
#else
	#define _ALS_SetPlayerSpecialAction
#endif
#define SetPlayerSpecialAction acc_SetPlayerSpecialAction

stock acc_SetPlayerInterior(playerid, interiorid)
{
	if(SetPlayerInterior(playerid, interiorid)) return CallRemoteFunction("ac_SetPlayerInterior", "ii", playerid, interiorid);
	return 0;
}

#if defined _ALS_SetPlayerInterior
	#undef SetPlayerInterior
#else
	#define _ALS_SetPlayerInterior
#endif
#define SetPlayerInterior acc_SetPlayerInterior

stock acc_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
	if(SetPlayerPos(playerid, x, y, z)) return CallRemoteFunction("ac_SetPlayerPos", "ifff", playerid, x, y, z);
	return 0;
}

#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif
#define SetPlayerPos acc_SetPlayerPos

stock acc_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z)
{
	if(SetPlayerPosFindZ(playerid, x, y, z)) return CallRemoteFunction("ac_SetPlayerPosFindZ", "ifff", playerid, x, y, z);
	return 0;
}

#if defined _ALS_SetPlayerPosFindZ
	#undef SetPlayerPosFindZ
#else
	#define _ALS_SetPlayerPosFindZ
#endif
#define SetPlayerPosFindZ acc_SetPlayerPosFindZ

stock acc_SetPlayerVelocity(playerid, Float:X, Float:Y, Float:Z)
{
	if(SetPlayerVelocity(playerid, X, Y, Z)) return CallRemoteFunction("ac_SetPlayerVelocity", "ifff", playerid, X, Y, Z);
	return 0;
}

#if defined _ALS_SetPlayerVelocity
	#undef SetPlayerVelocity
#else
	#define _ALS_SetPlayerVelocity
#endif
#define SetPlayerVelocity acc_SetPlayerVelocity

stock acc_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
	if(PutPlayerInVehicle(playerid, vehicleid, seatid)) return CallRemoteFunction("ac_PutPlayerInVehicle", "iii", playerid, vehicleid, seatid);
	return 0;
}

#if defined _ALS_PutPlayerInVehicle
	#undef PutPlayerInVehicle
#else
	#define _ALS_PutPlayerInVehicle
#endif
#define PutPlayerInVehicle acc_PutPlayerInVehicle

stock acc_RemovePlayerFromVehicle(playerid)
{
	if(RemovePlayerFromVehicle(playerid)) return CallRemoteFunction("ac_RemovePlayerFromVehicle", "i", playerid);
	return 0;
}

#if defined _ALS_RemovePlayerFromVehicle
	#undef RemovePlayerFromVehicle
#else
	#define _ALS_RemovePlayerFromVehicle
#endif
#define RemovePlayerFromVehicle acc_RemovePlayerFromVehicle

stock acc_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z)
{
	if(SetVehiclePos(vehicleid, x, y, z)) return CallRemoteFunction("ac_SetVehiclePos", "ifff", vehicleid, x, y, z);
	return 0;
}

#if defined _ALS_SetVehiclePos
	#undef SetVehiclePos
#else
	#define _ALS_SetVehiclePos
#endif
#define SetVehiclePos acc_SetVehiclePos

stock acc_SetVehicleVelocity(vehicleid, Float:X, Float:Y, Float:Z)
{
	if(SetVehicleVelocity(vehicleid, X, Y, Z)) return CallRemoteFunction("ac_SetVehicleVelocity", "ifff", vehicleid, X, Y, Z);
	return 0;
}

#if defined _ALS_SetVehicleVelocity
	#undef SetVehicleVelocity
#else
	#define _ALS_SetVehicleVelocity
#endif
#define SetVehicleVelocity acc_SetVehicleVelocity

stock acc_SetVehicleAngularVelocity(vehicleid, Float:X, Float:Y, Float:Z)
{
	if(SetVehicleAngularVelocity(vehicleid, X, Y, Z)) return CallRemoteFunction("ac_SetVehicleAngularVelocity", "ifff", vehicleid, X, Y, Z);
	return 0;
}

#if defined _ALS_SetVehicleAngularVelocity
	#undef SetVehicleAngularVelocity
#else
	#define _ALS_SetVehicleAngularVelocity
#endif
#define SetVehicleAngularVelocity acc_SetVehicleAngularVelocity

stock acc_ChangeVehiclePaintjob(vehicleid, paintjobid)
{
	if(ChangeVehiclePaintjob(vehicleid, paintjobid)) return CallRemoteFunction("ac_ChangeVehiclePaintjob", "ii", vehicleid, paintjobid);
	return 0;
}

#if defined _ALS_ChangeVehiclePaintjob
	#undef ChangeVehiclePaintjob
#else
	#define _ALS_ChangeVehiclePaintjob
#endif
#define ChangeVehiclePaintjob acc_ChangeVehiclePaintjob

stock acc_SetVehicleHealth(vehicleid, Float:health)
{
	if(health < 0.0) health = 0.0;
	if(SetVehicleHealth(vehicleid, health)) return CallRemoteFunction("ac_SetVehicleHealth", "if", vehicleid, health);
	return 0;
}

#if defined _ALS_SetVehicleHealth
	#undef SetVehicleHealth
#else
	#define _ALS_SetVehicleHealth
#endif
#define SetVehicleHealth acc_SetVehicleHealth

stock acc_RepairVehicle(vehicleid)
{
	if(RepairVehicle(vehicleid)) return CallRemoteFunction("ac_RepairVehicle", "i", vehicleid);
	return 0;
}

#if defined _ALS_RepairVehicle
	#undef RepairVehicle
#else
	#define _ALS_RepairVehicle
#endif
#define RepairVehicle acc_RepairVehicle

#if !defined FILTERSCRIPT

#if defined _inc_y_hooks || defined _INC_y_hooks
	Hook:ac_OnGameModeInit()
#else
	public OnGameModeInit()
#endif
{
	if(!LoadCfg()) printf(CFG_OPENING_ERROR, CONFIG_FILE);
	if(ACAllow[42])
	{
		#if !USE_QUERY
			QueryEnable = !!GetConsoleVarAsBool("query");
			SendRconCommand("query 0");
		#endif
		RconEnable = !!GetConsoleVarAsBool("rcon");
		SendRconCommand("rcon 0");
	}
	LagCompMode = !!GetConsoleVarAsInt("lagcompmode");
	print(" ");
	print("--------------------------------------");
	print(LOADED_MSG_1);
	printf(LOADED_MSG_2, NEX_AC_VERSION);
	#undef NEX_AC_VERSION
	print(LOADED_MSG_3);
	print("--------------------------------------\n");
	new a = 1;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnGameModeInit
		a = ac_OnGameModeInit();
	#endif
	new strtmp[10];
	GetConsoleVarAsString("version", strtmp, sizeof strtmp);
	if(strcmp(strtmp, AC_SERVER_VERSION)) print(VERSION_WARNING);
	#undef AC_SERVER_VERSION
	return a;
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
	Hook:ac_OnGameModeExit()
#else
	public OnGameModeExit()
#endif
{
	new a = 1;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnGameModeExit
		a = ac_OnGameModeExit();
	#endif
	print(" ");
	print("--------------------------------------");
	print(STATS_STRING_1);
	print(STATS_STRING_2);
	printf(STATS_STRING_3, StatsInfo[0]);
	printf(STATS_STRING_4, StatsInfo[1]);
	printf(STATS_STRING_5, StatsInfo[2]);
	printf(STATS_STRING_6, StatsInfo[3]);
	printf(STATS_STRING_7, StatsInfo[4]);
	printf(STATS_STRING_8, StatsInfo[5]);
	print("--------------------------------------\n");
	return a;
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
	Hook:ac_OnPlayerConnect(playerid)
#else
	public OnPlayerConnect(playerid)
#endif
{
	GetPlayerIp(playerid, AntiCheatInfo[playerid][acIp], 16);
	if(IsPlayerNPC(playerid))
	{
		if(ACAllow[36] && strcmp(AntiCheatInfo[playerid][acIp],
		"127.0.0.1")) KickWithCode(playerid, "", 0, 36);
		AntiCheatInfo[playerid][acTimerID] = -1;
	}
	else
	{
		if(ACAllow[48] && AntiCheatInfo[playerid][acOnline]) KickWithCode(playerid, "", 0, 48);
		if(ACAllow[41])
		{
			new version[8];
			GetPlayerVersion(playerid, version, sizeof version);
			if(!strcmp(version, "unknown", true))
			{
				#if defined DEBUG
					printf(DEBUG_CODE_2, playerid, version);
				#endif
				KickWithCode(playerid, "", 0, 41);
			}
		}
		new i = MAX_CONNECTS_FROM_IP;
		if(ACAllow[40])
		{
			#if defined foreach
				foreach(new f : Player)
				{
					if(!IsPlayerNPC(f) && f != playerid
					&& !strcmp(AntiCheatInfo[playerid][acIp], AntiCheatInfo[f][acIp], false))
			#else
				for(new f = GetPlayerPoolSize(); f != -1; --f)
				{
					if(IsPlayerConnected(f) && !IsPlayerNPC(f) && f != playerid
					&& !strcmp(AntiCheatInfo[playerid][acIp], AntiCheatInfo[f][acIp], false))
			#endif
				{
					i--;
					if(!i)
					{
						#if defined DEBUG
							printf(DEBUG_CODE_3, playerid, MAX_CONNECTS_FROM_IP);
						#endif
						#undef MAX_CONNECTS_FROM_IP
						KickWithCode(playerid, "", 0, 40);
						break;
					}
				}
			}
		}
		AntiCheatInfo[playerid][acDead] = true;
		AntiCheatInfo[playerid][acSpawnRes] =
		AntiCheatInfo[playerid][acDeathRes] = false;
		AntiCheatInfo[playerid][acIntEnterExits] = IntEnterExits;
		AntiCheatInfo[playerid][acStuntBonus] = StuntBonus;
		AntiCheatInfo[playerid][acCheatCount][0] =
		AntiCheatInfo[playerid][acLastWeapon] =
		AntiCheatInfo[playerid][acKicked] =
		AntiCheatInfo[playerid][acMoney] = 0;
		AntiCheatInfo[playerid][acSet][13] =
		AntiCheatInfo[playerid][acSet][12] =
		AntiCheatInfo[playerid][acSet][0] =
		AntiCheatInfo[playerid][acDialog] = -1;
		AntiCheatInfo[playerid][acAnim] = -2;
		for(i = 12; i != -1; --i)
		{
			AntiCheatInfo[playerid][acSetWeapon][i] = -1;
			AntiCheatInfo[playerid][acGiveAmmo][i] = -65535;
		}
		for(i = 27; i != -1; --i) AntiCheatInfo[playerid][acFloodCount][i] = 0;
		AntiCheatInfo[playerid][acDropJP][0] = AntiCheatInfo[playerid][acDropJP][1] =
		AntiCheatInfo[playerid][acDropJP][2] = 20001.0;
		memcpy(AntiCheatInfo[playerid][acACAllow], ACAllow, 0, sizeof(ACAllow) * 4, sizeof ACAllow);
		AntiCheatInfo[playerid][acTimerID] = SetTimerEx("acTimer", 1000, false, "i", playerid);
	}
	AntiCheatInfo[playerid][acOnline] = true;
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
	Hook:ac_OnPlayerDisconnect(playerid, reason)
#else
	public OnPlayerDisconnect(playerid, reason)
#endif
{
	if(AntiCheatInfo[playerid][acOnline])
	{
		AntiCheatInfo[playerid][acOnline] = false;
		if(!IsPlayerNPC(playerid))
		{
			KillTimer(AntiCheatInfo[playerid][acTimerID]);
			if(!reason) Kick(playerid);
			if(AntiCheatInfo[playerid][acACAllow][37]) BlockIpAddress(AntiCheatInfo[playerid][acIp],
			(MIN_TIME_RECONNECT * 1000) - (reason ? 0 : GetConsoleVarAsInt("playertimeout")));
			#undef MIN_TIME_RECONNECT
		}
		if(AntiCheatInfo[playerid][acVeh]
		&& AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acDriver] == playerid)
		{
			AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acDriver] = 65535;
			if(AntiCheatInfo[playerid][acKicked] == 2)
			{
				LinkVehicleToInterior(AntiCheatInfo[playerid][acVeh],
				AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acInt]);
				SetVehicleZAngle(AntiCheatInfo[playerid][acVeh],
				AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acZAngle]);
				SetVehiclePos(AntiCheatInfo[playerid][acVeh], AntiCheatInfo[playerid][acPos][0],
				AntiCheatInfo[playerid][acPos][1], AntiCheatInfo[playerid][acPos][2]);
				SetVehicleHealth(AntiCheatInfo[playerid][acVeh],
				AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acHealth]);
				ChangeVehiclePaintjob(AntiCheatInfo[playerid][acVeh],
				AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acPaintJob]);
			}
		}
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerDisconnect
			return ac_OnPlayerDisconnect(playerid, reason);
		#endif
	}
	return 1;
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
	Hook:ac_OnPlayerSpawn(playerid)
#else
	public OnPlayerSpawn(playerid)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	if(!IsPlayerNPC(playerid))
	{
		if(AntiCheatInfo[playerid][acACAllow][27] && AntiCheatInfo[playerid][acSet][7] == -1
		&& (!AntiCheatInfo[playerid][acSpawnRes] || GetTickCount() < AntiCheatInfo[playerid][acSpawnTime]
		+ 1000)) KickWithCode(playerid, "", 0, 27);
		new i;
		for(i = 10; i != 0; --i) AntiCheatInfo[playerid][acSet][i] = -1;
		for(i = 12; i != -1; --i)
		{
			AntiCheatInfo[playerid][acWeapon][i] =
			AntiCheatInfo[playerid][acAmmo][i] = 0;
			AntiCheatInfo[playerid][acSetWeapon][i] = -1;
			AntiCheatInfo[playerid][acGiveAmmo][i] = -65535;
		}
		AntiCheatInfo[playerid][acParachute] =
		AntiCheatInfo[playerid][acSpawnRes] =
		AntiCheatInfo[playerid][acModShop] =
		AntiCheatInfo[playerid][acPicked] =
		AntiCheatInfo[playerid][acTpToZ] =
		AntiCheatInfo[playerid][acDead] = false;
		AntiCheatInfo[playerid][acFreeze] = true;
		AntiCheatInfo[playerid][acNextSpecAct] =
		AntiCheatInfo[playerid][acLastPickup] =
		AntiCheatInfo[playerid][acSeat] = -1;
		AntiCheatInfo[playerid][acCheatCount][9] =
		AntiCheatInfo[playerid][acLastSpecAct] =
		AntiCheatInfo[playerid][acLastShot] =
		AntiCheatInfo[playerid][acSpecAct] =
		AntiCheatInfo[playerid][acDmgRes] =
		AntiCheatInfo[playerid][acVeh] = 0;
		AntiCheatInfo[playerid][acSpeed] = 0.0;
		SetPlayerHealth(playerid, 100.0);
		SetPlayerArmour(playerid, 0.0);
		for(i = 2; i != -1; --i)
		{
			if(AntiCheatInfo[playerid][acSpawnWeapon][i] != -1)
			{
				AntiCheatInfo[playerid][acWeapon][WeaponSlots[AntiCheatInfo[playerid]
				[acSpawnWeapon][i]]] = AntiCheatInfo[playerid][acSpawnWeapon][i];
				AntiCheatInfo[playerid][acAmmo][WeaponSlots[AntiCheatInfo[playerid]
				[acSpawnWeapon][i]]] = AntiCheatInfo[playerid][acSpawnAmmo][i];
			}
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
	Hook:ac_OnPlayerDeath(playerid, killerid, reason)
#else
	public OnPlayerDeath(playerid, killerid, reason)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	if(AntiCheatInfo[playerid][acACAllow][28] && (AntiCheatInfo[playerid][acDead]
	|| !AntiCheatInfo[playerid][acDeathRes] && reason != 255 && (reason != 54
	|| killerid != 65535))) KickWithCode(playerid, "", 0, 28);
	AntiCheatInfo[playerid][acDeathRes] = false;
	AntiCheatInfo[playerid][acSet][0] = -1;
	AntiCheatInfo[playerid][acSpawnRes] =
	AntiCheatInfo[playerid][acDead] = true;
	AntiCheatInfo[playerid][acSpawnTime] = GetTickCount();
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
	Hook:ac_OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
#else
	public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
#endif
{
	AntiCheatInfo[playerid][acDeathRes] = true;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerTakeDamage
		return ac_OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);
	#else
		return 1;
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
	Hook:ac_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
#else
	public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][0] + Mtfc[0][0]) FloodDetect(playerid, 0);
		else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][0] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	if(AntiCheatInfo[playerid][acACAllow][39] && dialogid
	!= AntiCheatInfo[playerid][acDialog])
	{
		#if defined OnCheatDetected
			KickWithCode(playerid, "", 0, 39);
		#else
			return KickWithCode(playerid, "", 0, 39);
		#endif
	}
	AntiCheatInfo[playerid][acDialog] = -1;
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][0] = i;
	if(AntiCheatInfo[playerid][acACAllow][45])
	{
		while((i = strfind(inputtext, "%")) != -1) strdel(inputtext, i, i + 1);
	}
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnDialogResponse
		return ac_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
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
	Hook:ac_OnEnterExitModShop(playerid, enterexit, interiorid)
#else
	public OnEnterExitModShop(playerid, enterexit, interiorid)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	#if !USE_TUNING_GARAGES
		#if defined OnCheatDetected
			KickWithCode(playerid, "", 0, 23, 1);
		#else
			return KickWithCode(playerid, "", 0, 23, 1);
		#endif
	#endif
	#undef USE_TUNING_GARAGES
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][1] + Mtfc[1][0]) FloodDetect(playerid, 1);
		else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][1] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acSet][0] = interiorid;
	AntiCheatInfo[playerid][acModShop] = !!enterexit;
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][1] = i;
	AntiCheatInfo[playerid][acGtc][11] = i + 1500;
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
	Hook:ac_OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
#else
	public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetPlayerVehicleID(playerid);
	if(newinteriorid != AntiCheatInfo[playerid][acSet][0])
	{
		if(i)
		{
			if(AntiCheatInfo[playerid][acACAllow][3]) KickWithCode(playerid, "", 0, 3, 1);
		}
		else if(AntiCheatInfo[playerid][acACAllow][2] && !AntiCheatInfo[playerid][acIntEnterExits]
		&& newinteriorid != AntiCheatInfo[playerid][acSet][12]) KickWithCode(playerid, "", 0, 2, 1);
		GetPlayerPos(playerid, AntiCheatInfo[playerid][acPos][0],
		AntiCheatInfo[playerid][acPos][1], AntiCheatInfo[playerid][acPos][2]);
		AntiCheatInfo[playerid][acGtc][11] = GetTickCount() + 1500;
	}
	if(!AntiCheatInfo[playerid][acKicked] && i) AntiCheatVehInfo[i][acInt] = newinteriorid;
	if(AntiCheatInfo[playerid][acSet][12] == -1) AntiCheatInfo[playerid][acSet][0] = -1;
	else AntiCheatInfo[playerid][acSet][12] = -1;
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
	Hook:ac_OnRconLoginAttempt(ip[], password[], success)
#else
	public OnRconLoginAttempt(ip[], password[], success)
#endif
{
	if(ACAllow[42])
	{
		static iptables[MAX_PLAYERS][2], ip_index;
		new i, current_ip = IpToInt(ip);
		for(; i < ip_index && i < sizeof iptables; ++i)
		{
			if(iptables[i][0] == current_ip)
			{
				if(success) iptables[i][1] = 0;
				else if(++iptables[i][1] > MAX_RCON_LOGIN_ATTEMPT)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_4, ip, password);
					#endif
					iptables[i][1] = 0;
					KickWithCode(65535, ip, 1, 42, 1);
				}
				i = -1;
				break;
			}
		}
		if(i != -1 && !success)
		{
			iptables[ip_index][0] = current_ip;
			if(++iptables[ip_index][1] > MAX_RCON_LOGIN_ATTEMPT)
			{
				#undef MAX_RCON_LOGIN_ATTEMPT
				#if defined DEBUG
					printf(DEBUG_CODE_4, ip, password, iptables[ip_index][1]);
				#endif
				iptables[ip_index][1] = 0;
				KickWithCode(65535, ip, 1, 42, 2);
			}
			if(++ip_index > sizeof(iptables) - 1) ip_index = 0;
			iptables[ip_index][1] = 0;
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
	Hook:ac_OnPlayerUpdate(playerid)
#else
	public OnPlayerUpdate(playerid)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	static gtc, gpp, bool:ur;
	ur = false;
	gtc = GetTickCount();
	if(!IsPlayerNPC(playerid))
	{
		gpp = GetPlayerPing(playerid);
		if(AntiCheatInfo[playerid][acACAllow][38])
		{
			if(gpp > MAX_PING)
			{
				if(++AntiCheatInfo[playerid][acCheatCount][0] > MAX_PING_WARNINGS)
				{
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acCheatCount][0] = 0;
						KickWithCode(playerid, "", 0, 38);
					#else
						return KickWithCode(playerid, "", 0, 38);
					#endif
				}
				#undef MAX_PING_WARNINGS
			}
			else AntiCheatInfo[playerid][acCheatCount][0] = 0;
		}
		static stateanim;
		if((stateanim = GetPlayerState(playerid)) != 9)
		{
			gpp += 100;
			static w, a;
			a = GetPlayerAmmo(playerid);
			w = GetPlayerWeapon(playerid);
			if(AntiCheatInfo[playerid][acSet][3] != -1)
			{
				if(AntiCheatInfo[playerid][acSet][3] == w)
				{
					AntiCheatInfo[playerid][acSet][3] =
					AntiCheatInfo[playerid][acSetWeapon][WeaponSlots[w]] = -1;
					AntiCheatInfo[playerid][acWeapon][WeaponSlots[w]] = w;
				}
				else if(AntiCheatInfo[playerid][acACAllow][52] && !(1 < stateanim < 4)
				&& gtc > AntiCheatInfo[playerid][acGtc][2] + gpp
				&& ++AntiCheatInfo[playerid][acNOPCount][0] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "GivePlayerWeapon");
					#endif
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acSet][3] =
						AntiCheatInfo[playerid][acSetWeapon][WeaponSlots[w]] = -1;
						KickWithCode(playerid, "", 0, 52, 1);
					#else
						return KickWithCode(playerid, "", 0, 52, 1);
					#endif
				}
			}
			if(AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[w]] != -65535)
			{
				if(AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[w]] == a)
				{
					AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[w]] = -65535;
					AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]] = a;
				}
				else if(AntiCheatInfo[playerid][acACAllow][52] && gtc >
				AntiCheatInfo[playerid][acGtcGiveAmmo][WeaponSlots[w]] + gpp
				&& ++AntiCheatInfo[playerid][acNOPCount][1] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "SetPlayerAmmo");
					#endif
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acGiveAmmo][WeaponSlots[w]] = -65535;
						KickWithCode(playerid, "", 0, 52, 2);
					#else
						return KickWithCode(playerid, "", 0, 52, 2);
					#endif
				}
			}
			static i;
			i = GetPlayerInterior(playerid);
			if(AntiCheatInfo[playerid][acLastWeapon] != w)
			{
				if(AntiCheatInfo[playerid][acWeapon][WeaponSlots[w]] != w)
				{
					if(w == 40 || w == 46 && AntiCheatInfo[playerid][acVeh]
					&& AntiCheatInfo[playerid][acParachute])
					{
						AntiCheatInfo[playerid][acWeapon][WeaponSlots[w]] = w;
						AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]] = a;
					}
					else if(21 < w < 33 && IsPlayerInAmmuNation(playerid, i))
					{
						if(AntiCheatInfo[playerid][acSet][10]
						!= -1) AntiCheatInfo[playerid][acSet][10] += AmmuNationInfo[w - 22][0];
						else AntiCheatInfo[playerid][acSet][10] = AmmuNationInfo[w - 22][0];
						AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]] = AmmuNationInfo[w - 22][1];
						AntiCheatInfo[playerid][acCheatCount][10] = 0;
						AntiCheatInfo[playerid][acWeapon][WeaponSlots[w]] = w;
						ur = true;
					}
					else if(-1 < AntiCheatInfo[playerid][acLastPickup] < MAX_PICKUPS
					&& AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acWeapon] == w
					&& a == PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acWeapon]]
					&& IsPlayerInRangeOfPoint(playerid, 5.0, AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acPos][0],
					AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acPos][1],
					AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acPos][2]))
					{
						AntiCheatInfo[playerid][acWeapon][WeaponSlots[w]] = w;
						if(2 < WeaponSlots[AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acWeapon]] <
						6) AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]] +=
						PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acWeapon]];
						else AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]] =
						PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acWeapon]];
					}
					else if(AntiCheatInfo[playerid][acLastPickup] > MAX_PICKUPS
					&& AntiCheatDPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acWeapon] == w
					&& a == PickupAmmo[AntiCheatDPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acWeapon]]
					&& IsPlayerInRangeOfPoint(playerid, 5.0, AntiCheatDPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acPos][0],
					AntiCheatDPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acPos][1],
					AntiCheatDPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acPos][2]))
					{
						AntiCheatInfo[playerid][acWeapon][WeaponSlots[w]] = w;
						if(2 < WeaponSlots[AntiCheatDPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acWeapon]] <
						6) AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]] +=
						PickupAmmo[AntiCheatDPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acWeapon]];
						else AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]] =
						PickupAmmo[AntiCheatDPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acWeapon]];
					}
					else if(AntiCheatInfo[playerid][acACAllow][15]
					&& AntiCheatInfo[playerid][acSetWeapon][WeaponSlots[w]] == -1
					&& gtc > AntiCheatInfo[playerid][acGtc][7] + gpp)
					{
						#if defined OnCheatDetected
							AntiCheatInfo[playerid][acWeapon][WeaponSlots[w]] = w;
							KickWithCode(playerid, "", 0, 15, 1);
						#else
							return KickWithCode(playerid, "", 0, 15, 1);
						#endif
					}
				}
			}
			else if(AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]] != a)
			{
				switch(w)
				{
					case 16, 17, 18, 35, 36, 39, 43:
					{
						if(AntiCheatInfo[playerid][acACAllow][16] && (!AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]]
						|| AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]] - 1 != a))
						{
							#if defined OnCheatDetected
								AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]] = a;
								KickWithCode(playerid, "", 0, 16, 1);
							#else
								return KickWithCode(playerid, "", 0, 16, 1);
							#endif
						}
						AntiCheatInfo[playerid][acAmmo][WeaponSlots[w]]--;
					}
				}
			}
			static Float:health;
			GetPlayerHealth(playerid, health);
			if(AntiCheatInfo[playerid][acSet][1] != -1)
			{
				if(AntiCheatInfo[playerid][acSet][1] > 255)
				{
					while(health < AntiCheatInfo[playerid][acSet][1]) health += 256;
				}
				if(AntiCheatInfo[playerid][acSet][1] == health) AntiCheatInfo[playerid][acSet][1] = -1;
				else if(AntiCheatInfo[playerid][acACAllow][52] && gtc > AntiCheatInfo[playerid][acGtc][3]
				+ gpp && ++AntiCheatInfo[playerid][acNOPCount][3] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "SetPlayerHealth");
					#endif
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acSet][1] = -1;
						KickWithCode(playerid, "", 0, 52, 3);
					#else
						return KickWithCode(playerid, "", 0, 52, 3);
					#endif
				}
			}
			else if(AntiCheatInfo[playerid][acACAllow][12])
			{
				while(AntiCheatInfo[playerid][acHealth] > health + 255) health += 256;
				if(health > AntiCheatInfo[playerid][acHealth] && !(health <= AntiCheatInfo[playerid][acHealth] + 70.0
				&& IsPlayerInRestaurant(playerid, i)) && !(health <= AntiCheatInfo[playerid][acHealth] + 35.0
				&& IsPlayerNearVendingMachine(playerid, i)))
				{
					#if defined OnCheatDetected
						KickWithCode(playerid, "", 0, 12);
					#else
						return KickWithCode(playerid, "", 0, 12);
					#endif
				}
			}
			static Float:armour;
			GetPlayerArmour(playerid, armour);
			if(AntiCheatInfo[playerid][acSet][2] != -1)
			{
				if(AntiCheatInfo[playerid][acSet][2] > 255)
				{
					while(armour < AntiCheatInfo[playerid][acSet][2]) armour += 256;
				}
				if(AntiCheatInfo[playerid][acSet][2] == armour) AntiCheatInfo[playerid][acSet][2] = -1;
				else if(AntiCheatInfo[playerid][acACAllow][52] && gtc > AntiCheatInfo[playerid][acGtc][5]
				+ gpp && ++AntiCheatInfo[playerid][acNOPCount][5] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "SetPlayerArmour");
					#endif
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acSet][2] = -1;
						KickWithCode(playerid, "", 0, 52, 4);
					#else
						return KickWithCode(playerid, "", 0, 52, 4);
					#endif
				}
			}
			else if(AntiCheatInfo[playerid][acACAllow][13])
			{
				while(AntiCheatInfo[playerid][acArmour] > armour + 255) armour += 256;
				if(armour > AntiCheatInfo[playerid][acArmour])
				{
					if(IsPlayerInAmmuNation(playerid, i))
					{
						if(AntiCheatInfo[playerid][acSet][10]
						!= -1) AntiCheatInfo[playerid][acSet][10] += 200;
						else AntiCheatInfo[playerid][acSet][10] = 200;
						AntiCheatInfo[playerid][acCheatCount][10] = 0;
						ur = true;
					}
					else
					{
						#if defined OnCheatDetected
							KickWithCode(playerid, "", 0, 13);
						#else
							return KickWithCode(playerid, "", 0, 13);
						#endif
					}
				}
			}
			if(AntiCheatInfo[playerid][acACAllow][19])
			{
				if(health < AntiCheatInfo[playerid][acHealth]
				|| armour < AntiCheatInfo[playerid][acArmour])
				{
					AntiCheatInfo[playerid][acVehDmgRes] = false;
					AntiCheatInfo[playerid][acCheatCount][9] =
					AntiCheatInfo[playerid][acDmgRes] = 0;
				}
				else if(AntiCheatInfo[playerid][acDmgRes]
				&& gtc > AntiCheatInfo[playerid][acGtc][14] + gpp)
				{
					AntiCheatInfo[playerid][acVehDmgRes] = false;
					AntiCheatInfo[playerid][acDmgRes] = 0;
					if(++AntiCheatInfo[playerid][acCheatCount][9] >
					MAX_GODMODE_WARNINGS)
					{
						#if defined OnCheatDetected
							AntiCheatInfo[playerid][acCheatCount][9] = 0;
							KickWithCode(playerid, "", 0, 19);
						#else
							return KickWithCode(playerid, "", 0, 19);
						#endif
					}
				}
			}
			static pvehid;
			a = bad_GetPlayerMoney(playerid);
			pvehid = GetPlayerVehicleID(playerid);
			if(AntiCheatInfo[playerid][acACAllow][14] && a > AntiCheatInfo[playerid][acMoney]
			&& !(AntiCheatInfo[playerid][acStuntBonus] && pvehid) && !IsPlayerInCasino(playerid, i))
			{
				#if defined OnCheatDetected
					AntiCheatInfo[playerid][acMoney] = a;
					KickWithCode(playerid, "", 0, 14);
				#else
					a = AntiCheatInfo[playerid][acMoney];
					ResetPlayerMoney(playerid);
					GivePlayerMoney(playerid, a);
				#endif
			}
			if(AntiCheatInfo[playerid][acSet][10] != -1)
			{
				if(a < AntiCheatInfo[playerid][acMoney] && AntiCheatInfo[playerid][acSet][10] ==
				(AntiCheatInfo[playerid][acMoney] - a)) AntiCheatInfo[playerid][acSet][10] = -1;
				else if(AntiCheatInfo[playerid][acACAllow][15] && gtc > AntiCheatInfo[playerid][acGtc][15]
				+ 1030 && ++AntiCheatInfo[playerid][acCheatCount][10] > MAX_NOP_WARNINGS)
				{
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acSet][10] = -1;
						KickWithCode(playerid, "", 0, 15, 3);
					#else
						return KickWithCode(playerid, "", 0, 15, 3);
					#endif
				}
			}
			if(AntiCheatInfo[playerid][acSet][13] != -1)
			{
				if(a < AntiCheatInfo[playerid][acMoney] && AntiCheatInfo[playerid][acSet][13] ==
				(AntiCheatInfo[playerid][acMoney] - a)) AntiCheatInfo[playerid][acSet][13] = -1;
				else if(AntiCheatInfo[playerid][acACAllow][23] && gtc > AntiCheatInfo[playerid][acGtc][17]
				+ 1500 && ++AntiCheatInfo[playerid][acCheatCount][12] > MAX_NOP_WARNINGS)
				{
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acSet][13] = -1;
						KickWithCode(playerid, "", 0, 23, 3);
					#else
						return KickWithCode(playerid, "", 0, 23, 3);
					#endif
				}
			}
			if(AntiCheatInfo[playerid][acACAllow][52])
			{
				if(AntiCheatInfo[playerid][acSet][0] != -1 && gtc > AntiCheatInfo[playerid][acGtc][0]
				+ gpp && ++AntiCheatInfo[playerid][acNOPCount][2] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "SetPlayerInterior");
					#endif
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acSet][0] = -1;
						KickWithCode(playerid, "", 0, 52, 5);
					#else
						return KickWithCode(playerid, "", 0, 52, 5);
					#endif
				}
				if(AntiCheatInfo[playerid][acSet][6] != -1 && gtc > AntiCheatInfo[playerid][acGtc][12]
				+ gpp && ++AntiCheatInfo[playerid][acNOPCount][8] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "TogglePlayerSpectating");
					#endif
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acSet][6] = -1;
						KickWithCode(playerid, "", 0, 52, 6);
					#else
						return KickWithCode(playerid, "", 0, 52, 6);
					#endif
				}
				if(AntiCheatInfo[playerid][acSet][7] != -1 && gtc > AntiCheatInfo[playerid][acGtc][13]
				+ gpp && ++AntiCheatInfo[playerid][acNOPCount][9] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "SpawnPlayer");
					#endif
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acSet][7] = -1;
						KickWithCode(playerid, "", 0, 52, 7);
					#else
						return KickWithCode(playerid, "", 0, 52, 7);
					#endif
				}
				if(AntiCheatInfo[playerid][acSet][11] != -1 && pvehid
				&& gtc > AntiCheatInfo[playerid][acGtc][8] + gpp + 3000)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "RemovePlayerFromVehicle");
					#endif
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acSet][11] = -1;
						KickWithCode(playerid, "", 0, 52, 8);
					#else
						return KickWithCode(playerid, "", 0, 52, 8);
					#endif
				}
			}
			static s, Float:pposX, Float:pposY, Float:pposZ;
			s = GetPlayerVehicleSeat(playerid);
			GetPlayerPos(playerid, pposX, pposY, pposZ);
			if(AntiCheatInfo[playerid][acSet][9] != -1)
			{
				if(AntiCheatInfo[playerid][acSet][9] == pvehid
				&& (AntiCheatInfo[playerid][acSet][5] == s
				|| AntiCheatInfo[playerid][acSet][5] == -1))
				{
					if(AntiCheatInfo[playerid][acVeh]
					&& AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acDriver] == playerid)
					{
						if(GetVehicleModel(AntiCheatInfo[playerid][acVeh]) == 457
						&& !AntiCheatInfo[playerid][acWeapon][1]) AntiCheatInfo[playerid][acWeapon][1] = 2;
						AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acDriver] = 65535;
					}
					if(!s)
					{
						AntiCheatVehInfo[pvehid][acDriver] = playerid;
						GetVehicleZAngle(pvehid, AntiCheatVehInfo[pvehid][acZAngle]);
						AntiCheatInfo[playerid][acSetVehHealth] = -1;
					}
					AntiCheatInfo[playerid][acCheatCount][11] = 0;
					AntiCheatInfo[playerid][acVehDmgRes] = false;
					AntiCheatInfo[playerid][acSet][11] =
					AntiCheatInfo[playerid][acSet][9] =
					AntiCheatInfo[playerid][acSet][8] =
					AntiCheatInfo[playerid][acSet][5] = -1;
					AntiCheatInfo[playerid][acSeat] = s;
				}
				else if(AntiCheatInfo[playerid][acACAllow][52] && gtc > AntiCheatInfo[playerid][acGtc][1]
				+ gpp && ++AntiCheatInfo[playerid][acNOPCount][7] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "PutPlayerInVehicle");
					#endif
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acSet][9] = -1;
						KickWithCode(playerid, "", 0, 52, 9);
					#else
						return KickWithCode(playerid, "", 0, 52, 9);
					#endif
				}
			}
			else
			{
				if(AntiCheatInfo[playerid][acSet][8] != -1)
				{
					if(IsPlayerInRangeOfPoint(playerid, 5.0, AntiCheatInfo[playerid][acSetPos][0],
					AntiCheatInfo[playerid][acSetPos][1], (AntiCheatInfo[playerid][acTpToZ]
					? pposZ : AntiCheatInfo[playerid][acSetPos][2])))
					{
						AntiCheatInfo[playerid][acSet][8] = -1;
						AntiCheatInfo[playerid][acGtc][11] = 0;
						AntiCheatInfo[playerid][acTpToZ] = false;
						AntiCheatInfo[playerid][acPos][0] = pposX;
						AntiCheatInfo[playerid][acPos][1] = pposY;
						AntiCheatInfo[playerid][acPos][2] = pposZ;
					}
					else if(gtc > AntiCheatInfo[playerid][acGtc][11] + gpp)
					{
						AntiCheatInfo[playerid][acTpToZ] = false;
						if(AntiCheatInfo[playerid][acACAllow][52]
						&& ++AntiCheatInfo[playerid][acNOPCount][10] > MAX_NOP_WARNINGS)
						{
							#if defined DEBUG
								printf(DEBUG_CODE_5, playerid, "SetPlayerPos");
							#endif
							#if defined OnCheatDetected
								AntiCheatInfo[playerid][acSet][8] = -1;
								KickWithCode(playerid, "", 0, 52, 10);
							#else
								return KickWithCode(playerid, "", 0, 52, 10);
							#endif
						}
					}
				}
				static Float:pvelX, Float:pvelY, Float:pvelZ, Float:vctsize, specact;
				vctsize = GetPlayerDistanceFromPoint(playerid, AntiCheatInfo[playerid][acPos][0],
				AntiCheatInfo[playerid][acPos][1], AntiCheatInfo[playerid][acPos][2]);
				specact = GetPlayerSpecialAction(playerid);
				if(pvehid)
				{
					if(!AntiCheatInfo[playerid][acVeh])
					{
						if(AntiCheatInfo[playerid][acACAllow][4]
						&& (AntiCheatInfo[playerid][acEnterVeh] != pvehid
						|| gtc < AntiCheatInfo[playerid][acEnterVehTime] + 600))
						{
							#if defined OnCheatDetected
								KickWithCode(playerid, "", 0, 4, 1);
							#else
								return KickWithCode(playerid, "", 0, 4, 1);
							#endif
						}
					}
					else if(AntiCheatInfo[playerid][acVeh] != pvehid)
					{
						if(AntiCheatInfo[playerid][acACAllow][4])
						{
							#if defined OnCheatDetected
								KickWithCode(playerid, "", 0, 4, 2);
							#else
								return KickWithCode(playerid, "", 0, 4, 2);
							#endif
						}
					}
					else if(AntiCheatInfo[playerid][acACAllow][50]
					&& AntiCheatInfo[playerid][acSeat] != s)
					{
						#if defined OnCheatDetected
							KickWithCode(playerid, "", 0, 50);
						#else
							return KickWithCode(playerid, "", 0, 50);
						#endif
					}
					if(stateanim == 2)
					{
						if(AntiCheatInfo[playerid][acACAllow][32] && AntiCheatVehInfo[pvehid][acDriver] != 65535
						&& AntiCheatVehInfo[pvehid][acDriver] != playerid)
						{
							#if defined OnCheatDetected
								KickWithCode(playerid, "", 0, 32);
							#else
								return ClearAnimations(playerid, 1);
							#endif
						}
						if(AntiCheatInfo[playerid][acACAllow][35] && GetPlayerCameraMode(playerid) == 55)
						{
							#if defined OnCheatDetected
								KickWithCode(playerid, "", 0, 35);
							#else
								return KickWithCode(playerid, "", 0, 35);
							#endif
						}
						static Float:vhealth;
						GetVehicleHealth(pvehid, vhealth);
						if(AntiCheatInfo[playerid][acSetVehHealth] != -1)
						{
							if(vhealth == AntiCheatInfo[playerid][acSetVehHealth]) AntiCheatInfo[playerid][acSetVehHealth] = -1;
							else if(AntiCheatInfo[playerid][acACAllow][52] && gtc > AntiCheatInfo[playerid][acGtc][4]
							+ gpp && ++AntiCheatInfo[playerid][acNOPCount][4] > MAX_NOP_WARNINGS)
							{
								#if defined DEBUG
									printf(DEBUG_CODE_5, playerid, "SetVehicleHealth");
								#endif
								#if defined OnCheatDetected
									AntiCheatInfo[playerid][acSetVehHealth] = -1;
									KickWithCode(playerid, "", 0, 52, 11);
								#else
									return KickWithCode(playerid, "", 0, 52, 11);
								#endif
							}
						}
						else if(AntiCheatInfo[playerid][acACAllow][11] && vhealth >
						AntiCheatVehInfo[pvehid][acHealth] && !AntiCheatInfo[playerid][acModShop]
						&& !IsPlayerInPayNSpray(playerid, i))
						{
							#if defined OnCheatDetected
								KickWithCode(playerid, "", 0, 11);
							#else
								return KickWithCode(playerid, "", 0, 11);
							#endif
						}
						if(AntiCheatInfo[playerid][acACAllow][20]
						&& AntiCheatInfo[playerid][acVehDmgRes])
						{
							if(vhealth < AntiCheatVehInfo[pvehid][acHealth])
							{
								AntiCheatInfo[playerid][acVehDmgRes] = false;
								AntiCheatInfo[playerid][acCheatCount][11] = 0;
							}
							else if(gtc > AntiCheatInfo[playerid][acGtc][16] + gpp)
							{
								AntiCheatInfo[playerid][acVehDmgRes] = false;
								if(++AntiCheatInfo[playerid][acCheatCount][11] >
								MAX_GODMODE_VEH_WARNINGS)
								{
									#if defined OnCheatDetected
										AntiCheatInfo[playerid][acCheatCount][11] = 0;
										KickWithCode(playerid, "", 0, 20);
									#else
										return KickWithCode(playerid, "", 0, 20);
									#endif
								}
							}
						}
						static Float:zangle;
						GetVehicleZAngle(pvehid, zangle);
						while(zangle < 0.0) zangle += 360.0;
						while(zangle > 360.0) zangle -= 360.0;
						GetVehicleVelocity(pvehid, pvelX, pvelY, pvelZ);
						if(gtc > AntiCheatInfo[playerid][acGtc][9] + gpp)
						{
							i = GetVehicleModel(pvehid) - 400;
							static Float:vsp, Float:spdiff;
							vsp = GetSpeed(pvelX,pvelY,pvelZ);
							spdiff = vsp - GetSpeed(AntiCheatVehInfo[pvehid][acVel][0],AntiCheatVehInfo[pvehid][acVel][1],AntiCheatVehInfo[pvehid][acVel][2]);
							if(AntiCheatInfo[playerid][acACAllow][10] && spdiff >= 20.0 && AntiCheatVehInfo[pvehid][acHealth] == vhealth
							&& AntiCheatVehInfo[pvehid][acHealth] > 220.0 && AntiCheatVehInfo[pvehid][acSpeedDiff] <= spdiff && (VehicleTypes[i] != 2
							|| floatabs(pvelX) > 0.3 || floatabs(pvelY) > 0.3 || floatabs(pvelZ) > 0.3))
							{
								#if defined OnCheatDetected
									KickWithCode(playerid, "", 0, 10, 1);
								#else
									return KickWithCode(playerid, "", 0, 10, 1);
								#endif
							}
							if(AntiCheatInfo[playerid][acACAllow][25] && vsp > 15.0 && floatabs(spdiff) < 25.0
							&& floatround(floatabs(zangle - AntiCheatVehInfo[pvehid][acZAngle])) == 180 && (pvelX < 0.0)
							!= (AntiCheatVehInfo[pvehid][acVel][0] < 0.0) && (pvelY < 0.0) != (AntiCheatVehInfo[pvehid][acVel][1] < 0.0)
							&& (pvelZ < 0.0) != (AntiCheatVehInfo[pvehid][acVel][2] < 0.0))
							{
								#if defined OnCheatDetected
									KickWithCode(playerid, "", 0, 25);
								#else
									return KickWithCode(playerid, "", 0, 25);
								#endif
							}
							static Float:zdiff;
							zdiff = pposZ - AntiCheatInfo[playerid][acPos][2];
							if(VehicleTypes[i] == 1)
							{
								if(AntiCheatInfo[playerid][acACAllow][10] && vsp > 269.0)
								{
									#if defined OnCheatDetected
										KickWithCode(playerid, "", 0, 10, 2);
									#else
										return KickWithCode(playerid, "", 0, 10, 2);
									#endif
								}
							}
							else if(AntiCheatInfo[playerid][acACAllow][8])
							{
								if(pvelZ >= 0.1 && pvelZ > AntiCheatVehInfo[pvehid][acVel][2]
								&& floatabs(AntiCheatInfo[playerid][acPos][0] - pposX) < zdiff * 1.2
								&& floatabs(AntiCheatInfo[playerid][acPos][1] - pposY) < zdiff * 1.2)
								{
									if(++AntiCheatInfo[playerid][acCheatCount][3] > (VehicleTypes[i] == 2
									? MAX_FLYHACK_BIKE_WARNINGS : MAX_FLYHACK_VEH_WARNINGS))
									{
										#if defined OnCheatDetected
											AntiCheatInfo[playerid][acCheatCount][3] = 0;
											KickWithCode(playerid, "", 0, 8, 1);
										#else
											return KickWithCode(playerid, "", 0, 8, 1);
										#endif
									}
								}
								else AntiCheatInfo[playerid][acCheatCount][3] = 0;
							}
							if(vctsize > 0.4 && gtc > AntiCheatInfo[playerid][acGtc][11] + gpp)
							{
								if(vctsize > 15.0 && vctsize > AntiCheatVehInfo[pvehid][acPosDiff] + ((vctsize / 3) * 1.5))
								{
									if(AntiCheatInfo[playerid][acACAllow][3] && AntiCheatInfo[playerid][acPos][2] > -97.0)
									{
										#if defined OnCheatDetected
											KickWithCode(playerid, "", 0, 3, 2);
										#else
											return KickWithCode(playerid, "", 0, 3, 2);
										#endif
									}
								}
								else if(AntiCheatInfo[playerid][acACAllow][1] && vsp < 16.0 && vctsize > 0.8)
								{
									if(++AntiCheatInfo[playerid][acCheatCount][2] > MAX_AIR_VEH_WARNINGS)
									{
										#if defined OnCheatDetected
											AntiCheatInfo[playerid][acCheatCount][2] = 0;
											KickWithCode(playerid, "", 0, 1);
										#else
											return KickWithCode(playerid, "", 0, 1);
										#endif
									}
									#undef MAX_AIR_VEH_WARNINGS
								}
								else AntiCheatInfo[playerid][acCheatCount][2] = 0;
							}
							AntiCheatVehInfo[pvehid][acSpeedDiff] = spdiff;
						}
						AntiCheatVehInfo[pvehid][acVel][0] = pvelX;
						AntiCheatVehInfo[pvehid][acVel][1] = pvelY;
						AntiCheatVehInfo[pvehid][acVel][2] = pvelZ;
						AntiCheatVehInfo[pvehid][acPosDiff] = vctsize;
						AntiCheatVehInfo[pvehid][acHealth] = vhealth;
						AntiCheatVehInfo[pvehid][acZAngle] = zangle;
					}
					AntiCheatInfo[playerid][acSeat] = s;
				}
				else
				{
					stateanim = GetPlayerAnimationIndex(playerid);
					GetPlayerVelocity(playerid, pvelX, pvelY, pvelZ);
					pvelX = GetSpeed(pvelX,pvelY,pvelZ);
					if(AntiCheatInfo[playerid][acAnim] != stateanim)
					{
						switch(stateanim)
						{
							case -1:
							{
								if(AntiCheatInfo[playerid][acACAllow][24])
								{
									#if defined OnCheatDetected
										KickWithCode(playerid, "", 0, 24);
									#else
										return KickWithCode(playerid, "", 0, 24);
									#endif
								}
							}
							case 958..979:
							{
								if(AntiCheatInfo[playerid][acACAllow][7] && w != 46)
								{
									#if defined OnCheatDetected
										KickWithCode(playerid, "", 0, 7, 1);
									#else
										return KickWithCode(playerid, "", 0, 7, 1);
									#endif
								}
							}
							case 1058:
							{
								if(AntiCheatInfo[playerid][acACAllow][7])
								{
									#if defined OnCheatDetected
										KickWithCode(playerid, "", 0, 7, 2);
									#else
										return KickWithCode(playerid, "", 0, 7, 2);
									#endif
								}
							}
							case 1231:
							{
								if(AntiCheatInfo[playerid][acACAllow][30])
								{
									i = GetPlayerSkin(playerid);
									if(!PedAnims && i && i != 74)
									{
										#if defined OnCheatDetected
											KickWithCode(playerid, "", 0, 30);
										#else
											return KickWithCode(playerid, "", 0, 30);
										#endif
									}
								}
							}
						}
					}
					else if(AntiCheatInfo[playerid][acACAllow][7]
					&& pvelX > 30.0 && 1537 < stateanim < 1545)
					{
						#if defined OnCheatDetected
							KickWithCode(playerid, "", 0, 7, 3);
						#else
							return KickWithCode(playerid, "", 0, 7, 3);
						#endif
					}
					if(AntiCheatInfo[playerid][acSet][4] != -1)
					{
						if(specact == AntiCheatInfo[playerid][acSet][4])
						{
							AntiCheatInfo[playerid][acSet][4] = -1;
							AntiCheatInfo[playerid][acSpecAct] = specact;
						}
						else if(AntiCheatInfo[playerid][acACAllow][52] && gtc > AntiCheatInfo[playerid][acGtc][6]
						+ gpp && ++AntiCheatInfo[playerid][acNOPCount][6] > MAX_NOP_WARNINGS)
						{
							#if defined DEBUG
								printf(DEBUG_CODE_5, playerid, "SetPlayerSpecialAction");
							#endif
							#if defined OnCheatDetected
								AntiCheatInfo[playerid][acSet][4] = -1;
								KickWithCode(playerid, "", 0, 52, 12);
							#else
								return KickWithCode(playerid, "", 0, 52, 12);
							#endif
						}
					}
					else if(specact != AntiCheatInfo[playerid][acSpecAct])
					{
						if(specact == AntiCheatInfo[playerid][acNextSpecAct]) AntiCheatInfo[playerid][acNextSpecAct] = -1;
						else if(AntiCheatInfo[playerid][acACAllow][18])
						{
							switch(specact)
							{
								case 0:
								{
									switch(AntiCheatInfo[playerid][acSpecAct])
									{
										case 11, 24, 25:
										{
											#if defined OnCheatDetected
												KickWithCode(playerid, "", 0, 18, 1);
											#else
												return KickWithCode(playerid, "", 0, 18, 1);
											#endif
										}
									}
								}
								case 1:
								{
									if(AntiCheatInfo[playerid][acSpecAct]
									&& !(19 < AntiCheatInfo[playerid][acSpecAct] < 25))
									{
										#if defined OnCheatDetected
											KickWithCode(playerid, "", 0, 18, 2);
										#else
											return KickWithCode(playerid, "", 0, 18, 2);
										#endif
									}
								}
								case 2:
								{
									if(!IsPlayerInRangeOfPoint(playerid, 5.0, AntiCheatInfo[playerid][acDropJP][0],
									AntiCheatInfo[playerid][acDropJP][1], AntiCheatInfo[playerid][acDropJP][2]))
									{
										#if defined OnCheatDetected
											KickWithCode(playerid, "", 0, 18, 3);
										#else
											return KickWithCode(playerid, "", 0, 18, 3);
										#endif
									}
									AntiCheatInfo[playerid][acDropJP][0] =
									AntiCheatInfo[playerid][acDropJP][1] =
									AntiCheatInfo[playerid][acDropJP][2] = 20001.0;
								}
								case 3:
								{
									switch(AntiCheatInfo[playerid][acSpecAct])
									{
										case 2, 5..8, 11, 68:
										{
											#if defined OnCheatDetected
												KickWithCode(playerid, "", 0, 18, 4);
											#else
												return KickWithCode(playerid, "", 0, 18, 4);
											#endif
										}
									}
								}
								default:
								{
									if(!(19 < specact < 25 && AntiCheatInfo[playerid][acSpecAct] == 1 && specact ==
									AntiCheatInfo[playerid][acLastSpecAct]) && !((specact == 4 || specact == 11 || specact == 24
									|| specact == 25) && AntiCheatInfo[playerid][acVeh]) && !(AntiCheatInfo[playerid][acSpecAct] == 3
									&& specact == AntiCheatInfo[playerid][acLastSpecAct]))
									{
										#if defined OnCheatDetected
											KickWithCode(playerid, "", 0, 18, 5);
										#else
											return KickWithCode(playerid, "", 0, 18, 5);
										#endif
									}
								}
							}
						}
						AntiCheatInfo[playerid][acLastSpecAct] = AntiCheatInfo[playerid][acSpecAct];
					}
					if(gtc > AntiCheatInfo[playerid][acGtc][10] + gpp
					&& GetPlayerSurfingVehicleID(playerid) == 65535
					&& GetPlayerSurfingObjectID(playerid) == 65535)
					{
						if(AntiCheatInfo[playerid][acACAllow][9] && pvelX > 211.0
						&& AntiCheatInfo[playerid][acSpeed] < pvelX)
						{
							#if defined OnCheatDetected
								KickWithCode(playerid, "", 0, 9);
							#else
								return KickWithCode(playerid, "", 0, 9);
							#endif
						}
						if(vctsize > 0.5 && gtc > AntiCheatInfo[playerid][acGtc][11] + gpp)
						{
							if(vctsize > 30.0)
							{
								if(AntiCheatInfo[playerid][acACAllow][2]
								&& AntiCheatInfo[playerid][acPos][2] > -97.0)
								{
									#if defined OnCheatDetected
										KickWithCode(playerid, "", 0, 2, 2);
									#else
										return KickWithCode(playerid, "", 0, 2, 2);
									#endif
								}
							}
							else if(pvelX <= vctsize * (vctsize < 1.0 ? 30.0 : 5.0))
							{
								if(pvelX < 3.0 && vctsize > 3.0)
								{
									if(AntiCheatInfo[playerid][acACAllow][2])
									{
										#if defined OnCheatDetected
											KickWithCode(playerid, "", 0, 2, 3);
										#else
											return KickWithCode(playerid, "", 0, 2, 3);
										#endif
									}
								}
								else if(AntiCheatInfo[playerid][acACAllow][0] && pvelX
								&& ++AntiCheatInfo[playerid][acCheatCount][1] > MAX_AIR_WARNINGS)
								{
									#if defined OnCheatDetected
										AntiCheatInfo[playerid][acCheatCount][1] = 0;
										KickWithCode(playerid, "", 0, 0);
									#else
										return KickWithCode(playerid, "", 0, 0);
									#endif
								}
								#undef MAX_AIR_WARNINGS
							}
						}
						AntiCheatInfo[playerid][acSpeed] = pvelX;
					}
					AntiCheatInfo[playerid][acAnim] = stateanim;
				}
				AntiCheatInfo[playerid][acSpecAct] = specact;
				AntiCheatInfo[playerid][acHealth] = floatround(health, floatround_tozero);
				AntiCheatInfo[playerid][acArmour] = floatround(armour, floatround_tozero);
			}
			AntiCheatInfo[playerid][acPos][0] = pposX;
			AntiCheatInfo[playerid][acPos][1] = pposY;
			AntiCheatInfo[playerid][acPos][2] = pposZ;
			AntiCheatInfo[playerid][acLastWeapon] = w;
			AntiCheatInfo[playerid][acVeh] = pvehid;
			AntiCheatInfo[playerid][acMoney] = a;
		}
	}
	gpp = 1;
	AntiCheatInfo[playerid][acLastUpdate] = gtc;
	if(ur) AntiCheatInfo[playerid][acGtc][15] = gtc;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerUpdate
		gpp = ac_OnPlayerUpdate(playerid);
	#endif
	if(AntiCheatInfo[playerid][acACAllow][33]
	&& gpp) return AntiCheatInfo[playerid][acFreeze];
	return gpp;
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
	Hook:ac_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#else
	public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#endif
{
	if(newkeys & 16 && AntiCheatInfo[playerid][acSpecAct] ==
	2 && GetPlayerSpecialAction(playerid) != 2)
	{
		AntiCheatInfo[playerid][acDropJP][0] = AntiCheatInfo[playerid][acPos][0];
		AntiCheatInfo[playerid][acDropJP][1] = AntiCheatInfo[playerid][acPos][1];
		AntiCheatInfo[playerid][acDropJP][2] = AntiCheatInfo[playerid][acPos][2];
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
	Hook:ac_OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
#else
	public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][2] + Mtfc[2][0]) return FloodDetect(playerid, 2);
		if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][2] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][2] = i;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerClickMap
		return ac_OnPlayerClickMap(playerid, fX, fY, fZ);
	#else
		return 1;
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
	Hook:ac_OnPlayerClickPlayer(playerid, clickedplayerid, source)
#else
	public OnPlayerClickPlayer(playerid, clickedplayerid, source)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][3] + Mtfc[3][0]) return FloodDetect(playerid, 3);
		if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][3] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][3] = i;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerClickPlayer
		return ac_OnPlayerClickPlayer(playerid, clickedplayerid, source);
	#else
		return 1;
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
	Hook:ac_OnPlayerClickTextDraw(playerid, Text:clickedid)
#else
	public OnPlayerClickTextDraw(playerid, Text:clickedid)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][4] + Mtfc[4][0]) return FloodDetect(playerid, 4);
		if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][4] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][4] = i;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerClickTextDraw
		return ac_OnPlayerClickTextDraw(playerid, clickedid);
	#else
		return 1;
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
	Hook:ac_OnPlayerCommandText(playerid, cmdtext[])
#else
	public OnPlayerCommandText(playerid, cmdtext[])
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 1;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][5] + Mtfc[5][0])
		{
			FloodDetect(playerid, 5);
			return 1;
		}
		if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][5] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][5] = i;
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
	Hook:ac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
#else
	public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][acKicked]) return 0;
	new bool:ur;
	if(!IsPlayerNPC(playerid))
	{
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][6] + Mtfc[6][0]) return FloodDetect(playerid, 6);
			if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][6] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][6] = i;
		i = GetVehicleModel(vehicleid);
		if(AntiCheatInfo[playerid][acACAllow][44]
		&& i == -1) return KickWithCode(playerid, "", 0, 44, 1);
		new Float:TmpPosX, Float:TmpPosY, Float:TmpPosZ;
		GetVehiclePos(vehicleid, TmpPosX, TmpPosY, TmpPosZ);
		TmpPosX = VectorSize(AntiCheatInfo[playerid][acPos][0]
		- TmpPosX, AntiCheatInfo[playerid][acPos][1] - TmpPosY,
		AntiCheatInfo[playerid][acPos][2] - TmpPosZ);
		if(AntiCheatInfo[playerid][acACAllow][4] && (!(i == 577
		|| i == 592) && TmpPosX > 15.0 || TmpPosX > 40.0))
		{
			#if defined OnCheatDetected
				KickWithCode(playerid, "", 0, 4, 3);
			#else
				return KickWithCode(playerid, "", 0, 4, 3);
			#endif
		}
		if(AntiCheatInfo[playerid][acEnterVeh] == vehicleid) ur = true;
		else
		{
			new TmpPrm1, TmpPrm2;
			GetVehicleParamsEx(vehicleid, TmpPrm2, TmpPrm2,
			TmpPrm2, TmpPrm1, TmpPrm2, TmpPrm2, TmpPrm2);
			if(TmpPrm1 != 1)
			{
				AntiCheatInfo[playerid][acEnterVeh] = vehicleid;
				if(VehicleTypes[i - 400] == 3) AntiCheatInfo[playerid][acEnterVehTime] = 0, ur = true;
			}
		}
	}
	if(!ur) AntiCheatInfo[playerid][acEnterVehTime] = AntiCheatInfo[playerid][acCall][27];
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
	Hook:ac_OnPlayerExitVehicle(playerid, vehicleid)
#else
	public OnPlayerExitVehicle(playerid, vehicleid)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(!IsPlayerNPC(playerid) && AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][7] + Mtfc[7][0]) return FloodDetect(playerid, 7);
		if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][7] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	switch(GetVehicleModel(AntiCheatInfo[playerid][acVeh]))
	{
		case 417, 425, 447, 469, 476, 487, 488, 497, 511, 512, 513, 519, 520,
		548, 553, 563, 577, 592, 593: AntiCheatInfo[playerid][acParachute] = true;
		default: AntiCheatInfo[playerid][acParachute] = false;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][7] = i;
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
	&& defined IsValidDynamicPickup
	#if defined _inc_y_hooks || defined _INC_y_hooks
		#if defined STREAMER_ENABLE_TAGS
			Hook:ac_OnPlayerPickUpDynamicPickup(playerid, STREAMER_TAG_PICKUP pickupid)
		#else
			Hook:ac_OnPlayerPickUpDynamicPickup(playerid, pickupid)
		#endif
	#else
		#if defined STREAMER_ENABLE_TAGS
			public OnPlayerPickUpDynamicPickup(playerid, STREAMER_TAG_PICKUP pickupid)
		#else
			public OnPlayerPickUpDynamicPickup(playerid, pickupid)
		#endif
	#endif
	{
		if(!IsPlayerConnected(playerid) || AntiCheatInfo[playerid][acKicked]
		|| !IsValidDynamicPickup(pickupid)) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][8] + Mtfc[8][0]) FloodDetect(playerid, 8);
			else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][8] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		if(AntiCheatInfo[playerid][acACAllow][6] && !IsPlayerInRangeOfPoint(playerid, 5.0,
		AntiCheatDPickInfo[pickupid][acPos][0], AntiCheatDPickInfo[pickupid][acPos][1],
		AntiCheatDPickInfo[pickupid][acPos][2]))
		{
			#if defined OnCheatDetected
				KickWithCode(playerid, "", 0, 6, 2);
			#else
				return KickWithCode(playerid, "", 0, 6, 2);
			#endif
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][8] = i;
		switch(AntiCheatDPickInfo[pickupid][acType])
		{
			case 1:
			{
				i = WeaponSlots[AntiCheatDPickInfo[pickupid][acWeapon]];
				if(AntiCheatInfo[playerid][acWeapon][i] ==
				AntiCheatDPickInfo[pickupid][acWeapon]) AntiCheatInfo[playerid][acAmmo][i] +=
				PickupAmmo[AntiCheatDPickInfo[pickupid][acWeapon]];
			}
			case 2: AntiCheatInfo[playerid][acSpecAct] = 2;
			case 3: AntiCheatInfo[playerid][acHealth] = 100;
			case 4: AntiCheatInfo[playerid][acArmour] = 100;
		}
		AntiCheatInfo[playerid][acLastPickup] = pickupid + MAX_PICKUPS;
		AntiCheatInfo[playerid][acPicked] = true;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnPlayerPickUpDynamicPickup
			return ac_OnPlayerPickUpDynamicPickup(playerid, pickupid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnPlayerPick\
			UpDynamicPickup
			#undef OnPlayerPickUpDynamicPickup
		#else
			#define _ALS_OnPlayerPickUpDynamicPickup
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
	Hook:ac_OnPlayerPickUpPickup(playerid, pickupid)
#else
	public OnPlayerPickUpPickup(playerid, pickupid)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][acKicked]) return 0;
	if(!AntiCheatInfo[playerid][acPicked])
	{
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][8] + Mtfc[8][0]) FloodDetect(playerid, 8);
			else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][8] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		if(AntiCheatInfo[playerid][acACAllow][6]
		&& (!(-1 < pickupid < MAX_PICKUPS) || !IsPlayerInRangeOfPoint(playerid,
		5.0, AntiCheatPickInfo[pickupid][acPos][0], AntiCheatPickInfo[pickupid][acPos][1],
		AntiCheatPickInfo[pickupid][acPos][2])))
		{
			#if defined OnCheatDetected
				KickWithCode(playerid, "", 0, 6, 1);
			#else
				return KickWithCode(playerid, "", 0, 6, 1);
			#endif
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][8] = i;
		switch(AntiCheatPickInfo[pickupid][acType])
		{
			case 1:
			{
				i = WeaponSlots[AntiCheatPickInfo[pickupid][acWeapon]];
				if(AntiCheatInfo[playerid][acWeapon][i] ==
				AntiCheatPickInfo[pickupid][acWeapon]) AntiCheatInfo[playerid][acAmmo][i] +=
				PickupAmmo[AntiCheatPickInfo[pickupid][acWeapon]];
			}
			case 2: AntiCheatInfo[playerid][acSpecAct] = 2;
			case 3: AntiCheatInfo[playerid][acHealth] = 100;
			case 4: AntiCheatInfo[playerid][acArmour] = 100;
		}
		AntiCheatInfo[playerid][acLastPickup] = pickupid;
	}
	else AntiCheatInfo[playerid][acPicked] = false;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerPickUpPickup
		if(!AntiCheatPickInfo[pickupid][acIsStatic]) return ac_OnPlayerPickUpPickup(playerid, pickupid);
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
	Hook:ac_OnPlayerRequestClass(playerid, classid)
#else
	public OnPlayerRequestClass(playerid, classid)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][9] + Mtfc[9][0]) return FloodDetect(playerid, 9);
		if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][9] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acClassid] = classid;
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][9] = i;
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
	Hook:ac_OnPlayerSelectedMenuRow(playerid, row)
#else
	public OnPlayerSelectedMenuRow(playerid, row)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][10] + Mtfc[10][0]) FloodDetect(playerid, 10);
		else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][10] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][10] = i;
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
	Hook:ac_OnPlayerStateChange(playerid, newstate, oldstate)
#else
	public OnPlayerStateChange(playerid, newstate, oldstate)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount(), bool:ur;
	if(!IsPlayerNPC(playerid))
	{
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][11] + Mtfc[11][0])
			{
				if(newstate != 1 || oldstate != 8) FloodDetect(playerid, 11);
			}
			else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][11] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		if(1 < oldstate < 4)
		{
			switch(oldstate)
			{
				case 2:
				{
					if(AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acDriver] ==
					playerid) AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acDriver] = 65535;
					if(GetVehicleModel(AntiCheatInfo[playerid][acVeh]) == 457
					&& !AntiCheatInfo[playerid][acWeapon][1]) AntiCheatInfo[playerid][acWeapon][1] = 2;
				}
				case 3:
				{
					if(AntiCheatInfo[playerid][acACAllow][2]
					&& newstate == 1 && !IsPlayerInRangeOfPoint(playerid, 15.0,
					AntiCheatInfo[playerid][acPos][0], AntiCheatInfo[playerid][acPos][1],
					AntiCheatInfo[playerid][acPos][2]) && !(AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acDriver]
					!= 65535 && i > AntiCheatInfo[AntiCheatVehInfo[AntiCheatInfo[playerid][acVeh]][acDriver]][acLastUpdate]
					+ 2000)) KickWithCode(playerid, "", 0, 2, 4);
				}
			}
			new Float:TmpVelX, Float:TmpVelY, Float:TmpVelZ;
			GetPlayerVelocity(playerid, TmpVelX, TmpVelY, TmpVelZ);
			AntiCheatInfo[playerid][acSpeed] = GetSpeed(TmpVelX,TmpVelY,TmpVelZ);
			ur = true;
		}
		switch(newstate)
		{
			case 1:
			{
				AntiCheatInfo[playerid][acSet][11] = -1;
				AntiCheatInfo[playerid][acEnterVeh] = 0;
				GetPlayerPos(playerid, AntiCheatInfo[playerid][acPos][0],
				AntiCheatInfo[playerid][acPos][1], AntiCheatInfo[playerid][acPos][2]);
			}
			case 2:
			{
				i = GetPlayerVehicleID(playerid);
				if(AntiCheatInfo[playerid][acACAllow][44])
				{
					new seatid;
					if((seatid = GetPlayerVehicleSeat(playerid)) != 128)
					{
						new model = GetVehicleModel(i) - 400;
						if(seatid || model < 0 || MaxPassengers[model >>> 3] >>> ((model & 7) << 2) & 0xF == 15
						&& AntiCheatInfo[playerid][acSet][9] == -1) KickWithCode(playerid, "", 0, 44, 2);
					}
				}
				if(AntiCheatInfo[playerid][acSet][9] == -1)
				{
					AntiCheatVehInfo[i][acDriver] = playerid;
					GetVehicleZAngle(i, AntiCheatVehInfo[i][acZAngle]);
					GetPlayerPos(playerid, AntiCheatInfo[playerid][acPos][0],
					AntiCheatInfo[playerid][acPos][1], AntiCheatInfo[playerid][acPos][2]);
					AntiCheatInfo[playerid][acCheatCount][11] = 0;
					AntiCheatInfo[playerid][acVehDmgRes] = false;
					AntiCheatInfo[playerid][acSetVehHealth] = -1;
				}
			}
			case 3:
			{
				AntiCheatInfo[playerid][acCheatCount][4] = 0;
				if(AntiCheatInfo[playerid][acACAllow][44] && (i = GetPlayerVehicleSeat(playerid)) != 128)
				{
					if(GetVehicleModel(GetPlayerVehicleID(playerid)) ==
					-1) KickWithCode(playerid, "", 0, 44, 3);
					else
					{
						new model = (MaxPassengers[model >>> 3] >>> ((model & 7) << 2)) & 0xF;
						if(i < 1 || (model == 15 || i > model)
						&& AntiCheatInfo[playerid][acSet][9] ==
						-1) KickWithCode(playerid, "", 0, 44, 4);
					}
				}
			}
			case 9:
			{
				if(AntiCheatInfo[playerid][acACAllow][21]
				&& AntiCheatInfo[playerid][acSet][6] ==
				-1) KickWithCode(playerid, "", 0, 21);
				AntiCheatInfo[playerid][acSet][6] = -1;
				AntiCheatInfo[playerid][acSpawnRes] = true;
				AntiCheatInfo[playerid][acSpawnTime] = 0;
			}
		}
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][11] = GetTickCount();
	if(ur) AntiCheatInfo[playerid][acGtc][10] = AntiCheatInfo[playerid][acCall][27];
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
	Hook:ac_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
#else
	public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	static i, gtc, bool:ur, bool:ur2;
	gtc = GetTickCount();
	ur = ur2 = false;
	if(!IsPlayerNPC(playerid))
	{
		if(AntiCheatInfo[playerid][acACAllow][22]
		&& !LagCompMode) return KickWithCode(playerid, "", 0, 22);
		if(!(-1 < hittype < 5) || hittype == 1 && !IsPlayerConnected(hitid)
		|| hittype == 2 && GetVehicleModel(hitid) == -1 || hittype == 3 && !IsValidObject(hitid)
		|| hittype == 4 && !IsValidPlayerObject(playerid, hitid)) return KickWithCode(playerid, "", 0, 47);
		if(AntiCheatInfo[playerid][acACAllow][34])
		{
			if(gtc > AntiCheatInfo[playerid][acLastUpdate] + 5000)
			{
				if(++AntiCheatInfo[playerid][acCheatCount][5] >
				MAX_AFK_GHOST_WARNINGS)
				{
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acCheatCount][5] = 0;
						KickWithCode(playerid, "", 0, 34);
					#else
						return KickWithCode(playerid, "", 0, 34);
					#endif
				}
				#undef MAX_AFK_GHOST_WARNINGS
			}
			else AntiCheatInfo[playerid][acCheatCount][5] = 0;
		}
		if(AntiCheatInfo[playerid][acACAllow][29])
		{
			if(hittype && !fX && !fY && !fZ)
			{
				if(++AntiCheatInfo[playerid][acCheatCount][13] > MAX_SILENT_AIM_WARNINGS)
				{
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acCheatCount][13] = 0;
						KickWithCode(playerid, "", 0, 29, 1);
					#else
						return KickWithCode(playerid, "", 0, 29, 1);
					#endif
				}
				#undef MAX_SILENT_AIM_WARNINGS
			}
			else
			{
				AntiCheatInfo[playerid][acCheatCount][13] = 0;
				if(hittype == 1 && gtc < AntiCheatInfo[hitid][acLastUpdate] + 1500 && !IsPlayerInAnyVehicle(hitid)
				&& GetPlayerSurfingVehicleID(hitid) == 65535 && GetPlayerSurfingObjectID(hitid) == 65535)
				{
					static Float:fPosX, Float:fPosY, Float:fPosZ, Float:fPosD;
					GetPlayerLastShotVectors(playerid, fPosD, fPosD, fPosD, fPosX, fPosY, fPosZ);
					if(!IsPlayerInRangeOfPoint(hitid, 5.0, fPosX, fPosY, fPosZ))
					{
						if(++AntiCheatInfo[playerid][acCheatCount][6] > MAX_PRO_AIM_WARNINGS)
						{
							#if defined OnCheatDetected
								AntiCheatInfo[playerid][acCheatCount][6] = 0;
								KickWithCode(playerid, "", 0, 29, 2);
							#else
								return KickWithCode(playerid, "", 0, 29, 2);
							#endif
						}
						#undef MAX_PRO_AIM_WARNINGS
					}
					else AntiCheatInfo[playerid][acCheatCount][6] = 0;
				}
			}
		}
		switch(hittype)
		{
			case 1:
			{
				if(AntiCheatInfo[hitid][acACAllow][19]
				&& AntiCheatInfo[hitid][acFreeze])
				{
					static t, j;
					t = GetPlayerTeam(playerid);
					j = GetPlayerInterior(hitid);
					if((t == 255 || t != GetPlayerTeam(hitid))
					&& AntiCheatInfo[hitid][acHealth] && !IsPlayerInRestaurant(hitid, j)
					&& !IsPlayerInAmmuNation(hitid, j) && !IsPlayerInCasino(hitid, j)) ur = true;
				}
			}
			case 2:
			{
				if(AntiCheatInfo[hitid][acACAllow][20]
				&& AntiCheatVehInfo[hitid][acDriver] != 65535
				&& AntiCheatInfo[AntiCheatVehInfo[hitid][acDriver]][acFreeze]
				&& AntiCheatVehInfo[hitid][acHealth] > 220.0)
				{
					static t;
					t = GetPlayerTeam(playerid);
					if(!VehFriendlyFire || t == 255 || t
					!= GetPlayerTeam(AntiCheatVehInfo[hitid][acDriver])) ur2 = true;
				}
			}
		}
		if(GetPlayerState(playerid) != 2)
		{
			if(AntiCheatInfo[playerid][acACAllow][26])
			{
				i = gtc - AntiCheatInfo[playerid][acShotTime];
				if(AntiCheatInfo[playerid][acLastShot] == weaponid)
				{
					if(weaponid != 38)
					{
						if(gtc < AntiCheatInfo[playerid][acReload] + 800)
						{
							#if defined OnCheatDetected
								AntiCheatInfo[playerid][acReload] = gtc - 800;
								KickWithCode(playerid, "", 0, 26, 4);
							#else
								return KickWithCode(playerid, "", 0, 26, 4);
							#endif
						}
						else if(27 < weaponid < 30 || weaponid == 32)
						{
							if(i < 30 && ++AntiCheatInfo[playerid][acCheatCount][8] >
							MAX_RAPID_FIRE_WARNINGS)
							{
								#if defined OnCheatDetected
									AntiCheatInfo[playerid][acCheatCount][8] = 0;
									KickWithCode(playerid, "", 0, 26, 1);
								#else
									return KickWithCode(playerid, "", 0, 26, 1);
								#endif
							}
						}
						else if(i < 50 || 32 < weaponid < 35 && i < 386)
						{
							if(++AntiCheatInfo[playerid][acCheatCount][8] >
							MAX_RAPID_FIRE_WARNINGS)
							{
								#if defined OnCheatDetected
									AntiCheatInfo[playerid][acCheatCount][8] = 0;
									KickWithCode(playerid, "", 0, 26, 2);
								#else
									return KickWithCode(playerid, "", 0, 26, 2);
								#endif
							}
						}
						else AntiCheatInfo[playerid][acCheatCount][8] = 0;
					}
				}
				else
				{
					if(i < 30)
					{
						#if defined OnCheatDetected
							KickWithCode(playerid, "", 0, 26, 3);
						#else
							return KickWithCode(playerid, "", 0, 26, 3);
						#endif
					}
					AntiCheatInfo[playerid][acCheatCount][8] = 0;
				}
				if(GetPlayerWeaponState(playerid) == 1) AntiCheatInfo[playerid][acReload] = gtc;
			}
			if(AntiCheatInfo[playerid][acACAllow][17])
			{
				static a;
				a = GetPlayerAmmo(playerid);
				if(!AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]])
				{
					#if defined OnCheatDetected
						AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]] = a;
						KickWithCode(playerid, "", 0, 17, 1);
					#else
						return KickWithCode(playerid, "", 0, 17, 1);
					#endif
				}
				if((i = abs(AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]] - a)))
				{
					switch(weaponid)
					{
						case 24, 29:
						{
							if(i > 2 || ++AntiCheatInfo[playerid][acCheatCount][7] > 2)
							{
								#if defined OnCheatDetected
									AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]] = a;
									AntiCheatInfo[playerid][acCheatCount][7] = 0;
									KickWithCode(playerid, "", 0, 17, 2);
								#else
									return KickWithCode(playerid, "", 0, 17, 2);
								#endif
							}
						}
						case 22, 26, 30, 31:
						{
							if(i > 3 || ++AntiCheatInfo[playerid][acCheatCount][7] > 3)
							{
								#if defined OnCheatDetected
									AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]] = a;
									AntiCheatInfo[playerid][acCheatCount][7] = 0;
									KickWithCode(playerid, "", 0, 17, 3);
								#else
									return KickWithCode(playerid, "", 0, 17, 3);
								#endif
							}
						}
						case 28, 32:
						{
							if(i > 8)
							{
								#if defined OnCheatDetected
									AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]] = a;
									KickWithCode(playerid, "", 0, 17, 4);
								#else
									return KickWithCode(playerid, "", 0, 17, 4);
								#endif
							}
						}
						case 38:
						{
							if(++AntiCheatInfo[playerid][acCheatCount][7] > 8)
							{
								#if defined OnCheatDetected
									AntiCheatInfo[playerid][acCheatCount][7] = 0;
									KickWithCode(playerid, "", 0, 17, 5);
								#else
									return KickWithCode(playerid, "", 0, 17, 5);
								#endif
							}
						}
						default:
						{
							#if defined OnCheatDetected
								AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]] = a;
								KickWithCode(playerid, "", 0, 17, 6);
							#else
								return KickWithCode(playerid, "", 0, 17, 6);
							#endif
						}
					}
				}
				else AntiCheatInfo[playerid][acCheatCount][7] = 0;
			}
			AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]]--;
			if(AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]] <
			-32768) AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]] += 65536;
			else if(!AntiCheatInfo[playerid][acAmmo][WeaponSlots[weaponid]]
			&& AntiCheatInfo[playerid][acSet][3] == weaponid) AntiCheatInfo[playerid][acSet][3] =
			AntiCheatInfo[playerid][acSetWeapon][WeaponSlots[weaponid]] = -1;
		}
		AntiCheatInfo[playerid][acLastShot] = weaponid;
	}
	i = 1;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerWeaponShot
		i = ac_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, fX, fY, fZ);
	#endif
	AntiCheatInfo[playerid][acShotTime] = gtc;
	if(i)
	{
		if(ur)
		{
			if(AntiCheatInfo[hitid][acArmour]) AntiCheatInfo[hitid][acDmgRes] = 2;
			else AntiCheatInfo[hitid][acDmgRes] = 1;
			AntiCheatInfo[hitid][acGtc][14] = gtc;
		}
		if(ur2)
		{
			AntiCheatInfo[AntiCheatVehInfo[hitid][acDriver]][acVehDmgRes] = true;
			AntiCheatInfo[AntiCheatVehInfo[hitid][acDriver]][acGtc][16] = gtc;
		}
	}
	return i;
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
	Hook:ac_OnVehicleMod(playerid, vehicleid, componentid)
#else
	public OnVehicleMod(playerid, vehicleid, componentid)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][12] + Mtfc[12][0]) FloodDetect(playerid, 12);
		else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][12] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	if(AntiCheatInfo[playerid][acACAllow][23] && !AntiCheatInfo[playerid][acModShop])
	{
		#if defined OnCheatDetected
			KickWithCode(playerid, "", 0, 23, 2);
		#else
			return KickWithCode(playerid, "", 0, 23, 2);
		#endif
	}
	if(AntiCheatInfo[playerid][acACAllow][43] && !IsComponentidCompatible(GetVehicleModel(vehicleid),
	componentid)) return KickWithCode(playerid, "", 0, 43, 1);
	if(AntiCheatInfo[playerid][acSet][13] !=
	-1) AntiCheatInfo[playerid][acSet][13] += ComponentPrices[componentid - 1000];
	else AntiCheatInfo[playerid][acSet][13] = ComponentPrices[componentid - 1000];
	AntiCheatInfo[playerid][acGtc][17] = AntiCheatInfo[playerid][acCall][27]
	= AntiCheatInfo[playerid][acCall][12] = i;
	AntiCheatInfo[playerid][acCheatCount][12] = 0;
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
	Hook:ac_OnVehiclePaintjob(playerid, vehicleid, paintjobid)
#else
	public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][13] + Mtfc[13][0]) FloodDetect(playerid, 13);
		else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][13] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	if(AntiCheatInfo[playerid][acACAllow][43] && !(-1 < paintjobid < 3)) KickWithCode(playerid, "", 0, 43, 2);
	else if(AntiCheatInfo[playerid][acACAllow][23] && !AntiCheatInfo[playerid][acModShop]) KickWithCode(playerid, "", 0, 23, 4);
	else AntiCheatVehInfo[vehicleid][acPaintJob] = paintjobid;
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][13] = i;
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
	Hook:ac_OnVehicleRespray(playerid, vehicleid, color1, color2)
#else
	public OnVehicleRespray(playerid, vehicleid, color1, color2)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][14] + Mtfc[14][0]) FloodDetect(playerid, 14);
		else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][14] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][14] = i;
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
	Hook:ac_OnVehicleSpawn(vehicleid)
#else
	public OnVehicleSpawn(vehicleid)
#endif
{
	AntiCheatVehInfo[vehicleid][acPaintJob] = 3;
	AntiCheatVehInfo[vehicleid][acSpawned] = true;
	AntiCheatVehInfo[vehicleid][acHealth] = 1000.0;
	AntiCheatVehInfo[vehicleid][acSpeedDiff] =
	AntiCheatVehInfo[vehicleid][acPosDiff] =
	AntiCheatVehInfo[vehicleid][acVel][0] =
	AntiCheatVehInfo[vehicleid][acVel][1] =
	AntiCheatVehInfo[vehicleid][acVel][2] = 0.0;
	AntiCheatVehInfo[vehicleid][acDriver] = 65535;
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
	Hook:ac_OnVehicleDeath(vehicleid, killerid)
#else
	public OnVehicleDeath(vehicleid, killerid)
#endif
{
	if(killerid != 65535)
	{
		new i = GetTickCount();
		if(AntiCheatInfo[killerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[killerid][acCall][15] + Mtfc[15][0]) FloodDetect(killerid, 15);
			else if(i < AntiCheatInfo[killerid][acCall][27] + Mtfc[27][0]) FloodDetect(killerid, 27);
			else AntiCheatInfo[killerid][acFloodCount][15] = AntiCheatInfo[killerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[killerid][acCall][27] = AntiCheatInfo[killerid][acCall][15] = i;
	}
	AntiCheatVehInfo[vehicleid][acSpawned] = false;
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
	Hook:ac_OnPlayerText(playerid, text[])
#else
	public OnPlayerText(playerid, text[])
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][16] + Mtfc[16][0]) return FloodDetect(playerid, 16);
		if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][16] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][16] = i;
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

#if defined OnPlayerEnterDynamicCP
	#if defined _inc_y_hooks || defined _INC_y_hooks
		#if defined STREAMER_ENABLE_TAGS
			Hook:ac_OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP checkpointid)
		#else
			Hook:ac_OnPlayerEnterDynamicCP(playerid, checkpointid)
		#endif
	#else
		#if defined STREAMER_ENABLE_TAGS
			public OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP checkpointid)
		#else
			public OnPlayerEnterDynamicCP(playerid, checkpointid)
		#endif
	#endif
	{
		if(AntiCheatInfo[playerid][acKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][17] + Mtfc[17][0]) return FloodDetect(playerid, 17);
			if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][17] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][17] = i;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnPlayerEnterDynamicCP
			return ac_OnPlayerEnterDynamicCP(playerid, checkpointid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnPlayerEnterDynamicCP
			#undef OnPlayerEnterDynamicCP
		#else
			#define _ALS_OnPlayerEnterDynamicCP
		#endif
		#define OnPlayerEnterDynamicCP ac_OnPlayerEnterDynamicCP
		#if defined ac_OnPlayerEnterDynamicCP
			#if defined STREAMER_ENABLE_TAGS
				forward ac_OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP checkpointid);
			#else
				forward ac_OnPlayerEnterDynamicCP(playerid, checkpointid);
			#endif
		#endif
	#endif
#else
	#if defined _inc_y_hooks || defined _INC_y_hooks
		Hook:ac_OnPlayerEnterCheckpoint(playerid)
	#else
		public OnPlayerEnterCheckpoint(playerid)
	#endif
	{
		if(AntiCheatInfo[playerid][acKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][17] + Mtfc[17][0]) return FloodDetect(playerid, 17);
			if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][17] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][17] = i;
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
#endif

#if defined OnPlayerLeaveDynamicCP
	#if defined _inc_y_hooks || defined _INC_y_hooks
		#if defined STREAMER_ENABLE_TAGS
			Hook:ac_OnPlayerLeaveDynamicCP(playerid, STREAMER_TAG_CP checkpointid)
		#else
			Hook:ac_OnPlayerLeaveDynamicCP(playerid, checkpointid)
		#endif
	#else
		#if defined STREAMER_ENABLE_TAGS
			public OnPlayerLeaveDynamicCP(playerid, STREAMER_TAG_CP checkpointid)
		#else
			public OnPlayerLeaveDynamicCP(playerid, checkpointid)
		#endif
	#endif
	{
		if(AntiCheatInfo[playerid][acKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][18] + Mtfc[18][0]) return FloodDetect(playerid, 18);
			if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][18] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][18] = i;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnPlayerLeaveDynamicCP
			return ac_OnPlayerLeaveDynamicCP(playerid, checkpointid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnPlayerLeaveDynamicCP
			#undef OnPlayerLeaveDynamicCP
		#else
			#define _ALS_OnPlayerLeaveDynamicCP
		#endif
		#define OnPlayerLeaveDynamicCP ac_OnPlayerLeaveDynamicCP
		#if defined ac_OnPlayerLeaveDynamicCP
			#if defined STREAMER_ENABLE_TAGS
				forward ac_OnPlayerLeaveDynamicCP(playerid, STREAMER_TAG_CP checkpointid);
			#else
				forward ac_OnPlayerLeaveDynamicCP(playerid, checkpointid);
			#endif
		#endif
	#endif
#else
	#if defined _inc_y_hooks || defined _INC_y_hooks
		Hook:ac_OnPlayerLeaveCheckpoint(playerid)
	#else
		public OnPlayerLeaveCheckpoint(playerid)
	#endif
	{
		if(AntiCheatInfo[playerid][acKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][18] + Mtfc[18][0]) return FloodDetect(playerid, 18);
			if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][18] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][18] = i;
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
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	Hook:ac_OnPlayerRequestSpawn(playerid)
#else
	public OnPlayerRequestSpawn(playerid)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][19] + Mtfc[19][0]) return FloodDetect(playerid, 19);
		if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][19] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acSpawnWeapon][0] = Class[AntiCheatInfo[playerid][acClassid]][0][0];
	AntiCheatInfo[playerid][acSpawnAmmo][0] = Class[AntiCheatInfo[playerid][acClassid]][0][1];
	AntiCheatInfo[playerid][acSpawnWeapon][1] = Class[AntiCheatInfo[playerid][acClassid]][1][0];
	AntiCheatInfo[playerid][acSpawnAmmo][1] = Class[AntiCheatInfo[playerid][acClassid]][1][1];
	AntiCheatInfo[playerid][acSpawnWeapon][2] = Class[AntiCheatInfo[playerid][acClassid]][2][0];
	AntiCheatInfo[playerid][acSpawnAmmo][2] = Class[AntiCheatInfo[playerid][acClassid]][2][1];
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][19] = i;
	i = 1;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerRequestSpawn
		i = ac_OnPlayerRequestSpawn(playerid);
	#endif
	if(i) AntiCheatInfo[playerid][acSet][7] = 1;
	return i;
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
	Hook:ac_OnPlayerExitedMenu(playerid)
#else
	public OnPlayerExitedMenu(playerid)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][20] + Mtfc[20][0]) FloodDetect(playerid, 20);
		else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][20] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][20] = i;
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

#if defined OnPlayerEnterDynamicRaceCP
	#if defined _inc_y_hooks || defined _INC_y_hooks
		#if defined STREAMER_ENABLE_TAGS
			Hook:ac_OnPlayerEnterDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid)
		#else
			Hook:ac_OnPlayerEnterDynamicRaceCP(playerid, checkpointid)
		#endif
	#else
		#if defined STREAMER_ENABLE_TAGS
			public OnPlayerEnterDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid)
		#else
			public OnPlayerEnterDynamicRaceCP(playerid, checkpointid)
		#endif
	#endif
	{
		if(AntiCheatInfo[playerid][acKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][21] + Mtfc[21][0]) return FloodDetect(playerid, 21);
			if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][21] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][21] = i;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnPlayerEnterDynamicRaceCP
			return ac_OnPlayerEnterDynamicRaceCP(playerid, checkpointid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnPlayerEnterDynamicRaceCP
			#undef OnPlayerEnterDynamicRaceCP
		#else
			#define _ALS_OnPlayerEnterDynamicRaceCP
		#endif
		#define OnPlayerEnterDynamicRaceCP ac_OnPlayerEnterDynamicRaceCP
		#if defined ac_OnPlayerEnterDynamicRaceCP
			#if defined STREAMER_ENABLE_TAGS
				forward ac_OnPlayerEnterDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid);
			#else
				forward ac_OnPlayerEnterDynamicRaceCP(playerid, checkpointid);
			#endif
		#endif
	#endif
#else
	#if defined _inc_y_hooks || defined _INC_y_hooks
		Hook:ac_OnPlayerEnterRaceCheckpoint(playerid)
	#else
		public OnPlayerEnterRaceCheckpoint(playerid)
	#endif
	{
		if(AntiCheatInfo[playerid][acKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][21] + Mtfc[21][0]) return FloodDetect(playerid, 21);
			if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][21] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][21] = i;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnPlayerEnterRaceCheckpoint
			return ac_OnPlayerEnterRaceCheckpoint(playerid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnPlayerEnter\
			RaceCheckpoint
			#undef OnPlayerEnterRaceCheckpoint
		#elseif defined _ALS_OnPlayerEnterRaceCP
			#undef OnPlayerEnterRaceCheckpoint
		#else
			#define _ALS_OnPlayerEnterRaceCheckpoint
		#endif
		#define OnPlayerEnterRaceCheckpoint ac_OnPlayerEnterRaceCheckpoint
		#if defined ac_OnPlayerEnterRaceCheckpoint
			forward ac_OnPlayerEnterRaceCheckpoint(playerid);
		#endif
	#endif
#endif

#if defined OnPlayerLeaveDynamicRaceCP
	#if defined _inc_y_hooks || defined _INC_y_hooks
		#if defined STREAMER_ENABLE_TAGS
			Hook:ac_OnPlayerLeaveDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid)
		#else
			Hook:ac_OnPlayerLeaveDynamicRaceCP(playerid, checkpointid)
		#endif
	#else
		#if defined STREAMER_ENABLE_TAGS
			public OnPlayerLeaveDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid)
		#else
			public OnPlayerLeaveDynamicRaceCP(playerid, checkpointid)
		#endif
	#endif
	{
		if(AntiCheatInfo[playerid][acKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][22] + Mtfc[22][0]) return FloodDetect(playerid, 22);
			if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][22] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][22] = i;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnPlayerLeaveDynamicRaceCP
			return ac_OnPlayerLeaveDynamicRaceCP(playerid, checkpointid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnPlayerLeaveDynamicRaceCP
			#undef OnPlayerLeaveDynamicRaceCP
		#else
			#define _ALS_OnPlayerLeaveDynamicRaceCP
		#endif
		#define OnPlayerLeaveDynamicRaceCP ac_OnPlayerLeaveDynamicRaceCP
		#if defined ac_OnPlayerLeaveDynamicRaceCP
			#if defined STREAMER_ENABLE_TAGS
				forward ac_OnPlayerLeaveDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid);
			#else
				forward ac_OnPlayerLeaveDynamicRaceCP(playerid, checkpointid);
			#endif
		#endif
	#endif
#else
	#if defined _inc_y_hooks || defined _INC_y_hooks
		Hook:ac_OnPlayerLeaveRaceCheckpoint(playerid)
	#else
		public OnPlayerLeaveRaceCheckpoint(playerid)
	#endif
	{
		if(AntiCheatInfo[playerid][acKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][22] + Mtfc[22][0]) return FloodDetect(playerid, 22);
			if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][22] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][22] = i;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnPlayerLeaveRaceCheckpoint
			return ac_OnPlayerLeaveRaceCheckpoint(playerid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnPlayerLeave\
			RaceCheckpoint
			#undef OnPlayerLeaveRaceCheckpoint
		#elseif defined _ALS_OnPlayerLeaveRaceCP
			#undef OnPlayerLeaveRaceCheckpoint
		#else
			#define _ALS_OnPlayerLeaveRaceCheckpoint
		#endif
		#define OnPlayerLeaveRaceCheckpoint ac_OnPlayerLeaveRaceCheckpoint
		#if defined ac_OnPlayerLeaveRaceCheckpoint
			forward ac_OnPlayerLeaveRaceCheckpoint(playerid);
		#endif
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	Hook:ac_OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
#else
	public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][23] + Mtfc[23][0]) return FloodDetect(playerid, 23);
		if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][23] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][23] = i;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerClickPlayerTextDraw
		return ac_OnPlayerClickPlayerTextDraw(playerid, playertextid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerClick\
		PlayerTextDraw
		#undef OnPlayerClickPlayerTextDraw
	#elseif defined _ALS_OnPlayerClickPlayerTD
		#undef OnPlayerClickPlayerTextDraw
	#else
		#define _ALS_OnPlayerClickPlayerTextDraw
	#endif
	#define OnPlayerClickPlayerTextDraw ac_OnPlayerClickPlayerTextDraw
	#if defined ac_OnPlayerClickPlayerTextDraw
		forward ac_OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	Hook:ac_OnVehicleDamageStatusUpdate(vehicleid, playerid)
#else
	public OnVehicleDamageStatusUpdate(vehicleid, playerid)
#endif
{
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][24] + Mtfc[24][0]) FloodDetect(playerid, 24);
		else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][24] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][24] = i;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnVehicleDamageStatusUpdate
		return ac_OnVehicleDamageStatusUpdate(vehicleid, playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnVehicleDamage\
		StatusUpdate
		#undef OnVehicleDamageStatusUpdate
	#elseif defined _ALS_OnVehicleDamageStatusUpd
		#undef OnVehicleDamageStatusUpdate
	#else
		#define _ALS_OnVehicleDamageStatusUpdate
	#endif
	#define OnVehicleDamageStatusUpdate ac_OnVehicleDamageStatusUpdate
	#if defined ac_OnVehicleDamageStatusUpdate
		forward ac_OnVehicleDamageStatusUpdate(vehicleid, playerid);
	#endif
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	Hook:ac_OnVehicleSirenStateChange(playerid, vehicleid, newstate)
#else
	public OnVehicleSirenStateChange(playerid, vehicleid, newstate)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][acACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][acCall][25] + Mtfc[25][0]) FloodDetect(playerid, 25);
		else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][acFloodCount][25] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][25] = i;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnVehicleSirenStateChange
		return ac_OnVehicleSirenStateChange(playerid, vehicleid, newstate);
	#else
		return 1;
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
		Hook:ac_OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
	#else
		public OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
	#endif
	{
		if(AntiCheatInfo[playerid][acKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][26] + Mtfc[26][0]) FloodDetect(playerid, 26);
			else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][26] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][26] = i;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnPlayerSelectDynamicObject
			return ac_OnPlayerSelectDynamicObject(playerid, objectid, modelid, x, y, z);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks && !defined _INC_y_hooks
		#if defined _ALS_OnPlayerSelect\
			DynamicObject
			#undef OnPlayerSelectDynamicObject
		#else
			#define _ALS_OnPlayerSelectDynamicObject
		#endif
		#define OnPlayerSelectDynamicObject ac_OnPlayerSelectDynamicObject
		#if defined ac_OnPlayerSelectDynamicObject
			forward ac_OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z);
		#endif
	#endif
#else
	#if defined _inc_y_hooks || defined _INC_y_hooks
		Hook:ac_OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ)
	#else
		public OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ)
	#endif
	{
		if(AntiCheatInfo[playerid][acKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][acACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][acCall][26] + Mtfc[26][0]) FloodDetect(playerid, 26);
			else if(i < AntiCheatInfo[playerid][acCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][acFloodCount][26] = AntiCheatInfo[playerid][acFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][acCall][27] = AntiCheatInfo[playerid][acCall][26] = i;
		#if !defined _inc_y_hooks && !defined _INC_y_hooks\
			&& defined ac_OnPlayerSelectObject
			return ac_OnPlayerSelectObject(playerid, type, objectid, modelid, fX, fY, fZ);
		#else
			return 1;
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
#endif

#if defined _inc_y_hooks || defined _INC_y_hooks
	Hook:ac_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z)
#else
	public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	static Float:vposX, Float:vposY, Float:vposZ, Float:vposD;
	GetVehiclePos(vehicleid, vposX, vposY, vposZ);
	vposD = GetVehicleDistanceFromPoint(vehicleid, new_x, new_y, new_z);
	if(passenger_seat)
	{
		static Float:zdiff;
		zdiff = new_z - vposZ;
		if(AntiCheatInfo[playerid][acACAllow][31]
		&& (floatabs(vel_x) >= floatabs(AntiCheatVehInfo[vehicleid][acVel][0]) > 0.3
		|| floatabs(vel_y) >= floatabs(AntiCheatVehInfo[vehicleid][acVel][1]) > 0.3
		|| floatabs(vel_x - AntiCheatVehInfo[vehicleid][acVel][0]) > 35.0
		|| floatabs(vel_y - AntiCheatVehInfo[vehicleid][acVel][1]) > 35.0) && zdiff > -5.0)
		{
			if(++AntiCheatInfo[playerid][acCheatCount][4] > MAX_CARSHOT_WARNINGS)
			{
				#if defined OnCheatDetected
					AntiCheatInfo[playerid][acCheatCount][4] = 0;
					KickWithCode(playerid, "", 0, 31);
				#else
					return KickWithCode(playerid, "", 0, 31);
				#endif
			}
			#undef MAX_CARSHOT_WARNINGS
		}
		else if(AntiCheatInfo[playerid][acACAllow][8] && vel_z >= 0.1 && vel_z >
		AntiCheatVehInfo[vehicleid][acVel][2] && floatabs(vposX - new_x) <
		zdiff * 1.2 && floatabs(vposY - new_y) < zdiff * 1.2)
		{
			if(++AntiCheatInfo[playerid][acCheatCount][3] > MAX_FLYHACK_VEH_WARNINGS)
			{
				#if defined OnCheatDetected
					AntiCheatInfo[playerid][acCheatCount][3] = 0;
					KickWithCode(playerid, "", 0, 8, 2);
				#else
					return KickWithCode(playerid, "", 0, 8, 2);
				#endif
			}
			#undef MAX_FLYHACK_VEH_WARNINGS
		}
		else AntiCheatInfo[playerid][acCheatCount][4] =
		AntiCheatInfo[playerid][acCheatCount][3] = 0;
	}
	if(AntiCheatInfo[playerid][acACAllow][5] && vposD > 15.0 && vposZ > -70.0
	&& vposD > AntiCheatVehInfo[vehicleid][acPosDiff] + ((vposD / 3) * 1.5))
	{
		#if defined OnCheatDetected
			KickWithCode(playerid, "", 0, 5);
		#else
			GetVehicleZAngle(vehicleid, AntiCheatVehInfo[vehicleid][acZAngle]);
			SetVehicleZAngle(vehicleid, AntiCheatVehInfo[vehicleid][acZAngle]);
			SetVehiclePos(vehicleid, vposX, vposY, vposZ);
			return 0;
		#endif
	}
	static a;
	a = 1;
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnUnoccupiedVehicleUpdate
		a = ac_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, new_x, new_y, new_z, vel_x, vel_y, vel_z);
	#endif
	if(a)
	{
		AntiCheatVehInfo[vehicleid][acSpeedDiff] =
		GetSpeed(vel_x,vel_y,vel_z)
		- GetSpeed(AntiCheatVehInfo[vehicleid][acVel][0],AntiCheatVehInfo[vehicleid][acVel][1],AntiCheatVehInfo[vehicleid][acVel][2]);
		AntiCheatVehInfo[vehicleid][acPosDiff] = vposD;
		AntiCheatVehInfo[vehicleid][acVel][0] = vel_x;
		AntiCheatVehInfo[vehicleid][acVel][1] = vel_y;
		AntiCheatVehInfo[vehicleid][acVel][2] = vel_z;
	}
	return a;
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
	Hook:ac_OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
#else
	public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
#endif
{
	if(AntiCheatInfo[playerid][acKicked]) return 0;
	if(AntiCheatInfo[playerid][acACAllow][46] && 383 < modelid < 394) return KickWithCode(playerid, "", 0, 46);
	#if !defined _inc_y_hooks && !defined _INC_y_hooks\
		&& defined ac_OnPlayerEditAttachedObject
		return ac_OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);
	#else
		return 1;
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

fpublic: acTimer(playerid)
{
	if(!IsPlayerConnected(playerid) || AntiCheatInfo[playerid][acKicked]) return 0;
	if(AntiCheatInfo[playerid][acACAllow][51] && NetStats_MessagesRecvPerSecond(playerid) >
	MAX_MSGS_REC_DIFF) KickWithCode(playerid, "", 0, 51);
	#undef MAX_MSGS_REC_DIFF
	static gtc, gpp, bool:ur;
	gtc = GetTickCount();
	ur = false;
	gpp = GetPlayerPing(playerid) + 100;
	if(gtc > AntiCheatInfo[playerid][acGtc][7] + gpp)
	{
		for(new i, w, a, bool:cw, s = WeaponSlots[GetPlayerWeapon(playerid)]; i < 13; ++i)
		{
			GetPlayerWeaponData(playerid, i, w, a);
			if(w == 39) cw = true;
			if(s != i)
			{
				if(AntiCheatInfo[playerid][acSetWeapon][i] != -1)
				{
					if(AntiCheatInfo[playerid][acSetWeapon][i] == w)
					{
						AntiCheatInfo[playerid][acSetWeapon][i] = -1;
						AntiCheatInfo[playerid][acWeapon][i] = w;
					}
					else if(AntiCheatInfo[playerid][acACAllow][52]
					&& gtc > AntiCheatInfo[playerid][acGtcSetWeapon][i] + gpp
					&& ++AntiCheatInfo[playerid][acNOPCount][0] > MAX_NOP_WARNINGS)
					{
						#if defined DEBUG
							printf(DEBUG_CODE_5, playerid, "GivePlayerWeapon");
						#endif
						#if defined OnCheatDetected
							AntiCheatInfo[playerid][acSetWeapon][i] = -1;
						#endif
						KickWithCode(playerid, "", 0, 52, 13);
					}
				}
				else
				{
					if(AntiCheatInfo[playerid][acWeapon][i] != w)
					{
						if(!w || w == 40 && cw || w == 46
						&& AntiCheatInfo[playerid][acVeh]
						&& AntiCheatInfo[playerid][acParachute])
						{
							AntiCheatInfo[playerid][acWeapon][i] = w;
							AntiCheatInfo[playerid][acAmmo][i] = a;
						}
						else if(-1 < AntiCheatInfo[playerid][acLastPickup] < MAX_PICKUPS
						&& AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acWeapon] == w
						&& a == PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acWeapon]]
						&& IsPlayerInRangeOfPoint(playerid, 5.0, AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acPos][0],
						AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acPos][1],
						AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acPos][2]))
						{
							AntiCheatInfo[playerid][acWeapon][i] = w;
							if(2 < i < 6) AntiCheatInfo[playerid][acAmmo][i] +=
							PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acWeapon]];
							else AntiCheatInfo[playerid][acAmmo][i] =
							PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup]][acWeapon]];
						}
						else if(AntiCheatInfo[playerid][acLastPickup] > MAX_PICKUPS
						&& AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acWeapon] == w
						&& a == PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acWeapon]]
						&& IsPlayerInRangeOfPoint(playerid, 5.0, AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acPos][0],
						AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acPos][1],
						AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acPos][2]))
						{
							AntiCheatInfo[playerid][acWeapon][i] = w;
							if(2 < i < 6) AntiCheatInfo[playerid][acAmmo][i] +=
							PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acWeapon]];
							else AntiCheatInfo[playerid][acAmmo][i] =
							PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][acLastPickup] - MAX_PICKUPS][acWeapon]];
						}
						else if(AntiCheatInfo[playerid][acACAllow][15]
						&& !(15 < w < 44 && !a))
						{
							#if defined OnCheatDetected
								AntiCheatInfo[playerid][acWeapon][i] = w;
								AntiCheatInfo[playerid][acAmmo][i] = a;
							#endif
							KickWithCode(playerid, "", 0, 15, 2);
						}
					}
					if(AntiCheatInfo[playerid][acGiveAmmo][i] != -65535)
					{
						if(AntiCheatInfo[playerid][acGiveAmmo][i] == a)
						{
							AntiCheatInfo[playerid][acGiveAmmo][i] = -65535;
							AntiCheatInfo[playerid][acAmmo][i] = a;
						}
						else if(AntiCheatInfo[playerid][acACAllow][52] && gtc >
						AntiCheatInfo[playerid][acGtcGiveAmmo][i] + gpp)
						{
							if(++AntiCheatInfo[playerid][acNOPCount][1] > MAX_NOP_WARNINGS)
							{
								#undef MAX_NOP_WARNINGS
								#if defined DEBUG
									printf(DEBUG_CODE_5, playerid, "SetPlayerAmmo");
								#endif
								#if defined OnCheatDetected
									AntiCheatInfo[playerid][acGiveAmmo][i] = -65535;
								#endif
								KickWithCode(playerid, "", 0, 52, 14);
							}
						}
					}
					if(15 < w < 44)
					{
						if(!a) AntiCheatInfo[playerid][acAmmo][i] = 0;
						else if(AntiCheatInfo[playerid][acACAllow][16] && (w != 40 && a >
						AntiCheatInfo[playerid][acAmmo][i] || !AntiCheatInfo[playerid][acAmmo][i]
						&& a > AntiCheatInfo[playerid][acAmmo][i]))
						{
							#if defined OnCheatDetected
								AntiCheatInfo[playerid][acAmmo][i] = a;
							#endif
							KickWithCode(playerid, "", 0, 16, 2);
						}
					}
				}
			}
			else if(21 < w < 33 || 40 < w < 43
			|| !LagCompMode && (15 < w < 40 || w == 43))
			{
				if(AntiCheatInfo[playerid][acACAllow][16] && a > AntiCheatInfo[playerid][acAmmo][i]
				&& AntiCheatInfo[playerid][acGiveAmmo][i] == -65535)
				{
					if(21 < w < 33 && !ur && IsPlayerInAmmuNation(playerid,
					GetPlayerInterior(playerid)) && AmmuNationInfo[w - 22][1] ==
					abs(a - AntiCheatInfo[playerid][acAmmo][i]))
					{
						#undef abs
						if(AntiCheatInfo[playerid][acSet][10]
						!= -1) AntiCheatInfo[playerid][acSet][10] += AmmuNationInfo[w - 22][0];
						else AntiCheatInfo[playerid][acSet][10] = AmmuNationInfo[w - 22][0];
						AntiCheatInfo[playerid][acAmmo][i] += AmmuNationInfo[w - 22][1];
						AntiCheatInfo[playerid][acCheatCount][10] = 0;
						ur = true;
					}
					else if(!LagCompMode)
					{
						#if defined OnCheatDetected
							AntiCheatInfo[playerid][acAmmo][i] = a;
						#endif
						KickWithCode(playerid, "", 0, 16, 3);
					}
				}
				else if(AntiCheatInfo[playerid][acAmmo][i]
				&& !LagCompMode) AntiCheatInfo[playerid][acAmmo][i] = a;
			}
		}
	}
	AntiCheatInfo[playerid][acCheatCount][1] =
	AntiCheatInfo[playerid][acCheatCount][2] = 0;
	if(ur) AntiCheatInfo[playerid][acGtc][15] = gtc;
	AntiCheatInfo[playerid][acTimerID] = SetTimerEx("acTimer", 1000, false, "i", playerid);
	return 1;
}

fpublic: ac_OnCheatDetected(playerid, ip_address[], type, code)
{
	if(type) BlockIpAddress(ip_address, 0);
	else
	{
		switch(code)
		{
			case 40: SendClientMessage(playerid, DEFAULT_COLOR, MAX_CONNECTS_MSG);
			case 41: SendClientMessage(playerid, DEFAULT_COLOR, UNKNOWN_CLIENT_MSG);
			default:
			{
				new strtmp[70];
				format(strtmp, sizeof strtmp, KICK_MSG, code);
				SendClientMessage(playerid, DEFAULT_COLOR, strtmp);
				#undef DEFAULT_COLOR
			}
		}
		new pping = GetPlayerPing(playerid) + 100;
		SetTimerEx("ac_KickTimer", (pping > MAX_PING ? MAX_PING : pping), false, "i", playerid);
		#undef MAX_PING
		if(GetPlayerState(playerid) == 2) AntiCheatInfo[playerid][acKicked] = 2;
		else AntiCheatInfo[playerid][acKicked] = 1;
	}
	return 1;
}

fpublic: ac_KickTimer(playerid) return Kick(playerid);

#undef fpublic

stock EnableAntiCheat(acid, enable)
{
	if(!(-1 < acid < sizeof ACAllow)) return 0;
	if(acid == 42)
	{
		if(enable)
		{
			if(!ACAllow[acid])
			{
				#if !USE_QUERY
					QueryEnable = !!GetConsoleVarAsBool("query");
				#endif
				RconEnable = !!GetConsoleVarAsBool("rcon");
			}
			#if !USE_QUERY
				SendRconCommand("query 0");
			#endif
			SendRconCommand("rcon 0");
		}
		else
		{
			new strtmp[9];
			#if !USE_QUERY
				format(strtmp, sizeof strtmp, "query %b", QueryEnable);
				SendRconCommand(strtmp);
			#endif
			format(strtmp, sizeof strtmp, "rcon %b", RconEnable);
			SendRconCommand(strtmp);
		}
	}
	ACAllow[acid] = !!enable;
	#if defined foreach
		foreach(new i : Player)
	#else
		for(new i = GetPlayerPoolSize(); i != -1; --i)
		{
			if(IsPlayerConnected(i))
	#endif
	{
		AntiCheatInfo[i][acACAllow][acid] = ACAllow[acid];
		if(enable)
		{
			switch(acid)
			{
				case 8: AntiCheatInfo[i][acCheatCount][3] = 0;
				case 17: AntiCheatInfo[i][acCheatCount][7] = 0;
				case 26: AntiCheatInfo[i][acCheatCount][8] = 0;
				case 29: AntiCheatInfo[i][acCheatCount][13] =
				AntiCheatInfo[i][acCheatCount][6] = 0;
				case 34: AntiCheatInfo[i][acCheatCount][5] = 0;
				case 38: AntiCheatInfo[i][acCheatCount][0] = 0;
			}
		}
	}
	#if !defined foreach
		}
	#endif
	return 1;
}

stock EnableAntiCheatForPlayer(playerid, acid, enable)
{
	if(!IsPlayerConnected(playerid) || !(-1 < acid < sizeof ACAllow)) return 0;
	AntiCheatInfo[playerid][acACAllow][acid] = !!enable;
	if(enable)
	{
		switch(acid)
		{
			case 8: AntiCheatInfo[playerid][acCheatCount][3] = 0;
			case 17: AntiCheatInfo[playerid][acCheatCount][7] = 0;
			case 26: AntiCheatInfo[playerid][acCheatCount][8] = 0;
			case 29: AntiCheatInfo[playerid][acCheatCount][13] =
			AntiCheatInfo[playerid][acCheatCount][6] = 0;
			case 34: AntiCheatInfo[playerid][acCheatCount][5] = 0;
			case 38: AntiCheatInfo[playerid][acCheatCount][0] = 0;
		}
	}
	return 1;
}

stock IsAntiCheatEnabled(acid)
{
	if(!(-1 < acid < sizeof ACAllow)) return false;
	return ACAllow[acid];
}

stock IsAntiCheatEnabledForPlayer(playerid, acid)
{
	if(!IsPlayerConnected(playerid) || !(-1 < acid < sizeof ACAllow)) return false;
	return AntiCheatInfo[playerid][acACAllow][acid];
}

static IsPlayerInRestaurant(playerid, interiorid)
{
	#if USE_RESTAURANTS
		new i;
		switch(interiorid)
		{
			case 5: i = 0;
			case 9: i = 1;
			case 10: i = 2;
			default: return false;
		}
		return IsPlayerInRangeOfPoint(playerid, 2.5, Restaurants[i][0],
		Restaurants[i][1], Restaurants[i][2]);
	#else
		return false;
	#endif
	#undef USE_RESTAURANTS
}

static IsPlayerInAmmuNation(playerid, interiorid)
{
	#if USE_AMMUNATIONS
		new i, s;
		switch(interiorid)
		{
			case 1: i = 0, s = -1;
			case 4: i = 1, s = 0;
			case 6: i = 3, s = 1;
			default: return false;
		}
		for(; i != s; --i)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.5, AmmuNations[i][0],
			AmmuNations[i][1], AmmuNations[i][2])) return true;
		}
	#endif
	#undef USE_AMMUNATIONS
	return false;
}

static IsPlayerInPayNSpray(playerid, interiorid)
{
	#if USE_PAYNSPRAY
		if(!interiorid)
		{
			for(new i = sizeof(PayNSpray) - 1; i != -1; --i)
			{
				if(IsPlayerInRangeOfPoint(playerid, 7.5, PayNSpray[i][0],
				PayNSpray[i][1], PayNSpray[i][2])) return true;
			}
		}
	#endif
	#undef USE_PAYNSPRAY
	return false;
}

static IsPlayerNearVendingMachine(playerid, interiorid)
{
	#if USE_VENDING_MACHINES
		new i, s;
		switch(interiorid)
		{
			case 0: i = 44, s = -1;
			case 1: i = 51, s = 44;
			case 2: i = 52, s = 51;
			case 3: i = 58, s = 52;
			case 6: i = 60, s = 58;
			case 7: i = 61, s = 60;
			case 15: i = 62, s = 61;
			case 16: i = 65, s = 62;
			case 17: i = 72, s = 65;
			case 18: i = 74, s = 72;
			default: return false;
		}
		for(; i != s; --i)
		{
			if(IsPlayerInRangeOfPoint(playerid, 1.5, VendingMachines[i][0],
			VendingMachines[i][1], VendingMachines[i][2])) return true;
		}
	#endif
	#undef USE_VENDING_MACHINES
	return false;
}

static IsPlayerInCasino(playerid, interiorid)
{
	#if USE_CASINOS
		new i, s;
		switch(interiorid)
		{
			case 1: i = 41, s = -1;
			case 10: i = 61, s = 41;
			case 12: i = 70, s = 61;
			default: return false;
		}
		for(; i != s; --i)
		{
			if(IsPlayerInRangeOfPoint(playerid, Casinos[i][3], Casinos[i][0],
			Casinos[i][1], Casinos[i][2])) return true;
		}
	#endif
	#undef USE_CASINOS
	return false;
}

static IsComponentidCompatible(modelid, componentid)
{
	if(modelid != -1)
	{
		switch(componentid)
		{
			case 1000..1191:
			{
				componentid -= 1000;
				if(VehicleMods[(modelid - 400) * 6 + (componentid >>> 5)]
				& 1 << (componentid & 0b00011111)) return true;
			}
			case 1192, 1193:
			{
				if(modelid == 576) return true;
			}
		}
	}
	return false;
}

static IpToInt(const s_szIP[])
{
	new aiBytes[1], iPos;
	aiBytes{0} = strval(s_szIP[iPos]);
	while(iPos < 15 && s_szIP[iPos++] != '.'){}
	aiBytes{1} = strval(s_szIP[iPos]);
	while(iPos < 15 && s_szIP[iPos++] != '.'){}
	aiBytes{2} = strval(s_szIP[iPos]);
	while(iPos < 15 && s_szIP[iPos++] != '.'){}
	aiBytes{3} = strval(s_szIP[iPos]);
	return aiBytes[0];
}

static FloodDetect(playerid, publicid)
{
	if(!AntiCheatInfo[playerid][acKicked])
	{
		if(++AntiCheatInfo[playerid][acFloodCount][publicid] > Mtfc[publicid][1])
		{
			#if defined DEBUG
				printf(DEBUG_CODE_1, playerid, Mtfc[publicid][1], publicid);
				#undef DEBUG
			#endif
			#if defined OnCheatDetected
				AntiCheatInfo[playerid][acFloodCount][publicid] = 0;
				KickWithCode(playerid, "", 0, 49, publicid);
			#else
				return KickWithCode(playerid, "", 0, 49, publicid);
			#endif
		}
		AntiCheatInfo[playerid][acCall][27]
		= AntiCheatInfo[playerid][acCall][publicid] = GetTickCount();
	}
	return 0;
}

static KickWithCode(playerid, ip_address[], type, code, code2 = 0)
{
	if(!type && (!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][acKicked])
	|| !(-1 < code < sizeof ACAllow)) return 0;
	StatsInfo[5]++;
	switch(code)
	{
		case 0..35, 37, 39, 51: StatsInfo[0]++;
		case 36, 38, 40, 41, 50: StatsInfo[4]++;
		case 42: StatsInfo[1]++;
		case 47..49: StatsInfo[3]++;
		case 43..46: StatsInfo[2]++;
	}
	new strtmp[6];
	if(code2) format(strtmp, sizeof strtmp, " (%d)", code2);
	if(type) printf(SUSPICION_2, ip_address, code, strtmp);
	else printf(SUSPICION_1, playerid, code, strtmp);
	#if defined OnCheatDetected
		OnCheatDetected(playerid, ip_address, type, code);
	#else
		ac_OnCheatDetected(playerid, ip_address, type, code);
	#endif
	return 0;
}

static LoadCfg()
{
	new i, File:cfgFile, string[415], strtmp[9];
	if(fexist(CONFIG_FILE))
	{
		if((cfgFile = fopen(CONFIG_FILE, io_read)))
		{
			while(fread(cfgFile, string))
			{
				if((i = strfind(string, "//")) != -1)
				{
					strmid(strtmp, string, i + 2, strlen(string));
					if(-1 < (i = strval(strtmp)) < sizeof ACAllow) ACAllow[i] = !!strval(string);
				}
			}
			fclose(cfgFile);
		}
		else return 0;
	}
	else if((cfgFile = fopen(CONFIG_FILE, io_write)))
	{
		#undef CONFIG_FILE
		for(; i < sizeof ACAllow; ++i)
		{
			format(strtmp, sizeof strtmp, "%d //%d\r\n", ACAllow[i], i);
			strcat(string, strtmp);
		}
		fwrite(cfgFile, string);
		fclose(cfgFile);
	}
	else return 0;
	return 1;
}

#endif
