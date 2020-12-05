// DataMock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DataMock.hpp";

int main()

{
    // SecID, Time_mu, Time_sig, Price_mu, Price_sig, Quantity_mu, Quantity_sig, num_orders
	SecurityInput secA = { "AAPL", 1603593025, 750,  120.50, 0.35, 120, 40, 25};
	SecurityInput secB = { "GOOG", 1603493025, 350,  1000, 2.25, 15, 4, 15 };
	SecurityInput secC = { "AMZN", 1603493025, 450,  2500, 10.2, 7, 6, 5 };

	vector<SecurityInput> secInputs = { secA, secB, secC};
	DataMock generator = DataMock(secInputs);
	generator.GenerateData();
	// generator.PrintData();
	generator.SaveData("sample.csv");
}
