#include "StudentPreProcessing.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImage * x = ImageFactory::newIntensityImage();
	x->set(image.getWidth(), image.getHeight());

	for (int i = 0; i < (image.getHeight() * image.getWidth()); ++i){
		RGB currentPixel = image.getPixel(i);
		Intensity intensePixel = ( (currentPixel.b + currentPixel.g + currentPixel.r) / 3);
		x->setPixel(i, intensePixel);
	}
	return x;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	ImageFactory::setImplementation(ImageFactory::DEFAULT);
	IntensityImage * x = ImageFactory::newIntensityImage();
	x->set(image.getWidth(), image.getHeight());

	for (int i = 0; i < (image.getHeight() * image.getWidth()); ++i){
		Intensity currentPixel = image.getPixel(i);
		x->setPixel(i, currentPixel);
	}
	return x;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	ImageFactory::setImplementation(ImageFactory::DEFAULT);
	IntensityImage * x = ImageFactory::newIntensityImage();
	x->set(image.getWidth(), image.getHeight());

	Kernel EdgeFourKern = Kernel(3, 3);

	int8_t kern[3][3] = {	{ 0, -1, 0 },
							{-1,  4,-1 },
							{ 0, -1, 0 } };

	/*
	EdgeFourKern.setKernelPoint(0, 0, 0);
	EdgeFourKern.setKernelPoint(1, 0, -1);
	EdgeFourKern.setKernelPoint(2, 0, 0);
	EdgeFourKern.setKernelPoint(0, 1, -1);
	EdgeFourKern.setKernelPoint(1, 1, 4);
	EdgeFourKern.setKernelPoint(2, 1, -1);
	EdgeFourKern.setKernelPoint(0, 2, 0);
	EdgeFourKern.setKernelPoint(1, 2, -1);
	EdgeFourKern.setKernelPoint(2, 2, 0);
	*/

	EdgeFourKern.setKernel(kern);
	std::cout << EdgeFourKern;

	for (int i = 0; i < (image.getHeight() * image.getWidth()); ++i){
		x->setPixel(i, image.getPixel(i));
	}
	return x;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	ImageFactory::setImplementation(ImageFactory::DEFAULT);
	IntensityImage * x = ImageFactory::newIntensityImage();
	x->set(image.getWidth(), image.getHeight());

	int thresholdValue = 140;

	for (int i = 0; i < (image.getHeight() * image.getWidth()); ++i){
		Intensity currentPixel = image.getPixel(i);
		if (currentPixel >= thresholdValue){
			currentPixel = 255;
		}
		else{
			currentPixel = 0;
		}
		x->setPixel(i, currentPixel);
	}
	return x;
}