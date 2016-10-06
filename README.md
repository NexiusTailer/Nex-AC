# [Nex-AC - Anticheat system](http://forum.sa-mp.com/showthread.php?t=579963)

Nex Anticheat (Nex-AC) - is a comprehensive protection which combines powerful anti-cheat and protection against various attacks (flood, DoS).  
Anti-cheat detects popular cheats instantly punishing cheaters.  
Anti-DoS combines customizable anti-flood, anti-DoS at the network level and a lot of protection tools against hacking, crashers etc.

##List of basic anti-cheats:
* Anti-AirBreak (onfoot/in vehicle)
* Anti-teleport hack (onfoot/into/in/between vehicles)
* Anti-teleport pickups
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
* Protection from the sandbox
* Protection against invalid version
* Anti-flood change seat
* Flood protection connects to one slot
* Anti-Rcon hack (brute/brute-forse)
* Anti-flood callback functions *(complete list below)*
* Anti-crashers *(complete list below)*
* Anti-NOP's *(complete list below)*
* Anti-Dos

#Additional features:
##### * Setting anti-cheat from file
The settings is located in a separate file (scriptfiles\nex-ac_settings.cfg)
##### * View Statistics
Ability to view statistics of the anti-cheat while the server working since its launch  
Displayed automatically when server turn off. Stored in a server log (server_log.txt)
##### * Logging the most important actions
Optionally you can enable debug-mode for log all actions
##### * Multilingual
Ability to set any of the available languages.  
It also simplifies the translation of anti-cheat to other languages

##List of publics which are protected by anti-flood:
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

##Anti-NOP's:
* SpawnPlayer
* SetPlayerPos
* SetVehiclePos
* SetPlayerAmmo
* SetPlayerHealth
* SetPlayerArmour
* SetVehicleHealth
* GivePlayerWeapon
* SetPlayerInterior
* PutPlayerInVehicle
* ResetPlayerWeapons
* SetPlayerArmedWeapon
* SetPlayerSpecialAction
* TogglePlayerSpectating
* RemovePlayerFromVehicle

##Anti-Crashers:
* Invalid tuning
* Invalid vehicle seat
* Illegal characters in the dialogues (deleting)
* Invalid attached objects
* Weapon Crasher

#Functions:
#### public OnCheatDetected(playerid, ip_address[], type, code)

>  Called when the tripped one of the anti-cheats
>  * `playerid` - ID of the cheater
>  * `ip_address[]` - IP-address of the cheater
>  * `type` - Type of offense (when `0` returns the ID, when `1` - IP)
>  * `code` - Code (ID) of the anti-cheat


#### EnableAntiCheat(acid, enable)

>  Use to enable/disable one of the anti-cheats
>  * `acid` - ID of the anti-cheat
>  * `enable` - `1` to enable/`0` to disable


#### EnableAntiCheatForPlayer(playerid, acid, enable)

>  Use to enable/disable one of the anti-cheats for a particular player
>  * `playerid` - ID of the player who needs enable/disable the anti-cheat
>  * `acid` - ID of the anti-cheat
>  * `enable` - `1` to enable/`0` to disable



Added in v1.3:


#### IsAntiCheatEnabled(acid)

> Use to check enable/disable one of the anti-cheats
>  * `acid` - ID of the anti-cheat
>  * Return `1 (true)` if enabled or `0 (false)` if disabled


#### IsAntiCheatEnabledForPlayer(acid, playerid)

> Use to check enable/disable one of the anti-cheats for a particular player
>  * `acid` - ID of the anti-cheat
>  * `playerid` - ID of the player who needs for check enable/disable the anti-cheat
>  * Return `1 (true)` if enabled or `0 (false)` if disabled



Added in v1.8.8:


#### AntiCheatGetHealth(playerid, &Float:health)

> Use to get the amount of the player's health
> * `playerid` - The ID of the player
> * `&Float:health` - Variable for storage health, passed by reference


#### AntiCheatGetArmour(playerid, &Float:armour)

> Use to get the amount of the player's armour
> * `playerid` - The ID of the player
> * `&Float:armour` - Variable for storage armour, passed by reference


#### AntiCheatGetVehicleHealth(vehicleid, &Float:health)

> Use to get the amount of the vehicle health
> * `vehicleid` - The ID of the vehicle
> * `&Float:health` - Variable for storage health, passed by reference


