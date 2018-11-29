/*
https://leetcode.com/problems/reorder-log-files/
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();


/*-------------------leetcode
bool myCompare(string a, string b){
	int i = a.find(' ');
	int j = b.find(' ');
	if(!isdigit(a[i + 1]) && !isdigit(b[j + 1]))
		return a.substr(i + 1) < b.substr(j + 1);
	else{
		if(!isdigit(a[i + 1])) 
			return true;
		return false;
	}
}
class Solution {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		stable_sort(logs.begin(), logs.end(), myCompare);
		return logs;
	}
}
*/

class Solution {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		if (logs.size() <= 1){
			return logs;
		}
		vector<string>letters;
		vector<string>digits;
		for (int i = 0; i < logs.size(); i++){
			if (isalpha(logs[i][logs[i].find(' ') + 1])){
				letters.push_back(logs[i]);
			}
			else{
				digits.push_back(logs[i]);
			}
		}
		for (int i = letters.size() - 1; i>0; i--){
			for (int j = 0; j < i; j++){
				string str1 = letters[j].substr(letters[j].find(' ') + 1);
				string str2 = letters[j + 1].substr(letters[j + 1].find(' ') + 1);
				if (str1>str2){
					string temp = letters[j];
					letters[j] = letters[j + 1];
					letters[j + 1] = temp;
				}
			}
		}
		letters.insert(letters.end(), digits.begin(), digits.end());
		return letters;
	}
};

int main(){
	vector<string>logs = { "a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo" };
	Solution s;
	vector<string>res = s.reorderLogFiles(logs);
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << endl;
	}
	system("pause");
	return 0;
}