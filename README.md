# Nex-AC - Anticheat system

Nex Anticheat (Nex-AC) - is a comprehensive protection which combines powerful anticheat and protection against various attacks (flood, DoS).  
Anticheat detects popular cheats instantly punishing cheaters.  
Anti-DoS combines customizable anti-flood, anti-DoS at network level and a lot of protection tools against hacking, crashers etc.

## List of basic anti-cheats:
* Anti-AirBreak (onfoot/in vehicle)
* Anti-teleport hack (onfoot/into/in/between vehicles)
* Anti-teleport (pickups)
* Anti-FlyHack (onfoot/in vehicle)
* Anti-SpeedHack (onfoot/in vehicle)
* Anti-Health hack (onfoot/in vehicle) and armour hack
* Anti-Weapon hack and (add/infinite) ammo hack
* Anti-Special actions hack (including jetpack)
* Anti-GodMode from bullets (onfoot/in vehicle)
* Anti-Invisible hack
* Anti-Money hack
* Anti-Tuning hack
* Anti-lagcomp-spoof
* Anti-Parkour mod
* Anti-Quick turn
* Anti-Rapid fire
* Anti-FakeSpawn
* Anti-FakeKill
* Anti-Pro Aim
* Anti-CJ run
* Anti-CarShot
* Anti-CarJack
* Anti-UnFreeze
* Anti-AFK Ghost
* Anti-Reconnect
* Anti-High ping
* Anti-Fake NPC
* Anti-Dialog hack
* Protection from sandbox
* Protection from invalid version
* Protection from flood by seat changing
* Protection from connection flood in one slot
* Anti-Rcon hack (brute/brute-force)
* Anti-callback functions flood *(complete list below)*
* Anti-crashers *(complete list below)*
* Anti-NOPs *(complete list below)*
* Anti-DoS

# Additional features:
* **Setting anticheat from file**  
The settings is located in a separate file (scriptfiles\nex-ac_settings.cfg)
* **Statistics viewing**  
Ability to view statistics of the anticheat for all the time of server work since its launch  
Displayed automatically when the server turns off. Stored in a server log (server_log.txt)
* **Logging the most important actions**  
Optionally, you can enable debug-mode for logging all actions
* **Multilingual**  
Ability to set any of the available languages  
It also simplifies the process of translation of anticheat into other languages

## List of publics which are protected by anti-flood:
* OnDialogResponse
* OnEnterExitModShop
* OnPlayerClickMap
* OnPlayerClickPlayer
* OnPlayerClickTextDraw
* OnPlayerCommandText
* OnPlayerEnterVehicle
* OnPlayerExitVehicle
* OnPlayerPickUpPickup
* OnPlayerRequestClass
* OnPlayerSelectedMenuRow
* OnPlayerStateChange
* OnVehicleMod
* OnVehiclePaintjob
* OnVehicleRespray
* OnVehicleDeath
* OnPlayerText
* OnPlayerEnterCheckpoint
* OnPlayerLeaveCheckpoint
* OnPlayerRequestSpawn
* OnPlayerExitedMenu
* OnPlayerEnterRaceCheckpoint
* OnPlayerLeaveRaceCheckpoint
* OnPlayerClickPlayerTextDraw
* OnVehicleDamageStatusUpdate
* OnPlayerSelectObject

## Anti-NOPs:
* SpawnPlayer
* SetPlayerPos
* SetVehiclePos
* SetPlayerAmmo
* SetPlayerHealth
* SetPlayerArmour
* SetVehicleHealth
* GivePlayerWeapon
* SetPlayerPosFindZ
* SetPlayerInterior
* PutPlayerInVehicle
* ResetPlayerWeapons
* SetPlayerSpecialAction
* TogglePlayerSpectating
* RemovePlayerFromVehicle

## Anti-Crashers:
* Invalid tuning
* Invalid vehicle seat
* Illegal characters in the dialogs (deleting)
* Invalid attached objects
* Weapon Crasher

# Functions:
#### public OnCheatDetected(playerid, ip_address[], type, code)
> Called when triggers one of the anti-cheats
> * `playerid` - The ID of the cheater
> * `ip_address[]` - IP-address of the cheater
> * `type` - Type of cheating (when `0` it returns the ID, when `1` - IP)
> * `code` - The code (ID) of the anti-cheat
> * This callback does not handle returns

