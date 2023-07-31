#include<bits/stdc++.h>
using namespace std;
int n, a, b, c, dp[1004][1004], visited[54], ret;
struct Q{
    int x;
    int y;
    int z;
};
vector<Q> Quest;

int rpg(int n_str, int n_int){
    int &ret = dp[n_str][n_int];
    if(ret != -1) return ret;
    
    ret = 0;
    int point = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(n_str >= Quest[i].x || n_int >= Quest[i].y){
            ret++;
            if(!visited[i]){
                visited[i] = 1;
                v.push_back(i);
                point += Quest[i].z;
            }
        }
    }
    for(int i = 0; i <= point; i++){
        int next_str = min(1000, n_str + i);
        int next_int = min(1000, n_int + point - i);
        ret = max(ret, rpg(next_str, next_int));
    }
    for(int i : v){
        visited[i] = 0;
    }
    return ret;
}
int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        Quest.push_back({a, b, c});
    }
    cout << rpg(1,1) << "\n";
    return 0;
}