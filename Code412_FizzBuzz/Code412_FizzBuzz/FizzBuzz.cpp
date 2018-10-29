/*
https://leetcode.com/problems/fizz-buzz/description/
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
	vector<string> fizzBuzz(int n) {
		vector<string>str;
		if (n <= 0){
			return str;
		}
		for (int i = 1; i <= n; i++){
			int first = i % 3;
			int second = i % 5;
			if (first == 0 && second == 0){
				str.push_back("FizzBuzz");
			}
			else if (first == 0){
				str.push_back("Fizz");
			}
			else if (second == 0){
				str.push_back("Buzz");
			}
			else{
				str.push_back(to_string(i));
			}
		}
		return str;
	}
};

int main(){
	int n = 15;
	Solution s;
	vector<string>str = s.fizzBuzz(n);
	for (int i = 0; i < str.size(); i++){
		cout << str[i] << endl;
	}
	system("pause");
	return 0;
}