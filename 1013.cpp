#include <iostream>
#include <string>
 
using namespace std;
 
int state[8][2] = {
    {0,0},
    {2,3},//1
    {0,4},//2
    {5,0},//3
    {2,3},//4//final
    {6,0},//5
    {6,7},//6
    {2,7},//7//final
};
 
string str;
string compiler(int);
 
int main(void) {
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++) {
        cin >> str;
        cout << compiler(1) << endl;
    }
 
    return 0;
}
 
string compiler(int init) {
    int cur_state = init;
    int index = 0;
    while (cur_state && (index < str.size())) {
        char c = str.at(index);
        cur_state = state[cur_state][c - '0'];
        index++;
 
        if (cur_state == 7 && (index + 1) < str.size() && str.at(index - 2) == '1' && str.at(index) == '0' && str.at(index + 1) == '0')
            cur_state = 3;
    }
 
    return (cur_state == 4 || cur_state == 7) ? "YES" : "NO";
}
