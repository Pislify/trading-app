import json

# read file
with open('currentprice.json', 'r') as myfile:
    data=myfile.read()

# parse file
obj = json.loads(data)

# show values
s = (str(obj["bpi"]["USD"]["rate"]))

