#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

const int DENOMINATIONS = 4;
const int NUMBEROFCUSTOMERS = 10;

class Customer;
void storeData(Customer customers[]);
void determineCoins(Customer customers[]);
int displayMenu();
int findName(std::string name, Customer customers[]);
void displayCoins(Customer customers[], int index);
void writeData(Customer customers[]);

class Customer {
private:
    std::string name;
    int change;
    std::vector<int> coins;

public:

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
    void setCoins(const std::vector<int> &newCoins){
        coins = newCoins;
    }
    std::vector<int> const &getCoins() const {
        return coins;
    }
};

int main() {

    Customer customers[NUMBEROFCUSTOMERS];
    int option; std::string name; int index;

    storeData(customers);
    determineCoins(customers);

    do {

        option = displayMenu();
        switch(option){
            case 1:
                std::cout << "Please enter a name: ";
                std::cin >> name;
                index = findName(name, customers);
                displayCoins(customers, index);
                break;
            case 2:
                writeData(customers);
                std::cout << "Quitting program...\n";
                break;
            default:
                std::cout << "Invalid option.\n";
                break;
        }
    } while (option != 2);

    return 0;
}

void storeData(Customer customers[]){

    std::ifstream inFile;
    int index = 0;
    std::string name;
    int change;

    inFile.open("../coins.txt");
    if(!inFile.is_open()){
        std::cout << "Error opening input file!" << std::endl;
    }

    while (index < NUMBEROFCUSTOMERS && inFile >> name >> change){
        customers[index].setName(name);
        customers[index].setChange(change);
        index++;
    }
    inFile.close();
}

void determineCoins(Customer customers[]){

    std::vector<int> customerCoins;

    for (int i = 0; i < NUMBEROFCUSTOMERS; i++){

        customerCoins = {0, 0, 0, 0};

        int change = customers[i].getChange();

            while(change >= 50) {
                customerCoins[0] = customerCoins[0] + 1;
                change = change - 50;
            }
            while(change >= 20) {
                customerCoins[1] = customerCoins[1] + 1;
                change = change - 20;
            }
            while(change >= 10) {
                customerCoins[2] = customerCoins[2] + 1;
                change = change - 10;
            }
            while(change >= 5) {
                customerCoins[3] = customerCoins[3] + 1;
                change = change - 5;
        }
            customers[i].setCoins(customerCoins);
    }
}

int displayMenu(){

    int option;

    menu:
    std::cout << "Please select an option:\n";
    std::cout << "1. Enter name\n";
    std::cout << "2. Exit\n";
    std::cin >> option;

    if((option != 1) && (option != 2)){
        std::cout << "Invalid option.\n";
        goto menu;
    }

    return option;
}

int findName(std::string name, Customer customers[]){

    int indexAt = -1;
    for(int i = 0; i < NUMBEROFCUSTOMERS; i++){
        if(name == customers[i].getName()){
            indexAt = i;
        }
    }
    return indexAt;
}

void displayCoins(Customer customers [], int target){

    std::cout << "Customer: " << customers[target].getName();
    printf("\n");
    printf("%d cents\n", customers[target].getChange());
    printf("\n");
    printf("Change:\n");

    if(customers[target].getCoins().at(0) != 0)
    {
        printf("50 cents: %d\n", customers[target].getCoins().at(0));
    }
    if(customers[target].getCoins().at(1) != 0)
    {
        printf("20 cents: %d\n", customers[target].getCoins().at(1));
    }
    if(customers[target].getCoins().at(2) != 0)
    {
        printf("10 cents: %d\n", customers[target].getCoins().at(2));
    }
    if(customers[target].getCoins().at(3) != 0)
    {
        printf("5 cents: %d\n", customers[target].getCoins().at(3));
    }
    printf("\n");

}

void writeData(Customer customers[]){

    int index; std::string name; int change;
    std::ofstream outFile;

    outFile.open("../change.csv");
    if(!outFile.is_open()){
        std::cout << "Error opening output file!" << std::endl;
    }

    for(int i = 0; i < NUMBEROFCUSTOMERS; i++){

        outFile << customers[i].getName() << " " << customers[i].getChange() << " " << customers[i].getCoins().at(0) << " " << customers[i].getCoins().at(1) << " " << customers[i].getCoins().at(2) << " " << customers[i].getCoins().at(3) << std::endl;
    }
    outFile.close();
}