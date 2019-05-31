# 04_BattleTank
An open world head-to-head tank fight with simple AI, terrain, and advanced control system Unreal 4.
* BT02 Setting Up a GitHub "repo_bt"

* function principle<br/>
bool isReloaded = (FPlatformTime::Seconds() - LastFierTime) > RelodingTimeInSeconds;<br/>
FPlatformTime::Seconds() - LastFierTime) > RelodingTimeInSeconds;<br/>
	0  - 0 > 3 no<br/>
	1 - 0 > 3 no<br/>
	2 - 0 > 3 no <br/>
	3 - 0 > 3 no <br/>
	4 - 0 > 3 yes<br/>
	Projectile->LaunchProjectile(LaunchSpeed);// выстреливаем снаряд со скоростью<br/>
	LastFierTime = FPlatformTime::Seconds(); <br/>
	 LastFierTime = 4<br/>
	4-4>3 no<br/>
	5-4>3 no<br/>
	6-4>3 no<br/>
	7-4>3 no<br/>
	8-4>3 yes <br/>
	Projectile->LaunchProjectile(LaunchSpeed);// выстреливаем снаряд со скоростью<br/>
	LastFierTime = FPlatformTime::Seconds();<br/>
	 LastFierTime = 8<br/>
