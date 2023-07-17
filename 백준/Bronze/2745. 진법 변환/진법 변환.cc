#include<bits/stdc++.h>
using namespace std;
int b, ret;
string n;

int main(){
    cin >> n >> b;
    int j = 0;
    for(int i = n.size()-1; i >= 0; i--){
        if(n[i] >= 'A' && n[i] <= 'Z'){
            ret += int(pow(b, j)) * (n[i] - 'A' + 10);
        } else{
            ret += int(pow(b, j)) * (n[i] - '0');
        }
        j++;
    }
    cout << ret << "\n";
    return 0;
}