#include "Card.h"

int main()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int choice;
    int that = 0;
    string name;
    double money;
    vector<Card> cards;
    int day, month;

    cout << "\tYOUR PERSONAL FINANCE SYSTEM\n\n";

    while (true)
    {
        cout << "Menu: " << endl;
        cout << "1| Add Card\n2| Deposit money\n3| Add category\n4| Costs input\n5| Make daily report\n6| Make monthly report\n7| Ratings\n#";

        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter card name: ";
            cin >> name;
            cout << "Enter money: ";
            cin >> money;

            cards.push_back(Card(name, money));

            cout << "Card " << cards.back().getName() << " successfully added!" << endl;
        }
        else
        {
            for (int i = 0; i < cards.size(); i++)
            {
                if (cards[i].getName() == name)
                {
                    that = i;
                }
            }

            switch (choice)
            {
            case 2:
                cout << "Enter money: ";
                cin >> money;

                cards[that].addCash(money);
                cout << "Cash successfully added!" << endl;

                break;

            case 3:
                cout << "Enter category name: ";
                cin >> name;

                cards[that].addCategory(name);

                cout << "Category successfully added!" << endl;
                break;

            case 4:
                cout << "Choose category:\n";
                cards[that].printCategories();

                cin >> choice;
                
                cout << "Input money: ";
                cin >> money;

                cards[that].addExpenxe(money, now, choice);
                break;

            case 5:
                cout << "1| For today\n2| Input day\n#";
                cin >> choice;

                if (choice == 1)
                {
                    cards[that].dailyReport(ltm->tm_mday, ltm->tm_mon + 1);
                }
                else
                {
                    cout << "Enter day: ";
                    cin >> day;
                    cout << "Enter month: ";
                    cin >> month;

                    cards[that].dailyReport(day, month);
                }
                break;

            case 6:
                cout << "1| For now\n2| Input month\n#";
                cin >> choice;

                if (choice == 1)
                {
                    cards[that].monthlyReport(ltm->tm_mon + 1);
                }
                else
                {
                    cout << "Enter month: ";
                    cin >> month;

                    cards[that].monthlyReport(month);
                }
                break;

            case 7:
                cout << "1| Top 3 expences per month\n2| Top 3 categories per month\n#" << endl;
                cin >> choice;

                if (choice == 1)
                {
                    cout << "1| For now\n2| Input month\n#";
                    cin >> choice;

                    if (choice == 1)
                    {
                        cards[that].monthlyRating(ltm->tm_mon + 1);
                    }
                    else
                    {
                        cout << "Enter month: ";
                        cin >> month;

                        cards[that].monthlyRating(month);
                    }
                }
                else
                {
                    cout << "1| For now\n2| Input month\n#";
                    cin >> choice;

                    if (choice == 1)
                    {
                        cards[that].monthlyCategory(ltm->tm_mon + 1);
                    }
                    else
                    {
                        cout << "Enter month: ";
                        cin >> month;

                        cards[that].monthlyCategory(month);
                    }
                }
                break;

            default:
                cout << "Wrong input!" << endl;
                break;
            }
        }
        
    }
}
