#include <iostream>
 
using namespace std;
 
int c[10] = { 0, };
 
void calc(long long, long long);
 
int main() {
    long long last;
    long long start = 1;
    long long digit = 1;
 
    cin >> last;
 
    while (true) {
        while (start % 10 != 0 && start <= last) {
            calc(start, digit);
            start++;
        }
 
        if (start > last) break;// 탐색 중인 첫 페이지와 마지막 페이지가 같은 level에 있을 때
 
        while (last % 10 != 9) {
            calc(last, digit);
            last--;
        }
 
        start /= 10;
        last /= 10;
 
        long long d = last - start + 1;
 
        for (int i = 0; i < 10; i++) {
            c[i] += (d * digit);
        }
 
        digit *= 10;
    }
 
    for (int i = 0; i < 10; i++) {
        if (i == 9) cout << c[i] << endl;
        else cout << c[i] << " ";
    }
 
    return 0;
}
 
void calc(long long n, long long digit) {
    while (n > 0) {
        c[n % 10] += digit;
        n /= 10;
    }
}
