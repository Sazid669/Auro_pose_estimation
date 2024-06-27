#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " dictionary_name" << std::endl;
        return 1;
    }

    std::string dictionary_name = argv[1];
    cv::Ptr<cv::aruco::Dictionary> dictionary;
   
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);

    cv::VideoCapture inputVideo;
    inputVideo.open(0);

    if (!inputVideo.isOpened()) {
        std::cerr << "ERROR: Could not open video stream." << std::endl;
        return 1;
    }

    cv::Mat frame, imageCopy;
    std::vector<int> ids;
    std::vector<std::vector<cv::Point2f>> corners;

    while (inputVideo.grab()) {
        inputVideo.retrieve(frame);
        frame.copyTo(imageCopy);
        cv::aruco::detectMarkers(frame, dictionary, corners, ids);

        // if at least one marker detected
        if (ids.size() > 0) {
            cv::aruco::drawDetectedMarkers(imageCopy, corners, ids);

            for (int i = 0; i < ids.size(); i++) {
                cv::rectangle(imageCopy, corners[i][0] - cv::Point2f(3, 3), corners[i][0] + cv::Point2f(3, 3), cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
            }
        }

        cv::imshow("Detected ArUco markers", imageCopy);
        char key = (char) cv::waitKey(10);
        if (key == 27) break; // ESC key: quit program
    }

    return 0;
}
