# sfml-spaceships
SFML game written in learning purposes.
Unit tests are written with the usage of GoogleTest framework.

All sounds have been download from https://freesound.org/.

# Install
In order to build this app it is required to have CMake (3.14) installed, aswell as GTest and SFML library.

Debian example for SFML library:  
`sudo apt-get install libsfml-dev`  

To install GTest:  
`sudo apt-get install libgtest-dev`  
`sudo apt-get install cmake` - install cmake  
`cd /usr/src/gtest`  
`sudo cmake CMakeLists.txt`  
`sudo make`  
`sudo cp *.a /usr/lib` - copy libgtest.a and libgtest_main.a to your /usr/lib folder  


Open terminal, move to the destinated location and type:  
`git clone https://github.com/4jeR/sfml-spaceships.git`  
`cd sfml-spaceships`  
`cd build`  
`cmake ..`  
`make`  
To run the game type   
`./run`  
while being in `build` directory.  
To run the tests just type  
`./testsRunAll` 

