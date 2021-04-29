#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
vector<char> map[50];
int check(int, int);
 
int main(void) {
    int n, m;
    int result = 2500;
 
    cin >> n >> m;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char k;
            cin >> k;
            map[i].push_back(k);
        }
    }
 
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            result = min(result, check(i, j));
        }
    }
 
    cout << result << endl;
 
    return 0;
}
 
int check(int n, int m) {
    int answerFirstW = 0, answerFirstB = 0;//map[n][m] = W이어야 할 때의 답과, B이어야할 때의 답
 
    for (int i = n; i < n + 8; i++) {
        for (int j = m; j < m + 8; j++) {
            if ((i + j) % 2 == 0) {
                if (map[i][j] != 'W') answerFirstW++;
                else answerFirstB++;
            }
            else {
                if (map[i][j] != 'W') answerFirstB++;
                else answerFirstW++;
            }
        }
    }
 
    return min(answerFirstB, answerFirstW);
}
