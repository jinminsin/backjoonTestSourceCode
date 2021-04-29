#include <iostream>
#include <algorithm>
 
using namespace std;
 
pair <int,int> a[50];
 
int main(void) {
    int n;
    int p[50];
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> a[i].first; a[i].second = i;
    }
 
    sort(a, a + n);
 
    for (int i = 0; i < n; i++ ) p[a[i].second] = i;
 
    for (int i = 0; i < n - 1; i++)
        cout << p[i] << " ";
 
    cout << p[n - 1] << endl;
 
    return 0;
}
