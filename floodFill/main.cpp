#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#define NUMBER_OF_NODES 9

using namespace std;

int N, componentCounter = 1; // number of edges
vector<int> adj[NUMBER_OF_NODES + 1];
int component[NUMBER_OF_NODES + 1];


void floodFill(int i) { // recursively add all connected nodes to the current component
	if (component[i] == 0) {
		component[i] = componentCounter;
		
		for (auto u : adj[i]) {
			floodFill(u);
		}
	}
}

int determineLargestComponent(int componentMapping[]) {
	multiset<int> componentSet; 
	for (int i = 1; i <= NUMBER_OF_NODES; i++)
		componentSet.insert(componentMapping[i]);

	// determine largest component (room)
	int currentLargestComponent = 0;
	for (int i = 1; i <= NUMBER_OF_NODES; i++) {
		if (componentSet.count(component[i]) > currentLargestComponent)
			currentLargestComponent = componentSet.count(component[i]);
	}
	return currentLargestComponent;
}

int determineNumberOfComponents(int componentMapping[]){
	set<int> uniqueComponents;
	for (int i = 1; i <= NUMBER_OF_NODES; i++)
		uniqueComponents.insert(componentMapping[i]);
	return uniqueComponents.size();
}

int main() {
	ifstream fin("graph.in");
	fin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		fin >> a >> b;
		adj[a].push_back(b);
	}
	fin.close();
	
	for (int i = 1; i <= NUMBER_OF_NODES; i++) {
		floodFill(i);
		componentCounter++;
	}

	for (int i = 1; i <= NUMBER_OF_NODES; i++) {
		cout << i << ": " << component[i] << endl;
	}
	

	cout << determineNumberOfComponents(component) << endl;
	cout << determineLargestComponent(component) << endl;

	return 0;
}
