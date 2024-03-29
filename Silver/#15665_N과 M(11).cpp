//https://www.acmicpc.net/problem/15665
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[8], ans[8];

void func(int cnt){
	if(cnt == m){
		for(int i=0; i<m; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	int preNum = -1;
	for(int i=0; i<n; ++i){
		if(arr[i]!=preNum){
			ans[cnt] = arr[i];
			preNum = ans[cnt];
			func(cnt+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; ++i)
		cin >> arr[i];
	sort(arr, arr+n);

	func(0);
	return 0;
}
