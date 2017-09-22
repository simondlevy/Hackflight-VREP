/*
   vrepsimmodel.hpp : Simulated model (PIDs) for Hackflight-VREP

   This file is part of Hackflight.

   Hackflight is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Hackflight is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with Hackflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <model.hpp>

namespace hf {

    class VrepSimModel : public Model {

        public:

            VrepSimModel(void) {

                // Level (accelerometer)
                levelP         = 0.10f;

                // Rate (gyro): P must be positive
                ratePitchrollP = 0.125f;
                ratePitchrollI = 0.05f;
                ratePitchrollD = 0.01f;

                // Yaw: P must be positive
                yawP           = 0.1f;
                yawI           = 0.05f;
            }
    };

} // namespace
