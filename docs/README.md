# <img align="left" width="150" height="150" src="https://github.com/ArranzCNL/ImprovedCameraSE-NG/blob/main/assets/Artwork/ic_logo2.png"> ImprovedCameraSE-NG

Improved Camera SE is an immersive first person camera modification for [The Elder Scrolls V: Skyrim Special Edition](https://store.steampowered.com/app/489830/The_Elder_Scrolls_V_Skyrim_Special_Edition/).
NG version allows this modification to work across multiple SkyrimSE versions from 1.5.97 to 1.6.1179 thanks to [CommonLibSSE-NG](https://github.com/CharmedBaryon/CommonLibSSE-NG) and [Address Library](https://github.com/meh321/AddressLibraryDatabase).

## Showcase
[![Improved Camera SE](https://img.youtube.com/vi/SGQNoSJBfSk/maxresdefault.jpg)](https://www.youtube.com/watch?v=SGQNoSJBfSk "Improved Camera SE")
Credits: [Capt. Panda](https://www.youtube.com/@CaptPanda)

## End User Requirements
* [Skyrim Script Extender (SKSE)](https://skse.silverlock.org/)
* [Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)

## Build Requirements
* [Visual Studio 2022 IDE - Programming Tool for Software Developers](https://visualstudio.microsoft.com/vs/)
  * Desktop development with C++
    * MSVC v143 - VS 2022 C++ x64/x86 build tools (Latest)
	* Windows 10 SDK (10.0.20348.0)

Main solution can be found inside of build/VC17/ImprovedCameraSE_VS2022.sln.

## License
* The Improved Camera SE source files are under the Mozilla Public License 2.0 (`LICENSE-MPL-2.0.txt`).
* The ng build links [alandtse's CommonLibSSE-NG](https://github.com/alandtse/CommonLibSSE-NG) (GPL-3.0 with a modding exception), so the compiled `ImprovedCameraSE.dll` is distributed under the GNU General Public License v3.0 or later (full text in `LICENSE` in the repository root and in `docs/LICENSE-GPL-3.0.txt` next to this file; `LICENSE.txt` in the download). MPL-2.0 section 3.3 allows this. See `NOTICE.txt` for the copyright statement and GPL notice.

Copyright (c) the Improved Camera SE authors (see `AUTHORS.md`) and CageTV, for the 1.7.x changes.

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

## Credits
* LogicDragon for [Enhanced Camera](https://www.nexusmods.com/skyrim/mods/57859/).
* inmundano for the bulk reverse engineering work that went into Improved Camera SE.
* [Ian Patterson](https://github.com/ianpatt/skse64) and developers for SKSE64.
* [Ryan-rsm-Mckenzie](https://github.com/Ryan-rsm-McKenzie/CommonLibSSE) CommonLibSSE original version, [powerof3](https://github.com/powerof3/CommonLibSSE) CommonLibSSE community version, [CharmedBaryon](https://github.com/CharmedBaryon/CommonLibSSE-NG) CommonLibSSE nextgen version and various other contributors to the CommonLibSSE libraries.
* [meh321](https://github.com/meh321) for address library.
