/*
https://leetcode.com/problems/number-complement/description/
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
	int findComplement(int num) {
		if (num == 0){
			return 1;
		}
		int temp = num;
		int flag = 1;
		while (temp != 0){
			num = num^flag;
			temp = temp >> 1;
			flag = flag << 1;
		}
		return num;
	}
};

int main(){
	int num = 5;
	Solution s;
	cout << s.findComplement(num) << endl;
	system("pause");
	return 0;
}