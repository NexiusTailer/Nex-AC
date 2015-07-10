//Nex-AC by Nexius v1.3 (0.3.7-R1)

#if defined _nex_ac_included
	#endinput
#endif
#define _nex_ac_included

#include <a_samp>

#if !defined FILTERSCRIPT

//#define DEBUG

#include <nex-ac_en.lang>	//Localization

#if !defined _nex_ac_lang_included
	#error Anticheat Nex-AC requires the installation of localization!
#endif

#define	NEX_AC_VERSION				"1.3"
#define SERVER_VERSION				"0.3.7"

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
#define MAX_CARSHOT_WARNINGS		3
#define MAX_PRO_AIM_WARNINGS		1
#define MAX_AFK_GHOST_WARNINGS		2
#define MAX_RAPID_FIRE_WARNINGS		2

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
	true,	//33 Anti-UnFreeze
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
	{800, 2},	//8 OnPlayerPickUpPickup
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
	{180, 3},	//25 OnVehicleSirenStateChange
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
	Float:pPos[3],
	Float:pDropJP[3],
	Float:pSetPos[3],
	Float:pSetVehHealth,
	Float:pSpeed,
	pHealth,
	pArmour,
	pMoney,
	pClassid,
	pLastWeapon,
	pEnterVeh,
	pEnterVehTime,
	pVeh,
	pSeat,
	pDialog,
	pAnim,
	pDmgRes,
	pSpecAct,
	pNextSpecAct,
	pLastSpecAct,
	pLastPickup,
	pShotTime,
	pSpawnTime,
	pLastUpdate,
	pTimerID,
	pKicked,
	pIp[16],
	pSet[13],
	pGtc[17],
	pWeapon[13],
	pAmmo[13],
	pSetWeapon[13],
	pGiveAmmo[13],
	pSpawnWeapon[3],
	pSpawnAmmo[3],
	pGtcSetWeapon[13],
	pGtcGiveAmmo[13],
	pNOPCount[11],
	pCheatCount[12],
	pCall[sizeof Mtfc],
	pFloodCount[sizeof Mtfc],
	bool:pACAllow[sizeof ACAllow],
	bool:pStuntBonus,
	bool:pModShop,
	bool:pFreeze,
	bool:pOnline,
	bool:pSpawnRes,
	bool:pDeathRes,
	bool:pVehDmgRes,
	bool:pDead,
	bool:pShot,
	bool:pTpToZ,
	bool:pPicked,
	bool:pParachute,
	bool:pIntEnterExits
}

enum ACVehInfo
{
	Float:vVel[3],
	Float:vSpeedDiff,
	Float:vPosDiff,
	Float:vZAngle,
	Float:vHealth,
	vDriver,
	vInt,
	vPaintJob,
	bool:vSpawned
}

enum ACPickInfo
{
	Float:pPos[3],
	pType,
	pWeapon,
	bool:pIsStatic
}

static
	StatsInfo[6],
	Class[MAX_CLASSES][3][2],
	AntiCheatInfo[MAX_PLAYERS][ACInfo],
	AntiCheatVehInfo[MAX_VEHICLES][ACVehInfo],
	AntiCheatPickInfo[MAX_PICKUPS][ACPickInfo],
	bool:IntEnterExits = true,
	bool:StuntBonus = true,
	bool:VehFriendlyFire,
	bool:LagCompMode,
	#if !USE_QUERY
		bool:QueryEnable,
	#endif
	bool:RconEnable,
	bool:PedAnims;

fpublic: ac_AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2)
{
	new vehicleid = AddStaticVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2);
	if(vehicleid != 65535)
	{
		AntiCheatVehInfo[vehicleid][vInt] = 0;
		AntiCheatVehInfo[vehicleid][vPaintJob] = 3;
		AntiCheatVehInfo[vehicleid][vSpawned] = true;
		AntiCheatVehInfo[vehicleid][vHealth] = 1000.0;
		AntiCheatVehInfo[vehicleid][vSpeedDiff] =
		AntiCheatVehInfo[vehicleid][vPosDiff] =
		AntiCheatVehInfo[vehicleid][vVel][0] =
		AntiCheatVehInfo[vehicleid][vVel][1] =
		AntiCheatVehInfo[vehicleid][vVel][2] = 0.0;
		AntiCheatVehInfo[vehicleid][vDriver] = 65535;
	}
	return vehicleid;
}

fpublic: ac_AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay, addsiren)
{
	new vehicleid = AddStaticVehicleEx(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay, addsiren);
	if(vehicleid != 65535)
	{
		AntiCheatVehInfo[vehicleid][vInt] = 0;
		AntiCheatVehInfo[vehicleid][vPaintJob] = 3;
		AntiCheatVehInfo[vehicleid][vSpawned] = true;
		AntiCheatVehInfo[vehicleid][vHealth] = 1000.0;
		AntiCheatVehInfo[vehicleid][vSpeedDiff] =
		AntiCheatVehInfo[vehicleid][vPosDiff] =
		AntiCheatVehInfo[vehicleid][vVel][0] =
		AntiCheatVehInfo[vehicleid][vVel][1] =
		AntiCheatVehInfo[vehicleid][vVel][2] = 0.0;
		AntiCheatVehInfo[vehicleid][vDriver] = 65535;
	}
	return vehicleid;
}

fpublic: ac_CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, addsiren)
{
	new vehicleid = CreateVehicle(vehicletype, x, y, z, rotation, color1, color2, respawn_delay, addsiren);
	if(vehicleid != 65535)
	{
		AntiCheatVehInfo[vehicleid][vInt] = 0;
		AntiCheatVehInfo[vehicleid][vPaintJob] = 3;
		AntiCheatVehInfo[vehicleid][vHealth] = 1000.0;
		AntiCheatVehInfo[vehicleid][vSpeedDiff] =
		AntiCheatVehInfo[vehicleid][vPosDiff] =
		AntiCheatVehInfo[vehicleid][vVel][0] =
		AntiCheatVehInfo[vehicleid][vVel][1] =
		AntiCheatVehInfo[vehicleid][vVel][2] = 0.0;
		if(!(568 < vehicletype < 571)) AntiCheatVehInfo[vehicleid][vSpawned] = true;
		AntiCheatVehInfo[vehicleid][vDriver] = 65535;
	}
	return vehicleid;
}

fpublic: ac_AddPlayerClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new classid = AddPlayerClass(modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	if(classid < MAX_CLASSES)
	{
		Class[classid][0][0] = weapon1;
		Class[classid][0][1] = weapon1_ammo;
		Class[classid][1][0] = weapon2;
		Class[classid][1][1] = weapon2_ammo;
		Class[classid][2][0] = weapon3;
		Class[classid][2][1] = weapon3_ammo;
	}
	return classid;
}

fpublic: ac_AddPlayerClassEx(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	new classid = AddPlayerClassEx(teamid, modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
	if(classid < MAX_CLASSES)
	{
		#undef MAX_CLASSES
		Class[classid][0][0] = weapon1;
		Class[classid][0][1] = weapon1_ammo;
		Class[classid][1][0] = weapon2;
		Class[classid][1][1] = weapon2_ammo;
		Class[classid][2][0] = weapon3;
		Class[classid][2][1] = weapon3_ammo;
	}
	return classid;
}

fpublic: ac_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
{
	if(!SetSpawnInfo(playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)) return 0;
	AntiCheatInfo[playerid][pSpawnWeapon][0] = weapon1;
	AntiCheatInfo[playerid][pSpawnAmmo][0] = weapon1_ammo;
	AntiCheatInfo[playerid][pSpawnWeapon][1] = weapon2;
	AntiCheatInfo[playerid][pSpawnAmmo][1] = weapon2_ammo;
	AntiCheatInfo[playerid][pSpawnWeapon][2] = weapon3;
	AntiCheatInfo[playerid][pSpawnAmmo][2] = weapon3_ammo;
	return 1;
}

fpublic: ac_AddStaticPickup(model, type, Float:X, Float:Y, Float:Z, virtualworld)
{
	new pickupid = CreatePickup(model, type, X, Y, Z, virtualworld);
	if(pickupid == -1) return 0;
	AntiCheatPickInfo[pickupid][pWeapon] = 0;
	switch(type)
	{
		case 2, 3, 15, 22:
		{
			switch(model)
			{
				case 370: AntiCheatPickInfo[pickupid][pType] = 2;
				case 1240: AntiCheatPickInfo[pickupid][pType] = 3;
				case 1242: AntiCheatPickInfo[pickupid][pType] = 4;
				case 321..369, 371, 372:
				{
					for(new i = 46; i != -1; --i)
					{
						if(WeaponModels[i] == model)
						{
							AntiCheatPickInfo[pickupid][pType] = 1;
							AntiCheatPickInfo[pickupid][pWeapon] = i;
							break;
						}
					}
				}
			}
		}
	}
	AntiCheatPickInfo[pickupid][pIsStatic] = true;
	AntiCheatPickInfo[pickupid][pPos][0] = X;
	AntiCheatPickInfo[pickupid][pPos][1] = Y;
	AntiCheatPickInfo[pickupid][pPos][2] = Z;
	return 1;
}

fpublic: ac_CreatePickup(model, type, Float:X, Float:Y, Float:Z, virtualworld)
{
	new pickupid = CreatePickup(model, type, X, Y, Z, virtualworld);
	if(pickupid != -1)
	{
		AntiCheatPickInfo[pickupid][pWeapon] = 0;
		switch(type)
		{
			case 2, 3, 15, 22:
			{
				switch(model)
				{
					case 370: AntiCheatPickInfo[pickupid][pType] = 2;
					case 1240: AntiCheatPickInfo[pickupid][pType] = 3;
					case 1242: AntiCheatPickInfo[pickupid][pType] = 4;
					case 321..369, 371, 372:
					{
						for(new i = 46; i != -1; --i)
						{
							if(WeaponModels[i] == model)
							{
								AntiCheatPickInfo[pickupid][pType] = 1;
								AntiCheatPickInfo[pickupid][pWeapon] = i;
								break;
							}
						}
					}
				}
			}
		}
		AntiCheatPickInfo[pickupid][pIsStatic] = false;
		AntiCheatPickInfo[pickupid][pPos][0] = X;
		AntiCheatPickInfo[pickupid][pPos][1] = Y;
		AntiCheatPickInfo[pickupid][pPos][2] = Z;
	}
	return pickupid;
}

#if defined CreateDynamicPickup\
	|| defined CreateDynamicPickupEx
	fpublic: STREAMER_TAG_PICKUP ac_CreateDynamicPickup(pickupid, modelid, type, Float:x, Float:y, Float:z)
	{
		switch(type)
		{
			case 2, 3, 15, 22:
			{
				switch(modelid)
				{
					case 370: AntiCheatPickInfo[pickupid][pType] = 2;
					case 1240: AntiCheatPickInfo[pickupid][pType] = 3;
					case 1242: AntiCheatPickInfo[pickupid][pType] = 4;
					case 321..369, 371, 372:
					{
						for(new i = 46; i != -1; --i)
						{
							if(WeaponModels[i] == modelid)
							{
								AntiCheatPickInfo[pickupid][pType] = 1;
								AntiCheatPickInfo[pickupid][pWeapon] = i;
								break;
							}
						}
					}
				}
			}
		}
		AntiCheatPickInfo[pickupid][pIsStatic] = false;
		AntiCheatPickInfo[pickupid][pPos][0] = x;
		AntiCheatPickInfo[pickupid][pPos][1] = y;
		AntiCheatPickInfo[pickupid][pPos][2] = z;
	}
#endif

fpublic: ac_DestroyVehicle(vehicleid)
{
	if(!DestroyVehicle(vehicleid)) return 0;
	AntiCheatVehInfo[vehicleid][vSpawned] = false;
	return 1;
}

fpublic: ac_DestroyPickup(pickup)
{
	if(!DestroyPickup(pickup)) return 0;
	AntiCheatPickInfo[pickup][pType] = 0;
	return 1;
}

#if defined DestroyDynamicPickup
	fpublic: ac_DestroyDynamicPickup(STREAMER_TAG_PICKUP pickupid)
	{
		if(!DestroyDynamicPickup(pickupid)) return 0;
		AntiCheatPickInfo[pickupid][pType] = 0;
		return 1;
	}
#endif

#if defined DestroyAllDynamicPickups\
	&& defined IsValidDynamicPickup
	fpublic: ac_DestroyAllDynamicPickups()
	{
		if(!DestroyAllDynamicPickups()) return 0;
		for(new STREAMER_TAG_PICKUP i = MAX_PICKUPS - 1; i != -1; --i)
		{
			if(IsValidDynamicPickup(i)) AntiCheatPickInfo[i][pType] = 0;
		}
		return 1;
	}
#endif

fpublic: ac_DisableInteriorEnterExits()
{
	IntEnterExits = false;
	return DisableInteriorEnterExits();
}

fpublic: ac_UsePlayerPedAnims()
{
	PedAnims = true;
	return UsePlayerPedAnims();
}

fpublic: ac_EnableVehicleFriendlyFire()
{
	VehFriendlyFire = true;
	return EnableVehicleFriendlyFire();
}

fpublic: ac_EnableStuntBonusForAll(enable)
{
	StuntBonus = !!enable;
	#if defined foreach
		foreach(Player, i) AntiCheatInfo[i][pStuntBonus] = StuntBonus;
	#else
		for(new i = GetPlayerPoolSize(); i != -1; --i)
		{
			if(IsPlayerConnected(i)) AntiCheatInfo[i][pStuntBonus] = StuntBonus;
		}
	#endif
	return EnableStuntBonusForAll(enable);
}

fpublic: ac_EnableStuntBonusForPlayer(playerid, enable)
{
	if(!EnableStuntBonusForPlayer(playerid, enable)) return 0;
	AntiCheatInfo[playerid][pStuntBonus] = !!enable;
	return 1;
}

fpublic: ac_ShowPlayerDialog(playerid, dialogid)
{
	if(IsPlayerConnected(playerid)) AntiCheatInfo[playerid][pDialog] = dialogid;
	return 1;
}

fpublic: ac_TogglePlayerControllable(playerid, toggle)
{
	if(!TogglePlayerControllable(playerid, toggle)) return 0;
	AntiCheatInfo[playerid][pFreeze] = !!toggle;
	return 1;
}

fpublic: ac_TogglePlayerSpectating(playerid, toggle)
{
	if(!TogglePlayerSpectating(playerid, toggle)) return 0;
	AntiCheatInfo[playerid][pSet][6] = 1;
	AntiCheatInfo[playerid][pNOPCount][8] = 0;
	AntiCheatInfo[playerid][pGtc][12] = GetTickCount();
	if(!toggle)
	{
		AntiCheatInfo[playerid][pSet][7] = 1;
		AntiCheatInfo[playerid][pNOPCount][9] = 0;
		AntiCheatInfo[playerid][pGtc][13] = AntiCheatInfo[playerid][pGtc][12];
	}
	return 1;
}

fpublic: ac_SpawnPlayer(playerid)
{
	if(!SpawnPlayer(playerid)) return 0;
	AntiCheatInfo[playerid][pSet][7] = 1;
	AntiCheatInfo[playerid][pNOPCount][9] = 0;
	AntiCheatInfo[playerid][pGtc][13] = GetTickCount();
	return 1;
}

fpublic: ac_SetPlayerHealth(playerid, Float:health)
{
	if(health > 16777250.0) health = 16777250.0;
	if(!SetPlayerHealth(playerid, health)) return 0;
	if(health < 0.0) health = 0.0;
	AntiCheatInfo[playerid][pNOPCount][3] = 0;
	AntiCheatInfo[playerid][pSet][1] = floatround(health, floatround_tozero);
	AntiCheatInfo[playerid][pGtc][3] = GetTickCount();
	return 1;
}

fpublic: ac_SetPlayerArmour(playerid, Float:armour)
{
	if(armour > 16777250.0) armour = 16777250.0;
	if(!SetPlayerArmour(playerid, armour)) return 0;
	if(armour < 0.0) armour = 0.0;
	AntiCheatInfo[playerid][pNOPCount][5] = 0;
	AntiCheatInfo[playerid][pSet][2] = floatround(armour, floatround_tozero);
	AntiCheatInfo[playerid][pGtc][5] = GetTickCount();
	return 1;
}

fpublic: ac_GivePlayerWeapon(playerid, weaponid, ammo)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(!(!AntiCheatInfo[playerid][pAmmo][WeaponSlots[weaponid]] && !ammo))
	{
		AntiCheatInfo[playerid][pNOPCount][0] =
		AntiCheatInfo[playerid][pNOPCount][1] = 0;
		if(15 < weaponid < 44)
		{
			if(2 < WeaponSlots[weaponid] < 6
			|| (AntiCheatInfo[playerid][pSetWeapon][WeaponSlots[weaponid]] ==
			-1 ? AntiCheatInfo[playerid][pWeapon][WeaponSlots[weaponid]]
			: AntiCheatInfo[playerid][pSetWeapon][WeaponSlots[weaponid]])
			== weaponid)
			{
				AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[weaponid]] =
				(AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[weaponid]] == -65535
				? AntiCheatInfo[playerid][pAmmo][WeaponSlots[weaponid]]
				: AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[weaponid]]) + ammo;
			}
			else AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[weaponid]] = ammo;
			if(AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[weaponid]] < -32768) ammo =
			AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[weaponid]] = -32768;
			else if(AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[weaponid]] > 32767) ammo =
			AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[weaponid]] = 32767;
			if(weaponid == 40 && ammo >
			0) AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[weaponid]] = ammo = 1;
		}
		AntiCheatInfo[playerid][pSet][3] =
		AntiCheatInfo[playerid][pSetWeapon][WeaponSlots[weaponid]] = weaponid;
	}
	GivePlayerWeapon(playerid, weaponid, ammo);
	AntiCheatInfo[playerid][pGtcGiveAmmo][WeaponSlots[weaponid]]
	= AntiCheatInfo[playerid][pGtcSetWeapon][WeaponSlots[weaponid]] =
	AntiCheatInfo[playerid][pGtc][2] = GetTickCount();
	return 1;
}

