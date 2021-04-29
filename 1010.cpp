#include <iostream>
 
using namespace std;
 
int combination(int, int);
int dp[31][31]={0, };
 
int main(void){
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int n,m;
        cin >> n >> m;
        cout << combination(m, n) << endl;
    }
    
    return 0;
}
 
int combination(int n,int r){
    if(dp[n][r] != 0) return dp[n][r];
    if(r == 0 || r == n) return dp[n][r] = 1;
    
    return dp[n][r] = combination(n - 1, r) + combination(n - 1, r - 1);
}
