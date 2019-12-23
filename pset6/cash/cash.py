from cs50 import get_float
from math import floor


while True:
    dollars = get_float("Change owed: ")
    cents = floor(dollars * 100)

    if cents > 0:
        break

quarters = cents // 25
dimes = (cents % 25) // 10
nickels = ((cents % 25) % 10) // 5
pennies = ((cents % 25) % 10) % 5

print(f"{quarters + dimes + nickels + pennies}")