axa=0
with open("input1.txt","r") as inputHandle:
	Numbers=["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
	numbers=[0,1,2,3,4,5,6,7,8,9]
	for word in inputHandle:
		found={}
		for i in range(0,10):
			if Numbers[i] in word:
				for ii in range(0,len(word)):
					if word.find(Numbers[i],ii)>-1:
						found[word.find(Numbers[i],ii)]=i
			if str(numbers[i]) in word:
				for ii in range(0,len(word)):
					if word.find(str(numbers[i]),ii)>-1:
						found[word.find(str(numbers[i]),ii)]=i
		firstKey=min(found.keys())
		lastKey=max(found.keys())
		axa+=(found[firstKey]*10+found[lastKey])
print(axa)