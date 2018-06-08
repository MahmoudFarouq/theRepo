import os
import pickle

class IndexBlock:
	def __init__(self, address, lstOfBlocks):
		self.address = address
		self.blocks  = lstOfBlocks

class MemoryBlock:
	def __init__(self, ocupied, start, end):
		self.ocupied = ocupied
		self.start = start
		self.end = end

	def __str__(self):
		return "{ocupied: "+str(self.ocupied)+", start: "+str(self.start)+", end: "+str(self.end)+"}"

class Memory:
	def __init__(self, MAX_SIZE):
		# False == Free
		self.mem = [MemoryBlock(False, 0, 4000)]

	def malloc(self, size):
		blocks = []
		for i in range(len(self.mem)):
			if size == 0:
				return blocks
			if self.mem[i].ocupied == False:
				self.mem[i].ocupied = True
				blocks.append(i)
				availSize = self.mem[i].end - self.mem[i].start
				if size  >= availSize:
					size -= availSize
				else:
					self.mem[i].end = self.mem[i].start + size
					self.mem.append(MemoryBlock(False, self.mem[i].start + size, self.mem[i].start + availSize))
					return blocks
		return None


	def free(self, indexBlock):
		for index in indexBlock:
			self.mem[index].ocupied = False

class File:
	def __init__(self, name, size, indexBlock):
		self.name = name
		self.size = int(size)
		self.indexBlock = indexBlock
		dotIndex = name.rfind('.')
		if(dotIndex != -1):
			self.type = name[dotIndex+1:]
		else:
			self.type = None

	def displayStructure(self, level):
		spaces = ("%"+str(level*4)+"s")%''
		print(spaces, self.name, self.size)

class Directory:
	def __init__(self, name):
		self.name = name
		self.content = {}

	def mkdir(self, dirName):
		if self.exists(dirName):
			return False
		self.content[dirName] = Directory(dirName)
		return True

	def touch(self, fileName, size):
		if self.exists(fileName):
			return False
		indexBlock = FileSystem.mem.malloc(int(size))
		self.content[fileName] = File(fileName, size, indexBlock)
		return True

	def rmFile(self, fileName):
		if fileName not in self.content.keys():
			return False
		FileSystem.mem.free(self.content[fileName].indexBlock)
		self.content.pop(fileName)
		return True

	def rmDir(self, dirName):
		if dirName not in self.content.keys():
			return False
		for _, file in self.content[dirName].content.items():
			print(file.name)
			if type(file) is File:
				FileSystem.mem.free(file.indexBlock)
		self.content.pop(dirName)
		return True

	def displayStructure(self, level):
		spaces = ("%"+str(level*4)+"s")%''
		print(spaces, self.name)
		for element in self.content.keys():
			self.content[element].displayStructure(level+1)
		return True

	def exists(self, name):
		if name in self.content.keys():
			return True
		return False

class FileSystem:
	mem = Memory(4000)
	def __init__(self, vfsFileName):
		self.curWorkingDir = Directory('/')
		self.root = self.curWorkingDir
		if 'FileSystem.vfs' in os.listdir():
			self.root, FileSystem.mem = pickle.load( open( "FileSystem.vfs", "rb" ) )

	def save(self):
		pickle.dump( [self.root, FileSystem.mem], open( "FileSystem.vfs", "wb" ) )

	def displayDiskStatus(self):
		for memBlock in FileSystem.mem.mem:
			print(memBlock)
		return True

	def displayDiskStructure(self):
		return self.root.displayStructure(0)

	def parse(self, args):
		try:
			if args[0] == 'status':
				return self.displayDiskStatus()
			elif args[0] == 'structure':
				return self.displayDiskStructure()
			dirs = args[1].split('/')
			wDir = self.getTheDirectory(dirs)
			if wDir == False:
				return False
			if args[0] == 'mkdir':
				return wDir.mkdir(dirs[-1])
			elif args[0] == 'touch':
				return wDir.touch(dirs[-1], args[2])
			elif args[0] == 'rmFile':
				return wDir.rmFile(dirs[-1])
			elif args[0] == 'rmDir':
				return wDir.rmDir(dirs[-1])
			elif args[0] == 'ls':
				return wDir.displayStructure(0)			
		except:
			pass
	def getTheDirectory(self, dirs):
		res = self.root if dirs[0] == '' else self.curWorkingDir
		for i in range(1, len(dirs)-1):
			_dir = dirs[i]
			if res.exists(_dir):
				res = res.content[_dir]
			else:
				return False
		return res


def main():
	fs = FileSystem('')
	while(True):
		line = input(">>> ")
		args = line.split(' ')
		if args[0] == 'q':
			fs.save()
			return
		print(fs.parse(args))


if __name__ == '__main__':
	main()
'''
	fs.parse('ls'.split(' '))
	fs.parse('touch hi.txt 200'.split(' '))
	fs.parse('ls'.split(' '))
	fs.parse('mkdir hi'.split(' '))
	fs.parse('mkdir man'.split(' '))
	fs.parse('mkdir /hi/man'.split(' '))
	fs.parse('ls'.split(' '))
	fs.parse('mkdir hi'.split(' '))
	fs.parse('ls'.split(' '))
	fs.parse('mkdir /hi/mando/tet'.split(' '))
	fs.parse('ls'.split(' '))
	fs.parse('mkdir /man/dodo'.split(' '))
	fs.parse('ls'.split(' '))
	fs.parse('touch /hi/man/tete.txt 100'.split(' '))
	fs.parse('ls'.split(' '))
	fs.parse('rmFile hi.txt'.split(' '))
	fs.parse('ls'.split(' '))
	fs.parse('rmDir /hi/man'.split(' '))
	fs.parse('ls'.split(' '))
	FileSystem.displayDiskStatus()
'''