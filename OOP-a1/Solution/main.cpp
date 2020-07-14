/* @Author
Student Name: Baris Incesu
Student ID: 150170092
Date: 07.04.2020 */

#include <iostream>
using namespace std;

struct ingredients{  //holds the ingredients of a pizza.
    int no;
    string malzeme;
    ingredients *next;
};

class pizza{    //Pizzas are created using this class for each order.
    private:
    string name;
    string size;
    string crust_type;
    ingredients *head, *temp, *tut;

    public:
    pizza *next;

    pizza(){  //standart pizza
        head = NULL;
        name = "standart Pizza";
        size = "medium";
        crust_type = "normal";
        ekle("mozarella");
    }
    pizza(string new_size, string new_crust_type, int pizza_type){ //pizzas are selected from the menu.
        head = NULL;
        size = new_size;
        crust_type = new_crust_type;
        ekle("mozarella");
        if(pizza_type == 1){
            name = "Chicken Pizza";
            ekle("chicken");
            ekle("mushroom");
            ekle("corn");
            ekle("onion");
            ekle("tomato");
        }
        else if(pizza_type == 2){
            name = "Broccoli Pizza";
            ekle("broccoli");
            ekle("pepperoni");
            ekle("olive");
            ekle("corn");
            ekle("onion");
        }
        else if(pizza_type == 3){
            name = "Sausage Pizza";
            ekle("sausage");
            ekle("tomato");
            ekle("olive");
            ekle("mushroom");
            ekle("corn");
        }
    }
    void ekle(string x){    //adds the desired ingredients to the pizza.
        if(head == NULL){
            head = new ingredients;
            head->next = NULL;
            head->no = 1;
            head->malzeme = x;
        }
        else{
            temp = head;
            int i = 2;
            while(temp->next != NULL){
                temp = temp->next;
                i++;
            }
            temp->next = new ingredients;
            temp = temp->next;
            temp->next = NULL;
            temp->malzeme = x;
            temp->no = i;
        }
    }
    void cikar(int a){      //removes the desired ingredients from the pizza.
        temp = head;
        if(head->no == a){
            tut = new ingredients;
            tut = head;
            head = head->next;
            delete tut;
        }

        else{
        while(temp->next->no != a){
            temp = temp->next;
        }
        tut = new ingredients;
        tut = temp->next;
        temp->next = temp->next->next;
        delete tut;
        }
        temp = head;
        int i = 1;
    }
    
    void showpizza(){     //prints the pizza.
        cout<<name<<" (";
        temp = head;
        while(temp!=NULL){
            cout<<temp->malzeme<<", ";
            temp = temp->next;
        }
        cout<<")"<<endl;
        cout<<"Size: "<<size<<", crust: "<<crust_type<<endl;
    }
    string getsize(){
        return size;
    }
    
    void showindregients(){       //Prints the contents of the pizza.
        temp = head;
        cout<<"Please enter the number of the indregient you want to remove from your pizza."<<endl;
        while(temp != NULL){
            cout<<temp->no<<". "<<temp->malzeme<<endl;
            temp = temp->next;
        }
        cout<<"Press 0 to save it"<<endl;
    }
    void deleteindregients(){       //contents delete the linked list in order.
        while(head != NULL){
            temp = head;
            head =head->next;
            delete temp;
        }
    }
    ~pizza(){
        deleteindregients();
    }
};

class order{
private:
    string customer;
    pizza *head, *temp;
    int drink[4];
    
public:
    order *next;
    void drinksec(){    //it takes drinks and saves them.
        drink[0] = 0;
        drink[1] = 0;
        drink[2] = 0;
        drink[3] = 0;
        cout<<"Please choose a drink:"<<endl;
        cout<<"0. No drink\n1. Cola 4 TL\n2. Soda 2 TL\n3. Ice tea 3 TL\n4. Fruit juice 3.5 TL"<<endl;
        cout<<"Press -1 to save order."<<endl;
        int a;
        do{
            cin>>a;
            if(a == 0 ||a == -1){break;}
            drink[a-1]++;
        }while(a != 0||a != -1);            
    }
    void getprice(){       //calculates the price of products for a person.
        float price = 0.0;

        temp = head;
        while(temp!=NULL){
            string x = temp->getsize();
            if(x == "small"){
                price += 15.0;
            }
            else if(x == "medium"){
                price += 20.0;
            }
            else if(x == "big"){
                price += 25.0;
            }
            temp = temp->next;
        }
        price += (drink[0]*4.0 + drink[1]*2.0 + drink[2]*3.0 + drink[3]*3.5);
            
        cout<<"Total price: "<<price<<endl;
        cout<<"Do you have a promotion code? (y/n)"<<endl;
        string y;
        cin>>y;
        if(y == "n"){
            cout<<"The order is delivered succesfully!"<<endl;;
        }
        else if(y == "y"){
            string cevap ;
            string dene = "I am a student";
            while(cevap != dene){          
                cout<<"Please enter your code: "<<endl;
                getline(cin,cevap);
            
                if(cevap == dene){
                    price -= (price/10);
                    cout<<"Discounted price: "<<price<<endl;
                    cout<<"The order is delivered Succesfully!"<<endl;
                    break;
                }
                else{
                    cout<<"Promotion code is not accepted."<<endl;
                }
            }
        }
        cout<<"\n\n"<<endl;
    }

