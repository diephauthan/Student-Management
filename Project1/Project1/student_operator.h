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
#include"student.h"

void menu(list <Student>& database);

void addStudent(list<Student>& database);

void edit_student_info(list<Student>& database);

void deletee(list<Student>& database);

void search_by_ID(list <Student>& database);

void search_by_name(list <Student>& database);

#endif
