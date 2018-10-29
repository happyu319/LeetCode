/*
https://leetcode.com/problems/distribute-candies/description/
*/
#include <iostream>
#include <vector>
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
	int distributeCandies(vector<int>& candies) {
		unordered_map<int, int>kinds;
		for (int i = 0; i < candies.size(); i++){
			kinds[candies[i]]++;
		}
		return kinds.size() <= candies.size() / 2 ? kinds.size() : candies.size() / 2;
	}
};

int main(){
	vector<int>candies = { 1, 1, 2, 3 };
	Solution s;
	cout << s.distributeCandies(candies) << endl;
	system("pause");
	return 0;
}