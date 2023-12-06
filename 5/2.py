tabsNo=["seeds:","-soil","-fertilizer","-water","-light","-temperature","-humidity","-location"]
currentTab=0

tabs=[]
result=[]
seedsNo=20
whichSeeds=14
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
		try:
			lineList=list(map(int,line.split(" ")))
			if len(lineList)==seedsNo:
				allSeeds=0
				# for element in range(0,seedsNo,2):
				element=whichSeeds
					#allSeeds+=lineList[element+1]
					# print(lineList[element],lineList[element+1])
				for i in range(lineList[element],lineList[element]+lineList[element+1]):
					tabs[0][i]=i
				# print(tabs[0])
				# exit()

			if len(lineList)==3:
				for value in tabs[currentTab-1].values():
					if value in range(lineList[1],lineList[1]+lineList[2]):
						tabs[currentTab][value]=value+(lineList[0]-lineList[1])
		except:
			pass
	
print(min(tabs[7].values()))
# print(tabs)