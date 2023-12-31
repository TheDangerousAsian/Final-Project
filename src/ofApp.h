#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"
#include "Octree.h"
#include "Particle.h"
#include "ParticleEmitter.h"
#include "TransformObject.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent2(ofDragInfo dragInfo);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void drawAxis(ofVec3f);
		void initLightingAndMaterials();
		void savePicture();
		void toggleWireframeMode();
		void togglePointsDisplay();
		void toggleSelectTerrain();
		void toggleTimer();
		void setCameraTarget();
		bool mouseIntersectPlane(ofVec3f planePoint, ofVec3f planeNorm, ofVec3f &point);
		bool raySelectWithOctree(ofVec3f &pointRet);
		void checkCollision();
		bool doPointSelection();
		glm::vec3 ofApp::getMousePointOnPlane(glm::vec3 p , glm::vec3 n);

		void loadVbo();
		Ray AGL;
		bool bAGL;
		float height;
		float fuel;
		ofEasyCam cam;
		ofxAssimpModelLoader mars, lander, spaceship;
		ofLight light;
		Box boundingBox, landerBounds;
		Box testBox;
		vector<Box> colBoxList;
		bool bLanderSelected = false;
		Octree octree;
		TreeNode selectedNode;
		glm::vec3 mouseDownPos, mouseLastPos;
		bool bInDrag = false;

		ofxIntSlider numLevels;
		ofxFloatSlider gravity;
		ofxFloatSlider damping;
		ofxFloatSlider radius;
		ofxVec3Slider velocity;
		ofxIntSlider numParticles;
		ofxFloatSlider lifespan;
		ofxVec2Slider lifespanRange;
		ofxVec3Slider turbMin;
		ofxVec3Slider turbMax;
		ofxFloatSlider mass;
		ofxFloatSlider radialForceVal;
		ofxFloatSlider radialHight;
		ofxFloatSlider cyclicForceVal;
		ofxFloatSlider rate;
		ofxPanel gui;

		bool bAltKeyDown;
		bool bCtrlKeyDown;
		bool bWireframe;
		bool bDisplayPoints;
		bool bPointSelected;
		bool bHide;
		bool pointSelected = false;
		bool bDisplayLeafNodes = false;
		bool bDisplayOctree = false;
		bool bDisplayBBoxes = false;
		bool bTimer = false;
		bool collision = false;
		bool gameOver = false;

		bool bLanderLoaded;
		bool bTerrainSelected;
	
		ofVec3f selectedPoint;
		ofVec3f intersectPoint;
		vector<Box> goalBox;
		map<Box, bool> bGoalBox;


		ParticleEmitter exhaustEmitter;
		ParticleEmitter landerEmitter;
		ParticleEmitter goalEmitter;
		ParticleEmitter explosionEmitter;


		ImpulseRadialForce *impulseForce;
		ImpulseRadialForce* explosiveForce;
		TurbulenceForce* explosiveTurbulentForce;
		GravityForce* gravityForce;
		GravityForce* neutralForce;
		TurbulenceForce* turbulenceForce;
		CyclicForce* cyclicForce;

		//Thrust sound
		ofSoundPlayer thrustSound;
		ofSoundPlayer pointUp;

		//Background Image
		//ofEasyCam cam;
		ofImage backgroundImage;
		ofPlanePrimitive backgroundPlane;

		//Fuel System
		float fuelGauge;
		float fuelUsageRate;
		bool isSpacebarPressed = false;


		vector<Box> bboxList;
		map<int, ofColor> colorMap;
		map<int, bool> keymap;
		const float selectionRange = 4.0;

		bool bDefaultCam;
		bool bThirdPersonCam;
		bool bTopDownCam;
		bool bExhaustCam;
		bool bSideCam;

		// textures
		ofTexture  particleTex;

		// shaders
		ofVbo vbo;
		ofShader shader;
};
