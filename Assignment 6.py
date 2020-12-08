class sort:
    def __init__(self):
        self.arr = []
        self.n = int(input("Enter number of students:"))
        print("Enter the first year percentages of the students: ")
        for _ in range(self.n):
            self.arr.append(int(input()))        
        
    def display(self):
        for i in range (self.n):
            print(self.arr[i])

    def quickSort(self):
        pass


flag = True
while(flag):
    choice = int(input("1) Quick sort \n2) Exit"))
    S = sort()
    if choice == 1:
        S.quickSort()
        S.display()
    elif choice == 2:
        flag = False
    else:
        print("Invalid choice! Exiting now.")
        flag = False