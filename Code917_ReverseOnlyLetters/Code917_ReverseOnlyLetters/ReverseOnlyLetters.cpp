/*
https://leetcode.com/problems/reverse-only-letters/description/
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	string reverseOnlyLetters(string S) {
		if (S.empty()){
			return S;
		}
		int left = 0;
		int right = S.size() - 1;
		while (left < right){
			if (!isalpha(S[left])){
				left++;
				continue;
			}
			if (!isalpha(S[right])){
				right--;
				continue;
			}
			swap(S[left++], S[right--]);
		}
		return S;
	}
};

int main(){
	string str1 = "ab-cd";
	string str2 = "a-bC-dEf-ghIj";
	string str3 = "Test1ng-Leet=code-Q!";
	Solution s;
	cout << str1 << " " << s.reverseOnlyLetters(str1) << endl;
	cout << str2 << " " << s.reverseOnlyLetters(str2) << endl;
	cout << str3 << " " << s.reverseOnlyLetters(str3) << endl;
	system("pause");
	return 0;
}