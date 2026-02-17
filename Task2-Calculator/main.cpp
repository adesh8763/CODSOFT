#include <iostream>
#include <string>
#include <limits>

template<typename T>
T getNumber(std::string prompt){
    
    T input;
    while(true){
        std::cout << prompt;
        if(std::cin >> input){
            return input;
        }
        std::cout << "Invalid Input! Try again..." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } 
}

template<typename T>
void executeCalculation(T n1, T n2, int op){
    std::cout << "The Result is: ";
    switch(op){
        case 1: std::cout << n1 + n2; break;
        case 2: std::cout << n1 - n2; break;
        case 3: std::cout << n1 * n2; break;
        case 4: 
                if(n2 == 0) {
                    std::cout << "Undefined(Division by Zero)";
                }
                else{
                    std::cout << n1 / n2;
                }
                break;
        default: std::cout << "Invalid Operation!"; 
    }
    std::cout << std::endl;
}

int main(){
    std::cout << "#####-----Simple calculator-----#####\n\n";
    
    int choice = getNumber<int>("Choose type (1 for Integer, 2 for Double): ");
    
    if(choice == 1){
        int num1 = getNumber<int>("Enter The First Number: ");
        int op = getNumber<int>("Enter Operation ( 1 [+], 2 [-], 3 [*], 4[/]): ");
        int num2 = getNumber<int>("Enter The Second Number: ");
        executeCalculation(num1, num2, op);
    }
    else if(choice == 2){
        double num1 = getNumber<double>("Enter The First Number: ");
        int op = getNumber<int>("Enter Operation ( 1 [+], 2 [-], 3 [*], 4[/]): ");
        double num2 = getNumber<double>("Enter The Second Number: ");
        executeCalculation(num1, num2, op);
    }
    else{
        std::cout << "Invalid choice!\n";
    }
    
    return 0;
}