/*
* File: Student.h
* Author: Hau Than Diep
* Date: 4/16/2024
* Description: This file is a Student header file that program is used for storing student information
*/

#ifndef _STUDENT_H
#define _STUDENT_H

#include<iostream>
#include <string>
#include <iomanip>

using namespace std;

typedef enum Gender
{
	MALE,
	FEMALE
}Gender;

typedef enum Rank
{
	Excellent,
	Good,
	Average,
	Poor,
}Rank;

class Student
{
private:
	int id; 
	string name;
	int age;
	Gender student_gender;
	double math_score;
	double physic_score;
	double chemical_score;

public:
	Student(int id, string name, int age, Gender gender, double math, double physic, double chemical) : id(id),
	name(name), age(age), student_gender(gender), math_score(math), physic_score(physic), chemical_score(chemical) {
	}

	//Student() {}
	Student() : id(), name(""), age(0), student_gender(Gender::MALE), math_score(0.0), physic_score(0.0), chemical_score(0.0) {
		static int ID = 202401;
		id = ID;
		ID++;
	}

	void setName(string _name);
	string getName() const;

	void setAge(int _age);
	int getAge();

	void setGender(Gender _gender);
	Gender getGender();

	void setMath(double _math_score);
	double getMath() const;


	void setPhysic(double _physic_score);
	double getPhysic() const;

	void setChemical(double _chemical_score);
	double getChemical() const;

	int getID();

	double getAverage() const;

	Rank getRank();

	void setData();
	void getData();

	//void sortdisplay();
};



#endif