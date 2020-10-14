def activities(s, f, n):
    print("Selected activities are:")
    i = 0
    print("A1")
    
    for j in range(1,n):
        if s[j] >= f[i]:
            print("A" + str(j+1))
            i = j


s = [1, 2, 3, 2, 4, 5, 6, 8, 7]
f = [4, 5, 6, 8, 6, 7, 7, 12, 9]

n = len(s)
activities(s, f, n)