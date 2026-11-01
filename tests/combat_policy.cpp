/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "utils/CombatPolicy.h"
#include <cassert>
#include <iostream>
using namespace ImprovedCamera::CombatPolicy;
struct Point {float x,y,z;};
int main(){
 assert(!EnabledFromProfile(""));assert(!EnabledFromProfile("0"));assert(EnabledFromProfile("1"));assert(!EnabledFromProfile("bad"));
 for(int e=0;e<2;++e)for(int f=0;f<2;++f)for(int n=0;n<2;++n){
  assert(Active(e,f,n,true)==bool(e&&f&&n));
  assert(!Active(e,f,n,false));
 }
 assert(!WeaponOut(0)); for(unsigned state=1;state<=5;++state) assert(WeaponOut(state)); assert(!WeaponOut(6));
 Point before{0,0,0}, ours{0,-18,0}, changed{2,-18,0};
 assert(RestorePosition(before,ours,ours));
 assert(!RestorePosition(before,ours,before));
 assert(!RestorePosition(before,ours,changed));
 assert(!RestorePosition(before,before,before));
 assert(RestoreScale(1,.001f,.001f));assert(!RestoreScale(1,.001f,.9f));assert(!RestoreScale(1,.001f,1));
 std::cout<<"PASS: optional profile value, combat gating, own-edit restoration and external-edit preservation\n";
}
