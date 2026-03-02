#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <cstring> 

using namespace std;

static int count1 = 0;
static int count2 = 0;
int op;
int flag1 = 0;
int flag2 = 0;
int opp;
int e = 0;
int h;
double testpnr;

class person {
public:
    string name;
    string mobile;
    string email;
    int age;
    int getdata();
};

int person::getdata() {
    fstream file;
    cout << "ENTER YOUR FULL NAME " << endl;
    getline(cin >> ws, name);
    cout << "ENTER YOUR AGE" << endl;
    cin >> age;
    cout << "ENTER MOBILE NO." << endl;
    getline(cin >> ws, mobile);
    cout << "ENTER EMAIL ID ";
    cin >> email;

    if (op == 3) {
        return 0; 
    } else {
        file.open("PASSENGER.txt", ios::app);
        file << "NAME: " << name << endl;
        file << "AGE: " << age << endl;
        file << "MOBILE: " << mobile << endl;
        file << "EMAIL: " << email << endl;
        file << endl << endl;
        file.close();
    }
    return 1;
}

class addon; 

class passenger : virtual public person {
protected:
    string id;
    string flightype;
    string passport = "-";
public:
    friend class addon;
    void getpass();
    virtual void displaydataa(string passenger1 = "NORMAL", string flightype = "DOMESTIC") = 0;
};

string passenger1; 
void passenger::getpass() {
    cout << "ENTER PASSENGER TYPE(NORMAL/STUDENT)\n";
    getline(cin >> ws, passenger1);
    fstream file;
    file.open("PASSENGER.txt", ios::app);
    file << "PASSENGER TYPE: " << passenger1 << endl;
    file.close();
    if (passenger1 == "STUDENT") {
        cout << "ENTER STUDENT ID " << endl;
        cin >> id;
    }
    system("CLS");
}

class staff : virtual public person {
protected:
    string role;
    int emp_id;
    string post;
public:
    char flight[20], air[10];
    float x, xii;
    string address, ex;
    void flightassign();
    int applypost();
    void display();
    void m_salary();
    friend int stafff(staff &s);
};

void staff::flightassign() {
    int b;
    cout << "FROM WHICH AIRLINE YOU BELONG TO\n";
    cin >> air;
    cout << "ENTER YOUR CURRENT AIRPORT LOCATION\n";
    cin >> flight;
    cout << "AVAILABLE " << air << " FLIGHTS FROM " << flight << "\n";
    cout << "1. " << air << " " << rand() % 100 + 101 << flight << " TO JAIPUR " << setw(30) << "22.00-23.10" << endl;
    cout << "2. " << air << " " << rand() % 100 + 101 << flight << " TO BANGLORE " << setw(28) << "18.00->19.10" << endl;
    cout << "3. " << air << " " << rand() % 100 + 101 << flight << " TO KOLKATA " << setw(29) << "12.30-13.45" << endl;
    cout << "4. " << air << " " << rand() % 100 + 101 << flight << " TO CHANDIGARH " << setw(26) << "16.00-18.10" << endl;
    cout << "ENTER YOUR CHOICE\n";
    cin >> b;
    if (b >= 1 && b <= 4) {
        cout << "FLIGHT IS ASSIGNED SUCCESSFULLY\n";
    } else {
        cout << "INVALID FLIGHT!!ENTER AGAIN\n";
    }
}

void staff::m_salary() {
    cout << "1.CLEANER(RS.1000/DAY)\n2.SECURITY(RS.2000/DAY)\n3.AIR HOSTESS(2500/DAY)\n4.PILOT(RS.8500/DAY)\n5.GROUND STAFF(RS.1200/DAY)\n6.AIRLINE BAGGAGE HANDLER(RS.3500/DAY)\n";
    cout.width(60);
    cout.fill('*');
    cout << "ENTER YOUR POST";
    cout << setfill('*') << setw(60) << "" << endl;
    getline(cin >> ws, role);
    if (role == "CLEANER") cout << "MONTHLY SALARY IS RS. " << 30 * 1000 << endl;
    else if (role == "SECURITY") cout << "MONTHLY SALARY IS RS. " << 30 * 2000 << endl;
    else if (role == "AIR HOSTESS") cout << "MONTHLY SALARY IS RS. " << 30 * 2500 << endl;
    else if (role == "PILOT") cout << "MONTHLY SALARY IS RS. " << 30 * 8500 << endl;
    else if (role == "GROUND STAFF") cout << "MONTHLY SALARY IS RS. " << 30 * 1200 << endl;
    else if (role == "AIRLINE BAGGAGE HANDLER") cout << "MONTHLY SALARY IS RS. " << 30 * 3500 << endl;
    else cout << "INVALID ENTRY" << endl;
}

