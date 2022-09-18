GENERATE_BINDINGS = auto
HEADERS = godot-headers
TARGET = debug
USE_CLANG = no

BASE = scons use_llvm=$(USE_CLANG) generate_bindings=$(GENERATE_BINDINGS) target=$(TARGET) headers=$(HEADERS)
LINUX = $(BASE) platform=linux
WINDOWS = $(BASE) platform=windows
MACOS = $(BASE) platform=macos


all:
	make linux
	make windows


linux:
	make linux32
	make linux64

linux32: SConstruct
	$(LINUX) bits=32

linux64: SConstruct
	$(LINUX) bits=64


windows:
	make windows32
	make windows64

windows32: SConstruct
	$(WINDOWS) bits=32

windows64: SConstruct
	$(WINDOWS) bits=64


macos: SConstruct
	$(MACOS)
