#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    for(int i=1;i<=T;i++)
    {
        stack <char> st;

        getchar();
        string S;
        cin >> S;

        for(char C : S)
        {
            if(st.empty())
            {
                st.push(C);
                continue;
            }
            
            if(C == '0')
            {
                st.push(C);
            }
            else if(C == '1')
            {
                if(st.top() == '0')
                {
                    st.pop();
                }
                else
                {
                    st.push(C);
                }
            }
            
            
        }

        if(st.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }

    return 0;
}