﻿#include "student_operator.h"

void menu(list <Student>& database)
{
	int choice = 0;
    bool exit_program = false;
	do {
        do
        {
            system("cls");

            cout << "\t\t\t***STUDENT MANAGEMENT SYSTEM***\t\t" << endl;
            cout << "\t\t\tMAIN MENU" << endl;
            cout << "\t\t======================" << endl;
            cout << "\t\t[1] Add A New Student." << endl;
            cout << "\t\t[2] Modify Student Information." << endl;
            cout << "\t\t[3] Delete A Student." << endl;
            cout << "\t\t[4] Search for A Student" << endl;
            cout << "\t\t[5] Arrange Student." << endl;
            cout << "\t\t[6] Student List." << endl;
            cout << "\t\t[7] Save Into database_sv.csv." << endl;
            cout << "\t\t[0] Exit the Program." << endl;
            cout << "\t\t=======================" << endl;
            cout << "\t\tEnter The Choice: ";
            cin >> choice;

        } while (choice < 0 || choice > 7);

		switch (choice)
		{
			case 1: // Add A New Student.
			{
				bool adding_another = true;
                do
                {
                    cout << "\n-----------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Add A New Student ---------------------------------------------" << endl;
                    addStudent(database);

                    cout << "\n\n\t\t\t 1. Add another student " << endl;
                    cout << "\t\t\t 0. Back to Menu " << endl;
                    cout << "\t\t\tEnter the choice: ";
                    cin >> choice;

                    if (choice == 1) {
                        adding_another = true;
                    }
                    else if (choice == 0) {
                        adding_another = false;
                    }
                    else {
                        cout << "please try again. " << endl;
                    }
                } while (adding_another);
				
				break;
			}

			case 2: // Edit Student Info
			{
                bool edit_another = true;
                while (edit_another) {
                    cout << "\n-----------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Edit Student Info ---------------------------------------------" << endl;
                    edit_student_info(database);
                    cout << "1. Go back " << endl;
                    cout << "0. Back to Menu " << endl;
                    cout << "Enter the choice: ";

                    cin >> choice;

                    if (choice == 1) {
                        edit_another = true;
                    }
                    else if (choice == 0) {
                        edit_another = false;
                    }
                    else {
                        cout << "please try again. " << endl;
                    }
                }

				break;
			}

            case 3: // Delete Student based on ID
            {
                bool delete_another = true;
                while (delete_another) {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Delete Student --------------------------------------------------" << endl;
                    deletee(database);
                    cout << "1. Go back " << endl;
                    cout << "0. Back to Menu " << endl;
                    cout << "Enter the choice: ";
                    cin >> choice;

                    if (choice == 1) {
                        delete_another = true;
                    }
                    else if (choice == 0) {
                        delete_another = false;
                    }
                    else {
                        cout << "please try again. " << endl;
                    }
                }

                break;
            }

            case 4: // Search Student based on ID or Name
            {
                bool continueSearch = false;

                do {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Search Student ---------------------------------------------" << endl;
                    cout << "1. Search by name" << endl;
                    cout << "2. Search by ID" << endl;
                    cout << "0. Back to Menu" << endl;
                    cout << "Enter The Choice: ";
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                                search_by_name(database);
                                cout << endl;
                                cout << "1. Search another student" << endl;
                                cout << "0. Back to Menu" << endl;
                                cout << "Enter The Choice: ";
                                cin >> choice;

                                if (choice == 1) {
                                    continueSearch = true;
                                }
                                else {
                                    continueSearch = false;
                                }
                            break;
                        }
                        case 2: {
                            search_by_ID(database);
                            cout << endl;
                            cout << "1. Search another student" << endl;
                            cout << "0. Back to Menu" << endl;
                            cout << "Enter The Choice: ";
                            cin >> choice;

                            if (choice == 1) {
                                continueSearch = true;
                            }
                            else {
                                continueSearch = false;
                            }
                            break;
                        }
                        case 0: {
                            break;
                            continueSearch = false;
                        }
                        default: {
                            cout << "Invalid choice. Please try again." << endl;
                            continueSearch = true;
                            break;
                        }
                    }
                } while (continueSearch);

                break;
            }


            case 6: // Display student list
            {
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------- Student List ---------------------------------------------" << endl;
                display_student(database);
                cout << endl;
                cout << "Press [0] to Back to Menu " << endl;
                cin >> choice;

                break;
            }

			default:
				break;
		}
	
	}while (!exit_program);
}

/*
* Function: addStudent
* Description: This function is used for adding a student into database
* Input:	database	
* Output:	none
*/
void addStudent(list<Student> &database)
{
	Student newstudent;
	newstudent.setData();

	database.push_back(newstudent);
}

