/*
 * SumOfLargeNumbers.c
 *
 *  Created on: 08-Jun-2018
 *      Author: shibu
 */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//A function to find the length of the string
int find_length(char* input)
{
	int i=0;
	while(input[i]!='\0')
	{
		i=i+1;
	}
	return i;
}

char* addNumberStrings(char* input1, char* input2)
{
	char* output;

	int input1_length=find_length(input1);
	int input2_length=find_length(input2);

	//initialize necessary variables.
	int maxlen = 0;
	int minlen = 0;
	int carry = 0; // To store the carry over value.
	int partsum = 0; //To store Least Significant Digit of two digit number

	char *maxarray;
	char *minarray;

	//Convert strings to array of characters. Here Characters are digits.
	//Two numbers may not be of same length.
	//Following is the code to nullify the effect of numbers of unequal length.

	if (input1_length > input2_length) {
		maxlen = input1_length;
		minlen = input2_length;
		maxarray = (char*) calloc(maxlen,sizeof(char));
		minarray = (char*) calloc(minlen,sizeof(char));
		maxarray=input1;
		minarray=input2;

	} else {
		maxlen = input2_length;
		minlen = input1_length;
		maxarray = (char*) calloc(maxlen,sizeof(char));
		minarray = (char*) calloc(minlen,sizeof(char));
		minarray=input1;
		maxarray=input2;
	}

	int j = maxlen;
	int* resarray = (int*) calloc(maxlen,sizeof(int)); //result size equal to size of largest number

	//Start extraction from least significant digit of both numbers
	for (int i = minlen - 1; i >= 0; i--) {
		j = j - 1;
		int data1 = maxarray[j]; //Extraction of character digit from array
		int data2 = minarray[i]; //Extraction of character digit from array

		data1 = data1 - 48; //conversion of character digit to numeric digit
		data2 = data2 - 48; //conversion of character digit to numeric digit

		partsum = data1 + data2 + carry; //Perform digit wise addition

		//Following code will take care of result of addition and carry over
		if (partsum > 9) {
			partsum = partsum - 10;
			carry = 1;
		} else {
			carry = 0;
		}
		resarray[j] = partsum;
	}
	j = j - 1;

	//following code will take care of unequal length of numbers addition carryover
	while (j >= 0) {
		int data1 = maxarray[j];
		data1 = data1 - 48;
		resarray[j] = data1 + carry;
		if (resarray[j] > 9) {
			resarray[j] = resarray[j] - 10;
			carry = carry + 1;
		} else {
			carry = 0;
		}
		j = j - 1;
	}

	//Conversion of result array into string.
	int range;
	char* ans = (char*) calloc(maxlen,sizeof(char));

	for (range = 0; range < maxlen; range++) {
		char data = resarray[range] + 48; //Conversion of numeric digit to character digit


		ans[range] = data;
	}
	ans[range] = '\0';

	char* final_ans=(char*)calloc(maxlen+1,sizeof(char));
	output=ans;
	if (carry == 1)
	{
		int i=0;
		while(ans[i]!='\0')
		{
			final_ans[i+1]=ans[i];
			i=i+1;
		}
		final_ans[i+1]='\0';
		final_ans[0]='1';

		output=final_ans;
	}

	free(maxarray);
	free(minarray);
	free(resarray);
	free(ans);
	free(final_ans);

	return output;
}

int main() {
	// TODO Auto-generated method stub

	printf("%s",addNumberStrings("99999999999999999","99999999999999"));
	return 0;
}

