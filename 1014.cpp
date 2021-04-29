#include <iostream>
#include <vector>
 
using namespace std;
#define MAPLINE 10
#define MAPSIZE 100
 
int possible[6][2] = { 
    {-1, -1},
    {0, -1},
    {1, -1},
    {-1, 1},
    {0, 1},
    {1, 1} 
};
 
vector<int> *adj, match;
vector<int> visited;
bool DFS(int,int);
 
int main() {
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++) {
        int n, m, impossible = 0;
        char b;
 
        cin >> n >> m;
        
        int map[MAPLINE][MAPLINE] = { 0, };
        bool crash[MAPLINE][MAPLINE] = { false, };
        int number = 0;
        adj = new vector<int>[MAPSIZE / 2 + 1];
 
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> b;
 
                if (b == 'x') {
                    impossible++;
                    crash[j][k] = true;
                }
                
                if (k % 2 == 0)
                    map[j][k] = ++number;
                else
                    map[j][k] = number;
            }
        }
 
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k+=2) {
                if (crash[j][k]) continue;
 
                for (int d = 0; d < 6; d++) {
                    int next[2] = { j + possible[d][0], k + possible[d][1] };
                    if (next[0] < 0 || next[0] >= n || next[1] < 0 || next[1] >= m || crash[next[0]][next[1]]) continue;
 
                    adj[map[j][k]].push_back(map[next[0]][next[1]]);
                }
            }
        }
 
        int maxMatch = 0;
        int cnt = 0;
        match = vector<int>(MAPSIZE / 2 + 1, -1);
        visited = vector<int>(MAPSIZE / 2 + 1, -1);
 
        for (int l = 1; l <= number;l++) {
            if (DFS(l,++cnt)) maxMatch++;
        }
 
        cout << n * m - impossible - maxMatch << endl;
    }
}
 
bool DFS(int i,int cnt)
{
    if (visited[i] == cnt) return false;
 
    visited[i] = cnt;
 
    for (int next : adj[i])
        if (match[next] == -1 || DFS(match[next],cnt)) {
            match[next] = i;
            return true;
        }
 
    return false;
}
