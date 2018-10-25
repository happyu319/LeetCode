/*
https://leetcode.com/problems/reverse-string/description/
*/
#include <iostream>
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
	string reverseString(string s) {
		if (s.size() == 0){
			return s;
		}
		for (int begin = 0, end = s.size() - 1; begin < end; begin++, end--){
			char temp = s[begin];
			s[begin] = s[end];
			s[end] = temp;
		}
		return s;
	}
};

int main(){
	string str = "A man, a plan, a canal: Panama";
	Solution s;
	cout << s.reverseString(str) << endl;
	system("pause");
	return 0;
}