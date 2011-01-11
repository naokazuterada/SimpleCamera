#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofSetFrameRate(30);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	
	ofBackground(0,0,0);
	
	mirror_vertical		= false;
	mirror_horizontal	= false;
	display_rotate		= false;
	fullscreen			= false;
	adjust_min			= false;
	
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(VIDEO_WIDTH, VIDEO_HEIGHT);
	
	src_image.allocate(VIDEO_WIDTH, VIDEO_HEIGHT);
}

//--------------------------------------------------------------
void testApp::update()
{
	bool bNewFrame = false;
	vidGrabber.grabFrame();
	bNewFrame = vidGrabber.isFrameNew();
	
	if (bNewFrame)
	{
		src_image.setFromPixels(vidGrabber.getPixels(), VIDEO_WIDTH, VIDEO_HEIGHT);
		src_image.mirror(mirror_vertical, mirror_horizontal);
	}
}

//--------------------------------------------------------------
void testApp::draw()
{
	if(display_rotate)
	{
		// windowにあわせて拡大縮小
		float x_scale = (float) ofGetWidth() / (float) VIDEO_HEIGHT;
		float y_scale = (float) ofGetHeight() / (float) VIDEO_WIDTH;
		float scale;
		if(adjust_min)	scale = min(x_scale, y_scale);
		else			scale = max(x_scale, y_scale);

		ofScale((float)scale,(float)scale,1);
		
		// 回転
		ofPushMatrix();
		ofRotateZ(90);
		src_image.draw(0, -VIDEO_HEIGHT);
		ofPopMatrix();
	}
	else 
	{
		// windowにあわせて拡大縮小
		float x_scale = (float) ofGetWidth() / (float) VIDEO_WIDTH;
		float y_scale = (float) ofGetHeight() / (float) VIDEO_HEIGHT;
		float scale;
		if(adjust_min)	scale = min(x_scale, y_scale);
		else			scale = max(x_scale, y_scale);
		ofScale((float)scale,(float)scale,1);
		
		src_image.draw(0, 0);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	switch (key) {
		case 'r':
			display_rotate = !display_rotate;
			cout << "display_rotate:" << display_rotate << "¥n";
			break;
		case 'v':
			mirror_vertical = !mirror_vertical;
			cout << "mirror_vertical:" << mirror_vertical << "¥n";
			break;
		case 'h':
			mirror_horizontal = !mirror_horizontal;
			cout << "mirror_horizontal:" << mirror_horizontal << "¥n";
			break;
		case 'f':
			fullscreen = !fullscreen;
			ofSetFullscreen(fullscreen);
			cout << "fullscreen:" << fullscreen << "¥n";
			break;
		case 'm':
			adjust_min = !adjust_min;
			cout << "adjust_min:" << adjust_min << "¥n";
			break;
		default:
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

