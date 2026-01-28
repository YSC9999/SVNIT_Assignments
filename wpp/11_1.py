import pandas as pd
from datetime import datetime

apr_4_2025 = pd.to_datetime('2025-04-04')
print("a) Date time object for Jan 15 2012:")
print(apr_4_2025)
print()

specific_time = pd.to_datetime('2025-04-05 21:20:00')
print("b) Specific date and time of 9:20 pm:")
print(specific_time)
print()

local_datetime = pd.Timestamp.now()
print("c) Local date and time:")
print(local_datetime)
print()

date_only = pd.Timestamp('2025-04-05').normalize()
print("d) A date without time:")
print(date_only)
print()

current_date = pd.Timestamp.now().normalize()
print("e) Current date:")
print(current_date)
print()

datetime_obj = pd.Timestamp('2025-04-05 14:35:27')
time_only = datetime_obj.time()
print("f) Time from a date time:")
print(time_only)
print()



current_time = datetime.now().time()
print("g) Current local time:")
print(current_time)