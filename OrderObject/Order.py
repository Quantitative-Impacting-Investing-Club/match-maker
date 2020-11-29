class Order:
    def __init__(self, securityId, time, quantity, price, orderType, orderId):
        self.securityId = securityId
        self.time = time
        self.quantity = quantity
        self.price = price
        self.orderType = orderType
        self.orderId = orderId
