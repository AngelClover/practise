#!/usr/bin/env python
# -*- coding: utf-8 -*-
########################################################################
# 
# 
########################################################################
 
"""
File: brute.py
Author: AngelClover(AngelClover@aliyun.com)
Date: 2016/02/05 00:09:50
"""
#!/usr/bin/python
#coding=utf-8
tab = list()
N = 1000000
t = 0
for i in range(0, N+2):
    t = t ^ i
    tab.append(t)
    
def get_xor(x, y):
    if x > y:
        t = x
        x = y
        y = t
    #print x,y,tab[x-1],tab[y]
    return tab[x-1] ^ tab[y]

li = raw_input().split()
n = int(li[0])
m = int(li[1])
li = raw_input().split()
a = list()
for i in li:
    a.append(int(i))

def get_ans(l, r):
    if l > r:
        t = l
        l = r
        r = t
    res = 0
    for x in range(l, r+1):
        for y in range(x, r+1):
            ans = get_xor(a[x], a[y])
            #print x,y,ans
            if res < ans:
                res = ans
    print res

l = list()
r = list()
for i in range(0, m):
    li = raw_input().split()
    l.append(int(li[0]) - 1)
    r.append(int(li[1]) - 1)
    get_ans(l[i], r[i])

