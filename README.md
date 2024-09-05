
# exp-12
## Aim:
To study and implement Constructors and Destructors.

## Theory:
Certainly! Here’s a more detailed summary of constructors in C++ in bullet points:

- **Special Member Function**: 
  - Has the same name as the class it belongs to.
  - Not a regular function but a special type designed for object initialization.

- **Primary Purpose**: 
  - Used to initialize an object’s data members and set up any necessary resources when the object is created.

- **Return Type**: 
  - Constructors do not have a return type, not even `void`.

- **Automatic Invocation**: 
  - Called automatically by the C++ runtime when an object is instantiated, ensuring that the object starts its life in a valid state.

- **Access Control**:
  - **Public**: Typically defined in the public section of a class to allow easy and unrestricted creation of objects.
  - **Private/Protected**: Can be defined in private or protected sections to restrict or control how objects of the class are created (e.g., for singleton patterns or factory methods).

- **Overloading**:
  - Constructors can be overloaded, meaning you can define multiple constructors with different parameter lists to initialize objects in different ways.
  
- **Virtual Functions**:
  - Constructors cannot be declared as virtual because they are responsible for initializing an object, and virtual dispatch is not applicable during object construction.

- **Syntax**:
  - **Inside the Class Definition**: Defined within the class body using the class name followed by parentheses, e.g., `ClassName(parameters) { // implementation }`.
  - **Outside the Class Definition**: Defined outside the class body using the scope resolution operator, e.g., `ClassName::ClassName(parameters) { // implementation }`.



## Difference 


| Feature               | Constructor                                    | Destructor                                      |
|-----------------------|------------------------------------------------|-------------------------------------------------|
| **Purpose**           | Initializes a newly created object            | Cleans up resources when an object is destroyed |
| **Syntax**            | `ClassName()`                                  | `~ClassName()`                                  |
| **Called When**       | When an object is instantiated                 | When an object goes out of scope or is explicitly deleted |
| **Parameters**        | Can take parameters to initialize object data  | Cannot take parameters                         |
| **Return Type**       | No return type (not even void)                 | No return type (not even void)                  |
| **Overloading**       | Can be overloaded to provide different ways of initialization | Cannot be overloaded                             |
| **Inheritance**       | Can be inherited and overridden in derived classes | Can be inherited and overridden in derived classes |
| **Order of Execution**| Executed before the body of the class          | Executed after the body of the class            |
| **Purpose Example**   | Setting initial values, allocating resources   | Releasing resources, cleanup operations         |
| **Implicit Call**     | Automatically called when an object is created | Automatically called when an object is destroyed |

### Comparing **Default**, **Parameterized**, and **Copy Constructors** in C++:

| **Feature**                   | **Default Constructor**                                  | **Parameterized Constructor**                         | **Copy Constructor**                                    |
|-------------------------------|----------------------------------------------------------|------------------------------------------------------|---------------------------------------------------------|
| **Definition**                 | A constructor that takes no arguments                    | A constructor that takes one or more arguments        | A constructor that creates a copy of an existing object  |
| **Syntax**                     | `ClassName();`                                           | `ClassName(type arg1, type arg2, ...);`               | `ClassName(const ClassName &obj);`                       |
| **Purpose**                    | Initializes members with default values                  | Initializes members with custom values                | Creates a new object as a copy of an existing object     |
| **Call Scenario**              | Called when an object is created without parameters       | Called when an object is created with specific values | Called when an object is copied (e.g., passing by value) |
| **Implicit Creation**          | Automatically provided if no constructors are defined    | Must be explicitly defined by the programmer          | Automatically provided unless overridden                 |
| **Overloading**                | Cannot be overloaded                                     | Can be overloaded with multiple parameter sets        | Cannot be overloaded                                     |
| **Example**                    | `Rectangle r1;`                                          | `Rectangle r2(5, 10);`                                | `Rectangle r3 = r2;`                                     |
| **When Used**                  | When an object doesn't need specific initialization       | When custom values need to be passed during object creation | When making a copy of an existing object                |
| **Default Parameters**         | Does not accept parameters                               | Accepts parameters                                   | Accepts one argument: a reference to another object      |


