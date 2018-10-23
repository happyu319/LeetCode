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
			int mid = (left + right) / 2;
			if (A[mid]<A[mid - 1]){
				right = mid - 1;
			}
			else if (A[mid] < A[mid + 1]){
				left = mid + 1;
			}
			else{
				return mid;
			}
		}
		return left;
	}
};

int main(){
	vector<int>arr = { 18, 29, 38, 59, 98, 100, 99, 98, 90 };
	Solution s;
	cout << s.peakIndexInMountainArray(arr) << endl;
	system("pause");
	return 0;
}