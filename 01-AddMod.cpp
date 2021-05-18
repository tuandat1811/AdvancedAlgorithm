#include <bits/stdc++.h>
using namespace std;
const unsigned long long MAX = 1e9 + 7;
int main() {
	unsigned long long a, b, ans;
	cin >> a >> b;
	//ans = (a + b);//% MAX;
	a = a % MAX;
	b = b % MAX;
	ans = (a + b) % MAX;
	std::cout << ans << endl;
}