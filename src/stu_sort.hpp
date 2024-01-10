#pragma once
#include <string> //you will have to use string in C++
#include "student.hpp"
#include "list.hpp"


// Sorting Functions

Student* SortedMerge(Student* a, Student* b);

void FrontBackSplit(Student* source, Student** frontRef, Student** backRef);

void MergeSort(Student** headRef);

// ToeflScore Checker

bool valid_Toefl(InternationalStudent* student);

// CIN Error Checker

void ignoreLine();
