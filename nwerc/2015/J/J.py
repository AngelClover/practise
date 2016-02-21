#!/usr/bin/env python
# -*- coding: utf-8 -*-
########################################################################
# 
# 
########################################################################
 
"""
File: J.py
Author: AngelClover(AngelClover@aliyun.com)
Date: 2016/02/21 15:09:27
"""
n = int(raw_input())
str = raw_input().split()
dic = [(x^((x<<1)&0xff)) for x in range(256) ]
dd = [ 0 for x in range(256)]
for i in range(256):
    dd[dic[i]] = i
res = ""
for i in str:
    res += ("%d " % dd[int(i)])
print res
