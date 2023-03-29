#include <iostream>
#include <sstream>
using namespace std; 

string findTime(string, int);
int min = 0;

class Passenger{
    protected:
    string name, gender, flightClass, boardingTime;
    public:
    Passenger(string name,string gender, string boardingTime){
        this -> name = name;
        this -> gender = gender;
        this -> boardingTime = boardingTime;
    }
    string getName(){
        return name;
    }
     string getGender(){
        return gender;
    }
     string getClass(){
        return flightClass;
    }
     string getBoarding(){
        return boardingTime;
    }
    void virtual calcBoardingTime() = 0;
};

class Economy : public Passenger{ 
    private:
    static int count;
    public:
    Economy(string name, string gender, string boardingTime):Passenger(name, gender, boardingTime){
        flightClass = "Economy Class";
        count++;
    }
    void calcBoardingTime(){
        ::min += 2;
        try{
            if(count>20)
            throw("Economy");
            else boardingTime = findTime(boardingTime, ::min);
        }catch(char *a){
        cout<<"Sorry no more seat left in"<<a<<"Class"<<endl;
        exit(1);
        }
    }
};
int Economy::count = 0;

class Business : public Passenger{
    private:
    static int count;
    public:
    Business(string name, string gender, string boardingTime):Passenger(name, gender, boardingTime){
        flightClass = "Business Class";
        count++;
    }
    void calcBoardingTime(){
        ::min += 3;
        try{
            if(count>10)
            throw("Business");
            else boardingTime = findTime(boardingTime, ::min);
        }catch(char *a){
        cout<<"Sorry no more seat left in"<<a<<"Class"<<endl;
        exit(1);
        }
    }

};
int Business::count = 0;

class First : public Passenger{
    private:
    static int count;
    public:
    First(string name, string gender, string boardingTime):Passenger(name, gender, boardingTime){
        flightClass = "First Class";
        count++;
    }
    void calcBoardingTime(){
        ::min += 4;
        try{
            if(count>10)
            throw("First");
            else boardingTime = findTime(boardingTime, ::min);
        }catch(char *a){
        cout<<"Sorry no more seat left in"<<a<<"Class"<<endl;
        exit(1);
        }
    }
};
int First::count = 0;

string findTime(string a, int b){
    int hour, minute;
    char semi;
    stringstream ss;
    ss << a;
    ss >> hour >> semi >> minute;
    stringstream ss2;
    minute += b;
    if(minute>59){
        minute -=60;
        hour++;
    }
    if(minute<10){
        ss2 << hour << ":0" << minute;
    }
    else{
        ss2 << hour << ":" << minute;
    }
    return ss2.str();
}

void displayPassengerInfo(Passenger *p){
    p->calcBoardingTime();
    cout<<p->getName()<<" "<<p->getGender()<<" "<<p->getClass()<<" "<<p->getBoarding()<<endl<<endl;
}

int main(){

    First p1("Adralei", "Male", "10.00");
    First p2("John", "Male", "10.00");
    Business p3("Anthony", "Male", "10.00");
    Economy p4("Eva","Female","10.00");
    Economy p5("Hana", "Female","10.00");
    First p6("Charlotte", "Female", "10.00");
    Economy p7("Bruce","Male","10.00");
    First p8("Dilara","Female", "10.00");
    First p9("Kaya","Male","10.00");
    Business p10("Koray","Male","10.00");

    displayPassengerInfo(&p1);
    displayPassengerInfo(&p2);
    displayPassengerInfo(&p3);
    displayPassengerInfo(&p4);
    displayPassengerInfo(&p5);
    displayPassengerInfo(&p6);
    displayPassengerInfo(&p7);
    displayPassengerInfo(&p8);
    displayPassengerInfo(&p9);
    displayPassengerInfo(&p10);
}