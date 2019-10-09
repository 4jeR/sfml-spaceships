

# sfml-spaceships
SFML game written in learning purposes.
Unit tests are written with the usage of GoogleTest framework.

All sounds have been downloaded from https://freesound.org/.

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

![screenshot3](https://user-images.githubusercontent.com/38592844/66511346-0dafbd00-ead7-11e9-965e-7aaac1f6475b.png)
![spaceships1](https://user-images.githubusercontent.com/38592844/66511180-c0335000-ead6-11e9-9630-29531dd04854.png)
![screenshot2](https://user-images.githubusercontent.com/38592844/66511244-e0630f00-ead6-11e9-8b55-b7a9338cebc6.png)
![screenshot4](https://user-images.githubusercontent.com/38592844/66511499-5798a300-ead7-11e9-9e7e-4338fc73fff4.png)