#### EnableAntiCheat(code, enable)
> Use to enable/disable one of the anti-cheats
> * `code` - The ID of the anti-cheat
> * `enable` - `1` to enable/`0` to disable
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the `code` parameter contains an invalid ID of the anti-cheat

#### EnableAntiCheatForPlayer(playerid, code, enable)
> Use to enable/disable one of the anti-cheats for a specific player
> * `playerid` - The ID of the player to enable/disable the anti-cheat for
> * `code` - The ID of the anti-cheat
> * `enable` - `1` to enable/`0` to disable
> * Returns `1` if the function executed successfully, `0` if the player is not connected or `-1` if the `code` parameter contains an invalid ID of the anti-cheat

Added in v1.3:

#### IsAntiCheatEnabled(code)
> Use to check whether one of the anti-cheats is enabled/disabled
> * `code` - The ID of the anti-cheat to check
> * Return `1 (true)` if enabled or `0 (false)` if disabled

#### IsAntiCheatEnabledForPlayer(playerid, code)
> Use to check whether one of the anti-cheats is enabled/disabled for a specific player
> * `playerid` - The ID of the player to be checked whether the anti-cheat is enabled/disabled for him
> * `code` - The ID of the anti-cheat to check
> * Return `1 (true)` if enabled or `0 (false)` if disabled

Added in v1.8.8:

#### AntiCheatGetHealth(playerid, &Float:health)
> Use to get the amount of the player's health (according to anticheat data)
> * `playerid` - The ID of the player to get the health of
> * `&Float:health` - A variable to store the health in, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the player is not connected

#### AntiCheatGetArmour(playerid, &Float:armour)
> Use to get the amount of the player's armour (according to anticheat data)
> * `playerid` - The ID of the player to get the armour of
> * `&Float:armour` - A variable to store the armour in, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the player is not connected

#### AntiCheatGetVehicleHealth(vehicleid, &Float:health)
> Use to get the amount of the vehicle's health (according to anticheat data)
> * `vehicleid` - The ID of the vehicle to get the health of
> * `&Float:health` - A variable to store the health in, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the vehicle does not exist

#### AntiCheatGetWeaponData(playerid, slot, &weapons, &ammo)
> Use to get the weapon and ammo in a specific player's weapon slot (according to anticheat data)
> * `playerid` - The ID of the player whose weapon data to retrieve
> * `slot` - The slot to get the weapon and ammo for
> * `&weapons` - A variable to store the weapon ID in, passed by reference
> * `&ammo` - A variable to store the ammo in, passed by reference
> * Returns `1` if the function executed successfully, `0` if the player is not connected or `-1` if the slot specified is invalid

#### AntiCheatGetSpawnWeapon(playerid, &weapon1, &weapon1_ammo, &weapon2, &weapon2_ammo, &weapon3, &weapon3_ammo)
> Use to get the spawn weapons and ammo of a player
> * `playerid` - The ID of the player whose spawn weapons and ammo to retrieve
> * `&weapon1` - A variable in which to store weapon 1, passed by reference
> * `&weapon1_ammo` - A variable in which to store the amount of ammo for weapon 1, passed by reference
> * `&weapon2` - A variable in which to store weapon 2, passed by reference
> * `&weapon2_ammo` - A variable in which to store the amount of ammo for weapon 2, passed by reference
> * `&weapon3` - A variable in which to store weapon 3, passed by reference
> * `&weapon3_ammo` - A variable in which to store the amount of ammo for weapon 3, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the player is not connected

#### AntiCheatGetPos(playerid, &Float:x, &Float:y, &Float:z)
> Use to get the position of a player (according to anticheat data)
> * `playerid` - The ID of the player to get the position of
> * `&Float:x` - A variable to store the x coordinate in, passed by reference
> * `&Float:y` - A variable to store the y coordinate in, passed by reference
> * `&Float:z` - A variable to store the z coordinate in, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the player is not connected

#### AntiCheatGetVehicleVelocity(vehicleid, &Float:x, &Float:y, &Float:z)
> Use to get the velocity of a vehicle (according to anticheat data)
> * `vehicleid` - The ID of the vehicle to get the velocity of
> * `&Float:x` - A variable to store the x velocity in, passed by reference
> * `&Float:y` - A variable to store the y velocity in, passed by reference
> * `&Float:z` - A variable to store the z velocity in, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the vehicle does not exist

