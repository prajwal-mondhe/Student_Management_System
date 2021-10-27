// STUDENT MANAGEMENT SYSTEM: @T.E.N LABS Task2 
// By Prajwal Mondhe

#include <iostream>
#include <fstream> 
//ofstream: Stream class to write on files
//ifstream: Stream class to read from files
//fstream: Stream class to both read and write from/to files.
//#include <stdlib.h> //This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <cstdlib>
#include <conio.h> //It stand for console input ouput i.e. it takes input from keyboard
using namespace std;

// CREATING STUDENT CLASS
class student
{
private:
    string name, roll_no, course, address, email_id, contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};

// MENU FUNCTION
void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");
    // system(“cls”) which is used to make the screen/terminal clear.

    cout << "\t\t\t ----------------------------------------------------------------------- " << endl;
    cout << "\t\t\t                    |  STUDENT MANAGEMENT SYSTEM  |                      " << endl;
    cout << "\t\t\t                         [By: Prajwal Mondhe]                        " << endl;
    cout << "\t\t\t ----------------------------------------------------------------------- " << endl;

    cout << "\t\t\t 1. Enter New record " << endl;
    cout << "\t\t\t 2. Display Record   " << endl;
    cout << "\t\t\t 3. Modify Record    " << endl;
    cout << "\t\t\t 4. Search Record    " << endl;
    cout << "\t\t\t 5. Delete Record    " << endl;
    cout << "\t\t\t 6. Exit             " << endl;

    cout << "\t\t\t ----------------------------------------------------------------------- " << endl;
    cout << "\t\t\t|                         Choose Option [1/2/3/4/5/6]                     " << endl;
    cout << "\t\t\t ----------------------------------------------------------------------- " << endl;

    cout << "\t\t\t Enter your option: ";
    cin >> choice;

    // Using switch case (not if else statement)
    switch (choice)
    {

    case 1:
        do
        {
            insert(); // Insert function called here
            cout << "\n\t\t\t Add another sudent record (y/n) :";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        
        //do while loop for multiple entries one after other.
        break;

    case 2:
        display();
        break;

    case 3:
        modify();
        break;

    case 4:
        search();
        break;

    case 5:
        deleted();
        break;

    case 6:
        cout << "\n\n\t\t\t                                Thank You !                                " << endl;
        cout << "\t\t\t ----------------------------------------------------------------------- \n"
             << endl;

        exit(0); // To exit the loop

    default:
        cout << "\n\t\t\t Invalid Choice...Please try again ";
        break;
    }
    getch();
    // getch() method pauses the Output Console until a key is pressed...means button press karke hi next step hoga

   
    goto menustart; // Making a loop with only 6 can exit
}
// INSERT FUNCTION
void student::insert()  // To define function in a class
{
    system("cls"); //system(“cls”) which is used to make the screen/terminal clear. ~ clrscr();
    
    fstream file;   //creating file named file that can be both read/write [fstream]

    cout << "\n--------------------------------------------------------------------------- " << endl;
    cout << "\n                 Add student details                                                " << endl;
    cout << "\n--------------------------------------------------------------------------- " << endl;

    cout << "\t\t\t Enter Name: ";
    cin >> name;

    cout << "\t\t\t Enter Roll no: ";
    cin >> roll_no;

    cout << "\t\t\t Enter Course: ";
    cin >> course;

    cout << "\t\t\t Enter Email Id: ";
    cin >> email_id;

    cout << "\t\t\t Enter Contact no: ";
    cin >> contact_no;

    cout << "\t\t\t Enter Address: ";
    cin >> address;

/*
1>ios::app
Append mode. All output to that file to be appended to the end.

2>ios::ate
Open a file for output and move the read/write control to the end of the file.

3>ios::in
Open a file for readin.

4>ios::out
Open a file for writing.

5>ios::trunc

If the file already exists, its contents will be truncated before opening the file.
*/

    // OPENING & CLOSING FILE
    //"studentRecord.txt" for string data
    file.open("studentRecord.txt", ios::app | ios::out); // Append details & open for writng only
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();

}

