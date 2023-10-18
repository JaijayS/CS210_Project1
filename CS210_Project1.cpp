// NAME: Jantzen Springer
// DATE: 09/17/2023
// ASSIGNMENT: CS210-PRORGAMMING LANGUAGES: PROJECT 1



#include <iostream>
#include <iomanip>
using namespace std;

// Declaring functions; 
void UserInput();

void UserInputMenu(int hours, int minutes, int seconds, string meridiem); 

void Clock12Hour(int hours, int minutes, int seconds, string meridiem);

void Clock24Hour(int hours, int minutes, int seconds, string meridiem);

void ClockDisplay(int hours, int minutes, int seconds, string meridiem);

void AddHour(int hours, int minutes, int seconds, string meridiem);

void AddSecond(int hours, int minutes, int seconds, string meridiem);

void AddMinute(int hours, int minutes, int seconds, string meridiem);


// USERINPUT FUNCTION: Processes user input to get initial time. 
void UserInput() {

// Initialize variables 

	int hours = 0;
	int minutes = 60;
	int seconds = 60;
	string meridiem = "am";

// User input for hours with ranges.
	while (hours < 1 || hours > 12) {

		cout << "Enter hours (1 - 12): ";
		cin >> hours;

	}
// User input for minutes with ranges.
	while (minutes < 0 || minutes > 59) {

		cout << "Enter minutes (0 - 59): ";
		cin >> minutes;

	}
// User input for seconds with ranges.
	while (seconds < 0 || seconds > 59) {

		cout << "Enter seconds (0 - 59): ";
		cin >> seconds;

	}
// User input for meridiem with ranges.
	while (meridiem != "AM" && meridiem != "PM"){

		cout << "AM or PM: ";
		cin >> meridiem; 

// Loop to capitalize user input.
		for (int i = 0; i < meridiem.length(); i++) {

			meridiem[i] = toupper(meridiem[i]);

		}
	}

// Establishes hours in 24 hour format.
	if (meridiem == "PM") {

		hours += 12;
		meridiem = "P M";

	}

	cout << endl << endl;

// Display Initial time from user input.
	ClockDisplay(hours, minutes, seconds, meridiem);

}


int main() {

// Main function only call on user input for initial time. 
	UserInput();

	return 0;
}


// CLOCK12HOUR: Function that outputs the time using 12-hour format
void Clock12Hour(int hours, int minutes, int seconds, string meridiem) {

	// Defines morning hours (AM)
	if (hours >= 0 && hours < 12 || hours == 24) {

		meridiem = "A M";

		if (hours == 24) {

			hours = 12;
		}

		else if (hours == 0) {

			hours += 1;
		}
	
	}
	// Defines afternoon hours (PM)
	else if (hours >= 12 && hours < 24) {

		meridiem = "P M";

		if (hours != 12) {

			hours -= 12;
		}
	}
	cout << endl;

	// Display for 12-hour format
	if (hours < 10) {

		cout << setw(3) << "*" << "\t" << 0 << hours;

	}
	else {

		cout << setw(3) << "*" << "\t" << hours;

	}
	cout << ':';

	if (minutes < 10) {

		cout << 0 << minutes;

	}

	else {

		cout << minutes;
	}

	cout << ':';

	if (seconds < 10) {

		cout << 0 << seconds;
	}

	else {

		cout << seconds;
	}
	cout << " " << meridiem << setw(8) << "*";

}


// CLOCK24HOUR: Function that displays time in 24-hour format
void Clock24Hour(int hours, int minutes, int seconds, string meridiem) {
 
// Formatting hours for 23 (11pm) - 0 (12am)
	if (hours == 0) {

		hours += 1;

	}
	else if (hours == 24) {

		hours = 0; 
	}
// Display for 24-Hour Clock
	if (hours < 10) {

		cout << setw(11) << "*" << setw(8) << 0 << hours;

	}
	else {

		cout << setw(11) << "*" << setw(9) << hours;

	}
	cout << ':'; 
	
	if (minutes < 10) {

		cout << 0 << minutes;
	
	}

	else {

		cout << minutes; 
	}
	
	cout << ':';
	
	if (seconds < 10) {

		cout << 0 << seconds;
	}

	else {

		cout << seconds;

	}
	cout << setw(10) << "*" << endl;
}


