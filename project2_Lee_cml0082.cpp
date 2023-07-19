/*
 * Courtney Lee
 * cml0082@auburn.edu
 * project2_Lee_cml0082.cpp
 *
 * Program to use probabilites to determine the outcome of a three person duel
 */Users/courtneylee/Documents/project2_Lee_cml0082.cpp
 * I used the hints provided for this project
 *
 * I consulted Stack Overflow for the 'press any key' command
 *
 * compliation instructions: g++ project2_Lee_cml0082.cpp
 */

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

//TABS
 
bool atleastTwoAlive (bool aAlive, bool bAlive, bool cAlive);
void aShoots1(bool & bAlive, bool & cAlive);
void bShoots(bool & aAlive, bool & cAlive);
void cShoots(bool & aAlive, bool & bAlive);
void aShoots2(bool & bAlive, bool & cAlive);
void pressAnyKey(void);

void test_atleastTwoAlive(void);
void test_aShoots1(void);
void test_bShoots(void);
void test_cShoots(void);
void test_aShoots2(void);

//variables
const int TOTAL_RUNS = 10000;
int aWin1 = 0;
int bWin = 0;
int cWin = 0;
int aWin2 = 0;
bool aAlive = true;
bool bAlive = true;
bool cAlive = true;

// MAIN DRIVING

int main() {
    cout << "*** Welcome to Lee's Duel Simulator***\n";
    srand((int)time(0));
    
    test_atleastTwoAlive();
    pressAnyKey();
    test_aShoots1();
    pressAnyKey();
    test_bShoots();
    pressAnyKey();
    test_cShoots();
    pressAnyKey();
    test_aShoots2();
    pressAnyKey();
    
    //Strategy 1
    cout << "Ready to test strategy 1 (run 10000 times): \n";
    pressAnyKey();
    
    //loop
    
    for (int i = 0; i < TOTAL_RUNS; i++) {
        //reset the lives for each loop
          aAlive = true;
          bAlive = true;
          cAlive = true;
        
        while (atleastTwoAlive(aAlive, bAlive, cAlive)) {
            aShoots1(bAlive, cAlive);
            bShoots(aAlive, cAlive);
            cShoots(aAlive, bAlive);
        }
        //increment for being the last person standing
        if (aAlive == true) {
            aWin1 ++;
        }
        if (bAlive == true) {
            bWin ++;
        }
        if (cAlive == true) {
            cWin ++;
    }
    }
    
    cout << "Aaron won " << aWin1 << "/10000 duels or " << static_cast<double>(aWin1) / TOTAL_RUNS * 100 << "%\n"
    
        << "Bob won " << bWin << "/10000 duels or " << static_cast<double>(bWin) / TOTAL_RUNS * 100 << "%\n"
    
        << "Charlie won" << cWin << "/10000 duels or " << static_cast<double>(cWin) / TOTAL_RUNS * 100 << "%\n"
        << endl;
    
    
    //Strategy 2
    cout << "Ready to test strategy 2 (run 10000 times): \n";
    pressAnyKey();
    
    //reinitialize bob and charlie wins
    bWin = 0;
    cWin = 0;
    
    //loop for second strategy
    for (int i = 0; i < TOTAL_RUNS; i++) {
        //reset the alives for each loop
          aAlive = true;
          bAlive = true;
          cAlive = true;
        
        while (atleastTwoAlive(aAlive, bAlive, cAlive)) {
            aShoots2(bAlive, cAlive);
            bShoots(aAlive, cAlive);
            cShoots(aAlive, bAlive);
        }
        if (aAlive == true) {
            aWin2 ++;
        }
        if (bAlive == true) {
            bWin ++;
        }
        if (cAlive == true) {
            cWin ++;
    }
    }
    cout << "Aaron won " << aWin2 << "/10000 duels or " << static_cast<double>(aWin2) / TOTAL_RUNS * 100 << "%\n"
    
        << "Bob won " << bWin << "/10000 duels or " << static_cast<double>(bWin) / TOTAL_RUNS * 100 << "%\n"
    
        << "Charlie won " << cWin << "/10000 duels or " << static_cast<double>(cWin) / TOTAL_RUNS * 100 << "%\n"
        << endl;
    
    
    if (aWin1 > aWin2) {
        cout << "Strategy 1 is better than strategy 2.\n";
    }
    else {
        cout << "Strategy 2 is better than strategy 1.\n";
    }
    return 0;
}


