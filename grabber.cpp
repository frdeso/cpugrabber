#include <iostream>
#include <vector>
#include <thread>

using namespace std;
void foo()
{
	int i= 0;
	while (1)
	{
		i++;
		if(i % 1000000000 == 0)
		{
			cout<<".";
			cout.flush();
		}
	}
}

int main()
{
	unsigned nbCores = std::thread::hardware_concurrency();
	vector<thread*> thrds;
	for(unsigned int i = 0; i < nbCores; ++i)
	{
		thrds.push_back(new thread(foo));
	}

	cout<<"Launched "<<nbCores<<" looping threads."<<endl;
	for(auto t: thrds)
	{
		t->join();
	}
	return 0;
}

