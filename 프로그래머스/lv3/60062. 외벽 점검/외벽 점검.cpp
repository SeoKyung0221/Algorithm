#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;

vector<int> changeStartIndex(vector<int> weak, int start, int n){
    vector<int> weakList;
    if(start == 0) return weak;
    else{
        for(int i = start; i < weak.size(); i++){
            weakList.push_back(weak[i]);
        }
        for(int i = 0; i < start; i++){
            weakList.push_back(weak[i] + n);
        }
    }
    return weakList;
}
int solution(int n, vector<int> weak, vector<int> dist) {
    int ret = INF;
    sort(dist.begin(), dist.end());
    do{
        for(int i = 0; i < weak.size(); i++){
            vector<int> weakList = changeStartIndex(weak, i, n);
            int idx = 0, flag = 0, curr = weakList[0] + dist[0];
            for(int j = 1; j < weakList.size(); j++){
                if(curr < weakList[j]){
                    if(idx + 1 == dist.size()){
                        flag = 1;
                        break;
                    }
                    curr = weakList[j] + dist[++idx];
                }
            }
            if(flag == 0)ret = min(ret, idx + 1);
        }
    }while(next_permutation(dist.begin(), dist.end()));
    
    return (ret == INF) ? -1 : ret;
}