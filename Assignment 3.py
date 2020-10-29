class Matrix:
	mat=[]

	def __init__(self,name):
		self.name=name
		print("For matrix",self.name)
		self.m=int(input("enter no. of rows"))
		self.n=int(input("enter no. of column"))
		self.mat=[]
		rowmat=[]
		for i in range(self.m):
			for j in range(self.n):
				e=int(input("Enter the element i[%d][%d]"%(i+1,j+1)))
				rowmat.append(e)
			self.mat.append(rowmat)
			rowmat=[]
	
	def addMat(self,m1,m2):
		addMatrix=[]
		rowmat=[]
		for i in range(m1.m):
			for j in range(m1.n):
				e=m1.mat[i][j]+m2.mat[i][j]
				rowmat.append(e)
			addMatrix.append(rowmat)
			rowmat=[]
		return addMatrix
	
	def subMat(self,m1,m2):
		subMatrix=[]
		rowmat=[]
		for i in range(m1.m):
			for j in range(m1.n):
				e=m1.mat[i][j]-m2.mat[i][j]
				rowmat.append(e)
			subMatrix.append(rowmat)
			rowmat=[]
		return subMatrix
	
	def multMat(self,m1,m2):
		multMatrix=[]
		rowmat=[]
		sum=0
		for i in range(m1.m):
			for j in range(m2.n):
				for k in range(m2.n):
					sum+=m1.mat[i][k]*m2.mat[k][j]
				rowmat.append(sum)
				sum=0
			multMatrix.append(rowmat)
			rowmat=[]
		return multMatrix
				
	def transpose(self,mat):
		new=[]
		rowmat=[]
		for i in range(mat.m):
			for j in range(mat.n):
				e=mat.mat[j][i]
				rowmat.append(e)
			new.append(rowmat)
			rowmat=[]
		return new
		print(new)
	

def compare(m,n,p,q):
	if (m==p and n==q):
		return 1
	else:
		return 0

def compareMult(n,p):
	if (n==p):
		return 1
	else:
		return 0
	
again="y"
while again=="Y" or again=="y":
		mat1=Matrix(1)
		mat2=Matrix(2)
		m=mat1.m
		n=mat1.n
		p=mat2.m
		q=mat2.n
		opAgain="y"
		while opAgain=="Y" or opAgain=="y":
			option=int(input("Enter\n1) For addition\n2) For subraction\n3) For multiplication\n4) For transpose"))
			if option==1:
				check=compare(m,n,p,q)
				if check:
					print("Addition of matrices is",Matrix.addMat(mat1,mat2))
				else:
					print("cannot be addedd")
					
			elif option==2:
				check=compare(m,n,p,q)
				if check:
					print("Subtraction of matrices is",Matrix.subMat(mat1,mat2))
				else:
					print("cannot be subtracted")
					
			elif option==3:
				check=compareMult(n,p)
				if check:
					print("Multiplication of matrices is",Matrix.multMat(mat1,mat2))
				else:
					print("cannot be multiplied")
					
			elif option==4:	
				print("Transpose of matrix 1 is",Matrix.transpose(mat1))
				print("Transpose of  matrix 2 is",Matrix.transpose(mat2))
			else:
				print("Wrong input")
			opAgain=input("want to perform other operations? (Y/N)")
		again=input("want to perform operation of different matrices? (Y/N)")