// CLOCKDISPLAY: Function that displays BOTH 12- and 24- hour time formats on the interface at the same time
 void ClockDisplay(int hours, int minutes, int seconds, string meridiem) {

// Display format
	 cout << "  **************************          **************************" << endl;
	 cout << setw(3) << "*" << setw(19) << "12 - Hour Clock" << setw(6) << "*";
	 cout << setw(11) << "*" << setw(18) << "24-Hour Clock" << setw(7) << "*"; 

// Calling on 12-hour clock
	 Clock12Hour(hours, minutes, seconds, meridiem);

// Calling on 24-hour clock
	 Clock24Hour(hours, minutes, seconds, meridiem);

	 cout << "  **************************          **************************" << endl;
	cout << endl << endl;

// Calling on user input menu
	UserInputMenu(hours, minutes, seconds, meridiem);

}

// USERINPUTMENU: Processes user input from the menu choices in the user interface
void UserInputMenu(int hours, int minutes, int seconds, string meridiem) {

	int userInput = 0;
// Displays user input menu until valid answers are inputted 
	while ((userInput != 1) && (userInput != 2) && (userInput != 3) && (userInput != 4)) {

		cout << setw(46) << "***************************" << endl;
		cout << setw(21) << "* " << "1 - Add One Hour" << setw(9) << "*" << endl;
		cout << endl;
		cout << setw(21) << "* "  << "2 - Add One Minute" << setw(7) << "*" << endl;
		cout << endl;
		cout << setw(21) << "* " << "3 - Add One Second" << setw(7) << "*" << endl;
		cout << endl;
		cout << setw(21) << "* " << "4 - Exit program" << setw(9) << "*" << endl;
		cout << setw(46) << "***************************" << endl;

		cin >> userInput;

		if (userInput == 1) {

			AddHour(hours, minutes, seconds, meridiem);
		}

		else if (userInput == 2) {

			AddMinute(hours, minutes, seconds, meridiem);
		}

		else if (userInput == 3) {

			AddSecond(hours, minutes, seconds, meridiem);
		}

		else if (userInput == 4) {

			cout << "Terminating Program" << endl;

			break;
		}

		else {

			cout << "Invalid Response" << endl;
		}

	}
}


// ADDSECOND: Write a function to add a second to clock time
void AddSecond(int hours, int minutes, int seconds, string meridiem) {

	if (seconds < 59) {

		seconds ++;

	}
	else{
;
		minutes++;
		seconds = 0; 
	}
	if (!(minutes <= 59)) {

		minutes = 0;

		if (hours == 24) {

			hours = 0; 
		}
		else {
			hours++; 
		}
	}
// Calls on ClockDisplay to show user time
	ClockDisplay(hours, minutes, seconds, meridiem);

}


// ADDMINUTE: Write a function to add a minute to clock time
void AddMinute(int hours, int minutes, int seconds, string meridiem) {


	if (minutes < 59) {

		minutes ++;

	}
	else{
		minutes = 0; 

		if (hours == 24) {
			hours = 0; 
		}
		else {
			hours++; 
		}
	}
// Calls on ClockDisplay to show user time
	ClockDisplay(hours, minutes, seconds, meridiem);

}


// Add hour
void AddHour(int hours, int minutes, int seconds, string meridiem) {

	if (hours < 24) {

		hours++; 
	}
	else if (hours == 24){

		hours = 0; 
	}
// Calls on ClockDisplay to show user time
	ClockDisplay(hours, minutes, seconds, meridiem);

}


