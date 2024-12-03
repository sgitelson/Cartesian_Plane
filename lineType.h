//------------------------------------------------------------------------------------
// Title: lineType.h
// Course: CPET 321
// Developer: Sam Gitelson (Computer Engineering Technology)
// Date: 10/23/24
// Description: Header file used to create the lineType class. Each lineType object
//				is a line in the Cartesian plane.
// -----------------------------------------------------------------------------------
#ifndef LINETYPE_H_
#define LINETYPE_H_

#include <iostream>
#include <string>

using namespace std;

class lineType {
	private:
		float a, b, c;
	public:
		/*constructor*/
		lineType(float = 1.0, float = 1.0, float = 1.0); //default constructor sets a = 1.0, b = 1.0, c = 1.0

		/*mutator*/
		void setCoefficient(float, float, float);

		/*accessor*/
		void displayLine() const;

		/*const functions*/
		float lineSlope() const;
		float lineSlopeNoText() const;
		void lineIntersection(lineType) const;

		/*operator overloads*/
		bool operator==(lineType);
		bool operator||(lineType);
		bool operator&&(lineType);


};
#endif