#### AntiCheatGetWeaponData(playerid, slot, &weapons, &ammo)

> Use to get weapons and ammo in a certain slot of the player
> * `playerid` - The ID of the player
> * `slot` - The slot in which need get the weapons and ammo
> * `&weapons` - Variable for storage weapon ID, passed by reference
> * `&ammo` - Variable for storage amount of ammo, passed by reference


#### AntiCheatGetSpawnWeapon(playerid, &weapon1, &weapon1_ammo, &weapon2, &weapon2_ammo, &weapon3, &weapon3_ammo)

> Use to get spawn weapons and ammo of the player
> * `playerid` - The ID of the player
> * `&weapon1` - Variable for storage the weapon 1, passed by reference
> * `&weapon1_ammo` - The variable for storage the amount of ammo for the weapon 1, passed by reference
> * `&weapon2` - Variable for storage the weapon 2, passed by reference
> * `&weapon2_ammo` - The variable for storage the amount of ammo for the weapon 2, passed by reference
> * `&weapon3` - Variable for storage the weapon 3, passed by reference
> * `&weapon3_ammo` - The variable for storage the amount of ammo for the weapon 3, passed by reference


#### AntiCheatGetPos(playerid, &Float:x, &Float:y, &Float:z)

> Use to get the player's position
> * `playerid` - The ID of the player
> * `&Float:x` - The variable for storage the x coordinate, passed by reference
> * `&Float:y` - The variable for storage the y coordinate, passed by reference
> * `&Float:z` - The variable for storage the z coordinate, passed by reference


#### AntiCheatGetSpeed(playerid, &Float:speed)

> Use to get the player's speed
> * `playerid` - The ID of the player
> * `&Float:speed` - Variable for storage the speed, passed by reference


#### AntiCheatGetVehicleVelocity(vehicleid, &Float:x, &Float:y, &Float:z)

> Use to get the vehicle speed
> * `vehicleid` - The ID of the vehicle
> * `&Float:x` - The variable for storage the x speed, passed by reference
> * `&Float:y` - The variable for storage the y speed, passed by reference
> * `&Float:z` - The variable for storage the z speed, passed by reference


#### AntiCheatGetAnimationIndex(playerid)

> Use to get the index (ID) of the player's current animation
> * `playerid` - The ID of the player
> * Returns the ID of the animation or `0` if the player is not connected


#### AntiCheatGetDialog(playerid)

> Use to get the ID of the opened dialog of the player
> * `playerid` - The ID of the player
> * Returns the ID of the dialog or `0` if the player is not connected


#### AntiCheatGetMoney(playerid)

> Use to get the amount of the player money
> * `playerid` - The ID of the player
> * Returns the amount of money or `0` if the player is not connected


#### AntiCheatGetClass(playerid)

> Use to get ID of the class of the player
> * `playerid` - The ID of the player
> * Returns the class ID or `0` if the player is not connected


#### AntiCheatGetEnterVehicle(playerid)

> Use to get the ID of the vehicle, which player try to enter
> * `playerid` - The ID of the player
> * Returns the ID of the vehicle or `0` if the player is not connected


#### AntiCheatGetVehicleID(playerid)

> Use to get the ID of the vehicle, in which sits the player
> * `playerid` - The ID of the player
> * Returns the ID of the vehicle or `0` if the player is not connected


#### AntiCheatGetWeapon(playerid)

> Use to get the player's current weapon ID
> * `playerid` - The ID of the player
> * Returns the ID of weapon or `0` if the player is not connected


#### AntiCheatGetVehicleSeat(playerid)

> Use to get the seat in the vehicle, on which sits the player
> * `playerid` - The ID of the player
> * Returns the number of the seat or `0` if the player is not connected


#### AntiCheatGetSpecialAction(playerid)

> Use to get the ID of the special action of the player
> * `playerid` - The ID of the player
> * Returns the ID of the special action or `0` if the player is not connected


#### AntiCheatGetLastSpecialAction(playerid)

> Use to get the ID of the previous special action of the player
> * `playerid` - The ID of the player
> * Returns the ID of the previous special action or `0` if the player is not connected


#### AntiCheatGetLastShotWeapon(playerid)

> Use to get the ID of the last weapon from which the player shot
> * `playerid` - The ID of the player
> * Returns the ID of the last weapon or `0` if the player is not connected


#### AntiCheatGetLastPickup(playerid)

