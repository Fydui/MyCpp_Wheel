#include <iostream>
using namespace std;

struct Car
{
    Car()
    {
        type = new char[50];

    }
    char* type;
    int years;
    int yr_tdy;
    int carmnky;
    //double oil;

    ~Car()
    {
        delete [] type;
    }
};

void Double_Car(int carmnky, int years, int yr_tdy)
{
    double carmnky_ = carmnky;
    int year = yr_tdy - years;
    double interest;

    for(int i = 0; i < year; i++)
    {

        cout << "\n\n##" << i+1 << "##\n" << endl;

        for(int k = 0; k <12; k++)
        {
            interest= carmnky_ - (carmnky_*0.001*k);
            cout <<"How much has the car been " << "in " << k+1 << " month: " << interest << endl;
            carmnky_ = interest;
        }

    //int mon_ = new int[i][k];

    }


    //return money;
}

int main()
{
    Car mycar;
    cout <<"Please enter your car model: " << endl;
    cin >> mycar.type;

    cout << "Please enter a year when you buy a car: " << endl;
    cin >> mycar.years;

    cout << "Year now: " << endl;
    cin >> mycar.yr_tdy;

    cout << "Please enter the car price: " << endl;
    cin >> mycar.carmnky;

    Double_Car(mycar.carmnky,mycar.years,mycar.yr_tdy);

    return 0;
}

