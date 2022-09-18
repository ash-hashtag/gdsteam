# GDsteam

A GDExtension to use GodotSteam without compiling Godot for Godot 4 and latest

### How to Use
download the compiled binaries and just place them in the res://addons folder before opening godot
that means open godot to initialize project and close it, then place this "gdsteam" folder

currently compiled version are for windows 64 bit only, but you can compile them on your own, if you know how to work with scons, I don't :)

### Compiling
just make sure you link steam_api correctly, and after compiling place the steam_api dll file beside the compiled output
run 'scons' for default debug build
run 'scons target=release' for release build
NOTE: current SConstruct is written only for windows
your output should be in output/gdsteam
copy the gdsteam folder to the project's res://addons/
start godot, hopefully should work

For Other OS
modify SConstruct as you need


### Documentation
you can follow exactly godotsteam documentation, this is just a wrapper for it.
