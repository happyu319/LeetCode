/*
https://leetcode.com/problems/uncommon-words-from-two-sentences/description/
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
	vector<string> uncommonFromSentences(string A, string B) {
		string str = A + " " + B;
		unordered_map<string, int>words;
		int pos = 0;
		while(true){
			if (str.find(" ", pos) != string::npos){
				int len = str.find(" ", pos) - pos;
				words[str.substr(pos, len)]++;
				pos = pos + len + 1;
			}
			else{
				words[str.substr(pos)]++;
				break;
			}
		}
		vector<string>result;
		unordered_map<string, int>::iterator it;
		for (it = words.begin(); it != words.end(); it++){
			if (it->second == 1){
				result.push_back(it->first);
			}
		}
		return result;
	}
};

int main(){
	string A = "this apple is sweet";
	string B = "this apple is sour";
	Solution s;
	vector<string>words = s.uncommonFromSentences(A, B);
	for (int i = 0; i < words.size(); i++){
		cout << words[i] << endl;
	}
	system("pause");
	return 0;
}