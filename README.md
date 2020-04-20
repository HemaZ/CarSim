# Hema's CarSim V0.1
#### A Simple Car Simulator based on SFML Library and ROS for Udacity C++ NanoDegree Capstone Project.
![screenshot](Screenshot.gif)

#### Dependencies
* SFML Library   ` sudo apt install libsfml-dev`
* [ROS](https://ros.org)


#### How To Run:
* `cd build && cmake ..`
* `make`
* `./CarSim`

### How to Drive Manually:
* Q -> Steer Left
* E -> Steer Right
* Arrow Up -> Increase Speed
* Backspace -> Reset

### How to Drive using ROS:
* Publish `std_msgs/Float32` on Topic `/CarSim/steer` values [-10,10]