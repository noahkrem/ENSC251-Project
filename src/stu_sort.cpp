//stu_sort.cpp to implement your sorting functions
#include <iostream>
#include "stu_sort.hpp"


// Sorting functions

Student* SortedMerge(Student* a, Student* b) {

    Student* result = NULL;

    // Base cases
    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }

    // Pick either a or b and call function recursively
    if (compareResearchScore(a, b) == 2) {
        result = a;
        result->next = SortedMerge(a->next, b);
    } else if (compareResearchScore(a, b) == 1) {
        if (compareCGPA(a, b) == 2 || compareCGPA(a, b) == 1) {
            result = a; 
            result->next = SortedMerge(a->next, b);

        } else {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
    } else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

// Split the list into two halves... If the length is odd, the extra node will go in the first list
void FrontBackSplit(Student* source, Student** frontRef, Student** backRef) {

    Student* fast;
    Student* slow;
    slow = source;
    fast = source->next;

    // Advance 'fast' two nodes, and advance 'slow' one node
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Now "slow" is at the midpoint or one before it
    // Split in two at that point
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void MergeSort(Student** headRef) {

    Student* head = *headRef;
    Student* a;
    Student* b;

    // Base case: if the list is empty, or only has one node
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    // Split head into two sublists, a and b
    FrontBackSplit(head, &a, &b);

    // Recursively sort sublists
    MergeSort(&a);
    MergeSort(&b);
    
    // Once sorted, merge the sublists
    *headRef = SortedMerge(a, b);
}

bool valid_Toefl(InternationalStudent* student) {

    if (student->get_ToeflReading() < 20 || student->get_ToeflListening() < 20 || student->get_ToeflSpeaking() < 20 || student->get_ToeflWriting() < 20) {
        return false;
    } else if (student->get_ToeflTotal() < 93) {
        return false;
    }
    
    return true;
}

// CIN Error Checker

void ignoreLine() {
    cin.clear();
    cin.ignore();
}



