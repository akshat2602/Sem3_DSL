class String:                                      
    def __init__(self):                            
        self.s=[]

    def Convert_stringTolist(self,str_):                
        for i in str_:
            self.s.append(i)
        

    def list_of_words(self):
        word_list = []
        w = ""
        for i in range(0,len(self.s)):
            if self.s[i] != " ":
                w += self.s[i]
            else:
                word_list.append(w)
                w = ""
        word_list.append(w)
        return word_list


    def longest_word(self):                             
        word = self.list_of_words()
        longest_current = word[0]
        for w in range(0,len(word)):
            if len(word[w]) > len(longest_current):
                longest_current = word[w]
        print("Longest word is :",longest_current)


    def frequency_Of_character(self,chr1):                     
        count = 0
        for i in range(len(self.s)):
            if self.s[i]==chr1:
                count = count + 1
        return count

    
    def palindromeCheck(self,pstr):                             
        rev = []
        is_p = True        
        for i in range(len(pstr.s)-1,-1,-1):
            rev.append(pstr.s[i])
        for i in range(len(pstr.s)):
            if pstr.s[i] != rev[i]:
                is_p = False
                break
            
        return is_p

    
    def Check_for_substring(self, subString):                        
        scount = 0
        match = True
        for i in range(0,len(self.s)):
            if subString.s[0] == self.s[i]:
                for j in range(0,len(subString.s)):
                    if subString.s[j] != self.s[i+j]:
                        match = False
                        break
                    else:
                        scount += 1
                        if match == True and scount == len(subString.s):
                            print("Index of first appearance of substring is :", i+1 )
        
        if match == False:
            print("Substring not found!") 


    def Word_frequency(self):
        occ_list = []
        word = self.list_of_words()
        for i in word:
            if i not in occ_list:
                occ_list.append(i)
        index = 0

        list1 = [['name', 0]]
        for i in occ_list:
            for j in word:
                if i == j:
                    list1[index][0] = i
                    list1[index][1] += 1
            if i != occ_list[len(occ_list) - 1]:
                list1.append(['name', 0])
                index += 1

        return list1  


print("1) Word with the longest length: ")
print("2) Frequency of a particular character: ")
print("3) Is the string a palindrome: ")
print("4) Index of first appearance of a substring: ")
print("5) Frequency of each word in the main string: ")


main_string = input("Enter the main string: ")
sstring=input("Enter sub string:")
pstring=input("Enter palindromic/non palindromic string:")
obj = String()                                                   
obj2 = String()
obj3 = String()

obj.Convert_stringTolist(main_string)
obj2.Convert_stringTolist(sstring)
obj3.Convert_stringTolist(pstring)

p = True

while p:

    choice = int(input("Enter your choice: "))
    if choice == 1:
        obj.longest_word()

    elif choice == 2:
        chr1 = input("Enter a character: ")
        print("The frequency of the above character is:", obj.frequency_Of_character(chr1))
    
    elif choice == 3: 
        print("Whether the above string is palindrome:", obj.palindromeCheck(obj3))
    
    elif choice == 4:
         obj.Check_for_substring(obj2)

    elif choice==5:
        print("Occurence of each word in given string :",obj.Word_frequency())
    
    else:
        p = False