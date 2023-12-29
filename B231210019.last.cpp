/****************************************************************************
**					       SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				        BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI:2
**				ÖÐRENCÝ ADI:Selva Artunç
**				ÖÐRENCÝ NUMARASI:B231210019
**				DERS GRUBU:1/C
****************************************************************************/
//libraries
#include <iostream>
#include<iomanip>
#include<math.h>
#include<ctime>
#pragma warning (disable:4996)// to disable warning 4996

using namespace std;

struct tm_
{

    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_mday;

};// to get system time

const int maxaccno = 100; //for count number of accounts
string hacc[maxaccno];
int acccounter = 0;
int generalacccounter=0;
int speacialacccounter=0;
class account
{
private:
    string accno;
public:
    int b = 0, s = 0, amount = 0, gap = 0, randomd = 0, day = 0;
    void buy()
    {
        cout << "How much money you want to invest" << endl;
        cin >> b;
        amount += b;
    }
    void sell()
    {
        cout << "How much crypto money you  want to sell?" << endl;
        cin >> s;
        this->amount -= s;
    }
    double balance()
    {
        return amount;
    }
    void profit()
    {
        cout << amount - (b - s) << endl;
    }
    void systemdate()
    {
        cout << "System date:";
        time_t t = time(0);
        tm* now = localtime(&t);
        cout << now->tm_mday << '-' << (now->tm_mon + 1) << '-' << (now->tm_year + 1900) << endl;
    }
    void  generalacc()
    {
        cout << "Enter dates first!" << endl;
        int day1, month1, year1, day2, month2, year2, gap = 0;
        cout << "Please enter a start time (DD-MM-YYYY):";
        cin >> day1 >> month1 >> year1;
        cout << "Please enter a end date (DD-MM-YYYY):";
        cin >> day2 >> month2 >> year2;
        if (month2 % 2 == 0 && month1 % 2 == 0)
        {
            gap = (year2 - year1) * 365 + (month2 - month1) * 31 + (day2 - day1);
            cout << gap << endl;
        }
        else if (month2 % 2 == 0 && month1 % 2 == 1)
        {
            gap = (year2 - year1) * 365 + (31 * month2 - 30 * month1) + (day2 - day1);
            cout << gap << endl;
        }
        else if (month2 % 2 == 1 && month1 % 2 == 0)
        {
            gap = (year2 - year1) * 365 + (30 * month2 - 31 * month1) + (day2 - day1);
            cout << gap << endl;
        }
        else if (month2 % 2 == 1 && month1 % 2 == 1)
        {
            gap = (year2 - year1) * 365 + (month2 - month1) * 30 + (day2 - day1);
            cout << gap << endl;
        }
        else if (month2 == 2 && month1 == 2)
        {
            gap = (year2 - year1) * 365 + (month2 - month1) * 29 + (day2 - day1);
            cout << gap << endl;
        }

        if (gap % 15 == 0)
        {
            amount -= gap * 0.05;
        }
        else
        {
            amount += gap * 1.01;
        }
        cout << "Your total balance is:" << balance() << endl;
    }
    void specialacc()
    {
        cout << "Enter dates first!" << endl;
        int day1, month1, year1, day2, month2, year2, gap = 0;
        cout << "Please enter a start time (DD-MM-YYYY):";
        cin >> day1 >> month1 >> year1;
        cout << "Please enter a end date (DD-MM-YYYY):";
        cin >> day2 >> month2 >> year2;
        if (month2 % 2 == 0 && month1 % 2 == 0)
        {
            gap = (year2 - year1) * 365 + (month2 - month1) * 31 + (day2 - day1);
            cout << gap << endl;
        }
        else if (month2 % 2 == 0 && month1 % 2 == 1)
        {
            gap = (year2 - year1) * 365 + (31 * month2 - 30 * month1) + (day2 - day1);
            cout << gap << endl;
        }
        else if (month2 % 2 == 1 && month1 % 2 == 0)
        {
            gap = (year2 - year1) * 365 + (30 * month2 - 31 * month1) + (day2 - day1);
            cout << gap << endl;
        }
        else if (month2 % 2 == 1 && month1 % 2 == 1)
        {
            gap = (year2 - year1) * 365 + (month2 - month1) * 30 + (day2 - day1);
            cout << gap << endl;
        }
        else if (month2 == 2 && month1 == 2)
        {
            gap = (year2 - year1) * 365 + (month2 - month1) * 29 + (day2 - day1);
            cout << gap << endl;
        }
        for (int i = 1; i <= gap; i++) //for calculate rates
        {
            int randomDay1 = 0;
            int randomDay2 = 0;
            int randomDay3 = 0;
            randomDay1 = rand() % 30 + 1;
            randomDay2 = rand() % 30 + 1;
            randomDay3 = rand() % 30 + 1;
            if (i == randomDay1 || i == randomDay2 || i == randomDay3)
            {
                amount -= amount * 0.1;
            }
            else
                amount += amount * 0.05;
            cout << "Your Current Balance is:" << balance() << endl;
        }


    }
    static void list()
    {
        for (int i = 0; i < acccounter; ++i) //for calculate number of accounts
        {
            cout << i + 1 << ".Account No: " << hacc[i] << endl;

        }
        cout << "Total Account Number is:" << acccounter << endl;
        cout << "Total General Account Number is:" << generalacccounter << endl;
        cout << "Total Speacial Account Number is:" << speacialacccounter << endl;
    }
    void setaccno()
    {
        cout << "Please enter  number: ";
        cin >> accno;
        hacc[acccounter++] = accno;
    }

};

int main()
{
    account a;
    int y;
    int x;
   do{
    cout << "1)General Account " << endl << "2)Special Account" << endl << "0)Exit" << endl;
    cin >> x;
       
     

        if (x == 1)//for general account process
        {   generalacccounter += 1;
            a.setaccno();
            do {
                cout << "1)Buy" << endl << "2)Sell" << endl << "3)Profit" << endl << "4)List" << endl << "5)System date" << endl << "6)Total Balance" << endl;
                cin >> y;
                switch (y)
                {
                case 1:
                    a.buy();
                    break;
                case 2:
                    a.sell();
                    break;
                case 3:
                    a.profit();
                    break;
                case 4:
                    a.list();
                    break;
                case 5:
                    a.systemdate();
                    break;
                case 6:
                    a.generalacc();
                    break;
                }
                if (y != 7)
                {
                    string z;
                    cout << "Did you want to countinue with this account? (Yes/No)" << endl;
                    cin >> z;
                    if (z != "Yes" && z != "yes")
                    {
                        y = 7;
                    }
                }
            } while (y != 7);
        }
        else if (x == 2) //for speacial account process
        {
            speacialacccounter += 1;
            a.setaccno();
            cout << "1)Buy" << endl << "2)Sell" << endl << "4)Profit" << endl << "5)List" << endl << "6)System date" << endl << "7)Total Balance" << endl;
            cin >> y;
            do {
                switch (y)
                {
                case 1:
                    a.buy();
                    break;
                case 2:
                    a.sell();
                    break;
                case 3:
                    a.profit();
                    break;
                case 4:
                    a.list();
                    break;
                case 5:
                    a.systemdate();
                    break;
                case 6:
                    a.specialacc();
                    break;
                }
                if (y != 7)
                {
                    string z;
                    cout << "Did you want to countinue with this account? (Yes/No)" << endl;
                    cin >> z;
                    if (z != "Yes" && z != "yes")
                    {
                        y = 7;
                    }
                }
            } while (y != 7);
        }
        else
        {
            cout << "Program quitting" << endl;
            return 0;
        }


    } while (true);
    return 0;
}
