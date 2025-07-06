#ifndef LAB7_H
#define LAB7_H

// Include for printing to the screen
#include <stdio.h>

// Include to use various string functions
#include <string.h>

// Macro for divider length
#define DIVIDER_LENGTH 110

// Macros for divider types
#define STAR '*'
#define DASH '-'

// Macros for standard header details
#define SCHOOL "[COLLEGE]\n"
#define LAB "Lab 7 - Numeric Arrays\n"
#define PROGRAMMER "Program Written by: [NAME]\n"

// Macros for table header details
#define FILE_HEADER "File Array"
#define CALCULATE_HEADER "Calculated Array"

// Macro for array length
#define ARRAY_LENGTH 20

// Prototypes for functions listed below
void PrintDividerStar(int *counter, FILE *pOutputFile);

void PrintDividerDash(int *counter, FILE *pOutputFile);

void PrintHeader(FILE *pOutputFile);

void PrintFileHeader(FILE *pOutputFile);

void PrintCalculateHeader(FILE *pOutputFile);

void FillFileArray(FILE *pInputFile, const int maxArrSize, int *counter, int fileArray[]);

void FillCalculateArray(const int maxArrSize, int *counter, 
	int calculatedArray[]);
	
void PrintArray(FILE *pOutputFile, const int maxArrSize, int *counter, int currentArray[]);

double CalculateAverage(int currentArray[], int *counter, const int maxArrSize);

void OutputAverages(FILE *pOutputFile, double fileAve, double calcAve);

int CalculateHighest(int currentArray[], int *counter, const int maxArrSize);

void OutputHighestData(FILE *pOutputFile, int fileHigh, int calcHigh);

void AddFive(int *fileArray, int *calculatedArray, const int maxArrSize, int *counter);

void AddElements(int fileArray[], int calculatedArray[], int *counter, const int maxArrSize);

#endif
