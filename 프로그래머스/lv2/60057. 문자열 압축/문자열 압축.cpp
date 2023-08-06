#include<bits/stdc++.h>
using namespace std;

int solution(string s) {
    int ret = s.size();
    for(int i = 1; i <= s.size() / 2; i++){
        vector<string> v;
        int j = 0;
        while(true){
            if(j + i > s.size()){
                v.push_back(s.substr(j, s.size() - j));
                break;
            }else{
                v.push_back(s.substr(j, i));
            }
            j += i;
        }
        int ret_ = s.size();
        int cnt = 1;
        string prev = v[0];
        for(int h = 1; h < v.size(); h++){
            if(prev == v[h]){
                cnt++;
            }else{
                if(cnt != 1) ret_ = ret_ - prev.size() * (cnt - 1) + (int)(to_string(cnt).size()); cnt = 1;
                prev = v[h];
            }
            if(cnt != 1 && h == v.size() - 1){
                ret_ = ret_ - prev.size() * (cnt - 1) + (int)(to_string(cnt).size());
            }
        }
        ret = min(ret, ret_);
    }
    return ret;
}