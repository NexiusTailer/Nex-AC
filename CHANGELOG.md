v1.9.58

Changes:
* Improved protections from SpeedHack onfoot and CarShot from the passenger seat
* Added protection from visual damage spoofing for other player's and unoccupied vehicles

Fixes:
* Fixed a bug in anti-fake spawn when a series of spawns would only trigger checks on the first instance
* Fixed a bypass in anti-dialog crasher when some forbidden characters were combined with each other
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