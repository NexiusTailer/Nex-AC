**v1.9.65**

Changes:
* Minor code optimization in OnPlayerUpdate
* Improved anti-AFK Ghost, now it also detects perfect invisible hack
* Improved validations in several synchronization types (when Pawn.RakNet is used)
* Anti-NOP SpawnPlayer and NOP SetPlayerInterior have been moved to the timer
* Improved anti-teleport for RC vehicles

Fixes:
* Fixed the behavior of one second timer when it was recreated too often
* Fixed a bug with a kick for NOP PutPlayerInVehicle if vehicle was respawned when putting in
* Fixed a bug with a kick for NOP RemovePlayerFromVehicle if player was in RC vehicles
* Fixed several bypasses for anti-speedhack (onfoot) which temporarily allowed high speeds
* Fixed several bypasses for anti-teleport related to PutPlayerInVehicle
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
