#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
//#include <iomanip>

using namespace std;

struct OceanRecord{
public:
    OceanRecord(
            string date,
    long double temp,
    double po4um,
    double sio3um,
    double no2um,
    double no3um,
    double salnty,
    double o2ml
            ) {
        Date = date;
        Temp = temp;
        Po4um = po4um;
        Sio3um = sio3um;
        No2um = no2um;
        No3um = no3um;
        Salnty = salnty;
        O2ml = o2ml;
    }

    void display(){
        cout << " Date: "<< Date <<endl;
        cout << " Temperature: "<< Temp <<endl;
        cout << " Phosphate: "<< Po4um <<endl;
        cout << " Silicate: "<< Sio3um <<endl;
        cout << " Nitrite: "<< No2um <<endl;
        cout << " Nitrate: "<< No3um <<endl;
        cout << " Salinity: "<< Salnty <<endl;
        cout << " Oxygen: "<< O2ml <<endl;
        cout << endl;
    }

    string Date;
    long double Temp;
    double Po4um;
    double Sio3um;
    double No2um;
    double No3um;
    double Salnty;
    double O2ml;
};


int main() {



    ifstream inputFile;
    inputFile.open("C:\\Users\\vixky\\Desktop\\project\\ocean.csv");
    vector<OceanRecord> dates;         //"container" -calculations
    string line = " ";
    getline(inputFile,line);
    line = "";
    while(getline(inputFile,line)){

    string date;
    long double temp;
    double po4um;
    double sio3um;
    double no2um;
    double no3um;
    double salnty;
    double o2ml;

    //cout<< fixed; cout<< setprecision(2)<< temp;   //turns off scientific notation

    string tempString= "";  // double data
    stringstream inputString(line);  // allows to create stream out of a line

    getline(inputString,date,',');

    getline(inputString,tempString,',');
    po4um = atof(tempString.c_str());   //get it as a line , then conversion
        tempString = "";                                //clean stream before using again

    getline(inputString,tempString,',');
    sio3um = atof(tempString.c_str());
    tempString = "";

    getline(inputString,tempString,',');
    no2um = atof(tempString.c_str());
        tempString = "";

    getline(inputString,tempString,',');
    no3um = atof(tempString.c_str());
        tempString = "";

    getline(inputString,tempString,',');
    salnty = atof(tempString.c_str());
    tempString = "";

    getline(inputString,tempString,',');
    o2ml = atof(tempString.c_str());

    OceanRecord date_test(date,temp,po4um,sio3um,no2um,no3um,salnty,o2ml);

    dates.push_back(date_test);

        line = " ";
    }

   for (auto date_test : dates){
       date_test.display();
   }

    return 0;
}
