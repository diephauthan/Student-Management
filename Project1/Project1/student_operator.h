/*
* File: student_operator.h
* Author: Hau Than Diep
* Date: 4/16/20244
* Description: This file is a Student header file that program is used for storing student information
*/

#ifndef _STUDENT_OPERATOR_H
#define _STUDENT_OPERATOR_H


#include<iostream>
#include<list>
#include<fstream>
#include"student.h"


void menu(list <Student>& database);

void addStudent(list<Student>& database);

void edit_student_info(list<Student>& database);

void deletee(list<Student>& database);

void search_by_ID(list <Student> &database);

void search_by_name(list <Student> database);

void display_student(list<Student> database);

bool compareByName(const Student& a, const Student& b);
void sortbyname(list<Student>& database);

bool comparebymath(const Student& a, const Student& b);
void sortbymath(list<Student>& database);

bool comparebyphysic(const Student& a, const Student& b);
void sortbyphysic(list<Student>& database);

bool comparebychemical(const Student& a, const Student& b);
void sortbychemical(list<Student>& database);

bool comparebyaverage(const Student& a, const Student& b);
void sortbyaverage(list<Student>& database);

void display_sort_list(list<Student> database);

void handleInvalidInput();
void saveCSV(list <Student>& database);


#endif
