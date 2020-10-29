class search:
    def __init__(self):
        self.arr = []
        self.n = int(input("Enter number of students that attended:"))
        for _ in range(self.n):
            self.arr.append(int(input()))        
        
    def linearSearch(self, x):
        var = -1
        for i in range (0, self.n): 
            if (self.arr[i] == x): 
                var = i
        if var == -1:
            print("Not found!")
        else:
            print("Element found at " + str(var) + "index")  


    def sentinelSearch(self, x):  
        last = self.arr[self.n - 1]  
        self.arr[self.n - 1] = x  
        i = 0
    
        while (self.arr[i] != x) :  
            i += 1
  
        self.arr[self.n - 1] = last  
  
        if ((i < self.n - 1) or (x == self.arr[self.n - 1])) :  
            print(str(x), "is present at index", str(i))  
        else: 
            print("Not found")  


    def fibonacciSearch(self, x): 
        fib2 = 0  
        fib1 = 1     
        fib = fib2 + fib1  
        var = -1
        
        while (fib < self.n): 
            fib2 = fib1 
            fib1 = fib 
            fib = fib2 + fib1 
    
        offset = -1
        while (fib > 1):  
            i = min(offset+fib2, self.n-1) 
            if (self.arr[i] < x): 
                fib = fib1 
                fib1 = fib2 
                fib2 = fib - fib1 
                offset = i 
    
            elif (self.arr[i] > x): 
                fib = fib2 
                fib1 = fib1 - fib2 
                fib2 = fib - fib1 
    
            else : 
                var = i 
    
        if(fib1 and self.arr[offset+1] == x): 
            var = offset+1

        if var == -1:
            print("Not found!")
        else:
            print("Element found at " + str(var) + "index")  

    def binarySearch(self, x): 
        var = -1
        l = 0
        while l <= self.n: 
            mid = l + (self.n - l) // 2
            if self.arr[mid] == x: 
                var =  mid 
            elif self.arr[mid] < x: 
                l = mid + 1 
            else: 
                self.n = mid - 1
        if var == -1:
            print("Not found!")
        else:
            print("Element found at " + str(var) + "index")  


flag = True
while(flag):
    S = search()
    S1 = search()
    no = int(input("Enter the number to be searched: "))
    choice = int(input("1) Linear search \n2) Sentinel search \n3) Binary search \n4) Fibonacci search \n5) Exit"))
    if choice == 1:
        S.linearSearch(no)
    elif choice == 2:
        S.sentinelSearch(no)
    elif choice == 3: 
        S.binarySearch(no)
    elif choice == 4: 
        S.fibonacciSearch(no)
    elif choice == 5:
        flag = False
    else:
        print("Invalid choice! Exiting...")
        flag = False