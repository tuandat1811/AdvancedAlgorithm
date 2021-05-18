#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6+1;
//khai bao bien nho hon 10^6
int a[MAX];
int s[MAX];
int n;
int sol;

void input(){
	cin>>n;
	for (int i = 1; i <= n ;i++){
		cin>>a[i];
		//input nhap vao
	}
}

void solve(){
	s[1] = a[1];
	sol= s[1];
	for (int i = 2; i<=n ; i++){
		if (s[i-1]>0) s[i] = s[i-1]+ a[i];
		else s[i]= a[i];
	sol = max(sol, s[i]);
	}
	cout << sol <<endl;
}
int main(){
	input();
	solve();
	return 0;
}

