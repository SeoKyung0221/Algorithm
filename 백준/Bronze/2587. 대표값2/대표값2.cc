#include<bits/stdc++.h>
using namespace std;
int num, mid, avg;
vector<int> v;
int main(){
    for(int i = 0; i < 5; i++){
        cin >> num;
        avg += num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    avg /= 5;
    cout << avg << "\n" << v[2];
}