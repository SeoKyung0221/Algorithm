#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;
    if(n == 1){
        return 0;
    }else{
        int i = 2;
        while(n > 1){
            while(n % i != 0){
                i++;
            }
            while(n % i == 0){
                if(n == i){
                    cout << i << "\n";
                    return 0;
                }else{
                    cout << i << "\n";
                    n /= i;
                }
            }
        }
    }
    
}