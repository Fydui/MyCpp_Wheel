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


    //double (*data)[year] = new double[year][12];

    //初始化二维数组
    double** data;  //指向二维数组的指针的指针
    data = new double*[year];   //初始化行
    for(int j =0;j<year;j++)
    {
       data[j] = new double[12];   //初始化列
    }


    for(int i = 0; i < year; i++)
    {

        cout << "\n\n##" << i+1 << "##\n" << endl;

        for(int k = 0; k <12; k++)
        {
            carmnky_= carmnky_ - (carmnky_*0.001*k);
            cout <<"How much has the car been " << "in " << k+1 << " month: " << carmnky_ << endl;
            //carmnky_ = interest;
            data[i][k]= carmnky_;
        }

    }

    double O_T = 0;
    for(int a =0;a < year;a++)
    {

        for(int b = 0; b < 12;b++)
        {
            O_T = O_T + data[a][b];
        }

          cout << a+1 <<"YEAR You are going to loss: "<< carmnky*12 - O_T << endl;
          O_T = 0;

    }

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

