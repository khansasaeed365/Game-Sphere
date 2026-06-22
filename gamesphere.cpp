#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;
void hospitalGame();
bool gameOver = false;
void ticTacToeGame();
void hangmanGame ();
void chessGame();
int getNumber()
    {
    int num;

    while(!(cin >> num))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input! Enter number again: ";
    }

    return num;
    }
// Inventory
string inventory[5];
int itemCount = 0;
string playerName ;
int totalAttempts = 0 ;   // count wrong ans

// ADD ITEMS IN INVENTORY
void addItem(string item)
 {
    inventory[itemCount] = item;
    itemCount++;
 }

// INT VALIDATION 
int getValidInt() {
    int num;
    while (true) {
        cin >> num;
        if (cin.fail())  
        {
            cin.clear();       // only reset data 
            cin.ignore(1000, '\n');  // clean buffer
            cout << "Invalid input! Enter numbers only: ";
        }
       else 
       {
            return num;
       }
    }
}

  // STRING VALIDATION
string getValidString() 
{
    string word;
    while (true) 
    {
        cin >> word;
        bool isValid = true;
        for (int i = 0; i < word.length(); i++) {
            if (isdigit(word[i])) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            return word;
        } else {
            cout << "Invalid input! Enter letters only: ";
        }
    }
}

void displayIntro() {
    cout << "==============================================" << endl;
    cout << "                                              " << endl;
    cout << "          ABANDONED HOSPITAL ESCAPE           " << endl;
    cout << "          Can you make it out alive...?       " << endl;
    cout << "                                              " << endl;
    cout << "==============================================" << endl;
    cout << "Enter your name, if you dare: ";
    playerName = getValidString () ;
    cout << "Welcome, " << playerName << "... let's hope you make it out." << endl;
}

void displayRules() {
    cout << "==============================================" << endl;
    cout << "               HOW TO PLAY                   " << endl;
    cout << "==============================================" << endl;
    cout << "- Solve puzzles to escape each room          " << endl;
    cout << "- You have 3 attempts per room               " << endl;
    cout << "- Wrong answers cost you chances             " << endl;
    cout << "- Collect all items to escape!               " << endl;
    cout << "==============================================" << endl;
}

void room1() {
    cout << "==============================================" << endl;
    cout << "          ROOM 1 - MAIN ENTRANCE             " << endl;
    cout << "==============================================" << endl;
    cout << "You wake up on a cold, wet floor.            " << endl;
    cout << "The smell of rust and rotting flesh fills the air." << endl;
    cout << "You find a TORN DIARY. It reads:             " << endl;
    cout << "'The key lies where the year of tragedy began.'" << endl;
    cout << "A locked drawer sits in front of you.        " << endl;
    cout << "==============================================" << endl;

    int ans;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Enter the 4-digit code (" << attempts << " attempts left): ";
        ans = getValidInt();

        if (ans == 1947) {
            cout << "==============================================" << endl;
            cout << "*CLICK*....                                   " << endl ;
            cout << "The drawer opens...                           " << endl;
            cout << "You found a RUSTY KEY!                       " << endl;
            cout << "==============================================" << endl;
            addItem("Rusty Key");
            cout << "Press ENTER to continue..." << endl;
            cin.ignore();
            cin.get();    // wait until user press enter
            return;
        } 
        else {
            attempts--;
            totalAttempts++;
            if (attempts > 0) {
                cout << "Wrong code. Something growls in the darkness..." << endl;
            }
        }
    }

    cout << "==============================================" << endl;
    cout << "The lights go out completely.                " << endl;
    cout << "You never made it out.                       " << endl;
    cout << "=== GAME OVER ===                            " << endl;
    cout << "==============================================" << endl;
    gameOver = true;
    return;
}

