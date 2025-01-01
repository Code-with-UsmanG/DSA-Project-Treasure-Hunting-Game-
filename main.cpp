
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <string>
#include<fstream>

using namespace std;
void gotoRowCol(int x ,int y );
void sleep(int a);
void logo(int k);
void score();
void recordScore(string playerName, int score);
void displayLeaderboard();
int coins;
int moves;
bool ex=0;
bool win1=0;
int health;
string lev;
//...........................
void gotoRowCol(int rpos, int cpos) {
    int xpos = cpos, ypos = rpos;
    COORD scrn;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOutput, scrn);
}
void sleep(int m) {
    for (int j = 0; j < m * 21000; j++) {}
}
//........................................

void exit_()
{    ex=1;
}

void logo(int l)
{
    int r,c;
     char k =178;
  if (lev== "EASY"){
    r=3;
    c=50;
  }
  else if (lev== "MEDIUM"){
    r=3;
    c=60;
  }
   else if (lev== "HARD"){
    r=3;
    c=70;
  }
  else   {
    r=3;
    c=50;
  }
         gotoRowCol(r++,c);
    cout<<k<<k<<k<<k<<"  "<<k<<k<<k<<"  "<<k<<"   "<<k<<"  "<<k<<k<<k<< "  ";
    gotoRowCol(r++,c);
    cout<<k<<"     "<<k<<" "<<k<<"  "<<k<<"  "<<" "<<k<<"  "<<k<< "  ";
    gotoRowCol(r++,c);
    cout<<k<<" "<<k<<k<<"  "<<k<<k<<k<<"  "<<k<<k<<" "<<k<<k<<"  "<<k<<k<<k<< "  ";
    gotoRowCol(r++,c);
    cout<<k<<"  "<<k<<"  "<<k<<" "<<k<<"  "<<k<<" "<<k<<" "   <<k<<"  "<<k<<"       ";
    gotoRowCol(r++,c);
    cout<<k<<k<<k<<k<<"  "<<k<<" "<<k<<"  "<<k<<"   "<<k<<"  "<<k<<k<<k<< "  ";
}
int L=0;
void score()
{
    gotoRowCol(1,10);
    cout<<"Coins : "<<coins<<" $";
     gotoRowCol(5,10);
    cout<<"Level : "<<L<<".";
     gotoRowCol(7,10);
    cout<<lev<<".";
      gotoRowCol(3,10);
    cout<<"HEALTH LEFT :"<<health;
     gotoRowCol(9,10);
    cout<<moves<<" Moves Left ";
}
void game_over()
{
    system("cls");

    score();
    lev=" ";
    logo(1);
    gotoRowCol(15, 50);
    cout << "=========================" << endl;
    gotoRowCol(16, 50);
    cout << "        GAME OVER       " << endl;
    gotoRowCol(17, 50);
    cout << "=========================" << endl;
    gotoRowCol(18, 50);
    cout << "Thank you for playing!" << endl;
    getch(); // Wait for a key press before exiting
}

 void instructions()
 {
         system("cls");
gotoRowCol(5, 50);
    cout << "Instructions:\n";
    gotoRowCol(9, 50);
    cout << "1. Use W/A/S/D to move up/left/down/right.\n";
    gotoRowCol(10, 50);
    cout << "2. Collect coins ($) to increase your score.\n";
    gotoRowCol(11, 50);
    cout << "3. Reach the exit (E) to win the level.\n";
    gotoRowCol(12, 50);
    cout << "4. Avoid running out of moves .\n";
    gotoRowCol(13, 50);
    cout << "5. Avoid running out of Health And hitting  \"X\".   \n";
    gotoRowCol(14, 50);
    cout << "6. You can pass through "<<'\xB0' <<"  blocks\n";
     gotoRowCol(15, 50);
    cout << "7. Have fun and good luck!\n";
     gotoRowCol(16, 50);
 }

