#include<bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int ret = 0;
    int prev = 0;
    for(int i : stations){
        int a = i - prev - 1 - w;
        int b = (int)(ceil((double)a / (double)(2 * w + 1)));
        ret += max(0, b);
        prev = i + w;
    }
    ret += (int)(ceil((double)(n - prev) /(double)(2 * w + 1)));
    return ret;
}