//
/*
* Courtney Lee
* cml0082@auburn.edu
* project3_Lee_cml0082.cpp
*
* Program to merge the numbers in two files into another file.
* Recieved help regarding syntax and basics of I/O in C++ from Caleb Curry's YouTube videos
*
* compilation instructions: g++ -std=c++11 project3_Lee_cml0082.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


// DECLARE FUNCTIONS


// function to check if the file exsists and is valid
bool checkFile(string);

// function to read the input file stream
vector<int>readFile(string);


// function to merge the two vectors
vector<int> merge (vector<int>, vector<int>);


// function to write the output file
void writeFile(string, vector<int>);



/*
 * Merges the numbers in the two specified files and write the numbers
 * in another file in ascending order
 *
 * @return 1 if program is successful
 */

int main() {
   //variables
   string fileName;
   
   
   cout <<"*** Welcome to Lee's sorting program ***\n";
   
   //file 1
   cout << "Enter the first input file name: ";
   cin >> fileName;
   checkFile(fileName);
   vector<int>numbers1 = readFile(fileName);
   
   cout << "The list of " << numbers1.size() << " numbers in file " << fileName << " is:\n";
   
   for(int i = 0; i < numbers1.size(); i++) {
      cout << numbers1.at(i) << "\n";
   }
   
   if(cin.fail() || !checkFile(fileName)) {
      return 0;
   }
   
   
   //file 2
   cout << "\nEnter the second input file name: ";
   cin >> fileName;
   checkFile(fileName);
   vector<int>numbers2 = readFile(fileName);
    
   cout << "The list of " << numbers2.size() << " numbers in file " << fileName << " is:\n";
    
   for(int j = 0; j < numbers2.size(); j++) {
      cout << numbers2.at(j) << "\n";
   }
    
   if(cin.fail() || !checkFile(fileName)) {
      return 0;
   }
   
   
   

      //merging files
   vector<int>numbers3 = merge(numbers1, numbers2);
   
   cout<< "\nThe sorted list of " << numbers3.size() << " numbers is: ";
    
   for(int k = 0; k < numbers3.size(); k++) {
      cout << numbers3.at(k) << " ";
   }
   
   //writing the file
   string outputFile;
    
   cout << "\nEnter the output file name: ";
   cin >> outputFile;
    
   writeFile(outputFile, numbers3);
   
   //confirmation message
   
   cout<< "*** Please check the new file - " << outputFile << "***\n"
      << "*** Goodbye. ***";
}


//DEFINING FUNCTIONS

// function to check if the file exsists and is valid
bool checkFile(string file) {
   ifstream stream;
   
   // check if file exists
   stream.open(file.c_str());
   
   if(stream.fail()) {
      cout << "No file found ";
      return false;
   }
   
   stream.close();
   return true;
}


// function to read the input file stream
vector<int>readFile(string file) {
   
   ifstream stream(file);
   
   vector<int> numbers;

   if (stream) {
      int i;
   
      while(stream >> i) {
         numbers.push_back(i);
      }
   }
   stream.close();
   return numbers;

}

// function to merge the two vectors
vector <int> merge(vector<int> num1, vector <int> num2) {
   //variables
   vector<int> outNum; //consolidated vector
      
// concatenate the vectors
   //recieved help from stack overflow about the syntax for concatenating two vectors into a new vector
   outNum.reserve(num1.size() + num2.size());
   outNum.insert(outNum.end(), num1.begin(), num1.end());
   outNum.insert(outNum.end(), num2.begin(),num2.end());
   
   //sort- consulted an my old project for this algorithm
   
   for (int i = 0; i < outNum.size(); i++) {
      int min = i;
      for (int j = i + 1; j < outNum.size(); j++) {
         if ((outNum.at(j))< (outNum.at(min))) {
            min = j;
         }
      }
      swap(outNum.at(i),outNum.at(min));
   }
   
   
   
   return outNum;
}



// function to write the output file
void writeFile (string file, vector<int> numbers) {
   ofstream outFile(file);
   
   for(int number : numbers) {
      outFile << number << endl;
   }
   
}


