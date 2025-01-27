#ifndef ASSN_H
#define ASSN_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <unistd.h>

using namespace std;

extern string student_Name;
extern string student_ID;
extern string divider;



void toUpperCase(string &str);
void promptUserToPressEnterToContinue();
void displayInfo();
int displayMenu();
void computeArea();
void reportShapes();

void sortShape();

 
#endif