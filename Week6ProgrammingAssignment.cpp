// This program takes in the user data for: Their name; How many days they birded; How many hours they birded; How many birds they saw; and if it is winter or not.
// This program outputs if the user had a good or bad birding day as well as a table of the user's statistics.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
enum season { Winter, Spring, Summer, Fall };

void printtable(string username, int daysbirding, double hoursbirding, int birdsseen, double hourlybirds, int day, const int week, bool daycheck[7]);

season convertenum(const string& seasonAnswer);

int main()
{
    string username;
    int day;
    const int week = 7;
    bool daycheck[7];
    int daysbirding = 0;
    double hoursbirding;
    int birdsseen;
    double hourlybirds;
    bool winter = false;
    string seasonanswer;
    season seasonentered;

    // ********** USER INPUT STATEMENTS **********

    cout << "Welcome! Please input your first name!\n";
    cin >> username;
    
    for (day = 0; day < week; day++) {
        cout << "Did you go birding today? Type 1 if Yes Type 0 if No\n";
        cin >> daycheck[day];
        daysbirding = daysbirding + daycheck[day];
     }

    do {
        cout << "How many hours did you go birding?\n";
        cin >> hoursbirding;
    } while (hoursbirding <= 0 || hoursbirding >= 168);

    cout << "How many birds did you see in total?\n";
    cin >> birdsseen;
    while (birdsseen <= 0) {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Enter a number: \n";
        cin >> birdsseen;
        "\n";
    }

    cout << "Enter the current season (Winter, Spring, Summer, or Fall):\n";
    cin >> seasonanswer;

    // ********** SWITCH STATEMENT **********

    seasonentered = convertenum(seasonanswer);
    switch (seasonanswer == "Winter") {
    case true:
        winter = !winter;
        break;
    case false:
        winter = winter;
        break;
    }

    // ********** CALCULATIONS **********

    hourlybirds = birdsseen / hoursbirding;

    cout << fixed << setprecision(2);

    // ********** OUTPUT STATEMENT **********

    if (hourlybirds >= 10 && winter == true) {
        cout << "You had a good birding day, even though it was winter!" << endl;
    }
    else if (hourlybirds <= 10 && winter == true) {
        cout << "Winter is a tough time for birding, it's okay." << endl;
    }
    else if (hourlybirds >= 10 && winter == false) {
        cout << "You had a good birding day!" << endl;
    }
    else if (hourlybirds <= 10 && winter == false) {
        cout << "You had a bad birding day." << endl;
    }

    // ********** PRINTTABLE FUNCTION **********

    printtable(username, daysbirding, hoursbirding, birdsseen, hourlybirds, day, week, daycheck);

    // ********** RETURN VALUE **********

    return 0;
}


// ********** PRINTTABLE OUTPUT **********

void printtable(string username, int daysbirding, double hoursbirding, int birdsseen, double hourlybirds, int day, const int week, bool daycheck[7]) {

    SetConsoleTextAttribute(hConsole, 13);
    cout << setw(30) << setfill('*') << "" << setfill(' ') << endl;
    SetConsoleTextAttribute(hConsole, 7);
    cout << "   " << setw(1) << "User's Name :" << setw(11) << username << endl;
    cout << "   " << setw(1) << "Days Birding :" << setw(10) << daysbirding << endl;
    cout << "   " << setw(1) << "Hours Birding :" << setw(9) << hoursbirding << endl;
    cout << "   " << setw(1) << "Bird Seen :" << setw(13) << birdsseen << endl;
    cout << "   " << setw(1) << "Average Birds :" << setw(9) << hourlybirds << endl;
    SetConsoleTextAttribute(hConsole, 13);
    cout << setw(30) << setfill('*') << "" << endl;
    SetConsoleTextAttribute(hConsole, 7);

    for (day = 0; day < week; day++) {
        cout << "Day: " << day + 1 << " ";
        if (daycheck[day] == 1) {
            cout << "Went Birding\n";
        }
        else {
            cout << "Did Not Go Birding\n";
        }
    }

    // ********** OUTPUT DATA **********

    ofstream outFile;

    outFile.open("report.txt");
    outFile << setw(30) << setfill('*') << "" << setfill(' ') << endl;
    outFile << "   " << setw(1) << "User's Name :" << setw(11) << username << endl;
    outFile << "   " << setw(1) << "Days Birding :" << setw(10) << daysbirding << endl;
    outFile << "   " << setw(1) << "Hours Birding :" << setw(9) << hoursbirding << endl;
    outFile << "   " << setw(1) << "Bird Seen :" << setw(13) << birdsseen << endl;
    outFile << "   " << setw(1) << "Average Birds :" << setw(9) << hourlybirds << endl;
    outFile << setw(30) << setfill('*') << "" << endl;
    outFile.close();
}

// ********** ENUM DATA **********

season convertenum(const string& seasonAnswer) {
    if (seasonAnswer == "Winter") {
        return Winter;
    }
    else if (seasonAnswer == "Spring") {
        return Spring;
    }
    else if (seasonAnswer == "Summer") {
        return Summer;
    }
    else if (seasonAnswer == "Fall") {
        return Fall;
    }
}