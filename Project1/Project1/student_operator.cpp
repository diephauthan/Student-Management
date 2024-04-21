#include "student_operator.h"

void menu(list <Student>& database)
{
	int choice = 0;
	do {
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
			cout << "\t\tEnter The Choice: " << endl;
			cin >> choice;

		switch (choice)
		{
			case 1: // Add A New Student.
			{
				bool adding_another = true;
				while (adding_another) {
					cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
					cout << "------------------------------------- Add A New Student ---------------------------------------------" << endl;
					addStudent(database);

					cout << "\n\n\t\t\t 1. Add another student " << endl;
					cout << "\t\t\t 0. Exit " << endl;
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
				}
				break;
			}

			case 2: // Edit Student Info
			{
                bool edit_another = true;
                while (edit_another) {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Edit Student Info ---------------------------------------------" << endl;
                    edit_student_info(database);
                    cout << "\n\n\t\t\t 1. Go back " << endl;
                    cout << "\t\t\t 0. Exit " << endl;
                    cout << "\t\t\tEnter the choice: ";

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
                    cout << "------------------------------------- Delete Student ---------------------------------------------" << endl;
                    deletee(database);
                    cout << "\n\n\t\t\t 1. Go back " << endl;
                    cout << "\t\t\t 0. Exit " << endl;
                    cout << "\t\t\tEnter the choice: ";
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
			default:
				break;
		}
	
	}while (choice != 0);
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
* Function: edit 
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
                break;
            }
            case 2: {
                cout << "Enter the new age: ";
                short int new_age;
                cin >> new_age;
                it->setAge(new_age);
                cout << "Student age updated successfully!" << endl;
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
                break;
            }
            case 4: {
                cout << "Enter the new math score: ";
                float new_math_score;
                cin >> new_math_score;
                it->setMath(new_math_score);
                cout << "Math score updated successfully!" << endl;
                break;
            }
            case 5: {
                cout << "Enter the new physics score: ";
                float new_physics_score;
                cin >> new_physics_score;
                it->setPhysic(new_physics_score);
                cout << "Physics score updated successfully!" << endl;
                break;
            }
            case 6: {
                cout << "Enter the new chemistry score: ";
                float new_chemical_score;
                cin >> new_chemical_score;
                it->setChemical(new_chemical_score);
                cout << "Chemistry score updated successfully!" << endl;
                break;
            }
            default:
                cout << "Invalid choice! Please enter a number from 1 to 6." << endl;
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

    cout << "No Student with ID " << ID_input << "found in the database" << endl;
}