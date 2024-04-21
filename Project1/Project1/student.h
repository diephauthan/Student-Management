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
	Student(string name, int age, Gender gender, double math, double physic, double chemical) :
	name(name), age(age), student_gender(gender), math_score(math), physic_score(physic), chemical_score(chemical) {
		static int ID = 202401;
		id = ID;
		ID++;
	}

	Student();

	void setName(string _name);
	string getName();

	void setAge(int _age);
	int getAge();

	void setGender(Gender _gender);
	Gender getGender();

	void setMath(double _math_score);
	double getMath();


	void setPhysic(double _physic_score);
	double getPhysic();

	void setChemical(double _chemical_score);
	double getChemical();

	int getID();

	double getAverage();

	Rank getRank();

	void setData();
	void getData();
};


#endif