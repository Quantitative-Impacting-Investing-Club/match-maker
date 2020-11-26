// Base Class for Option (Abstract Class)


#ifndef DATAMOCK_HPP
#define DATAMOCK_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/uniform_01.hpp>
#include <boost/variant.hpp>
#include <boost/random.hpp>
#include <time.h>

using namespace std;



struct SecurityInput
{
	string securityID;
	int time_mu; // In seconds since epoch
	double time_sig;
	double price_mu;
	double price_sig;
	int quantity_mu;
	double quantity_sig;
	int num_orders;
};


class DataMock
{
	// Parameters that define an option valuation
private:
	vector<SecurityInput> SecurityVec;
	vector<vector<boost::variant<string, string, int, double, string, int>>> OrderCollections;
	int OrderID;
	
public:
	// Constructors & Destructor
	DataMock(); // Default constructor
	DataMock(vector<SecurityInput> SecVec); // Parametrized Constructor
	DataMock(const DataMock& source); // Copy constructor
	virtual ~DataMock(); // Destructor

	// Assignment Operator
	DataMock& operator = (const DataMock& source);

	// Generate Data Matrix
	void GenerateData();
	void GenerateSecData(const SecurityInput& SecInp);

	// Print
	void PrintData() const;

	// Save as CSV/TXT
	void SaveData(string fp);

};

#endif