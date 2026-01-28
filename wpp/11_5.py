import pandas as pd
import numpy as np

concerts = pd.DataFrame({
    'date': pd.date_range(start='2023-01-01', periods=100, freq='3D'),
    'artist': np.random.choice(['Taylor Swift', 'BTS', 'Coldplay', 'Beyonce'], 100),
    'venue': np.random.choice(['Madison Square Garden', 'Wembley Stadium', 'The O2', 'Hollywood Bowl'], 100)
})

concerts['year_month'] = concerts['date'].dt.strftime('%Y-%m')

artists = concerts['artist'].unique()
venues = concerts['venue'].unique()

artist_venue_pairs = pd.MultiIndex.from_product([artists, venues], names=['artist', 'venue'])

concert_counts = concerts.groupby(['year_month', 'artist', 'venue']).size().unstack(level=[1, 2])

all_months = pd.DataFrame(index=concerts['year_month'].unique(), columns=artist_venue_pairs)

for year_month in concerts['year_month'].unique():
    for artist in artists:
        for venue in venues:
            try:
                count = concert_counts.loc[year_month, (artist, venue)]
                all_months.loc[year_month, (artist, venue)] = count
            except (KeyError, ValueError):
                all_months.loc[year_month, (artist, venue)] = 0

all_months = all_months.fillna(0).astype(int)

all_months = all_months.sort_index()

print("Concert Counts by Year-Month and (Artist, Venue) Pair:")
print(all_months)

print("\nAlternative approach using pivot_table:")
pivot_result = pd.pivot_table(
    concerts, 
    index='year_month', 
    columns=['artist', 'venue'], 
    aggfunc='size', 
    fill_value=0
)
print(pivot_result)