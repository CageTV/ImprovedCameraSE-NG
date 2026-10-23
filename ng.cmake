# ImprovedCameraSE.dll on alandtse's CommonLibSSE-NG (Skyrim 1.6.1170 and 1.7.x, SE and AE); included by E:/WorkSpace/ng-build/CMakeLists.txt (see ng_plugin there).
# The Visual Studio project in ImprovedCamera/build/VC17 is the original build (ArranzCNL's CommonLibSSE-NG "flatrim" branch as a submodule, Skyrim 1.5.97 to 1.6.1179).
# Needs the vendor submodules imgui, mINI and glm (git submodule update --init); MinHook comes from vcpkg.
set(_ic "${CMAKE_CURRENT_LIST_DIR}/ImprovedCamera")
file(GLOB_RECURSE _ic_sources RELATIVE "${_ic}" CONFIGURE_DEPENDS "${_ic}/source/*.cpp")
list(APPEND _ic_sources
    PCH/PCH.cpp
    vendor/imgui/imgui.cpp vendor/imgui/imgui_demo.cpp vendor/imgui/imgui_draw.cpp vendor/imgui/imgui_tables.cpp vendor/imgui/imgui_widgets.cpp)
find_package(minhook CONFIG REQUIRED)
ng_plugin(TARGET ImprovedCameraSE NAME ImprovedCameraSE VERSION 1.1.2.4228 AUTHOR "IC Team" ROOT "${_ic}"
    SOURCES ${_ic_sources}
    INCLUDES "${_ic}/include" "${_ic}/PCH" "${_ic}/vendor" "${_ic}/vendor/imgui" "${_ic}/vendor/mINI/src" "${_ic}/vendor/glm"
    PCH "${_ic}/PCH/PCH.h"
    DEFINES ICSE_NG SKSE_SUPPORT_XBYAK=1
    OPTIONS /UUNICODE /U_UNICODE
    LIBS minhook::minhook)
# the vendored imgui sources do not include the precompiled header
set_source_files_properties(
    "${_ic}/vendor/imgui/imgui.cpp" "${_ic}/vendor/imgui/imgui_demo.cpp" "${_ic}/vendor/imgui/imgui_draw.cpp" "${_ic}/vendor/imgui/imgui_tables.cpp" "${_ic}/vendor/imgui/imgui_widgets.cpp"
    TARGET_DIRECTORY ImprovedCameraSE PROPERTIES SKIP_PRECOMPILE_HEADERS ON)
