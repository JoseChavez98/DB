import math

def ED(q,c):
    suma = 0

    for  i in range (1,len(q)):
        suma += (q[i]-c[i])**2

    dist = math.sqrt(suma)
    return dist


        

def RangeSearch(collection,r,q):
    result = []
    
    for c in range (len(collection)):
        
        dist = ED(q,collection.iloc[c,:])
        if dist <r:
            result.append(c)
    
    return result


def precision(Q,R,iris):``
    count=0
    for id_r in R:
        if iris.iloc[id_r,4] == iris.iloc[Q.name,4]:
            count+=1

    return count/len(R)

        