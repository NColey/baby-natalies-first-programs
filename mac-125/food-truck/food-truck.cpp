//============================================================================
//Name: Natalie Coley
//ID: 23263431
//MAC 125
//Final Project
///============================================================================

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

class TacoTruck
{
private:
	string TruckName;
	int numberSold;
    	int justSold;
	double tacoPrice;
	int dailySales;
	double totalEarned;

public:
	TacoTruck(); //constructor

	TacoTruck(string TruckName, int newNumberSold, int newJustSold, double newTacoPrice, int newDailySales, double newTotalEarned);

	double getTacoPrice(); //accessor

	void setTacoPrice(); //mutator - sets item price

	int getNumberSold(); //accessor

	void setNumberSold(); //mutator

	int getDailySales(); //accessor

	void setDailySales(); //mutator

  	int soldToday(); //function to calculate number of items sold daily

	double getTotalEarned(); //accessor

  	void setTotalEarned(); //mutator - calculates total earnings

	void writeOutput(); //outputs sales data

	void displaySalesData(); //displays sales data to the user
};

TacoTruck::TacoTruck() //default constructor
{
	TruckName = "Tasty Tacos";
	numberSold = 0;
    	justSold = 0;
	tacoPrice = 0.0;
	dailySales = 0;
	totalEarned = 0.0;
}

TacoTruck::TacoTruck(string TruckName, int newNumberSold, int newJustSold, double newTacoPrice, int newDailySales, double newTotalEarned)
{ //constructor with parameters - initializes the variables of class TacoTruck
	TruckName = "Tasty Tacos";
	numberSold = newNumberSold;
	justSold = newJustSold;
	tacoPrice = newTacoPrice;
	dailySales = newDailySales;
	totalEarned = newTotalEarned;
}


void TacoTruck::setTacoPrice() /*Precondition: the variable has been declared. Postcondition: Sets the item price. */
{
	tacoPrice = 2.50;
}

double TacoTruck::getTacoPrice() /*Precondition: setTacoPrice() has been invoked. Postcondition: Returns the item price. */
{
	return tacoPrice;
}

void TacoTruck::setDailySales() /*Precondition: dailySales has been declared.
								  Postcondition: Uses a random number between 10 and 50 to
								  estimate a typical number of sales in a day. */
{
	dailySales = rand()%40+10;
}

int TacoTruck::getDailySales() /*Precondition: setDailySales() has been invoked. Postcondition: Returns the daily sales.*/
{
	return dailySales;
}

void TacoTruck::setNumberSold() /*Precondition: setDailySales() has been invoked.
								  Postcondition: Uses a random variable to estimate the number sold in an individual
								  transaction and records the total sold by that point in the day. */
{
	for(int i=0; i<dailySales; i++){

		justSold = numberSold;
		numberSold = rand()%5+1; /*limits the number sold to a number between 1 and 5 to maintain a realistic estimate of
								   how much would be sold in a typical food stand transaction. */
		numberSold = justSold + numberSold;
	}

}

int TacoTruck::getNumberSold() /*Precondition: setNumberSold() has been invoked. Postcondition: Returns the number of items sold in an individual transaction. */
{
	return numberSold;
}

int TacoTruck::soldToday() /*Precondition: setNumberSold() has been invoked.
							 Postcondition: Returns the total number of items sold at that point in time. */
{
    return numberSold;
    totalEarned = numberSold * tacoPrice;
}

void TacoTruck::setTotalEarned() /*Precondition: getTotalEarned() has been invoked.
								   Postcondition: Calculates the total amount earned by the stand.*/
{
	totalEarned = numberSold * tacoPrice;
}

double TacoTruck::getTotalEarned() /*Precondition: Variable totalEarned has been initialized.
									 Postcondition: Returns the total amount earned by the stand.*/
{
	return totalEarned;
}

