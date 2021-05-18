#include<bits/stdc++.h>
using namespace std;
int n, k;
int c[100][100];
void input() {
	cin >> n >> k;
	for (int i = 0; i <= 2 * n; i++) {
		for (int j = 0; j <= 2 * n; j++) {
			cin >> c[i][j];
		}
	}
}


