#include <iostream>
#include <string>
#include <math.h>

#define BASE 16
 
using namespace std; 

string convertToLetter (int N) { 
	switch (N) { 
		case 10: 	return "A"; 
					break;
		case 11: 	return "B"; 
					break;
		case 12: 	return "C"; 
					break;
		case 13: 	return "D"; 
					break;
		case 14: 	return "E"; 
					break;
		case 15: 	return "F"; 
					break;
		default: 	return "";
					break;
	}
}

int main() { 
	int n, upperBound; // upperBound is the highest exponent you'll see
	string answer;

	cin >> n;

	upperBound = log(n) / log(BASE);

	for (int i = upperBound; i >= 0; i--) { 
		int d = n / pow(BASE, i);
		
		string s; 
		if (d >= 10) { 
			s = convertToLetter(d);
		} else { 
			s = to_string(d);
		}
		answer += s;
		n -= d * pow(BASE, i);
	}

	cout << answer << endl;

	return 0;
}