// binarysearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool isValueInVector_binarySearch(int value, vector<int> &v) {
	int low = 0;
	int high = v.size() -1;
	int medium;
	while (true) {
		if (value > v[high] || value < v[low]) {
			return false;
		}
		medium = (high + low) / 2;
		cout << v[medium] << " ";
		if (medium == high || medium == low) {
			if (value == v[high] || value == v[low]) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (value == v[medium]) {
			return true;
		}
		else if (value > v[medium]) {
			low = medium;
		}
		else {
			high = medium;
		}
	}
}

int main()
{
    
	vector<int> v;
	for (int i = 0; i < 100; ++i) {
		v.push_back(i);
	}
	cout << "Result: " << isValueInVector_binarySearch(20, v) << endl;
	return 0;
}