void room2() {
    cout << "==============================================" << endl;
    cout << "          ROOM 2 - PATIENT WARD              " << endl;
    cout << "==============================================" << endl;
    cout << "You enter a long dark corridor of abandoned beds." << endl;
    cout << "Tattered curtains sway even though there is no wind." << endl;
    cout << "Something moves under one of the sheets...  " << endl;
    cout << "A bloody note on the floor reads:            " << endl;
    cout << "'Count the beds that face the window.'       " << endl;
    cout << "You look around... 20 beds total.            " << endl;
    cout << "Some face the North wall. Some face the East window." << endl;
    cout << "==============================================" << endl;

    int answer;
    int attempts = 3;

    while (attempts > 0) {
        cout << "How many beds face the window? (" << attempts << " attempts left): ";
        answer = getValidInt();

        if (answer == 7) {
            cout << "==============================================" << endl;
            cout << "The ward suddenly becomes silent...          " << endl;
            cout << "You hear metal scraping against the floor.   " << endl;
            cout << "You found a SCALPEL!                         " << endl;
            cout << "==============================================" << endl;
            addItem("Scalpel");
            cout << "Press ENTER to continue..." << endl;
            cin.ignore();
            cin.get();
            return;
        }
        else {
            attempts--;
            totalAttempts++;
            if (attempts > 0) {
                cout << "Wrong answer." << endl;
                cout << "One of the beds slowly creaks on its own..." << endl;
            }
        }
    }

    cout << "==============================================" << endl;
    cout << "The ward lights begin to flicker violently.  " << endl;
    cout << "A shadow appears beside your bed.            " << endl;
    cout << "You never escaped the Patient Ward.          " << endl;
    cout << "=== GAME OVER ===                            " << endl;
    cout << "==============================================" << endl;
    gameOver = true;
    return;
}

void room3() {
    cout << "==============================================" << endl;
    cout << "          ROOM 3 - LABORATORY                " << endl;
    cout << "==============================================" << endl;
    cout << "Broken test tubes crunch under your feet.   " << endl;
    cout << "The walls are covered in strange symbols.    " << endl;
    cout << "A locked cabinet hums with a faint red glow." << endl;
    cout << "On the wall, scrawled in dried blood:        " << endl;
    cout << "'I flow through every vein of this place.'   " << endl;
    cout << "==============================================" << endl;

    int attempts = 3;
    string password;

    while (attempts > 0) {
        cout << "What am I? (" << attempts << " attempts left): ";
        password = getValidString();

        if (password == "BLOOD" || password == "blood") {
            cout << "==============================================" << endl;
            cout << "The cabinet clicks open...                   " << endl;
            cout << "A dim light flickers inside.                 " << endl;
            cout << "You found a FLASHLIGHT!                      " << endl;
            cout << "==============================================" << endl;
            addItem("Flashlight");
            cout << "Press ENTER to continue..." << endl;
            cin.ignore();
            cin.get();
            return;
        }
        else {
            attempts--;
            totalAttempts++;
            if (attempts > 0) {
                cout << "Wrong answer." << endl;
                cout << "The chemicals around you start vibrating..." << endl;
                gameOver = true;
            }
            return;
        }
    }

    cout << "==============================================" << endl;
    cout << "The red glow from the cabinet grows brighter." << endl;
    cout << "The symbols on the wall start moving...      " << endl;
    cout << "You never escaped the Laboratory.            " << endl;
    cout << "=== GAME OVER ===                            " << endl;
    cout << "==============================================" << endl;
    gameOver = true;
    return;
}

