/*
   Hackflight Receiver class declaration for V-REP simulator

   Copyright (C) Simon D. Levy 2017

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

#include <receiver.hpp>

namespace hf {

    class VrepSimReceiver : public Receiver {

        public:

            virtual void     begin(void) override;
            virtual bool     useSerial(void) override;
            virtual uint16_t readChannel(uint8_t chan) override;

    };  // class VrepSimReceiver

}  // namespace hf