// IMPLEMENTATION OF FUNCTIONS

/*
 * Function to determine if the duel will continue
 * returns true to continue.
 * return false if not.
 */
bool atleastTwoAlive(bool aAliveS, bool bAliveS, bool cAliveS) {
    aAliveS = aAlive;
    bAliveS= bAlive;
    cAliveS = cAlive;
    
    if (((aAlive == true) & (bAlive == true)) || ((aAlive == true) & (cAlive == true)) ||
        ((bAlive == true) & (cAlive == true))) {
        return true;
    }
    return false;
}


void test_atleastTwoAlive(void) {
    cout << "Unit Testing 1: Function - atleastTwoAlive()\n";
    bool aaron_a = true;
    bool bob_a = true;
    bool charlie_a = true;
    cout <<"\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(atleastTwoAlive(aaron_a, bob_a, charlie_a));
    cout << "\tCase passed ...\n";
    
    aaron_a = false;
    bob_a = true;
    charlie_a = true;
    cout <<"\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(atleastTwoAlive(aaron_a, bob_a, charlie_a));
    cout << "\tCase passed ...\n";
    
    aaron_a = true;
    bob_a = false;
    charlie_a = true;
    cout <<"\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(atleastTwoAlive(aaron_a, bob_a, charlie_a));
    cout << "\tCase passed ...\n";
    
    aaron_a = true;
    bob_a = true;
    charlie_a = false;
    cout <<"\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(atleastTwoAlive(aaron_a, bob_a, charlie_a));
    cout << "\tCase passed ...\n";
    
    aaron_a = false;
    bob_a = false;
    charlie_a = true;
    cout <<"\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(atleastTwoAlive(aaron_a, bob_a, charlie_a));
    cout << "\tCase passed ...\n";
    
    aaron_a = false;
    bob_a = true;
    charlie_a = false;
    cout <<"\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(atleastTwoAlive(aaron_a, bob_a, charlie_a));
    cout << "\tCase passed ...\n";
    
    aaron_a = true;
    bob_a = false;
    charlie_a = false;
    cout <<"\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(atleastTwoAlive(aaron_a, bob_a, charlie_a));
    cout << "\tCase passed ...\n";
    
    aaron_a = false;
    bob_a = false;
    charlie_a = false;
    cout <<"\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(atleastTwoAlive(aaron_a, bob_a, charlie_a));
    cout << "\tCase passed ...\n";
}

/*
 * Function to determine who Aaron shoots and if he hits them.
 * Generates a random number 0-2, where 1 = hit
 * everything else misses - representing 1/3 accuracy
 * Strategy 1: Aaron aims for Charlie if he's alive, Bob otherwise.
 */

void aShoots1(bool & bAliveS, bool & cAliveS) {
    bAliveS = bAlive;
    cAliveS = cAlive;
    if (atleastTwoAlive(aAlive, bAlive, cAlive)) {
    int shoot = (rand() % 3);
    if (aAlive == true & shoot == 1) {
        if (cAliveS == true) {
            cAlive = false;
        }
        else {
            bAlive = false;
        }
    }
}
}


void test_aShoots1(void) {
    cout << "Unit Testing 2: Function aShoots1(bAlive, cAlive)\n";
    //
    bool bob_a = true;
    bool charlie_a = true;
    cout << "\tCase 1: Bob alive, Charlie alive\n"
    << "\t\tAaron is shooting at Charlie\n";
    aShoots1(bob_a, charlie_a);
    
    bob_a = false;
    charlie_a = true;
    cout << "\tCase 2: Bob dead, Charlie alive\n"
    <<"\t\tAaron is shooting at Charlie\n";
    aShoots1(bob_a, charlie_a);
    
    bob_a = true;
    charlie_a = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n"
    << "\t\tAaron is shooting at Bob\n";
    aShoots1(bob_a, charlie_a);
}

/*
 * Function to determine who Bob shoots and if he hits them.
 * Generates a random number 0-1, where 1 = hit
 * 0 misses - representing 1/2 accuracy
 * Aims for Charlie if he's alive, and Aaron otherwise.
 */
