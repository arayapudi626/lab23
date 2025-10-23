#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Goat23.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> &trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    //bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> trip;

while(true) {
    int choice = main_menu();
    switch (choice) {
        case 1: add_goat(trip, names, colors); break;
        case 2: delete_goat(trip); break;
        case 3: display_trip(trip); break;
        case 4: return 0;
    }
}
    return 0;
}

int main_menu() {
    cout << "*** GOAT MANAGER 3001 ***\n"
    << "[1] Add a goat \n"
    << "[2] Delete a goat \n"
    << "[3] List goats \n"
    << "[4] Quit \n"
    <<"Choice --> ";

    int choice;
    cin >> choice;
    if (choice >=1 && choice <=4){
        return choice;
    }
    cout << "Invalid choice. Try again. \n";
}

void add_goat(list<Goat> &trip, string names[], string colors[]){
    string name = names[rand() % SZ_NAMES];
    int age = rand() % MAX_AGE + 1;
    string color = colors[rand() % SZ_COLORS];

    Goat new_goat(name, age, color);
    trip.push_back(new_goat);
    trip.sort();

    cout << "Added goat: " << name << "( " << age << ", " << color << " )\n";
}

int select_goat(list<Goat> &trip){
    int i = 1;
    for (const auto& g : trip){
        cout << "[" << i++ << "] " << g.get_name() << ", ( " << g.get_age() << ", " << g.get_color() << ") \n";
    }
    cout << "Select a goat by number --> ";
    int choice;
    cin >> choice;
    if (choice >=1 && choice <= trip.size()){
        return choice;
    }
}


void delete_goat(list<Goat> &trip){
    int count = 1;
    int choice = select_goat(trip);
    for (auto it = trip.begin(); it != trip.end(); it++, count++){
        if (count == choice){
            cout << "Deleting: " << it->get_name() << " ( " << it->get_age() << ", " << it->get_color() << " ) \n";
            trip.erase(it);
            return;
        }
    }
    

}

void display_trip(list<Goat> trip){
    trip.sort();
    int i = 1;
    for (const Goat& g : trip){
        cout << "[" << i++ << "] " << g.get_name() << " ( " << g.get_age() << ", " << g.get_color() << " ) \n";
    }
}


