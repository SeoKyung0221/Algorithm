#include<bits/stdc++.h>
using namespace std;
int t, a, b, ret;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}
int lcd(int a, int b){
    return a * b / gcd(a, b);
}

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin>> a >> b;
        cout << lcd(a, b) << "\n";
    }
}