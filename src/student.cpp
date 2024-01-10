//student.cpp to implement your classes
#include <string>
#include <iostream>
#include <iomanip> // For the setprecision() function
#include "student.hpp"


// ToeflScore--------------------------------------------

// Default constructor
ToeflScore::ToeflScore() {

    reading = 0;
    listening = 0;
    speaking = 0;
    writing = 0;
    total = 0;
}

// Call this function every time one of the member values is altered
void ToeflScore::update_total() {
    total = reading + listening + speaking + writing;
}

// Getters
int ToeflScore::get_reading() const {
    return reading;
}

int ToeflScore::get_listening() const {
    return listening;
}

int ToeflScore::get_speaking() const {
    return speaking;
}

int ToeflScore::get_writing() const {
    return writing;
}
    
int ToeflScore::get_total() const {
    return total;
}

// Setters
void ToeflScore::set_reading(int reading) {
    this->reading = reading;
    update_total();
}
    
void ToeflScore::set_listening(int listening) {
    this->listening = listening;
    update_total();
}
void ToeflScore::set_speaking(int speaking) {
    this->speaking = speaking;
    update_total();
}

void ToeflScore::set_writing(int writing) {
    this->writing = writing;
    update_total();
}

// Overload << operator
ostream& operator <<(ostream& outs, ToeflScore& toeflScore) {

    outs << toeflScore.reading << ", " << toeflScore.listening << ", " << toeflScore.speaking << ", " << toeflScore.writing << endl;
    return outs;
}

// ToeflScore--------------------------------------------





// Student-----------------------------------------------


// Default constructor
Student::Student() {

    firstName = "NULL";
    lastName = "NULL";
    CGPA = 0.0;
    researchScore = 0.0;
    appID = 00000000;
}

Student::Student(Student* student) {

    set_firstName(student->get_firstName());
    set_lastName(student->get_lastName());
    set_CGPA(student->get_CGPA());
    set_researchScore(student->get_researchScore());
    set_appID(student->get_appID());
}

// Getters
string Student::get_firstName() const {
    return firstName;
}

string Student::get_lastName() const {
    return lastName;
}

float Student::get_CGPA() const {
    return CGPA;
}

int Student::get_researchScore() const {
    return researchScore;
}

int Student::get_appID() const {
    return appID;
}

// Setters
void Student::set_firstName(string firstName) {
    try {
        if (firstName == " ") {
            throw firstName;
        }
        if ((firstName[0] >= 65 && firstName[0] <= 90) && (firstName[0] >= 97 && firstName[0] <= 122)) {
            throw firstName;
        }
    }
    catch (string e) {
        cout << "Invalid first name!" << endl;
        exit(1);
    }

    // If the first letter of the name is lowercase change it to uppercase
    if (firstName[0] >= 97 && firstName[0] <= 122) {
        firstName[0] = firstName[0] - 32;
    }

    // Change any letter that isn't the first from uppercase to lowercase 
    for (int i = 1; i <= firstName.length(); i++) {
        if (firstName[i] >= 65 && firstName[i] <= 90) {
            firstName[i] = firstName[i] + 32;
        }
    }
    this->firstName = firstName;

}

void Student::set_lastName(string lastName) {
    string test;

    try {
        if (lastName == " ") {
            throw lastName;
        }
        if ((lastName[0] >= 65 && lastName[0] <= 90) && (lastName[0] >= 97 && lastName[0] <= 122)) {
            throw lastName;
        }
    }
    catch (string e) {
        cout << "Invalid last name!" << endl;
        exit(1);
    }

    // Change last names to all be in the same format
    if (lastName[0] >= 97 && lastName[0] <= 122) {
        lastName[0] = lastName[0] - 32;
    }

    for (int i = 1; i <= lastName.length(); i++) {
        if (lastName[i] >= 65 && lastName[i] <= 90) {
            lastName[i] = lastName[i] + 32;
        }
    }
    this->lastName = lastName;
}

