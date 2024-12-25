// Including important header files
#include<iostream>
#include<conio.h>
#include <cstdlib>
#include<string>
#include <iomanip> // for setw()
#include <random>  // for random
#include<chrono>    // for random number
#include <ctime>
#include <thread>
#include<sstream>
#include<limits>
#include <fstream>
#include <vector>


// .........for colorful text
#define RESET    "\033[0m"
#define RED      "\033[31m"
#define GREEN    "\033[32m"
#define YELLOW   "\033[33m"
#define CYAN     "\033[36m"

using namespace  std;

// defining global variables
static int k=0;
static string data_fname [3][4][300];
static int age[3][4][300];
static string address[3][4][300];
static unsigned long long number [3][4][300];
static string reference[3][4][300];
static string seat_no[3][4][300];
int seat=0;
string selectedSeat;
static string to_place[3][4][300];
static string book_time[3][4][300];


// ... for random number
int randomNum(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);

    uniform_int_distribution<> dis(11, 99);
    int random_number = dis(gen);

    return random_number;
}

int randomNum2(){
    mt19937 gen(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<> dis(11, 99);
    int randomNumber = dis(gen);

    return randomNumber;
}


// ,..... to check if number is inputed in integer?
void notInt(){
    // If input is not an integer
    cin.clear(); // Clear the error flag
    cin.ignore(1234567890, '\n'); // Discard invalid input
}

// to define that function and class are used in the middle of progaram
class menu;

int personalData(string , int);
string seatEconomy(int, int);
string seatBusiness(int, int);

int info(string, string, int , int, int, int);
int countBookedSeats(int, int);
int thanksFor(int, int, string, int, string, unsigned long long, string, string, string);

void viewTicket();
void ViewTicketDetials(int, int, int);
void updateTicket();
int updateTicketDetails(int, int, int);

int seatEconomyUpdate(int, int, int);
int seatBusinessUpdate(int, int, int);

void cancelFlight();
int cancelFlightTrue(int, int, int);



// for file handeling
const string filePath = "4semproject.txt";

// structure
struct Booking {
    string f_reference;
    string f_name;
    int f_age;
    string f_address;
    string f_number;
    string f_seatNo;
    string f_bookTime;
    string f_flightTo;
};


// class started
class menu{
    string name , flight;
    int eco, busi, num;
    public:

    // for invalid click
    void invalid(){
        // If input is not an integer
        cin.clear(); // Clear the error flag
        cin.ignore(1234567890, '\n'); // Discard invalid input
    }

    // for place option
    void tochoose(){
        cout<<"Press 1 for  _flight to Pokhara."<<endl;
        cout<<"Press 2 for  _flight to Biratnagar."<<endl;
        cout<<"Press 3 for  _flight to Nepalganj."<<endl;
        cout<<"\n";
        cout<<"Press 0 to return main menu."<<endl<<endl<<endl;
    }
// for exact place with name code and rate for flight
    void toPokhara(){
        name = "Pokhara";
        flight = "POK";
        eco = 5000;
        busi = 6520;
        num = 1785;
        info(name, flight, eco, busi, num, 0);
    }

    void toBiratnagar(){
        name = "Biratnagar";
                flight = "BRT";
                eco = 5920;
                busi = 7280;
                num= 1992;
                info(name, flight, eco, busi, num, 1);
    }
    void toNepalganj(){
        name = "Nepalganj";
                flight = "NPG";
                eco = 5500;
                busi = 6250;
                num= 1412;
                info(name, flight, eco, busi, num, 2);
    }


    // for internal choose:
    int internalchoose(string place){
        int chooseInternalOption;
        while(true){
            if(!(cin >> chooseInternalOption)){
                invalid();
                continue;
            }
            else{
                switch(chooseInternalOption){
                    case 1:
                    personalData(place, chooseInternalOption);
                    break;
                    case 2:
                    personalData(place, chooseInternalOption);
                    break;
                    case 3:
                    personalData(place, chooseInternalOption);
                    break;
                    case 4:
                    personalData(place, chooseInternalOption);
                    break;
                    default:
                    break;

                }
                return 0;
            }
        }
        return 0;
    }


    // to open the main menu
    int run(){
        
        int in_choice;

        while (true) {

            system("cls");
            
            cout<<CYAN<<"\n*******************************************************"<<RESET<<endl;
            cout<<CYAN<<"\n_________ "<<RED<<"       SkyHigh Reservations        " << CYAN <<" _________" << RESET <<endl<<endl;
            cout<<CYAN<<"*\t   "<< GREEN <<" Welcome to SkyHigh Reservations    \t "<< CYAN <<"     *" << RESET <<endl<<endl;
            // cout<<"......................................................." << endl;
            cout<<"\t \t \t \t      \e[2m Kathmandu, Nepal \e[0m"<<endl;
            cout<<YELLOW<<"......................................................." << RESET<<endl <<endl<<endl;
            
            cout << "Enter your choice" << endl<<endl;
            cout << "Press 1 for Flight Information." << endl;
            cout << "Press 2 for Book Flight." << endl;
            cout << "Press 3 for view and update ticket information." << endl;
            cout << "Press 0 to exit the program." << endl << endl;


            if (!(cin >> in_choice)) {
                invalid();
                continue; // Prompt the user again
            }
            
            switch (in_choice) {
                case 1:
                    system("cls");
                    information();          
                    break;
                
                case 2:
                    system("cls");
                    bookFlight();
                    break;

                case 3:
                    system("cls");
                    viewAndUpdate();
                    break;

                case 0:
                
                    return 0; // Exit the program

                default:
                    system("cls");
                    cout << "Invalid input \n\n" << endl;
                    cout<<"Press any key to continue.....";
                    getch();
                    system("cls");
                    break;
            }
        }
    }

    
// to show the information of flight
    int information(){
        while (true){
            system("cls");
            cout<<"    Information of Flight \n\n";
             tochoose();

            int c1_in;
            if (!(cin >> c1_in)) {
                invalid();
                continue; // Prompt the user again
            }
            switch (c1_in){
                case 1 :
                toPokhara();
                break;

                case 2 :
                toBiratnagar();
                break;

                case 3 :
                toNepalganj();
                break;

                case 0 :
                    return 0;
                    break;

                default:
                    system("cls");
                    cout<<"Invalid input. press any key to continue . \n"<<endl;
                    getch();                    
                    break;
            }
            cout<<"press any key to the main menu."<<endl<<endl;
                getch();
                return 0;
        }
        
         
    }

    // to book the flight
    int bookFlight(){
        int chooseBookOpt;
        while(true){
            system("cls");
            cout<<" \t Book Ticket online " << endl << endl;
            cout<< "Choose any options : "<< endl;
            tochoose();
            if(!(cin>> chooseBookOpt)){
                invalid();
                continue; // Prompt the user again
            }
            switch(chooseBookOpt){
                case 1:
                    cout<<"Book flight for pokhara \n"<<endl;
                    toPokhara();
                    cout<<"Choose Option:  ";
                    internalchoose("Pokhara");
                    return 0;

                case 2:
                    cout<<"Book flight for Biratnagar \n"<<endl;
                    toBiratnagar();
                    cout<<"Choose Option:  ";
                    internalchoose("Biratnagar");
                    return 0;

                case 3:
                    cout<<"Book flight for Nepalganj \n"<<endl;
                    toNepalganj();
                    cout<<"Choose Option:  ";
                    internalchoose("Nepalganj");
                    return 0;

                case 0:
                    run();
                    return 0;
            
                default:
                    system("cls");
                    cout<<"Invalid Input \n"<<endl;
                    getch();
                    break;
            }
        }
    }

    int viewAndUpdate(){
        int choose_optv;
        while (true){
            system("cls");
            cout<<CYAN<<"\n_________ "<<RED<<"       SkyHigh Reservations        " << CYAN <<" _________" << RESET <<endl<<endl;
            cout<<YELLOW<<"......................................................." << RESET<<endl <<endl<<endl;
            cout<<"Choose Option: " << endl << endl;
            cout <<"1.  View Ticket."<< endl;
            cout <<"2.  Update Ticket. "<<endl;
            cout <<"3.  Cancel Flight."<<endl;
            cout <<"0.  Go to main menu."<<endl<<endl;

            if(!(cin>> choose_optv)){
                invalid();
                continue; // Prompt the user again
            }
            switch(choose_optv){
                case 1:
                    viewTicket();
                    return 0;
                case 2:
                    updateTicket();
                    return 0;
                case 3:
                    cancelFlight();
                    return 0;
                case 0:
                    return 0;

                default:
                    system("cls");
                    cout<<"Invalid Input \n"<<endl;
                    getch();
                    break;
            }

        }
        

    }

};


bool isTenDigitNumber(long long num) {
        stringstream ss;
        ss << num;
        string strNum = ss.str();
        return strNum.length() == 10;
        }

// to show the main information regarding to flight
int info(string to, string flight, int eco, int busin, int num, int ky){
    system("cls");
    int totalSeats=15;
    cout<<"  Following are flights for "<<to<< ".\n\n";

    cout<<" 1.\tSKYHI"<<num++<<" "<<flight<<"145"<<endl;
    cout<<"\t time: 8am \t | \t Rs. "<<eco<<" for Economy \t | \t Rs. "<<busin<<" for Business "<<endl;
    cout<<"\t Total Seat : 15 \t Remaining seat : "<< totalSeats - countBookedSeats(ky, 1)<<"\n "<<endl;

    cout<<" 2.\tSKYHI"<<num++<<" "<<flight<<"146"<<endl;
    cout<<"\t time: 11am \t | \t Rs. "<<eco<<" for Economy \t | \t Rs. "<<busin<<"  for Business "<<endl;
    cout<<"\t Total Seat : 15 \t Remaining seat : "<< totalSeats - countBookedSeats(ky, 2)<<"\n "<<endl;

    cout<<" 3.\tSKYHI"<<num++<<" "<<flight<<"147"<<endl;
    cout<<"\t time: 2pm \t | \t Rs."<<eco<<" for Economy \t | \t Rs. "<<busin<<"  for Business "<<endl;
    cout<<"\t Total Seat : 15 \t Remaining seat : "<< totalSeats - countBookedSeats(ky, 3)<<"\n "<<endl;

    cout<<" 4.\tSKYHI"<<num<<" "<<flight<<"148"<<endl;
    cout<<"\t time: 4pm \t | \t Rs. "<<eco<<" for Economy \t | \t Rs. "<<busin<<"  for Business "<<endl;
    cout<<"\t Total Seat : 15 \t Remaining seat : "<< totalSeats - countBookedSeats(ky, 4)<<"\n "<<endl;
   
}
// to show booked seat
int countBookedSeats(int dIn, int flight) {
    int bookedSeats = 0;
    for (int i = 0; i < k; i++) {
        if ((seat_no[dIn][flight][i]) != "") {
            bookedSeats++;
        }
    }
    return bookedSeats;
}

// personal data.
int personalData(string name, int option){
    int i;
    system("cls");
    cout<<RED<<"Enter Your Detials \n"<<RESET<<endl;
    if(name == "Pokhara"){
        i=0;
    }
    else if (name == "Biratnagar"){
        i=1;
    }
    else{
        i=2;
    }

    // cout<<"Enter your name \t:   ";
    // cin.ignore();
    // getline(cin, data_fname[i][option][k]);
    cin.ignore();
    while (true){
        string fname;
        cout<<"Enter your name \t:   ";
        // cin.ignore();
        getline(cin, fname);
        if (fname.length()>= 4){
            data_fname[i][option][k] = fname;
            break;
        }
        else{
            cout<<"Invalid name."<<endl;
        }
    }

    while(true){
        cout<<"Enter your age \t\t:   ";
        int age_input;
        if(!(cin >> age_input)){
                notInt();
                cout<< "Invalid Input."<<endl;
                continue;
            }
        else if(age_input<1){
            cout<< "Age can not be less than 1."<<endl;
        }
        else if(age_input > 100){
            cout<< "Age can not be greater than 100."<<endl;
        }
        
        else{
            age[i][option][k] = age_input;
            break;
        }
    }


    cout <<"Enter your address\t:   ";
    cin.ignore();
    getline(cin,address[i][option][k]);
    
    while(true){
        cout<<"Enter your number\t:   ";
        long long int inpnumber;


        if(!(cin >> inpnumber)){
                notInt();
                continue;
            }
        else if(!isTenDigitNumber(inpnumber)){
                cout << "Invalid phone number. Please enter a 10-digit phone number." << endl;
                continue;
            }
        else{
            number[i][option][k] = inpnumber;
            break;
        }
    }



    int rndm = randomNum();
    int rndm2= randomNum2();

    reference[i][option][k]= "SKYHIG"+to_string(age[i][option][k])+to_string(i)+"KE"+to_string(rndm)+"X"+to_string(rndm2);
    // cout<<reference[i][option][k];

    while(true){
        int seat_types;
        cout<<"\nchoose seat types: \n 1. Economy \t 2.Business \n ";
        // cout<<reference[i][option][k];
        
        if(!(cin >> seat_types)){
            cin.clear(); // Clear the error flag
            cin.ignore(12, '\n');
            continue;
        }
        switch (seat_types){
            case 1:
                selectedSeat = seatEconomy(i, option);              
                thanksFor(i,option, data_fname[i][option][k], age[i][option][k], address[i][option][k], number[i][option][k], selectedSeat, reference[i][option][k], name);
                return 0;
            case 2:
                selectedSeat = seatBusiness(i, option);
                thanksFor(i, option, data_fname[i][option][k], age[i][option][k], address[i][option][k], number[i][option][k], selectedSeat, reference[i][option][k], name);
                break;
            default:
                cout<<"\nInvalid input.\n";
                continue;
        }
        return 0;
    }
    
}

// to book economy seat
string seatEconomy(int i, int o){
    cout<<"\n\nSelect seat number : "<<endl;
    for(int a=1; a<=5; a++){
        cout<<a<<". \t A-"<<a<<"\t";
        for(int c=0; c<k; c++){
            string string_Find = "A-"+ to_string(a);
            if(seat_no[i][o][c].find(string_Find) != string::npos)
                cout<<"*";
        }
        cout<<"\t | \t"<<a+5<<".  \t C-"<<a<<"\t";
        for(int c=0; c<k; c++){
            string string_Find = "C-"+ to_string(a);
            if(seat_no[i][o][c].find(string_Find) != string::npos)
                cout<<"*";
        }
        cout<<" "<<endl;
    }

    

    cout<<"\nNote : * are booked seat"<<endl;

    cout<<"\n"<<endl;
    int num;
    while(true){
        cin >> num;
        string seat_choose;

        if(num<6){
            seat_choose = "A-"+to_string (num);
            seat_no[i][o][k] = seat_choose;

            return seat_choose; 
        }
        else if(num<11){
            num = num-5;
            seat_choose = "C-"+ to_string (num);
            seat_no[i][o][k] = seat_choose;
            return seat_choose;
        }
        else{
            cout<<"Invalid Input enter again. :  ";
            continue;
        }
    } 

}

// to book business seat
string seatBusiness(int i, int o){
    cout<<"\n\nSelect seat number : "<<endl;
    for(int a=1; a<=5; a++){
        cout<<a<<". \t B-"<<a<<"\t";
        for(int c=0; c<=k; c++){
            string string_Find = "B-"+ to_string(a);
            if(seat_no[i][o][c].find(string_Find) != string::npos)
                cout<<"*";
        }
        cout<<""<<endl;
    }

  

    cout<<"\nNote : * are booked seat"<<endl;
    
    cout<<"\n"<<endl;
    int num;
    while (true)
    {
        cin >> num;
        string seat_choose;
        if(num<6){
            seat_choose = "B-"+to_string (num);
            seat_no[i][o][k] = seat_choose;
            return seat_choose;
        }
        else{
            cout<<"Invalid Input enter again. :  ";
            continue;
        }

    }
    
    
}

// thanks for booking
int thanksFor(int i, int o, string name_i, int age_i, string address_i, unsigned long long number_i, string seatchoose_i, string refe_i, string flightto){
    system("cls");

    string s;
    s=seatchoose_i;
    for(int w=0; w<k; w++){
        if(seat_no[i][o][w]== s){
            cout<<"Seat already taken ";
            getch();
            return 0;
        }
    }
    string flight_Time;
    if (o==1){
        flight_Time = "8 AM  ";
    }
    else if (o==2){
        flight_Time = "11 AM ";
    }
    else if (o==3){
        flight_Time = "2 PM  ";
    }
    else if (o==4){
        flight_Time = "4 PM  ";
    }

    to_place[i][o][k] = flightto;
    book_time[i][o][k] = flight_Time;


    
    
    cout<<CYAN<<"\n_________ "<<RED<<"       SkyHigh Reservations        " << CYAN <<" _________" << RESET <<endl<<endl;
    cout<<YELLOW<<"......................................................." << RESET<<endl <<endl<<endl;

    cout<<"._____________________________________________________."<<endl;
    cout<<"|            Thanks for booking ticket.               | "<<endl;
    cout<<"|-----------------------------------------------------|"<<endl;
    cout<<"|                                                     |"<<endl;

    cout<<"|   Ref no.   \t:  "<<refe_i <<"\t\t      |"<<endl;
    cout<<"|   Name   \t:  "<<name_i <<"\t\t";
    if(name_i.length() < 13){
        cout<<"\t";
    }
    cout<<"      |"<<endl;
    cout<<"|   Age   \t:  "<<age_i <<"\t\t\t\t      |"<<endl;
    cout<<"|   Address   \t:  "<<address_i <<"\t\t\t      |"<<endl;
    cout<<"|   Phone no.  \t:  "<<number_i <<"\t\t\t      |"<<endl;
    cout<<"|   Seat No.   \t:  "<<seatchoose_i <<"\t\t\t\t      |"<<endl;
    cout<<"|   Time  \t:  "<<flight_Time <<"\t\t\t      |"<<endl;
    cout<<"|   Flight To\t:  "<<flightto <<"\t\t\t      |"<<endl;
    cout<<"|_____________________________________________________|"<<endl;


    // file handeling
    ofstream outFile(filePath, ios::app); // open in append mode
    // open file 
    if (outFile.is_open()){
        // save file
        outFile << "Reference : " << reference[i][o][k] << "\t |\t Name : " << data_fname[i][o][k] << "\t |\t Age : " << age[i][o][k] << "\t |\t Address : " <<   address[i][o][k] << "\t |\t Number : " << number[i][o][k] << "\t |\t Seat No. : " << seat_no[i][o][k] << "\t |\t Book Time :" << book_time[i][o][k] << "\t |\t Flight to : " << to_place[i][o][k] <<"\n";
        outFile.close();  // close filee
    }
    // if not opened?
    else{
        cerr << "Unable to open file for writing.";
    }


    // remaining code
    cout<<" "<<endl;
    getch();
    k++;
    cout<<"\nYou are about to exit this menu. \nPlesae save reference number for future.\n"<<endl;
    getch();
    return 0;

}

// to confirm detail to view ticket info
void viewTicket(){
    system("cls");

    string inp_reference;
    string inp_name;

    cout<<CYAN<<"\n_________ "<<RED<<"       SkyHigh Reservations        " << CYAN <<" _________" << RESET <<endl<<endl;
    cout<<YELLOW<<"......................................................." << RESET<<endl <<endl<<endl;
    
    cout<<"\t\t View Ticket Information"<<endl<<endl;

    cout<<"Enter Your reference number \t:  ";
    cin>> inp_reference;

    cout<<"Enter Your name \t\t:  ";
    cin.ignore();
    getline(cin, inp_name);

    int new_i=0, new_o=0, new_k=0;
    for(int i=0; i<= 4; i++){
        for(int j=0; j<= 4; j++){
            for(int x= 0; x<=300; x++){
                if(inp_reference == reference[i][j][x]){
                    new_i = i;
                    new_o = j;
                    new_k = x;
                }
            }
        }
    }

    
    if (data_fname[new_i][new_o][new_k] == inp_name && k>0){
        ViewTicketDetials(new_i, new_o, new_k);

        cout<<"\n Press any key to exit this menu"<<endl;
    }
    else{
        cout<<"Reference and Name didn't matched.";     
    }

    getch();

}

// to view ticket information
void ViewTicketDetials(int i, int o, int k){
    system("cls");

    cout<<CYAN<<"\n_________ "<<RED<<"       SkyHigh Reservations        " << CYAN <<" _________" << RESET <<endl<<endl;
    cout<<YELLOW<<"......................................................." << RESET<<endl <<endl<<endl;


    cout<<RED<< "\t    Your Flight Details" << RESET <<endl<<endl;

    cout<<"Ref no.   \t:  "<< reference[i][o][k] <<endl;
    cout<<"Name   \t\t:  "<< data_fname[i][o][k] <<endl;
    cout<<"Age   \t\t:  "<< age[i][o][k] <<endl;
    cout<<"Address   \t:  "<< address[i][o][k] <<endl;
    cout<<"Phone no.  \t:  "<< number[i][o][k] <<endl;
    cout<<"Seat No.   \t:  "<< seat_no[i][o][k] <<endl;
    cout<<"Time  \t\t:  "<< book_time[i][o][k] <<endl;
    cout<<"Flight To   \t:  "<< to_place[i][o][k] <<endl;
    // cout<<i<<endl;
    // cout<<o<<endl;
    // cout<<k<<endl;

    getch();

}

// to update economy seat
int seatEconomyUpdate(int i, int o, int w){
    cout<<"\n\nSelect seat number : "<<endl;
    for(int a=1; a<=5; a++){
        cout<<a<<". \t A-"<<a<<"\t";
        for(int c=0; c<k; c++){
            string string_Find = "A-"+ to_string(a);
            if(seat_no[i][o][c].find(string_Find) != string::npos)
                cout<<"*";
        }
        cout<<"\t | \t"<<a+5<<".  \t C-"<<a<<"\t";
        for(int c=0; c<k; c++){
            string string_Find = "C-"+ to_string(a);
            if(seat_no[i][o][c].find(string_Find) != string::npos)
                cout<<"*";
        }
        cout<<" "<<endl;
    }

    

    cout<<"\nNote : * are booked seat"<<endl;

    cout<<"\n"<<endl;
    int num;
    while(true){
        cin >> num;
        string seat_choose;

        if(num<6){
            seat_choose = "A-"+to_string (num);
            for(int m=0; m<k; m++){
                if(seat_no[i][o][m]== seat_choose){
                    system("cls");
                    cout<<"Seat already taken ";
                    getch();
                    return 0;
                }
                else{
                    seat_no[i][o][w] = seat_choose;
                    system("cls");
                    cout<<"update sucessfully"<<endl;
                    getch();
                    return 0;
                }
            }   
        }

        else if(num<11){
            num = num-5;
            seat_choose = "C-"+ to_string (num);
            for(int m=0; m<k; m++){
                if(seat_no[i][o][m]== seat_choose){
                    system("cls");
                    cout<<"Seat already taken ";
                    getch();
                    return 0;
                }
                else{
                    seat_no[i][o][w] = seat_choose;
                    system("cls");
                    cout<<"update sucessfully"<<endl;
                    getch();
                    return 0;
                }
            }
        }

        else{
            cout<<"Invalid Input enter again. :  ";
            continue;
        }
    } 

}

// to update business seat
int seatBusinessUpdate(int i, int no, int w){
    cout<<"\n\nSelect seat number : "<<endl;
    for(int a=1; a<=5; a++){
        cout<<a<<". \t B-"<<a<<"\t";
        for(int c=0; c<=k; c++){
            string string_Find = "B-"+ to_string(a);
            if(seat_no[i][no][c].find(string_Find) != string::npos)
                cout<<"*";
        }
        cout<<""<<endl;
    }

  

    cout<<"\nNote : * are booked seat"<<endl;
    
    cout<<"\n"<<endl;
    int num;
    while (true)
    {
        cin >> num;
        string seat_choose;
        if(num<6){
            seat_choose = "B-"+to_string (num);
            for(int m=0; m<k; m++){
                if(seat_no[i][no][m]== seat_choose){
                    system("cls");
                    cout<<"Seat already taken ";
                    getch();
                    return 0;
                }
                else{
                    seat_no[i][no][w] = seat_choose;
                    system("cls");
                    cout<<"update sucessfully"<<endl;
                    getch();
                    return 0;
                }
            }
        }
        else{
            cout<<"Invalid Input enter again. :  ";
            continue;
        }

    }
    
    
}

// to update ticket
void updateTicket(){
    system("cls");

    string inp_reference;
    string inp_name;

    cout<<CYAN<<"\n_________ "<<RED<<"       SkyHigh Reservations        " << CYAN <<" _________" << RESET <<endl<<endl;
    cout<<YELLOW<<"......................................................." << RESET<<endl <<endl<<endl;
    
    cout<<"\t\t Update Ticket Information"<<endl<<endl;

    cout<<"Enter Your reference number \t:  ";
    cin>> inp_reference;

    cout<<"Enter Your name \t\t:  ";
    cin.ignore();
    getline(cin, inp_name);

    int new_i=0, new_o=0, new_k=0;
    for(int i=0; i<= 4; i++){
        for(int j=0; j<= 4; j++){
            for(int x= 0; x<=300; x++){
                if(inp_reference == reference[i][j][x]){
                    new_i = i;
                    new_o = j;
                    new_k = x;
                }
            }
        }
    }

    
    if (data_fname[new_i][new_o][new_k] == inp_name && k>0){
         updateTicketDetails(new_i, new_o, new_k);

        cout<<"\n Press any key to exit this menu"<<endl;
    }
    else{
        cout<<"Reference and Name didn't matched.";     
    }

    getch();   

}

int o_choose(int i, int o, int x){
        system("cls");
        cout<<" Choose any option : "<<endl<<endl;
        cout<<"1.  For Economy Seat."<<endl;
        cout<<"2.  For Business Seat."<<endl;
        int st;
        while(true){
            if(!(cin >> st)){
                notInt();
                continue;
            }
            else if (st>2 || st<1){
                cout<<"Invalid Input. "<<endl;
                continue;
            }
            switch(st){
                case 1:
                    seatEconomyUpdate(i, o, x);
                    return 0; 
                case 2:
                    seatBusinessUpdate(i, o, x);
                    return 0;
                default:
                    cout<<"Invalid Input try again"<<endl;
                    continue;      
            }
        }
}

int updateTicketDetails(int i, int o, int kk){
    system("cls");
    cout<<"Choose an option : "<<endl<<endl;

    cout<<"1.  To change Flight Time."<<endl;
    cout<<"2.  To change Seat Number."<<endl;
    cout<<"0.  To go to main menu."<<endl;

    int nn, new_o;
    ifstream inFile(filePath);
    vector<string> lines;
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            lines.push_back(line); // Store each line in a vector
        }
        inFile.close();
        } 
    else {
        cerr << "Unable to open file for reading.\n";
    }

    string age_s, num_s;

    menu m;
    while(true){
        if(!(cin >> nn)){
            notInt();
            continue;
        }
        switch(nn){
            
            case 1:
                if (i==0){
                    m.toPokhara();
                    cout<<" choose an option :  ";
                    while(true){
                        if(!(cin >> new_o)){
                            notInt();
                            continue;
                        }

                        else if(new_o >4 || new_o < 1){
                            cout<<"Invalid input"<<endl;
                            continue;
                        }

                        else{
                            o_choose(i, new_o, kk);
                            string flight_Time;
                            string string_age;
                            string string_num;
                             
                            if(o != new_o){
                                if (new_o==1){
                                    flight_Time = "8 AM  ";
                                }
                                else if (new_o==2){
                                    flight_Time = "11 AM ";
                                }
                                else if (new_o==3){
                                    flight_Time = "2 PM  ";
                                }
                                else if (new_o==4){
                                    flight_Time = "4 PM  ";
                                }

                                seat_no[i][o][kk] = "";
                                reference[i][new_o][kk] = reference[i][o][kk];
                                reference[i][o][kk] = "";
                                data_fname[i][new_o][kk] = data_fname[i][o][kk];
                                age[i][new_o][kk] = age[i][o][kk];
                                string_age = to_string(age[i][o][kk]);
                                age[i][o][kk] = NULL;
                                address[i][new_o][kk] = address[i][o][kk];
                                address[i][o][kk] = "";
                                number[i][new_o][kk] = number[i][o][kk];
                                string_num = to_string(number[i][o][kk]);
                                number[i][o][kk] = NULL;
                                book_time[i][new_o][kk] = flight_Time;
                                book_time[i][o][kk] = "";
                                to_place[i][new_o][kk] = to_place[i][o][kk];
                                to_place[i][o][kk] = "";

                                // to update file
                                lines[kk] = "Reference : " + reference[i][new_o][kk] + "\t |\t Name : " + data_fname[i][new_o][kk] + "\t |\t Age : " + string_age + "\t |\t Address : " +   address[i][new_o][kk] + "\t |\t Number : " + string_num + "\t |\t Seat No. : " + seat_no[i][new_o][kk] + "\t |\t Book Time :" + book_time[i][new_o][kk] + "\t |\t Flight to : " + to_place[i][new_o][kk] ;
                                
                                // to update files
                                ofstream outFile(filePath); // Open the file for writing
                                if (outFile.is_open()){
                                    for (const auto &l : lines){
                                        outFile << l << "\n"; // Write each line back to the file
                                    }
                                    outFile.close();
                                }
                                else{
                                    cerr << "Unable to open file for writing.\n";
                                }
                            }
                            else{
                                string string_age;
                                string string_num;
                                string_age = to_string (age[i][o][kk]) ;
                                string_num = to_string(number[i][o][kk]);

                                // to update file
                                lines[kk] = "Reference : " + reference[i][o][kk] + "\t |\t Name : " + data_fname[i][o][kk] + "\t |\t Age : " + string_age + "\t |\t Address : " +   address[i][o][kk] + "\t |\t Number : " + string_num + "\t |\t Seat No. : " + seat_no[i][o][kk] + "\t |\t Book Time :" + book_time[i][o][kk] + "\t |\t Flight to : " + to_place[i][o][kk] ;
                                
                                // to update files
                                ofstream outFile(filePath); // Open the file for writing
                                if (outFile.is_open()){
                                    for (const auto &l : lines){
                                        outFile << l << "\n"; // Write each line back to the file
                                    }
                                    outFile.close();
                                }
                                else{
                                    cerr << "Unable to open file for writing.\n";
                                }
                            }                            

                            return 0;
                            break;
                        }
                    }
                    break;
                }
                else if(i==1){
                    m.toBiratnagar();
                    cout<<" choose an option :  ";
                    while(true){
                        if(!(cin >> new_o)){
                            notInt();
                            continue;
                        }

                        else if(new_o >4 || new_o < 1){
                            cout<<"Invalid input"<<endl;
                            continue;
                        }

                        else{
                            o_choose(i, new_o, kk);
                            string flight_Time;
                            string string_age;
                            string string_num;
                             
                            if(o != new_o){
                                if (new_o==1){
                                    flight_Time = "8 AM  ";
                                }
                                else if (new_o==2){
                                    flight_Time = "11 AM ";
                                }
                                else if (new_o==3){
                                    flight_Time = "2 PM  ";
                                }
                                else if (new_o==4){
                                    flight_Time = "4 PM  ";
                                }

                                seat_no[i][o][kk] = "";
                                reference[i][new_o][kk] = reference[i][o][kk];
                                reference[i][o][kk] = "";
                                data_fname[i][new_o][kk] = data_fname[i][o][kk];
                                age[i][new_o][kk] = age[i][o][kk];
                                string_age = to_string(age[i][o][kk]);
                                age[i][o][kk] = NULL;
                                address[i][new_o][kk] = address[i][o][kk];
                                address[i][o][kk] = "";
                                number[i][new_o][kk] = number[i][o][kk];
                                string_num = to_string(number[i][o][kk]);
                                number[i][o][kk] = NULL;
                                book_time[i][new_o][kk] = flight_Time;
                                book_time[i][o][kk] = "";
                                to_place[i][new_o][kk] = to_place[i][o][kk];
                                to_place[i][o][kk] = "";

                                // to update file
                                lines[kk] = "Reference : " + reference[i][new_o][kk] + "\t |\t Name : " + data_fname[i][new_o][kk] + "\t |\t Age : " + string_age + "\t |\t Address : " +   address[i][new_o][kk] + "\t |\t Number : " + string_num + "\t |\t Seat No. : " + seat_no[i][new_o][kk] + "\t |\t Book Time :" + book_time[i][new_o][kk] + "\t |\t Flight to : " + to_place[i][new_o][kk] ;
                                
                                // to update files
                                ofstream outFile(filePath); // Open the file for writing
                                if (outFile.is_open()){
                                    for (const auto &l : lines){
                                        outFile << l << "\n"; // Write each line back to the file
                                    }
                                    outFile.close();
                                }
                                else{
                                    cerr << "Unable to open file for writing.\n";
                                }

                            }
                            else{
                                string string_age;
                                string string_num;
                                string_age = to_string (age[i][o][kk]) ;
                                string_num = to_string(number[i][o][kk]);

                                // to update file
                                lines[kk] = "Reference : " + reference[i][o][kk] + "\t |\t Name : " + data_fname[i][o][kk] + "\t |\t Age : " + string_age + "\t |\t Address : " +   address[i][o][kk] + "\t |\t Number : " + string_num + "\t |\t Seat No. : " + seat_no[i][o][kk] + "\t |\t Book Time :" + book_time[i][o][kk] + "\t |\t Flight to : " + to_place[i][o][kk] ;
                                
                                // to update files
                                ofstream outFile(filePath); // Open the file for writing
                                if (outFile.is_open()){
                                    for (const auto &l : lines){
                                        outFile << l << "\n"; // Write each line back to the file
                                    }
                                    outFile.close();
                                }
                                else{
                                    cerr << "Unable to open file for writing.\n";
                                }
                            }
                            return 0;
                            break;
                        }
                    }
                    break;

                }
                else if(i==2){
                    m.toNepalganj();
                    cout<<" choose an option :  ";
                    while(true){
                        if(!(cin >> new_o)){
                            notInt();
                            continue;
                        }

                        else if(new_o >4 || new_o < 1){
                            cout<<"Invalid input"<<endl;
                            continue;
                        }

                        else{
                            o_choose(i, new_o, kk);
                            string flight_Time;
                            string string_age;
                            string string_num;
                             
                            if(o != new_o){
                                if (new_o==1){
                                    flight_Time = "8 AM  ";
                                }
                                else if (new_o==2){
                                    flight_Time = "11 AM ";
                                }
                                else if (new_o==3){
                                    flight_Time = "2 PM  ";
                                }
                                else if (new_o==4){
                                    flight_Time = "4 PM  ";
                                }

                                seat_no[i][o][kk] = "";
                                reference[i][new_o][kk] = reference[i][o][kk];
                                reference[i][o][kk] = "";
                                data_fname[i][new_o][kk] = data_fname[i][o][kk];
                                age[i][new_o][kk] = age[i][o][kk];
                                string_age = to_string(age[i][o][kk]);
                                age[i][o][kk] = NULL;
                                address[i][new_o][kk] = address[i][o][kk];
                                address[i][o][kk] = "";
                                number[i][new_o][kk] = number[i][o][kk];
                                string_num = to_string(number[i][o][kk]);
                                number[i][o][kk] = NULL;
                                book_time[i][new_o][kk] = flight_Time;
                                book_time[i][o][kk] = "";
                                to_place[i][new_o][kk] = to_place[i][o][kk];
                                to_place[i][o][kk] = "";

                                // to update file
                                lines[kk] = "Reference : " + reference[i][new_o][kk] + "\t |\t Name : " + data_fname[i][new_o][kk] + "\t |\t Age : " + string_age + "\t |\t Address : " +   address[i][new_o][kk] + "\t |\t Number : " + string_num + "\t |\t Seat No. : " + seat_no[i][new_o][kk] + "\t |\t Book Time :" + book_time[i][new_o][kk] + "\t |\t Flight to : " + to_place[i][new_o][kk] ;
                                
                                // to update files
                                ofstream outFile(filePath); // Open the file for writing
                                if (outFile.is_open()){
                                    for (const auto &l : lines){
                                        outFile << l << "\n"; // Write each line back to the file
                                    }
                                    outFile.close();
                                }
                                else{
                                    cerr << "Unable to open file for writing.\n";
                                }

                            }
                            else{
                                string string_age;
                                string string_num;
                                string_age = to_string (age[i][o][kk]) ;
                                string_num = to_string(number[i][o][kk]);

                                // to update file
                                lines[kk] = "Reference : " + reference[i][o][kk] + "\t |\t Name : " + data_fname[i][o][kk] + "\t |\t Age : " + string_age + "\t |\t Address : " +   address[i][o][kk] + "\t |\t Number : " + string_num + "\t |\t Seat No. : " + seat_no[i][o][kk] + "\t |\t Book Time :" + book_time[i][o][kk] + "\t |\t Flight to : " + to_place[i][o][kk] ;
                                
                                // to update files
                                ofstream outFile(filePath); // Open the file for writing
                                if (outFile.is_open()){
                                    for (const auto &l : lines){
                                        outFile << l << "\n"; // Write each line back to the file
                                    }
                                    outFile.close();
                                }
                                else{
                                    cerr << "Unable to open file for writing.\n";
                                }
                            }
                            return 0;
                            break;
                        }
                    }
                    break;

                }

            case 2:
                o_choose(i, o, kk);               
                if(kk>=0){
                    age_s = to_string(age[i][o][kk]);
                    num_s = to_string (number[i][o][kk]);

                    lines[kk] = "Reference : " + reference[i][o][kk] + "\t |\t Name : " + data_fname[i][o][kk] + "\t |\t Age : " + age_s + "\t |\t Address : " +   address[i][o][kk] + "\t |\t Number : " + num_s + "\t |\t Seat No. : " + seat_no[i][o][kk] + "\t |\t Book Time :" + book_time[i][o][kk] + "\t |\t Flight to : " + to_place[i][o][kk] ;
                                
                    // to update files
                    ofstream outFile(filePath); // Open the file for writing
                    if (outFile.is_open()){
                        for (const auto &l : lines){
                            outFile << l << "\n"; // Write each line back to the file
                        }
                        outFile.close();
                    }
                    else{
                        cerr << "Unable to open file for writing.\n";
                    }
                
                }
                return 0;

            case 0:
                return 0;

            default :
                cout<<"Invalid input. "<<endl;
                continue;

        }

        break;

        
    }

    
}

