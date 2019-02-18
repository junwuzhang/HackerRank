# Enter your code here. Read input from STDIN. Print output to STDOUT
n = input()
for i in range(int(n)):
    stringEvenIdx = ""
    stringOddIdx = ""
    inputString = input()
    for j in range(len(inputString)):
        # if even index:
        if j % 2 == 0:
            stringEvenIdx += inputString[j]
        else: stringOddIdx += inputString[j]
    print(stringEvenIdx, stringOddIdx)
