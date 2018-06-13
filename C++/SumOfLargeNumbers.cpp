/*
 * SumOfLargeNumbers.h
 *
 *  Created on: 08-Jun-2018
 *      Author: shibu
 */

#include<string>
#include<iostream>

using namespace std;

class SumOfLargeNumbers {

	public:
	//Read input values as strings
	string addNumberStrings(string input1,string input2)
	{
		//initialize necessary variables.
		int maxlen=0;
		int minlen=0;
		int carry=0; // To store the carry over value.
		int partsum=0;//To store Least Significant Digit of two digit number

		char* maxarray=new char[5];
		char* minarray=new char[5];

		//Convert strings to array of characters. Here Characters are digits.
		//Two numbers may not be of same length.
		//Following is the code to nullify the effect of numbers of unequal length.

		if(input1.length()>input2.length())
		{
			maxlen=input1.length();
			minlen=input2.length();
			maxarray = new char[maxlen];
			minarray = new char[minlen];
			input1.copy(maxarray,input1.length(),0);
			input2.copy(minarray,input2.length(),0);

		}
		else
		{
			maxlen=input2.length();
			minlen=input1.length();
			maxarray = new char[maxlen];
			minarray = new char[minlen];
			input1.copy(minarray,input1.length(),0);
			input2.copy(maxarray,input2.length(),0);

		}

		int j=maxlen;
		int* resarray=new int[maxlen]; //result size equal to size of largest number

		//Start extraction from least significant digit of both numbers
		for(int i=minlen-1;i>=0;i--)
		{
			j=j-1;
			int data1=maxarray[j]; //Extraction of character digit from array
			int data2=minarray[i];//Extraction of character digit from array

			data1=data1-48; //conversion of character digit to numeric digit
			data2=data2-48; //conversion of character digit to numeric digit

			partsum=data1+data2+carry; //Perform digit wise addition

			//Following code will take care of result of addition and carry over
			if(partsum>9)
			{
				partsum=partsum-10;
				carry=1;
			}
			else
			{
				carry=0;
			}
			resarray[j]=partsum;
		}
		j=j-1;

		//following code will take care of unequal length of numbers addition carryover
		while(j>=0)
		{
			int data1=maxarray[j];
			data1=data1-48;
			resarray[j]=data1+carry;
			if(resarray[j]>9)
			{
				resarray[j]=resarray[j]-10;
				carry=carry+1;
			}
			else
			{
				carry=0;
			}
			j=j-1;
		}

		//Conversion of result array into string.
		int range;
		char* ans=new char[maxlen];
		for(range=0;range<maxlen;range++)
		{
			char data=resarray[range]+48; //Conversion of numeric digit to character digit
			ans[range]=data;
		}
		ans[range]='\0';
		string result(ans);

		if(carry==1)
		{
			result="1"+result;
		}

		delete maxarray;
		delete minarray;
		delete resarray;


		return result;
	}
};
int main()
{
			SumOfLargeNumbers testcases;
			string ans =testcases.addNumberStrings("123456789", "999999999");
			cout<<"\nTestcase1\n";
			cout<<"123456789 + 999999999 = "<<ans;
			ans =testcases.addNumberStrings("123456789", "0000000");
			cout<<"\nTestcase2\n";
			cout<<"123456789 + 0000000 = "<<ans;
			ans =testcases.addNumberStrings("123456789", "1");
			cout<<"\nTestcase3\n";
			cout<<"123456789 + 1 = "<<ans;
			return 1;
}
