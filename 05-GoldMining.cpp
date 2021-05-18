#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
int n, L1, L2;
int a[MAX];
int F[MAX]; //tong luong vang lon nhat duoc chon 
int ans = -1;
deque<int> d;
void input() {
	cin >> n >> L1 >> L2;
	for (int i = 1; i <= n;i++) {
		cin >> a[i];
	}
}

void solve() {
	for (int i = 1;i <= n;i++) {
		while (!d.empty() && d.front() < i - L2) d.pop_front();
		if (i - L1 > 0) {
			while (!d.empty() && F[d.back()] < F[i - L1]) d.pop_back();
			d.push_back(i - L1);
		}
		F[i] = a[i] + d.empty() ? 0 : F[d.front()];
		ans = max(ans, F[i]);
	}
	cout << ans << endl;
}
int main()
{
	input();
	solve();
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAX = 1e6 + 10;
//int n, L1, L2;
//int a[MAX];
//int F[MAX]; //tong luong vang lon nhat duoc chon 
//int ans = -1;
//void input() {
//	cin >> n >> L1 >> L2;
//	for (int i = 1; i <= n;i++) {
//		cin >> a[i];
//	}
//}
//
//void solve() {
//	for (int i = 1;i <= n;i++) {
//		F[i] = a[i];
//	}
//	for (int i = L1 + 1; i <= n;i++) {
//		for (int j = i - L2; j <= i - L1; j++) {
//			if (j > 0) {
//				F[i] = max(F[i], F[j] + a[i]);
//			}
//		}
//	}
//	for (int i = 1; i <= n;i++) {
//		ans = max(ans, F[i]);
//	}
//	cout << ans << endl;
//}
//int main()
//{
//	input();
//  solve();
//	return 0;
//}
//