void Student::set_CGPA(float CGPA) {
        try {
        if (CGPA == 0) {
            throw CGPA;
        }
    }
    catch (float e) {
        cout << "Invalid CGPA!" << endl;
        exit(1);
    }
    this->CGPA = CGPA;
}

void Student::set_researchScore(int researchScore) {
    try {
        if (researchScore == 0) {
            throw researchScore;
        }
    }
    catch (int e) {
        cout << "Invalid research score!" << endl;
        exit(1);
    }
    this->researchScore = researchScore;
}

void Student::set_appID() {
    static int appID_next = 20220000;
    this -> appID = appID_next;
    appID_next++;
}

void Student::set_appID(int appID) {
    this->appID = appID;
    try {
        if (appID == 0) {
        throw appID;
        }
    }
    catch (int e) {
        cout << "Error: no application ID";
    }
}

// Comparing functions
int compareCGPA(const Student& stu1, const Student& stu2) {
    
    // Case 1:
    if (stu1.CGPA < stu2.CGPA) {
        return 0;
    // Case 2;
    } else if (stu1.CGPA == stu2.CGPA) {
        return 1;
    // Case 3:
    } else if (stu1.CGPA > stu2.CGPA) {
        return 2;
    // If none of these:
    } else {
        return -1;
    }
}

int compareResearchScore(const Student& stu1, const Student& stu2) {
    
    // Case 1:
    if (stu1.researchScore < stu2.researchScore) {
        return 0;
    // Case 2;
    } else if (stu1.researchScore == stu2.researchScore) {
        return 1;
    // Case 3:
    } else if (stu1.researchScore > stu2.researchScore) {
        return 2;
    // If none of these:
    } else {
        return -1;
    }
}

int compareFirstName(const Student& stu1, const Student& stu2) {

    int strLength1 = stu1.firstName.size();
    int strLength2 = stu2.firstName.size();
    int minLength;
    
    // Setting the min length to the length of the shortest string
    if (strLength1 <= strLength2) {
        minLength = strLength1;
    }
    else {
        minLength = strLength2;
    }

    // Only loops until we have fully traversed the shortest string
    for (int i = 0; i < minLength; i++) {
        // returns 1 if student2's first name comes alphabetically before student1's last name 
        if (stu1.firstName[i] > stu2.firstName[i]) {
            return 0;
        }
        // returns 2 if student1's fisrt name comes alphabetically before student2's last name 
        else if (stu1.firstName[i] < stu2.firstName[i]) {
            return 2;
        }
    }

    // If the for loop does not detect any difference:
    if (strLength1 <= strLength2) {
        return 2;
    } else if (strLength1 > strLength2) {
        return 0;
    }
    return -1;
}

int compareLastName(const Student& stu1, const Student& stu2) {

    int strLength1 = stu1.lastName.size();
    int strLength2 = stu2.lastName.size();
    int minLength;
    
    // Setting the min length to the length of the shortest string
    if (strLength1 <= strLength2){
        minLength = strLength1;
    }
    else {
        minLength = strLength2;
    }

    // Only loops until we have fully traversed the shortest string
    for (int i = 0; i < minLength; i++){
        // returns 0 if student2's last name comes alphabetically before student1's last name 
        if (stu1.lastName[i] > stu2.lastName[i]){
            return 0;
        }
        // returns 2 if student1's last name comes alphabetically before student2's last name 
        else if (stu1.lastName[i] < stu2.lastName[i]){
            return 2;
        }
    }
    // If the for loop does not detect any difference:
    if (strLength1 <= strLength2) {
        return 2;
    } else if (strLength1 > strLength2) {
        return 0;
    }
    return -1;
}

int compareCGPA(const Student* stu1, const Student* stu2) {

    // Case 1:
    if (stu1->CGPA < stu2->CGPA) {
        return 0;
    // Case 2;
    } else if (stu1->CGPA == stu2->CGPA) {
        return 1;
    // Case 3:
    } else if (stu1->CGPA > stu2->CGPA) {
        return 2;
    // If none of these:
    } else {
        return -1;
    }
}

