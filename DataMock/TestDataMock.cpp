// DataMock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DataMock.hpp";

int main()
{
	SecurityInput secA = { "AAPL", 10000000, 250,  100, 1.5, 1000, 200, 100};
	vector<SecurityInput> secInputs = { secA };
	DataMock generator = DataMock(secInputs);
	generator.GenerateData();
	generator.PrintData();
}
