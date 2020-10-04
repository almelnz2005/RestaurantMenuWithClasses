#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>


class Order{
private:
    std::string orderName;
    int burgerCount;
    std::string burgerToppings;
    int friesCount;
    std::string friesToppings;
    int saladCount;
    int hotdogCount;
    std::string hotdogToppings;
    int drinksCount;
    std::string drinksToppings;
    float total;
    const float burgerCost = 1.99;
    const float friesCost = 0.99;
    const float saladCost = 1.50;
    const float hotdogCost = 1.45;
    const float drinksCost = 0.80;
    float orderTotal;

    static int numOfOrders;

public:
    std::string GetOrderName(){return orderName;}
    void SetOrderName(std::string orderName){this->orderName = orderName;}
    int GetBurgerCount(){return burgerCount;}
    void SetBurgerCount(int burgerCount){this->burgerCount = this->burgerCount + burgerCount;}
    std::string GetBurgerToppings(){return burgerToppings;}
    void SetBurgerToppings(std::string burgerToppings){this->burgerToppings = burgerToppings;}
    int GetFriesCount(){return friesCount;}
    void SetFriesCount(int friesCount){this->friesCount = this->friesCount + friesCount;}
    std::string GetFriesToppings(){return friesToppings;}
    void SetFriesToppings(std::string friesToppings){this->friesToppings = friesToppings;}
    int GetSaladCount(){return saladCount;}
    void SetSaladCount(int saladCount){this->saladCount = this->saladCount + saladCount;}
    int GetHotdogCount(){return hotdogCount;}
    void SetHotdogCount(int hotdogCount){this->hotdogCount = this->hotdogCount + hotdogCount;}
    std::string GetHotdogToppings(){return hotdogToppings;}
    void SetHotdogToppings(std::string hotdogToppings){this->hotdogToppings = hotdogToppings;}
    int GetDrinksCount(){return drinksCount;}
    void SetDrinksCount(int drinksCount){this->drinksCount = this->drinksCount + drinksCount;}
    std::string GetDrinksToppings(){return drinksToppings;}
    void SetDrinksToppings(std::string drinksToppings){this->drinksToppings = drinksToppings;}

    Order();
    ~Order();
    void MenuPrint();
    void PrintOrderToScreen();
    void Toppings(char);
    void PrintOrderToFile();
    void OrderEntry();

};

int Order::numOfOrders;

Order::Order(){
    this->orderName = "";
    this->burgerCount = 0;
    this->burgerToppings = "";
    this->friesCount = 0;
    this->friesToppings = "";
    this->saladCount = 0;
    this->hotdogCount = 0;
    this->hotdogToppings = "";
    this->drinksCount = 0;
    this->drinksToppings = "";

}

Order::~Order(){
    std::cout << "The Order " << this -> orderName << " has been completed.\n";
}


void Order::PrintOrderToScreen(){
    std::system("clear");
    this->MenuPrint();
    printf("-----------Totals-------------\n");
    printf("Order Name: %s\n", this->orderName.c_str());
    if(this->burgerCount > 0 ){
        printf("Burger(s): %d Toppings: %s\n", this->burgerCount, this->burgerToppings.c_str());
    }
    if(this->friesCount > 0 ){
        printf("Fries: %d Toppings: %s\n", this->friesCount, this->friesToppings.c_str());
    }
    if(this->saladCount > 0 ){
        printf("Salad(s): %d\n", this->saladCount);
    }
    if(this->hotdogCount > 0 ){
        printf("Hotdog(s): %d Toppings: %s\n", this->hotdogCount, this->hotdogToppings.c_str());
    }
        if(this->drinksCount > 0 ){
        printf("Drink(s): %d Toppings: %s\n", this->drinksCount, this->drinksToppings.c_str());
    }

    this->orderTotal = this->burgerCount*this->burgerCost + this->friesCount*this->friesCost + this->saladCount*this->saladCost + this->hotdogCount*this->hotdogCost + this->drinksCount*this->drinksCost;

    printf("Total: %.2f\n", this->orderTotal);
    printf("------------------------------\n");
};

