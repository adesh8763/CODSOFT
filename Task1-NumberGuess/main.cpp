#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main(){
	srand(static_cast<unsigned int>(time(0)));
	int generatedNumber = rand()%101;
	int guessedNumber = 0;
	int steps = 0;
	std::cout <<"#####-----Number Guessing Game-----#####" << std::endl;
	while(true){
		std::cout << "Enter a guess(0-100): ";
		if(!(std::cin >> guessedNumber)){
			std::cout << "Invalid Input! Try again...\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		++steps;
		if(guessedNumber == generatedNumber){
			std::cout << "Congratulations! You guessed it Right in "<< steps << " steps.\n";
			break;
		}
		std::cout << ((guessedNumber > generatedNumber)? "Too High" : "Too Low") << "! Try again...\n";
	}
	return 0;
}
