v1.9.59

Changes:
* Improved protection from invalid attached objects
* Improved protection from invalid damage (now there are checks for actors as well)
* Added blocking of invalid shots, which were previously logged by built-in server checks (when Pawn.RakNet is used)
* Improved anti-trailer teleport (when Pawn.RakNet is used)

Fixes:
* Fixed an issue with SetVehicleParamsForPlayer when the closed doors status of vehicles wasn't considered
* Fixed possible runtime errors when OnPlayerSelectedMenuRow and OnPlayerExitedMenu could handle not fully connected player
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
