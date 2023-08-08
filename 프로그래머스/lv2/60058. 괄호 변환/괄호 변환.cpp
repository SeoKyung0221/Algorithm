#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') cnt++;
        else cnt--;
        if(cnt < 0) return false;
    }
    return (cnt == 0) ? true : false;
}
string solution(string p) {
    if(check(p)) return p;
    int i = 0, cnt1 = 0, cnt2 = 0;
    for(i = 0; i < p.size(); i++){
        if(p[i] == '(') cnt1++;
        else cnt2++;
        if(cnt1 == cnt2) break;
    }
    string u = p.substr(0, i + 1);
    string v = p.substr(i+1, p.size() - (i+1));
    if(check(u)){
        return u + solution(v);
    }else{
        string s = "";
        s += '(';
        s += solution(v);
        s += ')';
        u = u.substr(1, u.size() - 2);
        for(int j = 0; j < u.size(); j++){
            if(u[j] == '(') s += ')';
            else s += '(';
        }
        return s;
    }
}