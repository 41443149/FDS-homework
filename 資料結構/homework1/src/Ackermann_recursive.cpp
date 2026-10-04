#include<iostream>
using namespace std;
long long ack(long long m, long long n) {
	if (m == 0) return n + 1;
	else if (n == 0) return ack(m - 1, 1);
	else return ack(m - 1, ack(m, n - 1));
}
int main() {
	long long m, n;
	cout << "輸入m,n: ";
	cin >> m >> n;
	cout << "Ackermann function:(" << m << "," << n << ")=" << ack(m, n);
	return 0;
}
