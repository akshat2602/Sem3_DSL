class sort:
    def __init__(self):
        self.arr = []
        self.n = int(input("Enter number of students:"))
        print("Enter the second year percentages of the students: ")
        for _ in range(self.n):
            self.arr.append(int(input()))        
        
    def display(self):
        for i in range (self.n):
            print(self.arr[i])

    def insertionSort(self): 
        for i in range(self.n): 
            temp = self.arr[i] 
            j = i-1
            while j >= 0 and temp < self.arr[j] : 
                    self.arr[j + 1] = self.arr[j] 
                    j -= 1
            self.arr[j + 1] = temp 
        

    def shellSort(self): 
        gap = (self.n)//2
        while gap > 0:
                 
            for i in range(gap,self.n): 
                temp = self.arr[i] 
                j = i

                while  j >= gap and self.arr[j-gap] >temp: 
                    self.arr[j] = self.arr[j-gap] 
                    j -= gap 

                self.arr[j] = temp 
            gap //= 2


flag = True
while(flag):
    S = sort()
    choice = int(input("1) Insertion sort \n2) Shell sort \n3) Exit"))
    if choice == 1:
        S.insertionSort()
        S.display()
    elif choice == 2:
        S.shellSort()
        S.display()
    elif choice == 3:
        flag = False
    else:
        print("Invalid choice! Exiting now.")
        flag = False