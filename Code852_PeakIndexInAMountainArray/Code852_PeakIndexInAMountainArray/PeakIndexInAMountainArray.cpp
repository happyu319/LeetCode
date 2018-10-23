/*
https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		if (A.size() < 3){
			return 0;
		}
		int left = 0;
		int right = A.size() - 1;
		while (left < right){
		}
	}
};

int main(){
	vector<int>arr = { 1, 2, 1, 0 };
	Solution s;
	cout << s.peakIndexInMountainArray(arr) << endl;
	system("pause");
	return 0;
}