fpublic: ac_SetPlayerAmmo(playerid, weaponslot, ammo)
{
	if(!IsPlayerConnected(playerid)) return 0;
	if(ammo < -32768) ammo = -32768;
	else if(ammo > 32767) ammo = 32767;
	if(weaponslot == 40 && ammo) ammo = 1;
	SetPlayerAmmo(playerid, weaponslot, ammo);
	if(15 < weaponslot < 44
	&& AntiCheatInfo[playerid][pWeapon][WeaponSlots[weaponslot]])
	{
		AntiCheatInfo[playerid][pNOPCount][1] = 0;
		AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[weaponslot]] = ammo;
		AntiCheatInfo[playerid][pGtcGiveAmmo][WeaponSlots[weaponslot]] = GetTickCount();
	}
	return 1;
}

fpublic: ac_SetPlayerArmedWeapon(playerid, weaponid)
{
	if(!SetPlayerArmedWeapon(playerid, weaponid)) return 0;
	if(weaponid == AntiCheatInfo[playerid][pWeapon][WeaponSlots[weaponid]])
	{
		AntiCheatInfo[playerid][pNOPCount][0] = 0;
		AntiCheatInfo[playerid][pSet][3] = weaponid;
		AntiCheatInfo[playerid][pGtc][2] = GetTickCount();
	}
	return 1;
}

fpublic: ac_ResetPlayerWeapons(playerid)
{
	if(!ResetPlayerWeapons(playerid)) return 0;
	for(new i = 12; i != -1; --i)
	{
		AntiCheatInfo[playerid][pWeapon][i] =
		AntiCheatInfo[playerid][pAmmo][i] = 0;
		AntiCheatInfo[playerid][pSetWeapon][i] = -1;
		AntiCheatInfo[playerid][pGiveAmmo][i] = -65535;
	}
	AntiCheatInfo[playerid][pSet][3] = 0;
	AntiCheatInfo[playerid][pGtc][7] = GetTickCount();
	return 1;
}

fpublic: ac_GivePlayerMoney(playerid, money)
{
	if(!GivePlayerMoney(playerid, money)) return 0;
	AntiCheatInfo[playerid][pMoney] += money;
	return 1;
}

fpublic: ac_ResetPlayerMoney(playerid)
{
	if(!ResetPlayerMoney(playerid)) return 0;
	AntiCheatInfo[playerid][pMoney] = 0;
	return 1;
}

fpublic: ac_GetPlayerMoney(playerid) return (IsPlayerConnected(playerid) ? AntiCheatInfo[playerid][pMoney] : 0);

fpublic: ac_SetPlayerSpecialAction(playerid, actionid)
{
	if(!SetPlayerSpecialAction(playerid, actionid)) return 0;
	if(actionid == 2 || actionid == 68 || 4 < actionid < 9
	|| 9 < actionid < 12 || 19 < actionid < 26 || !actionid
	&& AntiCheatInfo[playerid][pSpecAct] != 10 || actionid ==
	13 && AntiCheatInfo[playerid][pSpecAct] == 11)
	{
		AntiCheatInfo[playerid][pNOPCount][6] = 0;
		if((actionid == 68 || 9 < actionid < 12 || 19 <
		actionid < 26) && 4 < AntiCheatInfo[playerid][pSpecAct] <
		9) AntiCheatInfo[playerid][pNextSpecAct] = actionid;
		else
		{
			if(actionid == 13) actionid = 0;
			else if(actionid == 2) AntiCheatInfo[playerid][pNextSpecAct] =
			AntiCheatInfo[playerid][pSpecAct];
			else AntiCheatInfo[playerid][pNextSpecAct] = -1;
			AntiCheatInfo[playerid][pSet][4] = actionid;
			AntiCheatInfo[playerid][pGtc][6] = GetTickCount();
			if(AntiCheatInfo[playerid][pSpecAct] ==
			11) AntiCheatInfo[playerid][pGtc][6] += 2500;
		}
	}
	return 1;
}

fpublic: ac_SetPlayerInterior(playerid, interiorid)
{
	if(!SetPlayerInterior(playerid, interiorid)) return 0;
	while(interiorid < 0) interiorid += 256;
	if(interiorid != GetPlayerInterior(playerid))
	{
		AntiCheatInfo[playerid][pNOPCount][2] = 0;
		if(AntiCheatInfo[playerid][pDead]) AntiCheatInfo[playerid][pSet][12] = interiorid;
		else AntiCheatInfo[playerid][pSet][0] = interiorid;
		AntiCheatInfo[playerid][pGtc][0] = GetTickCount();
	}
	return 1;
}

fpublic: ac_SetPlayerPos(playerid, Float:x, Float:y, Float:z)
{
	if(!SetPlayerPos(playerid, x, y, z)) return 0;
	AntiCheatInfo[playerid][pSet][8] = 1;
	AntiCheatInfo[playerid][pNOPCount][10] = 0;
	AntiCheatInfo[playerid][pSetPos][0] = AntiCheatInfo[playerid][pPos][0] = x;
	AntiCheatInfo[playerid][pSetPos][1] = AntiCheatInfo[playerid][pPos][1] = y;
	AntiCheatInfo[playerid][pSetPos][2] = AntiCheatInfo[playerid][pPos][2] = z;
	AntiCheatInfo[playerid][pGtc][11] = GetTickCount();
	return 1;
}

fpublic: ac_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z)
{
	if(!SetPlayerPosFindZ(playerid, x, y, z)) return 0;
	AntiCheatInfo[playerid][pSet][8] = 1;
	AntiCheatInfo[playerid][pTpToZ] = true;
	AntiCheatInfo[playerid][pNOPCount][10] = 0;
	AntiCheatInfo[playerid][pSetPos][0] = AntiCheatInfo[playerid][pPos][0] = x;
	AntiCheatInfo[playerid][pSetPos][1] = AntiCheatInfo[playerid][pPos][1] = y;
	AntiCheatInfo[playerid][pGtc][11] = GetTickCount();
	return 1;
}

fpublic: ac_SetPlayerVelocity(playerid, Float:X, Float:Y, Float:Z)
{
	if(!SetPlayerVelocity(playerid, X, Y, Z)) return 0;
	AntiCheatInfo[playerid][pSpeed] = GetSpeed(X,Y,Z);
	AntiCheatInfo[playerid][pGtc][10] = GetTickCount();
	return 1;
}

fpublic: ac_PutPlayerInVehicle(playerid, vehicleid, seatid)
{
	if(!PutPlayerInVehicle(playerid, vehicleid, seatid)) return 0;
	if(AntiCheatVehInfo[vehicleid][vSpawned])
	{
		new model = GetVehicleModel(vehicleid) - 400;
		AntiCheatInfo[playerid][pNOPCount][7] = 0;
		AntiCheatInfo[playerid][pSet][9] = vehicleid;
		if(seatid > MaxPassengers[model >>> 3] >>> ((model
		& 7) << 2) & 0xF) AntiCheatInfo[playerid][pSet][5] = -1;
		else AntiCheatInfo[playerid][pSet][5] = seatid;
		AntiCheatInfo[playerid][pGtc][1] = GetTickCount();
	}
	return 1;
}

fpublic: ac_RemovePlayerFromVehicle(playerid)
{
	if(!RemovePlayerFromVehicle(playerid)) return 0;
	AntiCheatInfo[playerid][pSet][11] = 1;
	AntiCheatInfo[playerid][pGtc][8] = GetTickCount();
	return 1;
}

fpublic: ac_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z)
{
	if(!SetVehiclePos(vehicleid, x, y, z)) return 0;
	AntiCheatVehInfo[vehicleid][vVel][0] =
	AntiCheatVehInfo[vehicleid][vVel][1] =
	AntiCheatVehInfo[vehicleid][vVel][2] = 0.0;
	if(AntiCheatVehInfo[vehicleid][vDriver] != 65535)
	{
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pSet][8] = 1;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pNOPCount][10] = 0;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pSetPos][0] =
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pPos][0] = x;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pSetPos][1] =
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pPos][1] = y;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pSetPos][2] =
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pPos][2] = z;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pGtc][11] =
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pGtc][9] = GetTickCount();
	}
	return 1;
}

fpublic: ac_SetVehicleVelocity(vehicleid, Float:X, Float:Y, Float:Z)
{
	if(!SetVehicleVelocity(vehicleid, X, Y, Z)) return 0;
	if(AntiCheatVehInfo[vehicleid][vDriver] != 65535)
	{
		AntiCheatVehInfo[vehicleid][vVel][0] = X;
		AntiCheatVehInfo[vehicleid][vVel][1] = Y;
		AntiCheatVehInfo[vehicleid][vVel][2] = Z;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pGtc][9] = GetTickCount();
	}
	return 1;
}

fpublic: ac_SetVehicleAngularVelocity(vehicleid, Float:X, Float:Y, Float:Z)
{
	if(!SetVehicleAngularVelocity(vehicleid, X, Y, Z)) return 0;
	if(AntiCheatVehInfo[vehicleid][vDriver] != 65535)
	{
		AntiCheatVehInfo[vehicleid][vVel][0] = X;
		AntiCheatVehInfo[vehicleid][vVel][1] = Y;
		AntiCheatVehInfo[vehicleid][vVel][2] = Z;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pGtc][9] = GetTickCount();
	}
	return 1;
}

fpublic: ac_ChangeVehiclePaintjob(vehicleid, paintjobid)
{
	if(!ChangeVehiclePaintjob(vehicleid, paintjobid)) return 0;
	AntiCheatVehInfo[vehicleid][vPaintJob] = paintjobid;
	return 1;
}

fpublic: ac_SetVehicleHealth(vehicleid, Float:health)
{
	if(health < 0.0) health = 0.0;
	if(!SetVehicleHealth(vehicleid, health)) return 0;
	if(AntiCheatVehInfo[vehicleid][vDriver] != 65535)
	{
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pNOPCount][4] = 0;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pSetVehHealth] = health;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pGtc][4] = GetTickCount();
	}
	return 1;
}

fpublic: ac_RepairVehicle(vehicleid)
{
	if(!RepairVehicle(vehicleid)) return 0;
	if(AntiCheatVehInfo[vehicleid][vDriver] != 65535)
	{
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pNOPCount][4] = 0;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pSetVehHealth] = 1000.0;
		AntiCheatInfo[AntiCheatVehInfo[vehicleid][vDriver]][pGtc][4] = GetTickCount();
	}
	return 1;
}

#endif

stock acc_AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2)
	return CallRemoteFunction("ac_AddStaticVehicle", "iffffii", modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2);

#if defined _ALS_AddStaticVehicle
	#undef AddStaticVehicle
#else
	#define _ALS_AddStaticVehicle
#endif
#define AddStaticVehicle acc_AddStaticVehicle

stock acc_AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1, color2, respawn_delay, addsiren = 0)
	return CallRemoteFunction("ac_AddStaticVehicleEx", "iffffiid", modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay, addsiren);

#if defined _ALS_AddStaticVehicleEx
	#undef AddStaticVehicleEx
#else
	#define _ALS_AddStaticVehicleEx
#endif
#define AddStaticVehicleEx acc_AddStaticVehicleEx

stock acc_CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1, color2, respawn_delay, addsiren = 0)
	return CallRemoteFunction("ac_CreateVehicle", "iffffiid", vehicletype, x, y, z, rotation, color1, color2, respawn_delay, addsiren);

#if defined _ALS_CreateVehicle
	#undef CreateVehicle
#else
	#define _ALS_CreateVehicle
#endif
#define CreateVehicle acc_CreateVehicle

stock acc_AddPlayerClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
	return CallRemoteFunction("ac_AddPlayerClass", "iffffiiiiii", modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);

#if defined _ALS_AddPlayerClass
	#undef AddPlayerClass
#else
	#define _ALS_AddPlayerClass
#endif
#define AddPlayerClass acc_AddPlayerClass

