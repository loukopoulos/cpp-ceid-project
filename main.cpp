#include <iostream> //input output functions
#include <fstream> //file streams apo antikeimena
#include <vector> 
#include <string>
#include <typeinfo> //pithanh xrhsh gia debugging - p.x. tsekaroume tupous metavlhtwn 

using namespace std;

int Partition(vector<float> &v, int start, int end){
	
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			swap(v[i],v[j]);
			++j;
		}
	}
	swap(v[j],v[pivot]);
	return j;
	
}

void Quicksort(vector<float> &v, int start, int end ){

	if(start<end){
		int p = Partition(v,start,end);
		Quicksort(v,start,p-1);
		Quicksort(v,p+1,end);
	}
	
}

void PrintVector(vector<int> v){
	for(int i=0;i<v.size();++i)
		cout<<v[i]<<" ";
	cout<<"\n\n";
}

int main()
{
    vector <string> dates;
    vector <float> temps;
    vector <float> phosphate;
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


		//idia kinhsh kai gia ksexwrismo ths phosphate
        found = line.find(comma);
        if (found != string::npos){
        	//cout << "First occurence is " << found << endl;
		}
		//antigrafh ths PHOSPHATE kathe grammhs sto vector "phosphate"
		length = line.copy(copiedString,found,0);
    	copiedString[length] = '\0';
    	num = stof(copiedString);
    	phosphate.push_back(num);
    	line.erase(0,found+1);


		//antigrafh olhs ths allh upoloiphs plhroforias
		length = line.copy(copiedString,line.length(),0);
    	copiedString[length] = '\0';
    	other.push_back(copiedString);
    	line.erase(0,line.length());

		
		//cout<<"Date: "<<dates[i]<<endl;
        //cout<<"Temperature: "<<temps[i]<<endl;
        //cout<<"Phosphate: "<<phosphate[i]<<endl;
        //cout<<"Other info: "<<other[i]<<endl;
        //cout<<endl;
		
        i++;
	}
    //====================================================================
    file.close();
	
	
	//gia thn wra h quicksort epanalamvanetai apeira
	//pithano provlima pou exei na kanei me thn emveleia tou vector mas
	Quicksort(temps, 0, temps.size());
	cout<<temps.size()<<endl;
	for (i = 0; i<=temps.size(); i++)
	{
		cout<<i+1<<":"<< temps[i]<<endl;
	}
	//an thelisw na emfanisw thn taksinomhmeno vector den tha mporw,
	//tha emfanisthei taksinomhmenh mono sth sunarthsh pou kaleite.
	//sthn main tha emfanisthei me th seira opws htan ola ta stoixeia tou excel


    return 0;
}
