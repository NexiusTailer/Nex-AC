**v1.9.68**

Changes:
* Improved validation checks within protections from AFK Ghost and Pro Aim
* Changed the punishment for negative damage in related callbacks (damage block instead of kick)
* Improved stability when getting incorrect return values ​​from various natives
* Minor improvements and fixes

Fixes:
* Fixed a bug with parameters for hooked callbacks in y_prehook integration
* Fixed behavior of anti-NOPs when setting health while being in spectator mode
* Fixed some false detections of anti-GodMode onfoot and in vehicle

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
