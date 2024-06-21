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

  cv::Mat output;
  cv::resize(input, output, cv::Size(w, h), 0, 0, cv::INTER_LINEAR);

  std::vector<uchar> outputBuffer;
  cv::imencode(".jpg", output, outputBuffer);

  return outputBuffer;
}

int main() {
  std::vector<uchar> inputBuffer;
  std::ifstream file("../images/wiz2.png", std::ios::binary);

  if (file.is_open()) {
    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    inputBuffer.resize(fileSize);
    file.read(reinterpret_cast<char *>(inputBuffer.data()), fileSize);
    file.close();
    std::vector<uchar> outputBuffer = pixelateImage(inputBuffer, 32, 32);

    try {
      std::ofstream outputFile("output.jpg", std::ios::binary);
      if (outputFile.is_open()) {
        outputFile.write(reinterpret_cast<const char *>(outputBuffer.data()),
                         outputBuffer.size());
        outputFile.close();
        std::cout << "Pixelated image saved as output.jpg" << std::endl;
      } else {
        std::cerr << "Failed to open output file." << std::endl;
      }
    } catch (const std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  } else {
    std::cerr << "Failed to open input file." << std::endl;
  }

  return 0;
}