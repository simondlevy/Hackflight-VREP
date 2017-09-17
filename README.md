# Running Hackflight in the V-REP simulator

<img src="hackflight.png">

Hackflight-VREP is a cross-platform flight simulator using the <a
href="https://github.com/simondlevy/Hackflight">Hackflight</a> firmware and the
V-REP robotics simulator.  Originally part of the Hackflight repository,
Hackflight-VREP was broken off into its own repository because of its much
larger size.

<b>I am only maintaining this simulator for 64-bit platforms.</b>

<b>Quickstart, Windows</b>

<ol>
<li> Install <a href="http://www.coppeliarobotics.com/downloads.html">V-REP</a>.
<p><li>Clone the hackflight repository.
<p><li>Drag the plugin <b>scenes\outdoors\x64\Release\v_repExtHackflight.dll</b>
to the V-REP folder where the other DLLs are. On my computer this is
<b>C:\Program FIles\V-REP3\V-REP_PRO_EDU</b>.
<p><li>Plug in your R/C transmitter, joystick, or game controller. Currently supported:
<p><ul>
<li> FrkSky Taranis transmitter with USB cable
<p><li>Logitch Extreme 3D Pro joystick
<p><li>Nyko Core Controller for PS3
<p><li>XBOX360 controller
<p><li>Keyboard, using the Microsoft Flight Controller numeric keypad 
<a href="http://www.flightsimbooks.com/flightsimhandbook/keyboardcontrols.php">mappings</a>,
if none of the above are connected: not recommended because it requires you 
to foreground the console
</ul>

<p><li> In the <b>outdoors</b> folder, ouble-click on the hackflight scene <b>hackflight.ttt</b> 
to launch V-REP.
<p><li> Press the triangular play button at the top of V-REP.
<p><ul>
<p><li> If V-REP asks you whether you really want to run the simulation with a dt=10msec
update rate, agree.  You may have to do this three times.
<p><li>If the vehicle takes off immediately, make sure your throttle is down by
raising it slightly and then lowering it all the way down.  You may also need to wiggle
the sticks a little at first for the simulator to detect them.  Inexpensive clones of 
controllers like the XBOX360 tend to give a noisy signal (nonzero values when
centered).
</ul>
<p><li>Press the square stop button at the top of V-REP to stop the simulation.
</ol>


<b>Quickstart, Linux</b>

<ol>
<li> Install <a href="http://www.coppeliarobotics.com/downloads.html">V-REP</a>.
<p><li>Clone the hackflight repository.
<p><li>Drag the plugin <b>scenes/outdoors/x64/Release/libv_repExtHackflight.so</b>
to the V-REP folder where the other plugins are. On my computer this is
<b>~/Software//V-REP_PRO_EDU_V3_3_1_64_Linux</b>.
<p><li>Plug in your R/C transmitter, joystick, or game controller (see above).  On Linux you can
also go wireless, using a Teensy 3.2 micrcontroller with Spektrum satellite (e.g., Lemon RX) attached.
The Arduino sketch supporting this is in the <b>dsmdongle</b> directory in the main part of the repository.
The Linux version checks for this setup by attempting to open <tt>/dev/ttyACM0</tt>.  So you may need
to modify that setting in <b>controller_Linux.cpp</b>.
<p><li> Open a terminal window, navigate to the V-REP folder, and do <b>./vrep.sh</b> to launch V-REP.
<p><li> Follow steps 6-7 above.
</ol>

<b>Developing for Windows</b>

You will need Visual Studio 2015.  After cloning the hackflight repository,
double-click on <b>v_repExtHackflight.vcxproj</b> to launch the project.
Building for Release will create the DLL file, which you can then move into the
V-REP folder as in the Windows quickstart above.  

<b>Developing for Linux</b>

After cloning the Hackflight <a href="https://github.com/simdlevy/Hackflight">repository</a>, 
edit the <tt>VREP\_DIR</tt> variable in the Makefile in this directory
(<b>outdoors</b>) to reflect where you installed V-REP.  Typing <b>make
install</b> should then build the plugin and install it the appropriate place.

<b>Companion-Board Simulation</b>

Linux users can experiment with a simulated &ldquo;companion board&rdquo; computer
(Raspberry Pi, ODROID, BeagleBone) that uses Python and OpenCV to illustrate a 
simple machine-vision algorithm.  This project resides in <b>hackflight/sim/vision</b>.
Before trying it out you will need to install OpenCV:  

<p>

On Ubuntu:
<pre>
  sudo apt install python-opencv
  sudo apt install libopencv-dev
</pre>

<p>

On Fedora:

<pre>
  sudo yum install opencv-python
  sudo yum install opencv-devel
</pre>