stock acc_AddPlayerClassEx(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
	return CallRemoteFunction("ac_AddPlayerClassEx", "iiffffiiiiii", teamid, modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);

#if defined _ALS_AddPlayerClassEx
	#undef AddPlayerClassEx
#else
	#define _ALS_AddPlayerClassEx
#endif
#define AddPlayerClassEx acc_AddPlayerClassEx

stock acc_SetSpawnInfo(playerid, team, skin, Float:x, Float:y, Float:z, Float:rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo)
	return CallRemoteFunction("ac_SetSpawnInfo", "iiiffffiiiiii", playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);

#if defined _ALS_SetSpawnInfo
	#undef SetSpawnInfo
#else
	#define _ALS_SetSpawnInfo
#endif
#define SetSpawnInfo acc_SetSpawnInfo

stock acc_AddStaticPickup(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0) return CallRemoteFunction("ac_AddStaticPickup", "iifffd", model, type, X, Y, Z, virtualworld);

#if defined _ALS_AddStaticPickup
	#undef AddStaticPickup
#else
	#define _ALS_AddStaticPickup
#endif
#define AddStaticPickup acc_AddStaticPickup

stock acc_CreatePickup(model, type, Float:X, Float:Y, Float:Z, virtualworld = 0) return CallRemoteFunction("ac_CreatePickup", "iifffd", model, type, X, Y, Z, virtualworld);

#if defined _ALS_CreatePickup
	#undef CreatePickup
#else
	#define _ALS_CreatePickup
#endif
#define CreatePickup acc_CreatePickup

#if defined CreateDynamicPickup
	stock STREAMER_TAG_PICKUP acc_CreateDynamicPickup(modelid, type, Float:x, Float:y, Float:z, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = 100.0)
	{
		new STREAMER_TAG_PICKUP pickupid = CreateDynamicPickup(modelid, type, x, y, z, worldid, interiorid, playerid, streamdistance);
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
	stock STREAMER_TAG_PICKUP acc_CreateDynamicPickupEx(modelid, type, Float:x, Float:y, Float:z, Float:streamdistance = 100.0, worlds[] = { -1 }, interiors[] = { -1 }, players[] = { -1 }, maxworlds = sizeof worlds, maxinteriors = sizeof interiors, maxplayers = sizeof players)
	{
		new STREAMER_TAG_PICKUP pickupid = CreateDynamicPickupEx(modelid, type, x, y, z, streamdistance, worlds, interiors, players, maxworlds, maxinteriors, maxplayers);
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

stock acc_DestroyVehicle(vehicleid) return CallRemoteFunction("ac_DestroyVehicle", "i", vehicleid);

#if defined _ALS_DestroyVehicle
	#undef DestroyVehicle
#else
	#define _ALS_DestroyVehicle
#endif
#define DestroyVehicle acc_DestroyVehicle

stock acc_DestroyPickup(pickup) return CallRemoteFunction("ac_DestroyPickup", "i", pickup);

#if defined _ALS_DestroyPickup
	#undef DestroyPickup
#else
	#define _ALS_DestroyPickup
#endif
#define DestroyPickup acc_DestroyPickup

#if defined DestroyDynamicPickup
	stock acc_DestroyDynamicPickup(STREAMER_TAG_PICKUP pickupid) return CallRemoteFunction("ac_DestroyDynamicPickup", "i", pickupid);

	#if defined _ALS_DestroyDynamicPickup
		#undef DestroyDynamicPickup
	#else
		#define _ALS_DestroyDynamicPickup
	#endif
	#define DestroyDynamicPickup acc_DestroyDynamicPickup
#endif

#if defined DestroyAllDynamicPickups
	stock acc_DestroyAllDynamicPickups() return CallRemoteFunction("ac_DestroyAllDynamicPickups", "");

	#if defined _ALS_DestroyAllDynamicPickups
		#undef DestroyAllDynamicPickups
	#else
		#define _ALS_DestroyAllDynamicPickups
	#endif
	#define DestroyAllDynamicPickups acc_DestroyAllDynamicPickups
#endif

stock acc_DisableInteriorEnterExits() return CallRemoteFunction("ac_DisableInteriorEnterExits", "");

#if defined _ALS_DisableInteriorEnterExits
	#undef DisableInteriorEnterExits
#else
	#define _ALS_DisableInteriorEnterExits
#endif
#define DisableInteriorEnterExits acc_DisableInteriorEnterExits

stock acc_UsePlayerPedAnims() return CallRemoteFunction("ac_UsePlayerPedAnims", "");

#if defined _ALS_UsePlayerPedAnims
	#undef UsePlayerPedAnims
#else
	#define _ALS_UsePlayerPedAnims
#endif
#define UsePlayerPedAnims acc_UsePlayerPedAnims

stock acc_EnableVehicleFriendlyFire() return CallRemoteFunction("ac_EnableVehicleFriendlyFire", "");

#if defined _ALS_EnableVehicleFriendlyFire
	#undef EnableVehicleFriendlyFire
#else
	#define _ALS_EnableVehicleFriendlyFire
#endif
#define EnableVehicleFriendlyFire acc_EnableVehicleFriendlyFire

stock acc_EnableStuntBonusForAll(enable) return CallRemoteFunction("ac_EnableStuntBonusForAll", "i", enable);

#if defined _ALS_EnableStuntBonusForAll
	#undef EnableStuntBonusForAll
#else
	#define _ALS_EnableStuntBonusForAll
#endif
#define EnableStuntBonusForAll acc_EnableStuntBonusForAll

stock acc_EnableStuntBonusForPlayer(playerid, enable) return CallRemoteFunction("ac_EnableStuntBonusForPlayer", "ii", playerid, enable);

#if defined _ALS_EnableStuntBonusForPlayer
	#undef EnableStuntBonusForPlayer
#else
	#define _ALS_EnableStuntBonusForPlayer
#endif
#define EnableStuntBonusForPlayer acc_EnableStuntBonusForPlayer

#if defined Dialog_Show
	stock ac_Dialog_Show(playerid, style, string:title[], string:caption[], string:button1[], string:button2[] = "", dialog = -1)
		return CallRemoteFunction("ac_ShowPlayerDialog", "id", playerid, dialog),
		Dialog_Show(playerid, style, title, caption, button1, button2, dialog);

	#if defined _ALS_Dialog_Show
		#undef Dialog_Show
	#else
		#define _ALS_Dialog_Show
	#endif
	#define Dialog_Show ac_Dialog_Show
#endif

stock acc_ShowPlayerDialog(playerid, dialogid, style, caption[], info[], button1[], button2[])
	return CallRemoteFunction("ac_ShowPlayerDialog", "id", playerid, dialogid),
	ShowPlayerDialog(playerid, dialogid, style, caption, info, button1, button2);

#if defined _ALS_ShowPlayerDialog
	#undef ShowPlayerDialog
#else
	#define _ALS_ShowPlayerDialog
#endif
#define ShowPlayerDialog acc_ShowPlayerDialog

stock acc_TogglePlayerControllable(playerid, toggle) return CallRemoteFunction("ac_TogglePlayerControllable", "ii", playerid, toggle);

#if defined _ALS_TogglePlayerControllable
	#undef TogglePlayerControllable
#else
	#define _ALS_TogglePlayerControllable
#endif
#define TogglePlayerControllable acc_TogglePlayerControllable

stock acc_TogglePlayerSpectating(playerid, toggle) return CallRemoteFunction("ac_TogglePlayerSpectating", "ii", playerid, toggle);

#if defined _ALS_TogglePlayerSpectating
	#undef TogglePlayerSpectating
#else
	#define _ALS_TogglePlayerSpectating
#endif
#define TogglePlayerSpectating acc_TogglePlayerSpectating

stock acc_SpawnPlayer(playerid) return CallRemoteFunction("ac_SpawnPlayer", "i", playerid);

#if defined _ALS_SpawnPlayer
	#undef SpawnPlayer
#else
	#define _ALS_SpawnPlayer
#endif
#define SpawnPlayer acc_SpawnPlayer

stock acc_SetPlayerHealth(playerid, Float:health) return CallRemoteFunction("ac_SetPlayerHealth", "if", playerid, health);

#if defined _ALS_SetPlayerHealth
	#undef SetPlayerHealth
#else
	#define _ALS_SetPlayerHealth
#endif
#define SetPlayerHealth acc_SetPlayerHealth

stock acc_SetPlayerArmour(playerid, Float:armour) return CallRemoteFunction("ac_SetPlayerArmour", "if", playerid, armour);

#if defined _ALS_SetPlayerArmour
	#undef SetPlayerArmour
#else
	#define _ALS_SetPlayerArmour
#endif
#define SetPlayerArmour acc_SetPlayerArmour

stock acc_GivePlayerWeapon(playerid, weaponid, ammo) return CallRemoteFunction("ac_GivePlayerWeapon", "iid", playerid, weaponid, ammo);

#if defined _ALS_GivePlayerWeapon
	#undef GivePlayerWeapon
#else
	#define _ALS_GivePlayerWeapon
#endif
#define GivePlayerWeapon acc_GivePlayerWeapon

stock acc_SetPlayerAmmo(playerid, weaponslot, ammo) return CallRemoteFunction("ac_SetPlayerAmmo", "iid", playerid, weaponslot, ammo);

#if defined _ALS_SetPlayerAmmo
	#undef SetPlayerAmmo
#else
	#define _ALS_SetPlayerAmmo
#endif
#define SetPlayerAmmo acc_SetPlayerAmmo

stock acc_SetPlayerArmedWeapon(playerid, weaponid) return CallRemoteFunction("ac_SetPlayerArmedWeapon", "ii", playerid, weaponid);

#if defined _ALS_SetPlayerArmedWeapon
	#undef SetPlayerArmedWeapon
#else
	#define _ALS_SetPlayerArmedWeapon
#endif
#define SetPlayerArmedWeapon acc_SetPlayerArmedWeapon

stock acc_ResetPlayerWeapons(playerid) return CallRemoteFunction("ac_ResetPlayerWeapons", "i", playerid);

#if defined _ALS_ResetPlayerWeapons
	#undef ResetPlayerWeapons
#else
	#define _ALS_ResetPlayerWeapons
#endif
#define ResetPlayerWeapons acc_ResetPlayerWeapons

stock acc_GivePlayerMoney(playerid, money) return CallRemoteFunction("ac_GivePlayerMoney", "id", playerid, money);

#if defined _ALS_GivePlayerMoney
	#undef GivePlayerMoney
#else
	#define _ALS_GivePlayerMoney
#endif
#define GivePlayerMoney acc_GivePlayerMoney

stock acc_ResetPlayerMoney(playerid) return CallRemoteFunction("ac_ResetPlayerMoney", "i", playerid);

#if defined _ALS_ResetPlayerMoney
	#undef ResetPlayerMoney
#else
	#define _ALS_ResetPlayerMoney
#endif
#define ResetPlayerMoney acc_ResetPlayerMoney

static stock bad_GetPlayerMoney(playerid) return GetPlayerMoney(playerid);

stock acc_GetPlayerMoney(playerid) return CallRemoteFunction("ac_GetPlayerMoney", "i", playerid);

#if defined _ALS_GetPlayerMoney
	#undef GetPlayerMoney
#else
	#define _ALS_GetPlayerMoney
#endif
#define GetPlayerMoney acc_GetPlayerMoney

stock acc_SetPlayerSpecialAction(playerid, actionid) return CallRemoteFunction("ac_SetPlayerSpecialAction", "ii", playerid, actionid);

#if defined _ALS_SetPlayerSpecialAction
	#undef SetPlayerSpecialAction
#else
	#define _ALS_SetPlayerSpecialAction
#endif
#define SetPlayerSpecialAction acc_SetPlayerSpecialAction

stock acc_SetPlayerInterior(playerid, interiorid) return CallRemoteFunction("ac_SetPlayerInterior", "ii", playerid, interiorid);

#if defined _ALS_SetPlayerInterior
	#undef SetPlayerInterior
#else
	#define _ALS_SetPlayerInterior
#endif
#define SetPlayerInterior acc_SetPlayerInterior

stock acc_SetPlayerPos(playerid, Float:x, Float:y, Float:z) return CallRemoteFunction("ac_SetPlayerPos", "ifff", playerid, x, y, z);

#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif
#define SetPlayerPos acc_SetPlayerPos

stock acc_SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z) return CallRemoteFunction("ac_SetPlayerPosFindZ", "ifff", playerid, x, y, z);

#if defined _ALS_SetPlayerPosFindZ
	#undef SetPlayerPosFindZ
#else
	#define _ALS_SetPlayerPosFindZ
#endif
#define SetPlayerPosFindZ acc_SetPlayerPosFindZ

stock acc_SetPlayerVelocity(playerid, Float:X, Float:Y, Float:Z) return CallRemoteFunction("ac_SetPlayerVelocity", "ifff", playerid, X, Y, Z);

#if defined _ALS_SetPlayerVelocity
	#undef SetPlayerVelocity
#else
	#define _ALS_SetPlayerVelocity
#endif
#define SetPlayerVelocity acc_SetPlayerVelocity

stock acc_PutPlayerInVehicle(playerid, vehicleid, seatid) return CallRemoteFunction("ac_PutPlayerInVehicle", "iii", playerid, vehicleid, seatid);

#if defined _ALS_PutPlayerInVehicle
	#undef PutPlayerInVehicle
#else
	#define _ALS_PutPlayerInVehicle
#endif
#define PutPlayerInVehicle acc_PutPlayerInVehicle

stock acc_RemovePlayerFromVehicle(playerid) return CallRemoteFunction("ac_RemovePlayerFromVehicle", "i", playerid);

#if defined _ALS_RemovePlayerFromVehicle
	#undef RemovePlayerFromVehicle
#else
	#define _ALS_RemovePlayerFromVehicle
#endif
#define RemovePlayerFromVehicle acc_RemovePlayerFromVehicle

stock acc_SetVehiclePos(vehicleid, Float:x, Float:y, Float:z) return CallRemoteFunction("ac_SetVehiclePos", "ifff", vehicleid, x, y, z);

#if defined _ALS_SetVehiclePos
	#undef SetVehiclePos
#else
	#define _ALS_SetVehiclePos
#endif
#define SetVehiclePos acc_SetVehiclePos

stock acc_SetVehicleVelocity(vehicleid, Float:X, Float:Y, Float:Z) return CallRemoteFunction("ac_SetVehicleVelocity", "ifff", vehicleid, X, Y, Z);

#if defined _ALS_SetVehicleVelocity
	#undef SetVehicleVelocity
#else
	#define _ALS_SetVehicleVelocity
#endif
#define SetVehicleVelocity acc_SetVehicleVelocity

stock acc_SetVehicleAngularVelocity(vehicleid, Float:X, Float:Y, Float:Z) return CallRemoteFunction("ac_SetVehicleAngularVelocity", "ifff", vehicleid, X, Y, Z);

#if defined _ALS_SetVehicleAngularVelocity
	#undef SetVehicleAngularVelocity
#else
	#define _ALS_SetVehicleAngularVelocity
#endif
#define SetVehicleAngularVelocity acc_SetVehicleAngularVelocity

stock acc_ChangeVehiclePaintjob(vehicleid, paintjobid) return CallRemoteFunction("ac_ChangeVehiclePaintjob", "ii", vehicleid, paintjobid);

#if defined _ALS_ChangeVehiclePaintjob
	#undef ChangeVehiclePaintjob
#else
	#define _ALS_ChangeVehiclePaintjob
#endif
#define ChangeVehiclePaintjob acc_ChangeVehiclePaintjob

stock acc_SetVehicleHealth(vehicleid, Float:health) return CallRemoteFunction("ac_SetVehicleHealth", "if", vehicleid, health);

#if defined _ALS_SetVehicleHealth
	#undef SetVehicleHealth
#else
	#define _ALS_SetVehicleHealth
#endif
#define SetVehicleHealth acc_SetVehicleHealth

stock acc_RepairVehicle(vehicleid) return CallRemoteFunction("ac_RepairVehicle", "i", vehicleid);

#if defined _ALS_RepairVehicle
	#undef RepairVehicle
#else
	#define _ALS_RepairVehicle
#endif
#define RepairVehicle acc_RepairVehicle

#if !defined FILTERSCRIPT

#if defined _inc_y_hooks
	Hook:ac_OnGameModeInit()
#else
	public OnGameModeInit()
#endif
{
	if(!LoadCfg()) printf(CFG_OPENING_ERROR, CONFIG_FILE);
	if(ACAllow[42])
	{
		#if !USE_QUERY
			QueryEnable = !!GetServerVarAsBool("query");
			SendRconCommand("query 0");
		#endif
		RconEnable = !!GetServerVarAsBool("rcon");
		SendRconCommand("rcon 0");
	}
	LagCompMode = !!GetServerVarAsInt("lagcompmode");
	print(" ");
	print("--------------------------------------");
	print(LOADED_MSG_1);
	printf(LOADED_MSG_2, NEX_AC_VERSION);
	#undef NEX_AC_VERSION
	print(LOADED_MSG_3);
	print("--------------------------------------\n");
	new a = 1;
	#if !defined _inc_y_hooks\
		&& defined ac_OnGameModeInit
		a = ac_OnGameModeInit();
	#endif
	new strtmp[10];
	GetServerVarAsString("version", strtmp, sizeof strtmp);
	if(strcmp(strtmp, SERVER_VERSION)) print(VERSION_WARNING);
	#undef SERVER_VERSION
	return a;
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnGameModeExit()
#else
	public OnGameModeExit()
#endif
{
	new a = 1;
	#if !defined _inc_y_hooks\
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

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerConnect(playerid)
#else
	public OnPlayerConnect(playerid)
#endif
{
	GetPlayerIp(playerid, AntiCheatInfo[playerid][pIp], 16);
	if(IsPlayerNPC(playerid))
	{
		if(ACAllow[36] && strcmp(AntiCheatInfo[playerid][pIp],
		"127.0.0.1")) KickWithCode(playerid, "", 0, 36);
		AntiCheatInfo[playerid][pTimerID] = -1;
	}
	else
	{
		if(ACAllow[48] && AntiCheatInfo[playerid][pOnline]) KickWithCode(playerid, "", 0, 48);
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
		new i;
		if(ACAllow[40])
		{
			new f = MAX_CONNECTS_FROM_IP;
			#if defined foreachex
				foreachex(Player, i)
				{
					if(!IsPlayerNPC(i) && i != playerid
					&& !strcmp(AntiCheatInfo[playerid][pIp], AntiCheatInfo[i][pIp], false))
			#else
				for(i = GetPlayerPoolSize(); i != -1; --i)
				{
					if(IsPlayerConnected(i) && !IsPlayerNPC(i) && i != playerid
					&& !strcmp(AntiCheatInfo[playerid][pIp], AntiCheatInfo[i][pIp], false))
			#endif
				{
					f--;
					if(!f)
					{
						#if defined DEBUG
							printf(DEBUG_CODE_3, playerid, MAX_CONNECTS_FROM_IP);
						#endif
						#undef MAX_CONNECTS_FROM_IP
						KickWithCode(playerid, "", 0, 40);
					}
				}
			}
		}
		AntiCheatInfo[playerid][pDead] = true;
		AntiCheatInfo[playerid][pSpawnRes] =
		AntiCheatInfo[playerid][pDeathRes] = false;
		AntiCheatInfo[playerid][pIntEnterExits] = IntEnterExits;
		AntiCheatInfo[playerid][pStuntBonus] = StuntBonus;
		AntiCheatInfo[playerid][pCheatCount][0] =
		AntiCheatInfo[playerid][pLastWeapon] =
		AntiCheatInfo[playerid][pKicked] =
		AntiCheatInfo[playerid][pMoney] = 0;
		AntiCheatInfo[playerid][pSet][12] =
		AntiCheatInfo[playerid][pSet][0] =
		AntiCheatInfo[playerid][pDialog] = -1;
		AntiCheatInfo[playerid][pAnim] = -2;
		for(i = 12; i != -1; --i)
		{
			AntiCheatInfo[playerid][pSetWeapon][i] = -1;
			AntiCheatInfo[playerid][pGiveAmmo][i] = -65535;
		}
		for(i = 27; i != -1; --i) AntiCheatInfo[playerid][pFloodCount][i] = 0;
		AntiCheatInfo[playerid][pDropJP][0] = AntiCheatInfo[playerid][pDropJP][1] =
		AntiCheatInfo[playerid][pDropJP][2] = 20001.0;
		memcpy(AntiCheatInfo[playerid][pACAllow], ACAllow, 0, sizeof(ACAllow) * 4, sizeof ACAllow);
		AntiCheatInfo[playerid][pTimerID] = SetTimerEx("acTimer", 1000, false, "i", playerid);
	}
	AntiCheatInfo[playerid][pOnline] = true;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerConnect
		return ac_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerDisconnect(playerid, reason)
#else
	public OnPlayerDisconnect(playerid, reason)
#endif
{
	if(AntiCheatInfo[playerid][pOnline])
	{
		AntiCheatInfo[playerid][pOnline] = false;
		if(!IsPlayerNPC(playerid))
		{
			KillTimer(AntiCheatInfo[playerid][pTimerID]);
			if(!reason) Kick(playerid);
			if(AntiCheatInfo[playerid][pACAllow][37]) BlockIpAddress(AntiCheatInfo[playerid][pIp],
			(MIN_TIME_RECONNECT * 1000) - (reason ? 0 : GetServerVarAsInt("playertimeout")));
			#undef MIN_TIME_RECONNECT
		}
		if(AntiCheatInfo[playerid][pVeh]
		&& AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vDriver] == playerid)
		{
			AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vDriver] = 65535;
			if(AntiCheatInfo[playerid][pKicked] == 2)
			{
				LinkVehicleToInterior(AntiCheatInfo[playerid][pVeh],
				AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vInt]);
				SetVehicleZAngle(AntiCheatInfo[playerid][pVeh],
				AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vZAngle]);
				SetVehiclePos(AntiCheatInfo[playerid][pVeh], AntiCheatInfo[playerid][pPos][0],
				AntiCheatInfo[playerid][pPos][1], AntiCheatInfo[playerid][pPos][2]);
				SetVehicleHealth(AntiCheatInfo[playerid][pVeh],
				AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vHealth]);
				ChangeVehiclePaintjob(AntiCheatInfo[playerid][pVeh],
				AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vPaintJob]);
			}
		}
		#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerDisconnect
			return ac_OnPlayerDisconnect(playerid, reason);
		#endif
	}
	return 1;
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerSpawn(playerid)
#else
	public OnPlayerSpawn(playerid)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	if(!IsPlayerNPC(playerid))
	{
		if(AntiCheatInfo[playerid][pACAllow][27] && AntiCheatInfo[playerid][pSet][7] == -1
		&& (!AntiCheatInfo[playerid][pSpawnRes] || GetTickCount() < AntiCheatInfo[playerid][pSpawnTime]
		+ 1000)) KickWithCode(playerid, "", 0, 27);
		new i;
		for(i = 10; i != 0; --i) AntiCheatInfo[playerid][pSet][i] = -1;
		for(i = 12; i != -1; --i)
		{
			AntiCheatInfo[playerid][pWeapon][i] =
			AntiCheatInfo[playerid][pAmmo][i] = 0;
			AntiCheatInfo[playerid][pSetWeapon][i] = -1;
			AntiCheatInfo[playerid][pGiveAmmo][i] = -65535;
		}
		AntiCheatInfo[playerid][pParachute] =
		AntiCheatInfo[playerid][pVehDmgRes] =
		AntiCheatInfo[playerid][pSpawnRes] =
		AntiCheatInfo[playerid][pModShop] =
		AntiCheatInfo[playerid][pPicked] =
		AntiCheatInfo[playerid][pTpToZ] =
		AntiCheatInfo[playerid][pDead] = false;
		AntiCheatInfo[playerid][pFreeze] = true;
		AntiCheatInfo[playerid][pNextSpecAct] =
		AntiCheatInfo[playerid][pLastPickup] =
		AntiCheatInfo[playerid][pSeat] = -1;
		AntiCheatInfo[playerid][pLastSpecAct] =
		AntiCheatInfo[playerid][pSpecAct] =
		AntiCheatInfo[playerid][pDmgRes] =
		AntiCheatInfo[playerid][pVeh] = 0;
		AntiCheatInfo[playerid][pSpeed] = 0.0;
		SetPlayerHealth(playerid, 100.0);
		SetPlayerArmour(playerid, 0.0);
		for(i = 2; i != -1; --i)
		{
			if(AntiCheatInfo[playerid][pSpawnWeapon][i] != -1)
			{
				AntiCheatInfo[playerid][pWeapon][WeaponSlots[AntiCheatInfo[playerid]
				[pSpawnWeapon][i]]] = AntiCheatInfo[playerid][pSpawnWeapon][i];
				AntiCheatInfo[playerid][pAmmo][WeaponSlots[AntiCheatInfo[playerid]
				[pSpawnWeapon][i]]] = AntiCheatInfo[playerid][pSpawnAmmo][i];
			}
		}
	}
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerSpawn
		return ac_OnPlayerSpawn(playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerDeath(playerid, killerid, reason)
#else
	public OnPlayerDeath(playerid, killerid, reason)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	if(AntiCheatInfo[playerid][pACAllow][28] && (AntiCheatInfo[playerid][pDead]
	|| !AntiCheatInfo[playerid][pDeathRes] && reason != 255 && (reason != 54
	|| killerid != 65535))) KickWithCode(playerid, "", 0, 28);
	AntiCheatInfo[playerid][pDeathRes] = false;
	AntiCheatInfo[playerid][pSet][0] = -1;
	AntiCheatInfo[playerid][pSpawnRes] =
	AntiCheatInfo[playerid][pDead] = true;
	AntiCheatInfo[playerid][pSpawnTime] = GetTickCount();
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerDeath
		return ac_OnPlayerDeath(playerid, killerid, reason);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
#else
	public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
#endif
{
	AntiCheatInfo[playerid][pDeathRes] = true;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerTakeDamage
		return ac_OnPlayerTakeDamage(playerid, issuerid, amount, weaponid, bodypart);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
#else
	public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][0] + Mtfc[0][0]) FloodDetect(playerid, 0);
		else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][0] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	if(AntiCheatInfo[playerid][pACAllow][39] && dialogid
	!= AntiCheatInfo[playerid][pDialog]) return KickWithCode(playerid, "", 0, 39);
	AntiCheatInfo[playerid][pDialog] = -1;
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][0] = i;
	if(AntiCheatInfo[playerid][pACAllow][45])
	{
		while((i = strfind(inputtext, "%")) != -1) strdel(inputtext, i, i + 1);
	}
	#if !defined _inc_y_hooks\
		&& defined ac_OnDialogResponse
		return ac_OnDialogResponse(playerid, dialogid, response, listitem, inputtext);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnEnterExitModShop(playerid, enterexit, interiorid)
