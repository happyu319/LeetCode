/*
https://leetcode.com/problems/groups-of-special-equivalent-strings/description/
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int numSpecialEquivGroups(vector<string>& A) {
		if (A.empty()){
			return 0;
		}
		vector<vector<string>>str(A.size());
		unordered_map<string, int>nums;
		for (int i = 0; i < A.size(); i++){
			str[i].push_back("");
			str[i].push_back("");
			for (int j = 0; j < A[i].size(); j++){
				str[i][j % 2] = str[i][j % 2] + A[i][j];
			}
			sort(str[i][0].begin(), str[i][0].end());
			sort(str[i][1].begin(), str[i][1].end());
			nums[str[i][0] + str[i][1]]++;
		}
		return nums.size();
	}
};

int main(){
	vector<string>str = { "abc", "acb", "bac", "bca", "cab", "cba" };
	Solution s;
	cout << s.numSpecialEquivGroups(str) << endl;
	system("pause");
	return 0;
}