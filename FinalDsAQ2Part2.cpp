#include<bits/stdc++.h>
using namespace std;

class Holder
{
    public:

    string name;
    long long int UniqueVals;

    Holder(string name, long long int UniqueVals)
    {
        this->name = name;
        this->UniqueVals = UniqueVals;
    }
};

class comp
{
    public:

    bool operator()(Holder A, Holder B)
    {
        if(A.name != B.name)
        {
            if(A.name > B.name)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(A.UniqueVals < B.UniqueVals)
            {
                return true;
            }
            else
            {
                return false;
            } 
        }

    }

};

int main()
{
    long long int N;
    cin >> N;

    priority_queue <Holder,vector<Holder>,comp> A;

    for(long long int i=0;i<N;i++)
    {
        string name;
        cin >> name;

        long long int UniqueVals;
        cin >> UniqueVals;

        Holder H(name,UniqueVals);
        A.push(H);
    }

    while(!A.empty())
    {
        cout << A.top().name << " " << A.top().UniqueVals << " " << endl;
        A.pop();
    }

    return 0;
}