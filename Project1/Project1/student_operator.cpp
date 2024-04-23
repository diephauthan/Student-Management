#include "student_operator.h"

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

                    bool validInput = false;
                    while (!validInput) {
                        cout << "\n\n\t\t\t 1. Add another student " << endl;
                        cout << "\t\t\t 0. Back to Menu " << endl;
                        cout << "\t\t\tEnter the choice: ";

                        if (!(cin >>choice)) {
                            handleInvalidInput();
                        }
                        else {
                            validInput = true;
                        }
                    }

                    if (choice == 1) {
                        adding_another = true;
                    }
                    else if (choice == 0) {
                        adding_another = false;
                    }
                    else {
                        adding_another = false;
                    }
                } while (adding_another);
				
				break;
			}

			case 2: // Edit Student Info
			{
                bool edit_another = true;
                do
                {
                    cout << "\n-----------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Edit Student Info ---------------------------------------------" << endl;
                    edit_student_info(database);
                    cout << "1. Go back " << endl;
                    cout << "0. Back to Menu " << endl;
                    bool validInput = false;
                    while (!validInput) {
                        cout << "Enter the choice: ";
                        if (!(cin >> choice)) {
                            handleInvalidInput();
                        }
                        else {
                            validInput = true;
                        }
                    }

                    if (choice == 1) {
                        edit_another = true;
                    }
                    else if (choice == 0) {
                        edit_another = false;
                    }
                    else {
                        cout << "Invalid choice. Please try again.";
                        edit_another = false;
                    }
                } while (edit_another);

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
                    
                    while (!(cin >> choice)) {
                        cout << endl;
                        handleInvalidInput();
                    }

                    if (choice == 1) {
                        delete_another = true;
                    }
                    else if (choice == 0) {
                        delete_another = false;
                    }
                    else {
                        cout << "Invalid choice. Please try again.";
                        delete_another = false;
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
                    //cin >> choice;
                    while (!(cin >> choice)) {
                        cout << endl;
                        handleInvalidInput();
                    }

                    switch (choice) {
                        case 1: {
                                search_by_name(database);
                                cout << endl;
                                cout << "1. Search another student" << endl;
                                cout << "0. Back to Menu" << endl;
                                cout << "Enter The Choice: ";
                                while (!(cin >> choice)) {
                                    cout << endl;
                                    handleInvalidInput();
                                }

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
                            while (!(cin >> choice)) {
                                cout << endl;
                                handleInvalidInput();
                            }

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

            case 5: // Sort student
            {
                bool continuesort = false;
                do
                {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    cout << "------------------------------------- Sort Student ---------------------------------------------" << endl;
                    cout << "1. Sort by name" << endl;
                    cout << "2. Sort by math score" << endl;
                    cout << "3. Sort by physic score" << endl;
                    cout << "4. Sort by chemical score" << endl;
                    cout << "5. Sort by avarage score" << endl;
                    cout << "0. Back to Menu" << endl;
                    cout << "Enter The Choice: ";
                    while (!(cin >> choice)) {
                        cout << endl;
                        handleInvalidInput();
                    }

                    switch (choice)
                    {
                        case 1: {
                            sortbyname(database);
                            display_sort_list(database);
                            cout << endl;
                            cout << "1. Sort another type" << endl;
                            cout << "0. Back to Menu" << endl;
                            cout << "Enter The Choice: ";
                            while (!(cin >> choice)) {
                                cout << endl;
                                handleInvalidInput();
                            }

                            if (choice == 1) {
                                continuesort = true;
                            }
                            else {
                                continuesort = false;
                            }
                            
                            break;
                        }
                        case 2: {
                            sortbymath(database);
                            display_sort_list(database);
                            cout << endl;
                            cout << "1. Sort another type" << endl;
                            cout << "0. Back to Menu" << endl;
                            cout << "Enter The Choice: ";
                            while (!(cin >> choice)) {
                                cout << endl;
                                handleInvalidInput();
                            }

                            if (choice == 1) {
                                continuesort = true;
                            }
                            else {
                                continuesort = false;
                            }

                            break;
                        }
                        case 3: {
                            sortbyphysic(database);
                            display_sort_list(database);
                            cout << endl;
                            cout << "1. Sort another type" << endl;
                            cout << "0. Back to Menu" << endl;
                            cout << "Enter The Choice: ";
                            while (!(cin >> choice)) {
                                cout << endl;
                                handleInvalidInput();
                            }

                            if (choice == 1) {
                                continuesort = true;
                            }
                            else {
                                continuesort = false;
                            }

                            break;
                        }
                        case 4: {
                            sortbychemical(database);
                            display_sort_list(database);
                            cout << endl;
                            cout << "1. Sort another type" << endl;
                            cout << "0. Back to Menu" << endl;
                            cout << "Enter The Choice: ";
                            while (!(cin >> choice)) {
                                cout << endl;
                                handleInvalidInput();
                            }

                            if (choice == 1) {
                                continuesort = true;
                            }
                            else {
                                continuesort = false;
                            }

                            break;
                        }
                        case 5: {
                            sortbyaverage(database);
                            display_sort_list(database);
                            cout << endl;
                            cout << "1. Sort another type" << endl;
                            cout << "0. Back to Menu" << endl;
                            cout << "Enter The Choice: ";
                            while (!(cin >> choice)) {
                                cout << endl;
                                handleInvalidInput();
                            }

                            if (choice == 1) {
                                continuesort = true;
                            }
                            else {
                                continuesort = false;
                            }

                            break;
                        }
                        case 0: {
                            break;
                            continuesort = false;
                        }
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            continuesort = true;
                        break;
                    }
                } while (continuesort);
                break;
            }


            case 6: // Display student list
            {
                cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                cout << "------------------------------------- Student List ---------------------------------------------" << endl;
                display_student(database);
                cout << endl;
                cout << "Press any number to Back to Menu " << endl;
                while (!(cin >> choice)) {
                    cout << endl;
                    handleInvalidInput();
                }
                break;
            }
            
            case 7:
            {
                bool check = false;
                do
                {
                    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
                    // save_data();
                    saveCSV(database);
                    cout << "------------------------------------- Successfully Save Data --------------------------------------------" << endl;
                    cout << endl;
                    cout << "Press any number to Back to Menu " << endl;
                    while (!(cin >> choice)) {
                        cout << endl;
                        handleInvalidInput();
                    }
                } while (check);
                
                    break;
            }
            case 0:
            {
                exit_program = true;
                break;
            }
			default:
                cout << "Invalid choice. Please try again.";
                exit_program = false;
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
    list<Student>::iterator it;

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
                break;
            }
        }
 
      if (!found) {
            cout << "No student with ID " << ID_input << " found in the database." << endl;
        }
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
* Function: compare by name
* Description: This function is used for compare 2 students by name
* Input:	database
* Output:	none
*/
bool compareByName(const Student& a, const Student& b) {
    return a.getName() < b.getName();
}

/*
* Function: sort by name
* Description: This function is used for sort students name by using compare by name function
* Input:	database
* Output:	none
*/
void sortbyname(list<Student>&database) {
    database.sort(compareByName);
}

/*
* Function: compare by math
* Description: This function is used for compare 2 students by math
* Input:	database
* Output:	none
*/
bool comparebymath(const Student& a, const Student& b) {
    return a.getMath() > b.getMath();
}

/*
* Function: sort by math
* Description: This function is used for sort students math by using compare by math function
* Input:	database
* Output:	none
*/
void sortbymath(list<Student>& database) {
    database.sort(comparebymath);
}

/*
* Function: compare by physic
* Description: This function is used for compare 2 students by physic
* Input:	database
* Output:	none
*/
bool comparebyphysic(const Student& a, const Student& b) {
    return a.getPhysic() > b.getPhysic();
}

/*
* Function: sort by physic
* Description: This function is used for sort students physic by using compare by physic function
* Input:	database
* Output:	none
*/
void sortbyphysic(list<Student>& database) {
    database.sort(comparebyphysic);
}

/*
* Function: compare by chemical
* Description: This function is used for compare 2 students by chemical
* Input:	database
* Output:	none
*/
bool comparebychemical(const Student& a, const Student& b)
{
    return a.getChemical() > b.getChemical();
}

/*
* Function: sort by chemical
* Description: This function is used for sort students chemical by using compare by chemical function
* Input:	database
* Output:	none
*/
void sortbychemical(list<Student>& database) {
    database.sort(comparebychemical);
}

/*
* Function: compare by average
* Description: This function is used for compare 2 students by average
* Input:	database
* Output:	none
*/
bool comparebyaverage(const Student& a, const Student& b) {
    return a.getAverage() > b.getAverage();
}

/*
* Function: sort by average
* Description: This function is used for sort students average by using compare by average function
* Input:	database
* Output:	none
*/
void sortbyaverage(list<Student>& database) {
    database.sort(comparebyaverage);
}

/*
* Function: Display sort list
* Description: This function is used for Display the list is sorted
* Input:	database
* Output:	none
*/
void display_sort_list(list<Student> database)
{
    if (database.empty()) {
        cout << "The student database is empty." << endl;
        return;
    }

    cout << "Ordinals| ID\t\t| Name\t\t| Sex\t\t| Average Score\t| Rank\t\t" << endl;

    int stt = 1;
    for (list<Student>::iterator it = database.begin(); it != database.end(); ++it) {
        cout << setw(3) << left << stt++ << "\t|  ";
        cout << setw(5) << left << it->getID() << "\t|  ";
        cout << setw(5) << left << it->getName() << "\t|  ";
        
        string gender; 
        int gendervalue = it->getGender();
        if (gendervalue == 0) {
            gender = "Male"; 
        }
        else {
            gender = "Female";
        }
        cout << setw(5) << left << gender << "\t|  "; 
        cout << setw(10) << left << it->getAverage() << "\t|  ";

        string rank; 
        int rankValue = it->getRank(); 
        if (rankValue == 0) {
            rank = "Excellent";
        }
        else if (rankValue == 1) {
            rank = "Good"; 
        }
        else if (rankValue == 2) {
            rank = "Average";
        }
        else {
            rank = "Poor";
        }
        cout << setw(7) << left << rank << "\n"; 

    }
}

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

    cout << "Ordinals| ID\t\t| Name\t\t| Sex\t\t| Math\t| Physic| Chemical\t| Average Score | Rank" << endl;

    int stt = 1;
    for (list<Student>::iterator it = database.begin(); it != database.end(); ++it) {
        cout << setw(3) << left << stt++ << "\t|  ";
        cout << setw(5) << left << it->getID() << "\t|  ";
        cout << setw(5) << left << it->getName() << "\t|  ";

        string gender;
        int gendervalue = it->getGender();
        if (gendervalue == 0) {
            gender = "Male";
        }
        else {
            gender = "Female";
        }
        cout << setw(5) << left << gender << "\t|  ";
        cout << setw(3) << left << it->getMath() << "\t|  ";
        cout << setw(3) << left << it->getPhysic() << "\t|  ";
        cout << setw(5) << left << it->getChemical() << "\t|  ";
        cout << setw(5) << left << it->getAverage() << "\t|  ";

        string rank;
        int rankValue = it->getRank();
        if (rankValue == 0) {
            rank = "Excellent";
        }
        else if (rankValue == 1) {
            rank = "Good";
        }
        else if (rankValue == 2) {
            rank = "Average";
        }
        else {
            rank = "Poor";
        }
        cout << setw(7) << left << rank << "\n";

    }
}

/*
* Function: Handle Invalid Input
* Description: This function is used for Handle Invalid Input in menu function
* Input:	database
* Output:	none
*/
void handleInvalidInput() {
    cout << "Invalid input. Please enter an integer." << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*
* Function: savecsv
* Description: This function is used for saving into database_sv.csv
* Input:   database (student list)
* Output:  return: None
*/
void saveCSV(list<Student>& database) {
    ofstream file;
    file.open("database_sv.csv");

    file << "ID,Name,Gender,Math,Physic,Chemical,Average" << endl;

    for (auto& it : database) {
        file << it.getID() << ',' << it.getName() << ',' << it.getGender() << ',' << it.getMath() << "," << it.getPhysic() << ',' << it.getChemical() << ',' << it.getAverage() << endl;
    }

    file.close();
}