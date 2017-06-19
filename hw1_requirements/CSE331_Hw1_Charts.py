# -*- coding: utf-8 -*-
"""
Created on Mon Sep 12 18:01:37 2016

@author: GIBZ
"""

from numpy import *
import math
import matplotlib.pyplot as plt

data_list = list()

data_file = open("/Users/GIBZ/331/hw1_requirements/Sort_Array_TimeResults.txt", 'r')

with data_file as inf:
    
    for line in inf:
        
        data_list.append(line)
        
for elm in data_list:
    
    print(elm)
    
#loop through each element in data list, get all the i=0 together etc.
bigList = list() 
for elm in data_list:

    collection = elm.split()
    bigList.append(collection)
    
N_List = list()
time1_List = list()
time2_List = list()

#construct N List
for i in range(0,7):

    N_List.append(bigList[i][0])

#construct time1_list
for i in range(0,7):
    
    time1_List.append(bigList[i][1])
          
#construct time2_list
for i in range(0,7):
    
    time2_List.append(bigList[i][2])

#testing-- plotting a different list for color
test_list = [1.1e7,2.0e7,3.4e7,4.5e7,5.2e7,6.9e7,7.8e7]        
 
#plot the functions
plt.plot(N_List,time1_List,'r') # plotting t,a separately 
plt.plot(N_List,time2_List,'b') # plotting t,b separately 
plt.show()

 