int compareResearchScore(const Student* stu1, const Student* stu2) {
    
    // Case 1:
    if (stu1->researchScore < stu2->researchScore) {
        return 0;
    // Case 2;
    } else if (stu1->researchScore == stu2->researchScore) {
        return 1;
    // Case 3:
    } else if (stu1->researchScore > stu2->researchScore) {
        return 2;
    // If none of these:
    } else {
        return -1;
    }
}

int compareFirstName(const Student* stu1, const Student* stu2) {

    int strLength1 = stu1->firstName.size();
    int strLength2 = stu2->firstName.size();
    int minLength;
    
    // Setting the min length to the length of the shortest string
    if (strLength1 <= strLength2) {
        minLength = strLength1;
    }
    else {
        minLength = strLength2;
    }

    // Only loops until we have fully traversed the shortest string
    for (int i = 0; i < minLength; i++) {
        // returns 1 if student2's first name comes alphabetically before student1's last name 
        if (stu1->firstName[i] > stu2->firstName[i]) {
            return 0;
        }
        // returns 2 if student1's fisrt name comes alphabetically before student2's last name 
        else if (stu1->firstName[i] < stu2->firstName[i]) {
            return 2;
        }
    }

    // If the for loop does not detect any difference:
    if (strLength1 <= strLength2) {
        return 2;
    } else if (strLength1 > strLength2) {
        return 0;
    }
    return -1;
}

int compareLastName(const Student* stu1, const Student* stu2) {

    int strLength1 = stu1->lastName.size();
    int strLength2 = stu2->lastName.size();
    int minLength;
    
    // Setting the min length to the length of the shortest string
    if (strLength1 <= strLength2){
        minLength = strLength1;
    }
    else {
        minLength = strLength2;
    }

    // Only loops until we have fully traversed the shortest string
    for (int i = 0; i < minLength; i++){
        // returns 0 if student2's last name comes alphabetically before student1's last name 
        if (stu1->lastName[i] > stu2->lastName[i]){
            return 0;
        }
        // returns 2 if student1's last name comes alphabetically before student2's last name 
        else if (stu1->lastName[i] < stu2->lastName[i]){
            return 2;
        }
    }
    // If the for loop does not detect any difference:
    if (strLength1 <= strLength2) {
        return 2;
    } else if (strLength1 > strLength2) {
        return 0;
    }
    return -1;
}

int compareProvince(const Student* stu1, const Student* stu2) {

    int strLength1 = stu1->get_province().size();
    int strLength2 = stu2->get_province().size();
    int minLength;
    
    // Setting the min length to the length of the shortest string
    if (strLength1 <= strLength2) {
        minLength = strLength1;
    }
    else {
        minLength = strLength2;
    }

    // Only loops until we have fully traversed the shortest string
    for (int i = 0; i < minLength; i++) {
        // returns 1 if student2's first name comes alphabetically before student1's last name 
        if (stu1->get_province()[i] > stu2->get_province()[i]) {
            return 0;
        }
        // returns 2 if student1's first name comes alphabetically before student2's last name 
        else if (stu1->get_province()[i] < stu2->get_province()[i]) {
            return 2;
        }
    }
    // If the for loop does not detect any difference:
    if (strLength1 <= strLength2) {
        return 2;
    } else if (strLength1 > strLength2) {
        return 0;
    }
    return -1;
}

