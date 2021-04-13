#include <iostream>
using namespace std;

int e[10001][2];
int dp[10002][3];

void recur(int, int, int);

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int area, mem, result = 20001;
        cin >> area >> mem;

        for (int j = 1; j <= area; j++)
            cin >> e[j][0];

        for (int j = 1; j <= area; j++)
            cin >> e[j][1];

        dp[1][0] = 0; dp[1][1] = dp[1][2] = 1;

        recur(1, area, mem);
        result = min(result, dp[area + 1][0]);

        if (area > 1) {
            if (e[1][0] + e[area][0] <= mem) {
                dp[2][0] = 1;
                dp[2][1] = 2;
                dp[2][2] = e[1][1] + e[2][1] <= mem ? 1 : 2;
                recur(2, area, mem);
                result = min(result, dp[area][2] + 1);
            }
            if (e[1][1] + e[area][1] <= mem) {
                dp[2][0] = 1;
                dp[2][1] = e[1][0] + e[2][0] <= mem ? 1 : 2;
                dp[2][2] = 2;
                recur(2, area, mem);
                result = min(result, dp[area][1] + 1);
            }
            if (e[1][0] + e[area][0] <= mem && e[1][1] + e[area][1] <= mem) {
                dp[2][0] = 0; dp[2][1] = dp[2][2] = 1;
                recur(2, area, mem);
                result = min(result, dp[area][0] + 2);
            }
        }

        cout << result << endl;
    }

    return 0;
}

void recur(int index, int area, int mem) {
    for (int i = index; i <= area; i++) {
        dp[i + 1][0] = min(dp[i][1] + 1, dp[i][2] + 1);

        if (e[i][0] + e[i][1] <= mem)
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 1);

        if (i > 1 && e[i - 1][0] + e[i][0] <= mem && e[i - 1][1] + e[i][1] <= mem)
            dp[i + 1][0] = min(dp[i + 1][0], dp[i - 1][0] + 2);

        if (i <= area - 1) {
            dp[i + 1][1] = dp[i + 1][0] + 1;

            if (e[i][0] + e[i + 1][0] <= mem)
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + 1);

            dp[i + 1][2] = dp[i + 1][0] + 1;

            if (e[i][1] + e[i + 1][1] <= mem)
                dp[i + 1][2] = min(dp[i + 1][2], dp[i][1] + 1);
        }
    }
}
