#	CONSEGNA
#Scrivere un programma che dati in input due numeri interi positivi
#N ed M (M sottomultiplo di N), disegni una scacchiera
#N*MxN*M con blocchi di asterischi M*M.

print("Inserisci numeri interi positivi\nIl 1° deve essere un multiplo del 2°")
n = int(input("Inserisci primo numero:\t"))
m = int(input("Inserisci un sottomultiplo del primo: "))
right = n%m==0

while not(m>0 and n>0 and right and m!=1):
    n = int(input("Inserisci primo numero:\t"))
    m = int(input("Inserisci un sottomultiplo del primo: "))

S = "*" #Star
L = "-" #Line
c = int((m*n)/(2*m))

for i in range(0,c):
    for i1 in range(0,m):
        print((S*m+L*m)*c)
    for i2 in range(0,m):
        print((L*m+S*m)*c)

#m=2
#n=4
#**--**--
#**--**--
#--**--**
#--**--**
#**--**--
#**--**--
#--**--**
#--**--**
