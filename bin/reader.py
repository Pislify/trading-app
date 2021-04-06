import json

# read file
with open('currentprice.json', 'r') as myfile:
    data=myfile.read()

# parse file
obj = json.loads(data)

# show values
s = (str(obj["bpi"]["USD"]["rate"]))

s = s.replace(".","")
s = s.replace(",","")
s = s[5:]
r = int(s)
print(s)

with open('currentprice.json', 'w') as myfile:
    myfile.write(str(r))

    