#include <iostream> //input output functions
#include <fstream> //file streams apo antikeimena
#include <vector> 
#include <string>
#include <typeinfo> //pithanh xrhsh gia debugging - p.x. tsekaroume tupous metavlhtwn 
#include <algorithm>
#include <cmath>

using namespace std;

//FUNCTIONS-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//Sort gia Binary Anazhthsh kai alla...... :)
void Insertionsort_for_dates(vector<string> &formatted_dates, vector<string> &dates, vector<float> &temps, vector<float> &phosp, vector<string> &other)
{
	int i;

	for (i=0; i<dates.size(); i++)
	{
		string hmero = dates[i];
		hmero.erase(2,1);
		hmero.erase(4,1);
		formatted_dates.push_back(hmero);
	}
	
	
    for(size_t j = 1; j < formatted_dates.size(); j++)
    {
      string key = formatted_dates[j];
      int i = j-1;

      while(i >= 0 && formatted_dates[i] > key)
      {
         swap(formatted_dates[i+1], formatted_dates[i]);
         swap(temps[i+1], temps[i]);
         swap(dates[i+1], dates[i]);
         swap(phosp[i+1], phosp[i]);
         swap(other[i+1], other[i]);
         i--;
      }
      formatted_dates[i+1] = key;
    }
}

int BinarySearch(string input, vector<string> &dates, vector<string> &formatted_dates, vector <float> &temps, vector<float> &phosp, vector<string> &other )
{
	int i =0;
	Insertionsort_for_dates(formatted_dates, dates, temps, phosp, other);
	
	int left = 0;
	int right = dates.size()-1;
	while (left <= right)
	{	
		int next = left + (right-left)/2;
		if (formatted_dates[next]==input)
			return next;
			
		if (formatted_dates[next] < input)
			left = next + 1;
			
		else
			right = next - 1;
	}
	return -1;
}

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

void Insertionsort(vector<float> &temps, vector<string> &dates, vector<float> &phosp, vector<string> &other)
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

 
void heapify(vector<float> &phosp, int n, int i, vector<string> &dates, vector<float> &temps, vector<string> &other) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && phosp[left] > phosp[largest])
      largest = left;
  
    if (right < n && phosp[right] > phosp[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(phosp[i], phosp[largest]);
      swap(dates[i], dates[largest]);
      swap(temps[i], temps[largest]);
      swap(other[i], other[largest]);
      heapify(phosp, n, largest, dates, temps, other);
    }
  }
  
  // main function to do heap sort
void Heapsort(vector<float> &phosp, int n, vector<string> &dates, vector<float> &temps, vector<string> &other) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(phosp, n, i, dates, temps, other);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(phosp[0], phosp[i]);
      swap(dates[0], dates[i]);
      swap(temps[0], temps[i]);
      swap(other[0], other[i]);
  
      // Heapify root element to get highest element at root again
      heapify(phosp, i, 0, dates, temps, other);
    }
  }

void Countingsort(int arr[], int arr2[], vector<string> &dates, int size)
{
  int phospout[size];
  string datesout[size];
  int tempsout[size];
  
  int count[size];
  int max = arr[0];
  string datesmax = dates[0];
  int max2 = arr2[0];
      for (int i = 1; i < size; i++)
	  {
        if (arr[i] > max)
          max = arr[i];
          datesmax = dates[i];
          max2 = arr2[i];
      }

      for (int i = 0; i <= max; ++i)
	  {
        count[i] = 0;
      }

      for (int i = 0; i < size; i++)
	  {
        count[arr[i]]++;
      }

      for (int i = 1; i <= max; i++)
	  {
        count[i] += count[i - 1];
      }

      for (int i = size - 1; i >= 0; i--) {
        phospout[count[arr[i]] - 1] = arr[i];
        datesout[count[arr[i]] - 1] = dates[i];
        tempsout[count[arr[i]] - 1] = arr2[i];
		count[arr[i]]--;
      }

      for (int i = 0; i < size; i++) {
        arr[i] = phospout[i];
		dates[i] = datesout[i];
		arr2[i] = tempsout[i];
      }
} 


//MAIN-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

int main()
{
    vector <string> dates;
    vector <float> temps;
    vector <float> phosp;
	vector <string> other;
	vector <string> formatted_dates;
	
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
    i = 0;
    int n = phosp.size(); //1405
    
    int expression;
	while (expression!=0)
	{
	    cout<<"いいい MENU いいい"<<endl;
	    cout<<"1. Insertion Sort"<<endl;
	    cout<<"2. Quick Sort"<<endl;
	    cout<<"3. Heap Sort"<<endl;
	    cout<<"4. Counting Sort"<<endl;
	    cout<<"5. Binary Search"<<endl;
	    cout<<"0. EXIT"<<endl; 
	    cout<<"Please Enter your choice: ";
	    cin >> expression;
	    cout<<endl<<endl;
	    
	    switch (expression)
	    {
	    	case 1:
	    		Insertionsort(temps, dates, phosp, other);
	    		break;
	    		
	    	case 2:
	    		Quicksort(temps, 0, temps.size()-1, dates, phosp, other);
	    		break;
	    		
	    	case 3:
	    		Heapsort(phosp, n, dates, temps, other);
	    		break;
	    		
	    	case 4:
	    		{
			    	int arr[phosp.size()];
					int arr2[temps.size()];
					for (i = 0; i<phosp.size(); i++)
					{
						arr[i] = (int) (phosp[i]*100);
						arr2[i] = (int) (temps[i]*100);
			    	}
					Countingsort(arr, arr2, dates, phosp.size());
					for (i = 0; i<phosp.size(); i++)
					{
						phosp[i] = (float) (arr[i])/100;
						temps[i] = (float) (arr2[i])/100;
					}
					break;
				}
			case 5:
				{
					string x;
					cout<<"Enter date for Binary Search(In MMDDYYYY format): "<<endl; //tha mporousa na to tropopoihsw me string functions na pairnei kathe mera/mhna/xrono ksexwrista, alla den eixa allo xrono.
					cin >> x;
					int pos;
					pos = BinarySearch(x, dates, formatted_dates, temps, phosp, other);
					if (pos == -1)
						cout<<"Exases"<<endl;
					else
					{
						cout<<"Date: "<<dates[pos]<<endl;
						cout<<"Temperature: "<<temps[pos]<<endl;
						cout<<"Phosphate: "<<phosp[pos]<<endl;
						cout<<endl<<endl;
					}
					break;
				}
			case 0:
				{
					break;
				}
		}
	}
	
	

    return 0;
}
