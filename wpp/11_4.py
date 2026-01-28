import pandas as pd
import numpy as np

np.random.seed(42)
schedule = pd.DataFrame({
    'day': range(1, 11),
    'john_visiting': np.random.choice([True, False], size=10),
    'judy_visiting': np.random.choice([True, False], size=10)
})

schedule['party'] = schedule['john_visiting'] & schedule['judy_visiting']

schedule['days_til_party'] = 99

for i in range(len(schedule)):
    if schedule.loc[i, 'party']:
        schedule.loc[i, 'days_til_party'] = 0
    else:
        for j in range(i+1, len(schedule)):
            if schedule.loc[j, 'party']:
                schedule.loc[i, 'days_til_party'] = j - i
                break

print("Schedule for the next 10 days:")
print(schedule)

print("\nDay-by-day summary:")
for i, row in schedule.iterrows():
    party_status = "PARTY TODAY!" if row['party'] else f"{int(row['days_til_party'])} days until next party"
    if row['days_til_party'] == 99:
        party_status = "No party scheduled within the 10-day period"
    print(f"Day {row['day']}: John visiting: {row['john_visiting']}, Judy visiting: {row['judy_visiting']} - {party_status}")