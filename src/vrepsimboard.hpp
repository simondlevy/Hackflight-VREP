/*
   Hackflight Board class declaration for V-REP simulator

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

#include <hackflight.hpp>
#include <board.hpp>
#include <config.hpp>

namespace hf {

    class VrepSimBoard : public Board {

        public:

            virtual void     init(Config& config) override;
            virtual void     getImu(float eulerAnglesRadians[3], float gyroRadiansPerSecond[3]) override;
            virtual void     ledSet(uint8_t id, bool is_on)  override;
            virtual uint64_t getMicros() override;
            virtual void     writeMotor(uint8_t index, float value) override;
            virtual void     delayMilliseconds(uint32_t msec) override;
            virtual bool     skipArming(void) override;

    private: // types

        typedef struct stdev_t {
            float m_oldM, m_newM, m_oldS, m_newS;
            int m_n;
        } stdev_t;

    private: //methods

        static void normalizeV(float src[3], float dest[3]);

    private: // fields

        float       EstG[3];
        float       EstN[3];
        float       gyroCmpfFactor;
        float       gyroScale;

    };  // class VrepSimBoard

}  // namespace hf