void intro() {
    system("cls");
    string lines[] = {
        "*******************************",
        "*                             *",
        "* WELCOME TO THE TREASURE HUNT*",
        "*                             *",
        "*******************************",
        "*                             *",
        "*     Get ready to navigate   *",
        "*        the mysterious       *",
        "*            maze!            *",
        "*                             *",
        "*******************************"
    };
    int c=5;
gotoRowCol(5,50);
 sleep(5000);
    for (const string& line : lines) {
         sleep(5000);
        cout << line << endl;
        gotoRowCol(c++,50);
      // Adjust the sleep duration for the desired effect
    }

    sleep(5000);
    system("cls");

    string title = "THE TREASURE HUNT";
    string subtitle = "Your challenge awaits...";

    gotoRowCol(5, 50);
    for (char c : title) {
        cout << c;
        sleep(5000);
    }

    gotoRowCol(7, 45);
    for (char c : subtitle) {
        cout << c;
        sleep(5000);
    }

    sleep(50000);
instructions();
    cout << "Press any key to start the game...";

    getch(); // Wait for a key press to proceed
    system("cls");
}




void win() {
    system("cls");
    logo(1); // Use the existing logo function to display the logo

    string lines[] = {
        "*******************************",
        "*                             *",
        "*    CONGRATULATIONS! YOU     *",
        "*       WON THE GAME!         *",
        "*                             *",
        "*******************************"
    };

    for (const string& line : lines) {
        gotoRowCol(10, 45);
        cout << line << endl;
        sleep(500); // Adjust the sleep duration for the desired effect
    }

    sleep(500);
    system("cls");

    string congrats = "CONGRATULATIONS!";
    string message = "You successfully navigated the maze!";
    string scoreMessage = "Your score is: " + to_string(coins);

    gotoRowCol(5, 40);
    for (char c : congrats) {
        cout << c;
        sleep(50);
    }

    gotoRowCol(7, 35);
    for (char c : message) {
        cout << c;
        sleep(50);
    }

    gotoRowCol(9, 38);
    for (char c : scoreMessage) {
        cout << c;
        sleep(50);
    }

    sleep(500);
    cout << "\n\nEnter your name: ";
    string playerName;
    cin >> playerName;

    recordScore(playerName, coins); // Record the score
    displayLeaderboard(); // Display the leaderboard

    win1 = 1; // Set the win flag to true
    getch(); // Wait for a key press to proceed
}

// Function to record the score to a file
void recordScore(string playerName, int score) {
    ofstream file("scores.txt", ios::app); // Open file in append mode
    if (file.is_open()) {
        file << playerName << " " << score << endl;
        file.close();
    } else {
        cout << "Unable to open file to record score." << endl;
    }
}


// Function to display the leaderboard
void displayLeaderboard() {
    ifstream file("scores.txt");
    if (!file) {
        cout << "No scores recorded yet!\n";
        return;
    }

    string playerName;
    int score;

    // Simple arrays to store names and scores
    string names[100];
    int scores[100];
    int count = 0;

    while (file >> playerName >> score) {
        names[count] = playerName;
        scores[count] = score;
        count++;
    }
    file.close();

    // Sort the scores in descending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                swap(scores[j], scores[j + 1]);
                swap(names[j], names[j + 1]);
            }
        }
    }
    system("cls");
    int c=5;
gotoRowCol(5,45);
    cout << "Leaderboard:\n";
    gotoRowCol(++c,45);
    cout << "==============================\n";
    for (int i = 0; i < count; i++) {
            gotoRowCol(++c,45);
        cout << "|"<<names[i]<<""  ;
         gotoRowCol(c,55);
        cout<< " |"<<scores[i] ;
        gotoRowCol(c,65);
        cout<< " |points|";
    }
    gotoRowCol(++c,45);
    cout << "==============================\n";
}

struct Node {
    char type; // Cell type: 'P' (player), '\xB1' (wall), '.' (path), 'E' (exit)
    Node* up;
    Node* down;
    Node* left;
    Node* right;

    Node(char t) : type(t), up(nullptr), down(nullptr), left(nullptr), right(nullptr) {}
};


