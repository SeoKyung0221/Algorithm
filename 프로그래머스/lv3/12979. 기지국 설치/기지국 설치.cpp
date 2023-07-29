#include <bits/stdc++.h>
using namespace std; 
int solution(int n, vector<int> stations, int w){ 
    int ret = 0;
    int prev = -w;
    for(int here : stations){
        int a = prev + w;
        int b = here - w;
        int h = b - a - 1;
        ret += int(ceil((double)h / (double)(2 * w + 1)));
        prev = here;
    }
    ret += int(ceil((double)(n-prev-w) / (double)(2 * w + 1)));
    return ret;
}