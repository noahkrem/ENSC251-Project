
// Stops us from defining our files more than once
#pragma once
#include <string>
#include <iostream>
#include "student.hpp"
#include "stu_sort.hpp"
using namespace std;


class List {

    Student* head;
    Student* tail;

    bool is_InternationalStudent(Student* student);

    Student* insertHelper(Student* student);

public:
    List();

    List(const List& list);
    
    ~List();

    Student* get_head() const;
    Student** get_headPtr();
    Student* get_tail() const;

    int listSize();

    void insertStudent(DomesticStudent* student);
    void insertStudent(InternationalStudent* student);

    void deleteStudent(string firstName, string lastName);

    void deleteEnds();

    void printStudent(Student* student);

    void printList();

    Student new_Node(Student Student);

    // Search Functions
    void search_CGPA(float CGPA);
    void search_researchScore(int researchScore);
    void search_appID(int appID);
    void search_name(string firstName, string lastName);



    // Functions for merged list

    friend List mergeList(const List& list1, const List& list2);

    void print_threshold(int researchScore_threshold, double CPGA_threshold);
};