void print_board_(int dimensions_x, int dimensions_y) {

   logo(1);
dimensions_x=2*dimensions_y;
    char b=178;
    int row = 11, col = 50;
    gotoRowCol(row, col);
    for (int i = 0; i <= dimensions_x ; i++) {
        cout << b;
    }

    for (int i = 0; i <= dimensions_y + 1; i++) {
        gotoRowCol(row, col);
        cout << b;
        row++;
    }
    for (int i = 0; i <= dimensions_x ; i++) {
        cout << b;
        col++;
    }
    for (int i = 0; i <= dimensions_y + 1; i++) {
        row--;
        gotoRowCol(row, col);
        cout << b;
    }
     row = 10, col = 49;
    gotoRowCol(row, col);
    for (int i = 0; i <= dimensions_x + 4; i++) {
        cout << b;
    }
     for (int i = 0; i <= dimensions_y + 2; i++) {
            gotoRowCol(++row, col);
        cout << b;
    }
     for (int i = 0; i <= dimensions_x + 2; i++) {
            gotoRowCol(row, ++col);
        cout << b;
    }
     for (int i = 0; i <= dimensions_y + 2; i++) {
            gotoRowCol(--row, col);
        cout << b;
    }
    col++;
     for (int i = 0; i <= dimensions_y + 2; i++) {
            gotoRowCol(++row, col);
        cout << b;
    }
     row = 9, col = 48;
       for (int i = 0; i <= dimensions_y + 3; i++) {
            gotoRowCol(++row, col);
        cout << b;


       }
       score();
}


// Function to display the maze
void displayMaze(Node* start,int x) {
    Node* row = start;
    int r = 12, c = 51;
    print_board_(x, x); // Print the board before rendering the maze cells
    while (row) {
        Node* col = row;
        while (col) {
            gotoRowCol(r, c);
            cout << col->type << "";
            col = col->right;
            c++;
        }
        r++;
        c = 51;
        row = row->down;
    }
    gotoRowCol(10,10);
}


// Function to MOV the player
bool MOVPlayer(Node*& player, char MOV) {
    Node* next = nullptr;
    if (MOV == 'W' && player->up && player->up->type != '\xB1') {
        next = player->up;

    } else if (MOV == 'A' && player->left && player->left->type != '\xB1') {
        next = player->left;

    } else if (MOV == 'S' && player->down && player->down->type != '\xB1') {
        next = player->down;

    } else if (MOV == 'D' && player->right && player->right->type != '\xB1') {
        next = player->right;

    }
    else if (MOV == 'E' ) {
        exit_();

    }

    if (next) {
        // Check if the next cell is the exit
        if (next->type == 'E') {
            player->type = ' '; // Set the current cell to path
            next->type = 'P';   // Set the next cell to player
            player = next;
            win1=1;
            return true;
        }

        // Check if the next cell is a teleporter ('T')


        if(next->type == '$') {
            coins = coins + 10;
        }
         if(next->type == 'X') {
           health--;
        }

        // Update the maze
        player->type = ' '; // Set the current cell to path
        next->type = 'P';   // Set the next cell to player
        player = next;      // Move the player pointer

        return true;
    }
    return false; // Invalid MOV
}
//.........................................LEVELS................................................