#### AntiCheatGetSpeed(playerid)
> Use to get the speed of a player
> * `playerid` - The ID of the player to get the speed of
> * Returns the player's speed or `0` if the player is not connected

#### AntiCheatGetAnimationIndex(playerid)
> Use to get the index (ID) of the player's current animation (according to anticheat data)
> * `playerid` - The ID of the player to get the animation index of
> * Returns the ID of the animation or `0` if the player is not connected

#### AntiCheatGetDialog(playerid)
> Use to get the ID of the opened dialog for a player
> * `playerid` - The ID of the player to get the active dialog ID for
> * Returns the ID of the dialog or `-1` if the player is not connected

#### AntiCheatGetEnterVehicle(playerid)
> Use to get the ID of the vehicle a player attempted to enter last time
> * `playerid` - The ID of the player to get the last entered vehicle ID of
> * Returns the ID of the entered vehicle or `0` if the player is not connected

#### AntiCheatGetVehicleID(playerid)
> Use to get the ID of the vehicle a player is currently in (according to anticheat data)
> * `playerid` - The ID of the player in the vehicle to get the ID of
> * Returns the ID of the vehicle or `0` if the player is not connected

#### AntiCheatGetWeapon(playerid)
> Use to get the ID of the player's current weapon (according to anticheat data)
> * `playerid` - The ID of the player to get the currently held weapon of
> * Returns the ID of the weapon or `-1` if the player is not connected

#### AntiCheatGetVehicleSeat(playerid)
> Use to get the seat of the vehicle a player is currently in (according to anticheat data)
> * `playerid` - The ID of the player to get the seat of
> * Returns the ID of the seat or `-1` if the player is not connected

#### AntiCheatGetSpecialAction(playerid)
> Use to get the ID of the player's special action (according to anticheat data)
> * `playerid` - The ID of the player to get the special action of
> * Returns the ID of the special action or `0` if the player is not connected

#### AntiCheatGetLastSpecialAction(playerid)
> Use to get the ID of the player's previous special action
> * `playerid` - The ID of the player to get the previous special action of
> * Returns the ID of the previous special action or `0` if the player is not connected

#### AntiCheatGetLastShotWeapon(playerid)
> Use to get the ID of the last weapon a player shot from
> * `playerid` - The ID of the player to get the last shot weapon ID of
> * Returns the ID of the last shot weapon or `-1` if the player is not connected

#### AntiCheatGetLastPickup(playerid)
> Use to get the ID of the last pickup which a player picked up
> * `playerid` - The ID of the player to get the last picked up pickup ID of
> * Returns the ID of the last picked up pickup or `-1` if the player is not connected

#### AntiCheatGetLastUpdateTime(playerid)
> Use to get the player's last update tick
> * `playerid` - The ID of the player to get the last update tick of
> * Returns the tick of the last update or `0` if the player is not connected

#### AntiCheatGetLastReloadTime(playerid)
> Use to get the player's last weapon reload tick
> * `playerid` - The ID of the player to get the last reload tick of
> * Returns the tick of the last reload or `0` if the player is not connected

#### AntiCheatGetLastEnteredVehTime(playerid)
> Use to get the player's last entering vehicle attempt tick
> * `playerid` - The ID of the player to get the last entering vehicle attempt tick of
> * Returns the tick of the last entering attempt or `0` if the player is not connected

#### AntiCheatGetLastShotTime(playerid)
> Use to get the player's last weapon shot tick
> * `playerid` - The ID of the player to get the last shot tick of
> * Returns the tick of the last shot or `0` if the player is not connected

#### AntiCheatGetLastSpawnTime(playerid)
> Use to get the player's last spawn tick
> * `playerid` - The ID of the player to get the last spawn tick of
> * Returns the tick of the last spawn or `0` if the player is not connected

#### AntiCheatIntEnterExitsIsEnabled(playerid)
> Use to check whether the enter/exit markers in interiors are enabled/disabled for a player
> * `playerid` - The ID of the player to check
> * Returns `1 (true)` if enabled or `0 (false)` if disabled

