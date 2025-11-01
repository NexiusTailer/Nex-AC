**v1.9.67**

Changes:
* Improved protection from invalid tuning (paintjob) on open.mp server
* Considered a few cases of CJ animation appearing on other skins for anti-CJ run
* NOP numbering in OnNOPWarning now matches EnableAntiNOP(ForPlayer)
* Minor improvements and fixes

Fixes:
* Fixed a bug in OnPlayerConnect that prevented NPCs from joining in some cases
* Fixed a bug in anti-NOP RemovePlayerFromVehicle with a kick while being in trains
* Fixed anti-NOP triggering for special actions during a long fall
* Fixed anti-health hack behavior when setting float inf values

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
