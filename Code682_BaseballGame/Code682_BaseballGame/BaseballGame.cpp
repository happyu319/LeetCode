/*
https://leetcode.com/problems/baseball-game/description/
*/
#include <iostream>
#include <vector>
#include <stack>
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
	int calPoints(vector<string>& ops) {
		if (ops.empty()){
			return 0;
		}
		stack<int>points;
		int sum = 0;
		for (int i = 0; i < ops.size(); i++){
			if (ops[i] == "C"){
				sum = sum - points.top();
				points.pop();
				continue;
			}
			else if (ops[i] == "D"){
				points.push(points.top() * 2);
			}
			else if (ops[i] == "+"){
				int temp1 = points.top();
				points.pop();
				int temp2 = points.top();
				points.push(temp1);
				points.push(temp1 + temp2);
			}
			else{
				points.push(stoi(ops[i]));
			}
			sum = sum + points.top();
		}
		return sum;
	}
};

int main(){
	vector<string>ops = { "5", "-2", "4", "C", "D", "9", "+", "+" };
	Solution s;
	cout << s.calPoints(ops) << endl;
	system("pause");
	return 0;
}