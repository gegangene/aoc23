numbers=[]
symbolsMap=[]
numberSum=0
with open("input3.txt","r") as fileHandle:
	lineCounter=0
	for line in fileHandle:
		numbers.append([])
		symbolsMap.append([])
		# line=line.replace("\n", "")
		symbolCounter=0
		numberStr=""
		numberPos=()
		for symbol in line:
			numbers[lineCounter].append(0)
			symbolsMap[lineCounter].append(0)
			if symbol.isnumeric():
				numberStr+=symbol
				numberPos+=(symbolCounter,)
			elif symbol!="." and symbol!="\n":
				symbolsMap[lineCounter][symbolCounter]=1
				if(len(numberPos)>0):
					for i in range(min(numberPos),max(numberPos)+1):
						numbers[lineCounter][i]=int(numberStr)
				numberStr=""
				numberPos=()
			else:
				if(len(numberPos)>0):
					for i in range(min(numberPos),max(numberPos)+1):
						numbers[lineCounter][i]=int(numberStr)
				numberStr=""
				numberPos=()
			symbolCounter+=1
		lineCounter+=1

for i in range(len(numbers)):
	for ii in range(len(numbers[i])):
		if symbolsMap[i][ii]==1:
			for j in range(i-1,i+2):
				for jj in range(ii-1,ii+2):
					try:
						if numbers[j][jj]>0:
							numTemp=numbers[j][jj]
							numberSum+=numbers[j][jj]
							numbers[j][jj]=0
							lastPos=jj+1
							try:
								while(numbers[j][lastPos]==numTemp):
									numbers[j][lastPos]=0
									lastPos+=1
							except:
								pass
							lastPos=jj-1
							try:
								while(numbers[j][lastPos]==numTemp):
									numbers[j][lastPos]=0
									lastPos-=1
							except:
								pass
					except:
						continue
print(numberSum)