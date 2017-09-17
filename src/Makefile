#
#   Makefile for V-REP simulator using Hackflight
#
#   Copyright (C) Simon D. Levy and Matt Lubas 2016
#
#   This file is part of Hackflight-VREP.
#
#   Hackflight-VREP is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.

#   Hackflight-VREP is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#   You should have received a copy of the GNU General Public License
#   along with Hackflight-VREP.  If not, see <http://www.gnu.org/licenses/>.
#

# Edit this for where you installed Hackflight
HACKFLIGHT_DIR = $(HOME)/Desktop/Hackflight
 
# Edit this for where you installed V-REP
VREP_DIR_LINUX = $(HOME)/Software/V-REP_PRO_EDU_V3_4_0_Linux

COMMON = $(VREP_DIR)/programming/common/
CFLAGS = -std=c++11 -Wall -D_SIM \
		 -I$(VREP_DIR)/programming/include/ -I. -I../../src -I$(HACKFLIGHT_DIR)/include \
		 -Wall -fPIC -static

CFLAGS += -I/usr/include/SDL
VREP_DIR = $(VREP_DIR_LINUX)
VREP_LIBDIR = $(VREP_DIR)

PLUGIN = libv_repExtHackflight.so

ALL = $(PLUGIN) 

all: $(ALL)

$(PLUGIN): *.cpp ../../src/*.cpp ../../src/*.hpp $(HACKFLIGHT_DIR)/include/*.hpp 
	g++ $(CFLAGS) -c -DVREP_DIR=\"$(VREP_LIBDIR)\" ../../src//v_repExtHackflight.cpp 
	g++ $(CFLAGS) -c ../../src/controller_Posix.cpp 
	g++ $(CFLAGS) -c ../../src/controller_Linux.cpp 
	g++ $(CFLAGS) -c $(COMMON)/scriptFunctionData.cpp 
	g++ $(CFLAGS) -c $(COMMON)/scriptFunctionDataItem.cpp
	g++ $(CFLAGS) -c $(COMMON)/v_repLib.cpp
	g++ $(CFLAGS) -c ../../src/MSPPG.cpp
	g++ *.o -o libv_repExtHackflight.so -lpthread -shared $(JOYLIB)

install: $(PLUGIN)
	cp $(PLUGIN) $(VREP_LIBDIR)

release: $(PLUGIN)
	cp $(PLUGIN) x64/Release

clean:
	rm -f $(ALL) *.o *.pyc *~

