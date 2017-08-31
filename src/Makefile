#
#   Makefile for V-REP simulator using Hackflight
#
#   Copyright (C) Simon D. Levy and Matt Lubas 2016
#
#   This file is part of Hackflight.
#
#   Hackflight is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#   Hackflight is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#   You should have received a copy of the GNU General Public License
#   along with Hackflight.  If not, see <http://www.gnu.org/licenses/>.
#

# Edit this for where you installed Hackflight
HACKFLIGHT_DIR = $(HOME)/Desktop/Hackflight
 
# Edit this for where you installed V-REP
VREP_DIR_LINUX = $(HOME)/Software/V-REP_PRO_EDU_V3_4_0_Linux
VREP_DIR_OSX   = /Applications/V-REP_PRO_EDU_V3_3_2_Mac

COMMON = $(VREP_DIR)/programming/common/
CFLAGS = -std=c++11 -Wall -D_SIM \
		 -I$(VREP_DIR)/programming/include/ -I. -I../../src -I$(HACKFLIGHT_DIR)/common -I$(HACKFLIGHT_DIR)/include \
		 -Wall -fPIC -static

OS = $(shell uname -s)
ifeq ($(OS), Linux)
	EXT = so
	CFLAGS += -I/usr/include/SDL
	VREP_DIR = $(VREP_DIR_LINUX)
    VREP_LIBDIR = $(VREP_DIR)
else
	EXT = dylib
	CFLAGS += -I/Library/Frameworks/SDL2.framework/Headers/
	JOYLIB = -lSDL2
	VREP_DIR = $(VREP_DIR_OSX)
    VREP_LIBDIR = $(VREP_DIR)/vrep.app/Contents/MacOS/
endif

PLUGIN = libv_repExtHackflight.$(EXT)

ALL = $(PLUGIN) 

all: $(ALL)

libv_repExtHackflight.$(EXT): *.hpp ../../src/*.cpp ../../src/*.hpp $(HACKFLIGHT_DIR)/include/*.hpp 
	g++ $(CFLAGS) -c -DVREP_DIR=\"$(VREP_LIBDIR)\" ../../src//v_repExtHackflight.cpp 
	g++ $(CFLAGS) -c $(HACKFLIGHT_DIR)/common/serial.cpp
	g++ $(CFLAGS) -c ../../src/controller_Posix.cpp 
	g++ $(CFLAGS) -c ../../src/controller_$(OS).cpp 
	g++ $(CFLAGS) -c $(COMMON)/scriptFunctionData.cpp 
	g++ $(CFLAGS) -c $(COMMON)/scriptFunctionDataItem.cpp
	g++ $(CFLAGS) -c $(COMMON)/v_repLib.cpp
	g++ $(CFLAGS) -c ../../src/MSPPG.cpp
	g++ *.o -o libv_repExtHackflight.$(EXT) -lpthread -shared $(JOYLIB) -lmsppg

install: $(PLUGIN)
	cp $(PLUGIN) $(VREP_LIBDIR)

release: $(PLUGIN)
	cp $(PLUGIN) Release

clean:
	rm -f $(ALL) *.o *.pyc *~
