#include<bits/stdc++.h>
using namespace std;
int main()
{       
    int T;
    cin >> T;

    getchar();

    for(int i=1;i<=T;i++)
    {
        map <string,int> ManChittro;
        
        string name;
        getline(cin,name);

        stringstream ss(name);
        string word;

        int Max = INT_MIN;
        string TheName;
        
        while(ss >> word)
        {
            ManChittro[word]++;

            if(ManChittro[word] > Max)
            {
                Max = ManChittro[word];
                TheName = word; 
            }
        }
    
        cout << TheName << " " << Max << endl;   

    }

    return 0;
}