void staff::display() {
    cout << "POST: " << post << "\nNAME: " << name << "\nAGE: " << age << "\nMOBILE: " << mobile << "\nEMAIL: " << email << "\nADDRESS: " << address << "\nXTH PERCENTAGE: " << x << "\nXII th PERCENTAGE: " << xii << "\nEXPERIENCE: " << ex << endl;
}

int staff::applypost() {
    cout << "1.CLEANER\n2.SECURITY\n3.AIR HOSTESS\n4.PILOT\n5.GROUND STAFF\n6.AIRLINE BAGGAGE HANDLER\n7.EXIT\n";
    cout << "ENTER THE POST FOR WHICH YOU WANT TO APPLY\n";
    getline(cin >> ws, post);
    if (post == "EXIT") return (0);
    getdata();
    cout << "ENTER YOUR ADDRESS\n";
    getline(cin >> ws, address);
    cout << "ENTER YOUR Xth PERCENTAGE\n";
    cin >> x;
    cout << "ENTER YOUR XIIth/DIPLOMA PERCENTAGE\n";
    cin >> xii;
    cout << "ENTER YOUR EXPERIENCE IF ANY\n";
    getline(cin >> ws, ex);
    cout << "APPLICATION SUBMITTED SUCCESSFULLY\n\nAPPLICATION\n";
    display();
    return 1;
}

int stafff(staff &s) {
    while (1) {
        int ops;
        cout << "1.FLIGHT ASSIGNMENT\n2.CALCULATE MONTHLY SALARY\n3.EXIT\nENTER YOUR CHOICE\n";
        cin >> ops;
        system("CLS");
        switch (ops) {
            case 1: s.flightassign(); break;
            case 2: s.m_salary(); break;
            case 3: return (1);
            default: cout << "WRONG CHOICE ENTER AGAIN";
        }
    }
}

class flightsearch : public passenger, public staff {
protected:
    string departure;
    string date;
    string destination;
    string classs;
    char dir_con[20];
public:
    void flight_search();
    void flightdisplay();
    void displaydataa(string passenger1 = "NORMAL", string flightype = "DOMESTIC") {
        cout << "NAME: " << name << endl;
        cout << "MOBILE: " << mobile << endl;
        cout << "EMAIL ID: " << email << endl;
        cout << "PASSENGER TYPE: " << passenger1 << endl;
        cout << "FLIGHTYPE: " << flightype << endl;
        cout << "PASSPORT NUMBER: " << passport << endl;
    }
};

int indigo[3], vistara[3], air_india[3], akasaair[3];
int indigo_c[3], vistara_c[3];
double t[10], p[10];
double ticket_price = 0;

void flightsearch::flightdisplay() {
    int h[10], m[10], u[10], hh[10], mm[10], j = 1, k = rand() % 100;
    for (int i = 1; i <= 8; i++) {
        h[i] = rand() % 24;
        m[i] = rand() % 60;
        u[i] = ((h[i] * 60 + m[i]) + k);
        hh[i] = u[i] / 60;
        mm[i] = u[i] % 60;
    }
    if (strcmp(dir_con, "DIRECT") != 0) { 
        if ((destination == "MUMBAI") || (destination == "BANGLORE")) {
            try { throw(dir_con); }
            catch (...) { cout << "OOPS!NO RESULT FOUND FOR YOUR SEARCH, WE SUGEST YOU MODIFY YOUR SEARCH" << endl; }
        } else {
            cout << "CONNECTED FLIGHTS FROM " << departure << " TO " << destination << endl;
            p[j] = rand() % 100 + 3000;
            cout << "1. " << departure << " TO MUMBAI T1 \nINDIGO|6E" << rand() % 100 + 101 << " " << h[j] << ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << p[j] << "/-" << endl;
            j++;
            p[j] = rand() % 100 + 4000;
            cout << "MUMBAI T2 TO " << destination << "\nVISTARA UK" << rand() % 100 + 101 << " " << h[j] << ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << p[j] << "/-" << endl;
            j++;
        }
    } else {
        cout << "DIRECT FLIGHTS FROM " << departure << " TO " << destination << endl;
        for (int i = 0; i < 2; i++) {
            t[j] = rand() % 100 + 3000; indigo[i + 1] = rand() % 100 + 101;
            cout << (1 + (i * 4)) << ".INDIGO|6E" << indigo[i + 1] << " " << h[j] << ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << t[j] << "/-" << endl; j++;
            t[j] = rand() % 100 + 4000; vistara[i + 1] = rand() % 100 + 101;
            cout << (2 + (i * 4)) << ".VISTARA|UK" << vistara[i + 1] << " " << h[j] << ":" << m[j] << "------->" << hh[j] << ":" << mm[j] << " RS." << t[j] << "/-" << endl; j++;
        }
    }
}

