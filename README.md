# Note: We are no longer developing this project.  
## We've switched to a [simulator](https://github.com/simondlevy/Hackflight/sim) built with UnrealEngine

# Running Hackflight in the V-REP simulator

<img src="hackflight.png">

Hackflight-VREP is a cross-platform flight simulator using the 
[Hackflight](https://github.com/simondlevy/Hackflight) firmware and the
V-REP robotics simulator.  Originally part of the Hackflight repository,
Hackflight-VREP was broken off into its own repository because of its much
larger size.

<b>I am only maintaining this simulator for Windows and Linux 64-bit platforms.</b>

## Quickstart, Windows

1. Install <a href="http://www.coppeliarobotics.com/downloads.html">V-REP</a>.
2. Clone the hackflight repository.
3. Drag the plugin <b>scenes\outdoors\x64\Release\v_repExtHackflight.dll</b>
to the V-REP folder where the other DLLs are. On my computer this is
<b>C:\Program FIles\V-REP3\V-REP_PRO_EDU</b>.
4. Plug in your R/C transmitter, joystick, or game controller. Currently supported:

    * FrkSky Taranis transmitter with USB cable
    * Logitch Extreme 3D Pro joystick
    * PS3 controller
    * XBOX360 controller

5. In the <b>outdoors</b> folder, ouble-click on the hackflight scene <b>hackflight.ttt</b> 
to launch V-REP.
6. Press the triangular play button at the top of V-REP.
    * If V-REP asks you whether you really want to run the simulation with a dt=10msec
update rate, agree.  You may have to do this three times.
    * If the vehicle takes off immediately, make sure your throttle is down by
raising it slightly and then lowering it all the way down.  You may also need to wiggle
the sticks a little at first for the simulator to detect them.  Inexpensive clones of 
controllers like the XBOX360 tend to give a noisy signal (nonzero values when
centered).
7. Press the square stop button at the top of V-REP to stop the simulation.


## Quickstart, Linux

1. Install <a href="http://www.coppeliarobotics.com/downloads.html">V-REP</a>.
2. Clone the hackflight repository.
3. Drag the plugin <b>scenes/outdoors/x64/Release/libv_repExtHackflight.so</b>
to the V-REP folder where the other plugins are. On my computer this is
<b>~/Software//V-REP_PRO_EDU_V3_3_1_64_Linux</b>.
4. Plug in your R/C transmitter, joystick, or game controller (see above).  
The Linux version checks for this setup by attempting to open <tt>/dev/ttyACM0</tt>.  So you may need
to modify that setting in <b>controller_Linux.cpp</b>.
5. Open a terminal window, navigate to the V-REP folder, and do <b>./vrep.sh</b> to launch V-REP.
6. Follow steps 6-7 for Windows above.

## Development

If you want to develop Hackflight-VREP, you will also need to clone the [https://github.com/simondlevy/Hackflight](Hackflight)
repository.  We suggest cloning it into your <b>Arduino/libraries</b> folder, as that is where the rest of the code
expects it to be.  (On Windows, your Arduino folder should be in your <b>Documents</b> folder; on Linux, in your home
directory.)

## Developing for Windows

You will need Visual Studio 2015.  After cloning the hackflight repository,
double-click on <b>v_repExtHackflight.vcxproj</b> to launch the project.
Building for Release will create the DLL file and save it to the V-REP folder for you.
If you run into trouble, make sure that your include and V-REP folders are specified
correctly in the Project configuration.

## Developing for Linux

After cloning the Hackflight <a href="https://github.com/simdlevy/Hackflight">repository</a>, 
edit the <tt>VREP\_DIR</tt> variable in the Makefile in this directory
(<b>outdoors</b>) to reflect where you installed V-REP.  Typing <b>make
install</b> should then build the plugin and install it the appropriate place.

## Companion-Board Simulation

Linux users can experiment with a simulated &ldquo;companion board&rdquo; computer
(Raspberry Pi, ODROID, BeagleBone) that uses Python and OpenCV to illustrate a 
simple machine-vision algorithm.  This project resides in <b>hackflight/sim/vision</b>.
Before trying it out you will need to install OpenCV:  

On Ubuntu:
```
  sudo apt install python-opencv
  sudo apt install libopencv-dev
```


On Fedora:

```
  sudo yum install opencv-python
  sudo yum install opencv-devel
```


