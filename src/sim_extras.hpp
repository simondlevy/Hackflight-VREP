/*
   sim_extras.hpp : Common declarations for extra functions in simulator

   Copyright (C) Simon D. Levy, Matt Lubas, and Julio Hidalgo Lopez 2016

   This file is part of Hackflight-VREP.

   Hackflight-VREP is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Hackflight-VREP is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with Hackflight-VREP.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <stdint.h>
#include <board.hpp>

// Implemented in sim_extras.cpp for each scene
void simExtrasStart(void);
void simExtrasUpdate(void);
void simExtrasMessage(int message, int * auxiliaryData, void * customData);
void simExtrasStop(void);

// Implemented in v_repExtHackflight.cpp
void errorDialog(char * message);