    void printorder(){      //prints all the information for a person.
        cout<<"Name: "<<customer<<"\n"<<endl;
        temp = head;
        while(temp!=NULL){
            temp->showpizza();
            temp = temp->next;
            cout<<endl;
        }
        if(drink[0]!= 0)
        cout<<drink[0]<<" cola, ";
        if(drink[1]!= 0)
        cout<<drink[1]<<" Soda, ";
        if(drink[2]!= 0)
        cout<<drink[2]<<" Ice Tea, ";
        if(drink[3]!= 0)
        cout<<drink[3]<<" Fruit Juice, ";

        cout<<"\n--------------\n"<<endl;
    }
    void setcustomer(){    
        cout<<"Name: ";
        string x;
        cin>>x;
        customer = x;
    }
    string getcustomer(){
        return customer;
    }

    void pizzaekle(string size1, string crust_type1, int type1){   //creates a pizza.
        temp = head;
        
        if(head == NULL){
            head = new pizza(size1, crust_type1, type1);
            head->next = NULL;
        }
        else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new pizza(size1, crust_type1, type1);
            temp = temp->next;
            temp->next = NULL;
        }
    }
    
    void pizzaekle2(string size1, string crust_type1, int type1){   //It is used to produce 2 or more pizzas.
        temp = head;
        int d;
        if(head == NULL){
            head = new pizza(size1, crust_type1, type1);
            head->showindregients();
            do{
                cin>>d;
                if(d == 0){break;}
                head->cikar(d);
            }while(d != 0);
            head->next = NULL;
        }
        else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new pizza(size1, crust_type1, type1);
            temp = temp->next;
            temp->next = NULL;
            temp->showindregients();
            do{
                cin>>d;
                if(d == 0){break;}
                temp->cikar(d);
            }while(d != 0);           
        }
    }
    ~order(){
        while(head != NULL){
            temp = head;
            head =head->next;
            delete temp;
        }
    }
};

class orderlist{
    private:
    order *head = NULL, *temp = NULL, *tut = NULL;
    int n;

    public: 
    void takeorder(){   //creates a person and takes orders.
        menu();
        int sec_pizza;
        string x, y; 
            cin>>sec_pizza;
            if(sec_pizza == 0){
                
            }
            else if(sec_pizza == 1||2||3){
                cout<<"Select size: small (15 TL), medium (20 TL), big(25 TL)"<<endl;
                cin>>x;
                cout<<"Select crust type: thin, normal, thick"<<endl;
                cin>>y;
            }       
        cout<<"..."<<endl;
        if(head == NULL){
          head = new order;
            head->pizzaekle(x,y,sec_pizza);
            temp = head;
            head->next = NULL;
        }
        else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new order;
            temp->next->pizzaekle(x,y,sec_pizza);
            temp = temp->next;
            temp->next = NULL;
        }
        int amount;
        cout<<"Enter the amount: ";
        cin>>amount;
        int i = 1;
        while(i<amount){
            temp->pizzaekle2(x,y,sec_pizza);
            i++;
        }
        temp->drinksec();        
        temp->setcustomer();
        cout<<"Your order is saved, it will be delivered when it is ready...\n----------------------"<<endl;
        temp->printorder();
    }

    void menu(){
    cout<<"Pizza Menu"<<endl;
    cout<<"1. Chicken Pizza (mozarella, chicken, mushroom, corn, onion, tomato)"<<endl;
    cout<<"2. Broccoli Pizza (mozarella, broccoli, pepperoni, olive, corn, onion)"<<endl;
    cout<<"3. Sausage Pizza (mozarella, sausage, tomato, olive, mushroom, corn)"<<endl;
    cout<<"0. Back to main menu"<<endl;
    }

    void listorders(){      //lists all contacts and all orders.
        temp = head;
        int i = 1;
        while(temp != NULL){
            cout<<i<<"\n-----------------\n"<<endl;
            temp->printorder();
            temp = temp->next;
            i++;
        }

    }

    void deliverorders(){     //shows the account and removes the payee from the list.
        listorders();
        temp = head;
        cout<<"Please write the customer name in order to deliver his/her order: ";
        string c;
        cin>>c;
        while(temp!=NULL){
            if(temp->getcustomer() == c){break;}
            temp=temp->next;
        }
        temp->printorder();
        temp->getprice();
        temp = head;
        if(head->getcustomer()==c){
            if(head->next != NULL){head = head->next;}
            else{head = NULL;}            
            delete temp;
        }
        else{
        while(temp!=NULL){
            if(temp->next->getcustomer() == c){break;}
            temp=temp->next;
        }
        tut = temp->next;
        if(temp->next->next == NULL){
            temp->next = NULL;
        }
        else{
            temp->next = temp->next->next;
        }
        delete tut;       
        }
    }
    ~orderlist(){
        while(head != NULL){
            temp = head;
            head =head->next;
            delete temp;
        }
    }

};

int main(){

 int secim;
    orderlist o1;
    
    do{
    cout<<"Welcome to Unicorn Pizza!"<<endl;
    cout<<"1. Add an order\n2. List orders\n3. Deliver order\n4. Exit"<<endl;
    cout<<"Choose what to do: ";
    
    cin>>secim;
    if(secim == 1){
        o1.takeorder();
    }
    else if(secim == 2){
        o1.listorders();
    }
    else if(secim == 3){
        o1.deliverorders();
    }
    else if(secim == 4){
        cout<<"Goodbye...";
    }
    else{
        cout<<"This is not a valid choice, please try again!";
    }
    }while(secim!=4);

    o1.~orderlist();
  return 0;
}