int compareCountry(const Student* stu1, const Student* stu2) {

    int strLength1 = stu1->get_country().size();
    int strLength2 = stu2->get_country().size();
    int minLength;
    
    // Setting the min length to the length of the shortest string
    if (strLength1 <= strLength2) {
        minLength = strLength1;
    }
    else {
        minLength = strLength2;
    }

    // Only loops until we have fully traversed the shortest string
    for (int i = 0; i < minLength; i++) {
        // returns 1 if student2's first name comes alphabetically before student1's last name 
        if (stu1->get_country()[i] > stu2->get_country()[i]) {
            return 0;
        }
        // returns 2 if student1's first name comes alphabetically before student2's last name 
        else if (stu1->get_country()[i] < stu2->get_country()[i]) {
            return 2;
        }
    }
    // If the for loop does not detect any difference:
    if (strLength1 <= strLength2) {
        return 2;
    } else if (strLength1 > strLength2) {
        return 0;
    }
    return -1;
}



// Virtual Functions

string Student::get_province() const {
    return "PV";
}

string Student::get_country() const {
    return "CT";
}

int Student::get_ToeflReading() const {
    return 0;
}

int Student::get_ToeflListening() const {
    return 0;
}

int Student::get_ToeflSpeaking() const {
    return 0;
}

int Student::get_ToeflWriting() const {
    return 0;
}

int Student::get_ToeflTotal() const {
    return 0;
}

ToeflScore Student::get_ToeflScore() const {
    ToeflScore t;
    return t;
}



// Student-----------------------------------------------





// DomesticStudent---------------------------------------

// Default constructor
DomesticStudent::DomesticStudent() {
    province = "NULL";
}

DomesticStudent::DomesticStudent(const DomesticStudent& student) {

    set_firstName(student.get_firstName());
    set_lastName(student.get_lastName());
    set_CGPA(student.get_CGPA());
    set_researchScore(student.get_researchScore());
    set_province(student.get_province());
    set_appID(student.get_appID());
} 

DomesticStudent::DomesticStudent(const DomesticStudent* student) {

    set_firstName(student->get_firstName());
    set_lastName(student->get_lastName());
    set_CGPA(student->get_CGPA());
    set_researchScore(student->get_researchScore());
    set_province(student->get_province());
    set_appID(student->get_appID());
}

// Getter
string DomesticStudent::get_province() const {
    return province;
}

// Setter
void DomesticStudent::set_province(string province) {
    // Change any lowercase letters to uppercase
    for (int i = 0; i <= province.length(); i++) {
        if (province[i] >= 97 && province[i] <= 122) {
            province[i] = province[i] - 32;
        }
    }
    
    try {
        this->province = province;
        if (province != "NL" && province != "PE" && province != "NS" && province != "NB" && province != "QC" 
            && province != "ON" && province != "MB" && province != "SK" && province != "AB" && province != "BC" 
            && province != "YT" && province != "NT" && province != "NU") {
            throw province;
        }
        else if (province == " ") {
            throw province;
        }
    }
    catch (string e) {
        cout << "Error: No matching province" << endl;
        exit(1);
    }
}

// Compare Province Function
int compareProvince(const DomesticStudent& stu1, const DomesticStudent& stu2) {
    
    int strLength1 = stu1.province.size();
    int strLength2 = stu2.province.size();
    int minLength;
    
    // Setting the min length to the length of the shortest string
    if (strLength1 <= strLength2) {
        minLength = strLength1;
    }
    else {
        minLength = strLength2;
    }

    // Only loops until we have fully traversed the shortest string
    for (int i = 0; i < minLength; i++) {
        // returns 1 if student2's first name comes alphabetically before student1's last name 
        if (stu1.province[i] > stu2.province[i]) {
            return 0;
        }
        // returns 2 if student1's first name comes alphabetically before student2's last name 
        else if (stu1.province[i] < stu2.province[i]) {
            return 2;
        }
    }
    // If the for loop does not detect any difference:
    if (strLength1 <= strLength2) {
        return 2;
    } else if (strLength1 > strLength2) {
        return 0;
    }
    return -1;
}

// Overloading the << operator
ostream& operator <<(ostream& outs, DomesticStudent& student) {

    outs << student.get_firstName() << ", " << student.get_lastName() << ", " << student.province << ", "
    << fixed << setprecision(1) << student.get_CGPA() << ", " << student.get_researchScore() << endl;
    // Note that the setprecision function outputs only the first decimal place, rounded

    return outs;
}

