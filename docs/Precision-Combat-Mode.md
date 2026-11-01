# Precision Combat Mode

An optional Improved Camera compatibility mode for Precision. The implementation lives in Improved Camera; it does not modify Precision, forward first-person arms as incoming collision geometry, or create a second visual actor.

## Enable

Open **Left Shift + Home → General → Precision Combat Mode** and save the selected profile with **File → Save Profile** (Ctrl+S). Alternatively, add this to the selected Improved Camera profile:

```ini
[GENERAL]
bPrecisionCombatMode=1
```

The setting defaults to off when absent, preserving existing profile behavior. Set it to 0 or disable the checkbox to restore normal Improved Camera behavior. The new field and menu item are appended to preserve existing indices/field offsets.

## Behavior

- During normal first person, keep the engine camera baseline both sheathed and drawn. This avoids the height step between idle, combat and the vanilla Tab tween; native crouching and movement remain available. IC head/eye camera offsets are intentionally bypassed in this mode.
- Hide the rendered third-person body from the start of drawing through completion of sheathing, including fists and spells. Keep native first-person arms and skip IC body translation, arm scaling and third-person weapon copying while drawn. Enemy proximity/combat flags alone do not keep the body hidden after sheathing.
- Keep the body hidden across the internal first-person state reset and reveal it only after normal IC body transforms have been rebuilt, preventing transition flashes.
- Track local translation/scale edits and restore only unchanged owned edits before the next native first-person update. Strong node references guard reload lifetimes. This leaves newer engine/other-mod edits intact.
- Track owned camera translation changes and restore them before the native camera update, preventing additive offsets on repeated camera/save/screenshot updates.
- While IC FOV override is enabled, synchronize the active world FOV with vanilla's reset source and retain it through the Tab tween. Disabling override restores the previous reset setting only if it is still owned. Map/dialogue/special menu projection is left under menu control. First Person and First Person Combat FOV remain separate sliders.

Mounts, transformations, killmoves, death, scripted cameras and disabling the new option retain their existing camera paths. The save-offset/FOV maintenance fixes also apply outside the new combat toggle where appropriate.

Precision uses third-person skeleton data for incoming collision clones. This mode removes IC's combat pose alterations and hides the render body; it does not replace incoming collision with a nonexistent full first-person skeleton. Exact equivalence to unmodified vanilla collision has not been instrumented or proven.

## Hook constraint

The 1.7.104 smooth-transition replacement site at relocation 41996 + 0x303 contains `FF 90 88 03 00 00` (`call [rax+0x388]`). The branch helper's returned relative target is not a callable original function for this virtual instruction. The new branch returns the native first-person policy (`false`) directly and must not call the stored `func` target. Calling the derived interior address skips a function prologue and can cause an unaligned `movaps` crash.

## Validation

Built as a Windows x64 Release DLL using MSVC 19.44, Windows SDK 10.0.26100 and alandtse/CommonLibSSE-NG 15.4.0 (`adebc31dcfa65077594526e36373bbc4d8a474b4`). The locally tested DLL advertises Address Library v5 and only runtime 1.7.104; this contribution does not add build-toolchain or runtime-port changes to upstream.

The contributor reports successful in-game testing on Skyrim 1.7.104 with Precision 2.0.6 and Blade and Blunt: startup, incoming combat, draw/sheath visibility, body restoration with enemies nearby, quicksave, Tab/FOV transitions, and the final consistent-height adjustment. This is one user's integration test, not a cross-runtime or exhaustive compatibility certification.

Portable policy regression checks (run from repository root):

```sh
c++ -std=c++17 -UNDEBUG -I ImprovedCamera/include tests/combat_policy.cpp -o combat_policy_test
./combat_policy_test
```

On MSVC, the same test was built with `/UNDEBUG` and passed via CTest. It exercises profile defaults, weapon-state coverage, and own-edit restoration/external-edit preservation. It cannot verify rendering or collision behavior. PE exports, runtime metadata and imported dependencies were also inspected on the tested build.

For additional review, compare the toggle on/off with Precision collision debug enabled; test draw/sheath, fists/spells, idle/crouch, Tab/map/dialogue, quicksave, equipment reloads, first/third-person transitions and special camera events. Test other supported runtimes independently before claiming support there.
