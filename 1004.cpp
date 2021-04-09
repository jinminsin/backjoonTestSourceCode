#include <iostream>
using namespace std;

/*
원을 경계선이라고 가정하고 행성계의 최소한의 진입/이탈 과정만 포함하며, 그 경로는 상관이 없다.
최소한의 과정만 묻기 때문에 조건은 매우 간단해진다.
출발점이나 도착점이 각각 행성의 내부와 외부에 존재하면 된다.
*/

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, x2, y1, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		int p;
		int result = 0;
		cin >> p;

		for (int j = 0; j < p; j++) {
			int cx, cy, cr;

			cin >> cx >> cy >> cr;

			int rc1 = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);//출발점에서 행성의 중심까지의 거리 제곱
			int rc2 = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);//도착점에서 행성의 중심까지의 거리 제곱

			bool check = (rc1 < cr* cr ? true : false) != (rc2 < cr* cr ? true : false);

			if (check == true)
				result++;
		}			
		cout << result << endl;
	}

	return 0;
}
