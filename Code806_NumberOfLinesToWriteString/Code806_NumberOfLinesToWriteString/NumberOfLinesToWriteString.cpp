/*
https://leetcode.com/problems/number-of-lines-to-write-string/description/
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	vector<int> numberOfLines(vector<int>& widths, string S) {
		vector<int>res;
		if (S.size() == 0){
			res.push_back(0);
			res.push_back(0);
			return res;
		}
		int line = 1;
		int num = 0;
		for (int i = 0; i < S.size(); i++){
			if (num + widths[S[i] - 'a']>100){
				line++;
				num = widths[S[i] - 'a'];
			}
			else{
				num = num + widths[S[i] - 'a'];
			}
		}
		res.push_back(line);
		res.push_back(num);
		return res;
	}
};

int main(){
	vector<int>widths = { 4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	string S = "bbbcccdddaaa";
	Solution s;
	vector<int>lines = s.numberOfLines(widths, S);
	cout << lines[0] << " " << lines[1] << endl;
	system("pause");
	return 0;
}