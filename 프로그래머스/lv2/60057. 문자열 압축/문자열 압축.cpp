#include<bits/stdc++.h>
using namespace std;

int solution(string s) {
    int ret = s.size();
    for(int i = 1; i <= s.size()/2; i++){
        int _ret = s.size();
        vector<string> v;
        int j = 0;
        while(true){
            if(j + i > s.size()){
                v.push_back(s.substr(j, i));
                break;
            }else{
                v.push_back(s.substr(j, i));
                j += i;
            }
        }
        string a = v[0];
        int cnt = 1;
        for(int i = 1; i < v.size(); i++){
            if(a == v[i]){
                cnt++;
            }else{
                if(cnt != 1){
                    _ret = _ret - ((cnt-1) * a.size()) + to_string(cnt).size();
                }
                cnt = 1;
                a = v[i];
            }
            if(i == v.size() - 1 && cnt != 1){
                _ret = _ret - ((cnt-1) * a.size()) + to_string(cnt).size();
            }
        }
        ret = min(ret, _ret);
    }
    return ret;
}