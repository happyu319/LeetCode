/*
https://leetcode.com/problems/next-greater-element-i/description/
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
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int>nextGreater;
		vector<int>::iterator it;
		for (it = findNums.begin(); it != findNums.end(); it++){
			vector<int>::iterator iter = find(nums.begin(), nums.end(), *it);
			int num = *iter;
			int flag = true;
			while (iter != nums.end()){
				num = max(num, *iter++);
				if (num != *it){
					nextGreater.push_back(num);
					flag = false;
					break;
				}
			}
			if (flag){
				nextGreater.push_back(-1);
			}
		}
		return nextGreater;
	}
};
/*------------------LeetCodeÃ‚Ω‚
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		stack<int> s;
		unordered_map<int, int> m;
		vector<int> res;
		for (int num : nums){
			while (!s.empty() && s.top() < num){
				m[s.top()] = num;
				s.pop();
			}
			s.push(num);
		}
		for (int num : findNums){
			res.push_back(m.count(num) ? m[num] : -1);
		}
		return res;
	}
};*/

int main(){
	vector<int>nums1 = { 3, 1, 5, 7, 9, 2, 6 };
	vector<int>nums2 = { 1, 2, 3, 5, 6, 7, 9, 11 };
	Solution s;
	vector<int>nums = s.nextGreaterElement(nums1, nums2);
	for (int i = 0; i < nums.size(); i++){
		cout << nums[i] << endl;
	}
	system("pause");
	return 0;
}