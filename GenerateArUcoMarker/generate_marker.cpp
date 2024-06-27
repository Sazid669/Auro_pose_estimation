#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <dictionary> <id> <size> <output_file>" << std::endl;
        return 1;
    }

    // Parse the input arguments
    std::string dictionary_name = argv[1];
    int marker_id = std::stoi(argv[2]);
    int marker_size = std::stoi(argv[3]);
    std::string output_file = argv[4];

    // Create the dictionary
    cv::Ptr<cv::aruco::Dictionary> dictionary;
    if (dictionary_name == "DICT_ARUCO_ORIGINAL") {
        dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
    } else {
        std::cerr << "Unknown dictionary name" << std::endl;
        return 1;
    }

    // Create the marker image
    cv::Mat marker_image;
    cv::aruco::drawMarker(dictionary, marker_id, marker_size, marker_image);

    // Save the marker image
    if (!cv::imwrite(output_file, marker_image)) {
        std::cerr << "Failed to save the marker image" << std::endl;
        return 1;
    }

    std::cout << "Marker generated successfully: " << output_file << std::endl;
    return 0;
}
