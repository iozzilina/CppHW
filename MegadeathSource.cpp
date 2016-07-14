#include <iostream>
#include <time.h>
#include <mutex>
#include <vector>
#include <Windows.h>

std::mutex mtx;

class Door
{
public:
	Door() {};
	~Door() {};
	int TimeToPass() {return timeToPassInMS;};

private:
	int timeToPassInMS = 20;// 20 miliseconds by requirement

};

class Person
{
public:
	Person() {};
	~Person() {};

	void passThruDoor(Door &aDoor) {
		mtx.lock;
		Sleep(aDoor.TimeToPass());
		mtx.unlock();
	}

private:
	std::string name;

};


int main() {

	Door aDoor = Door();

	std::vector<Person*> audience; //a vector of pointers to objects
	for (int i = 0; i < 100000; i++)
	{
		audience.push_back(new Person()); //create a new person and add its pointer to the vector
	}

	
	std::vector<std::thread> ExitQueThreads;

	unsigned long long threadClock = clock();

	for (int i = 0; i < audience.size(); i++)
	{
		ExitQueThreads.push_back(std::thread(audience[i]->passThruDoor(aDoor)));
	}



	for (int i = 0; i < ExitQueThreads.size(); i++)
	{
		ExitQueThreads[i].join(); // whait for all the threads to finish.
	}
	
	printf("%0.4f\n", (float)(clock() - threadClock) / CLOCKS_PER_SEC); 
	
	return 0;
}




