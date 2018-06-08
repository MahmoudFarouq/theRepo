class Process:
	def __init__(self, name, allocRes, maxRes):
		self.name = name
		self.allocRes = allocRes
		self.maxRes = maxRes
		self.needed = [ maxRes[i]-allocRes[i] for i in range(len(maxRes))]
	def __le__(self, availRes):
		return all( [ availRes[key] >= self.needed[index] for index, key in enumerate(availRes) ] )

def printTable(availRes, allProc):
	cellWidth = len(availRes)*len(availRes)+2
	print(4*cellWidth*'-')
	print('p, Alloc, Max, Available  = ', availRes)
	for proc in allProc:
		print(proc.name, proc.allocRes, proc.maxRes)

def add(avail, proc):
	for index, key in enumerate(avail):
		avail[key] += proc[index]
	

availRes = {'A':3, 'B':3, 'C':2}
p0 = Process('p0', [0,1,0], [7,5,3])
p1 = Process('p1', [2,0,0], [3,2,2])
p2 = Process('p2', [3,0,2], [9,0,2])
p3 = Process('p3', [2,1,1], [2,2,2])
p4 = Process('p4', [0,0,2], [4,3,3])
Processes = [ p0, p1, p2, p3, p4]

changed = True
while(len(Processes) != 0 and changed):
	printTable(availRes, Processes)
	changed = False
	for proc in Processes:
		if proc <= availRes:
			add(availRes, proc.allocRes)
			Processes.remove(proc)
			print(proc.name+" Removed.")
			changed = True

if not changed:
	print("failed")
else:
	print("succeded")


