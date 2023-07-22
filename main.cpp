#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>

const int DENOMINATIONS = 4;
const int NUMBEROFCUSTOMERS = 10;

class Customer;
void storeData(Customer customers[]);
void determineCoins(Customer customers[]);
int displayMenu();
void getName();
void searchArray();
void displayCoins();
void writeData();

class Customer {
private:
    std::string name;
    int change;

public:

    int coins[DENOMINATIONS];

    void setName(std::string newName){
        name = newName;
    }
    std::string getName(){
        return name;
    }
    void setChange(int newChange){
        change = newChange;
    }
    int getChange(){
        return change;
    }
    void setCoins(int newCoins[]){
        std::copy(newCoins, newCoins+4, coins);
    }
    int getCoins(){
        return *coins;
    }
};

int main() {

    Customer customers[NUMBEROFCUSTOMERS];

    std::ofstream outFile;


    outFile.open("/Users/melodyflavel/CLionProjects/CoinsCalculator/change.csv");
    if(!outFile.is_open()){
        std::cout << "Error opening output file!" << std::endl;
        return 0;
    }

    storeData(customers);
    determineCoins(customers);

    return 0;
}

void storeData(Customer customers[]){

    std::ifstream inFile;
    int index = 0;
    std::string name;
    int change;

    inFile.open("/Users/melodyflavel/CLionProjects/CoinsCalculator/coins.txt");
    if(!inFile.is_open()){
        std::cout << "Error opening input file!" << std::endl;
    }

    while (index < NUMBEROFCUSTOMERS && inFile >> name >> change){
        customers[index].setName(name);
        customers[index].setChange(change);
        index++;
    }
}

void determineCoins(Customer customers[]){

    for (int i = 0; i < NUMBEROFCUSTOMERS; i++){
        customers[i].coins[0] = 0;
        customers[i].coins[1] = 0;
        customers[i].coins[2] = 0;
        customers[i].coins[3] = 0;

        int change = customers[i].getChange();

            while(change >= 50) {
                customers[i].coins[0] = customers[i].coins[0] + 1;
                change = change - 50;
            }
            while(change >= 20) {
                customers[i].coins[1] = customers[i].coins[1] + 1;
                change = change - 20;
            }
            while(change >= 10) {
                customers[i].coins[2] = customers[i].coins[2] + 1;
                change = change - 10;
            }
            while(change >= 5) {
                customers[i].coins[3] = customers[i].coins[3] + 1;
                change = change - 5;
        }
    }
}


int showMenu(){
    return 0;
}

void getName(){

}

void searchArray(){

}

void displayCoins(){

}

void writeData(){

}