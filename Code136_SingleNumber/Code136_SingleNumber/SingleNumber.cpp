/*
https://leetcode.com/problems/single-number/description/
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
	int singleNumber(vector<int>& nums) {
		if (nums.empty()){
			return 0;
		}
		int num = 0;
		for (int i = 0; i < nums.size(); i++){
			num = num^nums[i];
		}
		return num;
	}
};

int main(){
	vector<int>nums = { 2, 2, 1 };
	Solution s;
	cout << s.singleNumber(nums) << endl;
	system("pause");
	return 0;
}