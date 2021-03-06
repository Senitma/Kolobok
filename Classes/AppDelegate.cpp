#include "AppDelegate.h"
#include "Settings.h"
#include "Main\MainScene.h"
#include "Element\Element.h"

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
	Element::OffAutoDrawDelete();
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	cocos2d::GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = cocos2d::Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
		glview = cocos2d::GLViewImpl::createWithRect("Kolobok", cocos2d::Rect(0, 0, Settings::FIELDWIDTHSIZE, Settings::FIELDHEIGHTSIZE));
		director->setOpenGLView(glview);
	}

	glview->setDesignResolutionSize(Settings::FIELDWIDTHSIZE, Settings::FIELDHEIGHTSIZE, ResolutionPolicy::FIXED_WIDTH);

	// turn on display FPS
	director->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0f / Settings::FPS);

	cocos2d::FileUtils::getInstance()->addSearchPath("res");
	cocos2d::FileUtils::getInstance()->addSearchPath("res\\Assets\\Other");


	// create a scene. it's an autorelease object
	auto scene = MainScene::createScene();

	// run
	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	cocos2d::Director::getInstance()->stopAnimation();

	// if you use SimpleAudioEngine, it must be pause
	// SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	cocos2d::Director::getInstance()->startAnimation();

	// if you use SimpleAudioEngine, it must resume here
	// SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
