#pragma once

#include <iostream>

static std::string DefaultConfigString = 
"# If any settings will not be found default parameter value will be used\n"
"#\n"
"# Single keys MUST be written in Caps\n"
"# Available keys to set you can get there\n"
"# https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php\n"
"# For mouse buttons look here\n"
"# https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Mouse.php\n"
"# UpArrow, DownArrow etc can be written like so\n"
"\n"
"[Keys]\n"
"Keys: Z,X\n"
"\n"
"[Mouse]\n"
"Buttons: No\n"
"\n"
"[Statistics]\n"
"Statistics font: Default\n"
"Key counters font: Default\n"
"Statistics text color: 255,255,255\n"
"Key counters text color: 0,0,0\n"
"Statistics character size: 12\n"
"Key counters character size: 22\n"
"Show statistics: true\n"
"Show BPM: true\n"
"Only show set keys: false\n"
"Show key counters: true\n"
"\n"
"[Spacing]\n"
"# Distance from the borders and between the keys\n"
"Button distance: 7\n"
"Space between buttons and statistics: 10\n"
"Space on the statistics right: 0\n"
"\n"
"[Buttons Graphic]\n"
"Button texture: Default\n"
"Animation texture: Default\n"
"Button texture size: 50,50\n"
"Button texture color: 255,255,255,255\n"
"Animation velocity: 7\n"
"Animation scale on click: 1\n"
"Animation color: 255,255,255,255\n"
"\n"
"[Background]\n"
"Background texture: Default\n"
"Background color: 44,28,31,180\n"
"\n"
"[Other]\n"
"Changeability alert color: 255,0,0\n"
"Highlighted text button color: 255,0,0\n";