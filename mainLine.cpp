//------------------------------------------------------------------------------------
// Title: mainLine.cpp
// Course: CPET 321
// Developer: Sam Gitelson (Computer Engineering Technology)
// Date: 10/23/24
// Description: Main file for Lab 5. Creates 4 lines and presents a menu with options 
//				for various things you can do with the lines.
// -----------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include "lineType.h"

using namespace std;

lineType L1(2.5, -1.2, 3.7);
lineType L2(1.2, 2.5, -8.9);
lineType L3(2.7, -3.6, -5.7);
lineType L4(5.4, -7.2, -11.4);

vector<lineType> lines{ L1, L2, L3, L4 };

int main() {

	string option;
	string lineChoice;
	lineType lineHold1;
	lineType lineHold2;
	float aHold, bHold, cHold;

	while (true) {

		bool optloop = true;

		cout << "\nOptions for lines L1, L2, L3, and L4:"
			<< "\nSet (SET): Choose a line and change its coefficients."
			<< "\nDisplay (DIS): Choose a line and display its equation."
			<< "\nDisplay All (DISALL): Displays the equations for all lines."
			<< "\nSlope (SLPE): Choose a line and display its slope."
			<< "\nEqual (EQ): Choose two lines and check if they are equal."
			<< "\nParallel (PAR): Choose two lines and check if they are parallel."
			<< "\nPerpendicular (PER): Choose two lines and check if they are perpendicular."
			<< "\nIntersection (INT): Choose two lines and find there intersection point."
			<< "\nQuit (QUIT): Exits the program.";

		cout << "\nTo select an option, enter the corresponding option code shown in parentheses.\n";
		
		//sets user input to all caps to eliminate character sensitivity
		cin >> option;
		for (char& c : option) {
			c = toupper(c);
		}

		//set option, user chooses new coefficients for a line, and then which line to assign them to
		//uses setCoefficient member function
		if (option == "SET") {
			cout << "\nSet option chosen.";
			cout << "\nEnter 3 float values for coefficients a, b, and c\n";
			cin >> aHold; cin >> bHold; cin >> cHold;
			while (optloop == true) {
				cout << "\nChoose a line [L1, L2, L3, L4] (case sensitive)\n";
				cin >> lineChoice;
				if (lineChoice == "L1") {
					L1.setCoefficient(aHold, bHold, cHold);
					cout << "\nNew line 1 equation: ";
					L1.displayLine();
					optloop = false;
				}
				else if (lineChoice == "L2") {
					L2.setCoefficient(aHold, bHold, cHold);
					cout << "\nNew line 2 equation: ";
					L2.displayLine();
					optloop = false;
				}
				else if (lineChoice == "L3") {
					L3.setCoefficient(aHold, bHold, cHold);
					cout << "\nNew line 3 equation: ";
					L3.displayLine();
					optloop = false;
				}
				else if (lineChoice == "L4") {
					L4.setCoefficient(aHold, bHold, cHold);
					cout << "\nNew line 4 equation: ";
					L4.displayLine();
					optloop = false;
				}
				else {
					cin.clear();
					cout << "\nInvalid input.";
				}
			} //optloop
		} //SET

		//display option, user chooses a line, then that line is displayed in standard form for the Cartesian Plane
		//uses displayLine member function
		else if (option == "DIS") {
			cout << "\nDisplay option chosen.";
			while (optloop == true) {
				cout << "\nChoose a line [L1, L2, L3, L4] (case sensitive)\n";
				cin >> lineChoice;
				if (lineChoice == "L1") {
					cout << "\nLine 1 equation: ";
					L1.displayLine();
					optloop = false;
				}
				else if (lineChoice == "L2") {
					cout << "\nLine 2 equation: ";
					L2.displayLine();
					optloop = false;
				}
				else if (lineChoice == "L3") {
					cout << "\nLine 3 equation: ";
					L3.displayLine();
					optloop = false;
				}
				else if (lineChoice == "L4") {
					cout << "\nLine 4 equation: ";
					L4.displayLine();
					optloop = false;
				}
				else {
					cout << "\nInvalid input.";
				}
			 }//disloop
		}//DISPLAY

		//display all oprion, displays all 4 lines in standard form for the Cartesian Plane
		//uses displayLine member function
		else if (option == "DISALL") {
			cout << "\nDisplay All option chosen.";
			for (lineType line : lines) {
				line.displayLine();
			}//disallloop
		}//DISPLAY ALL

		//slope option, user chooses a line, then the slope of the line is calculated and displayed
		//uses lineSlope member function
		else if (option == "SLPE") {
			cout << "\nSlope option chosen.";
			while (optloop == true) {
				cout << "\nChoose a line [L1, L2, L3, L4] (case sensitive)\n";
				cin >> lineChoice;
				if (lineChoice == "L1") {
					cout << "\nLine 1 slope: ";
					L1.lineSlope();
					optloop = false;
				}
				else if (lineChoice == "L2") {
					cout << "\nLine 2 slope: ";
					L2.lineSlope();
					optloop = false;
				}
				else if (lineChoice == "L3") {
					cout << "\nLine 3 slope: ";
					L3.lineSlope();
					optloop = false;
				}
				else if (lineChoice == "L4") {
					cout << "\nLine 4 slope: ";
					L4.lineSlope();
					optloop = false;
				}
				else {
					cout << "\nInvalid input.";
				}
			}//slopeloop
		}//SLOPE


		//equals option, user chooses 2 lines and is informed whether they are equal or not
		//uses the == operator overload for lineType
		else if (option == "EQ") {
			cout << "\nEqual option chosen";
			while (optloop == true) {
				cout << "\nChoose the first line [L1, L2, L3, L4] (case sensitive)\n";
				cin >> lineChoice;
				if (lineChoice == "L1") {
					lineHold1 = L1;
					optloop = false;
				}
				else if (lineChoice == "L2") {
					lineHold1 = L2;
					optloop = false;
				}
				else if (lineChoice == "L3") {
					lineHold1 = L3;
					optloop = false;
				}
				else if (lineChoice == "L4") {
					lineHold1 = L4;
					optloop = false;
				}
				else {
					cout << "\nInvalid input.";
				}
			}//eq1loop
			optloop = true;
			while (optloop == true) {
				cout << "\nChoose the second line [L1, L2, L3, L4] (case sensitive)\n";
				cin >> lineChoice;
				if (lineChoice == "L1") {
					lineHold2 = L1;
					optloop = false;
				}
				else if (lineChoice == "L2") {
					lineHold2 = L2;
					optloop = false;
				}
				else if (lineChoice == "L3") {
					lineHold2 = L3;
					optloop = false;
				}
				else if (lineChoice == "L4") {
					lineHold2 = L4;
					optloop = false;
				}
				else {
					cout << "\nInvalid input.";
				}
			}//eq2loop
			cout << "Line 1: "; lineHold1.displayLine();
			cout << "Line 2: "; lineHold2.displayLine();
			if (lineHold1 == lineHold2) {
				cout << "\nThese lines are equal.\n";
			}
			else {
				cout << "\nThese lines are not equal.\n";
			}
		}//EQUAL

		//parallel option, user chooses 2 lines and is informed if they are parallel or not
		//uses the || operator overload for lineType
		else if (option == "PAR") {
			cout << "\nParallel option chosen.";
			while (optloop == true) {
				cout << "\nChoose the first line [L1, L2, L3, L4] (case sensitive)\n";
				cin >> lineChoice;
				if (lineChoice == "L1") {
					lineHold1 = L1;
					optloop = false;
				}
				else if (lineChoice == "L2") {
					lineHold1 = L2;
					optloop = false;
				}
				else if (lineChoice == "L3") {
					lineHold1 = L3;
					optloop = false;
				}
				else if (lineChoice == "L4") {
					lineHold1 = L4;
					optloop = false;
				}
				else {
					cout << "\nInvalid input.";
				}
			}//par1loop
			optloop = true;
			while (optloop == true) {
				cout << "\nChoose the second line [L1, L2, L3, L4] (case sensitive)\n";
				cin >> lineChoice;
				if (lineChoice == "L1") {
					lineHold2 = L1;
					optloop = false;
				}
				else if (lineChoice == "L2") {
					lineHold2 = L2;
					optloop = false;
				}
				else if (lineChoice == "L3") {
					lineHold2 = L3;
					optloop = false;
				}
				else if (lineChoice == "L4") {
					lineHold2 = L4;
					optloop = false;
				}
				else {
					cout << "\nInvalid input.";
				}
			}//par2loop
			cout << "Line 1: "; lineHold1.displayLine();
			cout << "Line 2: "; lineHold2.displayLine();
			if (lineHold1 || lineHold2) {
				cout << "\nThese lines are parallel.\n";
			}
			else {
				cout << "\nThese lines are not parallel.\n";
			}
		}//PARALLEL

		//perpendicular option, user chooses 2 lines and is informed if they are perpendicular or not
		//uses the && operator overload for lineType
		else if (option == "PER") {
			cout << "\nPerpendicular option chosen.";
			while (optloop == true) {
				cout << "\nChoose the first line [L1, L2, L3, L4] (case sensitive)\n";
				cin >> lineChoice;
				if (lineChoice == "L1") {
					lineHold1 = L1;
					optloop = false;
				}
				else if (lineChoice == "L2") {
					lineHold1 = L2;
					optloop = false;
				}
				else if (lineChoice == "L3") {
					lineHold1 = L3;
					optloop = false;
				}
				else if (lineChoice == "L4") {
					lineHold1 = L4;
					optloop = false;
				}
				else {
					cout << "\nInvalid input.";
				}
			}//per1loop
			optloop = true;
			while (optloop == true) {
				cout << "\nChoose the second line [L1, L2, L3, L4] (case sensitive)\n";
				cin >> lineChoice;
				if (lineChoice == "L1") {
					lineHold2 = L1;
					optloop = false;
				}
				else if (lineChoice == "L2") {
					lineHold2 = L2;
					optloop = false;
				}
				else if (lineChoice == "L3") {
					lineHold2 = L3;
					optloop = false;
				}
				else if (lineChoice == "L4") {
					lineHold2 = L4;
					optloop = false;
				}
				else {
					cout << "\nInvalid input.";
				}
			}//per2loop
			cout << "Line 1: "; lineHold1.displayLine();
			cout << "Line 2: "; lineHold2.displayLine();
			lineHold1.lineSlope();
			lineHold2.lineSlope();
			if (lineHold1 && lineHold2) {
				cout << "\nThese lines are perpendicular.\n";
			}
			else {
				cout << "\nThese lines are not perpendicular.\n";
			}
		}//PERPENDICULAR

		//intersection option, user chooses 2 lines, and the point of intersection of the lines is calculated and displayed
		//uses lineIntersection member function
		else if (option == "INT") {
			cout << "\nIntersection option chosen.";
			while (optloop == true) {
				cout << "\nChoose the first line [L1, L2, L3, L4] (case sensitive)\n";
				cin >> lineChoice;
				if (lineChoice == "L1") {
					lineHold1 = L1;
					optloop = false;
				}
				else if (lineChoice == "L2") {
					lineHold1 = L2;
					optloop = false;
				}
				else if (lineChoice == "L3") {
					lineHold1 = L3;
					optloop = false;
				}
				else if (lineChoice == "L4") {
					lineHold1 = L4;
					optloop = false;
				}
				else {
					cout << "\nInvalid input.";
				}
			}//int1loop
			optloop = true;
			while (optloop == true) {
				cout << "\nChoose the second line [L1, L2, L3, L4] (case sensitive)\n";
				cin >> lineChoice;
				if (lineChoice == "L1") {
					lineHold2 = L1;
					optloop = false;
				}
				else if (lineChoice == "L2") {
					lineHold2 = L2;
					optloop = false;
				}
				else if (lineChoice == "L3") {
					lineHold2 = L3;
					optloop = false;
				}
				else if (lineChoice == "L4") {
					lineHold2 = L4;
					optloop = false;
				}
				else {
					cout << "\nInvalid input.";
				}
			}//int2loop
			cout << "Line 1: "; lineHold1.displayLine();
			cout << "Line 2: "; lineHold2.displayLine();
			lineHold1.lineIntersection(lineHold2);
		}//INTERSECTION

		//quit option, exits the program
		else if (option == "QUIT") {
			exit(1);
		}//QUIT

		else {
			cout << "\nInvalid input.";
		}//OTHER

	} //mainloop	
} //main