#### AntiCheatStuntBonusIsEnabled(playerid)
> Use to check whether stunt bonus is enabled/disabled for a player
> * `playerid` - The ID of the player to check
> * Returns `1 (true)` if enabled or `0 (false)` if disabled

#### AntiCheatIsInModShop(playerid)
> Use to check whether a player is in ModShop or not
> * `playerid` - The ID of the player to check
> * Returns `1 (true)` if it is or `0 (false)` if it is not

#### AntiCheatIsFrozen(playerid)
> Use to check whether a player is frozen or not
> * `playerid` - The ID of the player to check
> * Returns `1 (true)` if frozen or `0 (false)` if not frozen

#### AntiCheatIsDead(playerid)
> Use to check whether a player is dead or not
> * `playerid` - The ID of the player to check
> * Returns `1 (true)` if dead or `0 (false)` if not dead

#### AntiCheatIsConnected(playerid)
> Use to check whether a player is on the server or not
> * `playerid` - The ID of the player to check
> * Returns `1 (true)` if it is or `0 (false)` if it is not

Added in v1.9.37:

#### public OnCheatWarning(playerid, ip_address[], type, code, code2, count)
> Called when triggers any warnings of one of the anti-cheats
> * `playerid` - The ID of the suspected cheater
> * `ip_address[]` - IP-address of the suspected cheater
> * `type` - Type of cheating (when `0` it returns the ID, when `1` - IP)
> * `code` - The code (ID) of the anti-cheat
> * `code2` - The subcode (ID) of the anti-cheat check
> * `count` - Count of warnings triggered on suspected cheater
> * This callback does not handle returns

#### public OnFloodWarning(playerid, publicid, count)
> Called when triggers any anti-flood warnings on one of the protected publics
> * `playerid` - The ID of the suspected flooder
> * `publicid` - The ID of the public that was called too quickly
> * `count` - Count of warnings triggered on suspected flooder
> * This callback does not handle returns

#### public OnNOPWarning(playerid, nopid, count)
> Called when triggers any NOP warnings on one of the protected functions
> * `playerid` - The ID of the suspected cheater
> * `nopid` - The ID of the NOP check
> * `count` - Count of warnings triggered on suspected cheater
> * This callback does not handle returns

