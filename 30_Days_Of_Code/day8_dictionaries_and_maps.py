# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(input())
phoneBook = {}
for i in range(n):
    inputStr = str(input()).split(" ")
    name = inputStr[0]
    number = inputStr[1]
    phoneBook[name] = number

for i in range(n):
    queryName = str(input())
    if queryName in phoneBook:
        print(queryName+"="+phoneBook[queryName])
    else:
        print("Not found")