// Cancel Flight verify
void cancelFlight(){
    system("cls");

    string inp_reference;
    string inp_name;

    cout<<CYAN<<"\n_________ "<<RED<<"       SkyHigh Reservations        " << CYAN <<" _________" << RESET <<endl<<endl;
    cout<<YELLOW<<"......................................................." << RESET<<endl <<endl<<endl;
    
    cout<<"\t\t Cancel Your Flight."<<endl<<endl;

    cout<<"Enter Your reference number \t:  ";
    cin>> inp_reference;

    cout<<"Enter Your name \t\t:  ";
    cin.ignore();
    getline(cin, inp_name);

    int new_i=0, new_o=0, new_k=0;
    for(int i=0; i<= 4; i++){
        for(int j=0; j<= 4; j++){
            for(int x= 0; x<=300; x++){
                if(inp_reference == reference[i][j][x]){
                    new_i = i;
                    new_o = j;
                    new_k = x;
                }
            }
        }
    }

    
    if (data_fname[new_i][new_o][new_k] == inp_name && k>0){
         cancelFlightTrue(new_i, new_o, new_k);

    }
    else{
        cout<<"Reference and Name didn't matched.";     
    }

    // getch();   
}

int cancelFlightTrue(int i, int o, int q){
    system("cls");

    cout<<CYAN<<"\n____________ "<<RED<<"     \t\t  SkyHigh Reservations \t\t       " << CYAN <<" ____________" << RESET <<endl<<endl;
    cout<<YELLOW<<"...................................................................................." << RESET<<endl <<endl<<endl;

    cout<<"Your flight details :"<<endl<<endl;

    cout<<".__________________________________________________________________________________.\n";
    cout<<"| Name :  "<<data_fname[i][o][q]<<"\t\t |  Reference :  "<< reference[i][o][q]<<"\t\t   |" <<endl; 
    cout<<"|----------------------------------------------------------------------------------| \n";
    cout<<"| Seat :  "<< seat_no[i][o][q] <<"\t\t |  Flight Place :  "<< to_place[i][o][q] << "\t |  Time :  "<< book_time[i][o][q]<<"\t   |"<<endl;
    cout<<"|__________________________________________________________________________________|\n"<<endl;

    cout <<"Are you sure want to cancel your flight ?"<<endl;
    cout<<"1.  Yes \n";
    cout<<"2.  No  \n";

    int chose_cancel;
    // Delete the data from file
     ifstream inFile(filePath); // Open the file for reading
    vector<string> lines;
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            lines.push_back(line); // Store each line in a vector
        }
        inFile.close();
    } else {
        cerr << "Unable to open file for reading.\n";
    }

    while (true){
        if(!(cin >> chose_cancel)){
            notInt();
            continue;
        }
        switch(chose_cancel){
            case 1:
                if(k>=0){
                    seat_no[i][o][q] = "";
                    reference[i][o][q] = "";
                    data_fname[i][o][q] = "";
                    age[i][o][q] = NULL;
                    address[i][o][q] = "";
                    number[i][o][q] = NULL;
                    book_time[i][o][q] = "";
                    to_place[i][o][q] = ""; 

                    // to delete file data

                    lines.erase(lines.begin() + q); // Erase the file
                    ofstream outFile(filePath); // Open the file for writing
                    if (outFile.is_open()) {
                        for (const auto &l : lines) {
                            outFile << l << "\n"; // Write each line back to the file
                        }
                        outFile.close();
                    } else {
                        cerr << "Unable to open file for writing.\n";
                    }

                    system("cls"); 
                    cout <<"Your Flight has been canceled. \n\n";
                    cout<<"Press any key to go to main menu.\n";
                    getch();
                    return 0;
                }
            
            case 2:
                cout << "You are about to exit. \nPress any key to go to main menu"<<endl;
                getch();
                return 0;
            default:
                cout<< "Invalid Input. Enter again. "<< endl;
                continue;

        }
    }


    
}

