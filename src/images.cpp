#include "images.h"
cv::Mat sfml2opencv(const sf::Image &img) {
  // get size from image
  cv::Size size(img.getSize().x, img.getSize().y);
  // create a mat on image memory
  cv::Mat mat(size, CV_8UC4, (void *)img.getPixelsPtr(), cv::Mat::AUTO_STEP);
  // make SFML RGBA to OpenCV BGRA
  cv::cvtColor(mat, mat, cv::COLOR_RGBA2BGRA);
  // clone mat to avoid memory editing on image memory
  return mat.clone();
}
sensor_msgs::ImagePtr windowToROS(sf::Image &window) {
  cv::Mat img = sfml2opencv(window);
  sensor_msgs::ImagePtr msg =
      cv_bridge::CvImage(std_msgs::Header(), "bgra8", img).toImageMsg();

  return msg;
}