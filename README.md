# Nex-AC - Anticheat system
(http://forum.sa-mp.com/showthread.php?t=579963)

Nex Anticheat (Nex-AC) - is a comprehensive protection which combines powerful anti-cheat and protection against various attacks (flood, DoS).

Anti-cheat detects popular cheats instantly punishing cheaters.

Anti-DoS combines customizable anti-flood, anti-DoS at the network level and a lot of protection tools against hacking, crashers etc.

#List of basic anti-cheats:
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
* Anti-flood callback functions (complete list below)
* Anti-crashers (complete list below)
* Anti-NOP's (complete list below)
* Anti-Dos

#Additional features:
* Setting anti-cheat from file
The settings is located in a separate file (scriptfiles\nex-ac_settings.cfg)
* View Statistics
Ability to view statistics of the anti-cheat while the server working since its launch
Displayed automatically when server turn off. Stored in a server log (server_log.txt)
* Logging the most important actions
Optionally you can enable debug-mode for log all actions
* Multilingual
Ability to set any of the available languages.
It also simplifies the translation of anti-cheat to other languages

#List of publics which are protected by anti-flood:
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

#Anti-NOP's:
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
* SetPlayerDrunkLevel
* SetPlayerArmedWeapon
* SetPlayerSpecialAction
* TogglePlayerSpectating
* RemovePlayerFromVehicle

#Anti-Crashers:
* Invalid tuning
* Invalid vehicle seat
* Illegal characters in the dialogues (deleting)
* Invalid attached objects
* Weapon Crasher

#Functions:
public OnCheatDetected(playerid, ip_address[], type, code)

  Called when the tripped one of the anti-cheats
  * playerid - ID of the cheater
  * ip_address[] - IP-address of the cheater
  * type - Type of offense (when 0 returns the ID, when 1 - IP)
  * code - Code (ID) of the anti-cheat


EnableAntiCheat(acid, enable)

  Use to enable/disable one of the anti-cheats
  * acid - ID of the anti-cheat
  * enable - 1 to enable/0 to disable


EnableAntiCheatForPlayer(playerid, acid, enable)

  Use to enable/disable one of the anti-cheats for a particular player
  * playerid - ID of the player who needs enable/disable the anti-cheat
  * acid - ID of the anti-cheat
  * enable - 1 to enable/0 to disable



Added in v1.3:


IsAntiCheatEnabled(acid)

 Use to check enable/disable one of the anti-cheats
* acid - ID of the anti-cheat
* Return 1 (true) if enabled or 0 (false) if disabled


IsAntiCheatEnabledForPlayer(acid, playerid)

 Use to check enable/disable one of the anti-cheats for a particular player
* acid - ID of the anti-cheat
* playerid - ID of the player who needs for check enable/disable the anti-cheat
* Return 1 (true) if enabled or 0 (false) if disabled

#Multilingual:
The script can be configured at any of the available languages. To do this, just download the link the desired localization, save it in a directory with the main include (nex_ac.inc) and recompile your script.

#Installation:
1. Download version of the anticheat which compatible with the version of your server
2. Download the language file (.lang) on your preferred language
3. Copy both files to the folder "/pawno/include" which is located in the folder with the server
4. In gamemode and all filterscripts after "#include <a_samp>" write the following: "#include <nex-ac>"
 Warning! If you are using a Streamer Plugin by Incognito, include it before nex-ac!
5. Compile the modified scripts

#Bugs:
Currently they were not detected. If you find a bug, please write about it in this thread.

#Thanks:
* Magic_York, Roberto_York, TheHero, Nike_33, Mix_Rargard, Unisheld - testing
* ZiGGi, Urukhay, Yashas, theYiin - advice on the code
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

This script also contains materials of third-party projects with open source.

P.s. I develop this anticheat about a year and spent on it a lot of effort and time. I very much hope that it will be useful to you.

Enjoy!