void level_10()
{  ex=0;
     L=10;
health=5;
lev="HARD";
moves=150;
win1=0;
    int x=30;
    Node* nodes[30][60];
char maze[30][60] = {
    {'P', '.', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.','\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X'},
    {'.', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.',},
    {'.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.'},
    {'.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.','X', '.', '.', '\xB1', '.', '\xB1', '.', '.', '$', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '$', '.', '.', '$', '$'},
    {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},
    {'X', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1'},
    {'.', '.', '.', '\xB1', '.', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','$', '\xB1', '.', '$', '$', '.', '.', '.', '.', '.', '\xB1', '.', '\xB0', '.', '\xB1', '.', '.', '\xB1', '\xB1', 'E','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '.', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', 'X', '.', '$', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '\xB1', '\xB1', '$','.', '$', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '$', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', 'X', '.', '.', '$', '.', '.', '$', '$','.', '\xB1', '$', '\xB1', '$', '\xB1', '\xB1', '.', 'X', '.',},
    {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1' },
    {'.', '.', '\xB1', '.', '\xB1', '.','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1'},
    {'.', '.', '.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1', '.', '\xB1', '.'},
    {'.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.','\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1'},
    {'.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1', '\xB1', '\xB1','.', '.', 'X', '.', '.', '$', '.', '.', '$', '$'},
    {'.', '\xB1','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1','.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1','\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.'},
{'.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.'},
    {'.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.','X', '.', '.', '\xB1', '.', '\xB1', '.', '.', '$', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '$', '.', '.', '$', '$'},
    {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},
    {'X', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1'},
    {'.', '.', '.', '\xB1', '.', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','$', '\xB1', '.', '$', '$', '.', '.', '.', '.', '.', '\xB1', '.', '\xB0', '.', '\xB1', '.', '.', '\xB1', '\xB1', 'E','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '.', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', 'X', '.', '$', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '\xB1', '\xB1', '$','.', '$', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '$', '$', '\xB1', '\xB1', '\xB1'}

    };



    // Initialize nodes and link them
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            nodes[i][j] = new Node(maze[i][j]);
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            if (i > 0) nodes[i][j]->up = nodes[i - 1][j];
            if (i < x-1) nodes[i][j]->down = nodes[i + 1][j];
            if (j > 0) nodes[i][j]->left = nodes[i][j - 1];
            if (j < (2*x)-1) nodes[i][j]->right = nodes[i][j + 1];
        }
    }

    // Start the game
    Node* player = nodes[0][0]; // Player starts at 'P'
    cout << "Navigate the maze to find the exit (E).\n";

    char MOV;
    bool gameWon = false; // Add a flag to track if the game is won

    while (!gameWon) {
        system("cls");
        displayMaze(nodes[0][0], x);
        score(); // Display the score and moves left

        cout << "MOV (W/A/S/D/E): ";
        cin >> MOV;
        if (!MOVPlayer(player, MOV)) {
            cout << "Invalid MOV!\n";
            continue;
        }

        // Decrement the moves
        moves--;

        // Check if moves are exhausted
       if (moves == 0||health==0||ex==1) {
            game_over();
            return;
        }

        system("cls");
        displayMaze(nodes[0][0], x); // Refresh the display after movement
        if (win1) {
            // Player reached the exit
            coins += 200; // Add bonus coins for winning
            win(); // Call the win function
            gameWon = true; // Set the flag to true
        }
    }

    // Free memory
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            delete nodes[i][j];
        }
    }
     system("cls");
    logo(1);
       gotoRowCol(9,50);
    cout<<"1)      FOR MAIN MENU  PRESS 1 ";
       gotoRowCol(11,50);
    cout<<"2)        PRESS ANY KEY FOR PLAY NEXT LEVEL ";
      int choice;
    gotoRowCol(18,25);
    cout<<"Enter your Choice ::" ;
    cin>>choice;
    if(choice!=1)
    {

    }
}



void level_9()
{  ex=0;
win1=0;
     L=9;
health=5;
lev="HARD";
moves=150;
    int x=30;
    Node* nodes[30][60];
char maze[30][60] = {
    {'P', '.', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.','\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.','X', '.', '.', '\xB1', '.', '\xB1', '.', '.', '$', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '$', '.', '.', '$', '$'},
    {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},

    {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},
    {'X', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1'},
    {'.', '.', '.', '\xB1', '.', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','$', '\xB1', '.', '$', '$', '.', '.', '.', '.', '.', '\xB1', '.', '\xB0', '.', '\xB0', '.', '.', '\xB1', '\xB1', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '.', '$', '\xB1', '\xB1', '\xB1'},
       {'.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1'},
    {'X', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1'},
    {'.', '.', '.', '\xB1', '.', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.'},
    {'.', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.',},
    {'.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','$', '\xB1', '.', '$', '$', '.', '.', '.', '.', '.', '\xB1', '.', '\xB0', '.', '\xB1', '.', '.', '\xB1', '\xB1', 'E','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '.', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', 'X', '.', '$', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '\xB1', '\xB1', '$','.', '$', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '$', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', 'X', '.', '.', '$', '.', '.', '$', '$','.', '\xB1', '$', '\xB1', '$', '\xB1', '\xB1', '.', 'X', '.',},
    {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1',  'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X','\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1' },
    {'.', '.', '\xB1', '.', '\xB1', '.','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1'},
    {'.', '.', '.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1', '.', '\xB1', '.'},
    {'.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.','\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1'},
    {'.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1', '\xB1', '\xB1','.', '.', 'X', '.', '.', '$', '.', '.', '$', '$'},
    {'.', '\xB1','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1','.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1','\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.'},
{'.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.'},
    {'.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.','X', '.', '.', '\xB1', '.', '\xB1', '.', '.', '$', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '$', '.', '.', '$', '$'},
   {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', 'X', '.', '$', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '\xB1', '\xB1', '$','.', '$', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '$', '$', '\xB1', '\xB1', '\xB1'}

    };



    // Initialize nodes and link them
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            nodes[i][j] = new Node(maze[i][j]);
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            if (i > 0) nodes[i][j]->up = nodes[i - 1][j];
            if (i < x-1) nodes[i][j]->down = nodes[i + 1][j];
            if (j > 0) nodes[i][j]->left = nodes[i][j - 1];
            if (j < (2*x)-1) nodes[i][j]->right = nodes[i][j + 1];
        }
    }

    // Start the game
    Node* player = nodes[0][0]; // Player starts at 'P'
    cout << "Navigate the maze to find the exit (E).\n";

    char MOV;
    bool gameWon = false; // Add a flag to track if the game is won

    while (!gameWon) {
        system("cls");
        displayMaze(nodes[0][0], x);
        score(); // Display the score and moves left

        cout << "MOV (W/A/S/D/E): ";
        cin >> MOV;
        if (!MOVPlayer(player, MOV)) {
            cout << "Invalid MOV!\n";
            continue;
        }

        // Decrement the moves
        moves--;

        // Check if moves are exhausted
       if (moves == 0||health==0||ex==1) {
            game_over();
            return;
        }

        system("cls");
        displayMaze(nodes[0][0], x); // Refresh the display after movement
        if (win1) {
            // Player reached the exit
            coins += 200; // Add bonus coins for winning
            win(); // Call the win function
            gameWon = true; // Set the flag to true
        }
    }

    // Free memory
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            delete nodes[i][j];
        }
    }
     system("cls");
    logo(1);
       gotoRowCol(9,50);
    cout<<"1)      FOR MAIN MENU  PRESS 1 ";
       gotoRowCol(11,50);
    cout<<"2)        PRESS ANY KEY FOR PLAY NEXT LEVEL ";
      int choice;
    gotoRowCol(18,25);
    cout<<"Enter your Choice ::" ;
    cin>>choice;
    if(choice!=1)
    {
      level_10();
    }
}

void level_8()
{  ex=0;
win1=0;
     L=8;
health=5;
lev="HARD";
moves=200;
    int x=30;
    Node* nodes[30][60];
char maze[30][60] = {
    {'P', '.', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.','\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X'},
   {'X', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1'},
    {'.', '.', '.', '\xB1', '.', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','$', '\xB1', '.', '$', '$', '.', '.', '.', '.', '.', '\xB1', '.', '\xB0', '.', '\xB0', '.', '.', '\xB1', '\xB1', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '.', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1' },
    {'.', '.', '\xB1', '.', '\xB1', '.','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1'},
    {'.', '.', '.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1', '.', '\xB1', '.'},

       {'.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1'},
    {'X', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1'},
    {'.', '.', '.', '\xB1', '.', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.'},
    {'.', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.',},
    {'.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','$', '\xB1', '.', '$', '$', '.', '.', '.', '.', '.', '\xB1', '.', '\xB0', '.', '\xB1', '.', '.', '\xB1', '\xB1', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '.', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', 'X', '.', '$', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '\xB1', '\xB1', '$','.', '$', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '$', '$', '\xB1', '\xB1', '\xB1'},
    {'.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', 'X', '.', '.', '$', '.', '.', '$', '$','.', '\xB1', '$', '\xB1', '$', '\xB1', '\xB1', '.', 'X', '.',},
    {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1',  'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X','\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
   {'.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.','\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1'},

    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.','X', '.', '.', '\xB1', '.', '\xB1', '.', '.', '$', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '$', '.', '.', '$', '$'},
    {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},
    {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},
     {'.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1', '\xB1', '\xB1','.', '.', 'X', '.', '.', '$', '.', '.', '$', '$'},
    {'.', '\xB1','.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1','.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '\xB1','\xB1','\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.'},
{'.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.'},
    {'.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1','\xB1', '.', '\xB0', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.','X', '.', '.', '\xB1', '.', '\xB1', '.', '.', '$', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', 'X', '.','\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '.', '$', '.', '.', '$', '$'},
   {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', 'X', '.', '$', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.','\xB1', '\xB1', '\xB1', '$','.', '$', '$', '\xB0', '\xB1', '\xB1'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.','\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1','\xB1', '\xB1', '\xB1', '$','$', '$', '$', '\xB0', 'E', '\xB1'}

    };



    // Initialize nodes and link them
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            nodes[i][j] = new Node(maze[i][j]);
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            if (i > 0) nodes[i][j]->up = nodes[i - 1][j];
            if (i < x-1) nodes[i][j]->down = nodes[i + 1][j];
            if (j > 0) nodes[i][j]->left = nodes[i][j - 1];
            if (j < (2*x)-1) nodes[i][j]->right = nodes[i][j + 1];
        }
    }

    // Start the game
    Node* player = nodes[0][0]; // Player starts at 'P'
    cout << "Navigate the maze to find the exit (E).\n";

    char MOV;
    bool gameWon = false; // Add a flag to track if the game is won

    while (!gameWon) {
        system("cls");
        displayMaze(nodes[0][0], x);
        score(); // Display the score and moves left

        cout << "MOV (W/A/S/D/E): ";
        cin >> MOV;
        if (!MOVPlayer(player, MOV)) {
            cout << "Invalid MOV!\n";
            continue;
        }

        // Decrement the moves
        moves--;

        // Check if moves are exhausted
       if (moves == 0||health==0||ex==1) {
            game_over();
            return;
        }

        system("cls");
        displayMaze(nodes[0][0], 30); // Refresh the display after movement
        if (win1) {
            // Player reached the exit
            coins += 200; // Add bonus coins for winning
            win(); // Call the win function
            gameWon = true; // Set the flag to true
        }
    }

    // Free memory
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            delete nodes[i][j];
        }
    }
     system("cls");
    logo(1);
       gotoRowCol(9,50);
    cout<<"1)      FOR MAIN MENU  PRESS 1 ";
       gotoRowCol(11,50);
    cout<<"2)        PRESS ANY KEY FOR PLAY NEXT LEVEL ";
      int choice;
    gotoRowCol(18,25);
    cout<<"Enter your Choice ::" ;
    cin>>choice;
    if(choice!=1)
    {
      level_9();
    }
}


void level_7()
{   L=7;
win1=0;
health=5;
 ex=0;
lev="MEDIUM";
moves=110;
    int x=20;
    Node* nodes[20][40];
char maze[20][40] = {
    {'P', '.', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', '$', '$', '.', '.', '.', '.', '$', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.'},
    {'\xB1', '\xB1', '\xB1', '\xB1', '\xB1', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.'},
   {'.', '.', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', '.', '$', '$', '.','\xB1', '\xB1', '.', '\xB1', '.', '.','.', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '.', '.', '.','\xB1', '\xB1', '.', '\xB1', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.'},
  {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.'},
    {'X', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '.', '.', '\xB0', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1'},
    {'.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.','.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.'},

    {'X', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '$', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '$', 'X', '\xB1', '.', '.', '\xB1', '.'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.'},
     {'.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '$', '$', '\xB1', '\xB1', '\xB1', '\xB1', '\xB1', '.', '\xB1', '.', '.', 'E', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', '\xB0', '.', '.', '$', '.', '.', '$', '$'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', '\xB0', '\xB0', '$', '.', '.', '.', '\xB1', '.','.', '.', '.'},

    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '$', '$', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.'},
    {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.'},

    {'.', 'X', '.', '.', '\xB1', '.', '\xB1', '.', '.', '$', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', 'X', '.', '.', '$', '.', '.', '$', '$'},

      {'.', '\xB1', '.', '\xB1', '.', '.', '$', '.', '\xB1', '.', 'X', '\xB1', '.', '.', 'X', '\xB1', '.', '\xB1', '.', 'X','.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.'},
    {'.', '\xB1', '\xB1', '.', '\xB1', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '\xB0', '\xB0', '$', '.', '\xB1', '.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '\xB1', '\xB1', '\xB1', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1'},
     {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.', '$', 'X', '.', '\xB1', '\xB1', '.', '\xB1', '.', '.','$', '\xB1', '.', '$', '$', '.', '.', '.', '.', '.', '\xB1', '.', '\xB0', '.', '\xB1', '.', '.', '\xB1', '\xB1', 'X'},
    {'.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', 'X', '.', '$', '\xB1', '.', '\xB1', '.', '.','.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.'},
    {'.', '.', '.', '\xB1', '\xB1', '\xB1', '.', '.', 'X', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.', '\xB1', '\xB1', '.', 'X', '.', '.', '$', '.', '.', '$', '$', '.', 'X', '\xB1', '$', '.', '.', '.', '\xB1', '.','.', '.', '.'},
   {'.', '\xB1', '.', '.', '\xB1', '.', '\xB1', '.', '.', '$', '\xB1', '\xB1', '.', '\xB1', '.', '\xB1', '.', '.', '.', '\xB1', '.', '\xB1', '.','.', '.', '.', '\xB1', '.', '\xB1', '\xB1','.', '.', 'X', '.', '.', '$', '.', '.', '$', '$'}

    };



    // Initialize nodes and link them
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            nodes[i][j] = new Node(maze[i][j]);
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            if (i > 0) nodes[i][j]->up = nodes[i - 1][j];
            if (i < x-1) nodes[i][j]->down = nodes[i + 1][j];
            if (j > 0) nodes[i][j]->left = nodes[i][j - 1];
            if (j < (x*2)-1) nodes[i][j]->right = nodes[i][j + 1];
        }
    }

    // Start the game
    Node* player = nodes[0][0]; // Player starts at 'P'
    cout << "Navigate the maze to find the exit (E).\n";

    char MOV;
    bool gameWon = false; // Add a flag to track if the game is won

    while (!gameWon) {
        system("cls");
        displayMaze(nodes[0][0], x);
        score(); // Display the score and moves left

        cout << "MOV (W/A/S/D/E): ";
        cin >> MOV;
        if (!MOVPlayer(player, MOV)) {
            cout << "Invalid MOV!\n";
            continue;
        }

        // Decrement the moves
        moves--;

        // Check if moves are exhausted
        if (moves == 0||health==0||ex==1) {
            game_over();
            return;
        }

        system("cls");
        displayMaze(nodes[0][0], x); // Refresh the display after movement
        if (win1) {
            // Player reached the exit
            coins += 200; // Add bonus coins for winning
            win(); // Call the win function
            gameWon = true; // Set the flag to true
        }
    }

    // Free memory
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < 2*x; j++) {
            delete nodes[i][j];
        }
    }
     system("cls");
    logo(1);
        gotoRowCol(9,50);
    cout<<"1)      FOR MAIN MENU  PRESS 1 ";
       gotoRowCol(11,50);
    cout<<"2)  PRESS ANY KEY FOR PLAY NEXT LEVEL ";
      int choice;
    gotoRowCol(18,25);
    cout<<"Enter your Choice ::" ;
    cin>>choice;
    if(choice!=1)
    {
        level_8();
    }
}
