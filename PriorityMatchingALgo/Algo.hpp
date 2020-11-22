#pragma once
// Base Class for Option (Abstract Class)


#ifndef ALGO_HPP
#define ALGO_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>
#include <map>
#include <queue>

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
	double fulfill_pq;
	double fulfill_quantity;
	double avg_fulfill_price;
};


class Algo
{
	// Parameters that define an option valuation
private:
	vector<SecurityInput> OrderSet;
	vector<double> PriceQueue;
	map<double, queue<SecurityInput>> BuyOrderMap;
	map<double, queue<SecurityInput>> SellOrderMap;

public:
	// Constructors & Destructor
	Algo(); // Default constructor
	Algo(vector<SecurityInput> OrderSet); // Parametrized Constructor
	Algo(const Algo& source); // Copy constructor
	virtual ~Algo(); // Destructor

	// Assignment Operator
	Algo& operator = (const Algo& source);

	// Add Additional Order
	void AdditionalOrder(vector<SecurityInput> OrderSet);
	void CreateQueue();
	void SortOrderByTimeStamp();
	void Execute();
	vector<SecurityInput> ReturnOrderSet();
};

#endif