#else
	public OnEnterExitModShop(playerid, enterexit, interiorid)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	#if !USE_TUNING_GARAGES
		return KickWithCode(playerid, "", 0, 23, 1);
	#else
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][1] + Mtfc[1][0]) FloodDetect(playerid, 1);
			else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][1] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pSet][0] = interiorid;
		AntiCheatInfo[playerid][pModShop] = !!enterexit;
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][1] = i;
		#if !defined _inc_y_hooks\
			&& defined ac_OnEnterExitModShop
			return ac_OnEnterExitModShop(playerid, enterexit, interiorid);
		#else
			return 1;
		#endif
	#endif
	#undef USE_TUNING_GARAGES
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
#else
	public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetPlayerVehicleID(playerid);
	if(newinteriorid != AntiCheatInfo[playerid][pSet][0])
	{
		if(i)
		{
			if(AntiCheatInfo[playerid][pACAllow][3]) KickWithCode(playerid, "", 0, 3, 1);
		}
		else if(AntiCheatInfo[playerid][pACAllow][2] && !AntiCheatInfo[playerid][pIntEnterExits]
		&& newinteriorid != AntiCheatInfo[playerid][pSet][12]) KickWithCode(playerid, "", 0, 2, 1);
		GetPlayerPos(playerid, AntiCheatInfo[playerid][pPos][0],
		AntiCheatInfo[playerid][pPos][1], AntiCheatInfo[playerid][pPos][2]);
		AntiCheatInfo[playerid][pGtc][11] = GetTickCount() + 1500;
	}
	if(!AntiCheatInfo[playerid][pKicked] && i) AntiCheatVehInfo[i][vInt] = newinteriorid;
	if(AntiCheatInfo[playerid][pSet][12] == -1) AntiCheatInfo[playerid][pSet][0] = -1;
	else AntiCheatInfo[playerid][pSet][12] = -1;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerInteriorChange
		return ac_OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
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
				else
				{
					if(++iptables[i][1] > MAX_RCON_LOGIN_ATTEMPT)
					{
						#if defined DEBUG
							printf(DEBUG_CODE_4, ip, password);
						#endif
						iptables[i][1] = 0;
						KickWithCode(65535, ip, 1, 42, 1);
					}
				}
				i = -1;
				break;
			}
		}
		if(i == -1 && !success)
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
	#if !defined _inc_y_hooks\
		&& defined ac_OnRconLoginAttempt
		return ac_OnRconLoginAttempt(ip, password, success);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerUpdate(playerid)
