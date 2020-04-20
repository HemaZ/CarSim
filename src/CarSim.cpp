#include "game.h"
#include "renderer.h"
#include "ros/ros.h"
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
int main(int argc, char **argv) {
  ros::init(argc, argv, "CarSim");
  ros::NodeHandle n;
  Game game(720, 1280, n);

  return 0;
}
