/*
https://leetcode.com/problems/goat-latin/description/
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
	string toGoatLatin(string S) {
		if (S.empty()){
			return S;
		}
		vector<string>str;
		int pos = S.find(" ");
		while (pos != string::npos){
			str.push_back(S.substr(0, pos));
			S = S.substr(pos + 1);
			pos = S.find(" ");
		}
		str.push_back(S);
		string res;
		for (int i = 0; i < str.size(); i++){
			string temp = str[i].substr(0, 1);
			if (temp == "a" || temp == "e" || temp == "i" || temp == "o" || temp == "u" ||
				temp == "A" || temp == "E" || temp == "I" || temp == "O" || temp == "U"){
				str[i] = str[i] + "ma";
			}
			else{
				str[i] = str[i].substr(1) + temp + "ma";
			}
			for (int j = 0; j < i + 1; j++){
				str[i] = str[i] + "a";
			}
			res = res + str[i] + " ";
		}
		res = res.substr(0, res.size() - 1);
		return res;
	}
};

int main(){
	string str = "I speak Goat Latin";
	Solution s;
	cout << s.toGoatLatin(str) << endl;
	system("pause");
	return 0;
}