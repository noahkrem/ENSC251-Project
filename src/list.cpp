
#include <string>
#include <iostream>
#include <iomanip>
#include "list.hpp"
using namespace std;



// DOMESTIC LIST-------------------------------------------------------

// PRIVATE---------------------------


bool List::is_InternationalStudent(Student* student) {

    if (student->get_ToeflTotal() != 0) {
        return true;
    }
    return false;
}

Student* List::insertHelper(Student* student) {

    StudentPtr temp = head;

    if (!is_InternationalStudent(student)) {



        // If we have a new head, we return NULL
        if (compareResearchScore(student, head) == 2) {
            return NULL;
        } else if (compareResearchScore(student, head) == 1) {

            if (compareCGPA(student, head) == 2) {
            return NULL;
            } else if (compareCGPA(student, head) == 1) {

                if (compareProvince(student, head) == 2) {
                        return NULL;
                } else if (compareProvince(student, temp->next) == 1) {
                        // If every value is the same, insert at head->next
                        return head;
                }
            }
        }

        // Once we have confirmed that our new node will not be the head, we continue the program:
        while (temp != tail) {

            if (compareResearchScore(student, temp->next) == 0) {
                temp = temp->next;
            } else if (compareResearchScore(student, temp->next) == 1) {

                if (compareCGPA(student, temp->next) == 0) {
                    temp = temp->next;
                } else if (compareCGPA(student, temp->next) == 1) {

                    if (compareProvince(student, temp->next) == 0) {
                        temp = temp->next;
                    } else if (compareProvince(student, temp->next) == 2) {
                        return temp;
                    } else {
                        temp = temp->next;
                    }

                } else {
                    return temp;
                }

            } else {
                return temp;
            }
        }
        return tail;


    } else {



        // If we have a new head, we return NULL
        if (compareResearchScore(student, head) == 2) {
            return NULL;
        } else if (compareResearchScore(student, head) == 1) {

            if (compareCGPA(student, head) == 2) {
            return NULL;
            } else if (compareCGPA(student, head) == 1) {

                if (compareCountry(student, head) == 2) {
                        return NULL;
                } else if (compareCountry(student, temp->next) == 1) {
                        // If every value is the same, insert at head->next
                        return head;
                }
            }
        }

        // Once we have confirmed that our new node will not be the head, we continue the program:
        while (temp != tail) {

            if (compareResearchScore(student, temp->next) == 0) {
                temp = temp->next;
            } else if (compareResearchScore(student, temp->next) == 1) {

                if (compareCGPA(student, temp->next) == 0) {
                    temp = temp->next;
                } else if (compareCGPA(student, temp->next) == 1) {

                    if (compareCountry(student, temp->next) == 0) {
                        temp = temp->next;
                    } else if (compareCountry(student, temp->next) == 2) {
                        return temp;
                    } else {
                        temp = temp->next;
                    }

                } else {
                    return temp;
                }

            } else {
                return temp;
            }
        }
        return tail;

    }
}

// PRIVATE------------------------





// PUBLIC-------------------------

List::List() {
    head = NULL;
    tail = NULL;
}

List::List(const List& list) {
    head = list.get_head();
    tail = list.get_tail();
}

List::~List() {   
    
    Student* current = get_head();
    Student* temp = NULL;

    while (current != NULL) {
        temp = current->next;
        current->next = NULL;
        delete current;
        current = temp;
    }
}

Student* List::get_head() const {
    return head;
}

Student** List::get_headPtr() {
    return &head;
}

Student* List::get_tail() const {
    return tail;
}

