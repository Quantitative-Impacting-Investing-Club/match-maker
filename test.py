from DataReader.DataReader import DataReader
from OrderObject.Order import Order

a = DataReader()
a.read_file('TestData/sample copy.csv')

order = Order(
    "securityId", "2020-10-25-02-47-35", 100, 120.39, "BUY", 4
)

a.receive_order(order)
