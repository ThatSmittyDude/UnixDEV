import math

def calculate_square_root(number):
    if number < 0:
        return "Cannot calculate the square root of a negative number."
    return math.sqrt(number)

num = float(input("Enter a number: "))
result = calculate_square_root(num)
print(f"The square root of {num} is {result}.")
