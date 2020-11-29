import pandas as pd
import numpy as np

class OrderBook:
    def __init__(self):
        self.orders = pd.DataFrame() # To be filled
    
    def add_orders(self, orders):
        if isinstance(orders, pd.DataFrame):
            self.orders = self.orders.append(orders, ignore_index=True)

        return 1
    
    def update_matches(self, matches)
