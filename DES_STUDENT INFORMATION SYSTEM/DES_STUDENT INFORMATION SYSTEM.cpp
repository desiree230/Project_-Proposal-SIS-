#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <string>



using namespace std;
FILE* fp, * ft;
struct student {

    char first_name[50];
    char last_name[50];
    char student_num[50];
    char course[50];
    char student_grades[2];
    int year;

};
struct student s;
char xstudent_num[50];
long int recsize;

void addStudent() {
    system("cls");
    cout << "Enter the First Name : ";
    cin >> s.first_name;
    cout << "Enter the Last Name : ";
    cin >> s.last_name;
    cout << "Enter the Student Number : ";
    cin >> s.student_num;
    cout << "Enter the Course    : ";
    cin >> s.course;
    cout << "Enter Academic Year  : ";
    cin >> s.year;
}


void viewRecord() {

    cout << "\n";
    cout << "\n      Name             ::  " << s.first_name << " " << s.last_name;
    cout << "\n      Student Number   ::  " << s.student_num;
    cout << "\n      Course           ::  " << s.course;
    cout << "\n      Academic Year    ::  " << s.year;
    cout << "\n      Grades           ::  " << s.student_grades;
}

void modify() {


    cout << "\n Enter the Student Number : ";
    cin >> xstudent_num;

    rewind(fp);
    while (fread(&s, recsize, 1, fp) == 1)
    {
        if (strcmp(s.student_num, xstudent_num) == 0)
        {
            cout << "\n";
            cout << "Enter the Student Grades : ";
            cin >> s.student_grades;

            fseek(fp, -recsize, SEEK_CUR);
            fwrite(&s, recsize, 1, fp);
            break;
        }
        else
            cout << "record not found";
    }
    cout << "\n Modify Another Record  (Click Y = Yes | N = No) ";



}

string username, password;


int main() {
    char another;
    char choice;


    fp = fopen("DB.txt", "rb+");

    if (fp == NULL) {
        fp = fopen("DB.txt", "wb+");
    }

    recsize = sizeof(s);

    while (1) {
        system("cls");
        cout << "\n";
        cout << "************************************************************************************************************************\n";
        cout << "                                               STUDENT INFORMATION SYSTEM\n";
        cout << "                                                 WELCOME TO DESIREE SIS\n";
        cout << "************************************************************************************************************************\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "                                                Select your Destination:\n                                                         ";
        cout << "\n";
        cout << "            STUDENTS:";
        cout << "\n          \t\t\t Press 1 == Sign-up New Student";
        cout << "\n          \t\t\t Press 2 == To View Records";
        cout << "\n------------------------------------------------------------------------------------------------------------------------";
        cout << "\n";
        cout << "\n";
        cout << "            TEACHERS:";
        cout << "\n          \t\t\t Press 3 == Edit Records";
        cout << "\n          \t\t\t Press 4 == To Delete Records";
        cout << "\n------------------------------------------------------------------------------------------------------------------------";
        cout << "\n";
        cout << "\n";
        cout << "\n          \t\t\t Press 5 == View all Records";
        cout << "\n          \t\t\t Press 6 == Exit the Program";
        cout << "\n";
        cout << "\nSelect your option:";
        fflush(stdin);
        choice = getche();
        switch (choice)
        {
        case '1':

            fseek(fp, 0, SEEK_END);
            another = 'Y';
            while (another == 'Y')
            {
                addStudent();
                fwrite(&s, recsize, 1, fp);
                cout << "\n Insert Another Record (Click Y = Yes | N = No) ";
                fflush(stdin);
                another = getchar();
            }
            break;

        case '2':
            system("cls");

            cout << "                                    View Record\n";

            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n Enter the Student Number : ";
            cin >> xstudent_num;
            rewind(fp);
            while (fread(&s, recsize, 1, fp) == 1) {
                if (strcmp(s.student_num, xstudent_num) == 0) {

                    viewRecord();
                }
                else {
                    cout << "Record not found";
                }
                cout << "\n\n";
                system("pause");
            }
            break;

        case '3':

            system("cls");
            cout << "                                                           Login\n";
            cout << "\n";
            cout << "\n";
            cout << "Enter your Username (Professor): ";
            cin >> username;
            cout << "Enter your Password: ";
            cin >> password;

            if (username == "Teacher" && password == "2023") {

                system("cls");

                cout << "Welcome! Your login was successful." << endl;

            }
            else {
                cout << "The username or password you entered was incorrect. Please try again" << endl;

                system("pause");
                return main();
            }



            another = 'Y';
            while (another == 'Y')
            {
                modify();
                fflush(stdin);
                another = getchar();

            }
            break;

        case '4':

            system("cls");

            cout << "               Login\n";
            cout << "\n";
            cout << "\n";
            cout << "Admin: \n";
            cin >> username;
            cout << "Password: \n";
            cin >> password;

            if (username == "admin" && password == "2023") {

                system("cls");

                cout << "Welcome!\nYour login was successful." << endl;
            }
            else {
                cout << "The username or password you entered was incorrect. Please try again" << endl;

                system("pause");

                return main();
            }


            another = 'Y';
            while (another == 'Y')
            {
                cout << "\n Enter the Student Number to delete: ";
                cin >> xstudent_num;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread(&s, recsize, 1, fp) == 1)

                    if (strcmp(s.student_num, xstudent_num) != 0)
                    {
                        fwrite(&s, recsize, 1, ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("DB.txt");

                int result = rename("temp.dat", "DB.txt");

                fp = fopen("DB.txt", "rb+");

                cout << "\n Delete Another Record  (Click Y = Yes | N = No) ";
                fflush(stdin);
                another = getchar();

            }

            break;
        case '5':

            system("cls");

            cout << "               View all Records\n";
            cout << "\n";
            cout << "\n";
            cout << "Admin: \n";
            cin >> username;
            cout << "Password: \n";
            cin >> password;

            if (username == "admin" && password == "2023") {

                system("cls");

                cout << "               View all Records\n";
                cout << "\n";
                cout << "\n";
                cout << "Welcome!Your login was successful." << endl;
                cout << "\n";
                cout << "\n";
                rewind(fp);
                cout << " View the Records ";
                cout << "\n";
                while (fread(&s, recsize, 1, fp) == 1) {
                    viewRecord();
                }
                cout << "\n\n";
                system("pause");

            }
            else {
                cout << "The username or password you entered was incorrect. Please try again" << endl;
                system("pause");

                return main();
            }



            break;

        case '6':
            fclose(fp);
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n                                ====END====             ";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            exit(0);



        }

    }

    return 0;
}



