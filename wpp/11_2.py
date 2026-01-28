import pandas as pd

s = pd.Series(['X', 'Y', 'T', 'Aaba', 'Baca', 'CABA', None, 'bird', 'horse', 'dog'])

print("Original Series:")
print(s)
print("\n")

upper_case = s.str.upper()
print("Uppercase values:")
print(upper_case)
print("\n")

lower_case = s.str.lower()
print("Lowercase values:")
print(lower_case)
print("\n")

string_lengths = s.str.len()
print("Length of each string:")
print(string_lengths)