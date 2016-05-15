#ifndef SRC_VISION_CORECAMERA_H_
#define SRC_VISION_CORECAMERA_H_

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
namespace CORE {
static const int DEFAULT = -1;
enum fileInputType {
		video,
		singleImage,
		multipleImages
};
class CORECamera {
private:
	VideoCapture* camera;
	String inputFilePath;
	fileInputType inputType;
	time_t lastCaptureTime;
public:
	class cameraSettings {
	public:
		int FPS, contrast, saturation, exposure, brightness;
		int resolution[2];
		cameraSettings(int resolution[2], int FPS, int brightness, int contrast, int saturation, int exposure);
		String toString();
		void fromString();
	};
	CORECamera(int deviceNumber, cameraSettings settings, bool manualImageMode = false, bool useThreading = true);
	CORECamera(int deviceNumber, int resolution[2], bool manualImageMode = false, bool useThreading = true);
	Mat getFrame();
	bool newFrameReady();
	bool setFPS(int FPS);
	bool setResolution(int resolution[2]);
	bool setResolutionX(int resolutionX);
	bool setResolutionY(int resolutionY);
	bool setBrightness(int brightness);
	bool setContrast(int constrast);
	bool setSaturation(int saturation);
	bool setExposure(int exposure);
	bool setCameraSettings(cameraSettings settings);
	void setCrop(int X1, int Y1, int X2, int Y2);
	int getFPS();
	int getResolutionX();
	int getResolutionY();
	int getBrightness();
	int getContrast();
	int getSaturation();
	int getExposure();
	time_t getLastCaptureTime();
	cameraSettings getCameraSettings();
	void useFileInput(bool manualImageMode);
	void setFileInputLocation(String path, fileInputType inputType);
	bool isOpen();
	void close();
};
}
#endif
