class StudMarks:
    def __init__(self, l):
        self.l = l
        self.size = 0
        for _ in l:
            self.size += 1

    @staticmethod
    def partition(l, a, b):
        i = a - 1
        pvt = l[b]
        for j in range(a, b):
            if l[j] < pvt:
                i += 1
                l[i], l[j] = l[j], l[i]
        l[i + 1], l[b] = l[b], l[i + 1]
        return i + 1

    def qcksort(self, l, a, b):
        l1 = l[:]
        if a < b:
            pt = self.partition(l1, a, b)
            l1 = self.qcksort(l1, a, pt - 1)
            l1 = self.qcksort(l1, pt + 1, b)
        return l1

    def quick(self):
        return self.qcksort(l, 0, self.size - 1)


l = list(map(float, input("Enter the first year percentages of students separated by whitespaces: ").split()))
s = StudMarks(l)
while True:
    print("-" * 150)
    l1 = s.quick()
    for i in range(s.size - 1, -1, -1):
        if s.size - i > 5:
            break
        print(str(s.size - i) + ". " + str(l1[i]))
        i += 1
    print(l1)
    print("Re-Enter percentages of students? (Y/N)")
    ch = input(">>>")
    if ch == "Y":
        l = list(map(float, input("Enter the second year percentages of students separated by whitespaces: ").split()))
        s = StudMarks(l)
    else:
        break