#include <bits/stdc++.h>
using namespace std;
int n, b, res=-1;
const int MAX=2000002;
void solve(){
	cin >>n >>b;
	int a[MAX];
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	int l[MAX], r[MAX]; 
	l[0]=a[0];
	r[0]= a[n-1];
	for (int i=1 ; i<=n ; i++){
		if (l[i]>a[i+1]){
			l[i+1]= l[i];
		}
		else {
			l[i+1]=a[i+1];
		}
	}
	for (int i=n; i>0; i--){
		if (r[i]> a[i-1]){
			r[i-1]= r[i];
		}
		else{
			r[i-1]= a[i-1];
		}
	}
	for (int i=0 ; i < n; i++){
		if(l[i]- a[i]>=b && r[i]- a[i]>=b){
			if(res < (l[i]- a[i]+r[i]- a[i])){
				res = l[i]- a[i]+r[i]- a[i];
			}
		}
	}
	cout<<res;
}
int main(){
	solve();
}