// Overloading the = operator
DomesticStudent& DomesticStudent::operator =(const DomesticStudent& student) {
    
    // We want to be able to say stu1 = stu2 multiple times throughout the document
    set_firstName(student.get_firstName());
    set_lastName(student.get_lastName());
    set_CGPA(student.get_CGPA());
    set_researchScore(student.get_researchScore());
    set_province(student.get_province());
    set_appID(student.get_appID());

    return *this;
}

// DomesticStudent--------------------------------------





// InternationalStudent----------------------------------

// Default constructor
InternationalStudent::InternationalStudent() {
    country = "NULL";
}

InternationalStudent::InternationalStudent(const InternationalStudent& student) {

    set_firstName(student.get_firstName());
    set_lastName(student.get_lastName());
    set_CGPA(student.get_CGPA());
    set_researchScore(student.get_researchScore());
    set_country(student.get_country());
    set_appID(student.get_appID());
    set_ToeflListening(student.get_ToeflListening());
    set_ToeflReading(student.get_ToeflReading());
    set_ToeflSpeaking(student.get_ToeflSpeaking());
    set_ToeflWriting(student.get_ToeflWriting());
} 

InternationalStudent::InternationalStudent(const InternationalStudent* student) {

    set_firstName(student->get_firstName());
    set_lastName(student->get_lastName());
    set_CGPA(student->get_CGPA());
    set_researchScore(student->get_researchScore());
    set_country(student->get_country());
    set_appID(student->get_appID());
    set_ToeflListening(student->get_ToeflListening());
    set_ToeflReading(student->get_ToeflReading());
    set_ToeflSpeaking(student->get_ToeflSpeaking());
    set_ToeflWriting(student->get_ToeflWriting());
}

// Getter
string InternationalStudent::get_country() const {
    return country;
}

int InternationalStudent::get_ToeflReading() const {
    return toeflScore.get_reading();
}

int InternationalStudent::get_ToeflListening() const {
    return toeflScore.get_listening();
}

int InternationalStudent::get_ToeflSpeaking() const {
    return toeflScore.get_speaking();
}

int InternationalStudent::get_ToeflWriting() const {
    return toeflScore.get_writing();
}

int InternationalStudent::get_ToeflTotal() const {
    return toeflScore.get_total();
}

ToeflScore InternationalStudent::get_ToeflScore() const {
    return this->toeflScore;
}

// Setter
void InternationalStudent::set_country(string country) {
    // Changes the first letter from lowercase to uppercase
    if (country[0] >= 97 && country[0] <= 122) {
        country[0] = country[0] - 32;
    }

    // Changes every other letter from uppercase to lowercase
    for (int i = 1; i <= country.length(); i++) {
        if (country[i] >= 65 && country[i] <= 90) {
            country[i] = country[i] + 32;
        }
    }
    
    try {
    this->country = country;
        if (country == "Idian") {
            throw country;
        }else if (country == " ") {
            bool input = false;
            throw input;
        }
        else if (country != "Canada" && country != "China" && country != "India" && country != "Iran" && country != "Korea") {
            bool input = false;
            throw input;
        }
        
    }
    catch (string e) {
        e = "India";
        this->country = e;
    }
    catch (bool e) {
        cout << "Invalid country!" << endl;
        exit(1);
    }
}


// Note that for each setter from here on we use the update_total() function, so that 
//      every time a ToeflScore is altered, the total score will also change
void InternationalStudent::set_ToeflReading(int reading) {
    try {
        if (reading == 0) {
            throw reading;
        }
        toeflScore.set_reading(reading);
    } 
        catch (int e) {
            cout << "Please enter a TOEFL reading score" << endl;
            exit(1);
        }
}

