#include <iostream>
 
using namespace std;
 
int main(void) {
    long long min, max;
 
    cin >> min >> max;
 
    int result = max - min + 1;
    bool visited[1000001] = { false, };
 
    for (long long i = 2; i * i <= max; i++) {
        long long d = min % (i * i) ? min / (i * i) + 1 : min / (i * i);
 
        for (long long j = d; j * (i * i) <= max; j++)
        {
            if (!visited[j * i * i - min]) {
                visited[j * i * i - min] = true;
                result--;
            }
        }
    }
 
    cout << result << endl;
 
    return 0;
}
