/*
https://leetcode.com/problems/smallest-range-i/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		if (A.size() == 0){
			return 0;
		}
		int maxValue = INT_MIN;
		int minValue = INT_MAX;
		for (int i = 0; i < A.size(); i++){
			maxValue = max(maxValue, A[i]);
			minValue = min(minValue, A[i]);
		}
		return (maxValue - minValue)>2 * abs(K) ? (maxValue - minValue - 2 * abs(K)) : 0;
	}
};

int main(){
	vector<int>A = { 1, 3, 6 };
	Solution s;
	int val = s.smallestRangeI(A, 3);
	cout << val << endl;
	system("pause");
	return 0;
}