int List::listSize() {

    Student* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void List::insertStudent(DomesticStudent* student) {
    
    StudentPtr temp;
    
    try {
        temp = new DomesticStudent(student);


        if (head == NULL) {
            head = temp;
            tail = temp;
            return;
        }

        StudentPtr after_me = insertHelper(student);

        if (after_me == NULL) {
            temp->next = head;
            head = temp;
            return;
        }

        if (after_me == tail) {
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
            return;
        }

        temp->next = after_me->next;
        after_me->next = temp;

    }


    catch(bad_alloc) {
        cout << "Error: ran out of memory" << endl;
    }
}

void List::insertStudent(InternationalStudent* student) {
    
    // If invalid toefl, end function without continuing
    if (!valid_Toefl(student)) {
        return;
    }
    
    StudentPtr temp;
    try {
        temp = new InternationalStudent(student);

        if (head == NULL) {
            head = temp;
            tail = temp;
            return;
        }

        StudentPtr after_me = insertHelper(student);

        if (after_me == NULL) {
            temp->next = head;
            head = temp;
            return;
        }

        if (after_me == tail) {
            tail->next = temp;
            tail = temp;
            tail->next = nullptr;
            return;
        }

        temp->next = after_me->next;
        after_me->next = temp;
        }

    catch(bad_alloc) {
        cout << "Error: ran out of memory" << endl;
    }
}

void List::deleteStudent(string firstName, string lastName) {
    
    bool found = false;

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

    Student* current = head->next;
    Student* before = head;

    while ((current->next != NULL)) {

        // Special case: delete head node
        if ((before->get_firstName() == firstName) && (before->get_lastName() == lastName)) {
            Student* discard = head;
            head = head->next;
            before = before->next;
            current = current->next;
            discard->next = NULL;
            delete discard;
            cout << firstName << ", " << lastName << " has been deleted." << endl;
            found = true;

        } else {

            if ((current->get_firstName() == firstName) && (current->get_lastName() == lastName)) {
                
                // We have found the name
                found = true;

                // Create a new variable to be deleted, so that we can continue to traverse the loop once deleted
                try {
                    Student* temp = current;
                    before->next = current->next;
                    current = current->next->next;
                    temp->next = NULL;
                    delete temp;

                    // We have successfully deleted the student
                    cout << firstName << ", " << lastName << " has been deleted. " << endl;
                }
                catch (bad_alloc) {
                    cout << "Error: ran out of memory." << endl;
                    exit(1);
                }

            } else {
                before = before->next;
                current = current->next;
            }
        }

    }  
    
   // Special case: delete tail node
    if ((tail->get_firstName() == firstName) && (tail->get_lastName() == lastName)) {
        found = true;
        before->next = current->next;
        tail = before;
        delete current;
        cout << firstName << ", " << lastName << " has been deleted" << endl;
    }

    if (found == false) {
        cout << firstName << ", " << lastName << " " << "not found in the list" << endl;
    }

}

void List::deleteEnds() {

    // Deleting head node
    Student* temp1 = head;
    head = head->next;
    delete temp1;

    Student* temp2 = head;
    // Locate the node before the tail
    while (temp2->next != tail) {
        temp2 = temp2->next;
    }
    
    // Deleting the tail node
    tail = temp2;
    temp2 = temp2->next;
    tail->next = NULL;
    delete temp2;
}

void List::printStudent(Student* student) {

    if (!is_InternationalStudent(student)) {
        cout << student->get_firstName() << ", " << student->get_lastName() << ", " << student->get_province() << ", "
        << fixed << setprecision(1) << student->get_CGPA() << ", " << student->get_researchScore() << endl;
    } else {
        cout << student->get_firstName() << ", " << student->get_lastName() << ", " << student->get_country() << ", "
        << fixed << setprecision(1) << student->get_CGPA() << ", " << student->get_researchScore() << ", "
        << student->get_ToeflSpeaking() << ", " << student->get_ToeflListening() << ", " << student->get_ToeflSpeaking() << ", " << student->get_ToeflWriting() << endl;
    }
}

void List::printList() {

    StudentPtr temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        cout << count << "      ";
        printStudent(temp);
        temp = temp->next;
    }
}





// SEARCH FUNCTIONS

void List::search_CGPA(float CGPA) {

    Student* temp = head;
    bool found = false;
    
    while (temp != NULL) {
        if (temp->get_CGPA() == CGPA) {
            printStudent(temp);
            found = true;
        }
        temp = temp->next;
    }  

    if (found == false) {
        cout << "A student with a CGPA of " << CGPA << " was not found in the list" << endl;
    }

}

void List::search_researchScore(int researchScore) {

    Student* temp = head;
    bool found = false;
    
    while (temp != NULL) {
        if (temp->get_researchScore() == researchScore) {
            printStudent(temp);
            found = true;
        }
        temp = temp->next;
    }  

    if (found == false) {
        cout << "A student with a research score of " << researchScore << " was not found in the list" << endl;
    }
}

void List::search_appID(int appID) {

    Student* temp = head;
    bool found = false;
    
    while (temp != NULL) {
        if (temp->get_appID() == appID) {
            printStudent(temp);
            found = true;
        }
        temp = temp->next;
    }  

    if (found == false) {
        cout << "A student with an application ID of " << appID << " was not found in the list" << endl;
    }
}

void List::search_name(string firstName, string lastName) {

    Student* temp = head;
    bool found = false;

    try {
        if ((firstName[0] >= 65 && firstName[0] <= 90) && (firstName[0] >= 97 && firstName[0] <= 122)) {
            throw firstName;
        }
    }
    catch (string e) {
        cout << "Please enter a valid first name" << endl;
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

        try {
        if (lastName == " ") {
            throw lastName;
        }
        if ((lastName[0] >= 65 && lastName[0] <= 90) && (lastName[0] >= 97 && lastName[0] <= 122)) {
            throw lastName;
        }
    }
    catch (string e) {
        cout << "Please enter a valid last name" << endl;
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

    while (temp != NULL) {
        if ((temp->get_firstName() == firstName) && (temp->get_lastName() == lastName)) {
            printStudent(temp);
            found = true;
        }
        temp = temp->next;
    }  

    if (found == false) {
        cout << "A student named " << firstName << " " << lastName << " was not found in the list" << endl;
    }
}

Student List::new_Node(Student student) {
    Student newStudent(student);
    return newStudent;
}

// SEARCH FUNCTIONS




// Note: If we want the domestic students to go before the international students:
        // DomesticList is list1, InternationalList is list2
List mergeList(const List& list1, const List& list2) {

    List newList(list1);

    newList.tail->next = list2.get_head();
    newList.tail = list2.get_tail();
    MergeSort(newList.get_headPtr());

    return newList;

}

void List::print_threshold(int researchScore_threshold, double CGPA_threshold) {

    Student* temp = head;
    bool found = false;

    while (temp->get_researchScore() >= researchScore_threshold) {
        if (temp->get_CGPA() >= CGPA_threshold) {
            printStudent(temp);
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "No matching students!" << endl;
    }
}

// PUBLIC----------------------------


