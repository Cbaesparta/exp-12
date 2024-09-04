//Name: Sai Sankar JENA
//Prn: 23070123112
//Class: EnTC B-2
#include<iostream>
#include<string.h>
using namespace std;

class student {
    int rno;
    char name[50];
    double fee;

public:
    student(int no, const char n[], double f);
    student(const student &t);

    void display();
};
student::student(int no, const char n[], double f) {
    rno = no;
    strcpy(name, n);
    fee = f;
}
student::student(const student &t) {
    rno = t.rno;
    strcpy(name, t.name);
    fee = t.fee;
}
void student::display() {
    cout << endl << rno << "\t" << name << "\t" << fee;
}
int main() {
    student s(123, "SAI", 1000);
    s.display();
    student sai(s);
    sai.display();
    return 0;
}
