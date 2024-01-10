
/* TO-DO LIST:
Part 3 (3.5 marks, each item 0.5):
  1.
  2.
  3.
  4.
  5.
  6.
  7.
Part 4 (1.5 marks)
Part 5 (5 marks):
  - We have included sorting upon insertion, which is of time complexity O(n) (worst-case scenario).
    This is better than the alternative of inserting and then sorting every time,
    which has a time complexity of no better than O(nlogn).
  - To merge our lists, we first append one list to the other, then sort only once using merge sort.
    This has a time complexity of O(nlogn)
  - Checks for valid Toefl score before anything else in the insert function, increasing efficiency.
    If the score is invalid, we simply ignore the given student.
  - Merged list can perform the same tasks as the domestic and international list, as well as the
    extra capability given in the project outline
Part 6 (5 marks)
*/


#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cctype> 
#include "student.hpp"
#include "stu_sort.hpp"
#include "list.hpp"
#include "test.hpp"


// Max number of students for interim project 

int main() {
  
  List domesticList;
  DomesticStudent temp_domesticStudent;

  List internationalList;
  InternationalStudent temp_internationalStudent;

  // Reading domestic-stu.txt file-----------------------------

  string line1;
  ifstream domesticFile("domestic-stu.txt");

  // Error check
  if (!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }

  // Read the first line of domestic-stu.txt, which specifies
  // the file format, and then print it out to the screen
  getline(domesticFile, line1);
  cout << "\nFile format: " << line1 << endl << endl;

  // Increases every time the loop iterates
  int stu_count1 = 0;

  // Loops until the end of the file
  while(getline(domesticFile, line1)) {

    istringstream ss(line1);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    stu_count1++;

    // Get firstName separated by comma
    getline(ss, firstName, ',');
    temp_domesticStudent.set_firstName(firstName);

    // Get lastName separated by comma
    getline(ss, lastName, ',');
    temp_domesticStudent.set_lastName(lastName);

    // Get province separated by comma
    getline(ss, province, ',');
    temp_domesticStudent.set_province(province);

    // Get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    temp_domesticStudent.set_CGPA(cgpa);
    
    // Get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    temp_domesticStudent.set_researchScore(researchScore);

    // Give the student a unique student ID
    temp_domesticStudent.set_appID();

    // Insert the domestic student into the list
    DomesticStudent* temp_ptr = new DomesticStudent(temp_domesticStudent);
    domesticList.insertStudent(temp_ptr);
    delete temp_ptr;
  
  }

  // Closes the file
  domesticFile.close();

// Reading domestic-stu.txt file-----------------------------





// Reading international-stu.txt file------------------------


  string line2;
  ifstream internationalFile("international-stu.txt");

  // Error check
  if (!internationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }

  // Read the first line of domestic-stu.txt, which specifies
  // the file format, and then print it out to the screen
  getline(internationalFile, line2);
  cout << "File format: " << line2 << endl << endl;

  // Increases every time the loop iterates
  int stu_count2 = 0;

  // Loops until the end of the file
  while(getline(internationalFile, line2)) {

    istringstream ss(line2);

    string firstName2, lastName2, country, s_cgpa2, s_researchScore2, s_reading, s_listening, s_speaking, s_writing;
    float cgpa2;
    int researchScore2, reading, listening, speaking, writing;

    stu_count2++;

    // Get firstName separated by comma
    getline(ss, firstName2, ',');
    temp_internationalStudent.set_firstName(firstName2);

    // Get lastName separated by comma
    getline(ss, lastName2, ',');
    temp_internationalStudent.set_lastName(lastName2);

    // Get province separated by comma
    getline(ss, country, ',');
    temp_internationalStudent.set_country(country);

    // Get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa2, ',');
    cgpa2 = atof(s_cgpa2.c_str());
    temp_internationalStudent.set_CGPA(cgpa2);
    
    // Get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore2, ',');
    researchScore2 = atoi(s_researchScore2.c_str());
    temp_internationalStudent.set_researchScore(researchScore2);

    // Get reading score separated by comma, and convert it to int
    getline(ss, s_reading, ',');
    reading = atoi(s_reading.c_str());
    temp_internationalStudent.set_ToeflReading(reading);

    // Get listening score separated by comma, and convert it to int
    getline(ss, s_listening, ',');
    listening = atoi(s_listening.c_str());
    temp_internationalStudent.set_ToeflListening(listening);

    // Get speaking score separated by comma, and convert it to int
    getline(ss, s_speaking, ',');
    speaking = atoi(s_speaking.c_str());
    temp_internationalStudent.set_ToeflSpeaking(speaking);
    
    // Get writing separated by comma, and convert it to int
    getline(ss, s_writing, ',');
    writing = atoi(s_writing.c_str());
    temp_internationalStudent.set_ToeflWriting(writing);

    // Give each student a unique ID number
    temp_internationalStudent.set_appID();

    // Insert the domestic student into the list
    internationalList.insertStudent(&temp_internationalStudent);

  } 

  // Closes the file
  internationalFile.close();

  // Reading international-stu.txt file------------------------





  // Initializing user input variables
  int userchoice1;
  int userchoice2;
  int exit;
  
  // Initial error check to exit program
  while(userchoice1 != 5 && userchoice2 != exit) {

    exit = 0;
    userchoice1 = 0;
    userchoice2 = 0;

    cout << "\nStudent Information Menu:\n" << endl;
    cout << "1 -> Navigate to Domestic Student menu" << endl;
    cout << "2 -> Navigate to International Student menu" << endl;
    cout << "3 -> Navigate to All Students menu" << endl;
    cout << "4 -> Navigate to Unit Testing" << endl;
    cout << "5 -> Exit Program" << endl;
    cin >> userchoice1;

    // Error check to make sure the user enters a digit, if not, user is prompted to try again
    while (cin.fail()) {
      ignoreLine();
      cout << "Invalid input, must be a digit from 1 to 5. Try again:" << endl;
      cin >> userchoice1;
    }

    // Checks the bounds of the user input
    while (userchoice1 > 5 || userchoice1 <= 0) {
      ignoreLine();
      cout << "Invalid input, must be a digit from 1 to 5. Try again:" << endl;
      cin >> userchoice1;
    }



    // Start Of Domestic Student Menu-----------------------------------

    // If the user enters 1, they are taken to the domestic student menu
    if (userchoice1 == 1) {
      
      cout << "\nDomestic Student Information Menu:\n" << endl;
      cout << "1 -> Search the existing list by Application ID" << endl;
      cout << "2 -> Search the existing list by CGPA" << endl;
      cout << "3 -> Search the existing list by Research Score" << endl;
      cout << "4 -> Search the existing list by Name" << endl;
      cout << "5 -> Create a new Domestic Student" << endl;
      cout << "6 -> Delete existing Domestic Student" << endl;
      cout << "7 -> Delete the head and the tail of the list" << endl;
      cout << "8 -> Exit Program" << endl;
      cin >> userchoice2; cout << "\n";
      exit = 8;

      // Error check to make sure the user enters a digit, if not, user is prompted to try again
      while (cin.fail()) {
        ignoreLine();
        cout << "Invalid input, must be a digit from 1 to 8. Try again:" << endl;
        cin >> userchoice2;
      }
      
      // Checks the bounds of the user input
      while (userchoice2 > 8 || userchoice2 <= 0) {
        ignoreLine();
        cout << "Invalid input, must be a digit from 1 to 8. Try again:" << endl;
        cin >> userchoice2;
      }

      if (userchoice2 == 1) {
        int appID;
        cout << "Enter application ID: ";
        cin >> appID;
        domesticList.search_appID(appID);
      } else if (userchoice2 == 2) {
        double CGPA;
        cout << "Enter CGPA: ";
        cin >> CGPA;
        domesticList.search_CGPA(CGPA);
      } else if (userchoice2 == 3) {
        int researchScore;
        cout << "Enter Research Score: ";
        cin >> researchScore;
        domesticList.search_researchScore(researchScore);
      } else if (userchoice2 == 4) {
        string firstName, lastName;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        domesticList.search_name(firstName, lastName);
      } else if (userchoice2 == 5) {

        DomesticStudent newStudent;
        double CGPA;
        int researchScore;
        string firstName, lastName, province;

        cout << "Enter new CGPA: "; 
        cin >> CGPA;
        newStudent.set_CGPA(CGPA);
        cout << "Enter new Research Score: "; 
        cin >> researchScore;
        newStudent.set_researchScore(researchScore);
        cout << "Enter new First Name: ";
        cin >> firstName;
        newStudent.set_firstName(firstName);
        cout << "Enter new Last Name: ";
        cin >> lastName;
        newStudent.set_lastName(lastName);
        cout << "Enter new Province: ";
        cin >> province;
        newStudent.set_province(province);

        newStudent.set_appID();

        domesticList.insertStudent(&newStudent);
        cout << firstName << ", " << lastName << " has been inserted" << endl;

      } else if (userchoice2 == 6) {
        string firstName, lastName;
        cout << "Enter First Name of student to be deleted: ";
        cin >> firstName;
        cout << "Enter Last Name of student to be deleted: ";
        cin >> lastName;
        domesticList.deleteStudent(firstName, lastName);
      } else if (userchoice2 == 7) {
        domesticList.deleteEnds();
        cout << "Head and Tail of the list have been deleted" << endl;
      }
    }

    // End Of Domestic Student Menu-----------------------------------



    // Start Of International Student Menu-----------------------------------

    // If the user enters 2, they are taken to the international student menu
    else if (userchoice1 == 2) {

      cout << "\nInternational Student Information Menu:\n" << endl;
      cout << "1 -> Search the existing list by Application ID" << endl;
      cout << "2 -> Search the existing list by CGPA" << endl;
      cout << "3 -> Search the existing list by Research Score" << endl;
      cout << "4 -> Search the existing list by Name" << endl;
      cout << "5 -> Create a new International Student" << endl;
      cout << "6 -> Delete existing International Student" << endl;
      cout << "7 -> Delete the head and the tail of the list" << endl;
      cout << "8 -> Exit Program" << endl;
      cin >> userchoice2; cout << "\n";
      exit = 8;

      // Error check to make sure the user enters a digit, if not, user is prompted to try again
      while (cin.fail()) {
        ignoreLine();
        cout << "Invalid input, must be a digit from 1 to 8. Try again:" << endl;
        cin >> userchoice2;
      }
      
      // Checks the bounds of the user input
      while (userchoice2 > 8 || userchoice2 <= 0) {
        ignoreLine();
        cout << "Invalid input, must be a digit from 1 to 8. Try again:" << endl;
        cin >> userchoice2;
      }

      if (userchoice2 == 1) {
        int appID;
        cout << "Enter application ID: ";
        cin >> appID;
        internationalList.search_appID(appID);
      } else if (userchoice2 == 2) {
        double CGPA;
        cout << "Enter CGPA: ";
        cin >> CGPA;
        internationalList.search_CGPA(CGPA);
      } else if (userchoice2 == 3) {
        int researchScore;
        cout << "Enter Research Score: ";
        cin >> researchScore;
        internationalList.search_researchScore(researchScore);
      } else if (userchoice2 == 4) {
        string firstName, lastName;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        internationalList.search_name(firstName, lastName);
      } else if (userchoice2 == 5) {
        
        InternationalStudent newStudent;
        double CGPA;
        int researchScore;
        string firstName, lastName, country;
        int reading, listening, speaking, writing;

        cout << "Enter new CGPA: "; 
        cin >> CGPA;
        newStudent.set_CGPA(CGPA);
        cout << "Enter new Research Score: "; 
        cin >> researchScore;
        newStudent.set_researchScore(researchScore);
        cout << "Enter new First Name: ";
        cin >> firstName;
        newStudent.set_firstName(firstName);
        cout << "Enter new Last Name: ";
        cin >> lastName;
        newStudent.set_lastName(lastName);
        cout << "Enter new Country: ";
        cin >> country;
        newStudent.set_country(country);
        cout << "Enter new Toefl Reading Score: ";
        cin >> reading;
        newStudent.set_ToeflReading(reading);
        cout << "Enter new Toefl Listening Score: ";
        cin >> listening;
        newStudent.set_ToeflListening(listening);
        cout << "Enter new Toefl Speaking Score: ";
        cin >> speaking;
        newStudent.set_ToeflSpeaking(speaking);
        cout << "Enter new Toefl Writing Score: ";
        cin >> writing;
        newStudent.set_ToeflWriting(writing);

        newStudent.set_appID();

        internationalList.insertStudent(&newStudent);
        if (!valid_Toefl(&newStudent)) {
          cout << "Error: Toefl Score is not sufficient" << endl;
        } else {
          cout << firstName << ", " << lastName << " has been inserted" << endl;
        }

      } else if (userchoice2 == 6) {
        string firstName, lastName;
        cout << "Enter First Name of student to be deleted: ";
        cin >> firstName;
        cout << "Enter Last Name of student to be deleted: ";
        cin >> lastName;
        internationalList.deleteStudent(firstName, lastName);
      } else if (userchoice2 == 7) {
        internationalList.deleteEnds();
        cout << "Head and Tail of the list have been deleted" << endl;
      }
    }
    // End Of International Student Menu-----------------------------------



    // Start Of All Students Student Menu-----------------------------------

    // If the user enters 3, they are taken to the all students menu
    else if (userchoice1 == 3) {

      exit = 10;
      List mergedList = mergeList(domesticList, internationalList);

      while (userchoice2 != exit) {
        cout << "\nAll Students Information Menu:\n" << endl;
        cout << "1 -> Search the existing list by Application ID" << endl;
        cout << "2 -> Search the existing list by CGPA" << endl;
        cout << "3 -> Search the existing list by Research Score" << endl;
        cout << "4 -> Search the existing list by Name" << endl;
        cout << "5 -> Search the existing list by Threshold" << endl;
        cout << "6 -> Create a new Domestic Student" << endl;
        cout << "7 -> Create a new International Student" << endl;
        cout << "8 -> Delete existing Student" << endl;
        cout << "9 -> Delete the head and the tail of the list" << endl;
        cout << "10 -> Exit Program" << endl;
        cin >> userchoice2; cout << "\n";

        // Error check to make sure the user enters a digit, if not, user is prompted to try again
        while (cin.fail()) {
          ignoreLine();
          cout << "Invalid input, must be a digit from 1 to 10. Try again:" << endl;
          cin >> userchoice2;
        }
        
        // Checks the bounds of the user input
        while (userchoice2 > 10 || userchoice2 <= 0) {
          ignoreLine();
          cout << "Invalid input, must be a digit from 1 to 10. Try again:" << endl;
          cin >> userchoice2;
        }

        if (userchoice2 == 1) {
          int appID;
          cout << "Enter application ID: ";
          cin >> appID;
          mergedList.search_appID(appID);
        } else if (userchoice2 == 2) {
          double CGPA;
          cout << "Enter CGPA: ";
          cin >> CGPA;
          mergedList.search_CGPA(CGPA);
        } else if (userchoice2 == 3) {
          int researchScore;
          cout << "Enter Research Score: ";
          cin >> researchScore;
          mergedList.search_researchScore(researchScore);
        } else if (userchoice2 == 4) {
          string firstName, lastName;
          cout << "Enter First Name: ";
          cin >> firstName;
          cout << "Enter Last Name: ";
          cin >> lastName;
          mergedList.search_name(firstName, lastName);
        } else if (userchoice2 == 5) {
          double CGPA_threshold;
          int researchScore_threshold;
          cout << "Enter CGPA Threshold: " << endl;
          cin >> CGPA_threshold;
          cout << "Enter Research Score Threshold: " << endl;
          cin >> researchScore_threshold;
          mergedList.print_threshold(researchScore_threshold, CGPA_threshold);
        } else if (userchoice2 == 6) {

          DomesticStudent newStudent;
          double CGPA;
          int researchScore;
          string firstName, lastName, province;

          cout << "Enter new CGPA: "; 
          cin >> CGPA;
          newStudent.set_CGPA(CGPA);
          cout << "Enter new Research Score: "; 
          cin >> researchScore;
          newStudent.set_researchScore(researchScore);
          cout << "Enter new First Name: ";
          cin >> firstName;
          newStudent.set_firstName(firstName);
          cout << "Enter new Last Name: ";
          cin >> lastName;
          newStudent.set_lastName(lastName);
          cout << "Enter new Province: ";
          cin >> province;
          newStudent.set_province(province);

          newStudent.set_appID();

          mergedList.insertStudent(&newStudent);
          cout << firstName << ", " << lastName << " has been inserted" << endl;

        } else if (userchoice2 == 7) {
          
          InternationalStudent newStudent;
          double CGPA;
          int researchScore;
          string firstName, lastName, country;
          int reading, listening, speaking, writing;

          cout << "Enter new CGPA: "; 
          cin >> CGPA;
          newStudent.set_CGPA(CGPA);
          cout << "Enter new Research Score: "; 
          cin >> researchScore;
          newStudent.set_researchScore(researchScore);
          cout << "Enter new First Name: ";
          cin >> firstName;
          newStudent.set_firstName(firstName);
          cout << "Enter new Last Name: ";
          cin >> lastName;
          newStudent.set_lastName(lastName);
          cout << "Enter new Country: ";
          cin >> country;
          newStudent.set_country(country);
          cout << "Enter new Toefl Reading Score: ";
          cin >> reading;
          newStudent.set_ToeflReading(reading);
          cout << "Enter new Toefl Listening Score: ";
          cin >> listening;
          newStudent.set_ToeflListening(listening);
          cout << "Enter new Toefl Speaking Score: ";
          cin >> speaking;
          newStudent.set_ToeflSpeaking(speaking);
          cout << "Enter new Toefl Writing Score: ";
          cin >> writing;
          newStudent.set_ToeflWriting(writing);

          newStudent.set_appID();

          mergedList.insertStudent(&newStudent);
          if (!valid_Toefl(&newStudent)) {
            cout << "Error: Toefl Score is not sufficient" << endl;
          } else {
            cout << firstName << ", " << lastName << " has been inserted" << endl;
          }

        } else if (userchoice2 == 8) {
          string firstName, lastName;
          cout << "Enter First Name of student to be deleted: ";
          cin >> firstName;
          cout << "Enter Last Name of student to be deleted: ";
          cin >> lastName;
          mergedList.deleteStudent(firstName, lastName);
        } else if (userchoice2 == 9) {
          mergedList.deleteEnds();
          cout << "Head and Tail of the list have been deleted" << endl;
        } else if (userchoice2 == 10) {
          return 0;
        }

      }

    }
    // End Of All Students Student Menu-----------------------------------



    // Unit Testing------------------------------------------------------

    // If the user enters 4, they are taken to the all students menu
    else if (userchoice1 == 4) {

      cout << "\nUnit Test:\n" << endl;
      testCases(domesticList, internationalList);

    }

  } 

  return 0;
}

