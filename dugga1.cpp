/*
 * =============================================================
 * TND012: Dugga 1
 * Author:Romeo Dahlström
 * LiU-id:romda293@student.liu.se
 * =============================================================
 */

#include <iostream>
#include <cmath>

int main() {
	//initilazed variables 
	double wallWidth; 
	double wall_toBottmRoof_height;
	double wall_toTipOfRoof_height; 
	double windowWidth; 
	double windowHeight; 
	double canPrice; 

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
	
}


