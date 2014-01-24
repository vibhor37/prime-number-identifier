#include <iostream>
#include <time.h>
using namespace std;
bool isPrime(int number){
//sets i to two
	int i = 2;
	//if number is divisible by 2(even numbers), the number is not a prime number except if the number is two.
    if(number%i==0){ 
	//if the number is greater than two it returns false, meaning, the number is not a prime number
		if(number>2) return false;
		//however if the number is not greater than 2, then ofcourse the number has to be 2(we are not dealing with zeroes and negative numbers) so it returns true
		else return true;
		};
	//i is then incremented.
    i++;
	//Beginning of while loop. Loop will run until i is less than half of number.
    while(i<(number/2)){
		//if number is divisible by i then the number is not a prime number as it was divided by a number other than itself or 1.
        if(number % i == 0) return false;
        /*i is incremented by 2 instead of 1 because the number is odd and odd numbers is never divisible by an even number.
		Even * Odd = Even Even * Even = Even Odd * Odd = Odd so if it not a prime number it would be useless 
		to check every time if it is divisible by an even number because the program knows it is odd.*/
		i+=2;
	}
	//Function returns true if the number has not been identified as not prime by the loop(if it had been identified as a composite number, then the function would have ended returning false)
    if(number == 1) return false;
	return true;
}
void loop(int start, int end){
	//[Warning: Jargon]loop takes in two arguments. start, that is the number from which the range of numbers from which prime numbers will be identified starts.
	//end is ofcourse the end of the range
	//i is set to start because start should not be incremented so using i instead.
	int i = start;
    //prime is declared and set to 0. This variable is set to the number of prime numbers present in the range.
	int prime = 0;
	//This loop increments the range and checks if the number is prime or composite by passing the current number, i, into the isPrime function.
    while(i<=end){
        //isPrime function is run
		if(isPrime(i)){
			//if function returns true(the number is prime), the number is outputted into the console.
            cout << i << endl;
			//prime is incremented, signifying that there is an increase in the number of prime number in the range(hopefully, I make sense)
            prime++;
		}
		//i is incremented and the loop runs(if i is less or equal to end) meaning the loop checks if the next number is a prime as well.
        i++;
	}
	//While Loop ends. The number of prime numbers found in the range is outputted into the console.
    cout << "Number of Prime Numbers: " << prime << endl;
}
int main(){
	//Outputs introduction to the program and instructions
	cout<<"This program allow you to find out all the prime numbers within a specified range quite efficiently" << endl;
	cout<<"Programmed by Asif Mallik" << endl;
	//Command is set to an empty string
	string command = "start";
	//Loop runs when the command is set to start.
	while(command=="start"){
		//two clock_t type objects are instantiated. 
		clock_t startTime, endTime;
		//two integer are declared(starting and ending numbers of the loop)
		int start, end;
		//self explanatory.
		cout<<"Range beginning number: ";
		cin>>start;
		cout<<"Range ending number: ";
		cin>>end;
		//start is set to the current clock time.
		startTime = clock();
		loop(start, end);
		//end is set to the current clock time.
		endTime = clock();
		//difference in time in second is found by first finding difference between the two times in clock then converting it to second by dividing it by their ratio.
		float timeTaken (((float)endTime - (float)startTime)/CLOCKS_PER_SEC);
		//self explanatory.
		cout << "Time Taken(in seconds): " << timeTaken << endl;
		cout << "Type \"start\" and hit enter in order to use the program again. Enter anything else to exit the program." << endl;
		cin >> command;
	}
	//program ends
	return 0;
}
