//https://www.acmicpc.net/problem/15657
#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] ={0, }, list[MAX] ={0, };
void dfs(int num, int cnt){
    //Base Condition
    if(cnt == m){
        for(int i=0; i<m; ++i)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    //Recursion Func
    for(int i=num; i<n; ++i){
        arr[cnt] = list[i];
        dfs(i, cnt+1);
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> list[i];

    sort(list, list+n);
    dfs(0, 0);
    return 0;
}