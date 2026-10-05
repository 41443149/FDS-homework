#include<iostream>
#include <string>
using namespace std;
void powerset(int index, string s, string used, int len) {
	if (used.size()==len) {
		if (used != "") cout << ", ";
		cout << "(";
		for (int i = 0; i < used.size(); i++) {
			cout << used[i];
			if (i + 1 < used.size()) cout << ", ";
		}
		cout << ")";
		return;//要中斷,不return會當機
	}
	if (index == s.size())
		return;//如果used.size()==len沒有成立就中斷
	powerset(index + 1, s, used + s[index], len);//選當前字母的呼叫函示放前面
	powerset(index + 1, s, used, len);//不選當前字母的呼叫函示放後面
}
int main() {
	int index = 0;
	string s,used="";
	cout << "輸入集合的內容:";
	cin >> s;
	cout << "Powerset (S)= {";
	for (int len = 0; len <= s.size(); len++) {//用len讓子集合每種個數由小輸出到大
		powerset(index, s, used, len);
	}
	cout<<"}." << endl;
	return 0;
}
