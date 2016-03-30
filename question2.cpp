///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name:
// Student No:
// Date: 
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// ***** QUESTION 2 *****
// Question 2 consists of 3 parts
// 2.1  Create a class "Time" which implements a 24hr clock in the format hh:mm   
//      Include default constructor, destructor, accessor and mutator (see how they are used in main to
//      determine the format required.
//      Put the declaration and definition in appropriate files! 
// 2.2  Overload the stream insertion operator for your class to print the time in format hh:mm 
// 2.3  Overload the POSTFIX increment operator to increment the minutes (include carry if needed)


// ***** DO NOT MODIFY CODE BELOW THIS LINE *****

class Time{
private:
	int hours;
	int mins;

public:
	Time();
	Time(int, int);
	void set(int h, int m);
	void get(int h, int m);
	~Time();
	friend ostream &operator<<(ostream &outout, Time &t);
	Time operator++(int);

};
Time::Time()
{
	hours = 0;
	mins = 0;

}


Time::Time(int hr, int min)
{
	
	hours = hr;
	mins = min;
}

void Time::get(int h, int m){
	set(h, m);
	hours = h;
	mins = m;
}

void Time::set(int h, int m){

	if (h > 0 && h <= 23) {
		hours = h;

	}
	else{
		hours = 0;
	}

	if (m > 0 && m <= 59) {
		mins = m;

	}
	else{
		mins = 0;
	}
	hours = h;
	mins = m;

}
Time Time ::operator++(int h)
{
	// save the orignal value
	Time T(hours, mins);
	// increment this object
	++mins;
	if (mins >= 60)
	{
		++hours;
		mins -= 60;
	}
	// return old original value
	return T;
}
Time::~Time()
{

}


ostream &operator<<(ostream &output, Time &t){
	output << t.hours << ":" << t.mins << endl;
	return output;
}


int main(int argc, char *argv[]) {

	Time myTime(8, 40);			
	int hour, me;		// instantiate time class 
	myTime++;
	cout << "CM3 starts at " << myTime << endl;			// demonstrate overloaded stream insertion operator
	hour=10;
	me = 30;
	myTime.set(hour, me);									// change the time
	
						                           // get changed time

	myTime.get(hour, me);
	cout << "Design 1 starts at " << me << " past " << hour << endl;   // display time in another format

}