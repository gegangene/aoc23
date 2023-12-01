axa=0
with open("input1.txt","r") as inputHandle:
	for word in inputHandle:
		a1=''
		a2=''
		for letter in word:
			if letter.isnumeric():
				if len(a1)>0:
					a2=letter
				else:
					a1=letter
		if len(a2)<1:
			a2=a1
		axa+=int(a1+a2)
print(axa)