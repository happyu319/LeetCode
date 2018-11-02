/*
https://leetcode.com/problems/nim-game/description/
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	bool canWinNim(int n) {
		return n % 4 != 0;
	}
};

int main(){
	int n = 71;
	Solution s;
	cout << s.canWinNim(n) << endl;
	system("pause");
	return 0;
}