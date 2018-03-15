/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 /**
 * @file A.cpp
 * @author AngelClover(AngelClover@baidu.com)
 * @date 2016/03/21 23:22:14
 * @brief 
 * not ok
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
int a[150001];
int n;
bool check(int x){
    if (x >= n - 1 || x < 0)return true;
    if (x & 1)
        return a[x] > a[x + 1];
    else
        return a[x] < a[x + 1];
}
int sum = 0;
vector<pair<int,int> > ans;
bool trytry(int x, int y, vector<int> pla){
    bool ret = false;
    swap(a[y], a[x]);
    if (check(y - 1) && check(y) &&
            check(x - 1) && check(x)){
        bool ok = true;
        for (int i = 0; ok && i < pla.size(); ++i)
            if (!check(pla[i]) || !check(pla[i] - 1))
                ok = false;
        //printf("%d,%d is %s\n", x, y, ok?"ok":"nok");
        if (ok){
            if (x > y)ans.push_back(make_pair(y, x));
            else ans.push_back(make_pair(x, y));
            ret = true;
        }
    }
    swap(a[y], a[x]);
    return ret;
}
int tryi(int x, vector<int> pla){
    if (x >= n)return 0;
    int tt = 0;
    for (int i = 0; i < n; ++i){
        if (i != x && trytry(i, x, pla)) ++tt;
    }
    return tt;
}
int main(){
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", a + i);
    }
    vector<int> pla;
    vector<int> pla2;
    for (int i = 0; i < n - 1; ++i){
        if (!check(i)) pla.push_back(i);
    }
    /*
    for (int i = 0; i < n - 1; ++i){
        printf("i:%d %s\n", i, check(i)?"y":"n");
    }
    */
    int sum = 0;
    if (pla.size() == 0){
        puts("0");
        return 0;
    }else if (pla.size() == 1){
        sum += tryi(pla[0], pla);
        sum += tryi(pla[0] + 1, pla);
        if (trytry(pla[0], pla[0] + 1, pla)) sum--;
    }else if (pla.size() == 2){
        if (pla[0] + 1 == pla[1]){
        }
        sum += tryi(pla[0], pla);
        sum += tryi(pla[1], pla);

    }else if (pla.size() == 3){
    }else if (pla.size() == 4){
    }
    //sum += tryi(pla[0], pla2);
    //sum += tryi(pla[0] + 1, pla2);
    //if (trytry(pla[0], pla[0] + 1, pla2))sum--;
    /*
    for (int i = 0; i < pla.size(); ++i){
        tryi(pla[i], pla);
        tryi(pla[i] + 1, pla);
    }
    */
    tryi(pla[0], pla);
    tryi(pla[0] + 1, pla);
    tryi(pla[0] + 2, pla);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    printf("%d\n", (int)ans.size());
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
