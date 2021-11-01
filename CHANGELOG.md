v1.9.57

Changes:
* Improved anti-dialog crasher (expanded list of forbidden characters in inputtext)
* Validation of unoccupied sync parameters has been improved and optimized (when Pawn.RakNet is used)

Fixes:
* Fixed a bug where some variables would not reset when the player exited spectating mode
* Fixed possible errors when using Pawn.RakNet handlers if their names matched
* Fixed some packet ID's for old server versions (when Pawn.RakNet is used)
* Minor fixes and improvements

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