#else
	public OnPlayerUpdate(playerid)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	static gpp, bool:ur;
	ur = false;
	if(!IsPlayerNPC(playerid))
	{
		gpp = GetPlayerPing(playerid);
		if(AntiCheatInfo[playerid][pACAllow][38])
		{
			if(gpp > MAX_PING)
			{
				if(++AntiCheatInfo[playerid][pCheatCount][0] >
				MAX_PING_WARNINGS) return KickWithCode(playerid, "", 0, 38);
				#undef MAX_PING_WARNINGS
			}
			else AntiCheatInfo[playerid][pCheatCount][0] = 0;
		}
		static stateanim;
		if((stateanim = GetPlayerState(playerid)) != 9)
		{
			gpp += 100;
			static gtc, w, a;
			gtc = GetTickCount();
			a = GetPlayerAmmo(playerid);
			w = GetPlayerWeapon(playerid);
			if(AntiCheatInfo[playerid][pSet][3] != -1)
			{
				if(AntiCheatInfo[playerid][pSet][3] == w)
				{
					AntiCheatInfo[playerid][pSet][3] =
					AntiCheatInfo[playerid][pSetWeapon][WeaponSlots[w]] = -1;
					AntiCheatInfo[playerid][pWeapon][WeaponSlots[w]] = w;
				}
				else if(AntiCheatInfo[playerid][pACAllow][52] && !(1 < stateanim < 4)
				&& gtc > AntiCheatInfo[playerid][pGtc][2] + gpp
				&& ++AntiCheatInfo[playerid][pNOPCount][0] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "GivePlayerWeapon");
					#endif
					return KickWithCode(playerid, "", 0, 52, 1);
				}
			}
			if(AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[w]] != -65535)
			{
				if(AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[w]] == a)
				{
					AntiCheatInfo[playerid][pGiveAmmo][WeaponSlots[w]] = -65535;
					AntiCheatInfo[playerid][pAmmo][WeaponSlots[w]] = a;
				}
				else if(AntiCheatInfo[playerid][pACAllow][52] && gtc >
				AntiCheatInfo[playerid][pGtcGiveAmmo][WeaponSlots[w]] + gpp
				&& ++AntiCheatInfo[playerid][pNOPCount][1] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "SetPlayerAmmo");
					#endif
					return KickWithCode(playerid, "", 0, 52, 2);
				}
			}
			static i;
			i = GetPlayerInterior(playerid);
			if(AntiCheatInfo[playerid][pLastWeapon] != w)
			{
				if(AntiCheatInfo[playerid][pWeapon][WeaponSlots[w]] != w)
				{
					if(w == 40 || w == 46 && AntiCheatInfo[playerid][pVeh]
					&& AntiCheatInfo[playerid][pParachute])
					{
						AntiCheatInfo[playerid][pWeapon][WeaponSlots[w]] = w;
						AntiCheatInfo[playerid][pAmmo][WeaponSlots[w]] = a;
					}
					else if(21 < w < 33 && IsPlayerInAmmuNation(playerid, i))
					{
						if(AntiCheatInfo[playerid][pSet][10]
						!= -1) AntiCheatInfo[playerid][pSet][10] += AmmuNationInfo[w-22][0];
						else AntiCheatInfo[playerid][pSet][10] = AmmuNationInfo[w-22][0];
						AntiCheatInfo[playerid][pAmmo][WeaponSlots[w]] = AmmuNationInfo[w-22][1];
						AntiCheatInfo[playerid][pCheatCount][10] = 0;
						AntiCheatInfo[playerid][pWeapon][WeaponSlots[w]] = w;
						ur = true;
					}
					else if(AntiCheatInfo[playerid][pLastPickup] > -1
					&& AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pWeapon] == w
					&& a == PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pWeapon]]
					&& IsPlayerInRangeOfPoint(playerid, 5.0, AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pPos][0],
					AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pPos][1],
					AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pPos][2]))
					{
						AntiCheatInfo[playerid][pWeapon][WeaponSlots[w]] = w;
						if(2 < WeaponSlots[AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pWeapon]] <
						6) AntiCheatInfo[playerid][pAmmo][WeaponSlots[w]] +=
						PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pWeapon]];
						else AntiCheatInfo[playerid][pAmmo][WeaponSlots[w]] =
						PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pWeapon]];
					}
					else if(AntiCheatInfo[playerid][pACAllow][15]
					&& AntiCheatInfo[playerid][pSetWeapon][WeaponSlots[w]] == -1
					&& gtc > AntiCheatInfo[playerid][pGtc][7]
					+ gpp) return KickWithCode(playerid, "", 0, 15, 1);
				}
				AntiCheatInfo[playerid][pShot] = false;
			}
			else if(AntiCheatInfo[playerid][pAmmo][WeaponSlots[w]] != a)
			{
				switch(w)
				{
					case 16, 17, 18, 35, 36, 39, 43:
					{
						if(AntiCheatInfo[playerid][pACAllow][16] && (!AntiCheatInfo[playerid][pAmmo][WeaponSlots[w]]
						|| AntiCheatInfo[playerid][pAmmo][WeaponSlots[w]] - 1 != a)) return KickWithCode(playerid, "", 0, 16, 1);
						AntiCheatInfo[playerid][pAmmo][WeaponSlots[w]]--;
					}
				}
			}
			static Float:health;
			GetPlayerHealth(playerid, health);
			if(AntiCheatInfo[playerid][pSet][1] != -1)
			{
				if(AntiCheatInfo[playerid][pSet][1] > 255)
				{
					while(health < AntiCheatInfo[playerid][pSet][1]) health += 256;
				}
				if(AntiCheatInfo[playerid][pSet][1] == health) AntiCheatInfo[playerid][pSet][1] = -1;
				else if(AntiCheatInfo[playerid][pACAllow][52] && gtc > AntiCheatInfo[playerid][pGtc][3]
				+ gpp && ++AntiCheatInfo[playerid][pNOPCount][3] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "SetPlayerHealth");
					#endif
					return KickWithCode(playerid, "", 0, 52, 3);
				}
			}
			else if(AntiCheatInfo[playerid][pACAllow][12])
			{
				while(AntiCheatInfo[playerid][pHealth] > health + 255) health += 256;
				if(health > AntiCheatInfo[playerid][pHealth] && !(health <= AntiCheatInfo[playerid][pHealth] + 70.0
				&& IsPlayerInRestaurant(playerid, i)) && !(health <= AntiCheatInfo[playerid][pHealth] + 35.0
				&& IsPlayerNearVendingMachine(playerid, i))) return KickWithCode(playerid, "", 0, 12);
			}
			static Float:armour;
			GetPlayerArmour(playerid, armour);
			if(AntiCheatInfo[playerid][pSet][2] != -1)
			{
				if(AntiCheatInfo[playerid][pSet][2] > 255)
				{
					while(armour < AntiCheatInfo[playerid][pSet][2]) armour += 256;
				}
				if(AntiCheatInfo[playerid][pSet][2] == armour) AntiCheatInfo[playerid][pSet][2] = -1;
				else if(AntiCheatInfo[playerid][pACAllow][52] && gtc > AntiCheatInfo[playerid][pGtc][5]
				+ gpp && ++AntiCheatInfo[playerid][pNOPCount][5] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "SetPlayerArmour");
					#endif
					return KickWithCode(playerid, "", 0, 52, 4);
				}
			}
			else if(AntiCheatInfo[playerid][pACAllow][13])
			{
				while(AntiCheatInfo[playerid][pArmour] > armour + 255) armour += 256;
				if(armour > AntiCheatInfo[playerid][pArmour])
				{
					if(IsPlayerInAmmuNation(playerid, i))
					{
						if(AntiCheatInfo[playerid][pSet][10]
						!= -1) AntiCheatInfo[playerid][pSet][10] += 200;
						else AntiCheatInfo[playerid][pSet][10] = 200;
						AntiCheatInfo[playerid][pCheatCount][10] = 0;
						ur = true;
					}
					else return KickWithCode(playerid, "", 0, 13);
				}
			}
			static vehid;
			vehid = GetPlayerVehicleID(playerid);
			if(AntiCheatInfo[playerid][pACAllow][19])
			{
				if(health < AntiCheatInfo[playerid][pHealth]
				|| armour < AntiCheatInfo[playerid][pArmour])
				{
					if(vehid) AntiCheatInfo[playerid][pVehDmgRes] = false;
					AntiCheatInfo[playerid][pDmgRes] = 0;
				}
				else if(AntiCheatInfo[playerid][pDmgRes] && gtc > AntiCheatInfo[playerid][pGtc][14] + gpp * 2
				&& ++AntiCheatInfo[playerid][pCheatCount][9] > MAX_NOP_WARNINGS) return KickWithCode(playerid, "", 0, 19);
			}
			a = bad_GetPlayerMoney(playerid);
			if(AntiCheatInfo[playerid][pACAllow][14] && a > AntiCheatInfo[playerid][pMoney])
			{
				if(!(AntiCheatInfo[playerid][pStuntBonus] && vehid)
				&& !IsPlayerInCasino(playerid, i))
				{
					a = AntiCheatInfo[playerid][pMoney];
					ResetPlayerMoney(playerid);
					GivePlayerMoney(playerid, a);
				}
			}
			else if(AntiCheatInfo[playerid][pSet][10] != -1 && a < AntiCheatInfo[playerid][pMoney])
			{
				if(AntiCheatInfo[playerid][pSet][10] ==
				(AntiCheatInfo[playerid][pMoney] - a)) AntiCheatInfo[playerid][pSet][10] = -1;
				else if(AntiCheatInfo[playerid][pACAllow][15] && gtc > AntiCheatInfo[playerid][pGtc][15]
				+ 1030 && ++AntiCheatInfo[playerid][pCheatCount][10] >
				MAX_NOP_WARNINGS) return KickWithCode(playerid, "", 0, 15, 3);
			}
			if(AntiCheatInfo[playerid][pACAllow][52])
			{
				if(AntiCheatInfo[playerid][pSet][0] != -1 && gtc > AntiCheatInfo[playerid][pGtc][0]
				+ gpp && ++AntiCheatInfo[playerid][pNOPCount][2] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "SetPlayerInterior");
					#endif
					return KickWithCode(playerid, "", 0, 52, 5);
				}
				if(AntiCheatInfo[playerid][pSet][6] != -1 && gtc > AntiCheatInfo[playerid][pGtc][12]
				+ gpp && ++AntiCheatInfo[playerid][pNOPCount][8] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "TogglePlayerSpectating");
					#endif
					return KickWithCode(playerid, "", 0, 52, 6);
				}
				if(AntiCheatInfo[playerid][pSet][7] != -1 && gtc > AntiCheatInfo[playerid][pGtc][13]
				+ gpp && ++AntiCheatInfo[playerid][pNOPCount][9] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "SpawnPlayer");
					#endif
					return KickWithCode(playerid, "", 0, 52, 7);
				}
				if(AntiCheatInfo[playerid][pSet][11] != -1 && vehid
				&& gtc > AntiCheatInfo[playerid][pGtc][8] + gpp + 3000)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "RemovePlayerFromVehicle");
					#endif
					return KickWithCode(playerid, "", 0, 52, 8);
				}
			}
			static s, Float:ppos[3];
			s = GetPlayerVehicleSeat(playerid);
			GetPlayerPos(playerid, ppos[0], ppos[1], ppos[2]);
			if(AntiCheatInfo[playerid][pSet][9] != -1)
			{
				if(AntiCheatInfo[playerid][pSet][9] == vehid
				&& (AntiCheatInfo[playerid][pSet][5] == s
				|| AntiCheatInfo[playerid][pSet][5] == -1))
				{
					if(AntiCheatInfo[playerid][pVeh]
					&& AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vDriver] == playerid)
					{
						if(GetVehicleModel(AntiCheatInfo[playerid][pVeh]) == 457
						&& !AntiCheatInfo[playerid][pWeapon][1]) AntiCheatInfo[playerid][pWeapon][1] = 2;
						AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vDriver] = 65535;
					}
					if(!s)
					{
						AntiCheatVehInfo[vehid][vDriver] = playerid;
						GetVehicleZAngle(vehid, AntiCheatVehInfo[vehid][vZAngle]);
						AntiCheatInfo[playerid][pSetVehHealth] = -1;
					}
					AntiCheatInfo[playerid][pVehDmgRes] = false;
					AntiCheatInfo[playerid][pSet][11] =
					AntiCheatInfo[playerid][pSet][9] =
					AntiCheatInfo[playerid][pSet][8] =
					AntiCheatInfo[playerid][pSet][5] = -1;
					AntiCheatInfo[playerid][pSeat] = s;
				}
				else if(AntiCheatInfo[playerid][pACAllow][52] && gtc > AntiCheatInfo[playerid][pGtc][1]
				+ gpp && ++AntiCheatInfo[playerid][pNOPCount][7] > MAX_NOP_WARNINGS)
				{
					#if defined DEBUG
						printf(DEBUG_CODE_5, playerid, "PutPlayerInVehicle");
					#endif
					return KickWithCode(playerid, "", 0, 52, 9);
				}
			}
			else
			{
				if(AntiCheatInfo[playerid][pSet][8] != -1)
				{
					if(IsPlayerInRangeOfPoint(playerid, 5.0, AntiCheatInfo[playerid][pSetPos][0],
					AntiCheatInfo[playerid][pSetPos][1], (AntiCheatInfo[playerid][pTpToZ]
					? ppos[2] : AntiCheatInfo[playerid][pSetPos][2])))
					{
						AntiCheatInfo[playerid][pSet][8] = -1;
						AntiCheatInfo[playerid][pGtc][11] = 0;
						AntiCheatInfo[playerid][pTpToZ] = false;
						AntiCheatInfo[playerid][pPos][0] = ppos[0];
						AntiCheatInfo[playerid][pPos][1] = ppos[1];
						AntiCheatInfo[playerid][pPos][2] = ppos[2];
					}
					else if(gtc > AntiCheatInfo[playerid][pGtc][11] + gpp)
					{
						AntiCheatInfo[playerid][pTpToZ] = false;
						if(AntiCheatInfo[playerid][pACAllow][52]
						&& ++AntiCheatInfo[playerid][pNOPCount][10] >
						MAX_NOP_WARNINGS)
						{
							#if defined DEBUG
								printf(DEBUG_CODE_5, playerid, "SetPlayerPos");
							#endif
							return KickWithCode(playerid, "", 0, 52, 10);
						}
					}
				}
				static Float:pvel[3], Float:vctsize, specact;
				vctsize = GetPlayerDistanceFromPoint(playerid, AntiCheatInfo[playerid][pPos][0],
				AntiCheatInfo[playerid][pPos][1], AntiCheatInfo[playerid][pPos][2]);
				specact = GetPlayerSpecialAction(playerid);
				if(vehid)
				{
					if(!AntiCheatInfo[playerid][pVeh])
					{
						if(AntiCheatInfo[playerid][pACAllow][4] && (AntiCheatInfo[playerid][pEnterVeh] != vehid
						|| gtc < AntiCheatInfo[playerid][pEnterVehTime] + 600)) return KickWithCode(playerid, "", 0, 4, 1);
					}
					else if(AntiCheatInfo[playerid][pVeh] != vehid)
					{
						if(AntiCheatInfo[playerid][pACAllow][4]) return KickWithCode(playerid, "", 0, 4, 2);
					}
					else if(AntiCheatInfo[playerid][pACAllow][50]
					&& AntiCheatInfo[playerid][pSeat]
					!= s) return KickWithCode(playerid, "", 0, 50);
					if(stateanim == 2)
					{
						if(AntiCheatInfo[playerid][pACAllow][32] && AntiCheatVehInfo[vehid][vDriver] != 65535
						&& AntiCheatVehInfo[vehid][vDriver] != playerid) return ClearAnimations(playerid, 1);
						if(AntiCheatInfo[playerid][pACAllow][35] && GetPlayerCameraMode(playerid) ==
						55) return KickWithCode(playerid, "", 0, 35);
						static Float:vhealth;
						GetVehicleHealth(vehid, vhealth);
						if(AntiCheatInfo[playerid][pSetVehHealth] != -1)
						{
							if(vhealth == AntiCheatInfo[playerid][pSetVehHealth]) AntiCheatInfo[playerid][pSetVehHealth] = -1;
							else if(AntiCheatInfo[playerid][pACAllow][52] && gtc > AntiCheatInfo[playerid][pGtc][4]
							+ gpp && ++AntiCheatInfo[playerid][pNOPCount][4] > MAX_NOP_WARNINGS)
							{
								#if defined DEBUG
									printf(DEBUG_CODE_5, playerid, "SetVehicleHealth");
								#endif
								return KickWithCode(playerid, "", 0, 52, 11);
							}
						}
						else if(AntiCheatInfo[playerid][pACAllow][11] && vhealth >
						AntiCheatVehInfo[vehid][vHealth] && !AntiCheatInfo[playerid][pModShop]
						&& !IsPlayerInPayNSpray(playerid, i)) return KickWithCode(playerid, "", 0, 11);
						if(AntiCheatInfo[playerid][pACAllow][20] && AntiCheatInfo[playerid][pVehDmgRes])
						{
							if(vhealth < AntiCheatVehInfo[vehid][vHealth]) AntiCheatInfo[playerid][pVehDmgRes] = false;
							else if(gtc > AntiCheatInfo[playerid][pGtc][16] + gpp * 2 && ++AntiCheatInfo[playerid][pCheatCount][11] >
							MAX_NOP_WARNINGS) return KickWithCode(playerid, "", 0, 20);
						}
						static Float:zangle;
						GetVehicleZAngle(vehid, zangle);
						while(zangle < 0.0) zangle += 360.0;
						while(zangle > 360.0) zangle -= 360.0;
						GetVehicleVelocity(vehid, pvel[0], pvel[1], pvel[2]);
						if(gtc > AntiCheatInfo[playerid][pGtc][9] + gpp)
						{
							i = GetVehicleModel(vehid) - 400;
							static Float:vsp, Float:spdiff;
							vsp = GetSpeed(pvel[0],pvel[1],pvel[2]);
							spdiff = vsp - GetSpeed(AntiCheatVehInfo[vehid][vVel][0],AntiCheatVehInfo[vehid][vVel][1],AntiCheatVehInfo[vehid][vVel][2]);
							if(AntiCheatInfo[playerid][pACAllow][10] && spdiff >= 20.0 && AntiCheatVehInfo[vehid][vHealth] == vhealth
							&& AntiCheatVehInfo[vehid][vHealth] > 220.0 && AntiCheatVehInfo[vehid][vSpeedDiff] <= spdiff && (i < 0 || VehicleTypes[i] != 2
							|| floatabs(pvel[0]) > 0.3 || floatabs(pvel[1]) > 0.3 || floatabs(pvel[2]) > 0.3)) return KickWithCode(playerid, "", 0, 10, 1);
							if(AntiCheatInfo[playerid][pACAllow][25] && vsp > 15.0 && floatabs(spdiff) < 25.0
							&& floatround(floatabs(zangle - AntiCheatVehInfo[vehid][vZAngle])) == 180 && (pvel[0] < 0.0)
							!= (AntiCheatVehInfo[vehid][vVel][0] < 0.0) && (pvel[1] < 0.0) != (AntiCheatVehInfo[vehid][vVel][1] < 0.0)
							&& (pvel[2] < 0.0) != (AntiCheatVehInfo[vehid][vVel][2] < 0.0)) return KickWithCode(playerid, "", 0, 25);
							static Float:zdiff;
							zdiff = ppos[2] - AntiCheatInfo[playerid][pPos][2];
							if(i > -1 && VehicleTypes[i] == 1)
							{
								if(AntiCheatInfo[playerid][pACAllow][10] && vsp > 269.0) return KickWithCode(playerid, "", 0, 10, 2);
							}
							else if(AntiCheatInfo[playerid][pACAllow][8] && pvel[2] >= 0.1 && pvel[2] >
							AntiCheatVehInfo[vehid][vVel][2] && floatabs(AntiCheatInfo[playerid][pPos][0] - ppos[0]) <
							zdiff * 1.2 && floatabs(AntiCheatInfo[playerid][pPos][1] - ppos[1]) < zdiff * 1.2)
							{
								if(++AntiCheatInfo[playerid][pCheatCount][3] >
								MAX_FLYHACK_VEH_WARNINGS) return KickWithCode(playerid, "", 0, 8, 1);
							}
							else AntiCheatInfo[playerid][pCheatCount][3] = 0;
							if(vctsize > 0.4 && gtc > AntiCheatInfo[playerid][pGtc][11] + gpp)
							{
								if(vctsize > 15.0 && vctsize > AntiCheatVehInfo[vehid][vPosDiff] + ((vctsize / 3) * 1.5))
								{
									if(AntiCheatInfo[playerid][pACAllow][3] && AntiCheatInfo[playerid][pPos][2] >
									-97.0) return KickWithCode(playerid, "", 0, 3, 2);
								}
								else if(AntiCheatInfo[playerid][pACAllow][1] && vsp < 16.0 && vctsize > 0.8)
								{
									if(++AntiCheatInfo[playerid][pCheatCount][2] >
									MAX_AIR_VEH_WARNINGS) return KickWithCode(playerid, "", 0, 1);
									#undef MAX_AIR_VEH_WARNINGS
								}
								else AntiCheatInfo[playerid][pCheatCount][2] = 0;
							}
							AntiCheatVehInfo[vehid][vSpeedDiff] = spdiff;
						}
						AntiCheatVehInfo[vehid][vVel][0] = pvel[0];
						AntiCheatVehInfo[vehid][vVel][1] = pvel[1];
						AntiCheatVehInfo[vehid][vVel][2] = pvel[2];
						AntiCheatVehInfo[vehid][vPosDiff] = vctsize;
						AntiCheatVehInfo[vehid][vHealth] = vhealth;
						AntiCheatVehInfo[vehid][vZAngle] = zangle;
					}
					AntiCheatInfo[playerid][pSeat] = s;
				}
				else
				{
					if(AntiCheatInfo[playerid][pACAllow][47]
					&& GetPlayerCameraMode(playerid) == 53)
					{
						GetPlayerCameraPos(playerid, pvel[0], pvel[1], pvel[2]);
						if(floatabs(pvel[0]) > 50000.0 || floatabs(pvel[1]) > 50000.0
						|| floatabs(pvel[2]) > 50000.0) return KickWithCode(playerid, "", 0, 47, 1);
					}
					stateanim = GetPlayerAnimationIndex(playerid);
					GetPlayerVelocity(playerid, pvel[0], pvel[1], pvel[2]);
					pvel[0] = GetSpeed(pvel[0],pvel[1],pvel[2]);
					if(AntiCheatInfo[playerid][pAnim] != stateanim)
					{
						switch(stateanim)
						{
							case -1:
							{
								if(AntiCheatInfo[playerid][pACAllow][24]) return KickWithCode(playerid, "", 0, 24);
							}
							case 958..979:
							{
								if(AntiCheatInfo[playerid][pACAllow][7]
								&& w != 46) return KickWithCode(playerid, "", 0, 7, 1);
							}
							case 1058:
							{
								if(AntiCheatInfo[playerid][pACAllow][7]) return KickWithCode(playerid, "", 0, 7, 2);
							}
							case 1231:
							{
								if(AntiCheatInfo[playerid][pACAllow][30])
								{
									i = GetPlayerSkin(playerid);
									if(!PedAnims && i && i != 74) return KickWithCode(playerid, "", 0, 30);
								}
							}
						}
					}
					else if(AntiCheatInfo[playerid][pACAllow][7] && pvel[0] > 30.0
					&& 1537 < stateanim < 1545) return KickWithCode(playerid, "", 0, 7, 3);
					if(AntiCheatInfo[playerid][pSet][4] != -1)
					{
						if(specact == AntiCheatInfo[playerid][pSet][4])
						{
							AntiCheatInfo[playerid][pSet][4] = -1;
							AntiCheatInfo[playerid][pSpecAct] = specact;
						}
						else if(AntiCheatInfo[playerid][pACAllow][52] && gtc > AntiCheatInfo[playerid][pGtc][6]
						+ gpp && ++AntiCheatInfo[playerid][pNOPCount][6] > MAX_NOP_WARNINGS)
						{
							#if defined DEBUG
								printf(DEBUG_CODE_5, playerid, "SetPlayerSpecialAction");
							#endif
							return KickWithCode(playerid, "", 0, 52, 12);
						}
					}
					else if(specact != AntiCheatInfo[playerid][pSpecAct])
					{
						if(specact == AntiCheatInfo[playerid][pNextSpecAct]) AntiCheatInfo[playerid][pNextSpecAct] = -1;
						else if(AntiCheatInfo[playerid][pACAllow][18])
						{
							switch(specact)
							{
								case 0:
								{
									switch(AntiCheatInfo[playerid][pSpecAct])
									{
										case 11, 24, 25: return KickWithCode(playerid, "", 0, 18, 1);
									}
								}
								case 1:
								{
									if(AntiCheatInfo[playerid][pSpecAct]
									&& !(19 < AntiCheatInfo[playerid][pSpecAct] <
									25)) return KickWithCode(playerid, "", 0, 18, 2);
								}
								case 2:
								{
									if(!IsPlayerInRangeOfPoint(playerid, 5.0,
									AntiCheatInfo[playerid][pDropJP][0], AntiCheatInfo[playerid][pDropJP][1],
									AntiCheatInfo[playerid][pDropJP][2])) return KickWithCode(playerid, "", 0, 18, 3);
									AntiCheatInfo[playerid][pDropJP][0] = AntiCheatInfo[playerid][pDropJP][1] =
									AntiCheatInfo[playerid][pDropJP][2] = 20001.0;
								}
								case 3:
								{
									switch(AntiCheatInfo[playerid][pSpecAct])
									{
										case 2, 5..8, 11, 68: return KickWithCode(playerid, "", 0, 18, 4);
									}
								}
								default:
								{
									if(!(19 < specact < 25 && AntiCheatInfo[playerid][pSpecAct] == 1 && specact ==
									AntiCheatInfo[playerid][pLastSpecAct]) && !((specact == 4 || specact == 11 || specact == 24
									|| specact == 25) && AntiCheatInfo[playerid][pVeh]) && !(AntiCheatInfo[playerid][pSpecAct] == 3
									&& specact == AntiCheatInfo[playerid][pLastSpecAct])) return KickWithCode(playerid, "", 0, 18, 5);
								}
							}
						}
						AntiCheatInfo[playerid][pLastSpecAct] = AntiCheatInfo[playerid][pSpecAct];
					}
					if(gtc > AntiCheatInfo[playerid][pGtc][10] + gpp && GetPlayerSurfingVehicleID(playerid) ==
					65535 && GetPlayerSurfingObjectID(playerid) == 65535)
					{
						if(AntiCheatInfo[playerid][pACAllow][9] && pvel[0] > 211.0
						&& AntiCheatInfo[playerid][pSpeed] < pvel[0]) return KickWithCode(playerid, "", 0, 9);
						if(vctsize > 0.5 && gtc > AntiCheatInfo[playerid][pGtc][11] + gpp)
						{
							if(vctsize > 30.0)
							{
								if(AntiCheatInfo[playerid][pACAllow][2]
								&& AntiCheatInfo[playerid][pPos][2] >
								-97.0) return KickWithCode(playerid, "", 0, 2, 2);
							}
							else if(pvel[0] <= vctsize * (vctsize < 1.0 ? 30.0 : 5.0))
							{
								if(pvel[0] < 3.0 && vctsize > 3.0)
								{
									if(AntiCheatInfo[playerid][pACAllow][2]) return KickWithCode(playerid, "", 0, 2, 3);
								}
								else if(AntiCheatInfo[playerid][pACAllow][0] && pvel[0]
								&& ++AntiCheatInfo[playerid][pCheatCount][1] >
								MAX_AIR_WARNINGS) return KickWithCode(playerid, "", 0, 0);
								#undef MAX_AIR_WARNINGS
							}
						}
						AntiCheatInfo[playerid][pSpeed] = pvel[0];
					}
					AntiCheatInfo[playerid][pAnim] = stateanim;
				}
				AntiCheatInfo[playerid][pSpecAct] = specact;
				AntiCheatInfo[playerid][pHealth] = floatround(health, floatround_tozero);
				AntiCheatInfo[playerid][pArmour] = floatround(armour, floatround_tozero);
			}
			AntiCheatInfo[playerid][pPos][0] = ppos[0];
			AntiCheatInfo[playerid][pPos][1] = ppos[1];
			AntiCheatInfo[playerid][pPos][2] = ppos[2];
			AntiCheatInfo[playerid][pLastWeapon] = w;
			AntiCheatInfo[playerid][pVeh] = vehid;
			AntiCheatInfo[playerid][pMoney] = a;
		}
	}
	gpp = 1;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerUpdate
		gpp = ac_OnPlayerUpdate(playerid);
	#endif
	AntiCheatInfo[playerid][pLastUpdate] = GetTickCount();
	if(ur) AntiCheatInfo[playerid][pGtc][15] = AntiCheatInfo[playerid][pLastUpdate];
	if(AntiCheatInfo[playerid][pACAllow][33] && gpp) return AntiCheatInfo[playerid][pFreeze];
	return gpp;
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#else
	public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
