/*
 * =============================================================
 * TND012: Dugga 1
 * Author:Romeo Dahlström
 * LiU-id:romda293@student.liu.se
 * =============================================================
 */

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	//initilazed variables 
	double wallWidth = 0; 
	double wall_toBottmRoof_height = 0; 
	double wall_toTipOfRoof_height = 0; 
	double windowWidth = 0; 
	double windowHeight = 0; 
	double canPrice = 0; 
	double totCanPrice = 0; 
	double discountPercent = 0.1; //10% discount 
	double can_paintArea = 25.00; 
	int tenCans = 10; 
	
	//Printing the user interface for where to enter the value for the asked variable and then storing it in that varibale. This is repeated for all the first 6 initialzed variables. 
	std::cout << "How wide is the wall?"; 
	std::cin >> wallWidth;
	std::cout << "How high is the wall to the bottom of the roof?";
	std::cin >> wall_toBottmRoof_height;
	std::cout << "How high is the wall to the tip of the slanted roof?";
	std::cin >> wall_toTipOfRoof_height;
	std::cout << "How wide is the window?";
	std::cin >> windowWidth;
	std::cout << "How high is the window?";
	std::cin >> windowHeight;
	std::cout << "Price of a can?";
	std::cin >> canPrice;

	//Prints a summary of all the input to the user
	std::cout << "\nA side wall that is\n\t" << std::fixed << std::setprecision(2) 
		<< wallWidth << " m wide,\n\t"
		<< wall_toBottmRoof_height << " m to the roof bottom,\n\t"
		<< wall_toTipOfRoof_height << " m to the tip of the slanted roof,\n"
		<< "containing a window that is\n\t"
		<< windowWidth << " m wide and\n\t"
		<< windowHeight << " m high," << std::endl; 
	
	///I have split the houseface into two parts: the triangle being the slanted roof and the rectangle being the wall base to the bottom of roof (I will call this recWall i.e. rectangle wall, for simplicity ).
	//calucaltes the slanted-roof area using the formual for finding the triangle area: (1/2) * base * height.
	double roofHeight = wall_toTipOfRoof_height - wall_toBottmRoof_height;
	double roofArea = (1.00/2.00) * wallWidth * roofHeight; ///the wall width is the base of the roof so the base of the triangle. 

	//calucaltes the window area using the forumla for finding the rectangle area: width * height.
	double windowArea = windowWidth * windowHeight;

	//calucaltes the recWall area using the forumla for finding the rectangle area: width * height.
	double recWallArea = wallWidth * wall_toBottmRoof_height;
	double tot_recWallArea = recWallArea - windowArea; //the window area must be substracted from rectWall area since the window will not be painted. 
	
	//add the two areas together to get the total area
	double totWallArea = tot_recWallArea + roofArea; 
	
	//divide the total area by 25m^2 to get how many cans are needed and then round it up with std::ceil to get the total amount of cans required to buy. 
	double totCans = std::ceil(totWallArea / can_paintArea); 

	//calculates the total price for the required cans of paint 
	bool discount = totCans > tenCans; 
	if (discount){
		double discountNumb = discountPercent * canPrice;
		double disCan_amount = totCans - tenCans; //Amount of cans being discounted.
		double non_disCan_amount = totCans - disCan_amount; //Amount of cans not being discounted.
		double disCan_Price = disCan_amount*(canPrice - discountNumb);//How much it costs for all the cans that got discounte. Note: it is a viable option to calculate it like this: disCan_amount * canPrice - disCan_amount * discountNumb; but factoring out disCan_amount makes it simplier. 
		double non_disCan_Price = non_disCan_amount * canPrice; //How much it costs for all the cans tat was not discounted.
		totCanPrice = non_disCan_Price + disCan_Price; //The total cost for all the cans.
	}
	else {
		totCanPrice = totCans * canPrice; //The total cost for all the cans 
	}
	
	//prints the result for the total wall area (rounded to 2 decimals), total amount of cans required to buy to paint the total wall area, and the total price for all the paint cans (rounded to 2 decimals)
	std::cout << "has " << std::fixed << std::setprecision(2) << totWallArea << " square meters of paintable wall\nand "
		<< std::setprecision(0) << totCans << " cans of paint need to be bought\n(assuming that each can covers 25 square meters of wall)\n\n"
		<< "Total price = " << std::setprecision(2) << totCanPrice << " :-" << std::endl;

	return 0; 
}