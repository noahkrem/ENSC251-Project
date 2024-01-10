// Stops us from defining our files more than once
#pragma once
#include <string>
#include <iostream>

using namespace std;

// This integer represents the base application ID number
const int baseAppID = 20220000;

class ToeflScore {
public:
    // Default constructor
    ToeflScore();

    // Update every time a score is changed
    void update_total();

    // Getters
    int get_reading() const;
    int get_listening() const;
    int get_speaking() const;
    int get_writing() const;
    int get_total() const;

    // Setters
    void set_reading(int reading);
    void set_listening(int listening);
    void set_speaking(int speaking);
    void set_writing(int writing);

    // Overload << operator
    friend ostream& operator<<(ostream& outs, ToeflScore& toeflScore);

private:
    int reading, listening, speaking, writing, total;
};

class Student {

public:

    Student* next;

    // Default constructor
    Student();
    
    Student(Student* student);

    // Getters
    string get_firstName() const;
    string get_lastName() const;
    float get_CGPA() const;
    int get_researchScore() const;
    int get_appID() const;

    // Setters
    void set_firstName(string firstName);
    void set_lastName(string lastName);
    void set_CGPA(float CGPA);
    void set_researchScore(int researchScore);
    void set_appID();
    void set_appID(int appID);

    // Comparing functions
    /*
        Three Cases; if stu1.object is...
        1. Less than, returns 0
        2. Equal to, returns 1
        3. Greater than, returns 2
        If none of these, return -1, which denotes an error
    */

    int friend compareCGPA(const Student& stu1, const Student& stu2);
    int friend compareResearchScore(const Student& stu1, const Student& stu2);
    int friend compareFirstName(const Student& stu1, const Student& stu2);
    int friend compareLastName(const Student& stu1, const Student& stu2);

    int friend compareCGPA(const Student* stu1, const Student* stu2);
    int friend compareResearchScore(const Student* stu1, const Student* stu2);
    int friend compareFirstName(const Student* stu1, const Student* stu2);
    int friend compareLastName(const Student* stu1, const Student* stu2);

    int friend compareProvince(const Student* stu1, const Student* stu2);
    int friend compareCountry(const Student* stu1, const Student* stu2);

    // Virtual Functions
    virtual string get_province() const;
    virtual string get_country() const;
    virtual int get_ToeflReading() const;
    virtual int get_ToeflListening() const;
    virtual int get_ToeflSpeaking() const;
    virtual int get_ToeflWriting() const;
    virtual int get_ToeflTotal() const;
    virtual ToeflScore get_ToeflScore() const;


    // Overload << operator
    friend ostream& operator<<(ostream& outs, Student& student);

private:
    string firstName;
    string lastName;
    float CGPA;
    int researchScore;
    int appID;
};

typedef Student* StudentPtr;

class DomesticStudent : public Student {

public:

    // Default constructor
    DomesticStudent(); 

    DomesticStudent(const DomesticStudent& student); 
    DomesticStudent(const DomesticStudent* student);

    // Getter
    string get_province() const override;

    // Setter
    void set_province(string province) ;  

    // Comparing functions specific to DomesticStudent
    int friend compareProvince(const DomesticStudent& stu1, const DomesticStudent& stu2);

    // Overload << operator
    friend ostream& operator<<(ostream& outs, DomesticStudent& student);

    // Overload = operator
    DomesticStudent& operator =(const DomesticStudent& student);

private:
    string province;
};

typedef DomesticStudent* DomesticPtr;

class InternationalStudent : public Student {

public:

    // Default constructor
    InternationalStudent();

    // Copy constructor
    InternationalStudent(const InternationalStudent& student);
    InternationalStudent(const InternationalStudent* student);

    // Getter
    string get_country() const override;
    int get_ToeflReading() const override;
    int get_ToeflListening() const override;
    int get_ToeflSpeaking() const override;
    int get_ToeflWriting() const override;
    int get_ToeflTotal() const override;
    ToeflScore get_ToeflScore() const override;
    
    // Setters
    void set_country(string country);
    void set_ToeflReading(int reading);
    void set_ToeflListening(int listening);
    void set_ToeflSpeaking(int speaking);
    void set_ToeflWriting(int writing);
    void set_ToeflTotal();

    // Compare functions that are specific to international students
    int friend compareCountry(const InternationalStudent& stu1, const InternationalStudent& stu2);

    // Overload << operator
    friend ostream& operator<<(ostream& outs, InternationalStudent& student);

    // Overload = operator
    InternationalStudent& operator =(const InternationalStudent& student);

    // Overload == operator
    friend bool operator ==(const InternationalStudent& stu1, const InternationalStudent& stu2);

private:
    string country;
    ToeflScore toeflScore;
};

typedef InternationalStudent* InternationalPtr;