void bShoots(bool & aAliveS, bool & cAliveS) {
    aAliveS = aAlive;
    cAliveS = cAlive;
    if (atleastTwoAlive(aAlive, bAlive, cAlive)) {
    int shoot = (rand() % 2);
    if (bAlive == true & shoot == 1) {
        if (cAliveS == true) {
            cAlive = false;
    }
        else {
            aAlive = false;
        }
}
}
}

void test_bShoots(void) {
    cout << "\nUnit Testing 3: Function bShoots(aAlive, cAlive)\n";
    //
    bool aaron_a = true;
    bool charlie_a = true;
    cout << "\tCase 1: Aaron alive, Charlie alive\n"
    << "\t\tBob is shooting at Charlie\n";
    bShoots(aaron_a, charlie_a);
    
    aaron_a = false;
    charlie_a = true;
    cout << "\tCase 2: Aaron dead, Charlie alive\n"
    <<"\t\tBob is shooting at Charlie\n";
    bShoots(aaron_a, charlie_a);
    
    aaron_a = true;
    charlie_a = false;
    cout << "\tCase 3: Aaron alive, Charlie dead\n"
    <<"\t\tBob is shooting at Aaron\n";
    bShoots(aaron_a, charlie_a);
    
}
/*
 * Function to determine who Charlie kills
 * Kills Bob if he's alive, and Aaron otherwise
 */

void cShoots(bool & aAliveS, bool & bAliveS) {
    aAliveS = aAlive;
    bAliveS = bAlive;
    if ((cAlive == true) &(atleastTwoAlive(aAlive, bAlive, cAlive))) {
        if (bAliveS == true) {
         bAlive = false;
        }
        else {
            aAlive = false;
        }
}
}

void test_cShoots(void) {
    cout << "Unit Testing 4: Function cShoots(aAlive, bAlive)\n";
    //
    bool aaron_a = true;
    bool bob_a = true;
    cout <<"\tCase 1: Aaron alive, Bob alive\n"
    <<"\t\tCharlie is shooting at Bob\n";
    cShoots(aaron_a, bob_a);
    
    aaron_a = false;
    bob_a = true;
    cout << "\tCase 2: Aaron dead, Bob alive\n"
    <<"\t\tCharlie is shooting at Bob\n";
    cShoots(aaron_a, bob_a);
    
    aaron_a = true;
    bob_a = false;
    cout << "\tCase 3: Aaron alive, Bob dead\n"
    << "\t\tCharlie is shooting at Aaron\n";
    cShoots(aaron_a, bob_a);
}

/*
 * Function to determine who Aaron shoots and if he hits them.
 * Generates a random number 0-2, where 1 = hit
 * everything else misses - representing 1/3 accuracy
 * Strategy 2: Aaron intentionally misses the first shot, then
 * he aims for Charlie if he's alive, Bob otherwise.
 */

void aShoots2(bool & bAliveS, bool & cAliveS) {
    bAliveS = bAlive;
    cAliveS = cAlive;
    int shoot;
    if (aAlive == true) {
        
        //if both charlie and bob are alive (first shot) Aaron intentionally misses
        if ((cAlive == true) & (bAlive == true)) {
        shoot = 0;
        }
        
        //if not, then aaron has a 1/3 chance of hitting his target.
        else {
            shoot = (rand() % 3);
        
        if ((atleastTwoAlive(aAlive, bAlive, cAlive)) & (shoot == 1)) {
            if (cAliveS == true) {
                cAlive = false;
            }
            else {
                bAlive = false;
            }
        }
    }
}
}

    

void test_aShoots2(void) {
    cout << "Unit Testing 5: Function aShoots1(bAlive, cAlive)\n";
    //
    bool bob_a = true;
    bool charlie_a = true;
    cout << "\tCase 1: Bob alive, Charlie alive\n"
    << "\t\t\tAaron intentionally misses his first shot\n"
    <<"\t\tBoth Bob and Charlie are alive\n";
    aShoots2(bob_a, charlie_a);
    
    bob_a = false;
    charlie_a = true;
    cout << "\tCase 2: Bob dead, Charlie alive\n"
    <<"\t\tAaron is shooting at Charlie\n";
    aShoots2(bob_a, charlie_a);
    
    bob_a = true;
    charlie_a = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n"
    << "\t\tAaron is shooting at Bob\n";
    aShoots2(bob_a, charlie_a);
}

//consulted stack overflow on how to prompt user to hit any key.
void pressAnyKey(void) {
    cout <<"Press any key to continue...\n";
    cin.get();
}


