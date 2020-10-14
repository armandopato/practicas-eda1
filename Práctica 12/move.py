def move(n, x, y, z):
    if n == 1:
        print("move", x, "to", y)
    else:
        move(n-1, x, z, y)
        print("move", x, "to", y)
        move(n-1, z, y, x)

move(10, "A", "B", "C")