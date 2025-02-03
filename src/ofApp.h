#pragma once

#include "ofMain.h"

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
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// Sorting algorithms
		void bubbleSort();
		void insertionSort();
		void quickSort(int low, int high);
		int quickSortPartition(int low, int high);
		void mergeSort(int left, int right);
		void merge(int left, int mid, int right);
		void fisherYatesShuffle();


		void swap(int i, int j);
		
	private:
		int radii[5]; // Five circle radii

};
