/*
https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
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
	string reverseWords(string s) {
		if (s.size() == 0){
			return s;
		}
		int pos = 0;
		while (pos < s.size()){
			if (s.find(" ", pos) == string::npos){
				reverse(s.begin() + pos, s.end());
				break;
			}
			int len = s.find(" ", pos) - pos;
			reverse(s.begin() + pos, s.begin() + pos + len);
			pos = s.find(" ", pos) + 1;
		}
		return s;
	}
};

int main(){
	string str = "Let's  take LeetCode contest";
	Solution s;
	cout << s.reverseWords(str) << endl;
	system("pause");
	return 0;
}