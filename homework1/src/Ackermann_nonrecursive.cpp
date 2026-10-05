#include<iostream>
using namespace std;
long long ack_non(long long m, long long n) {
	long long stk[100000];
	int top = 0;
	stk[top++] = m;//把m放入堆疊
	while (top > 0) {//還有m就繼續算
		int top_m = stk[--top];//把最上面的m拿出來
		if (top_m == 0) n += 1;//m=0時n+1
		else if (n == 0) {//m>0和n=0時m-1,n=1
			stk[top++] = top_m - 1;
			n = 1;
		}
		else {//m>0和n>0時a(m-1,a(m,n-1))
			stk[top++] = top_m - 1;
			stk[top++] = top_m;
			n -= 1;
		}
	}
	return n;//全部算完之後回傳
}

int main() {
	long long m, n;
	cout << "輸入m,n: ";
	cin >> m >> n;
	cout << "Ackermann function nonrecursive:(" << m << "," << n << ")=" << ack_non(m, n);
	return 0;
}
