#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
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
        vector<int> g[1001];//전입차수가 필요가 없다.
 
        for (int j = 0; j < rule; j++) {
            cin >> start >> dest;
            g[dest].push_back(start);
        }
 
        queue<int> q;
        long long totaltime[1001] = { 0, };//노드에 도착한 시간
 
        int w, result = 0;
        cin >> w;
        q.push(w);//목적지를 넣고
        totaltime[w] = times[w];
 
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
 
            if (g[cur].empty()) {
                result = result < totaltime[cur] ? totaltime[cur] : result;
            }//간선이 없을 때
 
            for (int next : g[cur]) {
                if (totaltime[next] < times[next] + totaltime[cur]) {
                    totaltime[next] = times[next] + totaltime[cur];
                    q.push(next);
                }//갱신해도 될 때
            }
        }//bfs
 
        cout << result << endl;
    }
 
    return 0;
}
