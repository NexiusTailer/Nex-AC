**v1.9.61**

Changes:
* Optimized protection against fake NPCs with YSF plugin included
* Improved some checks if surfing on per-player objects (when YSF is used)
* Improved quaternion validation in trailer sync (when Pawn.RakNet is used)
* Adjusted certain speed limits in anti-speedhack onfoot
* Removed version mismatch warning for open.mp server

Fixes:
* Tweaked validation checks for unoccupied sync parameters
* Fixed a bug with a parachute kick that could be received by the player with a slight delay
* Fixed incorrect behavior of trailers on older server versions (when Pawn.RakNet is used)
* Fixed a bug with zeroing of vehicle entering flag in some cases
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
