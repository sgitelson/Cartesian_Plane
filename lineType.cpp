//------------------------------------------------------------------------------------
// Title: lineType.cpp
// Course: CPET 321
// Developer: Sam Gitelson (Computer Engineering Technology)
// Date: 10/23/24
// Description: Body file for class lineType. Each line in the Cartesian Plane can be
//				compared and manipulated in various ways.
// -----------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include "lineType.h"

using namespace std;

/* constructor for lineType */
lineType::lineType(float a, float b, float c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

/* mutator for lineType */
//changes the coefficients for the line
void lineType::setCoefficient(float a, float b, float c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

/* accessor for lineType */
//displays the line in the form ax + by = c
void lineType::displayLine() const {
	if (b < 0) { //if b is negative, swap the + for a - and flip the sign for b
		cout << "\nLine = " << a << "x - " << (b * -1.0) << "y = " << c << "\n";
	}
	else {
		cout << "\nLine = " << a << "x + " << b << "y = " << c << "\n";
	}
}

/* calculates the slope of a given line */
float lineType::lineSlope() const {
	float slope;
	if (a == 0) { //if a = 0, line is horizontal
		slope = 0;
		cout << "\nThe slope of the line is: " << slope << ", AKA horizontal\n";
	}
	else if (b == 0) { //if b = 0, line is vertical
		slope = numeric_limits<float>::infinity();
		cout << "\nThe slope of the line is: Infinity, AKA vertical\n";
	}
	else { //otherwize, it calculates the slope based on the provided equation
		slope = -1 * (a / b);
		cout << "\nThe slope of the line is: " << slope << "\n";
	}
	return slope;
}

float lineType::lineSlopeNoText() const {
	float slope;
	if (a == 0) { //if a = 0, line is horizontal
		slope = 0;
	}
	else if (b == 0) { //if b = 0, line is vertical
		slope = numeric_limits<float>::infinity();
	}
	else { //otherwize, it calculates the slope based on the provided equation
		slope = -1 * (a / b);
	}
	return slope;
}

/* operator overload for ==, equates 2 lines in the Cartesian Plane */
//The math used in this function is as follows: if a2 mod a1 = 0, and same for b and c,
//then the lines are equal. This accounts for exact equavalence and scalar multiples of
//the given line. The function fmod(X,Y) is not commutative, so all values are tested in
//both positions of fmod(X,Y) to allow for overloaded operator commutativity.
bool lineType::operator==(lineType line) {
	bool ans;
	if (0 == (fmod(line.a, a)) && 0 == (fmod(line.b, b)) && 0 == (fmod(line.c, c))) {
		ans = true;
	}
	else if (0 == (fmod(a, line.a)) && 0 == (fmod(b, line.b)) && 0 == (fmod(c, line.c))) {
		ans = true;
	}
	else {
		ans = false;
	}
	return ans;
}

/* operator overload for ||, checks if 2 lines in the Cartesian Plane are parallel */
bool lineType::operator||(lineType line) {
	bool ans;
	if (lineSlope() == line.lineSlope()) { //if two lines have the same slope, the are parallel
		ans = true;
	}
	else {
		ans = false;
	}
	return ans;
}

/* operator overload for &&, checks if 2 lines in the Cartesian Plane are perpendicular */
//The first 2 if statements check for a vertical and horizontal line (slope 0 and slope infinity).
//Similar to the == operator overload, this functions tests if the first line has slope 0 and the
//second line has slope infinity, and vise versa to allow for operator commutativity
bool lineType::operator&&(lineType line) {
	bool ans;
	if (lineSlopeNoText() == 0 && line.lineSlopeNoText() == numeric_limits<float>::infinity()) {
		ans = true;
	}
	else if (lineSlopeNoText() == numeric_limits<float>::infinity() && line.lineSlopeNoText() == 0) {
		ans = true;
	}
	else if ((lineSlopeNoText() * line.lineSlopeNoText()) == -1.0) { //if the product of the slopes of 2 lines equals -1, then the lines are perpendicular
		ans = true;
	}
	else {
		ans = false;
	}
	return ans;
}

/* calculates the point of intersection of 2 lines in the Cartesian Plane */
void lineType::lineIntersection(lineType line) const {
	/* copy of the == operator overload */
	if (0 == (fmod(line.a, a)) && 0 == (fmod(line.b, b)) && 0 == (fmod(line.c, c))) {
		cout << "\nThe selected lines are equal, so they are always intersecting.\n";
	}
	else if (0 == (fmod(a, line.a)) && 0 == (fmod(b, line.b)) && 0 == (fmod(c, line.c))) {
		cout << "\nThe selected lines are equal, so they are always intersecting.\n";
	}
	/* copy of the || operator overload */
	else if (lineSlope() == line.lineSlope()) {
		cout << "\nThe selected lines are parallel, so they never intersect.\n";
	}
	/* calculates the intersection of the 2 lines using the given equation  */
	else {
		float x, y;
		x = ((c * line.b) - (line.c * b)) /
			((a * line.b) - (line.a * b));

		y = (c / b) - ((a / b) * x);
		
		cout << "\nThe point where these two lines intersect is: ( " << x << " , " << y << " )\n";
	}
}