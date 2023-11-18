#include<bits/stdc++.h>
using namespace std;

int n, m, ret[104][104];
char a[104][104];

void check(int y, int x) {
	int y_ = y, x_ = x;
	int cnt = 0;
	while (true) {
		if (x < 0) break;
		if (a[y][x] == 'c') {
			ret[y_][x_] = cnt;
			break;
		}
		else {
			x -= 1;
			cnt++;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	fill(&ret[0][0], &ret[0][0] + 104 * 104, -1);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check(i, j);
;		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}
}