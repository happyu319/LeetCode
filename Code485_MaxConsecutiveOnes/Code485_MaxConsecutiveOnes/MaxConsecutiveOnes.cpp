/*
https://leetcode.com/problems/max-consecutive-ones/description/
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
	int findMaxConsecutiveOnes(vector<int>& nums) {
		if (nums.empty()){
			return 0;
		}
		int maxOne = 0;
		int temp = 0;
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] & 1){
				temp++;
			}
			else{
				maxOne = max(maxOne, temp);
				temp = 0;
			}
		}
		maxOne = max(maxOne, temp);
		return maxOne;
	}
};

int main(){
	vector<int>nums = { 1, 1, 0, 1, 1, 1 };
	Solution s;
	cout << s.findMaxConsecutiveOnes(nums) << endl;
	system("pause");
	return 0;
}