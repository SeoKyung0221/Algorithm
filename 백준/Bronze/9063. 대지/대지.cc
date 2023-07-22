#include<bits/stdc++.h>
using namespace std;
int n, num1, num2, a = 10001, b = -10001, c = 10001, d = -10001;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num1 >> num2;
        a = min(a, num1);
        b = max(b, num1);
        c = min(c, num2);
        d = max(d, num2);
    }
    cout << (d-c) * (b-a) << "\n";
    return 0;
}