void Order::MenuPrint(){
    std::system("clear");
    printf("-----------------------------------------------INSTRUCTIONS--------------------------------------------\n");
    printf("To add and/or remove an item from the order enter the letter associated to the item followed by a space\n");
    printf("and then the quantity. If you want to add any toppings, select y when asked. Only one \n");
    printf("topping can be selected at this time. To remove an item include a negative sign on the left of the \n");
    printf("quantity.\n");
    printf("-------------------------------------------------------------------------------------------------------\n\n");
    printf("-------------Menu-------------\n");
    printf("Burger(b) - $1.99 (cheese, bacon, letuce, tomato)\n");
    printf("Fries(f) - $0.99 (cheese, bacon, ketchup)\n");
    printf("Salad(s) - $1.50 (No toppings available)\n");
    printf("Hotdog(h) - $1.45 (cheese, bacon, ketchup, mustard, chillibeans)\n");
    printf("Drinks(d) - $0.80 (cherry, alcohol)\n");
    printf("Completed Order(e 0)\n");
    printf("------------------------------\n");
}    

void Order::Toppings(char item){
    std::string toppings = "";
    std::string temp = "";

while(temp != "done"){
    this->MenuPrint();
    this->PrintOrderToScreen();
    printf("----------------------------------------INSTRUCTIONS FOR TOPPINGS--------------------------------------\n");
    printf("Enter toppings one at a time hit after each one. When complete enter \"done\".\n");
    printf("-------------------------------------------------------------------------------------------------------\n\n");
    printf("Enter the topping: ");
    std::cin >> temp;
    if(temp != "done"){
        toppings = toppings + " " + temp;
    }
}

    if(item == 'b'){
        this->SetBurgerToppings(toppings);
    }
    else if(item == 'f'){
        this->SetFriesToppings(toppings);
    }
    else if(item == 'h'){
        this->SetHotdogToppings(toppings);
    }
    else if(item == 'd'){
        this->SetDrinksToppings(toppings);
    }
}

void Order::PrintOrderToFile(){
    std::ofstream outfile ("/mnt/d/School/C++/RestaurantMenuWithClass/OrderReceipt.txt");
    outfile << "Order Name: " << this->GetOrderName() << std::endl;
    outfile << "----------------------------------------" << std::endl;
    outfile << "Item        Quantity" << std::endl;
    outfile << "----------------------------------------" << std::endl;
    if(this->burgerCount > 0 ){
        outfile << "Burger(s):      "<< this->burgerCount << "   Toppings:   " << this->burgerToppings.c_str() << std::endl;
    }
    if(this->friesCount > 0 ){
        outfile << "Fries:          "<< this->friesCount << "   Toppings:   " << this->friesToppings.c_str() << std::endl;
    }
    if(this->saladCount > 0 ){
    outfile << "Salad(s):       "<< this->saladCount << std::endl;
    }
    if(this->hotdogCount > 0 ){
        outfile << "Hotdog(s):      "<< this->hotdogCount << "   Toppings:   " << this->hotdogToppings.c_str() << std::endl;
    }
    if(this->drinksCount > 0 ){
        outfile << "Drink(s):       "<< this->drinksCount << "   Toppings:   " << this->drinksToppings.c_str() << std::endl; 
    }
    outfile << "----------------------------------------" << std::endl;
    outfile << "Total: " << this->orderTotal << std::endl;
}

void Order::OrderEntry(){
    char item;
    char toppingChoice;
    int quantity;

    while(item != 'e'){

        printf("Enter the Item and quantity: ");
        std::cin >> item >> quantity;

        if(item == 'b' || item == 'f' || item == 'h' || item == 'd'){
            printf("Would you like to add toppings(y or n): ");
            std::cin >> toppingChoice;
            if(toppingChoice == 'y'){
                this->Toppings(item);
            }
        }

        if(item != 'e'){
            if(item == 'b'){
                this->SetBurgerCount(quantity);
            }
            else if (item == 'f'){
                this->SetFriesCount(quantity);
            }
            else if(item == 's'){
                this->SetSaladCount(quantity);
            }
            else if(item == 'h'){
                this->SetHotdogCount(quantity);
            }
            else if(item == 'd'){
                this->SetDrinksCount(quantity);
            }
            else{
               printf("****ITEM IS NOT PART OF THE MENU.****");
            }
        }
        else{
            this->PrintOrderToFile();
        }
        this->MenuPrint();
        this->PrintOrderToScreen();
    }
}

int main(){ 
    Order today;

    std::string orderName;

    today.MenuPrint();

    printf("Enter the order name: ");
    std::cin >> orderName;
    
    today.SetOrderName(orderName);
    today.OrderEntry();

    return 0;
}