import pandas as pd
import numpy as np
import math
from function import *
#radio = 1.5 3.5 5.5
iris = pd.read_csv("iris.data", header = None)
dataT = iris.iloc[ :, 0:4]
Q1 = dataT.iloc[15, :]
Q2 = dataT.iloc[82, :]
Q3 = dataT.iloc[121,:]


data = dataT.drop([15,82,121], axis=0)

R1_1 = RangeSearch(data,1.5,Q1)
R1_2 = RangeSearch(data,3.5,Q1)
R1_3 = RangeSearch(data,5.5,Q1)

R2_1 = RangeSearch(data,1.5,Q2)
R2_2 = RangeSearch(data,3.5,Q2)
R2_3 = RangeSearch(data,5.5,Q2)

R3_1 = RangeSearch(data,1.5,Q3)
R3_2 = RangeSearch(data,3.5,Q3)
R3_3 = RangeSearch(data,5.5,Q3)
        
P1_1=precision(Q1,R1_1,iris)
P1_2=precision(Q1,R1_2,iris)
P1_3=precision(Q1,R1_3,iris)

P2_1=precision(Q2,R2_1,iris)
P2_2=precision(Q2,R2_2,iris)
P2_3=precision(Q2,R2_3,iris)

P3_1=precision(Q3,R3_1,iris)
P3_2=precision(Q3,R3_2,iris)
P3_3=precision(Q3,R3_3,iris)


print(P1_1)
print(P1_2) 
print(P1_3)
print("###")
print(P2_1)
print(P2_2)
print(P2_3)
print("###")
print(P3_1)
print(P3_2)
print(P3_3)

