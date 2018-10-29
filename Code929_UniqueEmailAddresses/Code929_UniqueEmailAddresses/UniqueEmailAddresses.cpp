/*
https://leetcode.com/problems/unique-email-addresses/description/
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		if (emails.empty()){
			return 0;
		}
		set<string>address;
		for (int i = 0; i < emails.size(); i++){
			int pos = emails[i].find("@");
			string local = emails[i].substr(0, pos);
			string domain = emails[i].substr(pos + 1);
			if (local.find("+")!=string::npos){
				local = local.substr(0, local.find("+"));
			}
			int index = local.find(".");
			while (index != string::npos){
				local = local.substr(0, index) + local.substr(index + 1);
				index = local.find(".", index);
			}
			address.insert(local + "@" + domain);
		}
		return address.size();
	}
};

int main(){
	vector<string>emails = { "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com" };
	Solution s;
	cout << s.numUniqueEmails(emails) << endl;
	system("pause");
	return 0;
}