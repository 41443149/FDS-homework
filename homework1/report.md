# 41443149
### 題目一 阿克曼函數 (Ackermann Function)遞迴與非遞迴
## 解題說明
####1.問題描述: 本題要求用遞迴和非遞迴兩個方法做出阿克曼函數（Ackermann Function）的計算

####2.解題策略

1.__遞迴:__ 依照題目圖片公式

 - if m=0,n+1
 - if n=0,A(m-1,1)
 - else A(m-1,A(m,n-1))

2.__非遞迴:__ 建立資料存放區，再用變數top模擬pop,push的功能，接著用題目公式計算

## 程式實作
1.__遞迴程式碼__
```cpp
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
```

2.__非遞迴程式碼__
```cpp
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
```

## 效能分析
1.__時間複雜度:__ *O* ( A ( m,n ) )，遞迴與非遞迴相同

2.__空間複雜度:__ *O* ( A ( m,n ) )，雖然符號相同差異在遞迴有呼叫堆疊，非遞迴是手動堆疊
## 測試與驗證
| 測試案例 | 輸入參數 (m,n) | 預期輸出 | 實際輸出 |
|----------|--------------|----------|----------|
| 測試一   |   (0,0)      | 1        | 1        |
| 測試二   |   (1,3)      | 5        | 5        |
| 測試三   |   (2,2)      | 7        | 7        |
| 測試四   |   (3,4)      | 125      | 125      |

## 申論及開發報告
1.__遞迴:__ 用題目的公式就可以算出計算，程式碼精簡。但堆疊空間小可能會導致溢位。

2.__非遞迴:__ 需要自行生成空間處存m的值，再利用while迴圈計算n。堆疊效果比遞迴好。

### 題目二 冪集合(Powerset)
## 解題說明
1.問題描述:輸入一個集合，遞迴輸出所有子集合

2.解題策略:
 - 用主程式的for迴圈控制輸出的子集合長度由小到大排列
 - 執行powerset函式時先呼叫選當前字元的呼叫函式，在呼叫不選的函式
 - 完成目標長度時終止函式，或是已經輸出完目標長度的子集合時，但目標長度還沒輸出完時終止函式，進入下一組長度的子集合

## 程式實作
```cpp
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
```

## 效能分析
1.__時間複雜度:__ *O* ( n * 2^n ) 

2.__空間複雜度:__ *O* ( n )

## 測試與驗證
| 測試案例 | 輸入參數 S    | 預期輸出 | 實際輸出 |
|----------|--------------|----------|----------|
| 測試一   |   (a,b,c)    | (), (a), (b), (c), (a, b), (a, c), (b, c), (a, b, c) | (), (a), (b), (c), (a, b), (a, c), (b, c), (a, b, c) |
| 測試二   |   (a)        | (), (a)   | (), (a) |
| 測試三   |   (a,b)      |  (), (a), (b), (a, b)       | (), (a), (b), (a, b)        |

## 申論及開發報告
輸入集合S，寫出遞迴函式排列輸出冪集合(Powerset)。依照長度排序子集合方便觀看。透過主程式for迴圈排列好子集合。達到目標長度的話中止函式，輸出完同一長度的子集合但是還沒全部輸出完的話中止函式進入下一個子集合長度輸出。
