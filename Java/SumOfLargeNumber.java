public class SumOfLargeNumber 
{
	//Read input values as strings
	public String addNumberStrings(String input1,String input2)
	{
		//initialize necessary variables.
		int maxlen=0;
		int minlen=0;
		int carry=0; // To store the carry over value.
		int partsum=0;//To store Least Significant Digit of two digit number
		
		char [] maxarray=null;
		char [] minarray=null;
		
		//Convert strings to array of characters. Here Characters are digits.
		//Two numbers may not be of same length.
		//Following is the code to nullify the effect of numbers of unequal length.
		
		if(input1.length()>input2.length())
		{
			maxarray=input1.toCharArray();
			minarray=input2.toCharArray();
			maxlen=input1.length();
			minlen=input2.length();
		}
		else
		{
			maxarray=input2.toCharArray();
			minarray=input1.toCharArray();
			maxlen=input2.length();
			minlen=input1.length();
		}
		
		int j=maxlen; 
		int []resarray=new int[maxlen]; //result size equal to size of largest number
		
		//Start extraction from least significant digit of both numbers
		for(int i=minlen-1;i>=0;i--) 
		{
			j=j-1;
			int data1=maxarray[j]; //Extraction of character digit from array1
			int data2=minarray[i];//Extraction of character digit from array2
			
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
		
		//Convertion of result array into string.
		
		String ans=new String();
		for(int range=0;range<maxlen;range++)
		{
			ans=ans+resarray[range];
		}
		if(carry==1)
		{
			ans="1"+ans;
		}
		return ans;
	}
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		SumOfLargeNumber testcases=new SumOfLargeNumber();
		String ans =testcases.addNumberStrings("123456789", "999999999");
		System.out.println("Testcase1");
		System.out.println("123456789 + 999999999 = "+ans);
		ans =testcases.addNumberStrings("123456789", "0000000");
		System.out.println("Testcase2");
		System.out.println("123456789 + 0000000 = "+ans);
		ans =testcases.addNumberStrings("123456789", "1");
		System.out.println("Testcase3");
		System.out.println("123456789 + 1 = "+ans);
	}
}