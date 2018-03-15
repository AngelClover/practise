#!/usr/bin/env python
# -*- coding: utf-8 -*-
########################################################################
# 
# 
########################################################################
 
"""
File: A.py
Author: AngelClover(AngelClover@aliyun.com)
Date: 2016/04/01 20:25:45
"""
#!/usr/bin/python
#coding=utf-8
import logging
from logging import debug


line = raw_input().split()
n = (int)(line[0])
m = (int)(line[1])
k = (int)(line[2])
a = list()
mx = 0
mn = 10**9
for i in range(n):
    line = raw_input().split()
    b = list()
    for j in line:
        b.append((int)(j))
        mx = max(mx, (int)(j))
        mn = min(mn, (int)(j))
    a.append(b)

print n, m, k
print a


l = mn
r = mx;
while l + 1 < r :
    mid = (l + r) / 2
    if ok(mid):
        l = mid
    else:
        r = mid + 1
print l

def ok (K):
    for i in range(len(a)):
        for j in range(len(a[i])):
            if a[i][j] >= K:
                add_edge(i * m + j,  i);
                add_edge(i * m + j,  n + j);
    ans = 0
    pre = [-1 for i in n + m]
    for i in range(n + m):
        vis = [0 for i in n * m]
        if find(i, vis, pre):
            ans += 1
    if ans >= k:
        return True
    else:
        return False

def find(x, vis, pre):
    for i in 





        

