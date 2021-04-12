#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, structure, rule;
int coordinate[1001][1001];
int times[1001];//시간
long long memo[1001];
long long totaltime(int);

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		memset(coordinate, 0, sizeof(coordinate));//메모 초기화
		memset(memo, -1, sizeof(memo));//메모 초기화

		cin >> structure >> rule;

		for (int j = 1; j <= structure; j++)
		{
			cin >> times[j];//건설 시간
		}

		int start, dest;

		for (int j = 0; j < rule; j++) {
			cin >> start >> dest;
			coordinate[start][dest] = 1;
		}

		int w;
		cin >> w;
	
		cout << totaltime(w) << endl;
	}

	return 0;
}

long long totaltime(int cur) {
	if (memo[cur] != -1) return memo[cur];//저장되어 있을 경우 리턴
	long long cur_time = 0;
	for (int i = 1; i <= structure; i++)//이전 노드 모두 탐색
		if (coordinate[i][cur])
			cur_time = max(cur_time, totaltime(i));

	return memo[cur] = cur_time + times[cur];
}
