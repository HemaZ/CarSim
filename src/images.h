#ifndef IMAGES_H
#define IMAGES_H
#include <SFML/Graphics.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <ros/ros.h>
#include <sensor_msgs/image_encodings.h>
cv::Mat sfml2opencv(const sf::Image &img);
sensor_msgs::ImagePtr windowToROS(sf::Image &window);

#endif