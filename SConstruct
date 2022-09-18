#!/usr/bin/env python
from glob import glob
from pathlib import Path

# TODO: Do not copy environment after godot-cpp/test is updated <https://github.com/godotengine/godot-cpp/blob/master/test/SConstruct>.
env = SConscript("godot-cpp/SConstruct")

# Add source files.
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

# Find gdextension path even if the directory or extension is renamed (e.g. project/addons/example/example.gdextension).
# (extension_path,) = glob("project/addons/*/*.gdextension")
# (extension_path,) = glob("project/addons/*/*.gdextension")

# Find the addon path (e.g. project/addons/example).
# addon_path = Path(extension_path).parent

# Find the project name from the gdextension file (e.g. example).
# project_name = Path(extension_path).stem
project_name = "gdsteam"

# TODO: Cache is disabled currently.
# scons_cache_path = os.environ.get("SCONS_CACHE")
# if scons_cache_path != None:
#     CacheDir(scons_cache_path)
#     print("Scons cache enabled... (path: '" + scons_cache_path + "')")

# Create the library target (e.g. libexample.linux.debug.x86_64.so).
# if env["platform"] == "macos":
#     library = env.SharedLibrary(
#         "{0}/bin/lib{1}.{2}.{3}.framework/{1}.{2}.{3}".format(
#             addon_path,
#             project_name,
#             env["platform"],
#             env["target"],
#         ),
#         source=sources,
#     )
# else:
if env["platform"] == "windows":
    env.Append(LIBS=["steam_api64"])
    env.Append(LIBPATH=["src/sdk/redistributable_bin/win64"])
    library = env.SharedLibrary(
        "output/{}/bin/lib{}.{}.{}.{}{}".format(
            project_name,
            project_name,
            env["platform"],
            env["target"],
            env["arch_suffix"],
            env["SHLIBSUFFIX"],
        ),
        source=sources,
    )
    print(library)
    # library = env.SharedLibrary(
    #     "{0}/bin/lib{1}.{2}.{3}.{4}{5}".format(
    #         addon_path,
    #         project_name,
    #         env["platform"],
    #         env["target"],
    #         env["arch_suffix"],
    #         env["SHLIBSUFFIX"],
    #     ),
    #     source=sources,
    # )
else: 
    print("unsupported platform")

Default(library)
