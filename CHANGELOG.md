**v1.9.63**

Changes:
* Increased the maximum number of warnings for anti-flyhack in vehicle
* Improved compatibility with older versions of Streamer Plugin (down to 2.8.2)
* Improved protection from various bypasses with spectating mode or death
* Tweaked some values in anti-speedhack onfoot

Fixes:
* Fixed issues with some anti-NOPs when exiting AFK
* Fixed several potential bugs in anti-health hack (onfoot/in vehicle) and armour hack
* Fixed a bug with a kick for entering vehicle if it was previously moved as a trailer
* Fixed display of debug message when protection from fake NPC was triggered
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
