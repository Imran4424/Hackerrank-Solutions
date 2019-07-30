#include <iostream>
#include <vector>
using namespace std;


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
				if (val >= 48)
				{
					return 50;
				}
				else
				{
					return val;
				}
			}
			else if (val < 45)
			{
				if (val >= 43)
				{
					return 45;
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
		else if (val < 40)
		{
			if (val >= 38)
			{
				return 40;
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

vector<int> gradingStudents(vector<int> grades) 
{
	for (int i = 0; i < grades.size(); ++i)
	{
		grades[i] = ChangingValues(grades[i]);
	}

	return grades;
}


