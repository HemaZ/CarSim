#ifndef GAME_H
#define GAME_H
#include "car.h"
#include "renderer.h"
#include "std_msgs/Float32.h"
#include <chrono>
#include <ros/ros.h>

#include <thread>
class Game {

public:
  Game(int height, int width, ros::NodeHandle &nh);

private:
  int _height;
  int _width;
  bool _play;
  Car _car;
  ros::Subscriber _sub;
  void _clbk(const std_msgs::Float32::ConstPtr &msg);
  void Run(Renderer &rnd);
  void LimitWorld();
};

#endif