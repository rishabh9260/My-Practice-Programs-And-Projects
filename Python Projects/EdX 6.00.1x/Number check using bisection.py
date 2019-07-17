low = 0
high = 100
ch = 'x'
print("Please think of a number between 0 and 100!")
while True:
    guess = int((high + low)/2)
    print("Is your secret number " + str(guess) + "?")
    print("Enter 'h' to indicate the guess is too high.", end =" ")
    print("Enter 'l' to indicate the guess is too low.", end =" ")
    print("Enter 'c' to indicate I guessed correctly.", end =" ")
    ch = input()
    if ch == 'h':
        high = guess
    elif ch == 'l':
        low = guess
    elif ch == 'c':
        print("Game over. Your secret number was: " + str(guess))
        break
    else:
        print("Sorry, I did not understand your input.")