void TacoTruck::writeOutput() /*Writes the output to the text file*/
{
	ofstream outStream("SalesData.txt", ios::out|ios::binary|ios::app);

	cout<<"Sales Info for "<<TruckName<<" Taco Stand"<<endl<<endl;
	cout<<"Truck name is: "<<TruckName;
	cout<<endl;
	cout<<"Number of sales transactions: "<<dailySales;
	cout<<endl;
	cout<<"Number sold today is: "<<numberSold;
	cout<<endl;
	cout<<"Total earned so far is: $"<<totalEarned;
	cout<<endl<<endl;

	outStream<<"Sales Info for "<<TruckName<<" Taco Stand\n\n";
	outStream<<"Truck name is: "<<TruckName<<"\n";
	outStream<<"Number of sales transactions: "<<dailySales<<"\n";
	outStream<<"Number sold today is: "<<numberSold<<"\n";
	outStream<<"Total earned so far is: $"<<totalEarned<<"\n\n";
	outStream.close();
}

void TacoTruck::displaySalesData() //Writes the output to the screen
{
	TacoTruck dailyTacoInfo;

	dailyTacoInfo.setTacoPrice();
	dailyTacoInfo.setDailySales();
	dailyTacoInfo.getDailySales();
	dailyTacoInfo.setNumberSold();
	dailyTacoInfo.getNumberSold();
	dailyTacoInfo.soldToday();
	dailyTacoInfo.setTotalEarned();
	dailyTacoInfo.writeOutput();
	cout<<endl;
}

class HotDogStand
{
private:
	string TruckName;
	int numberSold;
    int justSold;
	double hotDogPrice;
	int dailySales;
	double totalEarned;

public:
	HotDogStand(); //constructor

	HotDogStand(string TruckName, int newNumberSold, int newJustSold, double newHotDogPrice, int newDailySales, double newTotalEarned);

	double getHotDogPrice(); //accessor

	void setHotDogPrice(); //mutator - sets item price

	int getNumberSold(); //accessor

	void setNumberSold(); //mutator

	int getDailySales(); //accessor

	void setDailySales(); //mutator

    	int soldToday(); //function to calculate number of items sold daily

    	double getTotalEarned(); //accessor

    	void setTotalEarned(); //mutator - calculates total earnings

	void writeOutput(); //outputs sales data

	void displaySalesData(); //displays sales data to the user
};

HotDogStand::HotDogStand() //default constructor
{
	TruckName = "Henry's Hot Dogs";
	numberSold = 0;
    	justSold = 0;
	hotDogPrice = 0.0;
	dailySales = 0;
	totalEarned = 0.0;
}

HotDogStand::HotDogStand(string TruckName, int newNumberSold, int newJustSold, double newHotDogPrice, int newDailySales, double newTotalEarned)
{ //constructor with parameters - initializes the variables of class HotDogStand
	TruckName = "Henry's Hot Dogs";
	numberSold = newNumberSold;
	justSold = newJustSold;
	hotDogPrice = newHotDogPrice;
	dailySales = newDailySales;
	totalEarned = newTotalEarned;
}

void HotDogStand::setHotDogPrice() /*Precondition: the variable has been declared. Postcondition: Sets the item price. */
{
	hotDogPrice = 1.00;
}

double HotDogStand::getHotDogPrice() /*Precondition: setHotDogPrice() has been invoked. Postcondition: Returns the item price. */
{
	return hotDogPrice;
}

int HotDogStand::getDailySales() /*Precondition: setDailySales() has been invoked. Postcondition: Returns the daily sales.*/
{
	return dailySales;
}

void HotDogStand::setDailySales() /*Precondition: dailySales has been declared.
								  Postcondition: Uses a random number between 10 and 50 to
								  estimate a typical number of sales in a day. */
{
	dailySales = rand()%40+10;
}

int HotDogStand::getNumberSold() /*Precondition: setNumberSold() has been invoked. Postcondition: Returns the number of items sold in an individual transaction. */
{
	return numberSold;
}

void HotDogStand::setNumberSold() /*Precondition: setDailySales() has been invoked.
								  Postcondition: Uses a random variable to estimate the number sold in an individual
								  transaction and records the total sold by that point in the day. */
{
	for(int i=0; i<dailySales; i++){

		justSold = numberSold;
		numberSold = rand()%5+1; /*limits the number sold to a number between 1 and 5 to maintain a realistic estimate of
								   how much would be sold in a typical food stand transaction. */
		numberSold = justSold + numberSold;
	}

}

int HotDogStand::soldToday() /*Precondition: setNumberSold() has been invoked.
							 Postcondition: Returns the total number of items sold at that point in time. */
{
    return numberSold;
    totalEarned = numberSold * hotDogPrice;
}

