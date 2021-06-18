v1.9.56

Changes:
* Improved protection from fake NPCs without connecting YSF plugin
* Improved validation of unoccupied sync parameters (using Pawn.RakNet)
* Improved performance of the Pawn.RakNet dependent code
* Corrected some anti-flood settings
* Minor improvements and fixes

Fixes:
* Fixed anti-NOP SpawnPlayer in spectator mode
* Fixed a bug with updating the previous values ​​of health and armour when entering vehicles
* Fixed bypassing anti-speedhack onfoot and in vehicle when the player was given speed by the server
* Fixed triggering of anti-CarShot from passenger seat with a sharp decrease in speeds
* Fixed anti-pickups teleport for streamer pickups

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