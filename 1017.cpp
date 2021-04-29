#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> firstEqual, firstDifferent, match, visited;
vector<int> adj[25];
 
 
bool DFS(int, int);
 
int main(void) {
    int n, first;
 
    cin >> n;
 
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
 
        if (i == 0) first = k;
 
        if (k % 2 == first % 2) firstEqual.push_back(k);
        else firstDifferent.push_back(k);
    }
 
    if (firstEqual.size() != firstDifferent.size()) {
        cout << -1 << endl;
        return 0;
    }
 
    vector<bool> checkPrime = vector<bool>(1001, true);
 
    for (int i = 3; i < 2000; i+=2) {
        if (!checkPrime[i / 2]) continue;
 
        for (int j = i * i; j <= 2000; j += i * 2)
            checkPrime[j / 2] = false;
    }
 
    for (int i = 0; i < firstEqual.size(); i++)
        for (int j = 0; j < firstDifferent.size(); j++)
            if (checkPrime[(firstEqual[i] + firstDifferent[j]) / 2]) adj[i].push_back(j);
 
    
    vector<int> result;
 
    for (int i : adj[0]) {
        int maxMatch = 1;
        int cnt = 0;
        visited = vector<int>(25, 0);
        match = vector<int>(25, -1);
        match[i] = 0;
 
        for (int j = 0; j < firstEqual.size(); j++) {
            visited[0] = ++cnt;
            if (DFS(j, cnt)) maxMatch++;
        }
 
        if (maxMatch == firstDifferent.size()) result.push_back(firstDifferent[i]);
    }
 
    if (result.empty()) cout << -1 << endl;
    else {
        sort(result.begin(), result.end());
        for (int connect : result) {
            if (connect == result.back()) cout << connect << endl;
            else cout << connect << " ";
        }
    }
 
    return 0;
}
 
bool DFS(int i, int cnt)
{
    if (visited[i] == cnt) return false;
 
    visited[i] = cnt;
 
    for (int next : adj[i])
        if (match[next] == -1 || DFS(match[next], cnt)) {
            match[next] = i;
            return true;
        }
 
    return false;
}
