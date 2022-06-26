#include <iostream> //input output functions
#include <fstream> //file streams apo antikeimena
#include <vector> 
#include <string>
#include <typeinfo> //pithanh xrhsh gia debugging - p.x. tsekaroume tupous metavlhtwn 

using namespace std;

//orismata ola ta vectors
int Partition(vector<float> &temps, int start, int end, vector<string> &dates, vector<float> &phosp, vector<string> &other)
{	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(temps[i]<temps[pivot]){
			swap(temps[i],temps[j]);
			swap(dates[i],dates[j]);
			swap(phosp[i],phosp[j]);
			swap(other[i],other[j]);
			//swap ta stoixeia, dunamika
			++j;
		}
	}
	swap(temps[j],temps[pivot]);
	swap(dates[j],dates[pivot]);
	swap(phosp[j],phosp[pivot]);
	swap(other[j],other[pivot]);
	return j;	
}

void Quicksort(vector<float> &temps, int start, int end, vector<string> &dates, vector<float> &phosp, vector<string> &other)
{
	if(start<end){
		int p = Partition(temps, start, end, dates, phosp, other);
		Quicksort(temps,start,p-1, dates, phosp, other);
		Quicksort(temps,p+1,end, dates, phosp, other);
	}
}

void Insertion_sort(vector<float> &temps, vector<string> &dates, vector<float> &phosp, vector<string> &other)
{
    for(size_t j = 1; j < temps.size(); j++)
    {
      float key = temps[j];
      int i = j-1;

      while(i >= 0 && temps[i] > key)
      {
         swap(temps[i+1], temps[i]);
         swap(dates[i+1], dates[i]);
         swap(phosp[i+1], phosp[i]);
         swap(other[i+1], other[i]);
         i--;
      }
      temps[i+1] = key;
    }
}

int main()
{
    vector <string> dates;
    vector <float> temps;
    vector <float> phosp;
	vector <string> other;
    string line;
	int i = 0;
	float num; //xrhsh proswrinhs metavlitis gia metatroph stoixeiwn apo string se int

    ifstream file;
    file.open("ocean.csv");
    if(!file.is_open())
    {
        cout<<"Unable to open the file."<<endl;
        return 0;
    }

    //Eisagwgh kai diagrafh ths prwths grammhs tou excel sta vector mas,
	//kathws den periexei xrhsimh plhroforia
	getline(file, line);
    dates.push_back(line);
    dates.erase(dates.begin());

	//====================================================================
    //Gia oles tis grammes tou excel
    while(getline(file, line))
    {
    	char copiedString[30];
    	//antigrafh ths HMEROMHNIAS kathe grammhs sto vector "dates"
    	size_t length = line.copy(copiedString,10,0);
    	copiedString[length] = '\0';
		dates.push_back(copiedString); //eisagwgh sto vector
		line.erase(0,11); //diagrafh hmeromhnias apo th grammh excel


		//euresh theshs tou prwtou kommatos
		//gia ksexwrismo twn plhroforiwn pou psaxnoume
        char comma = ',';
        
        size_t found = line.find(comma);
        if (found != string::npos){
        	//cout << "First occurence is " << found << endl;
		}
		//antigrafh ths THERMOKRASIAS kathe grammhs sto vector "temps"
		length = line.copy(copiedString,found,0);
    	copiedString[length] = '\0';
    	num = stof(copiedString);
    	temps.push_back(num);
    	line.erase(0,found+1);


		//idia kinhsh kai gia ksexwrismo ths phosp
        found = line.find(comma);
        if (found != string::npos){
        	//cout << "First occurence is " << found << endl;
		}
		//antigrafh ths PHOSPHATE kathe grammhs sto vector "phosp"
		length = line.copy(copiedString,found,0);
    	copiedString[length] = '\0';
    	num = stof(copiedString);
    	phosp.push_back(num);
    	line.erase(0,found+1);


		//antigrafh olhs ths allh upoloiphs plhroforias
		length = line.copy(copiedString,line.length(),0);
    	copiedString[length] = '\0';
    	other.push_back(copiedString);
    	line.erase(0,line.length());

		
		//cout<<"Date: "<<dates[i]<<endl;
        //cout<<"Temperature: "<<temps[i]<<endl;
        //cout<<"Phosphate: "<<phosp[i]<<endl;
        //cout<<"Other info: "<<other[i]<<endl;
        //cout<<endl;
		
        i++;
	}
    //====================================================================
    file.close();
    
    
	//Quicksort(temps, 0, temps.size()-1, dates, phosp, other);
	Insertion_sort(temps, dates, phosp, other);
	
	/*
	for (i = 0; i<temps.size(); ++i)
	{
		cout<<i+1<<")"<<endl;
		cout<<temps[i]<<endl;
		cout<<endl;
		cout<<endl;
	}
	*/
	
	/*
	for (i = 0; i<temps.size(); ++i)
	{
		cout<<i+1<<")"<<endl;
		cout<<"Date: "<<dates[i]<<endl;
        cout<<"Temperature: "<<temps[i]<<endl;
        cout<<"Phosphate: "<<phosp[i]<<endl;
        cout<<"Other info: "<<other[i]<<endl;
        cout<<endl;
        cout<<endl;
	}
	*/
    return 0;
}
