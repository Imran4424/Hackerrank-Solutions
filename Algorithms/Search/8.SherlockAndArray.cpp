#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

lli leftArraySum, rightArraySum;

void RightSumFirst(vector <lli> arr, lli startIndex) // Initiating the right sum with all elements
{                                                   //  except left most element

    for (lli i = startIndex; i < arr.size(); ++i)
    {
        rightArraySum += arr[i];
    }
}

// Complete the balancedSums function below.
string balancedSums(vector<lli> arr) 
{
    leftArraySum = 0, rightArraySum =0;

    for (lli i = 0; i < arr.size(); ++i)
    {
        if (0 == i)
        {
            RightSumFirst(arr, i+1);

            if (0 == rightArraySum)
            {
                return "YES";
            }
        }
        else if (arr.size() - 1 == i)
        {
            leftArraySum += arr[i - 1];

            if (0 == leftArraySum)
            {
                return "YES";
            }
        }
        else
        {
            leftArraySum += arr[i - 1]; // just adding a single element to left sum
            rightArraySum -= arr[i]; // just subtracting a single element to right sum

            if (leftArraySum == rightArraySum)
            {
                return "YES";
            }            
        }

    }

    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    lli T = stoi(ltrim(rtrim(T_temp)));

    for (lli T_itr = 0; T_itr < T; T_itr++) 
    {
        string n_temp;
        getline(cin, n_temp);

        lli n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<lli> arr(n);

        for (lli i = 0; i < n; i++) 
        {
            lli arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string result = balancedSums(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) 
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) 
{
    string s(str);

    s.erase
    (
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) 
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) 
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