// for read existing booking
vector<string> split(const string &str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to trim leading and trailing spaces
string trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return ""; // No content
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

Booking parseBooking(const string &line) {
    Booking booking;
    auto parts = split(line, '\t');
    for (const auto &part : parts) {
        auto keyValue = split(part, ':');
        if (keyValue.size() == 2) {
            string key = trim(keyValue[0]);
            string value = trim(keyValue[1]);
            if (key.find("Reference") != string::npos) {
                booking.f_reference = value;
            } else if (key.find("Name") != string::npos) {
                booking.f_name = value;
            } else if (key.find("Age") != string::npos) {
                booking.f_age = stoi(value);
            } else if (key.find("Address") != string::npos) {
                booking.f_address = value;
            } else if (key.find("Number") != string::npos) {
                booking.f_number = value;
            } else if (key.find("Seat No") != string::npos) {
                booking.f_seatNo = value;
            } else if (key.find("Book Time") != string::npos) {
                booking.f_bookTime = value;
            } else if (key.find("Flight to") != string::npos) {
                booking.f_flightTo = value;
            }
        }
    }
    return booking;
}

void checkExestingFile(){
    // to read file
    ifstream file("4semproject.txt");

    vector<Booking> bookings;
    string line;
    while (getline(file, line)) {
        bookings.push_back(parseBooking(line));
    }
    file.close();

    int e, f;

    // Accessing booking
    for (const auto &booking : bookings) {

        if(booking.f_flightTo == "Pokhara"){
            e = 0;
            if(booking.f_bookTime == "8 AM"){
                f= 1;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else if(booking.f_bookTime == "11 AM"){
                f= 2;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else if(booking.f_bookTime == "2 PM"){
                f= 3;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else if(booking.f_bookTime == "4 PM"){
                f= 4;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else{
                // nothing to do
            }

        }

        else if(booking.f_flightTo == "Biratnagar"){
            e = 1;
            if(booking.f_bookTime == "8 AM"){
                f= 1;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else if(booking.f_bookTime == "11 AM"){
                f= 2;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else if(booking.f_bookTime == "2 PM"){
                f= 3;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else if(booking.f_bookTime == "4 PM"){
                f= 4;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else{
                // nothing to do
            }

        }

        else if(booking.f_flightTo == "Nepalganj"){
            e = 2;
            if(booking.f_bookTime == "8 AM"){
                f= 1;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else if(booking.f_bookTime == "11 AM"){
                f= 2;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else if(booking.f_bookTime == "2 PM"){
                f= 3;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else if(booking.f_bookTime == "4 PM"){
                f= 4;
                reference[e][f][k] = booking.f_reference;
                data_fname[e][f][k] = booking.f_name;
                age[e][f][k] = booking.f_age;
                address[e][f][k] = booking.f_address;
                number[e][f][k] = stoull(booking.f_number);
                seat_no[e][f][k] = booking.f_seatNo;
                book_time[e][f][k] = booking.f_bookTime;
                to_place[e][f][k] = booking.f_flightTo;
            }
            else{
                // nothing to do
            }

        }
        k++;
        
    }
}

// this is main 
int main(){

    checkExestingFile();

    // this is begining
    menu m;
    m.run();

    system("cls");
    cout<<"\nThanks for using our service .  \n\n\n";
    


    getch();

    cout<<"Bye Bye !!\nHave a great Day.\n"<<endl;
    getch();

    

    return 0;

}
