#include <iostream>
using namespace std;

/*
이번 문제는 수학문제다.
두 지점으로부터 일정 거리로 떨어진 지점들 중 겹치는 개수를 찾으면 되는 문제다.

한 지점으로부터 일정 거리로 떨어진 지점들의 집합은 원이다.
즉 계산한 거리는 반지름으로 r1, r2(r1 > r2)
두 중심간의 거리를 d라고 하면

두 점에서 만나는 경우
d != 0 and r1 - r2 < d < r1 + r2

한 점에서 만나는 경우
d != 0 and { r1+r2 = d (외접) r1-r2 = d(내접)}

한 점에서도 만나지 않을 경우
d = 0 and r1 - r2 != 0
d != 0 and r1 + r2 > d

무수히 많은 점에서 만날 경우
d = 0 and r1 - r2 = 0

*/

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, x2, y1, y2, r1, r2, d_pow;

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		d_pow = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

		if (d_pow == 0) {
			if (r1 - r2 != 0)
				cout << 0 << endl;
			else
				cout << -1 << endl;
		}
		else {
			if (d_pow > (r1 - r2) * (r1 - r2) && d_pow < (r1 + r2) * (r1 + r2))
				cout << 2 << endl;
			else if (d_pow == (r1 - r2) * (r1 - r2) || d_pow == (r1 + r2) * (r1 + r2))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}

	return 0;
}
