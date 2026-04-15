# Runs in O(k*log^3(n)) time where k is the number of rounds we want to run the test for.
# Checking divisors is O(sqrt(n)) time, so this is much faster than that at high N.
num = 2011
import random 
not_done = True 
import time 
start_time = time.time()

def euclid_alg(a, b):
    while b:
        a, b = b, a % b
    return a

if num%2 == 0:
    print("COMPOSITEEEEEEEEE")
    not_done = False 

runs = 0 
possible_guesses = [i for i in range(1, num-1)]
while runs <= 5 and not_done == True:
    test = random.choice(possible_guesses)
    possible_guesses.remove(test)
    if euclid_alg(test, num) != 1:
        print("COMPOSITEEEEEEEEE")
        end_time = time.time()
        not_done = False 
        continue 
    val1 = test**((num-1)//2)%num
    # Now calc jacobi symbol of (a / n)
    a = test 
    n = num   
    sign = 1 
    while a != 0:
        while a%2 == 0:
            a = a//2 
            k = n%8 
            if k == 3 or k == 5:
                sign = -sign 
        if a%4 == 3 and n%4 == 3:
            sign = -sign 
        a, n = n, a 
        a = a%n  
    if n == 1: 
        val2 = sign 
    else:
        val2 = 0 
    
    if val1 != val2%num:
        print("COMPOSITEEEEEEEEE")
        end_time = time.time()
        not_done = False 
        continue 
    
    runs += 1 

if not_done == True:
    print("PRIMEEEEEEEEEEEEE") 
    end_time = time.time()
    
print(f"Time taken: {end_time-start_time} seconds")