#### AntiCheatKickWithDesync(playerid, code)
> Use to kick with desync a specific player by the anticheat
> * `playerid` - The ID of the player who will be kicked with desync for the delay time
> * `code` - The ID of the anti-cheat (with some codes the player's vehicle will be resynced after his disconnection)
> * Returns `1` if the function executed successfully, `0` if the player is not connected or `-1` if the player has already been kicked

#### AntiCheatIsKickedWithDesync(playerid)
> Use to check whether a player is (being) kicked or not
> * `playerid` - The ID of the player to check
> * Returns `1` for kick onfoot, `2` for kick in a vehicle (driver), `3` if player is already disconnected or `0` if he isn't kicked

Added in v1.9.40:

#### AntiCheatGetSpawnPos(playerid, &Float:x, &Float:y, &Float:z)
> Use to get the spawn position of a player
> * `playerid` - The ID of the player to get the spawn position of
> * `&Float:x` - A variable to store the x coordinate in, passed by reference
> * `&Float:y` - A variable to store the y coordinate in, passed by reference
> * `&Float:z` - A variable to store the z coordinate in, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the player is not connected

Added in v1.9.41:

#### EnableAntiNOP(nopcode, enable)
> Use to enable/disable one of the anti-NOPs
> * `nopcode` - The ID of the anti-NOP
> * `enable` - `1` to enable/`0` to disable
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the `nopcode` parameter contains an invalid ID of the anti-NOP

#### EnableAntiNOPForPlayer(playerid, nopcode, enable)
> Use to enable/disable one of the anti-NOPs for a specific player
> * `playerid` - The ID of the player to enable/disable the anti-NOP for
> * `nopcode` - The ID of the anti-NOP
> * `enable` - `1` to enable/`0` to disable
> * Returns `1` if the function executed successfully, `0` if the player is not connected or `-1` if the `nopcode` parameter contains an invalid ID of the anti-NOP

#### IsAntiNOPEnabled(nopcode)
> Use to check whether one of the anti-NOPs is enabled/disabled
> * `nopcode` - The ID of the anti-NOP to check
> * Return `1 (true)` if enabled or `0 (false)` if disabled

#### IsAntiNOPEnabledForPlayer(playerid, nopcode)
> Use to check whether one of the anti-NOPs is enabled/disabled for a specific player
> * `playerid` - The ID of the player to be checked whether the anti-NOP is enabled/disabled for him
> * `nopcode` - The ID of the anti-NOP to check
> * Return `1 (true)` if enabled or `0 (false)` if disabled

Added in v1.9.42:

#### AntiCheatGetVehicleDriver(vehicleid)
> Use to get the ID of the driver of a vehicle
> * `vehicleid` - The ID of the vehicle to get the driver ID of
> * Returns the ID of the driver or `INVALID_PLAYER_ID` if the vehicle does not exist

#### AntiCheatGetVehicleInterior(vehicleid)
> Use to get the ID of the current interior of a vehicle
> * `vehicleid` - The ID of the vehicle to get the interior ID of
> * Returns the ID of the interior or `0` if the vehicle does not exist

#### AntiCheatGetVehiclePaintjob(vehicleid)
> Use to get the ID of the paintjob of a vehicle
> * `vehicleid` - The ID of the vehicle to get the paintjob ID of
> * Returns the ID of the paintjob or `3` if the vehicle does not exist

Added in v1.9.43:

#### AntiCheatGetVehiclePos(vehicleid, &Float:x, &Float:y, &Float:z)
> Use to get the position of a vehicle (according to anticheat data)
> * `vehicleid` - The ID of the vehicle to get the position of
> * `&Float:x` - A variable to store the x coordinate in, passed by reference
> * `&Float:y` - A variable to store the y coordinate in, passed by reference
> * `&Float:z` - A variable to store the z coordinate in, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the vehicle does not exist

#### AntiCheatGetVehicleZAngle(vehicleid, &Float:z_angle)
> Use to get the z rotation of a vehicle (according to anticheat data)
> * `vehicleid` - The ID of the vehicle to get the z rotation of
> * `&Float:z_angle` - A variable to store the z rotation in, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the vehicle does not exist

#### AntiCheatGetVehicleSpawnPos(vehicleid, &Float:x, &Float:y, &Float:z)
> Use to get the spawn position of a vehicle
> * `vehicleid` - The ID of the vehicle to get the spawn position of
> * `&Float:x` - A variable to store the x coordinate in, passed by reference
> * `&Float:y` - A variable to store the y coordinate in, passed by reference
> * `&Float:z` - A variable to store the z coordinate in, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the vehicle does not exist

#### AntiCheatGetVehicleSpawnZAngle(vehicleid, &Float:z_angle)
> Use to get the spawn z rotation of a vehicle
> * `vehicleid` - The ID of the vehicle to get the spawn z rotation of
> * `&Float:z_angle` - A variable to store the z rotation in, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the vehicle does not exist

Added in v1.9.46:

#### AntiCheatGetInterior(playerid)
> Use to get the ID of the interior a player is currently in (according to anticheat data)
> * `playerid` - The ID of the player to get the interior ID of
> * Returns the ID of the interior or `0` if the player is not connected

Added in v1.9.50:

#### AntiCheatGetEnterVehicleSeat(playerid)
> Use to get the seat of the vehicle a player attempted to enter last time
> * `playerid` - The ID of the player to get the last entered seat of
> * Returns the ID of the entered seat or `-1` if the player is not connected

#### AntiCheatGetWeaponInSlot(playerid, slot)
> Use to get the weapon ID in a specific player's weapon slot (according to anticheat data)
> * `playerid` - The ID of the player to get the weapon ID of
> * `slot` - The slot to get the weapon ID for
> * Returns the ID of weapon in a specific slot, `-1` if the player is not connected or `-2` if the slot specified is invalid

#### AntiCheatGetAmmoInSlot(playerid, slot)
> Use to get the ammo in a specific player's weapon slot (according to anticheat data)
> * `playerid` - The ID of the player to get the ammo of
> * `slot` - The slot to get the ammo for
> * Returns the amount of ammo in a specific slot, `-1` if the player is not connected or `-2` if the slot specified is invalid

#### AntiCheatIsInSpectate(playerid)
> Use to check whether a player is in spectator mode or not
> * `playerid` - The ID of the player to check
> * Returns `1 (true)` if it is or `0 (false)` if it is not

#### AntiCheatGetVehicleSpeed(vehicleid)
> Use to get the speed of a vehicle
> * `vehicleid` - The ID of the vehicle to get the speed of
> * Returns the vehicle speed or `0` if the vehicle does not exist

#### AntiCheatIsVehicleSpawned(vehicleid)
> Use to check whether a vehicle is spawned or not
> * `vehicleid` - The ID of the vehicle to check
> * Returns `1 (true)` if it is or `0 (false)` if it is not

Added in v1.9.53:

#### AntiCheatGetPickupPos(pickupid, &Float:x, &Float:y, &Float:z)
> Use to get the position of a pickup
> * `pickupid` - The ID of the pickup to get the position of
> * `&Float:x` - A variable to store the x coordinate in, passed by reference
> * `&Float:y` - A variable to store the y coordinate in, passed by reference
> * `&Float:z` - A variable to store the z coordinate in, passed by reference
> * Returns `1 (true)` if the function executed successfully or `0 (false)` if the pickup does not exist


[Example of setting **OnCheatDetected** in your gamemode](https://github.com/NexiusTailer/Nex-AC/blob/master/CHANGELOG.md)

# Multilingual:
The script can be configured in any of the available languages. To do it, just download the desired localization, save it in a directory with the main include *(nex_ac.inc)* and recompile your script.

* *.lang* files can be opened even in default notepad and easily edited

*Did not find your language? Help the project* :)  
If you know well a language that is not in the "lang" folder, please translate anticheat into this language. To do this, just send the translated .lang file via Pull Request.  
I will be very glad of your help and add you in the list of those who helped the development of the anticheat.

# Installation:
1. Download version of the anticheat which compatible with the version of your server
2. Download the language file *(.lang)* in your preferred language
3. Copy both files to a folder *"/pawno/include"* which is located in a folder with the server
4. In gamemode after *#include <a_samp>* write the following:
```
#define DEBUG
#include <nex-ac_en.lang> //or any other
#include <nex-ac>
```
5. In all filterscripts after *#include <a_samp>* write the following:
```
#include <nex-ac>
```
6. Compile the modified scripts

***Warnings:***
 * Check for using any other anticheats in order to avoid conflicts with them
 * If you use Streamer Plugin by Incognito, Pawn.RakNet, foreach, sscanf, YSF or SKY, include it before nex-ac
 * Also keep in mind that filterscript must have "#define FILTERSCRIPT" before including the anticheat
 

# Thanks:
* f0Re3t, Vitalik_Gonsor, Magic_York, Roberto_York, TheHero, Nike_33, Mix_Rargard, Unisheld - testing
* ZiGGi, Urukhay, Yashas, theYiin, RaefaldhiAmartya, PatchwerkQWER, kvann, rt-2 - advices on the code
* Carper - German translation
* Jstylezzz - Dutch translation
* J4Rr3x, Sasino97 - Italian translation
* Alex Westbrook, JustBored, Frenzoid - Spanish translation
* lashona, ArthourP, DAKYSKYE - Georgian translation
* wampiros6 - Polish translation
* DeitY, Dragony92 - Serbian translation
* NicK_ - Brazilian Portuguese translation
* KyleSmith, infin1tyy - Improved English translation
* M4D - Persian (Farsi) Translation
* Valera_Kovshikov - Ukrainian translation
* RaefaldhiAmartya - Indonesian translation
* vannesenn - Croatian translation
* j3rry, vic1997 - French translation
* zaibaslr2 - Lithuanian translation
* UnforgiveNNN - Romanian translation
* Pedro. - Hungarian translation
* Ben_Lovejoy - Finnish translation
* Rengar - Latvian translation
* bgedition - Bulgarian translation
* Jensenn - Turkish translation
* Sanady - Slovak translation
* Grig - Armenian translation
* SooBad - Czech translation
* OldPawn - Estonian translation
* Negativ_Tm - Turkmen translation
* Trung.Tin - Vietnamese translation
* willbedie - Albanian translation
* aktah - Thai translation
* Michael.Richmond - Moldavian translation
* NemanjaMAX - Bosnian translation
* TTG - simplified Chinese translation
* Abraar - Hindi translation

This script also contains materials from third-party open source projects.