double HotDogStand::getTotalEarned() /*Precondition: Variable totalEarned has been initialized.
									 Postcondition: Returns the total amount earned by the stand.*/
{
	return totalEarned;
}

void HotDogStand::setTotalEarned() /*Precondition: getTotalEarned() has been invoked.
								   Postcondition: Calculates the total amount earned by the stand.*/
{
	totalEarned = numberSold * hotDogPrice;
}

void HotDogStand::writeOutput() /*Writes the output to the text file.*/
{
	ofstream outStream("SalesData.txt", ios::out|ios::binary|ios::app);

	cout<<"Sales Info for "<<TruckName<<" Hot Dog Stand"<<endl<<endl;
	cout<<"Truck name is: "<<TruckName;
	cout<<endl;
	cout<<"Number of sales transactions: "<<dailySales;
	cout<<endl;
	cout<<"Number sold today is: "<<numberSold;
	cout<<endl;
	cout<<"Total earned so far is: $"<<totalEarned;
	cout<<endl<<endl;

	outStream<<"Sales Info for "<<TruckName<<" Hot Dog Stand\n\n";
	outStream<<"Truck name is: "<<TruckName<<"\n";
	outStream<<"Number of sales transactions: "<<dailySales<<"\n";
	outStream<<"Number sold today is: "<<numberSold<<"\n";
	outStream<<"Total earned so far is: $"<<totalEarned<<"\n";
	outStream<<"\n\n";
	outStream.close();
}

void HotDogStand::displaySalesData() //Writes the output to the screen so the user can view the sales results of the stand.
{
	HotDogStand dailyHotDogInfo;

	dailyHotDogInfo.setHotDogPrice();
	dailyHotDogInfo.setDailySales();
	dailyHotDogInfo.getDailySales();
	dailyHotDogInfo.setNumberSold();
	dailyHotDogInfo.getNumberSold();
	dailyHotDogInfo.soldToday();
	dailyHotDogInfo.setTotalEarned();
	dailyHotDogInfo.writeOutput();
	cout<<endl;
}


class IceCreamTruck
{
private:
	string TruckName;
	int numberSold;
    	int justSold;
	double iceCreamPrice;
	int dailySales;
	double totalEarned;

public:
	IceCreamTruck(); //constructor

	IceCreamTruck(string TruckName, int newNumberSold, int newJustSold, double newIceCreamPrice, int newDailySales, double newTotalEarned);

	double getIceCreamPrice(); //accessor

	void setIceCreamPrice(); //mutator - sets item price

	int getNumberSold(); //accessor

	void setNumberSold(); //mutator

	int getDailySales(); //accessor

	void setDailySales(); //mutator

    	int soldToday(); //function to calculate number of items sold daily

    	double getTotalEarned(); //accessor

    	void setTotalEarned(); //mutator - calculates total earnings

	void writeOutput(); //outputs sales data

	void displaySalesData(); //displays sales data to the user
};

IceCreamTruck::IceCreamTruck() //default constructor
{
	TruckName = "Frosty Delights";
	numberSold = 0;
    	justSold = 0;
	iceCreamPrice = 0.0;
	dailySales = 0;
	totalEarned = 0.0;
}

IceCreamTruck::IceCreamTruck(string TruckName, int newNumberSold, int newJustSold, double newIceCreamPrice, int newDailySales, double newTotalEarned)
{ //constructor with parameters - initializes the variables of class IceCreamTruck
	TruckName = "Frosty Delights";
	numberSold = newNumberSold;
	justSold = newJustSold;
	iceCreamPrice = newIceCreamPrice;
	dailySales = newDailySales;
	totalEarned = newTotalEarned;
}

void IceCreamTruck::setIceCreamPrice() /*Precondition: the variable has been declared. Postcondition: Sets the item price. */
{
	iceCreamPrice = 3.50;
}

double IceCreamTruck::getIceCreamPrice() /*Precondition: setIceCreamPrice() has been invoked. Postcondition: Returns the item price. */
{
	return iceCreamPrice;
}

int IceCreamTruck::getDailySales() /*Precondition: setDailySales() has been invoked. Postcondition: Returns the daily sales.*/
{
	return dailySales;
}

