card_number = input("Credit card number:")
card_number2 = card_number[::-1]
valid = 0
i = 0
luhnMain = 0
luhn = 0
luhn2 = 0
bug = 0

# First phase
while i < len(card_number):
    if (i+1) % 2 == 0:
        doubled = str(int(card_number2[i]) * 2)
        luhn += int(doubled[0]) + int(doubled[1]) if len(doubled) == 2 else int(doubled)
    else:
        luhn2 += int(card_number2[i])

    i += 1

# Second phase
luhnMain = luhn + luhn2

# Third phase
if luhnMain%10 == 0:
    # Valid number
    valid = 1

# Fourth phase - What type of card?
if valid == 1:
    # American Express (AMEX)
    if len(card_number) == 15 and (card_number[:2] == "34" or card_number[:2] == "37"):
        print(luhn, luhn2, luhnMain) # for debugging
        print("AMEX")
    # Mastercard (MASTERCARD) , Visa (VISA)
    if len(card_number) == 13 or len(card_number) == 16:
        if card_number[0] == "4":
            print(luhn, luhn2, luhnMain) # for debugging
            print("VISA")
        else:
            print(luhn, luhn2, luhnMain) # for debugging
            print("MASTERCARD")
else:
    print(luhn, luhn2, luhnMain) # for debugging
    print("INVALID")