/*
A heap is a complete binary tree whose
nodes all have the property that
they are less than both their children
and less than any node below.

A binary tree is a graph with a root node
and whose every node has 0, 1, or 2 children.

A complete binary tree means that every row,
except possibly the last, of a binary tree is 
complete.

Heaps support adding, removing, and 
altering.
*/

#include <iostream>
#include <fstream>
#include <math.h>

// must be at least 2 larger than the 
// number of elements in order
// to support 1-indexing AND adding
#define MAX_N 11 

using namespace std; 

int N;
int heap[MAX_N];

void displayHeap(int heap[], int size);
string determineSpace(int maxCol, int row);
void heap_insert(int heap[], int index, int element);
void heap_remove(int heap[], int index);

int main() {
	ifstream fin("heap.in");
	fin >> N; 
	for (int i = 1; i <= N; i++) { // it is easier to one index
		fin >> heap[i];
	}

	cout << "Here's the initial state: \n\n";
	displayHeap(heap, N);

	cout << "\nNow, input a number to add into the heap: "; 
	cin >> heap[N + 1];

	cout << "\nHere's what it looks like before any swapping: \n\n";
	displayHeap(heap, N + 1);

	cout << "\n\nHere's what it looks like after the swapping: \n\n";
	heap_insert(heap, N + 1, heap[N + 1]);
	displayHeap(heap, N + 1);

	cout << "\nNow, input a number to remove from the heap: ";
	int remove;
	cin >> remove;

	cout << "\nStart by replacing the element to remove with the last element in the heap \n\n";
	
	int last = heap[N + 1], index; 

	for (int i = 1; i <= N + 1; i++) {
		if (heap[i] == remove) {
			heap[i] = last; 
			index = i;
			heap[N + 1] = 10000000; 
			break;
		}
	}

	displayHeap(heap, N);

	cout << "\n\nNext, propagate the last element downwards: \n\n";
	heap_remove(heap, index);
	displayHeap(heap, N);
	return 0;
}

void displayHeap(int heap[], int size) {
	// the depth is the ceiling of log base 2 of size
	int depth = int(ceil(log2(size)));
	int count = 1;

	for (int row = 0; row < depth; row++){
		// print initial space
		for (int i = 0; i < pow(2, depth - row - 1) + 1; i++)
			cout << " ";


		for (int i = 0; i < pow(2, row) && count <= size; i++) {
			cout << heap[count];

			// print out the intermediate spaces (should get smaller 
			// towards bottom)
			for (int j = 0; j < pow(2, depth - row); j++)
				cout << " ";

			if (row == 1 || row == 0) 
				// pad a little bit more to compensate
				// for the two digit numbers in the heap
				cout << "   "; 

			count++;
		}
		cout << "\n";
	}
}

void heap_insert(int heap[], int index, int element){
	while (heap[index] < heap[int(floor(index / 2))]) {
		int t = heap[int(floor(index / 2))]; 
		heap[int(floor(index / 2))] = heap[index];
		heap[index] = t;

		index = int(floor(index / 2));
	}
}

void heap_remove(int heap[], int index) {
	// normally, this method 
	// would include the switch step, 
	// but that is already performed
	// in the main body loop.
	while (heap[index] > heap[2*index] ||
	 	   heap[index] > heap[2*index+1]) {
		int t = heap[index];
		int swapIndex = (heap[2*index] < heap[2*index + 1]) ?
		                2*index : 2*index + 1;
		heap[index] = heap[swapIndex];
		heap[swapIndex] = t;
	}
}
