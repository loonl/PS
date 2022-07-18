a,b,c = input().split()
a,b,c = int(a),int(b),int(c)
a %= b
for i in range(c-1):
    a = (a*10)%b
    
print((a*10) // b)