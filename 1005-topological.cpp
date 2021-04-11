#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;

/*
이번 문제는 그래프.
출력 가정에 의하면 비순환 그래프이며, 방향성이 존재하는 DAG 그래프.
DAG에서 도착점을 가정한 위 문제를 풀기 위해선 3가지 방법이 있는데

하나는 위상정렬
또 하나는 dfs or bfs
마지막으로는 다이나믹 프로그래밍... 동적계획법.
로직 공부를 위해 푸는 것이니 한번 모든 코드를 작성해보자.
3번은 프로그래밍 해봐야 알 것 같은데, 1번과 2번 모두 간선과 노드를 체크하므로 시간복잡도는 O(V+E)로 같다.

1, 위상정렬
위상정렬 알고리즘대로 사용하되, 여기에 추가적으로 건설 시간을 추가적으로 넣어줘야한다.
위상정렬은 전입차수를 이용하여 만들어진 그래프를 그대로 때려넣었다.
3개 코드 다하려고 하니까 메모리 신경 쓰기 싫어서 1001로 때려넣었다.
사실 그래프도 [1001][1001] 배열쓰고 싶었는데...그래도 프로그래머인데 모양새가 좀 그렇더라.
그래서 vector 썼다.
*/
 
int main() {
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        int structure, rule;
        cin >> structure >> rule;
 
        int times[1001] = { 0, };//시간
 
        for (int j = 1; j <= structure; j++)
        {
            cin >> times[j];//건설 시간
        }
 
        int start, dest;
        vector<int> g[1001];//그래프
        int indegree[1001] = { 0, };//전입차수
 
        for (int j = 0; j < rule; j++) {
            cin >> start >> dest;
            g[start].push_back(dest);
            indegree[dest]++;//그래프 형성
        }
 
        queue<int> q;
        long long totaltime[1001] = { 0, };//노드에 도착한 시간
 
        for (int j = 1; j <= structure; j++)
        {
            if (!indegree[j]) { q.push(j); totaltime[j] = times[j]; }
        }//가장 앞에 있는 노드 push
 
 
        int w;
        cin >> w;
 
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
 
            for (int next : g[cur]) {
                totaltime[next] = totaltime[next] > times[next] + totaltime[cur] ? totaltime[next] : times[next] + totaltime[cur];
 
                if (--indegree[next] == 0) q.push(next);
            }
        }
 
        cout << totaltime[w] << endl;
    }
 
    return 0;
}
