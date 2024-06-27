#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include <string>

cv::Ptr<cv::aruco::Dictionary> getPredefinedDictionary(const std::string& dictionary_name) {
    if (dictionary_name == "DICT_ARUCO_ORIGINAL") {
        return cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
    }
    
    else {
        throw std::runtime_error("Unknown dictionary name.");
    }
}

int main(int argc, char** argv) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " dictionary_name marker_id size output_file" << std::endl;
        return 1;
    }

    try {
        std::string dictionary_name = argv[1];
        int marker_id = std::stoi(argv[2]);
        int size = std::stoi(argv[3]);
        std::string output_file = argv[4];

        cv::Ptr<cv::aruco::Dictionary> dictionary = getPredefinedDictionary(dictionary_name);

        cv::Mat markerImage;
        cv::aruco::drawMarker(dictionary, marker_id, size, markerImage);

        cv::imwrite(output_file, markerImage);
        std::cout << "Marker generated and saved to " << output_file << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