/*
* Function: edit student info
* Description: This function is used for editing the student information
* Input:	database	
* Output:	none
*/
void edit_student_info(list<Student>& database) {
    int ID_input;
    cout << "Enter the ID of the student you want to modify: ";
    cin >> ID_input;

    bool found = false;
    for (list<Student>::iterator it = database.begin(); it != database.end(); ++it) {
        if (it->getID() == ID_input) {
            found = true;
            cout << "\nStudent found. Current information:" << endl;
            it->getData();

            cout << "\nWhat detail do you want to edit?" << endl;
            cout << "1. Name" << endl;
            cout << "2. Age" << endl;
            cout << "3. Gender" << endl;
            cout << "4. Math score" << endl;
            cout << "5. Physics score" << endl;
            cout << "6. Chemistry score" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                cout << "Enter the new name: ";
                string new_name;
                cin.ignore();
                getline(cin, new_name);
                it->setName(new_name);
                cout << "Student name updated successfully!" << endl;
                cout << endl;
                break;
            }
            case 2: {
                cout << "Enter the new age: ";
                int new_age;
                cin >> new_age;
                while (new_age < 0 || new_age > 150) {
                    cout << "Invalid choice! Please try again: ";
                    cin >> new_age;
                }
           
                it->setAge(new_age);
                cout << "Student age updated successfully!" << endl;
                cout << endl;
                break;
            }
            case 3: {
                string MF_;
                do {
                    cout << "\n\n\t\t\tEnter M for male and F for female" << endl;
                    cout << "\t\t\tEnter Gender: ";
                    cin >> MF_;
                } while (MF_ != "M" && MF_ != "F" && MF_ != "m" && MF_ != "f");

                Gender _gender;
                if (MF_ == "M" || MF_ == "m") {
                    _gender = MALE;
                }
                else {
                    _gender = FEMALE;
                }
                it->setGender(_gender);
                cout << "Student gender updated successfully!" << endl;
                cout << endl;
                break;
            }
            case 4: {
                cout << "Enter the new math score: ";
                float new_math_score;
                cin >> new_math_score;
                while (new_math_score < 0 || new_math_score > 10) {
                    cout << "Invalid choice! Please try again: ";
                    cin >> new_math_score;
                }
                it->setMath(new_math_score);
                cout << "Math score updated successfully!" << endl;
                cout << endl;
                break;
            }
            case 5: {
                cout << "Enter the new physics score: ";
                float new_physics_score;
                cin >> new_physics_score;
                while (new_physics_score < 0 || new_physics_score > 10) {
                    cout << "Invalid choice! Please try again: ";
                    cin >> new_physics_score;
                }
                it->setPhysic(new_physics_score);
                cout << "Physics score updated successfully!" << endl;
                cout << endl;
                break;
            }
            case 6: {
                cout << "Enter the new chemistry score: ";
                float new_chemical_score;
                cin >> new_chemical_score;
                while (new_chemical_score < 0 || new_chemical_score > 10) {
                    cout << "Invalid choice! Please try again: ";
                    cin >> new_chemical_score;
                }
                it->setChemical(new_chemical_score);
                cout << "Chemistry score updated successfully!" << endl;
                cout << endl;
                break;
            }
            default:
                cout << "Invalid choice! Please enter a number from 1 to 6:" << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "No student with ID " << ID_input << " found in the database." << endl;
    }
}

/*
* Function: deletee
* Description: This function is used for delete the student
* Input:	database
* Output:	none
*/
void deletee(list<Student>& database)
{
    int ID_input;
    cout << "Enter the ID of the student you want to delete: ";
    cin >> ID_input;

    for (list<Student>::iterator it = database.begin(); it != database.end(); ++it) {
        if (it->getID() == ID_input) {
            it = database.erase(it);
            cout << "Student ID: " << ID_input << " has been deleted sucessfully" << endl;
            return;
        }
    }

    cout << "No Student with ID " << ID_input << " found in the database" << endl;
}

/*
* Function: search by ID
* Description: This function is used for search the student by ID
* Input:	database
* Output:	none
*/
void search_by_ID(list <Student> &database)
{
    int ID_input;
    cout << "Enter the ID of the student: ";
    cin >> ID_input;
    for (list<Student>::iterator it = database.begin(); it != database.end(); ++it) {
        if (it->getID() == ID_input) {
            cout << "\nStudent found. Current information:" << endl;
            it->getData();
            return;
        }  
    }
     cout << "No student has this information " << endl;
}

/*
* Function: search by name
* Description: This function is used for search the student by name
* Input:	database
* Output:	none
*/
void search_by_name(list <Student> database)
{
    string student_name;
    cout << "Enter the name of the student: ";
    cin >> student_name;

    for (list<Student>::iterator it = database.begin(); it != database.end(); ++it) {
        if(it->getName() == student_name){
            cout << "\nStudent found. Current information:" << endl;
            it->getData();
            return;
        }
    }

    cout << "\n\t\t\t No student has this information " << endl; 
}

/*
* Function: Arrange Students by Name
* Description: This function is used for arrange students by name
* Input:	database
* Output:	none
*/


/*
* Function: Display list of students
* Description: This function is used for Display list of students
* Input:	database
* Output:	none
*/
void display_student(list<Student> database)
{
    if (database.empty()) {
        cout << "The student database is empty." << endl;
        return;
    }
    for (auto x : database) {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        x.getData();
    }
}