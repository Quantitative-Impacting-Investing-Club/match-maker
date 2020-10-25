#include "DataMock.hpp"
#include <iostream>
#include <fstream>



// Default Constructor
DataMock::DataMock() : SecurityVec({}), OrderCollections({}), OrderID(0)
{};

// Parametrized Constructor
DataMock::DataMock(vector<SecurityInput> SecVec) :SecurityVec(SecVec), OrderCollections({}), OrderID(0)
{};


// Copy Constructor
DataMock::DataMock(const DataMock& source) : SecurityVec(source.SecurityVec), OrderCollections(source.OrderCollections), OrderID(source.OrderID)
{};

// Destructor
DataMock::~DataMock()
{};

// Assignment Operator
DataMock& DataMock::operator = (const DataMock& source)
{
	if (this == &source)
	{
		return *this;
	}

	SecurityVec = source.SecurityVec;
	OrderCollections = source.OrderCollections;
	OrderID = source.OrderID;
	return *this;
}

// Generate Data
void DataMock::GenerateData() 
{
	for (int i = 0; i < SecurityVec.size(); i++)
	{
		GenerateSecData(SecurityVec[i]);
	}
}

// Generate by Security
void  DataMock::GenerateSecData(const SecurityInput& SecInp)
{	

	// Create Generator using normal distribution
	boost::lagged_fibonacci607 rng;

	boost::normal_distribution<> time_dist(SecInp.time_mu, SecInp.time_sig);
	boost::normal_distribution<> quant_dist(SecInp.quantity_mu, SecInp.quantity_sig);
	boost::normal_distribution<> price_dist(SecInp.price_mu, SecInp.price_sig);


	boost::variate_generator<boost::lagged_fibonacci607&, boost::normal_distribution<> > time_gen(rng, time_dist);
	boost::variate_generator<boost::lagged_fibonacci607&, boost::normal_distribution<> > quant_gen(rng, quant_dist);
	boost::variate_generator<boost::lagged_fibonacci607&, boost::normal_distribution<> > price_gen(rng, price_dist);


	// For loop for each order entry created
	time_t t;
	int q;
	double p;
	string order_type;
	vector<boost::variant<string, string, int, double, string, int>> order_entry;
	struct tm* time_info;
	string time_string;


	for (int i = 0; i < SecInp.num_orders; i++)
	{
		t = (time_t) time_gen();
		q = quant_gen();
		p = ((float) round(price_gen() * 100))/100;

		if (rand() % 2)
		{
			order_type = "BUY";
		}
		else
		{
			order_type = "SELL";
		}

		time_info = gmtime(&t);
		string time_string = asctime(time_info);

		t = (int) t;
		order_entry = { SecInp.securityID, time_string, q, p, order_type, ++OrderID};
		OrderCollections.push_back(order_entry);
	}
}

// Print Data
void  DataMock::PrintData() const
{
	for (int i = 0; i < OrderCollections.size(); i++)
	{
		cout << "Security ID: " << OrderCollections[i][0] << "Time: " << OrderCollections[i][1] << " Quantity: " << OrderCollections[i][2] << " Price: " << OrderCollections[i][3] << " Order Type: " << OrderCollections[i][4] << " OrderID: " << OrderCollections[i][5] << endl;
	}
}

// Save Data
void DataMock::SaveData(string fp)
{
}

