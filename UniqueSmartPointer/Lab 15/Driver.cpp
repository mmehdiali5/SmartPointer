#include<iostream>
using namespace std;
#include"UniqueSmartPointer.h"

class Tom
{
public:
	int mem;
	Tom(int i = 0) :mem(i)
	{
		cout << "\nTom " << this;
	}
	void print()
	{
		cout << "\nTom::print " << this;
    }
	~Tom()
	{
		cout << "\n~Tom " << this;
    }
};

ostream&operator<<(ostream&ost, const Tom&t)
{
	cout << &t << " : " << t.mem;
	return ost;
}

int main()
{
	/*UniqueSmartPointer<Tom[]>usp1(new Tom[3]);
	UniqueSmartPointer<UniqueSmartPointer<Tom[]>>usp2(&usp1);
	int counter = 0;*/
	/*{
		UniqueSmartPointer<Tom[]>usp1(new Tom[3]);
		UniqueSmartPointer<Tom[]>usp2(usp1);
		if (usp1)
		{
			cout << "\nusp1:I have ownership of: " << usp1.get();
		}
		if (usp2)
		{
			cout << "\nusp2:I have ownership of: " << usp2.get();
	    }
	}*/
	/*{
		UniqueSmartPointer<Tom[]>usp(new Tom[3]);
		for (int i = 0; i < 3; i = i + 1)
		{
			usp[i].mem = i * 2;
		}
		for (int i = 0; i < 3; i = i + 1)
		{
			usp[i].print();
			cout << "\nmem= " << usp[i].mem;
	    }
	}*/
	/*{
		UniqueSmartPointer<Tom[]>usp(new Tom[3]);
	}*/
	/*{
		UniqueSmartPointer<int[]>usp(new int[3]{ 10,20,30 });
		usp[0] = 100;
		for (int i = 0; i < 3; i = i + 1)
		{
			cout << usp[i]<<":";
		}
	}*/
	/*{
		UniqueSmartPointer<Tom>usp1;
		UniqueSmartPointer<Tom>usp2(new Tom(20));
		usp1 = move(usp2);
		if (usp1)
		{
			cout << "\nusp1: I have ownership of: " << usp1.get();
		}
		if (usp2)
		{
			cout << "\nusp2: I have ownership of: " << usp2.get();
		}
	}*/
	/*{
		UniqueSmartPointer<Tom>usp1(new Tom(10));
		UniqueSmartPointer<Tom>usp2(new Tom(20));
		usp1 = move(usp2);
		if (usp1)
		{
			cout << "\nusp1:I have ownership of: " << usp1.get();
		}
		if (usp2)
		{
			cout << "\nusp2:I have ownership of: " << usp2.get();
		}
	}*/
	/*UniqueSmartPointer<Tom>usp1(new Tom(10));
	UniqueSmartPointer<Tom>usp2(usp1.operator->());*/

	/*{
	UniqueSmartPointer<Tom>usp1(new Tom(10));
	UniqueSmartPointer<Tom>usp2(usp1);
	if (usp1)
	{
		cout << "\nusp1: I have ownership of: " << usp1.get();
	}
	if (usp2)
	{
		cout << "\nusp2: I have ownership of: " << usp2.get();
	}
	}*/

	/*{
		UniqueSmartPointer<Tom>usp1(new Tom(10));
		UniqueSmartPointer<Tom>usp2(new Tom(20));
		usp1 = usp2;
		if (usp1)
		{
			cout << "\nusp1:I have ownership of: " << usp1.get();
		}
		if (usp2)
		{
			cout << "\nusp1:I have ownership of: " << usp2.get();
		}
	}*/

	/*UniqueSmartPointer<Tom>usp1(new Tom(10));
	UniqueSmartPointer<Tom>usp2(new Tom(20));
	cout << "\n" << *usp1 << ":" << *usp2;
	*usp1 = *usp2;
	cout << "\n" << *usp1 << ":" << *usp2;*/

	/*Tom*p = new Tom(10);
	cout << "\naddress in p: " << p;
	{
		UniqueSmartPointer<Tom>usp(p);
		cout << "\n" << usp.get()->mem;
		cout << "\n" << usp->mem;
		usp->print();
	}*/
	/*{
		UniqueSmartPointer<Tom>usp1(new Tom(10));
		UniqueSmartPointer<Tom>usp2(new Tom(20));
		usp1->print();
		usp2->print();
		usp1.swap(usp2);
		usp1->print();
		usp2->print();
	}*/
	
	/*UniqueSmartPointer<int>usp(new int (34));
	UniqueSmartPointer<int>usp2(new int(50));
	cout << *usp << ":" << *usp2<<"\n";
	usp.swap(usp2);
	cout << *usp << ":" << *usp2;*/
	/*usp.release();
	if (!usp)
	{
		cout << "I am free now\n";
	}
	usp.reset(new int(100));
	if (usp)
	{
		cout << "\nI am occupied: " << *usp;
	}
	usp.reset(new int(200));
	if (usp)
	{
		cout << "\nI am occupied: " << *usp;
	}*/
	cout << "\n\n\n\n\n\n\n";
	return 0;
}