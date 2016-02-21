#!/usr/bin/env python
# -*- coding: utf-8 -*-
########################################################################
# 
# 
########################################################################
 
"""
File: A.py
Author: AngelClover(AngelClover@aliyun.com)
Date: 2016/02/21 14:49:35
"""
s = raw_input()
dic = [[0,0],[1,0],[0,1],[1,1]]
x = y = 0
base = 1
for i in range(len(s)):
    k = s[len(s)-1 - i]
    #print k
    ik = int(k)
    x += dic[ik][0] * base
    y += dic[ik][1] * base
    base *= 2
    #print x, y, base
print len(s),x,y
