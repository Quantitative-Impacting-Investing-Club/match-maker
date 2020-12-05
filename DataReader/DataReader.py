import sys
import os

sys.path.append('../') 
from OrderBook.OrderBook import OrderBook
from MatchObject.Match import Match

import pandas as pd

class DataReader:
    def __init__(self):
        self.order_book = OrderBook()

    def read_file(self, file_path):
        # Read Data in
        data = pd.read_csv(file_path, index_col=False)
        self.order_book.add_orders(data)

        # Call requisite function to match orders to orders left
        print(self.order_book.orders)

        # Update order Book

    def receive_order(self, order):
        order_dict = {
            'SecID' : order.securityId, 
            'Time' : order.time,
            'Quantity' : order.quantity,
            'Price' : order.price,
            'OrderType' : order.orderType,
            'OrderID' : order.orderId
        }

        self.order_book.add_orders(order_dict)
        print(self.order_book.orders)
