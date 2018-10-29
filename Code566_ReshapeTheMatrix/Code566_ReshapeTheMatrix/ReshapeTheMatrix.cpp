/*
https://leetcode.com/problems/reshape-the-matrix/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if (nums.empty()){
			return nums;
		}
		int oldR = nums.size();
		int oldC = nums[0].size();
		if (oldR*oldC != r*c){
			return nums;
		}
		vector<int>temp;
		for (int i = 0; i < nums.size(); i++){
			for (int j = 0; j < nums[i].size(); j++){
				temp.push_back(nums[i][j]);
			}
		}
		vector<vector<int>>newNums;
		for (int i = 0; i < r; i++){
			vector<int>tempNums;
			for (int j = 0; j < c; j++){
				tempNums.push_back(temp[i*c + j]);
			}
			newNums.push_back(tempNums);
			tempNums.clear();
		}
		return newNums;
	}
};

int main(){
	vector<vector<int>>nums = { { 1, 2 }, { 3, 4 } };
	int r = 1;
	int c = 4;
	Solution s;
	vector<vector<int>>newNums = s.matrixReshape(nums, r, c);
	for (int i = 0; i < newNums.size(); i++){
		for (int j = 0; j < newNums[i].size(); j++){
			cout << newNums[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}