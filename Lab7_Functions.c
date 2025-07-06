// Includes header details in header file
#include "Lab7.h"

//-----------------------------------------------------------------------------
// Function Name: PrintDividerStar
// Description: Prints a line of 110 stars as a divider to the screen.
//
//-----------------------------------------------------------------------------
void PrintDividerStar(int *counter, FILE *pOutputFile)
{
	// Initialize LCV (Loop Control Variable) to 0
	*counter = 0;
	
	// Print a bunch of symbols across the screen
	while (*counter < DIVIDER_LENGTH)
	{
		// Print one character to the screen
		fprintf(pOutputFile, "%c", STAR);

		// Increment counter
		(*counter)++;
	}
	// Move the cursor down to the next line
	fprintf(pOutputFile, "\n");
}

//-----------------------------------------------------------------------------
// Function Name: PrintDividerDash
// Description: Prints a line of 110 dashes as a divider to the screen.
//
//-----------------------------------------------------------------------------
void PrintDividerDash(int *counter, FILE *pOutputFile)
{
	// Initialize LCV (Loop Control Variable) to 0
	*counter = 0;
	
	// Print a bunch of symbols across the screen
	while (*counter < DIVIDER_LENGTH)
	{
		// Print one character to the screen
		fprintf(pOutputFile, "%c", DASH);

		// Increment counter
		(*counter)++;
	}
	
	// Move the cursor down to the next line
	fprintf(pOutputFile, "\n");
}

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description: Prints the standard header, including the school name, lab name 
// and programmer name to the screen.
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE *pOutputFile)
{
	// Print header to the screen
    fprintf(pOutputFile, SCHOOL);
    fprintf(pOutputFile, LAB);
    fprintf(pOutputFile, PROGRAMMER);
}

//-----------------------------------------------------------------------------
// Function Name: PrintFileHeader
// Description: Prints the table header, including the phrase file array to 
// the screen.
//
//-----------------------------------------------------------------------------
void PrintFileHeader(FILE *pOutputFile)
{
	// Print Header to the screen
	fprintf(pOutputFile, "%25s\n", FILE_HEADER);
}

//-----------------------------------------------------------------------------
// Function Name: PrintCalculateHeader
// Description: Prints the table header, including the phrase file array to 
// the screen.
//
//-----------------------------------------------------------------------------
void PrintCalculateHeader(FILE *pOutputFile)
{
	// Print Header to the screen
	fprintf(pOutputFile, "%30s\n", CALCULATE_HEADER);
}

//-----------------------------------------------------------------------------
// Function Name: FillFileArray
// Description: Obtains data from an input file and fills an integer array with
// the data from each line of the file
//
//-----------------------------------------------------------------------------
void FillFileArray(FILE *pInputFile, const int maxArrSize, int *counter, int fileArray[])
{
    // Declares variable to store number from input file
    int fileNumber;

    // Initialize counter to 0
    *counter = 0;

    // Loop to determine value of each index of array
    for (*counter = 0; *counter < maxArrSize; (*counter)++)
    {
        // Read a number from the file
        if (fscanf(pInputFile, "%d", &fileNumber) != 1)
        {
            // Exits loop if there is no current value
            break;
        }

        // Assign the number to the current index of the array
        fileArray[*counter] = fileNumber;
    }
}


//-----------------------------------------------------------------------------
// Function Name: FillCalculateArray
// Description: Starts with the first index being equal to zero for the 
// calculated array and then either divides by 2 or multiplies by 3 and adds
// 1 depending on whether the previous number was even or odd.
//
//-----------------------------------------------------------------------------
void FillCalculateArray(const int maxArrSize, int *counter, int calculatedArray[])
{
    // Initializes first index of calculatedArray
    calculatedArray[0] = 75;
	
	// Declare variable to check for number 1;
	int hasBeenOne = 0;

    // Loop to determine value of each index of array
    for(*counter = 1; *counter < maxArrSize; (*counter)++)
	{
        // If statement to determine whether previous value is even or odd
		if(calculatedArray[(*counter) - 1] % 2 == 0)
		{
			calculatedArray[*counter] = (calculatedArray[(*counter) - 1] / 2);
		}
		// Case if previous value is odd
		else
		{
			calculatedArray[*counter] = (calculatedArray[(*counter) - 1] * 3) + 1;
		}
		
		// Turns any value past the number 1 to zero
		if(hasBeenOne == 1)
		{
			calculatedArray[*counter] = 0;
		}
		
		// Sets hasBeenOne to 1 if a value has been one
		if(calculatedArray[*counter] == 1)
		{
			// Exits while loop
			hasBeenOne = 1;
		}
		
    }
}