#endif
{
	if(newkeys & 16 && AntiCheatInfo[playerid][pSpecAct] ==
	2 && GetPlayerSpecialAction(playerid) != 2)
	{
		AntiCheatInfo[playerid][pDropJP][0] = AntiCheatInfo[playerid][pPos][0];
		AntiCheatInfo[playerid][pDropJP][1] = AntiCheatInfo[playerid][pPos][1];
		AntiCheatInfo[playerid][pDropJP][2] = AntiCheatInfo[playerid][pPos][2];
	}
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerKeyStateChange
		return ac_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
#else
	public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][2] + Mtfc[2][0]) return FloodDetect(playerid, 2);
		if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][2] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][2] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerClickMap
		return ac_OnPlayerClickMap(playerid, fX, fY, fZ);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerClickPlayer(playerid, clickedplayerid, source)
#else
	public OnPlayerClickPlayer(playerid, clickedplayerid, source)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][3] + Mtfc[3][0]) return FloodDetect(playerid, 3);
		if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][3] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][3] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerClickPlayer
		return ac_OnPlayerClickPlayer(playerid, clickedplayerid, source);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerClickTextDraw(playerid, Text:clickedid)
#else
	public OnPlayerClickTextDraw(playerid, Text:clickedid)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][4] + Mtfc[4][0]) return FloodDetect(playerid, 4);
		if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][4] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][4] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerClickTextDraw
		return ac_OnPlayerClickTextDraw(playerid, clickedid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerCommandText(playerid, cmdtext[])
#else
	public OnPlayerCommandText(playerid, cmdtext[])
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 1;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][5] + Mtfc[5][0])
		{
			FloodDetect(playerid, 5);
			return 1;
		}
		if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][5] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][5] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerCommandText
		return ac_OnPlayerCommandText(playerid, cmdtext);
	#else
		return 0;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
#else
	public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][pKicked]) return 0;
	new bool:ur;
	if(!IsPlayerNPC(playerid))
	{
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][6] + Mtfc[6][0]) return FloodDetect(playerid, 6);
			if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][6] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][6] = i;
		i = GetVehicleModel(vehicleid);
		if(AntiCheatInfo[playerid][pACAllow][44]
		&& i == -1) return KickWithCode(playerid, "", 0, 44, 1);
		new Float:TmpPos[3];
		GetVehiclePos(vehicleid, TmpPos[0], TmpPos[1], TmpPos[2]);
		TmpPos[0] = VectorSize(AntiCheatInfo[playerid][pPos][0]
		- TmpPos[0], AntiCheatInfo[playerid][pPos][1] - TmpPos[1],
		AntiCheatInfo[playerid][pPos][2] - TmpPos[2]);
		if(AntiCheatInfo[playerid][pACAllow][4] && (!(i == 577 || i == 592) && TmpPos[0] >
		15.0 || TmpPos[0] > 40.0)) return KickWithCode(playerid, "", 0, 4, 3);
		if(AntiCheatInfo[playerid][pEnterVeh] == vehicleid) ur = true;
		else
		{
			new TmpPrm1, TmpPrm2;
			GetVehicleParamsEx(vehicleid, TmpPrm2, TmpPrm2,
			TmpPrm2, TmpPrm1, TmpPrm2, TmpPrm2, TmpPrm2);
			if(TmpPrm1)
			{
				AntiCheatInfo[playerid][pEnterVeh] = vehicleid;
				if(VehicleTypes[i-400] == 3) AntiCheatInfo[playerid][pEnterVehTime] = 0, ur = true;
			}
		}
	}
	if(!ur) AntiCheatInfo[playerid][pEnterVehTime] = AntiCheatInfo[playerid][pCall][27];
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerEnterVehicle
		return ac_OnPlayerEnterVehicle(playerid, vehicleid, ispassenger);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerExitVehicle(playerid, vehicleid)
#else
	public OnPlayerExitVehicle(playerid, vehicleid)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(!IsPlayerNPC(playerid) && AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][7] + Mtfc[7][0]) return FloodDetect(playerid, 7);
		if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][7] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	switch(GetVehicleModel(AntiCheatInfo[playerid][pVeh]))
	{
		case 417, 425, 447, 469, 476, 487, 488, 497, 511, 512, 513, 519, 520,
		548, 553, 563, 577, 592, 593: AntiCheatInfo[playerid][pParachute] = true;
		default: AntiCheatInfo[playerid][pParachute] = false;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][7] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerExitVehicle
		return ac_OnPlayerExitVehicle(playerid, vehicleid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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
	#if defined _inc_y_hooks
		Hook:ac_OnPlayerPickUpDynamicPickup(playerid, STREAMER_TAG_PICKUP pickupid)
	#else
		public OnPlayerPickUpDynamicPickup(playerid, STREAMER_TAG_PICKUP pickupid)
	#endif
	{
		if(!IsPlayerConnected(playerid) || AntiCheatInfo[playerid][pKicked]
		|| !IsValidDynamicPickup(pickupid)) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][8] + Mtfc[8][0]) FloodDetect(playerid, 8);
			else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][8] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		if(AntiCheatInfo[playerid][pACAllow][6] && !IsPlayerInRangeOfPoint(playerid, 5.0,
		AntiCheatPickInfo[pickupid][pPos][0], AntiCheatPickInfo[pickupid][pPos][1],
		AntiCheatPickInfo[pickupid][pPos][2])) return KickWithCode(playerid, "", 0, 6, 2);
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][8] = i;
		switch(AntiCheatPickInfo[pickupid][pType])
		{
			case 1:
			{
				i = WeaponSlots[AntiCheatPickInfo[pickupid][pWeapon]];
				if(AntiCheatInfo[playerid][pWeapon][i] ==
				AntiCheatPickInfo[pickupid][pWeapon]) AntiCheatInfo[playerid][pAmmo][i] +=
				PickupAmmo[AntiCheatPickInfo[pickupid][pWeapon]];
			}
			case 2: AntiCheatInfo[playerid][pSpecAct] = 2;
			case 3: AntiCheatInfo[playerid][pHealth] = 100;
			case 4: AntiCheatInfo[playerid][pArmour] = 100;
		}
		AntiCheatInfo[playerid][pLastPickup] = pickupid;
		AntiCheatInfo[playerid][pPicked] = true;
		#if !defined _inc_y_hooks\
			&& defined ac_OnPlayerPickUpDynamicPickup
			return ac_OnPlayerPickUpDynamicPickup(playerid, pickupid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks
		#if defined _ALS_OnPlayerPick\
			UpDynamicPickup
			#undef OnPlayerPickUpDynamicPickup
		#else
			#define _ALS_OnPlayerPickUpDynamicPickup
		#endif
		#define OnPlayerPickUpDynamicPickup ac_OnPlayerPickUpDynamicPickup
		#if defined ac_OnPlayerPickUpDynamicPickup
			forward ac_OnPlayerPickUpDynamicPickup(playerid, STREAMER_TAG_PICKUP pickupid);
		#endif
	#endif
#endif

#if defined _inc_y_hooks
	Hook:ac_OnPlayerPickUpPickup(playerid, pickupid)
#else
	public OnPlayerPickUpPickup(playerid, pickupid)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][pKicked]) return 0;
	if(!AntiCheatInfo[playerid][pPicked])
	{
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][8] + Mtfc[8][0]) FloodDetect(playerid, 8);
			else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][8] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		if(AntiCheatInfo[playerid][pACAllow][6]
		&& (!(-1 < pickupid < MAX_PICKUPS) || !IsPlayerInRangeOfPoint(playerid,
		5.0, AntiCheatPickInfo[pickupid][pPos][0], AntiCheatPickInfo[pickupid][pPos][1],
		AntiCheatPickInfo[pickupid][pPos][2]))) return KickWithCode(playerid, "", 0, 6, 1);
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][8] = i;
		switch(AntiCheatPickInfo[pickupid][pType])
		{
			case 1:
			{
				i = WeaponSlots[AntiCheatPickInfo[pickupid][pWeapon]];
				if(AntiCheatInfo[playerid][pWeapon][i] ==
				AntiCheatPickInfo[pickupid][pWeapon]) AntiCheatInfo[playerid][pAmmo][i] +=
				PickupAmmo[AntiCheatPickInfo[pickupid][pWeapon]];
			}
			case 2: AntiCheatInfo[playerid][pSpecAct] = 2;
			case 3: AntiCheatInfo[playerid][pHealth] = 100;
			case 4: AntiCheatInfo[playerid][pArmour] = 100;
		}
		AntiCheatInfo[playerid][pLastPickup] = pickupid;
	}
	else AntiCheatInfo[playerid][pPicked] = false;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerPickUpPickup
		if(!AntiCheatPickInfo[pickupid][pIsStatic]) return ac_OnPlayerPickUpPickup(playerid, pickupid);
		return 1;
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerRequestClass(playerid, classid)
#else
	public OnPlayerRequestClass(playerid, classid)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][9] + Mtfc[9][0]) return FloodDetect(playerid, 9);
		if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][9] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pClassid] = classid;
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][9] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerRequestClass
		return ac_OnPlayerRequestClass(playerid, classid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerSelectedMenuRow(playerid, row)
#else
	public OnPlayerSelectedMenuRow(playerid, row)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][10] + Mtfc[10][0]) FloodDetect(playerid, 10);
		else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][10] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][10] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerSelectedMenuRow
		return ac_OnPlayerSelectedMenuRow(playerid, row);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerStateChange(playerid, newstate, oldstate)
#else
	public OnPlayerStateChange(playerid, newstate, oldstate)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount(), bool:ur;
	if(!IsPlayerNPC(playerid))
	{
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][11] + Mtfc[11][0])
			{
				if(newstate != 1 || oldstate != 8) FloodDetect(playerid, 11);
			}
			else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][11] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		if(1 < oldstate < 4)
		{
			switch(oldstate)
			{
				case 2:
				{
					if(AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vDriver] ==
					playerid) AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vDriver] = 65535;
					if(GetVehicleModel(AntiCheatInfo[playerid][pVeh]) == 457
					&& !AntiCheatInfo[playerid][pWeapon][1]) AntiCheatInfo[playerid][pWeapon][1] = 2;
					AntiCheatInfo[playerid][pVehDmgRes] = false;
				}
				case 3:
				{
					if(AntiCheatInfo[playerid][pACAllow][2]
					&& newstate == 1 && !IsPlayerInRangeOfPoint(playerid, 15.0,
					AntiCheatInfo[playerid][pPos][0], AntiCheatInfo[playerid][pPos][1],
					AntiCheatInfo[playerid][pPos][2]) && !(AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vDriver]
					!= 65535 && i > AntiCheatInfo[AntiCheatVehInfo[AntiCheatInfo[playerid][pVeh]][vDriver]][pLastUpdate]
					+ 2000)) KickWithCode(playerid, "", 0, 2, 4);
				}
			}
			new Float:TmpVel[3];
			GetPlayerVelocity(playerid, TmpVel[0], TmpVel[1], TmpVel[2]);
			AntiCheatInfo[playerid][pSpeed] = GetSpeed(TmpVel[0],TmpVel[1],TmpVel[2]);
			ur = true;
		}
		switch(newstate)
		{
			case 1:
			{
				AntiCheatInfo[playerid][pSet][11] = -1;
				AntiCheatInfo[playerid][pEnterVeh] = 0;
				GetPlayerPos(playerid, AntiCheatInfo[playerid][pPos][0],
				AntiCheatInfo[playerid][pPos][1], AntiCheatInfo[playerid][pPos][2]);
			}
			case 2:
			{
				i = GetPlayerVehicleID(playerid);
				if(AntiCheatInfo[playerid][pACAllow][44])
				{
					new seatid;
					if((seatid = GetPlayerVehicleSeat(playerid)) != 128)
					{
						new model = GetVehicleModel(i) - 400;
						if(seatid || model < 0 || MaxPassengers[model >>> 3] >>> ((model & 7) << 2) & 0xF == 15
						&& AntiCheatInfo[playerid][pSet][9] == -1) KickWithCode(playerid, "", 0, 44, 2);
					}
				}
				if(AntiCheatInfo[playerid][pSet][9] == -1)
				{
					AntiCheatVehInfo[i][vDriver] = playerid;
					GetVehicleZAngle(i, AntiCheatVehInfo[i][vZAngle]);
					GetPlayerPos(playerid, AntiCheatInfo[playerid][pPos][0],
					AntiCheatInfo[playerid][pPos][1], AntiCheatInfo[playerid][pPos][2]);
					AntiCheatInfo[playerid][pSetVehHealth] = -1;
				}
			}
			case 3:
			{
				AntiCheatInfo[playerid][pCheatCount][4] = 0;
				if(AntiCheatInfo[playerid][pACAllow][44] && (i = GetPlayerVehicleSeat(playerid)) != 128)
				{
					if(GetVehicleModel(GetPlayerVehicleID(playerid)) ==
					-1) KickWithCode(playerid, "", 0, 44, 3);
					else
					{
						new model = (MaxPassengers[model >>> 3] >>> ((model & 7) << 2)) & 0xF;
						if(i < 1 || (model == 15 || i > model)
						&& AntiCheatInfo[playerid][pSet][9] ==
						-1) KickWithCode(playerid, "", 0, 44, 4);
					}
				}
			}
			case 9:
			{
				if(AntiCheatInfo[playerid][pACAllow][21]
				&& AntiCheatInfo[playerid][pSet][6] ==
				-1) KickWithCode(playerid, "", 0, 21);
				AntiCheatInfo[playerid][pSet][6] = -1;
				AntiCheatInfo[playerid][pSpawnRes] = true;
				AntiCheatInfo[playerid][pSpawnTime] = 0;
			}
		}
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][11] = GetTickCount();
	if(ur) AntiCheatInfo[playerid][pGtc][10] = AntiCheatInfo[playerid][pCall][27];
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerStateChange
		return ac_OnPlayerStateChange(playerid, newstate, oldstate);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
