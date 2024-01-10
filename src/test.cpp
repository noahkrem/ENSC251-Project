
//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <cctype> 
#include "student.hpp"
#include "stu_sort.hpp"
#include "list.hpp"

// Uncomment the illegal cases one by one before testing them because they exit the program when called


// Max number of students for interim project 

void testCases(List domesticList, List internationalList) {

  internationalList.printList();

  

cout << "Testing search based on application ID" << endl << endl;

  // Search based on application ID

  //Normal cases:
  cout << "Normal cases: " << endl << endl;
  domesticList.search_appID(20220050);
  domesticList.search_appID(20220075);
  // cout << endl;

  // Boundary cases:
  cout << "Boundary cases: " << endl;
  domesticList.search_appID(20220000);
  domesticList.search_appID(20220099);
  // cout << endl;

  // Illegal cases:
  // cout << "Illegal cases: " << endl << endl;
  // domesticList.search_appID(-5);
  // cout << endl;

  cout << endl << endl << "Testing search based on CGPA" << endl << endl;

  // Search based on CGPA

  // Normal cases:
  cout << "Normal cases: " << endl << endl;
  domesticList.search_CGPA(3);
  domesticList.search_CGPA(3.55);
  // cout << endl;

  // Boundary cases:
  cout << "Boundary cases: " << endl << endl;
  domesticList.search_CGPA(4.33);
  domesticList.search_CGPA(2.8);
  // cout << endl;


  // Illegal cases:
  // cout << "Illegal cases: " << endl << endl;
  // domesticList.search_CGPA(-1);

  cout << endl << endl << "Testing search based on research score" << endl << endl;
  // Search based on research score

  // Normal cases
  cout << "Normal cases: " << endl << endl;
  domesticList.search_researchScore(80);
  domesticList.search_researchScore(90);
  // cout << endl;

  // Boundary cases
  cout << "Boundary cases: " << endl << endl;
  domesticList.search_researchScore(100);
  domesticList.search_researchScore(70);
  // cout << endl;

  // illegal cases
  // cout << "Illegal cases: " << endl << endl;
  // domesticList.search_researchScore(-1);
  // cout << endl;

  cout << endl << endl << "Testing search based on name" << endl << endl;
  // Search based on name

  // Normal cases:
  cout << "Normal cases: " << endl << endl;
  domesticList.search_name("Zoey","Wood");
  domesticList.search_name("Abigail","Bailey");
  cout << endl;

  //Boundary cases:
  cout << "Boundary cases: " << endl << endl;
  domesticList.search_name("Mary", "White");
  domesticList.search_name("Claire", "Griffin");
  cout << endl;

  //Illegal cases:
  cout << "Illegal cases: " << endl << endl;
  domesticList.search_name("312313","2130981");
  cout << endl;


  cout << endl << endl << "Testing delete based on name" << endl << endl;
  // Deleting names from the list

  cout << "Original List" << endl;
  domesticList.printList();
  cout << endl << endl;

  // Normal cases:
  cout << "Normal cases: " << endl << endl;
  domesticList.deleteStudent("Zoey","Wood");
  domesticList.deleteStudent("Abigail","Bailey");
  cout << endl;

  // Boundary cases:
  cout << "Boundary cases: " << endl << endl;
  domesticList.deleteStudent("Christian", "Pulisic");
  domesticList.deleteStudent("Emily", "Rivera");
  cout << endl;

  // Illegal cases:
  cout << "Illegal cases: " << endl << endl;
  domesticList.deleteStudent("312313","2130981");
  cout << endl;

  cout << "List with deleted students" << endl;
  domesticList.printList();

  cout << endl << endl << "Deleting both the head and tail node in a single function" << endl << endl;
  
  cout << "Original List" << endl;
  domesticList.printList();

  domesticList.deleteEnds();

  cout << endl << "List with head and tail deleted" << endl;
  domesticList.printList();

  cout << endl << endl << "Merging the sorted DomesticStudent list and InternationalStudent list" << endl << endl;
  List newList = mergeList(domesticList, internationalList);
  newList.printList();

  cout << endl << endl << "Searching the merged list based on CGPA and research score" << endl << endl;
  
  // Normal cases:
  cout << "Normal cases: " << endl << endl;
  newList.search_CGPA(3.4);
  newList.search_researchScore(80);
  cout << endl;

  // Boundary cases:
  cout << "Boundary cases: " << endl << endl;
  newList.search_researchScore(70);
  newList.search_researchScore(100);
  newList.search_CGPA(2.80);
  newList.search_CGPA(4.33);
  cout << endl;

  // Illegal cases:
  cout << "Illegal cases: " << endl << endl;
  newList.search_researchScore(-5);
  newList.search_researchScore(101);
  newList.search_CGPA(5);
  newList.search_CGPA(-5);


  return;
} 
