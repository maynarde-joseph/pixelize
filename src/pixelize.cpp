#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>


// Returns buffer of pixelated image
// Inputs:
//  inputBuffer: buffer of an image
//  w: res eg. 16,32,64,128
//  h: res eg. 16,32,64,128
std::vector<uchar> pixelateImage(const std::vector<uchar> &inputBuffer, int w, int h) {
  cv::Mat input = cv::imdecode(inputBuffer, cv::IMREAD_COLOR);

  int height = input.rows;
  int width = input.cols;

  cv::Mat temp;
  cv::resize(input, temp, cv::Size(w, h), 0, 0, cv::INTER_LINEAR);

  cv::Mat output;
  cv::resize(temp, output, cv::Size(width, height), 0, 0, cv::INTER_NEAREST);

  std::vector<uchar> outputBuffer;
  cv::imencode(".jpg", output, outputBuffer);

  return outputBuffer;
}
