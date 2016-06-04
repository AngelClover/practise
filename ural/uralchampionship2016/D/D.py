#!/usr/bin/env python
# -*- coding: utf-8 -*-
########################################################################
# 
# 
########################################################################
 
"""
File: D.py
Author: AngelClover(AngelClover@aliyun.com)
Date: 2016/06/04 19:28:17
status: RE
"""
#!/usr/bin/python
#coding=utf-8
import os
import re
import copy


nu = [
      "._. ... ._. ._. ... ._. ._. ._. ._. ._.",
      "|.| ..| ._| ._| |_| |_. |_. ..| |_| |_|",
      "|_| ..| |_. ._| ..| ._| |_| ..| |_| ._|"
     ]

nn = []
for i in range(10):
    pla = i * 4
    x = []
    for j in range(3):
        x.append(nu[j][pla:pla+3])
    nn.append(x)

def compare(now, mo):
    #print now, mo
    for i in range(3):
        for j in range(3):
            a = now[i][j]
            b = mo[i][j]
            if a != '.' and a != b:
                return False
    return True

def judge(now, up):
    ret = []
    for i in range(up):
        good = compare(now, nn[i])
        if good:
            ret.append(i)
        #print "<>", i, res, al, ret
    return ret

line = raw_input()
Case = int(line)
res_all = []
for cas in range(Case):
    mp = []
    for i in range(3):
        line = raw_input()
        mp.append(line)
    
    rr = []
    for i in (0, 4, 10, 14):
        now = []
        for j in range(3):
            now.append(mp[j][i:i+3])
        up = 10
        if i == 0 or i == 10:
            up = 6
        ret = judge(now, up)
        rr.append(ret)
    #print rr
    res_all.append(rr)

def f(x):
    return x[0] * 1000 + x[1] * 100 + x[2]* 10 + x[3]


def choose(s, up_score):
    x = [0, 0, 0, 0]
    now = 0
    now_x = []
    for i in s[0][::-1]:
        if i > up_score/1000:
            continue
        x[0] = i
        for j in s[1][::-1]:
            if i * 10 + j > up_score/ 100:
                continue
            x[1] = j
            for k in s[2][::-1]:
                if i * 100 + j * 10 + k > up_score/10:
                    continue
                x[2] = k
                for l in s[3][::-1]:
                    x[3] = l
                    res = f(x)
                    if res < up_score and res > now:
                        res = now
                        now_x = copy.deepcopy(x)
                        return now_x
    return now_x

ans = []
total = 100000

for i in res_all:
    a = choose(i, total)
    res = f(a)
    total = res
    ans.append(a)

#print ans
for i in range(len(ans)):
    print "%d%d:%d%d" % (ans[i][0], ans[i][1], ans[i][2], ans[i][3])