void InternationalStudent::set_ToeflListening(int listening) {
    try {
        if (listening == 0) {
            throw listening;
        }
        toeflScore.set_listening(listening);
        toeflScore.update_total();
    }
        catch (int e) {
            cout << "Please enter a TOEFL listening score" << endl;
            exit(1);
        }
    
}

void InternationalStudent::set_ToeflSpeaking(int speaking) {
    try {
        if (speaking == 0) {
            throw speaking;
        }
        toeflScore.set_speaking(speaking);
        toeflScore.update_total();
    }
        catch (int e) {
            cout << "Please enter a TOEFL speaking score" << endl;
            exit(1);
        }
}

void InternationalStudent::set_ToeflWriting(int writing) {
    try {
        if (writing == 0) {
            throw writing;
        }
        toeflScore.set_writing(writing);
        toeflScore.update_total();
    }
        catch (int e) {
            cout << "Please enter a TOEFL writing score" << endl;
            exit(1);
        }
}

void InternationalStudent::set_ToeflTotal() {
    toeflScore.update_total();
}

// Comparing function that is specific to InternationalStudent
int compareCountry(const InternationalStudent& stu1, const InternationalStudent& stu2) {
    
    int strLength1 = stu1.country.size();
    int strLength2 = stu2.country.size();
    int minLength;
    
    // Setting the min length to the length of the shortest string
    if (strLength1 <= strLength2) {
        minLength = strLength1;
    }
    else {
        minLength = strLength2;
    }

    // Only loops until we have fully traversed the shortest string
    for (int i = 0; i < minLength; i++) {
        // returns 1 if student2's first name comes alphabetically before student1's last name 
        if (stu1.country[i] > stu2.country[i]) {
            return 0;
        }
        // returns 2 if student1's first name comes alphabetically before student2's last name 
        else if (stu1.country[i] < stu2.country[i]) {
            return 2;
        }
    }
    // If the for loop does not detect any difference:
    if (strLength1 <= strLength2) {
        return 2;
    } else if (strLength1 > strLength2) {
        return 0;
    }
    return -1;
}

// Overloaded Operators

ostream& operator <<(ostream& outs, InternationalStudent& student) {
    outs << student.get_firstName() << ", " << student.get_lastName() << ", " << student.get_country() << ", "
    << fixed << setprecision(1) << student.get_CGPA() << ", " << student.get_researchScore() << ", " << student.toeflScore << endl;

    return outs;
}

InternationalStudent& InternationalStudent::operator =(const InternationalStudent& student) {

    set_firstName(student.get_firstName());
    set_lastName(student.get_lastName());
    set_CGPA(student.get_CGPA());
    set_researchScore(student.get_researchScore());
    set_country(student.get_country());

    // Note that this overload differs from the one before, in that we must now update 
    //      the ToeflScores as well as the InternationalStudent member variables
    set_ToeflReading(student.get_ToeflReading());
    set_ToeflListening(student.get_ToeflListening());
    set_ToeflSpeaking(student.get_ToeflSpeaking());
    set_ToeflWriting(student.get_ToeflWriting());

    return *this;
}

bool operator ==(const InternationalStudent& stu1, const InternationalStudent& stu2) {

    // If all of these conditions are met, return true
    if (stu1.get_firstName() == stu2.get_firstName() 
        && stu1.get_lastName() == stu2.get_lastName() 
        && stu1.get_CGPA() == stu2.get_CGPA() 
        && stu1.get_researchScore() == stu2.get_researchScore()
        && stu1.get_country() == stu2.get_country() 
        && stu1.get_ToeflReading() == stu2.get_ToeflReading()
        && stu1.get_ToeflListening() == stu2.get_ToeflListening() 
        && stu1.get_ToeflSpeaking() == stu2.get_ToeflSpeaking()
        && stu1.get_ToeflWriting() == stu2.get_ToeflWriting()) 
    {
        return true;
    }

    // Otherwise, return false
    return false;
}



// InternationalStudent----------------------------------

