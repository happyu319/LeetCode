/*
https://leetcode.com/problems/binary-number-with-alternating-bits/description/
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
	bool hasAlternatingBits(int n) {
		if (n <= 0){
			return false;
		}
		int odd = 1;
		int even = 2;
		bool flag = true;
		while (n != 1){
			int first = odd&n;
			int second = even&n;
			second = second >> 1;
			if (first^second){
				n = n >> 1;
			}
			else{
				flag = false;
				break;
			}
		}
		return flag;
	}
};
/*
class Solution {
public:
	bool hasAlternatingBits(int n) {
		return !((n ^= n / 2) & (n + 1));
	}
};*/

int main(){
	int n = 10;
	Solution s;
	cout << s.hasAlternatingBits(n) << endl;
	system("pause");
	return 0;
}