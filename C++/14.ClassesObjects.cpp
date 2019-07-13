

// Write your Student class here

class Student
{
    int mark[5], total;

    public: void input()
    {
        for(int i=0; i<5; i++)
        {
            cin >> mark[i];
        }
    }

    public: int calculateTotalScore()
    {
        total = 0;

        for(int i=0; i<5; i++)
        {
            total += mark[i];
        }

        return total;
    }
};

