import pandas as pd
import numpy as np

asking_prices = pd.Series([12500, 9800, 15000, 18750, 24000, 7500, 16800])

fair_prices = pd.Series([11800, 10500, 14500, 17000, 22000, 9000, 15500])

print("Asking Prices:")
print(asking_prices)
print("\nFair Prices:")
print(fair_prices)

good_deals = asking_prices < fair_prices

print("\nCar Details with Deal Analysis:")
car_data = pd.DataFrame({
    'Asking Price': asking_prices,
    'Fair Price': fair_prices,
    'Is Good Deal': good_deals
})
print(car_data)

good_deal_indices = np.where(good_deals)[0].tolist()

print("\nIndices of Good Deals:")
print(good_deal_indices)

print("\nGood Deals Only:")
print(car_data[good_deals])