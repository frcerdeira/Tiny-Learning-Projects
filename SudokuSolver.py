import pandas as pd
import numpy as np

data = pd.read_csv('s01a.txt', sep = " ", header = None);
template = np.asarray(data, dtype = int)

def show(sudoku):
	for yy in range(9):
		if yy % 3 == 0:
			print("|-------|-------|-------|")

		for xx in range(9):

			if xx % 3 == 0: 
				print("|", end = " ")

			if xx == 8:
				print(sudoku[yy][xx], "|")
			else:
				print(sudoku[yy][xx], end = " ")
	print("|-------|-------|-------|")

def cell(sudoku): # Searches for next empty cell
	for yy in range(9):
		for xx in range(9):
			if sudoku[yy][xx] == 0:
				return xx, yy # Finds it, returns coordenates
	return False # Doesn't find it -> It's done

def check(value, sudoku, xx, yy):

	# We check columns 
	for j in range(9):
		if sudoku[j][xx] == value: # if we find it then
			return False # it's not

	# ... rows
	for i in range(9):
		if sudoku[yy][i] == value: # if we find it then
			return False # it's not

	# ... and squares
	sqX = int(xx/3) # where do you think we are??
	sqY = int(yy/3) # where do you think we are??

	sqX *= 3 # starting position
	sqY *= 3 # starting position

	for i in range(sqX, sqX+3):
		for j in range(sqY, sqY+3):
			if sudoku[j][i] == value: # if we find it then
				return False # it's not

	# Return if ok or not
	return True

def solve(sudoku):

	if not cell(sudoku):
		return True # No empty cells means we finished

	else:
		xx, yy = cell(sudoku)

	for value in range(1, 10):
		if check(value, sudoku, xx, yy): # test values 1-9
			sudoku[yy][xx] = value # if it's valid

			if solve(sudoku): # call the function again for next cell
				return True 

	sudoku[yy][xx] = 0  # If no valid values are
						# found we clear the cell

	return False  #... and backtrack


show(template)
print("\n", "\n")
solve(template)
show(template)