void student::display()
{
    system("cls");
    fstream file;
    int total = 0;

    cout << "\n\t\t\t --------------------------------------------------------------------------- " << endl;
    cout << "\n\t\t\t                  Student record table                                       " << endl;
    cout << "\n\t\t\t --------------------------------------------------------------------------- " << endl;

    file.open("studentRecord.txt", ios::in); //Reading mode..We only want to display 

    if (!file) // Empty file
    {
        cout << "\n\t\t\t No Data is present";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> contact_no >> address; //
        while (!file.eof()) // [ file.eof() ] is FALSE
//file.eof()   ->> , that returns nonzero (meaning TRUE) when there are no more data to be read from an input file stream, 
//and zero (meaning FALSE) otherwise.
        {
            cout << "\t\t\t Student No.      : " << total++ << endl;  // counting
            cout << "\t\t\t Student Name     : " << name << endl;
            cout << "\t\t\t Student Roll no  : " << roll_no << endl;
            cout << "\t\t\t Student Course   : " << course << endl;
            cout << "\t\t\t Student Email id : " << email_id << endl;
            cout << "\t\t\t Student address  : " << address << endl;
            cout << "\n";
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t\t No Data is present";
        }
        file.close();
    }
}

void student::modify()
{
    string rollno;
    int found = 0;
    system("cls");
    fstream file, file1;
    cout << "\t\t\t ----------------------------------------------------------------------- " << endl;
    cout << "\t\t\t                          Student Modify Details                         " << endl;
    cout << "\t\t\t ----------------------------------------------------------------------- " << endl;

    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Data is present...";
        file.close();
    }
    else
    {
        cout << "\n\t\t\t Enter Roll no of students which you want to Modify: ";
        cin >> rollno;

        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;

        while (!file.eof())
        {
            if (rollno != roll_no) //IF entered no is not same as any previous one
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {

                cout << "\t\t\t Enter Name: ";
                cin >> name;

                cout << "\t\t\t Enter Roll no: ";
                cin >> roll_no;

                cout << "\t\t\t Enter Course: ";
                cin >> course;

                cout << "\t\t\t Enter Email Id: ";

                cin >> email_id;

                cout << "\t\t\t Enter Contact no: ";
                cin >> contact_no;

                cout << "\t\t\t Enter Address: ";
                cin >> address;

                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";

                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;

            if (found == 0)
            {
                cout << "\t\t\t Student roll no, Not Found... \n";
            }
        }
        file1.close();
        file.close();

        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt"); //Updating
    }
}

void student::search()
{
    system("cls");
    fstream file;

    int found = 0;
    file.open("studentRecord.txt", ios::in);

    if (!file)
    {
        cout << "\t\t\t ----------------------------------------------------------------------- " << endl;
        cout << "\t\t\t|                         Student Search Data                     " << endl;
        cout << "\t\t\t ----------------------------------------------------------------------- " << endl;

        cout << "\n\t\t\t No Data is present...";
        // file.close();
    }
    else
    {
        string rollno;
        cout << "\t\t\t ----------------------------------------------------------------------- " << endl;
        cout << "\t\t\t|                         Student Search Data                     " << endl;
        cout << "\t\t\t ----------------------------------------------------------------------- " << endl;

        cout << "\n Enter Roll no of the student which you want to Search: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;

        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\t\t\t Student Name     : " << name << endl;
                cout << "\t\t\t Student Roll no  : " << roll_no << endl;
                cout << "\t\t\t Student Course   : " << course << endl;
                cout << "\t\t\t Student Email id : " << email_id << endl;
                cout << "\t\t\t Student address  : " << address << endl;

                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }

        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll no. not Found ";
        }
        file.close();
    }
}
void student::deleted()
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;

    cout << "\t\t\t ----------------------------------------------------------------------- " << endl;
    cout << "\t\t\t|                         Delete Student Details                         |" << endl;
    cout << "\t\t\t ----------------------------------------------------------------------- " << endl;

    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Data is present";
        //file.close();
    }
    else
    {
        cout << "\n\t\t\t Enter Roll no of the student which you want to delete the data:  ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if(rollno != roll_no)
            {
                file1  << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            //file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            
            else
            {
                found++;
                cout << "\n\t\t\t Data Deleted  Successfully.";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll no not found...";
        }

        file1.close();
        file.close();

        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}


int main()
{
    student project;
    project.menu();
    return 0;
}