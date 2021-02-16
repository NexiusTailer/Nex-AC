v1.9.55

Changes:
* Improved compatibility with weapon-config
* Improved anti-carshot from passenger seat
* Improved some invalid data checks in different syncs (using Pawn.RakNet)
* Improved protection from invisibility sending invalid camera mode with a detonator in hand (using Pawn.RakNet)
* Removed GetPlayerSyncWeapon function (when connecting YSF) due to its instability
* Changed default punishment for anti-CarJack
* Changed speed limits for some anticheats

Fixes:
* Fixed a bug when some variables were not reset after spawn
* Fixed a bug in anti-teleport hack with a kick entering a vehicle when it's being teleported by anticheat
* Fixed detections of anti-flood by vehicle parts when colliding with something with strobe lights on
* Minor fixes and improvements

There is full support for sampctl now (no more problems with the location of default .lang files)

The latest example of setting public OnCheatDetected in your gamemode:
```
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