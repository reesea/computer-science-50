from cs50 import get_string
from cs50 import sys


def main():

    # check command line argument
    if len(sys.argv) != 2:
        print("Hello, Please enter a valid command line argument")
        exit(1)

    key = int(sys.argv[1])

    # plain text string from user
    plaintext = get_string("Plaintext: ")
    print("ciphertext: ", end="")

    # iterate thru string and output ciphertext
    for i in range(len(plaintext)):
        # check for uppercase
        if str.isupper(plaintext[i]):
            upper = (((ord(plaintext[i]) - 65) + key) % 26) + 65
            print(chr(upper), end="")

        # check for lowercase
        elif str.islower(plaintext[i]):
            lower = (((ord(plaintext[i]) - 97) + key) % 26) + 97
            print(chr(lower), end="")
        # else print
        else:
            print("{}".format(plaintext[i]), end="")

    # print new line
    print()


if __name__ == "__main__":
    main()
