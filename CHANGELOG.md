**v1.9.64**

Changes:
* Improved protection from invalid attached objects
* Optimized protection from sandboxie and fake NPCs (comparing IPs as integers)
* Several improvements for anti-trailer teleport (when Pawn.RakNet is used)
* Added support for console variable names from open.mp server
* Reduced code duplication inside native function hooks

Fixes:
* Fixed several anti-teleport bypasses related to PutPlayerInVehicle
* Fixed a bug with a kick in vehicle if it was teleported by others during its entering
* Fixed a bug with a kick exiting vehicle if the player was previously teleported in AFK
* Tweaked validation checks for unoccupied sync parameters
* Minor fixes and improvements

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
