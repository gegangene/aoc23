tabsNo=["seeds:","-soil","-fertilizer","-water","-light","-temperature","-humidity","-location"]
currentTab=0

tabs=[]
result=[]
seedsNo=20
with open("input5.txt","r") as fileHandle:
	for line in fileHandle:
		line=line.strip()
		for i in range(len(tabsNo)):
			if tabsNo[i] in line:
				tabs.append({})
				currentTab=i
				if currentTab>0:
					for element in tabs[currentTab-1].values():
						tabs[currentTab][element]=element
		lineList=line.split(" ")
		if len(lineList)==seedsNo:
			for i in range(seedsNo):
				tabs[currentTab][i]=int(lineList[i])
		if len(lineList)==3:
			lineList=list(map(int,lineList))
			for value in tabs[currentTab-1].values():
				if value in range(lineList[1],lineList[1]+lineList[2]):
					tabs[currentTab][value]=value+(lineList[0]-lineList[1])
	
print(min(tabs[7].values()))