void flightsearch::flight_search() {
    count2++;
    cout << "ENTER DEPARTURE AIRPORT" << endl;
    cin >> departure;
    cout << "ENTER ARRIVAL AIRPORT" << endl;
    cin >> destination;
    while (departure == destination) {
        cout << "INVALID ENTRY(DESTINATION AND DEPARTURE AIRPORT CANT BE THE SAME)" << endl;
        cin >> destination;
    }
    cout << "ENTER DATE OF TRAVEL" << endl;
    cin >> date;
    cout << "DIRECT/CONNECTED\n";
    cin >> dir_con;
    fstream file("PASSENGER.txt", ios::app);
    file << endl << "DEPARTURE: " << departure << " DESTINATION: " << destination << " DATE: " << date << " DIRECT/CONNECTED: " << dir_con << endl;
    file.close();
    system("CLS");
    flightdisplay();
}

class addon {
protected:
    string seatno;
    string meal = "-";
    int baggage = 0;
    string fastforwardp = "-";
    char seat[10] = "-";
    string insurance = "-";
    float s = 0, q = 0, d = 0;
public:
    int seatToIndicerow(string);
    int seatToIndicecol(string);
    void bookseat(string);
    bool isbooked(string);
    bool isValidSeat(string);
    int getaddon();
    void displayaddon(string m = "-", float n = 1);
    void displayaddon(float s = 0, float d = 0, string a = "-");
};

void addon::displayaddon(string m, float n) {
    cout.setf(ios::left, ios::adjustfield);
    cout << endl << "MEAL: " << m << " QUANTITY: " << n << endl;
}

void addon::displayaddon(float s, float d, string a) {
    cout << "EXTRA BAGGAGE: " << baggage << "KG." << endl;
    cout << "FAST CHECK-IN QUANTITY: " << s << endl;
    cout << "SEAT: " << a << endl;
    cout << "TRAVEL INSURANCE: " << insurance << endl;
    cout << "NO. OF PASSENGERS: " << d << endl;
}

template <class T>
inline T cal_total(T ad, T ticket_price) {
    static float convi_fee = 300.75;
    if (ad == 0) return ticket_price + convi_fee;
    else return ticket_price + convi_fee + ad;
}

double ad = 0;
bool bookedseats[30][6] = { false };
int addon::seatToIndicerow(string s1) { return stoi(s1.substr(0, 2)); }
int addon::seatToIndicecol(string s1) { return s1.back() - 'A'; }
void addon::bookseat(string s) { bookedseats[seatToIndicerow(s)][seatToIndicecol(s)] = true; }
bool addon::isbooked(string s) { return bookedseats[seatToIndicerow(s)][seatToIndicecol(s)]; }

bool addon::isValidSeat(string s) {
    if (s.length() != 3) return false;
    string row = s.substr(0, 2);
    if (!isdigit(row[0]) || !isdigit(row[1])) return false;
    int rowNum = stoi(row);
    if (rowNum < 1 || rowNum > 30) return false;
    if (s[2] < 'A' || s[2] > 'F') return false;
    return true;
}

