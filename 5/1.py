def checkSeed(tabs,tabNo,key):
	result=0
	if(tabNo<6):
		try:
			key=tabs[tabNo][key]
		except:
			pass
		print(result)
		result=checkSeed(tabs,tabNo+1,key)
	return result


tabsNo=["seeds","soil","fertilizer","water","light","temperature","humidity","location"]
currentTab=0

tabs=[]
seeds=[]
result=[]
seedsNo=4
with open("input5.txt","r") as fileHandle:
	for line in fileHandle:
		line=line.strip()
		for i in range(len(tabsNo)):
			if line.find(tabsNo[i])>0:
				tabs.append({})
				currentTab=i-1
				print(currentTab)
		lineList=line.split(" ")
		if len(lineList)==3:
			for i in range(int(lineList[2])+1):
				tabs[currentTab][int(lineList[0])+i]=int(lineList[1])+i
		if len(lineList)==seedsNo:
			seeds=list(map(int,lineList))

for i in seeds:
	result.append(checkSeed(tabs,0,i))
	print("ugh\n\n")
	
	
# print(min(tabs[6]))
# print(tabs)
# print(result)