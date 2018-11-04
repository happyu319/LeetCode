/*
https://leetcode.com/problems/number-of-recent-calls/description/
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

class RecentCounter {
public:
	vector<int>cmd;
	RecentCounter() {
		cmd.clear();
	}

	int ping(int t) {
		cmd.push_back(t);
		int i = 0;
		for (i = 0; i<cmd.size(); i++){
			if (cmd[i] <= t&& cmd[i] >= t - 3000){
				break;
			}
		}
		return cmd.size() - i;
	}
};

int main(){
	RecentCounter r;
	cout << r.ping(1) << endl;
	cout << r.ping(100) << endl;
	cout << r.ping(3001) << endl;
	cout << r.ping(3002) << endl;
	system("pause");
	return 0;
}