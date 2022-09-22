# GDsteam

A GDExtension to use GodotSteam without compiling Godot for Godot 4 and latest

### How to Use
download the compiled [binaries](https://github.com/ash-hashtag/gdsteam/releases/tag/0.0.2), extract them and just place the gdsteam folder in the res://addons folder before opening godot
that means open godot to initialize project and close it, then place this "gdsteam" folder
it should automatically work on start

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
https://gramps.github.io/GodotSteam/

### Feel to Contribute

### Some weird things you may notice
#### IPAddress Class
I couldn't find ipaddress class within gdextension files, maybe it doesn't have one yet? So I copied that class from godot source code

#### Not a fork of GodotSteam
1: GodotSteam depends on core libraries, but gdextension doesn't support all core libraries  
2: GDExtension doesn't seem to support uint8 or uint16, so when generating bindings throws errors, so I replaced all of them uint32, and type casted. I would like to automate this, then we can have GodotSteam as submodule. That means this is a copy of GodotSteam src but modified, so I can't straight up rely on GodotSteam, every time it updates, we have to update this.

### Note: 
This is just to keep up with rapid development of godot 4, that means this may not support all features of godotsteam, this is just a substitute till actual godotsteam catches up with the latest godot build, so you can work without waiting for godotsteam official build, and maybe godotsteam itself might become a gdextension in future  
since the api is exactly same you won't get any trouble switching.


#### Fixes you can try if doesn't work
try to keep only one debug or release dll, and delete the other one, sometimes having them both release and debug files can cause issues
