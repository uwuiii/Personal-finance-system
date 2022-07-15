#include "Card.h"

string Category::getName()
{
	return categoryName;
}

void Category::addExpence(double money, time_t now)
{
	costs.push_back(Cost(money, now));
}

double Category::expPerDay(int day, int month)
{
	double _count = 0;

	for (int i = 0; i < costs.size(); i++)
	{
		if (costs[i].ltm->tm_mon + 1 == month && costs[i].ltm->tm_mday == day)
		{
			_count += costs[i].expence;
		}
	}

	return _count;
}

double Category::expPerMonth(int month)
{
	double _count = 0;

	for (int i = 0; i < costs.size(); i++)
	{
		if (costs[i].ltm->tm_mon + 1 == month)
		{
			_count += costs[i].expence;
		}
	}

	return _count;
}

double Category::monthlyMaxCost(int month)
{
	double max = costs[0].expence;

	for (int i = 0; i < costs.size(); i++)
	{
		if (costs[i].ltm->tm_mon + 1 == month)
		{
			if (costs[i].expence > max)
				max = costs[i].expence;
		}
	}

	return max;
}

string Card::getName()
{
	return cardName;
}

void Card::printCategories()
{
	cout << "Categories:" << endl;
	for (int i = 0; i < categories.size(); i++)
	{
		cout << i << " - " << categories[i].getName() << endl;
	}
	cout << '#';
}

void Card::addCash(double money)
{
	cash += money;
}

void Card::addExpenxe(double money, time_t now, int i)
{
	categories[i].addExpence(money, now);
}

void Card::addCategory(string name)
{
	categories.push_back(Category(name));
}

void Card::dailyReport(int day, int month)
{
	ostringstream ostr;

	ostr << "Report for " << day << "." << month << ":\n";

	for (int i = 0; i < categories.size(); i++)
	{
		ostr << categories[i].getName() << ": " << categories[i].expPerDay(day, month) << endl;
	}

	report = ostr.str();
	cout << report;
	save();
}

void Card::monthlyReport(int month)
{
	ostringstream ostr;

	ostr << "Report for month " << month << ":\n";

	for (int i = 0; i < categories.size(); i++)
	{
		ostr << categories[i].getName() << ": " << categories[i].expPerMonth(month) << endl;
	}

	report = ostr.str();
	cout << report;
	save();
}

void Card::monthlyRating(int month)
{
	ostringstream ostr;
	ostr << "Monthly expence rating: \n";

	double max = categories[0].monthlyMaxCost(month);
	int imax = 0;

	for (int i = 0; i < categories.size(); i++)
	{
		if (categories[i].monthlyMaxCost(month) > max)
		{
			max = categories[i].monthlyMaxCost(month);
			ostr << categories[i].getName() << ": " << max << endl;
			imax = i;
			break;
		}
	}

	double max1 = max;
	int imax1 = imax + 1;

	for (int i = imax; i < categories.size(); i++)
	{
		if (categories[i].expPerMonth(month) > max)
		{
			max1 = categories[i].monthlyMaxCost(month);
			ostr << categories[i].getName() << ": " << max1 << endl;
			imax1 = i;
			break;
		}
	}

	double max2 = max1;
	int imax2 = imax1 + 1;

	for (int i = imax2; i < categories.size(); i++)
	{
		if (categories[i].expPerMonth(month) > max)
		{
			max2 = categories[i].monthlyMaxCost(month);
			ostr << categories[i].getName() << ": " << max2 << endl;
			break;
		}
	}

	report = ostr.str();
	cout << report;
	save();
}

void Card::monthlyCategory(int month)
{
	ostringstream ostr;
	ostr << "Monthly category rating: \n";

	double max = categories[0].expPerMonth(month);
	int imax = 0;

	for (int i = 0; i < categories.size(); i++)
	{
		if (categories[i].expPerMonth(month) > max)
		{
			max = categories[i].expPerMonth(month);
			ostr << categories[i].getName() << endl;
			imax = i;
			break;
		}
	}

	double max1 = max;
	int imax1 = imax + 1;

	for (int i = imax; i < categories.size(); i++)
	{
		if (categories[i].expPerMonth(month) > max)
		{
			max1 = categories[i].expPerMonth(month);
			ostr << categories[i].getName() << endl;
			imax1 = i;
			break;
		}
	}

	double max2 = max1;
	int imax2 = imax1 + 1;

	for (int i = imax2; i < categories.size(); i++)
	{
		if (categories[i].expPerMonth(month) > max)
		{
			max2 = categories[i].expPerMonth(month);
			ostr << categories[i].getName() << endl;
			break;
		}
	}

	report = ostr.str();
	cout << report;
	save();
}

void Card::save()
{
	fout.open("reports.txt");
	fout << report;
	fout.close();
}
