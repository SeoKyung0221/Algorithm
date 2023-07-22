#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    while(true){
        cin >> n;
        if(n == -1) break;
        
        int i = 1;
        int cnt = 0;
        vector<int> v;
        
        while(i < n){
            if(n % i == 0){
                cnt += i;
                v.push_back(i);
            }
            i++;
        }
        if(cnt == n){
            cout << n << " = ";
            for(int i = 0; i < v.size(); i++){
                if(i == v.size()-1) cout << v[i];
                else cout << v[i] << " + ";
            } 
            cout << "\n";
        }else cout << n << " is NOT perfect.\n";
    }
}