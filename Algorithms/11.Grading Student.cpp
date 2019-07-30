#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

int ChangingValues(int val)
{
	if (val > 50)
	{
		if (val > 75)
		{
			if (val > 90)
			{
				if (val > 95)
				{
					if(val >=98)
					{
						return 100;
					}
					else
					{
						return val;
					}
				}
				else if (val < 95)
				{
					if(val >= 93)
					{
						return 95;
					}
					else
					{
						return val;
					}
				}
				else
				{
					return val;
				}
			}
			else if (val < 90)
			{
				if(val > 80)
				{
					if (val > 85)
					{
						if (val >= 88)
						{
							return 90;
						}
						else
						{
							return val;
						}
					}
					else if (val < 85)
					{
						if (val >= 83)
						{
							return 85;
						}
						else
						{
							return val;
						}
					}
					else
					{
						return val;
					}
				}
				else if (val < 80)
				{
					if (val >= 78)
					{
						return 80;
					}
					else
					{
						return val;
					}
				}
				else
				{
					return val;
				}
			}
			else
			{
				return val;
			}
		}
		else if (val < 75)
		{
			if (val > 60)
			{
				if (val > 70)
				{
					if (val >= 73)
					{
						return 75;
					}
					else
					{
						return val;
					}
				}
				else if (val < 70)
				{
					if (val > 65)
					{
						if (val >= 68)
						{
							return 70;
						}
						else
						{
							return val;
						}
					}
					else if (val < 65)
					{
						if(val >= 63)
						{
							return 65;
						}
						else
						{
							return val;
						}
					}
					else
					{
						return val;
					}
				}
				else
				{
					return val;
				}
			}
			else if(val < 60)
			{
				if (val > 55)
				{
					if (val >= 58)
					{
						return 60;
					}
					else
					{
						return val;
					}
				}
				else if (val < 55)
				{
					if (val >= 53)
					{
						return 55;
					}
					else
					{
						return val;
					}
				}
				else
				{
					return val;
				}
			}
			else
			{
				return val;
			}
		}
		else
		{
			return val;
		}
	}
	else if (val < 50)
	{
		if (val > 40)
		{
			if (val > 45)
			{
				/* code */
			}
			else if (val < 45)
			{
				/* code */
			}
			else
			{
				return val;
			}
		}
		else if (val < 40)
		{
			/* code */
		}
		else
		{
			return val;
		}
	}
	else
	{
		return val;
	}
}

vector<int> gradingStudents(vector<int> grades) 
{

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++) 
    {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (int i = 0; i < result.size(); i++) 
    {
        fout << result[i];

        if (i != result.size() - 1) 
        {
            fout << "\n";
        }
    }

    fout << "\n";

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

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
