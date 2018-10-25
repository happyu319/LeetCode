/*
https://leetcode.com/problems/subdomain-visit-count/description/
*/
#include <iostream>
#include <vector>
#include <string>
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
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		if (cpdomains.empty()){
			return cpdomains;
		}
		unordered_map<string, int>domains;
		vector<string>subdomains;
		for (int i = 0; i < cpdomains.size(); i++){
			int blank = cpdomains[i].find(" ");
			int visitNum = stoi(cpdomains[i].substr(0, blank));
			string domain = cpdomains[i].substr(blank + 1);
			while (domain.find(".") != string::npos){
				domains[domain] += visitNum;
				domain = domain.substr(domain.find(".") + 1);
			}
			domains[domain] += visitNum;
		}
		unordered_map<string, int>::iterator it;
		for (it=domains.begin(); it != domains.end(); it++){
			string temp = to_string(it->second);
			subdomains.push_back(temp + " " + it->first);
		}
		return subdomains;
	}
};

int main(){
	vector<string>cpdomains = { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
	Solution s;
	vector<string>domains = s.subdomainVisits(cpdomains);
	for (int i = 0; i < domains.size(); i++){
		cout << domains[i] << endl;
	}
	system("pause");
	return 0;
}