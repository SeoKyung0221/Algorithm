#include<bits/stdc++.h>
using namespace std;
int a, b, c;

int main(){
    cin >> a >> b >> c;
    
    if(a == 60 && b == 60 && c == 60){
        cout << "Equilateral\n";
        return 0;
    }
    if((a+b+c) > 180 || (a+b+c) < 180){
        cout << "Error\n";
        return 0;
    }else{
        if(a == b || b == c || c == a){
            cout << "Isosceles\n";
            return 0;
        }else{
            cout << "Scalene\n";
            return 0;
        }
    }
}