## Defining the constructor inside the class:
```
//Name:Sai Sankar Jena
//Prn: 23070123112
//Class: EnTC B-2
#include<iostream>
using namespace std;

class student
{
    int rollno;
    char name[50];
    double fee;
public:
    student()
    {
        cout << "Enter the RollNo: ";
        cin >> rollno;
        cin.ignore();
        cout << "Enter the Name: ";
        cin.getline(name, 50);
        cout << "Enter the Fee: "; 
        cin >> fee;
    }
    void display()
    {
        cout << endl << rollno << "\t" << name << "\t" << fee;
    }
};
int main()
{
    student s; 
    s.display();
    return 0;
}
```
Output:
```
/tmp/pZuuGX7Bpu.o
Enter the RollNo: 12
Enter the Name: sai
Enter the Fee: 45000

12	sai	45000

=== Code Execution Successful ===
```
## Defining the constructor outside the class:
```
//Name:Sai Sankar Jena
//Prn: 23070123112
//Class: EnTC B-2
#include<iostream>
using namespace std;

class student
{
    int rno;
    char name[50];
    double fee;

public:
    student();
    void display();
};
student::student()
{
    cout << "Enter the RollNo: ";
    cin >> rno;
    cout << "Enter the Name: ";
    cin >> name;
    cout << "Enter the Fee: ";
    cin >> fee;
}
void student::display()
{
    cout << endl << rno << "\t" << name << "\t" << fee;
}
int main()
{
    student s;
    s.display();
    return 0;
}
```
Output:
```
/tmp/GTj5cwPOxj.o
Enter the RollNo: 123
Enter the Name: sai
Enter the Fee: 45000

123	sai	45000

=== Code Execution Successful ===
```

## Default constructor:
```
//Name:Sai Sankar Jena
//Prn: 23070123112
//Class: EnTC B-2
#include<iostream>
#include<string>
using namespace std;

class Data {
    string name;
    int roll_no;
    char dept[50];
    int batch;

public:
    Data() {
        cout << "Name: ";
        cin >> name;
        cout << "Roll Number: ";
        cin >> roll_no;
        cout << "Department: ";
        cin >> dept;
        cout << "Batch: ";
        cin >> batch;
    }
    void display() {
        cout << endl << "DETAILS:" << endl << name << " " << roll_no << " " << dept << " " << batch << endl;
    }
};
int main() {
    Data d1;
    d1.display();
}
```
## Output:
```
/tmp/Fw5ruF4Dr2.o
Name: sai
Roll Number: 123
Department: entc
Batch: 23

DETAILS:
sai 123 entc 23


=== Code Execution Successful ===
```
## Parameterized constructor:
```
//Name:Sai Sankar Jena
//Prn: 23070123112
//Class: EnTC B-2
#include<iostream>
using namespace std;
class Num
{
    public:
    Num(int c, int d)
    {
        if(c>d)
        {
            cout<<c<<" is greater";
        }
        else
        {
            cout<<d<<" is greater";
        }
    }
};
int main()
{
Num n1(4,3);
}
```
## Output:
```
/tmp/1nnQoaKrTo.o
4 is greater

=== Code Execution Successful ===
```
## Copy constructor:
```
//Name:Sai Sankar Jena
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
    student s(123, "SAI", 100000);
    s.display();
    student manjeet(s);
    manjeet.display();
    return 0;
}
```
## Output:
```
/tmp/MJ5LxBry21.o

123	SAI	100000
123	SAI	100000

=== Code Execution Successful ===
```
## Destructors:

```
//Name:Sai Sankar Jena
//Prn: 23070123112
//Class: EnTC B-2
#include<iostream>
using namespace std;
int count=0;
class destruct
{
    public:
    destruct()
    {
        count++;
        cout<<"No. of objects created: "<<count<<endl;
    }
    ~destruct()
    {
        count--;
        cout<<"No. of objects destroyed: "<<count<<endl;
    }
};
int main()
{
destruct aa,bb,cc;
{ 
    destruct dd;
}
return 0;
}
```
## Output:
```
/tmp/DeiBtz27xV.o
No. of objects created: 1
No. of objects created: 2
No. of objects created: 3
No. of objects created: 4
No. of objects destroyed: 3
No. of objects destroyed: 2
No. of objects destroyed: 1
No. of objects destroyed: 0


=== Code Execution Successful ===
```

## Conclusion:


- **Purpose**: Essential for initializing objects and ensuring they start in a valid state.
- **Automatic Invocation**: Called automatically upon object creation.
- **Return Type**: No return type (not even `void`).
- **Overloading**: Supports overloading to allow different initialization options.
- **Access Control**: Typically defined in the public section but can be made private or protected to control object creation.
- **Flexibility**: Allows for various initialization methods to suit different needs.
- **Fundamental**: Crucial for robust and efficient C++ programming by ensuring objects are properly set up.