#else
	public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	static i, bool:ur, bool:ur2;
	i = GetTickCount();
	ur = ur2 = false;
	if(!IsPlayerNPC(playerid))
	{
		if(AntiCheatInfo[playerid][pACAllow][22]
		&& !LagCompMode) return KickWithCode(playerid, "", 0, 22);
		if(AntiCheatInfo[playerid][pACAllow][34] && i >
		AntiCheatInfo[playerid][pLastUpdate] + 5000)
		{
			if(++AntiCheatInfo[playerid][pCheatCount][5] >
			MAX_AFK_GHOST_WARNINGS) return KickWithCode(playerid, "", 0, 34);
			#undef MAX_AFK_GHOST_WARNINGS
		}
		else AntiCheatInfo[playerid][pCheatCount][5] = 0;
		if(AntiCheatInfo[playerid][pACAllow][29] && hittype == 1 && i <
		AntiCheatInfo[hitid][pLastUpdate] + 1500 && !IsPlayerInAnyVehicle(hitid)
		&& GetPlayerSurfingVehicleID(hitid) == 65535 && GetPlayerSurfingObjectID(hitid) == 65535)
		{
			static Float:fPos[4];
			GetPlayerLastShotVectors(playerid, fPos[3], fPos[3], fPos[3], fPos[0], fPos[1], fPos[2]);
			if(!IsPlayerInRangeOfPoint(hitid, 5.0, fPos[0], fPos[1], fPos[2]))
			{
				if(++AntiCheatInfo[playerid][pCheatCount][6] >
				MAX_PRO_AIM_WARNINGS) return KickWithCode(playerid, "", 0, 29);
				#undef MAX_PRO_AIM_WARNINGS
			}
			else AntiCheatInfo[playerid][pCheatCount][6] = 0;
		}
		else AntiCheatInfo[playerid][pCheatCount][6] = 0;
		switch(hittype)
		{
			case 1:
			{
				if(AntiCheatInfo[playerid][pACAllow][19]
				&& AntiCheatInfo[hitid][pFreeze]
				&& i > AntiCheatInfo[hitid][pGtc][14]
				+ GetPlayerPing(hitid) + 100)
				{
					static t, j;
					t = GetPlayerTeam(playerid);
					j = GetPlayerInterior(hitid);
					if((t == 255 || t != GetPlayerTeam(hitid))
					&& AntiCheatInfo[hitid][pHealth]
					&& !IsPlayerInRestaurant(hitid, j)
					&& !IsPlayerInAmmuNation(hitid, j)
					&& !IsPlayerInCasino(hitid, j))
					{
						if(AntiCheatInfo[hitid][pArmour]) AntiCheatInfo[hitid][pDmgRes] = 2;
						else AntiCheatInfo[hitid][pDmgRes] = 1;
						AntiCheatInfo[hitid][pCheatCount][9] = 0;
						ur = true;
					}
				}
			}
			case 2:
			{
				if(AntiCheatInfo[playerid][pACAllow][20]
				&& AntiCheatVehInfo[hitid][vDriver] != 65535
				&& AntiCheatInfo[AntiCheatVehInfo[hitid][vDriver]][pFreeze]
				&& AntiCheatVehInfo[hitid][vHealth] > 220.0)
				{
					static t;
					t = GetPlayerTeam(playerid);
					if(!VehFriendlyFire || t == 255
					|| t != GetPlayerTeam(AntiCheatVehInfo[hitid][vDriver]))
					{
						AntiCheatInfo[AntiCheatVehInfo[hitid][vDriver]][pCheatCount][11] = 0;
						ur2 = true;
					}
				}
			}
		}
		static s;
		s = GetPlayerState(playerid);
		if(s != 2)
		{
			if(AntiCheatInfo[playerid][pACAllow][47] && (s != 3 && GetPlayerWeapon(playerid) != weaponid
			|| weaponid != 38 && !(21 < weaponid < 35))) return KickWithCode(playerid, "", 0, 47, 2);
			i -= AntiCheatInfo[playerid][pShotTime];
			if(AntiCheatInfo[playerid][pShot])
			{
				if(AntiCheatInfo[playerid][pACAllow][26] && weaponid != 38)
				{
					if(27 < weaponid < 30 || weaponid == 32)
					{
						if(i < 30 && ++AntiCheatInfo[playerid][pCheatCount][8] >
						MAX_RAPID_FIRE_WARNINGS) return KickWithCode(playerid, "", 0, 26, 1);
					}
					else if(i < 50 || 32 < weaponid < 35 && i < 386)
					{
						if(++AntiCheatInfo[playerid][pCheatCount][8] >
						MAX_RAPID_FIRE_WARNINGS) return KickWithCode(playerid, "", 0, 26, 2);
					}
					else AntiCheatInfo[playerid][pCheatCount][8] = 0;
				}
			}
			else
			{
				if(AntiCheatInfo[playerid][pACAllow][26] && i <
				30) return KickWithCode(playerid, "", 0, 26, 3);
				AntiCheatInfo[playerid][pCheatCount][8] = 0;
				AntiCheatInfo[playerid][pShot] = true;
			}
			if(AntiCheatInfo[playerid][pACAllow][17])
			{
				if(!AntiCheatInfo[playerid][pAmmo][WeaponSlots[weaponid]]) return KickWithCode(playerid, "", 0, 17, 1);
				if((i = abs(AntiCheatInfo[playerid][pAmmo][WeaponSlots[weaponid]] - GetPlayerAmmo(playerid))))
				{
					switch(weaponid)
					{
						case 24, 29:
						{
							if(i > 2 || ++AntiCheatInfo[playerid][pCheatCount][7] >
							2) return KickWithCode(playerid, "", 0, 17, 2);
						}
						case 22, 26, 30, 31:
						{
							if(i > 3 || ++AntiCheatInfo[playerid][pCheatCount][7] >
							3) return KickWithCode(playerid, "", 0, 17, 3);
						}
						case 28, 32:
						{
							if(i > 8) return KickWithCode(playerid, "", 0, 17, 4);
						}
						case 38:
						{
							if(++AntiCheatInfo[playerid][pCheatCount][7] >
							8) return KickWithCode(playerid, "", 0, 17, 5);
						}
						default: return KickWithCode(playerid, "", 0, 17, 6);
					}
				}
				else AntiCheatInfo[playerid][pCheatCount][7] = 0;
			}
			AntiCheatInfo[playerid][pAmmo][WeaponSlots[weaponid]]--;
			if(AntiCheatInfo[playerid][pAmmo][WeaponSlots[weaponid]] <
			-32768) AntiCheatInfo[playerid][pAmmo][WeaponSlots[weaponid]] += 65536;
			else if(!AntiCheatInfo[playerid][pAmmo][WeaponSlots[weaponid]]
			&& AntiCheatInfo[playerid][pSet][3] == weaponid) AntiCheatInfo[playerid][pSet][3] =
			AntiCheatInfo[playerid][pSetWeapon][WeaponSlots[weaponid]] = -1;
		}
	}
	i = 1;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerWeaponShot
		i = ac_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, fX, fY, fZ);
	#endif
	AntiCheatInfo[playerid][pShotTime] = GetTickCount();
	if(i)
	{
		if(ur) AntiCheatInfo[hitid][pGtc][14] = AntiCheatInfo[playerid][pShotTime];
		if(ur2)
		{
			AntiCheatInfo[AntiCheatVehInfo[hitid][vDriver]][pVehDmgRes] = true;
			AntiCheatInfo[AntiCheatVehInfo[hitid][vDriver]][pGtc][16] =
			AntiCheatInfo[playerid][pShotTime];
		}
	}
	return i;
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnVehicleMod(playerid, vehicleid, componentid)
#else
	public OnVehicleMod(playerid, vehicleid, componentid)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][12] + Mtfc[12][0]) FloodDetect(playerid, 12);
		else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][12] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	if(AntiCheatInfo[playerid][pACAllow][23] && !AntiCheatInfo[playerid][pModShop]) return KickWithCode(playerid, "", 0, 23, 2);
	if(AntiCheatInfo[playerid][pACAllow][43] && !IsComponentidCompatible(GetVehicleModel(vehicleid),
	componentid)) return KickWithCode(playerid, "", 0, 43, 1);
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][12] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnVehicleMod
		return ac_OnVehicleMod(playerid, vehicleid, componentid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnVehiclePaintjob(playerid, vehicleid, paintjobid)
#else
	public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][13] + Mtfc[13][0]) FloodDetect(playerid, 13);
		else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][13] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	if(AntiCheatInfo[playerid][pACAllow][23] && !AntiCheatInfo[playerid][pModShop]) KickWithCode(playerid, "", 0, 23, 3);
	else if(AntiCheatInfo[playerid][pACAllow][43] && !(-1 < paintjobid < 3)) KickWithCode(playerid, "", 0, 43, 2);
	else AntiCheatVehInfo[vehicleid][vPaintJob] = paintjobid;
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][13] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnVehiclePaintjob
		return ac_OnVehiclePaintjob(playerid, vehicleid, paintjobid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnVehicleRespray(playerid, vehicleid, color1, color2)
#else
	public OnVehicleRespray(playerid, vehicleid, color1, color2)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][14] + Mtfc[14][0]) FloodDetect(playerid, 14);
		else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][14] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][14] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnVehicleRespray
		return ac_OnVehicleRespray(playerid, vehicleid, color1, color2);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnVehicleSpawn(vehicleid)
#else
	public OnVehicleSpawn(vehicleid)
#endif
{
	AntiCheatVehInfo[vehicleid][vPaintJob] = 3;
	AntiCheatVehInfo[vehicleid][vSpawned] = true;
	AntiCheatVehInfo[vehicleid][vHealth] = 1000.0;
	AntiCheatVehInfo[vehicleid][vSpeedDiff] =
	AntiCheatVehInfo[vehicleid][vPosDiff] =
	AntiCheatVehInfo[vehicleid][vVel][0] =
	AntiCheatVehInfo[vehicleid][vVel][1] =
	AntiCheatVehInfo[vehicleid][vVel][2] = 0.0;
	AntiCheatVehInfo[vehicleid][vDriver] = 65535;
	#if !defined _inc_y_hooks\
		&& defined ac_OnVehicleSpawn
		return ac_OnVehicleSpawn(vehicleid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnVehicleDeath(vehicleid, killerid)
#else
	public OnVehicleDeath(vehicleid, killerid)
#endif
{
	if(killerid != 65535)
	{
		new i = GetTickCount();
		if(AntiCheatInfo[killerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[killerid][pCall][15] + Mtfc[15][0]) FloodDetect(killerid, 15);
			else if(i < AntiCheatInfo[killerid][pCall][27] + Mtfc[27][0]) FloodDetect(killerid, 27);
			else AntiCheatInfo[killerid][pFloodCount][15] = AntiCheatInfo[killerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[killerid][pCall][27] = AntiCheatInfo[killerid][pCall][15] = i;
	}
	AntiCheatVehInfo[vehicleid][vSpawned] = false;
	#if !defined _inc_y_hooks\
		&& defined ac_OnVehicleDeath
		return ac_OnVehicleDeath(vehicleid, killerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerText(playerid, text[])
#else
	public OnPlayerText(playerid, text[])
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][16] + Mtfc[16][0]) return FloodDetect(playerid, 16);
		if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][16] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][16] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerText
		return ac_OnPlayerText(playerid, text);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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
	#if defined _inc_y_hooks
		Hook:ac_OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP checkpointid)
	#else
		public OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP checkpointid)
	#endif
	{
		if(AntiCheatInfo[playerid][pKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][17] + Mtfc[17][0]) return FloodDetect(playerid, 17);
			if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][17] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][17] = i;
		#if !defined _inc_y_hooks\
			&& defined ac_OnPlayerEnterDynamicCP
			return ac_OnPlayerEnterDynamicCP(playerid, checkpointid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks
		#if defined _ALS_OnPlayerEnterDynamicCP
			#undef OnPlayerEnterDynamicCP
		#else
			#define _ALS_OnPlayerEnterDynamicCP
		#endif
		#define OnPlayerEnterDynamicCP ac_OnPlayerEnterDynamicCP
		#if defined ac_OnPlayerEnterDynamicCP
			forward ac_OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP checkpointid);
		#endif
	#endif
#else
	#if defined _inc_y_hooks
		Hook:ac_OnPlayerEnterCheckpoint(playerid)
	#else
		public OnPlayerEnterCheckpoint(playerid)
	#endif
	{
		if(AntiCheatInfo[playerid][pKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][17] + Mtfc[17][0]) return FloodDetect(playerid, 17);
			if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][17] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][17] = i;
		#if !defined _inc_y_hooks\
			&& defined ac_OnPlayerEnterCheckpoint
			return ac_OnPlayerEnterCheckpoint(playerid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks
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
	#if defined _inc_y_hooks
		Hook:ac_OnPlayerLeaveDynamicCP(playerid, STREAMER_TAG_CP checkpointid)
	#else
		public OnPlayerLeaveDynamicCP(playerid, STREAMER_TAG_CP checkpointid)
	#endif
	{
		if(AntiCheatInfo[playerid][pKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][18] + Mtfc[18][0]) return FloodDetect(playerid, 18);
			if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][18] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][18] = i;
		#if !defined _inc_y_hooks\
			&& defined ac_OnPlayerLeaveDynamicCP
			return ac_OnPlayerLeaveDynamicCP(playerid, checkpointid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks
		#if defined _ALS_OnPlayerLeaveDynamicCP
			#undef OnPlayerLeaveDynamicCP
		#else
			#define _ALS_OnPlayerLeaveDynamicCP
		#endif
		#define OnPlayerLeaveDynamicCP ac_OnPlayerLeaveDynamicCP
		#if defined ac_OnPlayerLeaveDynamicCP
			forward ac_OnPlayerLeaveDynamicCP(playerid, STREAMER_TAG_CP checkpointid);
		#endif
	#endif
#else
	#if defined _inc_y_hooks
		Hook:ac_OnPlayerLeaveCheckpoint(playerid)
	#else
		public OnPlayerLeaveCheckpoint(playerid)
	#endif
	{
		if(AntiCheatInfo[playerid][pKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][18] + Mtfc[18][0]) return FloodDetect(playerid, 18);
			if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][18] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][18] = i;
		#if !defined _inc_y_hooks\
			&& defined ac_OnPlayerLeaveCheckpoint
			return ac_OnPlayerLeaveCheckpoint(playerid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerRequestSpawn(playerid)
#else
	public OnPlayerRequestSpawn(playerid)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][19] + Mtfc[19][0]) return FloodDetect(playerid, 19);
		if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][19] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pSpawnWeapon][0] = Class[AntiCheatInfo[playerid][pClassid]][0][0];
	AntiCheatInfo[playerid][pSpawnAmmo][0] = Class[AntiCheatInfo[playerid][pClassid]][0][1];
	AntiCheatInfo[playerid][pSpawnWeapon][1] = Class[AntiCheatInfo[playerid][pClassid]][1][0];
	AntiCheatInfo[playerid][pSpawnAmmo][1] = Class[AntiCheatInfo[playerid][pClassid]][1][1];
	AntiCheatInfo[playerid][pSpawnWeapon][2] = Class[AntiCheatInfo[playerid][pClassid]][2][0];
	AntiCheatInfo[playerid][pSpawnAmmo][2] = Class[AntiCheatInfo[playerid][pClassid]][2][1];
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][19] = i;
	i = 1;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerRequestSpawn
		i = ac_OnPlayerRequestSpawn(playerid);
	#endif
	if(i) AntiCheatInfo[playerid][pSet][7] = 1;
	return i;
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerExitedMenu(playerid)
#else
	public OnPlayerExitedMenu(playerid)
#endif
{
	if(!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][20] + Mtfc[20][0]) FloodDetect(playerid, 20);
		else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][20] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][20] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerExitedMenu
		return ac_OnPlayerExitedMenu(playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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
	#if defined _inc_y_hooks
		Hook:ac_OnPlayerEnterDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid)
	#else
		public OnPlayerEnterDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid)
	#endif
	{
		if(AntiCheatInfo[playerid][pKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][21] + Mtfc[21][0]) return FloodDetect(playerid, 21);
			if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][21] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][21] = i;
		#if !defined _inc_y_hooks\
			&& defined ac_OnPlayerEnterDynamicRaceCP
			return ac_OnPlayerEnterDynamicRaceCP(playerid, checkpointid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks
		#if defined _ALS_OnPlayerEnterDynamicRaceCP
			#undef OnPlayerEnterDynamicRaceCP
		#else
			#define _ALS_OnPlayerEnterDynamicRaceCP
		#endif
		#define OnPlayerEnterDynamicRaceCP ac_OnPlayerEnterDynamicRaceCP
		#if defined ac_OnPlayerEnterDynamicRaceCP
			forward ac_OnPlayerEnterDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid);
		#endif
	#endif
