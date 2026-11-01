/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once
#include <cmath>
#include <string_view>
namespace ImprovedCamera::CombatPolicy {
    constexpr bool EnabledFromProfile(std::string_view value) noexcept { return value == "1"; }
    constexpr bool Active(bool enabled, bool realFirstPerson, bool normalState, bool weaponOut) noexcept
    { return enabled && realFirstPerson && normalState && weaponOut; }
    constexpr bool WeaponOut(unsigned state) noexcept { return state >= 1 && state <= 5; }
    inline bool Close(float a, float b) noexcept { return std::fabs(a - b) <= 0.00001f; }
    template<class Point> bool SamePosition(const Point& a, const Point& b) noexcept
    { return Close(a.x,b.x) && Close(a.y,b.y) && Close(a.z,b.z); }
    template<class Point> bool RestorePosition(const Point& before, const Point& after, const Point& current) noexcept
    { return !SamePosition(before,after) && SamePosition(after,current); }
    inline bool RestoreScale(float before, float after, float current) noexcept
    { return !Close(before,after) && Close(after,current); }
}
