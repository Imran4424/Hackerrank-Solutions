#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
    private: int l,b,h;

    public: Box()
    {
    	l = b = h = 0;
    }

    public: Box(int l, int b, int h)
    {
    	this -> l = l;
    	this -> b = b;
    	this -> h = h;
    }

    public: Box(Box &obj)
    {
    	l = obj.l;
    	b = obj.b;
    	h = obj.h;
    }

    public: int getLength()
    {
    	return l;
    }

    public: int getBreadth()
    {
    	return b;
    }

    public: int getHeight()
    {
    	return h;
    }

    public: long long CalculateVolume()
    {
    	return (long long)l*b*h;
    }

    bool operator<(const Box &obj)
    {
    	if (l < obj.l)
    	{
    		return true;
    	}

    	if (l == obj.l && b < obj.b)
    	{
    		return true;
    	}

    	if (l == obj.l && b == obj.b && h < obj.h)
    	{
    		/*
    	}

    	return false;
    }

    friend ostream& operator<<(ostream&, const Box &obj);
};

ostream& operator<<(ostream&, const Box &obj)
{
	out << obj.l << " " << obj.b << " " << obj.h << endl;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main(int argc, char const *argv[])
{
	check2();
	return 0;
}