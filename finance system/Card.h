#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;


class Category
{
	class Cost
	{
	public:

		double expence;
		tm* ltm;

		Cost(double expence, time_t now)
		{
			this->expence = expence;
			ltm = localtime(&now);
		}
	};

	string categoryName;
	vector<Cost> costs;

public:

	Category(string name) : categoryName(name) {}

	string getName();
	void addExpence(double money, time_t now);
	double expPerDay(int day, int month);
	double expPerMonth(int month);
	double monthlyMaxCost(int month);
};

class Card
{
protected:

	string cardName;
	double cash;
	vector<Category> categories;
	ofstream fout;
	string report;

public:

	Card(string name, double cash) : cardName(name), cash(cash) {}

	string getName();
	void printCategories();
	void addCash(double money);
	void addExpenxe(double money, time_t now, int i);
	void addCategory(string name);
	void dailyReport(int day, int month);
	void monthlyReport(int month);
	void monthlyRating(int month);
	void monthlyCategory(int month);
	void save();
};
