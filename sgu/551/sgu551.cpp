/***************************************************************************
 * 
 * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 /**
 * @file sgu551.cpp
 * @author AngelClover(AngelClover@baidu.com)
 * @date 2018/03/14 22:27:04
 * @brief 
 *  
 **/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<set>
using namespace std;

int fak(int x, int t1, int t2){
    return x / t1 + x / t2;
}

int main(){
    int n, t1, t2;
    scanf("%d%d%d", &n, &t1, &t2);
    
    int l = 0, r = n * (t1 + t2);
    while (l < r){
        int mid = (l + r) / 2;
        int m = fak(mid, t1, t2);
        if (m < n) l = mid + 1;
        else r = mid;
    }
    int now = l;
    int solutions_done = fak(now, t1, t2);
    int next_stop = now;
    if (l % t1){
        next_stop = int(double(l) / t1 + 1 - 1e-6) * t1;
        solutions_done++;
    }else if (l % t2){
        next_stop = int(double(l) / t2 + 1 - 1e-6) * t2; 
        solutions_done++;
    }
    printf("%d %d\n", solutions_done, next_stop);
    return 0;
}


/* vim: set ts=4 sw=4 sts=4 tw=100 */
