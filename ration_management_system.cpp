#include <iostream>
#include <string>
using namespace std;

class Citizen
{
public:
    int id;
    string name, pan_no;
    double income;


    Citizen(int i, string n, string p, double inc)
    {
        id = i;
        name = n;
        income = inc;
        pan_no = p;
    }
};


class RationCard : public Citizen
{
public:
    string cardType;
    int quota;


    RationCard(int i, string n, string p, double inc)
        : Citizen(i, n, p, inc)
    {
        if (income > 100000)
        {
            cardType = "APL";
            quota = 10;
        }
        else if (income > 25000)
        {
            cardType = "BPL";
            quota = 30;
        }
        else
        {
            cardType = "AAY";
            quota = 40;
        }
    }


    string allocateRice(int& stock)
    {
        if (quota > stock)
            return "false";

        stock -= quota;
        return "true";
    }


    void display(int stock)
    {
        cout << "\n------ Citizen Details ------";
        cout << "\nCitizen ID   : " << id;
        cout << "\nName         : " << name;
        cout << "\nPan Number   : " << pan_no;
        cout << "\nIncome       : " << income << " Rs";
        cout << "\nRation Card Type : " << cardType;
        cout << "\nRice Allocated   : " << quota << " kg";
        cout << "\nRemaining Stock  : " << stock << " kg";
    }
};


int main()
{
    int id, stock, choice, add;
    string name, pan_no;
    double income;
    cout << "Enter available rice stock (in kg): ";
    cin >> stock;


    while (true)
    {
        cout << "\n\n----- MENU -----\n";
        cout << "1. Add Citizen & Allocate Rice\n";
        cout << "2. Restock Rice\n";
        cout << "3. Show Current Stock\n";
        cout << "4. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            {
                if (stock <= 0)
                {
                    cout << "\nStock is empty! Please restock first.\n";
                    break;
                }
                cout << "\n------ Food Ration Distribution Management System ------\n";


                cout << "Enter Citizen ID: ";
                cin >> id;


                cout << "Enter Name: ";
                cin >> name;


                cout << "Enter Pan Number: ";
                cin >> pan_no;


                cout << "Enter Annual Income: ";
                cin >> income;


                RationCard citizen(id, name, pan_no, income);


                if (citizen.allocateRice(stock) == "false")
                {
                    cout << "\nERROR: Insufficient rice stock available!";
                    cout << "\nPlease Restock...!!!!";
                    break;
                }


                citizen.display(stock);
                break;
            }
        case 2:
            {
                cout << "Enter Rice To Restock: ";
                cin >> add;
                stock += add;
                cout << "Updated Stock: " << stock << " Kg\n";
                break;
            }
        case 3:
            {
                cout << "Current stock: " << stock << " Kg\n";
                break;
            }
        case 4:
            {
                cout << "Process Exiting....Thankyou!!";
                return 0;
            }
        default:
            cout << "Please enter a valid choice.\n";
            break;
        }
    }
}
