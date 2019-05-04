#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
string str;
string sub1;
int N, flag;
char number[4] = { '0','1','2','3' };
bool possible(int n) {
	if (str.size() == 0) return true;
	int idx = str.size() - 1;
	int subsize = 1;
	while (1) {
		sub1 = str.substr(idx);
		if (idx - subsize < 0) break;
		if (str.substr(idx-subsize,subsize).find(sub1)!=-1) return false;
		idx--; subsize++;
	}
	return true;
}
void dfs(int length) {
	if (flag) return;
	if (length == N) {
		cout << str << endl;
		flag = true;
		return;
	}
	for (int i = 1; i < 4; i++) {
		str.push_back(number[i]);
		if (possible(i))
			dfs(length + 1);
		str.pop_back();
	}
}
int main() {
	cin >> N;
	dfs(0);
}