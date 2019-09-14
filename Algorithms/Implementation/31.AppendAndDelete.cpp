/*
    failed on two test cases
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) 
{
    if(s == t)
    {
        return "Yes";
    }
    
    if(t.size() == 0)
    {
        if(s.size() <= k)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }
    
    int sameCh = 0;
    
    for(int i= 0; i < s.size(); i++ )
    {
        if(s[i] == t[i])
        {
            sameCh++;
        }
        else
        {
            break;
        }
    }
    
    if(sameCh == 0)
    {
        int i = s.size();
        
        i += t.size();
        
        if(i <= k)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }
    else if(sameCh > 0)
    {
        int i = (s.size() - sameCh);
        
        i += t.size() - sameCh;
        
        if(i <= k)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }
    

    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
