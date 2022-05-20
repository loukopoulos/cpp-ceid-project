#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector <string> dates;
    vector <string> temps;
    vector <string> phosphate;
	vector <string> other;
    string line;
	int i = 0;

    ifstream file;
    file.open("ocean_copy.csv");
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
    
    //Gia oles tis grammes tou excel
    while(getline(file, line))
    {	
    	char copiedString[30];
    	//####antigrafh ths hmeromhnia kathe grammhs sto vector "dates"
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
		
		//####antigrafh ths thermokrasias kathe grammhs sto vector "temps"
		length = line.copy(copiedString,found,0);
    	copiedString[length] = '\0';
    	temps.push_back(copiedString);
    	line.erase(0,found+1);
		
		//idia kinhsh kai gia ksexwrismo ths phosphate
        found = line.find(comma);
        if (found != string::npos){
        	//cout << "First occurence is " << found << endl;
		}
		//####antigrafh ths phosphate kathe grammhs sto vector "phosphate"
		length = line.copy(copiedString,found,0);
    	copiedString[length] = '\0';
    	phosphate.push_back(copiedString);
    	line.erase(0,found+1);
		
		//####antigrafh olhs ths allh upoloiphs plhroforias
		length = line.copy(copiedString,line.length(),0);
    	copiedString[length] = '\0';
    	other.push_back(copiedString);
    	line.erase(0,line.length());
		
		//emfanish olwn twn stoixeiwn 
        cout<<dates[i]<<endl;
        cout<<temps[i]<<endl;
        cout<<phosphate[i]<<endl;
        cout<<other[i]<<endl;
        
        //**Shmeiwsh: gia thn euresh twn kommatwn 
		//mporoun na afairethoun oi sunthikes if 
		//pou tupwnoun gia tuxwn provlimata, 
		//alla afou den mas vgazei error mporoun na afairethoun
        
        i++;
    }
    
    file.close();
    return 0;
}
