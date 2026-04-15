# Shor's Algorithm 
import random 
number1 = 1013
number2 = 19
product = number1*number2

def euclid_alg(a, b):
    while b:
        a, b = b, a % b
    return a

done = False 
while not done: 
    guess = random.randint(2, product-1)
    gcd = euclid_alg(product, guess)
    if gcd == 1:
        done2 = False
        counter = 0
        while not done2: 
            counter += 1 
            if pow(guess, counter, product) == 1: 
                done2 = True  
        if counter%2 == 0:
            betterguess = guess**(counter//2)+1
            gcd = euclid_alg(product, betterguess)
            if gcd != 1 and gcd != product:
                print(gcd, product//gcd)
                done = True 
    else: 
        print(gcd, product//gcd)
        done = True 



