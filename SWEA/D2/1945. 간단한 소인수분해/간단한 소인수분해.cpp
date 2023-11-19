#include<bits/stdc++.h>
using namespace std;
int te, tcnt, n;

int main() {
	cin >> te;
	while (te--) {
		tcnt++;

		cin >> n;
		int temp = n;
		int a = 0, b = 0, c = 0, d = 0, e = 0;
		while (true) {
			if (temp % 2 == 0) {
				a++;
				temp = temp / 2;
			}
			else break;

		}
		temp = n;
		while (true) {
			if (temp % 3 == 0) {
				b++;
				temp /= 3;
			}
			else break;

		}
		temp = n;
		while (true) {
			if (temp % 5 == 0) {
				c++;
				temp /= 5;
			}
			else break;

		}
		temp = n;
		while (true) {
			if (temp % 7 == 0) {
				d++;
				temp /= 7;
			}
			else break;

		}
		temp = n;
		while (true) {
			if (temp % 11 == 0) {
				e++;
				temp /= 11;
			}
			else break;

		}
		cout << "#" << tcnt << " " << a << " " << b << " " << c << " " << d << " " << e << "\n";
	}
}