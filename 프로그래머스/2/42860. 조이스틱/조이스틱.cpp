#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution(string name) {
	int answer = 0;
	int n = name.length();
	int min_move = n-1;
    
	for(int i=0; i<n; ++i) {
		answer += arr[name[i] - 'A'];

		// 이동 횟수 계산
		int next = i+1;

		while(next < n && name[next] == 'A') next++;

		min_move = min(min_move, i+n-next + min(i, n - next));
	}

	answer+=min_move;
	return answer;
}