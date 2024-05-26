#include<bits/stdc++.h>
using namespace std;
int main()
{   
    list <int> Talika(0);

    int Q;
    cin >> Q;

    for(int i=1;i<=Q;i++)
    {
        int X, V;
        cin >> X >> V;

        if(X == 0)
        {
            Talika.push_front(V);

            cout << "L -> "; 

            for(auto it=Talika.begin();it!=Talika.end();it++)
            {
                cout << *it << " ";
            }

            cout << "\nR -> ";

            for(auto it=Talika.end();it!=Talika.begin();it--)
            {
                if(it == Talika.end())
                {
                    continue;
                }

                cout << *it << " ";
                
            }

            cout << *next(Talika.begin(),0) << endl;

        }
        else if(X == 1)
        {
            Talika.push_back(V);

            cout << "L -> "; 

            for(auto it=Talika.begin();it!=Talika.end();it++)
            {
                cout << *it << " ";
            }

            cout << "\nR -> ";

            for(auto it=Talika.end();it!=Talika.begin();it--)
            {
                if(it == Talika.end())
                {
                    continue;
                }

                cout << *it << " ";
                
            }

            cout << *next(Talika.begin(),0) << endl;

        }
        else if(X == 2)
        {
            int size = Talika.size();

            if(V < size)
            {
                Talika.erase(next(Talika.begin(),V));
            }

            cout << "L -> "; 

            for(auto it=Talika.begin();it!=Talika.end();it++)
            {
                cout << *it << " ";
            }

            cout << "\nR -> ";

            for(auto it=Talika.end();it!=Talika.begin();it--)
            {
                if(it == Talika.end())
                {
                    continue;
                }

                cout << *it << " ";
                
            }

            if(Talika.front() != 0)
            {
                cout << *next(Talika.begin(),0) << endl; 
            }
            else
            {
                cout << endl;
            }
           
        }

    }



    return 0;
}