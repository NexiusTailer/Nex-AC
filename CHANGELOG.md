**v1.9.62**

Changes:
* Improved check for spoofing by special actions of entering and exiting from a vehicle
* Coordinates for ammu-nations, restaurants and pay'n'sprays are now taken from the game files
* High ping protection no longer ignores players whose ping drops to normal values only occasionally
* Added support for some functions from YSF plugin which were also added to open.mp server
* Streamer_UpdateEx is now hooked by anticheat when called from filterscripts as well
* Minor improvements and fixes

Fixes:
* Fixed a bug with a kick for teleport in some cases when exiting RC vehicles
* Fixed a bug with a parachute kick that could be received when exiting air RC vehicles
* Fixed a bug with a kick when picking up health pickups, when player's health was already above 100
* Fixed a bug with a kick when picking up health, armour and weapon pickups of types 4 and 5
* Fixed false detection in anti-flood with fast entering and exiting from train carriages
* Tweaked anti-rapid fire settings for desert eagle and shotgun
* Fixed several bugs in anti-NOP for special actions

The latest example of setting public OnCheatDetected in your gamemode:

```pawn
forward OnCheatDetected(playerid, ip_address[], type, code);
public OnCheatDetected(playerid, ip_address[], type, code)
{
	if(type) BlockIpAddress(ip_address, 0);
	else
	{
		switch(code)
		{
			case 5, 6, 11, 14, 22, 32: return 1;
			case 40: SendClientMessage(playerid, -1, MAX_CONNECTS_MSG);
			case 41: SendClientMessage(playerid, -1, UNKNOWN_CLIENT_MSG);
			default:
			{
				new strtmp[sizeof KICK_MSG];
				format(strtmp, sizeof strtmp, KICK_MSG, code);
				SendClientMessage(playerid, -1, strtmp);
			}
		}
		AntiCheatKickWithDesync(playerid, code);
	}
	return 1;
}
```
