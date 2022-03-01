# 일곱난쟁이 

arr = []

for i in range(9): 
    arr.append(int(input()))
arr.sort()
sum = 0
for i in range(9):
	sum += arr[i]

result = sum - 100
i = 0
j = 8
while (1):
	if arr[i]+arr[j] < result:
		i += 1
	elif arr[i]+arr[j] > result:
		j -= 1
	elif arr[i]+arr[j] == result:
		break
del arr[i]
del arr[j-1]
for i in range(7):
	print (arr[i])
