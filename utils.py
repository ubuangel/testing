import math
#code smell?
def esprimo(n):
    if n<0:
        return "numeros negativos no son permitidos"
    if n<=1:
        return False

    if n==2:
        return True
    if n % 2 = 0:
        return False

    for i in range(2,int( math.sqrt(n))+1):
        if n%i==0:
            return False


    return True
def cubico(n):
    return n*n*n
def di_hola(cadena):
    return "hola"+cadena
