// DataMock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DataMock.hpp";

int main()
{
	SecurityInput secA = { "AAPL", 1000000000000, 250,  100, 1.5, 1000, 200, 100};
	SecurityInput secA = { "GOOG", 1000000000135, 1000,  1000, 2.5, 1000, 200, 100 };

	vector<SecurityInput> secInputs = { secA };
	DataMock generator = DataMock(secInputs);
	generator.GenerateData();
	generator.PrintData();
	generator.SaveData("sample.csv");
}
