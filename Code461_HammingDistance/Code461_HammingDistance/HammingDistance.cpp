/*
https://leetcode.com/problems/hamming-distance/description/
*/
#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
	int bit = x^y;
	int distance = 0;
	while (bit != 0){
		if (bit & 1){
			distance++;
		}
		bit = bit >> 1;
	}
	return distance;
}

int main(){
	unsigned int x, y;
	cin >> x >> y;
	cout << hammingDistance(x, y) << endl;
	system("pause");
	return 0;
}