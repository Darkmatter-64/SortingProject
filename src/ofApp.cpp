#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cout << "Setup" << endl;
	for (int i = 0; i < 5; i++) {
		this->radii[i] = rand() % 90 + 10; // Between 10 and 100
		cout << this->radii[i] << ", ";
	}
	cout << "Press: 'r' Reroll, 'b' Bubble Sort, 'q' Quick Sort, 'i' Insertion Sort, 'm' Merge Sort, 's' Fisher-Yates Shuffle" << endl;


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	int xOffset = 0;
	int yMax = 0;
	for (int i = 0; i < 5; i++) {
		int radius = this->radii[i];
		if (yMax < radius) {
			yMax = radius;
		}
	}
	for (int i = 0; i < 5; i++) {
		int radius = this->radii[i];
		ofNoFill();
		ofDrawCircle(radius + xOffset, yMax, radius);
		ofDrawBitmapString(to_string(radius), radius + xOffset, yMax);
		xOffset += 2 * radius;
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key) {
	case 'r':
		cout << endl << "New set: ";
		for (int i = 0; i < 5; i++) {
			this->radii[i] = rand() % 90 + 10; // Between 10 and 100
			cout << this->radii[i] << ", ";
		}
		break;

	case 'b':
		bubbleSort();
		cout << endl << "Bubble Sorted: ";
		for (int i = 0; i < 5; i++) {
			cout << this->radii[i] << ", ";
		}
		break;
	case 'i':
		insertionSort();
		cout << endl << "Insertion Sorted: ";
		for (int i = 0; i < 5; i++) {
			cout << this->radii[i] << ", ";
		}
		break;

	case 'q':
		quickSort(0,4);
		cout << endl << "Quick Sorted: ";
		for (int i = 0; i < 5; i++) {
			cout << this->radii[i] << ", ";
		}
		break;
	case 'm':
		mergeSort(0, 4);
		cout << endl << "Merge Sorted: ";
		for (int i = 0; i < 5; i++) {
			cout << this->radii[i] << ", ";
		}
		break;
	case 's':
		fisherYatesShuffle();
		cout << endl << "Fisher-Yates Shuffled: ";
		for (int i = 0; i < 5; i++) {
			cout << this->radii[i] << ", ";
		}
		break;
	}
	

}


// Sorting algorithms

// Inspired by https://www.geeksforgeeks.org/bubble-sort-in-cpp/
void ofApp :: bubbleSort() {
	// Outer loop that corresponds to the number of
	// elements to be sorted
	for (int i = 0; i < 4; i++) {
		// Last i elements are already
		// in place
		for (int j = 0; j < 4 - i; j++) {
			// Comparing adjacent elements
			if (radii[j] > radii[j + 1]) {
				// Swapping if in the wrong order
				swap(j, j + 1);
			}
		}
	}

}

// Inspired by https://www.geeksforgeeks.org/insertion-sort-algorithm/
void ofApp::insertionSort() {
	for (int i = 1; i < 5; ++i) {
		int key = radii[i];
		int j = i - 1;

		/* Move elements of arr[0..i-1], that are
		   greater than key, to one position ahead
		   of their current position */
		while (j >= 0 && radii[j] > key) {
			radii[j + 1] = radii[j];
			j = j - 1;
		}
		radii[j + 1] = key;
	}
}

// Inspired by https://www.geeksforgeeks.org/cpp-program-for-quicksort/
void ofApp::quickSort(int low, int high) {
	// Base case: This part will be executed till the starting
	// index low is lesser than the ending index high
	if (low < high) {

		// pi is Partitioning Index, arr[p] is now at
		// right place
		int pi =quickSortPartition(low, high);

		// Separately sort elements before and after the
		// Partition Index pi
		quickSort(low, pi - 1);
		quickSort( pi + 1, high);
	}
}

int ofApp::quickSortPartition(int low, int high) {
	// Selecting last element as the pivot
	int pivot = radii[high];

	// Index of elemment just before the last element
	// It is used for swapping
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {

		// If current element is smaller than or
		// equal to pivot
		if (radii[j] <= pivot) {
			i++;
			swap(i,j);
		}
	}

	// Put pivot to its position
	swap(i + 1, high);

	// Return the point of partition
	return (i + 1);
}

// Inspired by https://www.geeksforgeeks.org/merge-sort/
void ofApp::mergeSort(int left, int right) {
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, mid, right);
}

void ofApp::merge(int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// Create temp vectors
	vector<int> L(n1), R(n2);

	// Copy data to temp vectors L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = radii[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = radii[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;

	// Merge the temp vectors back 
	// into arr[left..right]
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			radii[k] = L[i];
			i++;
		}
		else {
			radii[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[], 
	// if there are any
	while (i < n1) {
		radii[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], 
	// if there are any
	while (j < n2) {
		radii[k] = R[j];
		j++;
		k++;
	}
}


void ofApp::swap(int i, int j) {
	int temp = this->radii[i];
	this->radii[i] = this->radii[j];
	this->radii[j] = temp;

}


// Fisher Yates Shuffle
// Inspired by https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
void ofApp::fisherYatesShuffle() {
	// Use a different seed value so that 
	// we don't get same result each time
	// we run this program 
	srand(time(NULL));

	// Start from the last element and swap 
	// one by one. We don't need to run for 
	// the first element that's why i > 0 
	for (int i = 4; i > 0; i--)
	{
		// Pick a random index from 0 to i 
		int j = rand() % (i + 1);

		// Swap arr[i] with the element 
		// at random index 
		swap(i,j);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
