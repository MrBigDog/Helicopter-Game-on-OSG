//
//  Configuration.cpp
//
//	See main.cpp file header for credits
//
//	This is a configuration class to congigure our screen and file data.

#include "Configuration.h"


Configuration::Configuration() {
	this->mouseControl = true;
	this->autoCamera = true;
	this->friction = true;
	this->missilesWithInitialVelocity = true;
	initialize();
}



// we initialize our sceen
void Configuration::initialize(){
    // get screen size
    initScreanSizeSettings();
	
    // get ket settings
    initKeySettings();
}



// screen setting
void Configuration::initScreanSizeSettings() {
	osg::GraphicsContext::WindowingSystemInterface *wsi = osg::GraphicsContext::getWindowingSystemInterface();
	
	if (!wsi)
		osg::notify(osg::NOTICE) << "Error, no WindowSystemInterface available, cannot create windows." << std::endl;
	else
		wsi->getScreenResolution(osg::GraphicsContext::ScreenIdentifier(0),
								 this->screenWidth, this->screenHeight);
	
}



// our key settings will be read from a file called settings.txt. It will read each line on the file
void Configuration::initKeySettings() {
	std::ifstream inFile;
	std::string inputWord;
	
    // open the file we provided
	inFile.open("settings.txt");

	inFile >> inputWord;
	inFile.ignore(500, '\n');
	if (inputWord == "false")
		this->mouseControl = false;
	else
		this->mouseControl = true;
	
	inFile >> inputWord;
	inFile.ignore(500, '\n');
	if (inputWord == "false")
		this->autoCamera = false;
	else
		this->autoCamera = true;
	
	inFile.get(this->keySettings.movingForward);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.movingRight);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.movingLeft);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.movingBackward);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.resetJoystick);
	inFile.ignore(500, '\n');
    
	inFile.get(this->keySettings.zeroRotorSpeed);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.decreaseRotorSpeed);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.increaseRotorSpeed);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.neutralRotorMode);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.rotateLeft);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.rotateRight);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.fire);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.incrementInclinationAngle);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.decrementInclinationAngle);
	inFile.ignore(500, '\n');
	
	inFile >> inputWord;
	inFile.ignore(500, '\n');
	if (inputWord == "false")
		this->missilesWithInitialVelocity = false;
	else
		this->missilesWithInitialVelocity = true;
	
	inFile.get(this->keySettings.incrementMissileInitialSpeed);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.decrementMissileInitialSpeed);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.frictionEnable);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.frictionDisable);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.updateKeySettings);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.showPopupHelpScreen);
	inFile.ignore(500, '\n');
	
	inFile.get(this->keySettings.hidePopupHelpScreen);
	inFile.ignore(500, '\n');
	
	
	inFile.close();
}



// getter functions of our singelton class 
unsigned int Configuration::getScreenWidth() {
	return this->screenWidth;
}



unsigned int Configuration::getScreenHeight() {
	return this->screenHeight;
}



KeySettings Configuration::getKeySettings() {
	return this->keySettings;
}



void Configuration::activateFriction() {
	this->friction = true;
}



void Configuration::disactivateFriction() {
	this->friction = false;
}


bool Configuration::isMouseControl() {
	return this->mouseControl;
}



bool Configuration::isAutoCamera() {
	return this->autoCamera;
}



bool Configuration::isFrictionActive() {
	return this->friction;
}



bool Configuration::isMissilesWithInitialVelocity() {
	return this->missilesWithInitialVelocity;
}






