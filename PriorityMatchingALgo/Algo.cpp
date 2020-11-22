#include "Algo.hpp"
#include <iostream>
#include <fstream>



// Default Constructor
Algo::Algo() : OrderSet({}), PriceQueue({}), BuyOrderMap({}), SellOrderMap({})
{};

// Parametrized Constructor
Algo::Algo(vector<SecurityInput> OrderSet) :OrderSet(OrderSet), PriceQueue({}), BuyOrderMap({}), SellOrderMap({})
{};


vector<SecurityInput> OrderSet;
vector<double> PriceQueue;
map<double, queue<SecurityInput>> BuyOrderMap;
map<double, queue<SecurityInput>> SellOrderMap;


// Copy Constructor
Algo::Algo(const Algo& source) : OrderSet(source.OrderSet), PriceQueue(source.PriceQueue), BuyOrderMap(source.BuyOrderMap), SellOrderMap(source.SellOrderMap)
{};

// Destructor
Algo::~Algo()
{};

// Assignment Operator
Algo& Algo::operator = (const Algo& source)
{
	if (this == &source)
	{
		return *this;
	}

	OrderSet = source.OrderSet;
	PriceQueue = source.PriceQueue;
	BuyOrderMap = source.BuyOrderMap;
	SellOrderMap = source.SellOrderMap;
	return *this;
}



void Algo::AdditionalOrder(vector<SecurityInput> OrderSet2)
{
	OrderSet.insert(OrderSet.end(), OrderSet2.begin(), OrderSet2.end());
}

bool sortbytime(SecurityInput i, SecurityInput j) { return (i.time_mu < j.time_mu);}


void Algo::SortOrderByTimeStamp()
{
	sort(OrderSet.begin() + 4, OrderSet.end(), sortbytime);
}

void Algo::CreateQueue()
{
	for (int i = 0; i < OrderSet.size(); i++)
	{	
		// Price is contained
		if (find(PriceQueue.begin(), PriceQueue.end(), OrderSet[i].price_mu) != PriceQueue.end()) {
		}
		else {
			PriceQueue.push_back(OrderSet[i].price_mu);
		}

		map<double, queue<SecurityInput>>::iterator it = BuyOrderMap.find(OrderSet[i].price_mu);
		if (it != BuyOrderMap.end())
		{
			//element found;
			(it->second).push(OrderSet[i]);
		};


		map<double, queue<SecurityInput>>::iterator it = SellOrderMap.find(OrderSet[i].price_mu);
		if (it != SellOrderMap.end())
		{
			//element found;
			(it->second).push(OrderSet[i]);
		};
	}
}


void Algo::Execute()
{
	sort(OrderSet.begin() + 4, OrderSet.end(), PriceQueue);
	for (int i = 0; i < PriceQueue.size(); i++)
	{
		while (SellOrderMap[i].size() > 0 | BuyOrderMap[i].size() > 0)
		{
			SecurityInput SellOrder = SellOrderMap[i].front();
			SecurityInput BuyOrder = BuyOrderMap[i].front();

			SellOrder.quantity_mu -= BuyOrder.quantity_mu;
			BuyOrder.quantity_mu -= SellOrder.quantity_mu;

			if (SellOrder.quantity_mu <= 0)
			{
				SellOrderMap[i].pop();
			}
			if (BuyOrder.quantity_mu <= 0)
			{
				BuyOrderMap[i].pop();
			}

		}

	}
}


vector<SecurityInput> Algo::ReturnOrderSet()
{
	
}

