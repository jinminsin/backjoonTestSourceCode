#include <iostream>
#include <cmath>
using namespace std;
 
int coordinate[2][20];
void combination(int, int, int);
double result;
bool visited[20] = { false, };
 
int main(void) {
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        result = 300000;
 
        for (int j = 0; j < c; j++)
            cin >> coordinate[0][j] >> coordinate[1][j];
 
        combination(0, c, c / 2);
        cout << fixed;
        cout.precision(12);
        cout << result << endl;
    }
    
    return 0;
}
 
void combination(int idx, int n, int r) {
    if (r == 0)
    {
        double x_sum = 0;
        double y_sum = 0;
 
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                x_sum += coordinate[0][i];
                y_sum += coordinate[1][i];
            }
            else {
                x_sum -= coordinate[0][i];
                y_sum -= coordinate[1][i];
            }
        }
 
        result = min(result, sqrt(x_sum * x_sum + y_sum * y_sum));
        return;
    }
    if (idx == n)
        return;
 
    visited[idx] = true;
    combination(idx + 1, n, r - 1);
 
    visited[idx] = false;
    combination(idx + 1, n, r);
}
