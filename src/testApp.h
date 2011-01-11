#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxOpenCv.h"

class testApp : public ofBaseApp{

	public:
	
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

	ofVideoGrabber  vidGrabber;
	ofxCvColorImage src_image;		// 取得用
	ofxCvColorImage rotate_image;	// 表示用
	ofxCvColorImage disp_image;	// 表示用
	
	static const int VIDEO_WIDTH = 640;
	static const int VIDEO_HEIGHT = 480;
	
	bool mirror_vertical;
	bool mirror_horizontal;
	bool display_rotate;
	bool fullscreen;
};

#endif
