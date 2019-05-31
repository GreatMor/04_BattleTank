# 04_BattleTank
An open world head-to-head tank fight with simple AI, terrain, and advanced control system Unreal 4.
* BT02 Setting Up a GitHub "repo_bt"

* function principle
bool isReloaded = (FPlatformTime::Seconds() - LastFierTime) > RelodingTimeInSeconds;
/*FPlatformTime::Seconds() - LastFierTime) > RelodingTimeInSeconds;
	0  - 0 > 3 np
	1 - 0 > 3 no
	2 - 0 > 3 no 
	3 - 0 > 3 no 
	4 - 0 > 3 yes
	Projectile->LaunchProjectile(LaunchSpeed);// выстреливаем снаряд со скоростью
	LastFierTime = FPlatformTime::Seconds(); 
	 LastFierTime = 4
	4-4>3 no
	5-4>3 no
	6-4>3 no
	7-4>3 no
	8-4>3 yes 
	Projectile->LaunchProjectile(LaunchSpeed);// выстреливаем снаряд со скоростью
	LastFierTime = FPlatformTime::Seconds();
	 LastFierTime = 8

	*/