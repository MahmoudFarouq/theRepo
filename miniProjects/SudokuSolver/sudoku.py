import os
import sys

class Board:
	# takes a triTuble (iIndex, jIndex, value)
	def __init__(self, values):
		"""self.board = []
		for i in range(9):
			self.board.append([])
			for j in range(9):
				self.board[i].append(0)
		for i, j, v in values:
			self.board[i][j] = values"""
		self.board = values
		if os.name == 'posix':
			self.clear = 'clear'
		else:
			self.clear = 'cls'
		
	#overload printing
	def __str__(self):
		toBePrinted = ""
		#os.system(self.clear)
		for row in range(9):
			for column in range(9): 
				toBePrinted += str(self.board[row][column]) + "    "
			toBePrinted += "\n"
		return toBePrinted

	#overload []
	def __getitem__(self, i):
		return self.board[i]

	#overload copy() function
	def copy(self):
		cpy = []
		for row in self.board:
			cpy.append(row.copy())
		return Board(cpy)

class SudokuSolver:
	def __init__(self, board):
		self.board = board
		self.solvable = True
	def solveProblem(self):
		while not self.reachedGoal() and self.solvable:
			changed = self.visitAll3x3subBoards()
			if not changed:
				return self.Expand()
		return self.board

	def Expand(self):
		emptyCells, number = self.getBestNewStart()
		# starting a new Tree-Search
		for emptyCell in emptyCells:
			newBoard = self.board.copy()
			newBoard[emptyCell[0]][emptyCell[1]] = number
			solver = SudokuSolver(newBoard)
			res = solver.solveProblem()
			if solver.solvable and res != None:
				return res
		return None

	def reachedGoal(self):
		for row in range(9):
			for column in range(9):
				if self.board[row][column] == 0:
					return False
		return True

	def visitAll3x3subBoards(self):
		changed = False
		for row in range(0, 9, 3):
			for column in range(0, 9, 3):
				changed |= self.visit3x3subBoard(row, column)
		return changed

	def visit3x3subBoard(self, row, column):
		notExistingElements = self.getNotExistingElements(row, column)
		return self.solve3x3subBoard(row, column, notExistingElements)

	def getNotExistingElements(self, row, column):
		sequence = [1,2,3,4,5,6,7,8,9]
		for i in range(row, row+3):
			for j in range(column, column+3):
				try:
					del sequence[ sequence.index(self.board[i][j]) ]
				except:
					pass
		return sequence

	def solve3x3subBoard(self, row, column, notExistingElements):
		changed = False
		for lookingFor in notExistingElements:
			copy = self.board.copy()
			self.checkVertical(row, copy, lookingFor)			
			self.checkHorizontal(column, copy, lookingFor)
			emptyCells = self.getEmptyCellsIndix(row, column, copy)
			if len(emptyCells) == 0 and self.getMinusOneCount(row, column, copy) > 0:
				self.solvable = False
				return False
			if len(emptyCells) == 1:
				self.board[emptyCells[0][0]][emptyCells[0][1]] = lookingFor
				changed = True
		return changed

	def getMinusOneCount(self, row, column, copy):
		counter = 0
		for i in range(row, row+3):
			for j in range(column, column+3):
				if copy[i][j] == -1:
					counter += 1
		return counter

	def checkVertical(self, row, copy, lookingFor):
		for i in range(row, row+3):
			for j in range(9):
				if copy[i][j] == lookingFor:
					for d in range(9):
						copy[i][d] = -1;

	def checkHorizontal(self, column, copy, lookingFor):
		for i in range(column, column+3):
				for j in range(9):
					if copy[j][i] == lookingFor:
						for d in range(9):
							copy[d][i] = -1;

	def getEmptyCellsIndix(self, row, column, copy):
		emptyCells = []
		for i in range(row, row+3):
			for j in range(column, column+3):
				if copy[i][j] == 0:
					emptyCells.append((i, j))
		return emptyCells

	def getBestNewStart(self):

		# get best subBoard
		i, j, bestLen = 0,0,100
		for row in range(0, 9, 3):
			for column in range(0, 9, 3):
				newLen = len( self.getNotExistingElements(row,column) )
				if(newLen < bestLen and newLen != 0):
					i, j, bestLen = row, column, newLen

		#get best number and it's possible possitions to spread
		elems = self.getNotExistingElements(i,j)
		bestEmptyCells, bestNum = [],0
		for lookingFor in elems:
			copy = self.board.copy()
			self.checkVertical(i, copy, lookingFor)			
			self.checkHorizontal(j, copy, lookingFor)
			emptyCells = self.getEmptyCellsIndix(i, j, copy)
			if len(bestEmptyCells) == 0 or len(emptyCells) < len(bestEmptyCells):
				bestEmptyCells, bestNum = emptyCells, lookingFor
		return (bestEmptyCells, bestNum)


if __name__ == '__main__':
	easy = [[1,0,0,4,8,9,0,0,6],
			 [7,3,0,0,0,0,0,4,0],
			 [0,0,0,0,0,1,2,9,5],
			 [0,0,7,1,2,0,6,0,0],
			 [5,0,0,7,0,3,0,0,8],
			 [0,0,6,0,9,5,7,0,0],
			 [9,1,4,6,0,0,0,0,0],
			 [0,2,0,0,0,0,0,3,7],
			 [8,0,0,5,1,2,0,0,4]]

	midum = [[0,2,0,6,0,8,0,0,0],
			 [5,8,0,0,0,9,7,0,0],
			 [0,0,0,0,4,0,0,0,0],
			 [3,7,0,0,0,0,5,0,0],
			 [6,0,0,0,0,0,0,0,4],
			 [0,0,8,0,0,0,0,1,3],
			 [0,0,0,0,2,0,0,0,0],
			 [0,0,9,8,0,0,0,3,6],
			 [0,0,0,3,0,6,0,9,0]]

	hard1 = [[0,0,0,6,0,0,4,0,0],
			 [7,0,0,0,0,3,6,0,0],
			 [0,0,0,0,9,1,0,8,0],
			 [0,0,0,0,0,0,0,0,0],
			 [0,5,0,1,8,0,0,0,3],
			 [0,0,0,3,0,6,0,4,5],
			 [0,4,0,2,0,0,0,6,0],
			 [9,0,3,0,0,0,0,0,0],
			 [0,2,0,0,0,0,1,0,0]]

	hard2 = [[0,2,0,0,0,0,0,0,0],
			 [0,0,0,6,0,0,0,0,3],
			 [0,7,4,0,8,0,0,0,0],
			 [0,0,0,0,0,3,0,0,2],
			 [0,8,0,0,4,0,0,1,0],
			 [6,0,0,5,0,0,0,0,0],
			 [0,0,0,0,1,0,7,8,0],
			 [5,0,0,0,0,9,0,0,0],
			 [0,0,0,0,0,0,0,4,0]]

	args = sys.argv
	if(len(args) == 1):
		board = Board( easy )
	elif args[1] == 'e':
		board = Board( easy )
	elif args[1] == 'm':
		board = Board( midum )
	elif args[1] == 'h1':
		board = Board( hard1 )
	elif args[1] == 'h2':
		board = Board( hard2 )
	else:
		board = Board( easy )
		

	solver = SudokuSolver(board)
	print(solver.solveProblem())