//-----------------------------------------------------------------------------
// Function Name: PrintArray
// Description: Prints out an array one index at a time with evenly spaced
// outputs. Shifts to next line after each fifth index outputted.
//
//-----------------------------------------------------------------------------
void PrintArray(FILE *pOutputFile, const int maxArrSize, int *counter, int currentArray[])
{
	// Loop continues 20 loops
	for(*counter = 0; *counter < maxArrSize; (*counter)++)
	{
		// Prints current index of array
		fprintf(pOutputFile, "%-10d", currentArray[*counter]);
		
		// Moves to the next line every fifth time through the loop
		if((*counter + 1) % 5 == 0)
		{
			// Moves to next line
			fprintf(pOutputFile, "\n");
		}
		
	}
	
}

//-----------------------------------------------------------------------------
// Function Name: CalculateAverage
// Description: Calculates the average of all non-zero values within an array
// and returns the average as a double.
//
//-----------------------------------------------------------------------------
double CalculateAverage(int currentArray[], int *counter, const int maxArrSize)
{
	// Initialize total count
	int total = 0;
	
	// Initialize return variable
	double average = 0;
	
	// Continues array until value is zero or twenty loops
	for(*counter = 0; *counter < maxArrSize; (*counter)++)
	{	
		// Adds current index to total
		total += currentArray[*counter];

		// Exits loop if the current array index is 0
		if(currentArray[*counter] == 0)
		{
			// Exits loop
			break;
		}
		
	}
	
	// Calculates the average value
	average = (double)total/(*counter);
	
	// Returns the average value
	return average;
	
}

//-----------------------------------------------------------------------------
// Function Name: OutputAverages
// Description: Prints the averages of both the file and calculated arrays to
// the screen.
//
//-----------------------------------------------------------------------------
void OutputAverages(FILE *pOutputFile, double fileAve, double calcAve)
{
	// Prints out file average to the screen
	fprintf(pOutputFile, "File Array Average: %f\n", fileAve);
	
	// Prints out calculated average to the screen
	fprintf(pOutputFile, "Calculated Array Average: %f\n", calcAve);
	
}

//-----------------------------------------------------------------------------
// Function Name: CalculateHighest
// Description: Sorts through each value of a given array and returns the
// highest value inside.
//
//-----------------------------------------------------------------------------
int CalculateHighest(int currentArray[], int *counter, const int maxArrSize)
{
	// Initialize highest value return variable
	int highest = 0;
	
	// Loop will continue through twenty loops
	for(*counter = 0; *counter < maxArrSize; (*counter)++)
	{
		// Checks if the current index of array is greater than previous highest
		if(currentArray[*counter] > highest)
		{
			// Sets the highest to the current index of array
			highest = currentArray[*counter];
		}
		
	}
	
	return highest;
	
}

//-----------------------------------------------------------------------------
// Function Name: OutputHighestData
// Description: Prints the highest values of both the file and calculated
// arrays to the screen.
//
//-----------------------------------------------------------------------------
void OutputHighestData(FILE *pOutputFile, int fileHigh, int calcHigh)
{
	// Prints the file highest to the screen
	fprintf(pOutputFile, "File Array Highest: %d\n", fileHigh);
	
	// Prints the calculated highest to the screen
	fprintf(pOutputFile, "Calculated Array Highest: %d\n", calcHigh);
	
}

//-----------------------------------------------------------------------------
// Function Name: AddFive
// Description: Adds 5 to the value of each non-zero index of both arrays.
//
//-----------------------------------------------------------------------------
void AddFive(int *fileArray, int *calculatedArray, const int maxArrSize, int *counter)
{	
	
	// Attach pointers to arrays
	int *filePointer = fileArray;
	int *calculatedPointer = calculatedArray;
	
	// Loop will continue through full size of array
	for(*counter = 0; *counter < maxArrSize; (*counter)++)
	{
		// Increases each index of file array by 5
		*filePointer += 5;
		
		// Moves to the next index of the array
		filePointer++;
		
	}
	
	// Loop will continue through full size of array
	for(*counter = 0; *counter < maxArrSize; (*counter)++)
	{
		// Increases each index of file array by 5
		*calculatedPointer += 5;
		
		// Moves to the next index of the array
		calculatedPointer++;
		
		// Exits loop if the calculated array index is 0
		if(*calculatedPointer == 0)
		{
			// Exits loop
			break;
		}
	}
	
}

//-----------------------------------------------------------------------------
// Function Name: AddElements
// Description: Adds the value of the current index of calculated array to the
// current index of file array.
//
//-----------------------------------------------------------------------------
void AddElements(int fileArray[], int calculatedArray[], int *counter, const int maxArrSize)
{
	// Loop will continue through full size of array
	for(*counter = 0; *counter < maxArrSize; (*counter)++)
	{
		// Adds current index of calculated array to file array
		fileArray[*counter] += calculatedArray[*counter];
		
		// Exits loop if the calculated array index is 0
		if(calculatedArray[*counter] == 0)
		{
			// Exits loop
			break;
		}
		
	}
	
}
