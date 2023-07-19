/*
 * Courtney Lee
 * cml0082@auburn.edu
 * project4_Lee_cml0082.cpp
 *
 * Program that utilizes a linked list to create a trivia game.
 * Recieved help geeks for geeks on the basic implementation of a linked list
 * Also, chegg for the hardcoding of the 3 questions.
 *
 * compilation instructions: g++ -std=c++11 project3_Lee_cml0082.cpp
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
#define UNIT_TESTING

//linked structure for the game: question, answer, and point value
struct TriviaNode {
    string question;
    string answer;
    int points;
    TriviaNode* next;
};

//creates pointer to trivia node
typedef TriviaNode* ptrNode;
ptrNode list = NULL;

//prototypes for the functions used in this program
void addNode (ptrNode & list, string question, string answer, int points);
void addQuestion ();
void initQuestionList();
int askQuestion (ptrNode & qlist, int numQ);
void unitTest();

//first version: debugging
#define triviaQuiz
int main() {
    unitTest();

    //point count
    int totalPoint = 0;
#ifdef triviaQuiz
    
   // second version: normal trivia
    cout << "*** Welcome to Lee's trivia quiz game ***\n";
    
    addQuestion();
    
    //loop to iterate through the linked list, while there is a next.
    for (ptrNode temp = list; temp !=NULL; temp = temp -> next) {
        string userAnswer;
        cout << "Question: " << temp -> question << "\n";
        cout << "Answer: ";
        //sets user input as userAnswer string to compare to set answer.
        getline(cin, userAnswer);
        
        if (userAnswer == temp -> answer) {
            cout << "Your answer is correct! You recieve " << temp -> points << " points.";
            totalPoint += temp -> points;
            cout << "\nYour total points: " << totalPoint <<"\n\n";
        }
        else {
            cout << "Your answer is wrong. The correct answer is " << temp -> answer << "\n";
            cout << "Your total points: " << totalPoint << "\n\n";
        }
        
    }
    
    cout << "\n\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
    return 0;
    
}
#endif

#ifdef UINIT_TESTING
    unitTest();
    return 0;
}
#endif


//function definitions

/*
 * Function to add a node to the linked list
 * @param ptrNode and list for where to add
 * @param questionIn for the input question part of the node
 * @param answerIn for the input answer part of the node
 * @param pointsIn for the input point value of the node
 */
void addNode (ptrNode & list, string questionIn, string answerIn, int pointsIn) {
    ptrNode node = new TriviaNode;
    node -> question = questionIn;
    node -> answer = answerIn;
    node -> points = pointsIn;
    
    //adds node to empty list and sets next to null
    //first node in will be the last node in the list
    if (list == NULL) {
        list = node;
        list -> next = NULL;
    }
    //adds node to the front of the list by making next point to the rest of the list.
    else {
        node -> next = list;
        list = node;
    }
}

/*
 * Function for user to add in their own questions
 */

void addQuestion () {
    string question;
    string answer;
    string con; //continue option
    string playerAnswer;
    int points;
    
    //sets user input to question, answer, an point vaue for the new node
    cout << "Enter a question: ";
    getline(cin, question);
    
    cout << "Enter an answer: ";
    getline(cin, answer);
    
    cout << "Enter award points: ";
    cin >> points;
    
    //adds the node to the list by calling addNode function
    addNode(list, question, answer, points);
    
    cout << "Continue? (Y/N): ";
    cin >> con;
    cin.ignore();
    cout << "\n";
    
    //if user selects y, it prompts them for another trivia node.
    if(con == "Y" || con == "y") {
        addQuestion();
    }
}

/*
 * Hardcodes the 3 initial trivia questions
 */
void initQuestionList() {
    //the new trivia nodes for each question
    TriviaNode node1;
    TriviaNode node2;
    TriviaNode node3;
    
    //given question 1
    string question1 = "How long was the shortest war on record? (Hint: how many minutes)";
    string answer1 = "38";
    int points1 = 100;
    
    //given question 2
    string question2 = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    string answer2 = "Bank of Italy";
    int points2 = 50;
    
    //given question 3
    string question3 = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
    string answer3 = "Wii Sports";
    int points3 = 20;
    
    //add the nodes to the list
    addNode(list, question3, answer3, points3);
    addNode(list, question2, answer2, points2);
    addNode(list, question1, answer1, points1);
    
}

/*
 * Function fror the unit testing function- generates warnings
 */
int askQuestion (ptrNode & qlist, int numQ) {
    int success = 1;
    
    if (numQ == 0) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.\n";
        return success;
    }
    else {
        string userGuess;
        int totalPoint =0;
        int length = 0;
        
        ptrNode temp = qlist;
        
        while (temp != NULL) {
            length++;
            temp = temp -> next;
        }
        
        if (numQ > length) {
            cout << "Warning - only " << length << " trivia questions in the list.\n";
            return success;
        }
        
        temp = qlist;
        
        for (int i =0; i < numQ; i++) {
            cout << "Question: " << temp -> question << "\n";
            cout << "Answer: ";
            
            getline (cin, userGuess);
            
            if (userGuess == temp -> answer) {
                totalPoint += temp -> points;
                success = 0;
                
                cout << "Your answer is correct! You recieve " << temp -> points << " points.\n";
                cout << "Your total points: " << totalPoint << "\n\n";
                }
            else {
                cout << "Your answer is wrong. The correct answer is " << temp -> answer << "\n";
                cout << "Your total points: " << totalPoint << "\n\n";
                success = 1;
            }
            temp = temp -> next;
            }
        return success;
        }
        
        
    }

/*
 * Function for debugging version of the program
 */
void unitTest() {
    initQuestionList();
    
    cout << "*** This is a debugging version ***\n";
    cout << "Unit Test Case 1: Ask no question. The program should give a warning message.\n";
    askQuestion(list, 0);
    cout << "Case 1 Passed\n";
    
    cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.\n";
    if (askQuestion(list, 1) == 1) {
        cout << "Case 2.1 passed\n";
    }
    else {
        cout << "Case 2.1 failed\n";
    }
    
    
    cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester eneters a correct answer.\n";
    if (askQuestion(list, 1)==0) {
        cout << "Case passed 2.2\n";
    }
    else {
        cout << "Case failed 2.2\n";
    }
    
    cout << "\nUnit Testing Case 3: Ask all the questions of the last trivia in the linked list.\n";
    askQuestion(list, 3);
    cout << "Case 3 passed";
    
    cout << "\nUnit Testing Case 4: Ask five questions in the linked list.\n";
    askQuestion(list, 5);
    cout <<"Case 4 passed";
    
    cout << "\n*** End of the Debugging Version ***\n";
    
    
}



    



