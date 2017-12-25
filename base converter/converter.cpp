#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() { 
	string s; 
	int accum = 0;

	cin >> s; 
	for (int i = 0; i < s.length(); i++) { 
		accum += stoi(s.substr(i, 1)) * pow(2, s.length() - i - 1);
	}

	cout << accum << endl;
	return 0;
}