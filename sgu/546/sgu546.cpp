/***************************************************************************
 * 
 * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 /**
 * @file sgu546.cpp
 * @author AngelClover(AngelClover@baidu.com)
 * @date 2018/03/14 23:07:18
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

inline void checkmin(int&a, const int&b){
    if (b < a) a = b;
}
int dp[210][210][210];
int from[210][210][210];
int main(){
    int n, a, b;
    char s[210];
    scanf("%d%d%d%s", &n, &a, &b, s);
    memset(dp, 0xff, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) s[i] -= '0';
    for (int i = 0; i < n; ++i){
        for (int j = 0; j <= a; ++j){
            for (int k = 0; k <= b; ++k){
                if (dp[i][j][k] >= 0){
                    for(int l = 0; l < 3; ++l){
                        int& x = dp[i + 1][j + (l == 0)][k + (l == 1)];
                        const int& y = dp[i][j][k] + (s[i] != l);
                        if (x == -1 || y < x){
                            x = y;
                            from[i + 1][j + (l == 0)][k + (l == 1)] = l;
                        }
                    }
                }
            }
        }
    }
    int res = dp[n][a][b];
    printf("%d\n", res);
    if (res >= 0){
        int la = a;
        int lb = b;
        vector<int> v;
        for (int i = n; i > 0; --i){
            int l = from[i][la][lb];
            v.push_back(l);
            la -= (l == 0);
            lb -= (l == 1);
        }
        for (int i = n - 1; i >= 0; --i){
            printf("%d", v[i]);
        }
    }
    putchar(10);
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
