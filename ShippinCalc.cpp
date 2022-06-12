#include <iostream>
#include <iomanip>  // imported this iomanip library to use format manipulators
#include <string>
#include <fstream> // this library is used for any text input and output to an external file
#include <algorithm> 

using namespace std;

//Declaring the constants

const int CharactLength = 50; // length of total number of dots that I have put in top line 

int main() {


	//Used these output statements to make program introduction
	//setfill() fills character based on the specified character
	//setw() helps set the field width used for output operations.

	cout << setfill('.');
	cout << setw(50) << "." << endl;
	cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
	cout << setfill('.');
	cout << setw(50) << "." << endl;
	cout << endl;

	cout << fixed << showpoint << setprecision(2); // floating-point values will be written in fixed point notations using fixed method 

	//declaring the variables that I will be using
	ofstream outFile;
	double shippingCost = 0;
	double orderTotal = 0;
	string itemName;
	string destination;
	char isFragile = 0;

	outFile.open("Order.txt");

	//Prompting the user for itemName
	string Output = "Please enter the item name (no space)";
	cout << Output << std::right << std::setw(CharactLength - Output.length()) << itemName, cin >> itemName;
	cout << endl;

	//asking user if the item is fragile
	string a = "Is the item fragile? (y=yes/n=no)";
	cout << a << std::right << std::setw(CharactLength - a.length()) << isFragile, cin >> isFragile;
	cout << endl;

	// Checking if the item is fragile using if else if statements
	if (isFragile == 'y' || isFragile == 'Y') {
		shippingCost += 2;
	}
	else if (isFragile == 'n' || isFragile == 'N') {
		shippingCost = 0;
	}
	else {
		cout << "Invalid entry, exiting" << endl;
		system("pause");
		exit(0);
	}

	//prompting user to enter order total
	string b = "Please enter your order total "; //prompting user to enter order total
	cout << b << std::right << std::setw(CharactLength - b.length()), cin >> orderTotal;
	cout << endl;


	string c = "Please enter destination. (usa/can/aus/mars)";//prompting user to enter destination
	cout << c << std::right << std::setw(CharactLength - c.length()) << destination, cin >> destination;
	cout << endl;


	transform(destination.begin(), destination.end(), destination.begin(), ::toupper); // converts string to upper case. In this case the values stored in destination 
	transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);

	//checking for the destination of the shipment using if else if statements
	if (destination == "USA")
	{
		if (orderTotal <= 50.00)
			shippingCost = shippingCost + 6.00;
		else if (orderTotal > 50.00 || orderTotal <= 100.00)
			shippingCost = shippingCost + 9.00;
		else if (orderTotal > 100.00 || orderTotal <= 150.00)
			shippingCost = shippingCost + 12.00;
		else
			shippingCost = 0.0;
	}

	else if (destination == "CAN") {
		if (orderTotal <= 50.00)
			shippingCost = shippingCost + 8.00;
		else if (orderTotal > 50.00 || orderTotal <= 100.00)
			shippingCost = shippingCost + 12.00;
		else if (orderTotal > 100.00 || orderTotal <= 150.00)
			shippingCost = shippingCost + 15.00;
		else
			shippingCost = 0.0;
	}
	else if (destination == "AUS") {
		if (orderTotal <= 50.00)
			shippingCost = shippingCost + 10.00;
		else if (orderTotal > 50.00 || orderTotal <= 100.00)
			shippingCost = shippingCost + 14.00;
		else if (orderTotal > 100.00 || orderTotal <= 150.00)
			shippingCost = shippingCost + 17.00;
		else
			shippingCost = 0.0;
	}
	else if (destination == "MARS") {
		if (orderTotal <= 50.00)
			shippingCost = shippingCost + 20.00;
		else if (orderTotal > 50.00 || orderTotal <= 100.00)
			shippingCost = shippingCost + 30.00;
		else if (orderTotal > 100.00 || orderTotal <= 150.00)
			shippingCost = shippingCost + 35.00;
		else
			shippingCost = 0.0;
	}
	else {
		cout << "Invalid entry, exiting" << endl;
		exit(0);
	}

	//Outputting all the entered values after calculation
	string d = "\n\nYour item is  ";
	cout << d << std::right << std::setw(CharactLength - d.length()) << itemName << endl;
	string e = "Your shipping cost is $";
	cout << e << std::right << std::setw(CharactLength - e.length()) << shippingCost << endl;
	string f = "You are shipping to";
	cout << f << std::right << std::setw(CharactLength - f.length()) << destination << endl;

	double totalCost = shippingCost + orderTotal;
	string g = "Your total shipping costs are $";
	cout << g << std::right << std::setw(CharactLength - g.length()) << totalCost << endl;
	string h = "----------------------------------------------Thank you !";
	cout << h << std::right << std::setw(CharactLength - h.length()) << endl;

	//Here I am using outFile instead of cout so that it writes to the file named Order.txt

	outFile << fixed << showpoint << setprecision(2); // floating-point values will be written in fixed point notations using fixed method

	string i = "\n\nYour item is  "; // Had to use different alphabets (ex - i,j,k etc) because i get an error saying variable already used if i use the same variable
	outFile << i << std::right << std::setw(CharactLength - i.length()) << itemName << endl;
	string j = "Your shipping cost is $";
	outFile << j << std::right << std::setw(CharactLength - j.length()) << shippingCost << endl;
	string k = "You are shipping to";
	outFile << k << std::right << std::setw(CharactLength - k.length()) << destination << endl;
	string l = "Your total shipping costs are $";
	outFile << l << std::right << std::setw(CharactLength - l.length()) << totalCost << endl;
	string m = "----------------------------------------------Thank you !";
	outFile << m << std::right << std::setw(CharactLength - m.length()) << endl;

	outFile.close(); // closing the output file that writes to an external file, in this case Order.txt
	system("pause");

}

