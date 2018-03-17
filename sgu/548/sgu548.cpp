/***************************************************************************
 * 
 * Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 /**
 * @file sgu548.cpp
 * @author AngelClover(AngelClover@baidu.com)
 * @date 2018/03/17 11:58:25
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

int dragon = 0, coin = 0;
int flag[200100];

struct cmp{
    bool operator() (const int& a, const int&b){
        if (flag[a] > 0 && flag[b] > 0){
            return flag[a] > flag[b] || (flag[a] == flag[b] && a < b);
        } else return true;
    }
};

std::priority_queue<int, vector<int>, cmp> Q;
void add(int x, int pla){
    coin += x;
    dragon++;
    flag[pla] = x;
    Q.push(pla);
}
void downto(int up){
    while (Q.size() > up){
        int pla = Q.top();
        dragon--;
        coin -= flag[pla];
        flag[pla] = 0;
        Q.pop();
    }
}



int main(){
    int n;
    scanf("%d", &n);
    char s[20];
    memset(flag, 0, sizeof(flag));
    int x;
    for (int i = 1; i < n; ++i){
        scanf("%s%d", s, &x);
        if (s[0] == 'd'){
            add(x, i);
        }else if (s[0] == 'p'){
            if (i < n - 1){
                downto(x - 1);
            }else{
                if (dragon < x){
                    puts("-1");
                    return 0;
                }
            }
        }
    }
    printf("%d\n%d\n", coin, dragon);
    bool first = true;
    for (int i = 1; i < n ; ++i){
       if (flag[i] > 0){
           if (!first)putchar(32);
           printf("%d", i + 1);
           first = false;
       }
    }
    putchar(10);

}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