int addon::getaddon() {
    static double veg = 200.8, nonveg = 400.6;
    static float extra_kg = 600.00;
    float q;
    cout << "1.MEAL\n2.EXTRA BAGGAGE\n3.FAST CHECK-IN\n4.SEAT\n5.TRAVEL INSURANCE\n6.SKIP TO PAYMENT\n7.EXIT\nENTER CHOICE\n";
    cin >> opp;
    switch (opp) {
        case 1:
            cout << "MEAL TYPE(VEG/NON-VEG): "; getline(cin >> ws, meal);
            cout << "QUANTITY: "; cin >> q;
            if (meal == "VEG") ad += (q * veg); else ad += (q * nonveg);
            break;
        case 2:
            cout << "WEIGHT (MAX 30KG): "; cin >> baggage;
            if (baggage <= 30) ad += (baggage * extra_kg);
            break;
        case 4:
            cout << "ENTER SEAT: "; cin >> seatno;
            if (isValidSeat(seatno)) bookseat(seatno);
            break;
        case 6:
            cout << "TOTAL PRICE IS: " << cal_total(ad, ticket_price) << endl;
            flag1 = 1; return 0;
        case 7: return 0;
    }
    return 1;
}

class booking : public flightsearch, public addon {
protected:
    string name1;
    string status = "BOOKED";
    string flight_full, flight_full_C1, flight_full_C2;
public:
    double pnr;
    booking *ptr;
    void book();
    void details();
    int cancel(booking &b);
    int review(booking &c);
    int modify(booking &d);
    string getFlightFull(string name, int arr[], int idx) { return name + to_string(arr[idx]); }
    bool operator==(booking &obja) { return (name == obja.name1); }
};

void operation(booking &obja) {
    while (1) {
        cout << "\n1.SEARCH\n2.BOOK\n3.CANCEL\n4.MODIFY\n5.VIEW\n6.EXIT\nCHOICE: ";
        cin >> h;
        system("CLS");
        switch (h) {
            case 1: obja.flight_search(); break;
            case 2: obja.book(); if (flag1 == 1) obja.details(); break;
            case 3: obja.cancel(obja); break;
            case 4: obja.modify(obja); break;
            case 5: obja.review(obja); break;
            case 6: exit(0);
        }
    }
}

void booking::book() {
    int o;
    flightdisplay();
    cout << "SELECT FLIGHT: "; cin >> o;
    ticket_price = t[o];
    ptr = new booking[20];
    ptr->getpass();
    ptr->getdata();
    ptr->getaddon();
}

int booking::cancel(booking &b) {
    cout << "ENTER NAME: "; getline(cin >> ws, name1);
    cout << "ENTER PNR: "; cin >> testpnr;
    if (pnr == testpnr) {
        status = "CANCELLED";
        cout << "TICKET CANCELLED\n";
    }
    return 0;
}

int booking::review(booking &c) {
    cout << "ENTER NAME: "; getline(cin >> ws, name1);
    cout << "ENTER PNR: "; cin >> testpnr;
    if (pnr == testpnr) {
        cout << "NAME: " << name << " STATUS: " << status << endl;
    }
    return 0;
}

void booking::details() {
    cout << "DEPARTURE: " << departure << " ARRIVAL: " << destination << " DATE: " << date << endl;
    pnr = rand() % 100 + 101;
    cout << "PNR: " << pnr << endl;
}

int booking::modify(booking &d) {
    int choice;
    cout << "1.MODIFY DEPARTURE\n2.MODIFY ARRIVAL\n3.MODIFY DATE\nCHOICE: ";
    cin >> choice;
    switch(choice) {
        case 1: cin >> departure; break;
        case 2: cin >> destination; break;
        case 3: cin >> date; break;
    }
    return 0;
}

int passwordcheck() {
    string pass;
    cout << "ENTER ADMIN PASSWORD: "; cin >> pass;
    if (pass == "23CE103" || pass == "23CE113") return 1;
    return 0;
}

void welcome(booking &b) {
    cout << "ENTER YOUR NAME: "; getline(cin >> ws, b.name);
    system("CLS");
    while (1) {
        cout << "HELLO " << b.name << "!\n1.PASSENGER\n2.STAFF\n3.JOB APPLICANT\n4.EXIT\nCHOICE: ";
        cin >> op;
        switch (op) {
            case 1: operation(b); break;
            case 2: if (passwordcheck()) stafff(b); break;
            case 3: b.applypost(); break;
            case 4: exit(0);
        }
    }
}

int main() {
    booking b;
    welcome(b);
    return 0;
}