#else
	#if defined _inc_y_hooks
		Hook:ac_OnPlayerEnterRaceCheckpoint(playerid)
	#else
		public OnPlayerEnterRaceCheckpoint(playerid)
	#endif
	{
		if(AntiCheatInfo[playerid][pKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][21] + Mtfc[21][0]) return FloodDetect(playerid, 21);
			if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][21] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][21] = i;
		#if !defined _inc_y_hooks\
			&& defined ac_OnPlayerEnterRaceCheckpoint
			return ac_OnPlayerEnterRaceCheckpoint(playerid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks
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
	#if defined _inc_y_hooks
		Hook:ac_OnPlayerLeaveDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid)
	#else
		public OnPlayerLeaveDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid)
	#endif
	{
		if(AntiCheatInfo[playerid][pKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][22] + Mtfc[22][0]) return FloodDetect(playerid, 22);
			if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][22] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][22] = i;
		#if !defined _inc_y_hooks\
			&& defined ac_OnPlayerLeaveDynamicRaceCP
			return ac_OnPlayerLeaveDynamicRaceCP(playerid, checkpointid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks
		#if defined _ALS_OnPlayerLeaveDynamicRaceCP
			#undef OnPlayerLeaveDynamicRaceCP
		#else
			#define _ALS_OnPlayerLeaveDynamicRaceCP
		#endif
		#define OnPlayerLeaveDynamicRaceCP ac_OnPlayerLeaveDynamicRaceCP
		#if defined ac_OnPlayerLeaveDynamicRaceCP
			forward ac_OnPlayerLeaveDynamicRaceCP(playerid, STREAMER_TAG_RACE_CP checkpointid);
		#endif
	#endif
#else
	#if defined _inc_y_hooks
		Hook:ac_OnPlayerLeaveRaceCheckpoint(playerid)
	#else
		public OnPlayerLeaveRaceCheckpoint(playerid)
	#endif
	{
		if(AntiCheatInfo[playerid][pKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][22] + Mtfc[22][0]) return FloodDetect(playerid, 22);
			if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][22] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][22] = i;
		#if !defined _inc_y_hooks\
			&& defined ac_OnPlayerLeaveRaceCheckpoint
			return ac_OnPlayerLeaveRaceCheckpoint(playerid);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
#else
	public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][23] + Mtfc[23][0]) return FloodDetect(playerid, 23);
		if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][23] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][23] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerClickPlayerTextDraw
		return ac_OnPlayerClickPlayerTextDraw(playerid, playertextid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnVehicleDamageStatusUpdate(vehicleid, playerid)
#else
	public OnVehicleDamageStatusUpdate(vehicleid, playerid)
#endif
{
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][24] + Mtfc[24][0]) FloodDetect(playerid, 24);
		else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][24] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][24] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnVehicleDamageStatusUpdate
		return ac_OnVehicleDamageStatusUpdate(vehicleid, playerid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnVehicleSirenStateChange(playerid, vehicleid, newstate)
#else
	public OnVehicleSirenStateChange(playerid, vehicleid, newstate)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	new i = GetTickCount();
	if(AntiCheatInfo[playerid][pACAllow][49])
	{
		if(i < AntiCheatInfo[playerid][pCall][25] + Mtfc[25][0]) FloodDetect(playerid, 25);
		else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
		else AntiCheatInfo[playerid][pFloodCount][25] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
	}
	AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][25] = i;
	#if !defined _inc_y_hooks\
		&& defined ac_OnVehicleSirenStateChange
		return ac_OnVehicleSirenStateChange(playerid, vehicleid, newstate);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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
	#if defined _inc_y_hooks
		Hook:ac_OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
	#else
		public OnPlayerSelectDynamicObject(playerid, objectid, modelid, Float:x, Float:y, Float:z)
	#endif
	{
		if(AntiCheatInfo[playerid][pKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][26] + Mtfc[26][0]) FloodDetect(playerid, 26);
			else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][26] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][26] = i;
		#if !defined _inc_y_hooks\
			&& defined ac_OnPlayerSelectDynamicObject
			return ac_OnPlayerSelectDynamicObject(playerid, objectid, modelid, x, y, z);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks
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
	#if defined _inc_y_hooks
		Hook:ac_OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ)
	#else
		public OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ)
	#endif
	{
		if(AntiCheatInfo[playerid][pKicked]) return 0;
		new i = GetTickCount();
		if(AntiCheatInfo[playerid][pACAllow][49])
		{
			if(i < AntiCheatInfo[playerid][pCall][26] + Mtfc[26][0]) FloodDetect(playerid, 26);
			else if(i < AntiCheatInfo[playerid][pCall][27] + Mtfc[27][0]) FloodDetect(playerid, 27);
			else AntiCheatInfo[playerid][pFloodCount][26] = AntiCheatInfo[playerid][pFloodCount][27] = 0;
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][26] = i;
		#if !defined _inc_y_hooks\
			&& defined ac_OnPlayerSelectObject
			return ac_OnPlayerSelectObject(playerid, type, objectid, modelid, fX, fY, fZ);
		#else
			return 1;
		#endif
	}

	#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z)
#else
	public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	static Float:vpos[4];
	GetVehiclePos(vehicleid, vpos[0], vpos[1], vpos[2]);
	vpos[3] = GetVehicleDistanceFromPoint(vehicleid, new_x, new_y, new_z);
	if(passenger_seat)
	{
		static Float:zdiff;
		zdiff = new_z - vpos[2];
		if(AntiCheatInfo[playerid][pACAllow][31] && (floatabs(vel_x) > 0.3 && floatabs(vel_x) >=
		floatabs(AntiCheatVehInfo[vehicleid][vVel][0]) || floatabs(vel_y) > 0.3 && floatabs(vel_y) >=
		floatabs(AntiCheatVehInfo[vehicleid][vVel][1])) && zdiff > -5.0)
		{
			if(++AntiCheatInfo[playerid][pCheatCount][4] >
			MAX_CARSHOT_WARNINGS) return KickWithCode(playerid, "", 0, 31);
			#undef MAX_CARSHOT_WARNINGS
		}
		else if(AntiCheatInfo[playerid][pACAllow][8] && vel_z >= 0.1 && vel_z >
		AntiCheatVehInfo[vehicleid][vVel][2] && floatabs(vpos[0] - new_x) <
		zdiff * 1.2 && floatabs(vpos[1] - new_y) < zdiff * 1.2)
		{
			if(++AntiCheatInfo[playerid][pCheatCount][3] >
			MAX_FLYHACK_VEH_WARNINGS) return KickWithCode(playerid, "", 0, 8, 2);
			#undef MAX_FLYHACK_VEH_WARNINGS
		}
		else AntiCheatInfo[playerid][pCheatCount][4] =
		AntiCheatInfo[playerid][pCheatCount][3] = 0;
	}
	if(AntiCheatInfo[playerid][pACAllow][5] && vpos[3] > 15.0 && vpos[2] > -70.0
	&& vpos[3] > AntiCheatVehInfo[vehicleid][vPosDiff] + ((vpos[3] / 3) * 1.5))
	{
		GetVehicleZAngle(vehicleid, AntiCheatVehInfo[vehicleid][vZAngle]);
		SetVehicleZAngle(vehicleid, AntiCheatVehInfo[vehicleid][vZAngle]);
		SetVehiclePos(vehicleid, vpos[0], vpos[1], vpos[2]);
		return 0;
	}
	static a;
	a = 1;
	#if !defined _inc_y_hooks\
		&& defined ac_OnUnoccupiedVehicleUpdate
		a = ac_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, new_x, new_y, new_z, vel_x, vel_y, vel_z);
	#endif
	if(a)
	{
		AntiCheatVehInfo[vehicleid][vSpeedDiff] =
		GetSpeed(vel_x,vel_y,vel_z)
		- GetSpeed(AntiCheatVehInfo[vehicleid][vVel][0],AntiCheatVehInfo[vehicleid][vVel][1],AntiCheatVehInfo[vehicleid][vVel][2]);
		AntiCheatVehInfo[vehicleid][vPosDiff] = vpos[3];
		AntiCheatVehInfo[vehicleid][vVel][0] = vel_x;
		AntiCheatVehInfo[vehicleid][vVel][1] = vel_y;
		AntiCheatVehInfo[vehicleid][vVel][2] = vel_z;
	}
	return a;
}

#if !defined _inc_y_hooks
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

#if defined _inc_y_hooks
	Hook:ac_OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
#else
	public OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
#endif
{
	if(AntiCheatInfo[playerid][pKicked]) return 0;
	if(AntiCheatInfo[playerid][pACAllow][46] && 383 < modelid < 394) return KickWithCode(playerid, "", 0, 46);
	#if !defined _inc_y_hooks\
		&& defined ac_OnPlayerEditAttachedObject
		return ac_OnPlayerEditAttachedObject(playerid, response, index, modelid, boneid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks
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
	if(!IsPlayerConnected(playerid) || AntiCheatInfo[playerid][pKicked]) return 0;
	if(AntiCheatInfo[playerid][pACAllow][51] && NetStats_MessagesRecvPerSecond(playerid) >
	MAX_MSGS_REC_DIFF) KickWithCode(playerid, "", 0, 51);
	#undef MAX_MSGS_REC_DIFF
	static gtc, gpp, bool:ur;
	gtc = GetTickCount();
	ur = false;
	gpp = GetPlayerPing(playerid) + 100;
	if(gtc > AntiCheatInfo[playerid][pGtc][7] + gpp)
	{
		for(new i, w, a, bool:cw, s = WeaponSlots[GetPlayerWeapon(playerid)]; i < 13; ++i)
		{
			GetPlayerWeaponData(playerid, i, w, a);
			if(w == 39) cw = true;
			if(s != i)
			{
				if(AntiCheatInfo[playerid][pSetWeapon][i] != -1)
				{
					if(AntiCheatInfo[playerid][pSetWeapon][i] == w)
					{
						AntiCheatInfo[playerid][pSetWeapon][i] = -1;
						AntiCheatInfo[playerid][pWeapon][i] = w;
					}
					else if(AntiCheatInfo[playerid][pACAllow][52]
					&& gtc > AntiCheatInfo[playerid][pGtcSetWeapon][i] + gpp
					&& ++AntiCheatInfo[playerid][pNOPCount][0] > MAX_NOP_WARNINGS)
					{
						#if defined DEBUG
							printf(DEBUG_CODE_5, playerid, "GivePlayerWeapon");
						#endif
						KickWithCode(playerid, "", 0, 52, 13);
					}
				}
				else
				{
					if(AntiCheatInfo[playerid][pWeapon][i] != w)
					{
						if(!w)
						{
							AntiCheatInfo[playerid][pWeapon][i] = 0;
							AntiCheatInfo[playerid][pAmmo][i] = a;
						}
						else if(w == 40 && cw || w == 46 && AntiCheatInfo[playerid][pVeh]
						&& AntiCheatInfo[playerid][pParachute])
						{
							AntiCheatInfo[playerid][pWeapon][i] = w;
							AntiCheatInfo[playerid][pAmmo][i] = a;
						}
						else if(AntiCheatInfo[playerid][pLastPickup] > -1
						&& AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pWeapon] == w
						&& a == PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pWeapon]]
						&& IsPlayerInRangeOfPoint(playerid, 5.0, AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pPos][0],
						AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pPos][1],
						AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pPos][2]))
						{
							AntiCheatInfo[playerid][pWeapon][i] = w;
							if(2 < i < 6) AntiCheatInfo[playerid][pAmmo][i] +=
							PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pWeapon]];
							else AntiCheatInfo[playerid][pAmmo][i] =
							PickupAmmo[AntiCheatPickInfo[AntiCheatInfo[playerid][pLastPickup]][pWeapon]];
						}
						else if(AntiCheatInfo[playerid][pACAllow][15] && !(15 < w
						< 44 && !a)) KickWithCode(playerid, "", 0, 15, 2);
					}
					if(AntiCheatInfo[playerid][pGiveAmmo][i] != -65535)
					{
						if(AntiCheatInfo[playerid][pGiveAmmo][i] == a)
						{
							AntiCheatInfo[playerid][pGiveAmmo][i] = -65535;
							AntiCheatInfo[playerid][pAmmo][i] = a;
						}
						else if(AntiCheatInfo[playerid][pACAllow][52] && gtc >
						AntiCheatInfo[playerid][pGtcGiveAmmo][i] + gpp)
						{
							if(++AntiCheatInfo[playerid][pNOPCount][1] > MAX_NOP_WARNINGS)
							{
								#undef MAX_NOP_WARNINGS
								#if defined DEBUG
									printf(DEBUG_CODE_5, playerid, "SetPlayerAmmo");
								#endif
								KickWithCode(playerid, "", 0, 52, 14);
							}
						}
					}
					if(15 < w < 44)
					{
						if(w == 40)
						{
							if(!a) AntiCheatInfo[playerid][pWeapon][i]
							= AntiCheatInfo[playerid][pAmmo][i] = 0;
							else if(AntiCheatInfo[playerid][pACAllow][16] && !AntiCheatInfo[playerid][pAmmo][i]
							&& a > AntiCheatInfo[playerid][pAmmo][i]) KickWithCode(playerid, "", 0, 16, 2);
						}
						else if(AntiCheatInfo[playerid][pACAllow][16] && a >
						AntiCheatInfo[playerid][pAmmo][i]) KickWithCode(playerid, "", 0, 16, 3);
					}
				}
			}
			else if(21 < w < 33 || 40 < w < 43
			|| !LagCompMode && (15 < w < 40 || w == 43))
			{
				if(AntiCheatInfo[playerid][pACAllow][16] && a > AntiCheatInfo[playerid][pAmmo][i]
				&& AntiCheatInfo[playerid][pGiveAmmo][i] == -65535)
				{
					if(21 < w < 33 && !ur && IsPlayerInAmmuNation(playerid,
					GetPlayerInterior(playerid)) && AmmuNationInfo[w-22][1] ==
					abs(a - AntiCheatInfo[playerid][pAmmo][i]))
					{
						#undef abs
						if(AntiCheatInfo[playerid][pSet][10]
						!= -1) AntiCheatInfo[playerid][pSet][10] += AmmuNationInfo[w-22][0];
						else AntiCheatInfo[playerid][pSet][10] = AmmuNationInfo[w-22][0];
						AntiCheatInfo[playerid][pAmmo][i] += AmmuNationInfo[w-22][1];
						AntiCheatInfo[playerid][pCheatCount][10] = 0;
						ur = true;
					}
					else if(!LagCompMode) KickWithCode(playerid, "", 0, 16, 4);
				}
				else if(AntiCheatInfo[playerid][pAmmo][i]
				&& !LagCompMode) AntiCheatInfo[playerid][pAmmo][i] = a;
			}
		}
	}
	AntiCheatInfo[playerid][pCheatCount][1] =
	AntiCheatInfo[playerid][pCheatCount][2] = 0;
	if(ur) AntiCheatInfo[playerid][pGtc][15] = gtc;
	AntiCheatInfo[playerid][pTimerID] = SetTimerEx("acTimer", 1000, false, "i", playerid);
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
		if(GetPlayerState(playerid) == 2) AntiCheatInfo[playerid][pKicked] = 2;
		else AntiCheatInfo[playerid][pKicked] = 1;
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
					QueryEnable = !!GetServerVarAsBool("query");
				#endif
				RconEnable = !!GetServerVarAsBool("rcon");
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
	#if defined foreachex
		foreachex(Player, enable) AntiCheatInfo[enable][pACAllow][acid] = ACAllow[acid];
	#else
		for(enable = GetPlayerPoolSize(); enable != -1; --enable)
		{
			if(IsPlayerConnected(enable)) AntiCheatInfo[enable][pACAllow][acid] = ACAllow[acid];
		}
	#endif
	return 1;
}

stock EnableAntiCheatForPlayer(playerid, acid, enable)
{
	if(!IsPlayerConnected(playerid) || !(-1 < acid < sizeof ACAllow)) return 0;
	AntiCheatInfo[playerid][pACAllow][acid] = !!enable;
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
	return AntiCheatInfo[playerid][pACAllow][acid];
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
	if(!AntiCheatInfo[playerid][pKicked])
	{
		if(++AntiCheatInfo[playerid][pFloodCount][publicid] > Mtfc[publicid][1])
		{
			#if defined DEBUG
				printf(DEBUG_CODE_1, playerid, Mtfc[publicid][1], publicid);
				#undef DEBUG
			#endif
			return KickWithCode(playerid, "", 0, 49, publicid);
		}
		AntiCheatInfo[playerid][pCall][27] = AntiCheatInfo[playerid][pCall][publicid] = GetTickCount();
	}
	return 0;
}

static KickWithCode(playerid, ip_address[], type, code, code2 = 0)
{
	if(!type && (!IsPlayerConnected(playerid)
	|| AntiCheatInfo[playerid][pKicked])
	|| !(-1 < code < sizeof ACAllow)) return 0;
	StatsInfo[5]++;
	switch(code)
	{
		case 0..35, 37, 39, 52: StatsInfo[0]++;
		case 36, 38, 40, 41, 51: StatsInfo[4]++;
		case 42: StatsInfo[1]++;
		case 48..50: StatsInfo[3]++;
		case 43..47: StatsInfo[2]++;
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