void room4() {
    cout << "==============================================" << endl;
    cout << "       ROOM 4 - OPERATION THEATRE            " << endl;
    cout << "==============================================" << endl;
    cout << "The doors swing open on their own.           " << endl;
    cout << "A rusted operating table sits in the center. " << endl;
    cout << "The ghost of a doctor stands before you.     " << endl;
    cout << "His hollow eyes stare into yours.            " << endl;
    cout << "He whispers: 'Answer my riddle or lose your soul...'" << endl;
    cout << "==============================================" << endl;

    int attempts = 3;
    string password;

    while (attempts > 0) {
        cout << "'I have hands but cannot clap. What am I?'" << endl;
        cout << "Your answer (" << attempts << " attempts left): ";
        password = getValidString();

        if (password == "CLOCK" || password == "clock") {
            cout << "==============================================" << endl;
            cout << "The ghost doctor steps aside slowly...       " << endl;
            cout << "A piece of paper falls from his coat.        " << endl;
            cout << "You found the EXIT CODE!                     " << endl;
            cout << "==============================================" << endl;
            addItem("Exit Code");
            cout << "Press ENTER to continue..." << endl;
            cin.ignore();
            cin.get();
            return;
        }
        else {
            attempts--;
            totalAttempts++;
            if (attempts > 0) {
                cout << "Wrong answer." << endl;
                cout << "The doctor screams. The room shakes.     " << endl;
                cout << "The operating table slides towards you..." << endl;
            }
        }
    }

    cout << "==============================================" << endl;
    cout << "The ghost doctor laughs in the darkness.     " << endl;
    cout << "You never left the Operation Theatre.        " << endl;
    cout << "=== GAME OVER ===                            " << endl;
    cout << "==============================================" << endl;
    gameOver = true;
    return;
}

void room5() {
    cout << "==============================================" << endl;
    cout << "          ROOM 5 - ROOFTOP EXIT              " << endl;
    cout << "==============================================" << endl;
    cout << "You reach the final door. Rain pours outside." << endl;
    cout << "Freedom is inches away.                      " << endl;
    cout << "The door has a 3-part lock.                  " << endl;
    cout << "Checking your inventory...                   " << endl;
    cout << "==============================================" << endl;

    for (int i = 0; i < itemCount; i++) {
        cout << "===> " << inventory[i] << endl;
    }

    cout << "==============================================" << endl;

    bool hasKey = false;
    bool hasScalpel = false;
    bool hasFlashlight = false;
    bool hasExitCode = false;

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i] == "Rusty Key")  
         hasKey = true;
        if (inventory[i] == "Scalpel")    
         hasScalpel = true;
        if (inventory[i] == "Flashlight")  
        hasFlashlight = true;
        if (inventory[i] == "Exit Code")   
        hasExitCode = true;
    }

    if (hasKey == true && hasScalpel == true && hasFlashlight == true && hasExitCode == true) {
        cout << "The lock clicks open one by one...           " << endl;
        cout << "You burst through the door into the night.   " << endl;
        cout << "You escaped.... You survived.                " << endl;
        cout << "But as you run... you hear footsteps behind you." << endl;
        cout << "==============================================" << endl;
        cout << playerName << " escaped... barely." << endl;
        cout << "=== YOU ESCAPED ===" << endl;
        cout << "Total wrong attempts: " << totalAttempts << endl;
        cout << "==============================================" << endl;
        cout << "Press ENTER to exit..." << endl;
        cin.ignore();
        cin.get();
        return;
    }
    else {
        cout << "Something is missing. The door won't budge.  " << endl;
        cout << "The lights go out completely.                 " << endl;
        cout << "==============================================" << endl;
        cout << playerName << " was never seen again." << endl;
        cout << "=== GAME OVER ===" << endl;
        cout << "==============================================" << endl;
    }
}

void hospitalEscape() {
    displayIntro();
    displayRules();
    room1();
    if(gameOver) 
    {
        return;
    }
    room2();
    if(gameOver) 
    {
        return;
    }
    room3();
    if(gameOver) 
    {
        return;
    }
    room4();
    if(gameOver) 
    {
        return;
    }
    room5();
}
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}};

void displayBoard()
{
    cout << "\n";
    cout << " " << board[0][0] << "  | " << board[0][1] << "  | " << board[0][2] << endl;
    cout << "____|____|____" << endl;
    cout << " " << board[1][0] << "  | " << board[1][1] << "  | " << board[1][2] << endl;
    cout << "____|____|____" << endl;
    cout << " " << board[2][0] << "  | " << board[2][1] << "  | " << board[2][2] << endl;
    cout << "\n";
}

bool checkWin()
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return true;
    }

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}

bool makeMove(int choice, char player)
{
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    // check valid position
    if (choice < 1 || choice > 9)
    {
        return false;
    }
    // check occupied position
    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        return false;
    }
    // placing symbol
    board[row][col] = player;
    return true;
}

