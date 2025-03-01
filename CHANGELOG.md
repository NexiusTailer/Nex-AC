**v1.9.66**

Changes:
* Expanded the list of callbacks that consider NPCs
* Added pre-hooks support for higher priority of ALS hooks by the anticheat
* Improved checks that determine the moment of dropping jetpack for its re-pickup
* Improved validations in aim synchronization (when Pawn.RakNet is used)

Fixes:
* Fixed a bug in anti-CJ run when it stopped detecting in some cases
* Fixed a bug with a kick for flyhack (onfoot) with driver's animation after leaving boats
* Fixed anti-GivePlayerWeapon NOP when giving ammo in the amount of 0 or more than 32767
* Fixed a bug with array index out of bounds when reading incorrect .cfg files
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
