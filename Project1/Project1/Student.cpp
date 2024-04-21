#include "student.h"
#include<string>
/*
* Class: Student
* Function: setName
* Description: This function is used for setting name of student
* Input:   name (name of student)
* Output:  return: None
*/
void Student::setName(string _name) {
	name = _name;
}
/*
* Class: Student
* Function: getName
* Description: This function is used for getting name of student
* Input:   None
* Output:  return: name (name of student)
*/
string Student::getName() {
	return name;
}

/*
* Class: Student
* Function: setAge
* Description: This function is used for setting the age of student
* Input:   age (age of student)
* Output:  return: None
*/
void Student::setAge(int _age) {
	age = _age;
}
/*
* Class: Student
* Function: getAge
* Description: This function is used for getting the age of student
* Input:   None
* Output:  return: age (age of student)
*/
int Student::getAge() {
	return age;
}

/*
* Class: Student
* Function: setGender
* Description: This function is used for setting the gender of student
* Input:   gender (gender of student)
* Output:  return: None
*/
void Student::setGender(Gender _gender) {
	student_gender = _gender;
}

/*
* Class: Student
* Function: getGender
* Description: This function is used for getting the gender of student
* Input:   None
* Output:  return: gender (gender of student)
*/
Gender Student::getGender() {
	return student_gender;
}

/*
* Class: Student
* Function: setMath
* Description: This function is used for setting Math score of student
* Input:   _math_score (Math score of student)
* Output:  return: None
*/
void Student::setMath(double _math_score)
{
	math_score = _math_score;
}

/*
* Class: Student
* Function: getMath
* Description: This function is used for getting Math score of student
* Input:   None
* Output:  return: math_score (Math score of student)
*/
double Student::getMath()
{
	return math_score;
}

/*
* Class: Student
* Function: setPhysic
* Description: This function is used for setting Physic score of student
* Input:   _physic_score (Physic score of student)
* Output:  return: None
*/
void Student::setPhysic(double _physic_score)
{
	physic_score = _physic_score;
}

/*
* Class: Student
* Function: getPhysic
* Description: This function is used for getting Physic score of student
* Input:   None
* Output:  return: physic_score (Physic score of student)
*/
double Student::getPhysic() {
	return physic_score;
}

/*
* Class: Student
* Function: setChemical
* Description: This function is used for setting Chemical score of student
* Input:   _chemical_score (Chemical score of student)
* Output:  return: None
*/
void Student::setChemical(double _chemical_score) {
	chemical_score = _chemical_score;
}

/*
* Class: Student
* Function: getChemical
* Description: This function is used for getting Chemical score of student
* Input:   None
* Output:  return: chemical_score (Chemical score of student)
*/
double Student::getChemical() {
	return chemical_score;
}

/*
* Class: Student
* Function: getID
* Description: This function is used for getting ID of the student
* Input: None
* Output: return id
*/
int Student::getID() {
	return id;
}

/*
* Class: Student
* Function: getAverage
* Description: This function is used for calculating the average score of student
* Input: None
* Output: (math marks + physic marks + chemical marks)/3
*/
double Student::getAverage()
{
	return(math_score + chemical_score + physic_score) / 3;
}

/*
* Class: Student
* Function: setData
* Description: This function is used for setting data for student.
* Input: None
* Output: None
*/
void Student::setData() {
	string _name;
	cout << "\t\t\tEnter Name: ";
	cin >> _name;
	setName(_name);

	int _age;
	bool validInput = false;
	do {
		cout << "\t\t\tEnter Age: ";
		cin >> _age;
		if (cin.fail()) {
			cout << "Invalid input! Please enter a valid integer." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (_age < 0 || _age > 150) {
			cout << "Invalid choice! Age must be between 0 and 150." << endl;
		}
		else {
			validInput = true;
		}
	} while (!validInput);
	setAge(_age);

	string MF;
	do {
		cout << "\t\t\tEnter M for male and F for female" << endl;
		cout << "\t\t\tEnter Gender: ";
		cin >> MF;
	} while (MF != "M" && MF != "F" && MF != "m" && MF != "f");

	Gender _gender;
	if (MF == "M" || MF == "m") {
		_gender = MALE;
	}
	else {
		_gender = FEMALE;
	}

	cout << "\t\t\tEnter the student score" << endl;

	cout << "\t\t\tEnter math score: ";
	double _math_score;
	cin >> _math_score;
	setMath(_math_score);

	cout << "\t\t\tEnter chemical score: ";
	double _chemical_score;
	cin >> _chemical_score;
	setChemical(_chemical_score);

	cout << "\t\t\tEnter physic score: ";
	double _physic_score;
	cin >> _physic_score;
	setPhysic(_physic_score);
}

/*
* Class: Student
* Function: getData
* Description: This function is used for getting data for student.
* Input: None
* Output: None
*/
void Student::getData()
{
	cout << "ID: " << getID() << endl;
	
	cout << "Name: " << getName() << endl;

	cout << "Age: " << getAge() << endl;

	cout << "Gender: ";
	if (getGender() == MALE) {
		cout << "Male" << endl;
	}
	else {
		cout << "Female" << endl;
	}

	cout << "Math\t | Physic\t | Chemical\t" << endl;
	cout << getMath() << getPhysic() << getChemical() << endl;

	cout << "Average Score: " << getAverage() << endl;

	cout << "Rank: " << getRank() << endl;
	switch (getRank()) {
	case Excellent:
		cout << "Excellent" << endl;
		break;
	case Good:
		cout << "Good" << endl;
		break;
	case Average:
		cout << "Average" << endl;
		break;
	case Poor:
		cout << "Poor" << endl;
		break;
	default:
		break;
	}
}

/*
* Class: Student
* Function: getRank
* Description: This function is used for getting rank of student
* Input:   None
* Output:  return: rank (rank of student)
*/
Rank Student::getRank() {
	if (getAverage() >= 8.5 && getAverage() <= 10) {
		return Excellent;
	}
	else if (getAverage() >= 6.5 && getAverage() <= 8.49) {
		return Good;
	}
	else if (getAverage() >= 5.0 && getAverage() <= 6.49) {
		return Average;
	}
	else
		return Poor;
}