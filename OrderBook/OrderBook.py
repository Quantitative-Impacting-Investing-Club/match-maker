import pandas as pd
import numpy as np
import sys

sys.path.append('../') 
from MatchObject.Match import Match

class OrderBook:
    def __init__(self):
        self.orders = pd.DataFrame() # To be filled when orders are added
    
    def add_orders(self, orders):
        self.orders = self.orders.append(orders, ignore_index=True)

        return 1
    
    def update_matches(self, matches):
        # Take in list of Match Object
        # 
        pass
