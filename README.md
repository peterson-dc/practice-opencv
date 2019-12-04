# practice-opencv

## Purpose
This repository was created as a workspace to experiment with the open source computer vision library, OpenCV. Essentially,
this is an OpenCV playground for a senior project, which is to use computer vision and sensors of different types to make an
autonomously driven go kart.

## Build Process
Each .cpp file is its own sample program that demonstrates some type of OpenCV functionality. Therefore, there are multiple
executable files created when this project is compiled.

Here is the list of executable files generated after compilation:
- OpenCVTest
- ContoursCVTest
- HSVThreshold
- FloorMapper
- EdgeDetection

This project uses CMake for its build tool. As long as OpenCV is installed correctly, CMake takes care of linking the OpenCV
libraries and compiling the code. If OpenCV is not installed, try checking out this link:

https://medium.com/@jaskaranvirdi/setting-up-opencv-and-c-development-environment-in-xcode-b6027728003

### Compilation Steps
1. ```mkdir build```
2. ```cd build```
3. ```cmake ..```
4. ```make```
