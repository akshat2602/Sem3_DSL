class Set:
    
    def __init__(self):
        self.elements = []
    
    def addelement(self, x):
        flag = 0
        for i in range(len(self.elements)):
            if self.elements[i] == x:
                flag += 1
        if flag == 0:
            self.elements.append(x)
        else:
            print("Duplicate element!")
            self.addelement(int(input()))

    def isemptyset(self):
        return self.elements == []

    def display(self):
        print(self.elements)

    def length(self):
        print(len(self.elements))
    
    def union(self, set2):
        unionSet = Set()
        for i in self.elements:
            unionSet.addelement(i)
        for k in range(len(set2.elements)):
            flag = 0
            for j in range(len(unionSet.elements)):
                if set2.elements[k] == unionSet.elements[j]:
                    flag += 1
                else: 
                    pass
            if flag == 0:
                unionSet.addelement(set2.elements[k])

        return unionSet

    def intersection(self, set2):
        intersectionSet = Set()
        for i in range(len(self.elements)):
            for j in range(len(set2.elements)):
                if self.elements[i] == set2.elements[j]:
                    intersectionSet.addelement(self.elements[i])
                
        return intersectionSet

    def A_minus_B(self, set2):
        A_B=Set()
        for i in range(len(self.elements)):
            flag = 0
            for j in range(len(set2.elements)):
                if self.elements[i] == set2.elements[j]:
                    flag += 1
                    break
            if flag == 0:
                A_B.addelement(self.elements[i])
        return A_B

def playIntersection(set1, set2):
    temp = set1.intersection(set2)
    return temp

def playUnion(set1, set2):
    temp = set1.union(set2)
    return temp

def playEitherNotBoth(set1, set2):
    a = set1.A_minus_B(set2)
    b = set2.A_minus_B(set1)
    temp = playUnion(a ,b)
    return temp

def play2not3(set1, set2, set3):
    x = playIntersection(set1, set3)
    y = playIntersection(set2, set3)
    z = playUnion(set1, set2)
    temp1 = z.A_minus_B(x)
    temp2 = temp1.A_minus_B(y)
    return temp2

def playNeither(set1, set2, universalSet):
    temp = universalSet.A_minus_B(set1.union(set2))
    return temp

total = int(input("Input total number of students: "))
print("Input student roll numbers: ")
U = Set()
for i in range(total):
    U.addelement(int(input()))
U.display()

cricket = int(input("Input total number of students who play cricket: "))
print("Input student roll numbers for cricket: ")
C = Set()
for i in range(cricket):
    C.addelement(int(input()))
C.display()

football = int(input("Input total number of students who play football: "))
print("Input student roll numbers for football: ")
F = Set()
for i in range(football):
    F.addelement(int(input()))
F.display()

badminton = int(input("Input total number of students who play badminton: "))
print("Input student roll numbers for badminton: ")
B = Set()
for i in range(badminton):
    B.addelement(int(input()))
B.display()
flag = True

while flag:
    print("""1. List students who play both cricket and badminton
2. List students who play either cricket or badminton but not both
3. Number of students who play neither cricket nor badminton
4. Number of students who play cricket and football but not badminton
5. Exit""")
    counter = int(input())
    if counter == 1:
        temp = playIntersection(C, B)
        temp.display()
    elif counter == 2:
        temp = playEitherNotBoth(C, B)
        temp.display()
    elif counter == 3:
        temp = playNeither(C, B, U)
        temp.length()
    elif counter == 4: 
        temp = play2not3(C, F, B)
        temp.length()
    elif counter == 5:
        flag = False
    else: 
        print("Invalid input!")

