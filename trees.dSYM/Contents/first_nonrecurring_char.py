# white board: find the first non-recurring character in a string. i.e. input "abbcdcaea" would return "d"

def non_rec(string):
    if not isinstance(string, str):
        print("Input is not of type: String")
        return None  # Return None to indicate an error in input type

    uniques = []

    for letter in string:
        if letter in uniques:
            uniques.remove(letter)
        else:
            uniques.append(letter)

    if uniques:  # Check if the list is not empty
        return uniques[0]
    else:
        return None  # Return None if all characters recur

# Example usage:
input_string = "abbcdcaea"
result = non_rec(input_string)
if result is not None:
    print(f"The first non-recurring character is '{result}'.")
else:
    print("No non-recurring character found.")
