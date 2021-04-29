#include <iostream>
#include <cmath>
 
using namespace std;
 
int main(void){
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;
        
        int d = y - x;
        int max_k = (int)sqrt(d);
        
        if(sqrt(d) == max_k){
            cout << 2 * max_k - 1 << endl;
        }else if(d <= max_k * max_k + max_k) {
            cout << 2 * max_k << endl;
        }else
            cout << 2 * max_k + 1 << endl;
    }
    
    return 0;
}
