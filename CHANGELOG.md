**v1.9.70**

Changes:
* Added optional parameters to a few natives when using omp-stdlib
* Parameters in callbacks are now validated even if anti-crashers are disabled
* Improved PlayerSpectate(Player/Vehicle) handling on open.mp server
* Minor improvements and corrections

Fixes:
* Fixed a bug that caused kick for GodMode when hitting passengers in vehicle
* Fixed protection categories in statistics calculation (when AC_USE_STATISTICS is enabled)
* Fixed delay behavior when giving weapons across multiple slots simultaneously
* Fixed a bug that caused kick for brass knuckles after resetting and re-giving weapons

The latest example of setting public OnCheatDetected in your gamemode:

```pawn
forward OnCheatDetected(playerid, const ip_address[], type, code);
public OnCheatDetected(playerid, const ip_address[], type, code)
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
