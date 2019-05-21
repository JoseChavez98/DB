import json
with open("tweets_2018-09-30.json", encoding='utf-8') as read_file:
    tweet_data = json.load(read_file)

file1 = open("tweets-id.txt","w")    
cont = 0    
string=""
for data in tweet_data:
    cont+=1
    string=data['id']
    #file1.write(str(string)+'\n')
    print(str(string))
