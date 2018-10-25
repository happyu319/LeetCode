/*
https://leetcode.com/problems/shortest-distance-to-a-character/description/
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
	vector<int> shortestToChar(string S, char C) {
		vector<int>distance;
		int prePos = INT_MAX;//左标志
		int curPos = S.find(C, 0);//右标志
		for (int i = 0; i < S.size(); i++){
			if (i <= curPos){
				distance.push_back(min(abs(prePos - i), abs(curPos - i)));
			}
			else{
				prePos = curPos;
				if (S.find(C, i) != string::npos){
					curPos = S.find(C, i);
				}
				else{//最后一个单词
					curPos = INT_MAX;
				}
				i--;
			}			
		}
		return distance;
	}
};

int main(){
	string str = "loveleetcode";
	char ch = 'e';
	Solution s;
	vector<int>distance = s.shortestToChar(str, ch);
	for (int i = 0; i < distance.size(); i++){
		cout << distance[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

/*-------LeetCode代码
class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		int left_flag = INT_MAX;
		vector<int> res;
		int dist;

		for (int i = 0; i < S.size(); i++) {
			dist = 0;
			if (S[i] == C) {//更新左标志
				res.push_back(dist);
				left_flag = i;
				continue;
			}
			for (int j = i; j < S.size(); j++){
				if (S[j] == C) {
					res.push_back(min(dist, abs(i - left_flag)));
					break;
				}
				//can't find in last word
				if (j == (S.size() - 1)) {
					res.push_back(i - left_flag);
					break;
				}
				dist++;
			}
		}
		return res;
	}
};*/