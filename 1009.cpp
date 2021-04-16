#include <iostream>
#include <vector>
using namespace std;
 
vector<int> d[10] = {
    {10},
    {1},
    {6,2,4,8},
    {1,3,9,7},
    {6,4},
    {5},
    {6},
    {1,7,9,3},
    {6,8,4,2},
    {1,9}
};
 
int main(void) {
    int t; 
    cin >> t;
 
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int digit = a % 10;
        cout << d[digit][b % d[digit].size()] << endl;
    }
    return 0;
}