void ticTacToeGame()
{
    string player1, player2;
    char currentPlayer = 'X';
    int choice;

    cout << "===== TIC TAC TOE =====\n\n";

    cout << "Enter Player 1 Name (X): ";
    cin.ignore();
    getline(cin, player1);

    cout << "Enter Player 2 Name (O): ";
    getline(cin, player2);

    while (true)
    {
        displayBoard();

        if (currentPlayer == 'X')
        {
            cout << player1 << "'s Turn (X): ";
        }
        else
        {
            cout << player2 << "'s Turn (O): ";
        }

        if (!(cin >> choice))
        {
            cout << "Invalid input! Numbers only.\n";

            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (!makeMove(choice, currentPlayer))
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if (checkWin())
        {
            displayBoard();

            if (currentPlayer == 'X')
                cout << "\nCongratulations " << player1 << "! You Win!\n";
            else
                cout << "\nCongratulations " << player2 << "! You Win!\n";

            break;
        }

        if (checkDraw())
        {
            displayBoard();
            cout << "\nGame Draw!\n";
            break;
        }
        // switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}
// To draw Hangman
    void Hangman(int chances) 
{
    cout << " \n _________\n";
    cout << " |/      |\n";

    // Head (5 chances)
    if (chances <= 5)
    {
        cout << " |      (_)\n";
    }
    else
    {
        cout << " |       \n";
    }

    // Body & Arms
    if (chances <= 4 && chances > 3)
    {
        cout << " |       |\n";          // Body
    }
    else if (chances <= 3 && chances > 2)
    {
        cout << " |       |\\\n";        // Body + Right arm
    }
    else if (chances <= 2)
    {
        cout << " |      /|\\\n";        // Body + Both arms
    }
    else
    {
        cout << " |       \n";
    }

    // Legs
    if (chances == 1)
    {
        cout << " |        \\\n";        // Right leg
    }
    else if (chances == 0)
    {
        cout << " |      / \\\n";       // Both legs
    }
    else
    {
        cout << " |       \n";
    }

    cout << " |\n";
    cout << "=========\n";
}

void hangmanGame() {
    string words[] = {
        "laptop", "mobile", "computer", "aeroplane", "quilt", "elephant", "glasses",
        "microwave", "lightning", "river", "mountain", "light", "shadow", "breeze",
        "stone", "flame", "cloud", "forest", "ocean", "sand", "leaf", "rain", "star",
        "moon", "sun", "field", "road", "bridge", "window", "mirror", "clock", "dream",
        "sound", "silence", "color", "shape", "path", "door", "paper", "ink", "glass",
        "metal", "wood", "seed", "root", "branch", "flower", "fruit", "bread", "water",
        "fire", "earth", "wind", "space", "time", "memory", "thought", "idea", "story",
        "poem", "rhythm", "voice", "echo", "smile", "laugh", "tear", "heart", "mind",
        "soul", "energy", "balance", "force", "power", "signal", "code", "logic",
        "number", "pattern", "order", "chaos", "system", "network", "data", "pixel",
        "frame", "image", "vision", "clarity", "depth", "surface", "texture", "tone",
        "hue", "contrast", "angle", "curve", "edge", "center", "horizon"
    };

    srand(time(0));
    string word = words[rand() % 100];
    string guessed(word.length(), '_');

    int chances = 6;
    char letter;
    bool found;
    bool alreadyGuessed[26] = {false};

    cout << "WELCOME TO HANGMAN GAME!\n";

    while (chances > 0 && guessed != word) {
        system("cls");
        cout << "WELCOME TO HANGMAN GAME!\n";

        cout << "\nWord: ";
        for (char c : guessed)
            cout << c << " ";

        cout << "\nChances left: " << chances;
        Hangman(chances);

        // INPUT VALIDATION 
        bool valid = false;

        while (valid == false) {
            cout << "\nEnter a Letter: ";
            cin >> letter;
            letter = tolower(letter);      // convert to lowercase

            if (!isalpha(letter)) {
                cout << "Invalid! Enter a letter only (a-z).\n";
            }
            else if (alreadyGuessed[letter - 'a']) {
                cout << "Already guessed '" << letter << "'! Try another.\n";
            }
            else {
                valid = true;    // input is correct, exit loop
            }
        }

        alreadyGuessed[letter - 'a'] = true;

        found = false;

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == letter) {
                guessed[i] = letter;
                found = true;
            }
        }

        if (!found) {
            chances--;
            cout << "Wrong guess!\n";
        } else {
            cout << "Correct!\n";
        }

        system("pause");
    }

    system("cls");
    if (guessed == word) {
        cout << "\n\nYOU WON! \nThe word was: " << word;
    } else {
        cout << "\n\nYOU LOST! \nThe word was: " << word;
        Hangman(0);
    }
}
void setupBoard(char gameBoard[8][8])
{
    // Black pieces
    gameBoard[0][0] = {'r'}; // rook
    gameBoard[0][1] = {'n'}; // knight
    gameBoard[0][2] = {'b'}; // bishop
    gameBoard[0][3] = {'q'}; // queen
    gameBoard[0][4] = {'k'}; // king
    gameBoard[0][5] = {'b'}; // bishop
    gameBoard[0][6] = {'n'}; // knight
    gameBoard[0][7] = {'r'}; // rook

    // Black pawns
    for(int col=0; col<8; col++)
    {
        gameBoard[1][col] = {'p'}; //black pawn
    }

    //for Empty spaces
    for(int i=2; i<6; i++)
    {
        for(int j=0; j<8; j++)
        {
            gameBoard[i][j] = {'.'};
        }
    }
    for(int col=0; col<8; col++)
    {
        gameBoard[6][col] = {'P'}; // white PAWN
    }

    // White piece
    gameBoard[7][0] = {'R'}; // ROOK
    gameBoard[7][1] = {'N'}; // KNIGHT
    gameBoard[7][2] = {'B'}; // BISHOP
    gameBoard[7][3] = {'Q'}; // QUEEN
    gameBoard[7][4] = {'K'}; // KING
    gameBoard[7][5] = {'B'}; // BISHOP
    gameBoard[7][6] = {'N'}; // KNIGHT
    gameBoard[7][7] = {'R'}; // ROOK
}

void showBoard(char gameBoard[8][8])
{
    cout << endl;

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cout << gameBoard[i][j] << "   ";
        }

        cout << endl;
    }

    cout << endl;
}
bool isValidMove(char board[8][8],int startRow, int startCol,int endRow, int endCol)
{
    char piece = board[startRow][startCol];

    int rowDiff = endRow - startRow;
    int colDiff = endCol - startCol;

    // ROOK(up,down,left,right)
    if(piece == 'R' || piece == 'r')
    {
        if(startRow == endRow || startCol == endCol)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // BISHOP(diagonal)
    if(piece == 'B' || piece == 'b')
    {
        if(abs(rowDiff) == abs(colDiff))

            return true;
        else
            return false;
    }

    // KNIGHT(L shape)
    if(piece == 'N' || piece == 'n')
    {
        if((abs(rowDiff)==2 && abs(colDiff)==1) || (abs(rowDiff)==1 && abs(colDiff)==2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // QUEEN(diagnoal & up,down,left, right)
    if(piece == 'Q' || piece == 'q')
    {
        if(startRow == endRow ||startCol == endCol || abs(rowDiff)==abs(colDiff))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // KING(one square)
    if(piece == 'K' || piece == 'k')
    {
        if(abs(rowDiff)<=1 && abs(colDiff)<=1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // WHITE PAWN(upward)
    if(piece == 'P')
    {
        if(startCol == endCol && endRow == startRow-1 && board[endRow][endCol]=='.')
        {
          return true;
        }
        else
        {
            return false;
        }
    }

    // BLACK PAWN(downward)
    if(piece == 'p')
    {
        if(startCol == endCol && endRow == startRow+1 && board[endRow][endCol]=='.')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return true;
}
bool movePiece(char gameBoard[8][8], int startRow, int startCol, int endRow , int endCol , bool whiteTurn , bool &gameover)
{
    // Check board limits outer range 
    if(startRow < 0 || startRow > 7 || startCol < 0 || startCol > 7 || endRow < 0 || endRow > 7 ||endCol < 0 || endCol > 7)
    {  
        cout << "position out of board!!" << endl;
        return false;
    }

    // Check empty position
    if(gameBoard[startRow][startCol] == '.')
    {
        cout <<"No piece at start position: " <<endl;
        return false;
    }
    char piece = gameBoard[startRow][startCol];

    // White turn check
    if(whiteTurn == true)
    {
        if(piece >= 'a' && piece <= 'z')
        {
            cout << "Black piece selected!" << endl;
            return false;
        }
    }

    // Black turn check
    if(whiteTurn == false)
    {
        if(piece >= 'A' && piece <= 'Z')
        {
            cout << "White piece selected!" << endl;
            return false;
        }
    }

    char destination = gameBoard[endRow][endCol];

    // Prevent same team kill
    if(piece >= 'A' && piece <= 'Z' &&
       destination >= 'A' && destination <= 'Z')
    {
        cout << "Cannot attack your own piece!" << endl;
        return false;
    }

    if(piece >= 'a' && piece <= 'z' &&
       destination >= 'a' && destination <= 'z')
    {
        cout << "Cannot attack your own piece!" << endl;
        return false;
    }

    if(isValidMove(gameBoard, startRow, startCol, endRow, endCol)==false)
    {
    cout << "Illegal move for this piece!"
         << endl;
    return false;
    }
    char targetPiece = board[endRow][endCol];

    // White king captured
    if(targetPiece == 'K')
    {
      cout << "\nCHECKMATE!" << endl;
      cout << "BLACK WINS!" << endl;

      gameover == true;
    }

    // Black king captured
    if(targetPiece == 'k')
    {
      cout << "\nCHECKMATE!" << endl;
      cout << "WHITE WINS!" << endl;

      gameover == true;
    }
    // Move piece
    gameBoard[endRow][endCol] = piece;

    // Empty old place
    gameBoard[startRow][startCol] = '.';


    return true;
}

void chessGame()
{
    char gameBoard[8][8];

    int startRow , startCol , endRow , endCol;
    bool moveResult , gameover;
    bool whiteTurn = true;
     setupBoard(gameBoard); // create board

    while(true) 
    {
        showBoard(gameBoard);
         if(whiteTurn == true)
        {
            cout << "WHITE TURN" << endl;
        }
        else
        {
            cout << "BLACK TURN" << endl;
        }

        cout << "Enter start row: ";
          startRow = getNumber();
        cout << "Enter start column: ";
          startCol = getNumber();
        cout << "Enter end row: ";
          endRow = getNumber();
        cout << "Enter end column: ";
          endCol = getNumber();
        // Move piece
        moveResult = movePiece(gameBoard, startRow, startCol, endRow, endCol , whiteTurn , gameover);

        if(moveResult == true)
        {
            cout << "Move Successful" << endl;
            whiteTurn = !whiteTurn;
        }
        else
        {
            cout << "Invalid Move" << endl;
        }
    }
      cout << "\n=================" << endl;
      cout << "   GAME OVER" << endl;
      cout << "=================" << endl;
}
int main()
{
    int choice;
    do
    {
    cout << "1. Hospital escape\n";
    cout << "2. Tic Tac Toe\n";
    cout << "3. Hangman\n";
    cout << "4. Chess\n";
    cout << "5. Exit\n";
    cout << "enter your choice: "<<endl;
    choice = getNumber();
    if(choice == 1)
    {
        hospitalEscape();
    }
    else if(choice == 2)
    {
        ticTacToeGame();
    }
    else if(choice == 3)
    {
        hangmanGame();
    }
    else if(choice == 4)
    {
        chessGame();
    }
    } while(choice >=1 && choice < 5);
    if (choice == 5)
    { 
        cout << " okieeeeeeeeeeeee!! " << endl;
    }

    
    return 0;
}
