// Includes header details in header file
#include "Lab7.h"

// Creates main function
int main(void)
{
	// Declare integers necessary for main
	int counter;
	int fileHighest;
	int calculatedHighest;
	
	// Declare doubles necessary for main
	double calculatedAverage;
	double fileAverage;
	
	// Create integer arrays
	int calculatedArray[ARRAY_LENGTH];
	int fileArray[ARRAY_LENGTH];
	
	// Declare two file pointers
	FILE* pInputFile = fopen("Lab7_Data.txt", "r");
	FILE* pOutputFile = fopen("Lab7_Output.txt", "w");
	
	// Print Star Divider
	PrintDividerStar(&counter, pOutputFile);

	// Print standard header to the screen
	PrintHeader(pOutputFile);

	// Print a bunch of symbols across the screen
	PrintDividerStar(&counter, pOutputFile);
	
	// Determines if the text file contains contents
	if (pInputFile != NULL)
	{
		// Function call to fill the file array
		FillFileArray(pInputFile, ARRAY_LENGTH, &counter, fileArray);
		
		// Function call to fill the calculated array
		FillCalculateArray(ARRAY_LENGTH, &counter, calculatedArray);
		
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
	
		// Print File header to the screen
		PrintFileHeader(pOutputFile);
	
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
		
		// Function call to print array with file array
		PrintArray(pOutputFile, ARRAY_LENGTH, &counter, fileArray);
		
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
	
		// Print File header to the screen
		PrintCalculateHeader(pOutputFile);
	
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
		
		// Function call to print array with calculated array
		PrintArray(pOutputFile, ARRAY_LENGTH, &counter, calculatedArray);
		
		// Function call to calculate average of file array
		fileAverage = CalculateAverage(fileArray, &counter, ARRAY_LENGTH);
		
		// Function call to calculate average of calculated array
		calculatedAverage = CalculateAverage(calculatedArray, &counter, ARRAY_LENGTH);
		
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
		
		// Function call to output both averages to the screen
		OutputAverages(pOutputFile, fileAverage, calculatedAverage);
		
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
		
		// Function call to calculate highest of file array
		fileHighest = CalculateHighest(fileArray, &counter, ARRAY_LENGTH);
		
		// Function call to calculate highest of calculated array
		calculatedHighest = CalculateHighest(calculatedArray, &counter, ARRAY_LENGTH);
		
		// Function call to output both highest values to the screen
		OutputHighestData(pOutputFile, fileHighest, calculatedHighest);
		
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
		
		// Function call to add 5 to each index of the arrays
		AddFive(fileArray, calculatedArray, ARRAY_LENGTH, &counter);
		
		// Function call to add calculated array to file array
		AddElements(fileArray, calculatedArray, &counter, ARRAY_LENGTH);
	
		// Print File header to the screen
		PrintFileHeader(pOutputFile);
	
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
		
		// Function call to print array with file array
		PrintArray(pOutputFile, ARRAY_LENGTH, &counter, fileArray);
		
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
	
		// Print File header to the screen
		PrintCalculateHeader(pOutputFile);
	
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
		
		// Function call to print array with calculated array
		PrintArray(pOutputFile, ARRAY_LENGTH, &counter, calculatedArray);
		
		// Function call to calculate average of file array
		fileAverage = CalculateAverage(fileArray, &counter, ARRAY_LENGTH);
		
		// Function call to calculate average of calculated array
		calculatedAverage = CalculateAverage(calculatedArray, &counter, ARRAY_LENGTH);
		
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
		
		// Function call to output both averages to the screen
		OutputAverages(pOutputFile, fileAverage, calculatedAverage);
		
		// Print Dash Divider
		PrintDividerDash(&counter, pOutputFile);
		
		// Function call to calculate highest of file array
		fileHighest = CalculateHighest(fileArray, &counter, ARRAY_LENGTH);
		
		// Function call to calculate highest of calculated array
		calculatedHighest = CalculateHighest(calculatedArray, &counter, ARRAY_LENGTH);
		
		// Function call to output both highest values to the screen
		OutputHighestData(pOutputFile, fileHighest, calculatedHighest);
	}
	else
	{
		// Print error message to the screen
		printf("File did not open\n");
		
	}
	
	// Closes both the input and output files
	fclose(pInputFile);
	fclose(pOutputFile);
	
	// Return 0 to end main
	return 0;
	
}
