/*
https://leetcode.com/problems/longest-uncommon-subsequence-i/description/
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int findLUSlength(string a, string b) {
		if (a.size() > b.size()){
			return a.size();
		}
		if (a.size() < b.size()){
			return b.size();
		}
		if (a == b){
			return -1;
		}
		return a.size();
	}
};

int main(){
	string a = "aba";
	string b = "cdc";
	Solution s;
	cout << s.findLUSlength(a, b) << endl;
	system("pause");
	return 0;
}