> Use to get the ID of the last pickup, which player pick
> * `playerid` - The ID of the player
> * Returns the ID of the last picked up pickup or `0` if the player is not connected


#### AntiCheatGetLastUpdateTime(playerid)

> Use to get the player's last update timestamp
> * `playerid` - The ID of the player
> * Returns the timestamp of the last update or `0` if the player is not connected


#### AntiCheatGetLastReloadTime(playerid)

> Use to get the player's last (weapon) reload timestamp
> * `playerid` - The ID of the player
> * Returns the timestamp of the last reload or `0` if the player is not connected


#### AntiCheatGetLastEnteredVehTime(playerid)

> Use to get the player's last entering vehicle attempt timestamp
> * `playerid` - The ID of the player
> * Returns timestamp of the last entering attempt or `0` if the player is not connected


#### AntiCheatGetLastShotTime(playerid)

> Use to get the player's last shot timestamp
> * `playerid` - The ID of the player
> * Returns the timestamp of the last shot or `0` if the player is not connected


#### AntiCheatGetLastSpawnTime(playerid)

> Use to get the player's last spawn timestamp
> * `playerid` - The ID of the player
> * Returns timestamp of the last spawn or `0` if the player is not connected


#### AntiCheatIntEnterExitsIsEnabled(playerid)

> Use to check enable/disable enter/exit markers in interiors for the player
> * `playerid` - The ID of the player
> * Returns `1 (true)` if enabled or `0 (false)` if disabled


#### AntiCheatStuntBonusIsEnabled(playerid)

> Use to check enable/disable stunt bonus for player
> * `playerid` - The ID of the player
> * Returns `1 (true)` if enabled or `0 (false)` if disabled


#### AntiCheatIsInModShop(playerid)

> Use to check: whether the player is in ModShop or not
> * `playerid` - The ID of the player
> * Returns `1 (true)` if it is or `0 (false)` if it is not


#### AntiCheatIsFrozen(playerid)

> Use to check: whether the player is frozen or not
> * `playerid` - The ID of the player
> * Returns `1 (true)` if frozen or `0 (false)` if not frozen


#### AntiCheatIsDead(playerid)

> Use to check: whether the player is dead or not
> * `playerid` - The ID of the player
> * Returns `1 (true)` if dead or `0 (false)` if not dead


#### AntiCheatIsConnected(playerid)

> Use to check: whether the player is on a server or not
> * `playerid` - The ID of the player
> * Returns `1 (true)` if it is or `0 (false)` if it is not

#Multilingual:
The script can be configured at any of the available languages. To do this, just download the link the desired localization, save it in a directory with the main include *(nex_ac.inc)* and recompile your script.

#####*It is also recommended to check on used any other anti-cheats in order to avoid conflicts with them.*

#Installation:
1. Download version of the anticheat which compatible with the version of your server
2. Download the language file *(.lang)* on your preferred language
3. Copy both files to the folder *"/pawno/include"* which is located in the folder with the server
4. In gamemode and all filterscripts after *#include "a_samp"* write the following: *#include "nex-ac"*  
*Warning! If you are using a Streamer Plugin by Incognito, foreach or y_hooks, include it before nex-ac!*  
*Also keep in mind that filterscript must have "#define FILTERSCRIPT" before including anticheat*
5. Compile the modified scripts

*You gets an error when you compiling this anticheat with YSI? Check out [some tips](http://forum.sa-mp.com/showpost.php?p=3556462&postcount=202)*

#Bugs:
Currently they were not detected. If you find a bug, please let me know about it.

##Thanks:
* Magic_York, Roberto_York, TheHero, Nike_33, Vitalik_Gonsor, Mix_Rargard, Unisheld - testing
* ZiGGi, Urukhay, Yashas, theYiin, RaefaldhiAmartya, PatchwerkQWER, kvann - advices on the code
* Carper - German translation
* Jstylezzz - Dutch translation
* J4Rr3x - Italian translation
* Alex Westbrook, JustBored - Spanish translation
* lashona - Georgian translation
* wampiros6 - Polish translation
* DeitY, Dragony92 - Serbian translation
* NicK_ - PT/BR translation
* KyleSmith - Improve English translation
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

This script also contains materials of third-party projects with open source.

P.s. I develop this anticheat about a year and spent on it a lot of effort and time. I very much hope that it will be useful to you.

Enjoy!
