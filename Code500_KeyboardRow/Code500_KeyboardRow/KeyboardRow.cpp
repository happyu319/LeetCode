/*
https://leetcode.com/problems/keyboard-row/description/
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

vector<string>keyboard = { "qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM" };

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string>keyboardWords;
		if (words.empty()){
			return keyboardWords;
		}
		for (int i = 0; i < words.size(); i++){
			int flag[3] = { 0 };
			for (int j = 0; j < words[i].size(); j++){
				if (flag[0] + flag[1] + flag[2] > 1){
					break;
				}
				if (keyboard[0].find(words[i][j]) != string::npos){
					flag[0] = 1;
					continue;
				}
				if (keyboard[1].find(words[i][j]) != string::npos){
					flag[1] = 1;
					continue;
				}
				if (keyboard[2].find(words[i][j]) != string::npos){
					flag[2] = 1;
					continue;
				}
			}
			if (flag[0] + flag[1] + flag[2] == 1){
				keyboardWords.push_back(words[i]);
			}
		}
		return keyboardWords;
	}
};

int main(){
	vector<string>words = { "Hello", "Alaska", "Dad", "Peace" };
	Solution s;
	vector<string>result = s.findWords(words);
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
	system("pause");
	return 0;
}