void IceCreamTruck::setDailySales() /*Precondition: dailySales has been declared.
								  Postcondition: Uses a random number between 10 and 50 to
								  estimate a typical number of sales in a day. */
{
	dailySales = rand()%40+10;
}

int IceCreamTruck::getNumberSold() /*Precondition: setNumberSold() has been invoked. Postcondition: Returns the number of items sold in an individual transaction. */
{
	return numberSold;
}

void IceCreamTruck::setNumberSold() /*Precondition: setDailySales() has been invoked.
								  Postcondition: Uses a random variable to estimate the number sold in an individual
								  transaction and records the total sold by that point in the day. */
{
	for(int i=0; i<dailySales; i++){

		justSold = numberSold;
		numberSold = rand()%5+1; /*limits the number sold to a number between 1 and 5 to maintain a realistic estimate of
								   how much would be sold in a typical food stand transaction. */
		numberSold = justSold + numberSold;
	}

}

int IceCreamTruck::soldToday() /*Precondition: setNumberSold() has been invoked.
							 Postcondition: Returns the total number of items sold at that point in time. */
{
    return numberSold;
    totalEarned = numberSold * iceCreamPrice;
}

double IceCreamTruck::getTotalEarned() /*Precondition: Variable totalEarned has been initialized.
									 Postcondition: Returns the total amount earned by the stand.*/
{
	return totalEarned;
}

void IceCreamTruck::setTotalEarned() /*Precondition: getTotalEarned() has been invoked.
								   Postcondition: Calculates the total amount earned by the stand.*/
{
	totalEarned = numberSold * iceCreamPrice;
}

void IceCreamTruck::writeOutput() /*Writes the output to the text file.*/
{
	ofstream outStream("SalesData.txt", ios::out|ios::binary|ios::app);

	cout<<"Sales Info for "<<TruckName<<" Ice Cream Truck"<<endl<<endl;
	cout<<"Truck name is: "<<TruckName;
	cout<<endl;
	cout<<"Number of sales transactions: "<<dailySales;
	cout<<endl;
	cout<<"Number sold today is: "<<numberSold;
	cout<<endl;
	cout<<"Total earned so far is: $"<<totalEarned;
	cout<<endl<<endl;

	outStream<<"Sales Info for "<<TruckName<<" Ice Cream Truck\n\n";
	outStream<<"Truck name is: "<<TruckName<<"\n";
	outStream<<"Number of sales transactions: "<<dailySales<<"\n";
	outStream<<"Number sold today is: "<<numberSold<<"\n";
	outStream<<"Total earned so far is: $"<<totalEarned<<"\n\n";

	outStream.close();
}

void IceCreamTruck::displaySalesData() //Writes the output to the screen so the user can view the sales results of the stand.
{
	IceCreamTruck dailyIceCreamInfo;

	dailyIceCreamInfo.setIceCreamPrice();
	dailyIceCreamInfo.setDailySales();
	dailyIceCreamInfo.getDailySales();
	dailyIceCreamInfo.setNumberSold();
	dailyIceCreamInfo.getNumberSold();
	dailyIceCreamInfo.soldToday();
	dailyIceCreamInfo.setTotalEarned();
	dailyIceCreamInfo.writeOutput();
	cout<<endl<<endl;
}

int main() {

	//displaying the sales data

	cout << "***************************************************" <<endl;
	cout<< " Welcome to Natalie's Mobile Food Service Emporium"<<endl;
	cout << "***************************************************"<<endl<<endl;

	TacoTruck displayTacoSales;
	displayTacoSales.displaySalesData();

	HotDogStand displayHotDogSales;
	displayHotDogSales.displaySalesData();

	IceCreamTruck displayIceCreamSales;
	displayIceCreamSales.displaySalesData();

	//reading data from the text file

	cout<<"The sales data has been saved to a file called SalesData.txt. \n\n";
	cout<<"Would you like to read the data from this file? \n";
	cout<<"If so press Y for yes and any other key to exit\n\n";
	char next;
	cin>>next;


	if(next=='Y'|| next=='y')
	{
		ifstream inStream("SalesData.txt");
		if(inStream.fail())
			{
				cout<<"Input file opening failed.";
				exit(1);
			}
		string content;
		while (inStream>>content){
			cout<<content<<' ';
		}


		inStream.close();

	}

	return 0;
}
