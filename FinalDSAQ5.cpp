#include<bits/stdc++.h>
using namespace std;

class Chattro
{
    public:

    string nam;
    int rol;
    int nombor;

    Chattro(string name, int roll, int marks)
    {
        nam = name;
        rol = roll;
        nombor = marks;
    }
};

class Tulona
{
    public:

    bool operator()(Chattro A, Chattro B)
    {
        if(A.nombor < B.nombor)
        {
            return true;
        }
        else if(A.nombor > B.nombor)
        {
            return false;
        }
        else
        {
            if(A.rol > B.rol)
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
    int N;
    cin >> N;

    priority_queue <Chattro,vector<Chattro>,Tulona> PQ;

    for(int i=1;i<=N;i++)
    {
        string nam;
        int rol;
        int nombor;

        getchar();
        cin >> nam >> rol >> nombor;

        Chattro OBJ(nam,rol,nombor);
        PQ.push(OBJ);
    }

    int Q;
    cin >> Q;

    for(int i=1;i<=Q;i++)
    {
        int queries;
        cin >> queries;

        if(queries == 0)
        {
            string nam;
            int rol;
            int nombor;

            getchar();
            cin >> nam >> rol >> nombor;

            Chattro OBJ(nam,rol,nombor);
            PQ.push(OBJ);

            if(!PQ.empty())
            {
                cout << PQ.top().nam << " " << PQ.top().rol << " " << PQ.top().nombor << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }

        }
        else if(queries == 1)
        {
            if(!PQ.empty())
            {
                cout << PQ.top().nam << " " << PQ.top().rol << " " << PQ.top().nombor << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
        else if(queries == 2)
        {
            if(!PQ.empty())
            {
                PQ.pop();
                
                if(!PQ.empty())
                {
                    cout << PQ.top().nam << " " << PQ.top().rol << " " << PQ.top().nombor << endl;
                }
                else
                {
                    cout << "Empty" << endl;
                }
            }
            else
            {
               cout << "Empty" << endl;
            }

        }

    }
    

    return 0;
}