/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void getOffer(ofstream&, float); // prototype 

int main()
{
    int i = 0; // used for array for loop
    float numDeal[25]; // use array to read all numbers and print if needed
    
    float offer; // intialize the offer calculation
    int caseNum = 25; // intializer of the integer value in charge of monitoring how many cases left
    
    ofstream penner; // second writer to store banker offer(s)
    penner.open("fileb.txt"); // open the writer for the getoffer function
    
    
    
    // ofstream writer here to write in all the boxes first and their values after
    ofstream writer;
    writer.open("file.txt");
    writer << "Box1" << endl;
    writer << "1000000" << endl;
    writer << "Box2" << endl;
    writer << "100" << endl;
    writer << "Box3" << endl;
    writer << "400000" << endl;
    writer << "Box4" << endl; 
    writer << "500" << endl;
    writer << "Box5" << endl;
    writer << "300" << endl;
    writer << "Box6" << endl;
    writer << "50000" << endl;
    writer << "Box7" << endl;
    writer << "50" << endl;
    writer << "Box8" << endl;
    writer << "75" << endl;
    writer << "Box9" << endl;
    writer << "10" << endl;
    writer << "Box10" << endl;
    writer << "100000" << endl;
    writer << "Box11" << endl; 
    writer << "5" << endl;
    writer << "Box12" << endl;
    writer << "500000" << endl;
    writer << "Box13" << endl;
    writer << "400" << endl;
    writer << "Box14" << endl;
    writer << "5000" << endl;
    writer << "Box15" << endl;
    writer << "25000" << endl;
    writer << "Box16" << endl; 
    writer << "200000" << endl;
    writer << "Box17" << endl;
    writer << "200" << endl;
    writer << "Box18" << endl;
    writer << "1" << endl;
    writer << "Box19" << endl;
    writer << "750" << endl;
    writer << "Box20" << endl;
    writer << ".01" << endl;
    writer << "Box21" << endl;
    writer << "10000" << endl;
    writer << "Box22" << endl;
    writer << "1000" << endl;
    writer << "Box23" << endl;
    writer << "25" << endl;
    writer << "Box24" << endl;
    writer << "300000" << endl;
    writer << "Box25" << endl;
    writer << "750000" << endl;
    writer << "Box26" << endl;
    writer << "75000" << endl;

    writer.close(); // close writer file
    
    // read the box and their values into the array
    string box_reader; // reads box
    int numBox;
    float deal_amount;
    ifstream reader;
    reader.open("file.txt"); // opens reader
    

    while(reader) // while loop using extraction operator to read deal amounts into array
    {
        reader >> box_reader;
        
        reader >> deal_amount;
        
        numDeal[i] = deal_amount;
        
        i++;
    }

    // ask user for their name 
    string userName;
    cout << "Welcome to Howard University's Edition of Deal or No Deal! What is your name?" << endl;
    cin >> userName;
    
    // print users name with a simple greeting
    cout << "It is a blessing to have you " << userName << ". Let's begin the game!" << endl;
    
    // just simple rules of the game
    cout << "THE RULES OD THE GAME:" << endl;
    cout << "The host will allow you to pick a box of the 25 boxes displayed. After you" << endl;
    cout << "select one, the banker will offer up a deal to accept in place for the box you have." << endl;
    cout << "Along the way, you will be asked to open various boxes. If you decide not to open any boxes," << endl;
    cout << "then you will formally submit to the banker's deal, in trade of your box you select in the beginning" << endl;
    cout << "but if you do not accept his deal, you will be able to take home what is inside of the box you selected." << endl;
    
    cout << " " << endl; // just a space to organize black box
    
    // allowung user to pick their box in allignment with array
    cout << userName << ", why don't you go ahead and select the box you will keep." << endl; 
    cout << "There are a number of different boxes. Choose your destiny now! (Pick number between 0-25)" << endl;
    cin >> numBox;
    
    bool keepGoing = true;
    char answer = ' ';
    while(keepGoing == true) // bool while loop to keep steps 6-11 running in the case user rejects deal
    {
    // STEP 6
    int box1, box2, box3, box4, box5; // 0(N) // intializers
    cout << userName << " it is now time for you to open 5 boxes. Select your first out of 26." << endl;
    cin >> box1; // O(N) // cins to show intitalizers
    cin >> box2; // O(N)
    cin >> box3; // O(N)
    cin >> box4; // O(N)
    cin >> box5; // O(N)
    
    int max_value = 0; // O(N) // intializer
    
    for(int i = 0; i < 25; i++) // finds max value for float offer ; O(N) 
    {
        if(i != box1 && i != box2 && i != box3 && i != box4 && i != box5) // O(N)
        {
            if(numDeal[i] > max_value) // O(N)
                max_value = numDeal[i]; // O(N)
            
        }
        else
            numDeal[i] = 0; // O(N)
    }
    
    /// STEP 7 & 8
    
    
    if(keepGoing = true) // O(N)
    {
        caseNum = caseNum - 5; // O(N)
    }  
    
    
    
    offer = 10000 - (214.74 * caseNum) + (.040 * max_value); // int offer to calculate offer ; // O(N)
    
    // using offer calculation, bankers offer is shown here
    cout << userName << ", our banker is prepared to offer you: "; // O(N)
    cout << "$" << fixed << showpoint << setprecision(2) << offer << " dollars/cents." << endl; // O(N) // iomanip to organize float numbers
            for(int i = 0; i < 25; i++) // O(N*N) // for loops to show boxes left for user to pick
            {
                if(numDeal[i] == 0) // O(N*N)
                    cout << 0 << " "; // O(N*N)
                else
                    cout << i << " "; // O(N*N)
            }
    
    
    // used to accept or reject deal
    cout << " " << endl; 
    cout << "Do we have a deal or would you like to reject this offer? (Type D to accept offer/ N to reject offer) " << endl; // O(N)
    cin >> answer; // O(N)
    
    
    if(answer == 'N' || answer == 'n') // O(N) // if N, steps 6-11 repeat
        {
            keepGoing = true; // O(N)
            
        }
    else if(answer == 'd' || answer == 'D') // O(N) // if D, code ends
        {
            keepGoing = false; // O(N)
            
            cout << "Thank you for playing DEAL ... or NO DEAL!" << endl; // O(N)
        }
    else // O(N)
        {
        keepGoing = false; // O(N)
        
            cout << "This game has reached an error. Please try and start over again." << endl; // O(N)
        }
    
    }
    
    getOffer(penner, offer); // function call for banker offer // O(N)
    
    
    // ask user to see other boxes
    string user_option; // intializer
    cout << "Would you like to see what was in the other boxes? Type yes or no." << endl;
    cin >> user_option;
    if(user_option == "Yes" || "yes") // if statement if user says yes
        {
            for(int i = 0; i < 25; i++) // for loop to print deal amounts of all other boxes
            {
                 cout << numDeal[i] << endl;
            }
        }
    else if(user_option == "No" || "no") // if no, code ends ...
        {
            return 0;
        }
    else
        cout << "Error!" << endl;

    // STEP TO SHOW MONEY AMOUNTS
    cout << "Let's look on how you did:" << endl;
    cout << "Your winnings: " << offer << endl;
    cout << "Potential winnings: " << numDeal[numBox] << endl;
   
        
   return 0;
   
   
}
    
void getOffer(ofstream& penner, float offer) // definition
{
    penner << offer << endl;
}


// TASKS THAT STILL NEED TO BE DONE
/*
- make sure array is reading properly (done)
- make sure banker offer is writing to file (done)
- add potential winnings and winnings of user (done)
    - userbox for pt winnings and winnings = offer_accepted
- fix caseNum & max_value to make sure offer is correct (done)
- make sure all array can print out (done)

- add time complexity to bool loop // (done)
- add comments to every code line // (done) 
- clean up the code make it look more organized :)

You will receive points for utilizing the following topics:
setw/setprecision   [1 point] USED
reading from a file [1 point] USED
if statements   [1 point] USED
loops   [1 point] USED
functions   [1 point] USED
reference parameters   [1 point] USED
arrays   [1 point] USED
time complexity   [1 point] USED
linked lists   [1 point]
writing to a file   [1 point] USED

potential EC grade: 9 EC POINTS

*/






