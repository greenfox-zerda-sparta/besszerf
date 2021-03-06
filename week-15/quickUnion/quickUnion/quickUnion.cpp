// quickUnion.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

class QuickUnion {

public:
	QuickUnion(int arrayLength);
	void unite(int index1, int index2);
	bool find(int index1, int index2);
	vector<vector<int>> getGroups();
	void printGroups();
private:
	vector<int> id;
	vector<int> sz;
	int root(int i);
	bool contains(vector<int> &v, int x);
};

QuickUnion::QuickUnion(int l) {
	for (int i = 0; i < l; ++i) {
		id.push_back(i);
	}
	sz = vector<int>(l, 0);
}

int QuickUnion::root(int i) {
	while (i != id[i]) {
		id[i] = id[id[i]];
		i = id[i];
	}
	return i;
}

bool QuickUnion::find(int index1, int index2) {
	return (root(index1) == root(index2));
}

void QuickUnion::unite(int index1, int index2) {
	if (sz[root(index1)] >= sz[root(index2)]) {
		sz[root(index1)] += sz[root(index2)];
		id[root(index2)] = root(index1);
	}
	else {
		sz[root(index2)] += sz[root(index1)];
		id[root(index1)] = root(index2);
	}
}

bool QuickUnion::contains(vector<int> &v, int x){
	return std::find(v.begin(), v.end(), x) != v.end();
}

vector<vector<int>> QuickUnion::getGroups() {
	vector<int> used;
	vector<vector<int>> groups;
	for (int i = 0; i < id.size(); ++i) {
		int rootOfi = root(i);
		if (!contains(used, i)) {
			vector<int> r;
			for (int j = i; j < id.size(); ++j) {
				int roofOfj = root(j);
				if (rootOfi == roofOfj) {
					r.push_back(j);
					used.push_back(j);
				}
			}
			groups.push_back(r);
		}
	}
	return groups;
}

void QuickUnion::printGroups()
{
	vector<vector<int>> v = getGroups();
	for (auto it : v) {
		for (auto ite : it) {
			cout << ite << " ";
		}
		cout << endl;
	}
}

int main()
{
	QuickUnion u(10);
	vector<vector<int>> connections = { { 3, 4 },{ 4, 9 },{ 8, 0 },{ 2, 3 },/*{ 5, 6 },{ 5, 9 },*/{ 7, 3 },{ 4, 8 },{ 6, 1 } };
	for (auto it : connections) {
		u.unite(it[0], it[1]);
	}
	cout << u.find(1, 3) << endl;
	cout << u.find(0, 4) << endl;
	u.printGroups();
	return 0;
}

