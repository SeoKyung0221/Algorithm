#include<bits/stdc++.h>
using namespace std;
int n, num;
map<int, int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> num;
        mp[num]++;
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        for(int i = 0; i < (*it).second; i++){
            cout << (*it).first << "\n";
        }
    }
}