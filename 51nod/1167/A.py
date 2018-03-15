#!/usr/bin/env python
# -*- coding: utf-8 -*-
########################################################################
# 
# 
########################################################################
 
"""
File: A.py
Author: AngelClover(AngelClover@aliyun.com)
Date: 2016/02/19 12:13:46
"""
#!/usr/bin/python
#coding=utf-8
k = int(raw_input())
n = int(raw_input())

print k,n
def f(n):
    if n < k:
        return 1
    s = n % k
    if s != 0:
        n -= s
    return f(n - k) + f(n / k)
print f(n)



