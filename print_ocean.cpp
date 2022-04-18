#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{


    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream MyFile;
    MyFile.open("ocean.csv", ios::in);
    if(MyFile.good())
    {
        while(getline(MyFile, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";

    for(int i=0;i<content.size();i++)
    {
        cout<<content[i][0]<<" ";
        cout<<content[i][2]<<" ";
        cout<<"\n";

    }

    return 0;
}
