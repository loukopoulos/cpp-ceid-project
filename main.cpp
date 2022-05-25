#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//bait taksinomhsh    
void BubbleSort(vector <string> list)
{
	int i,j;
	string temp;
    for(i=0; i<list.size()-1; i++){
    	for (j=0; j<list.size()-i-1; j++){
    		if (list[j] > list[j+1]){
    			temp = list[j];
    			list[j] = list [j+1];
    			list[j+1] = temp;
			}
		}
	}
	for (i=0; i<list.size()-1; i++){
		cout << list[i] << endl;
	}

}

int main()
{
    vector <string> dates;
    vector <string> temps;
    vector <string> phosphate;
	vector <string> other;
    string line;
	int i = 0;

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
    	//antigrafh ths hmeromhnia kathe grammhs sto vector "dates"
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

		//antigrafh ths thermokrasias kathe grammhs sto vector "temps"
		length = line.copy(copiedString,found,0);
    	copiedString[length] = '\0';
    	temps.push_back(copiedString);
    	line.erase(0,found+1);

		//idia kinhsh kai gia ksexwrismo ths phosphate
        found = line.find(comma);
        if (found != string::npos){
        	//cout << "First occurence is " << found << endl;
		}
		//antigrafh ths phosphate kathe grammhs sto vector "phosphate"
		length = line.copy(copiedString,found,0);
    	copiedString[length] = '\0';
    	phosphate.push_back(copiedString);
    	line.erase(0,found+1);

		//antigrafh olhs ths allh upoloiphs plhroforias
		length = line.copy(copiedString,line.length(),0);
    	copiedString[length] = '\0';
    	other.push_back(copiedString);
    	line.erase(0,line.length());

		//!!!emfanish olwn twn stoixeiwn
		
		//cout<<"Date: "<<dates[i]<<endl;
        //cout<<"Temperature: "<<temps[i]<<endl;
        //cout<<"Phosphate: "<<phosphate[i]<<endl;
        //cout<<"Other info: "<<other[i]<<endl;
        //cout<<endl;
		
        //**Shmeiwsh: gia thn euresh twn kommatwn
		//mporoun na afairethoun oi sunthikes if
		//pou tupwnoun gia tuxwn provlimata,
		//afou den mas vgazei error 
		
        i++;
    }
    //====================================================================
    file.close();
        
	BubbleSort(temps);
	
	//an thelisw na emfanisw thn taksinomhmeno vector den tha mporw,
	//tha emfanisthei taksinomhmenh mono sth sunarthsh pou kaleite.
	//sthn main tha emfanisthei me th seira opws htan ola ta stoixeia tou excel


    return 0;
}
