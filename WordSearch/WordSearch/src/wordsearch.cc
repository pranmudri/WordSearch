#include "wordsearch.hpp"
std::vector<std::vector<char>> GetBoard() {
    std::vector<std::vector<char>> board = {{'T','S','O','R','R','Y','N','A','T','D'},
                                             {'B','A','T','T','E','R','S','H','I', 'P'},
                                             {'Y','H', 'R','S','K','V','R','B','Y','E'},
                                             {'L','A','C','U','S','M','U','N','O','L'},
                                             {'O','N','L','D','I','T','J','C','Q','B'},
                                             {'P','A','U','O','R','I','H','Q','T','U'},
                                             {'O','B','E','K','F','E','H','Q','S','O'},
                                             {'N','I','L','U','S','W','A','F','U','R'},
                                             {'O','S','D','S','N','E','L','Q','R','T'},
                                              {'M','G','E','L','G','G','O','B','O','J'}};
    return board;

}
std::vector<std::string> GetWords() {
    std::vector<std::string>words = {"BATTERSHIP","CLUE","RISK","TROUBLE","BOGGLE","HANABI","SORRY","TSURO","CHESS","MONOPOLY","SUDOKU","UNO"};
    return words;

}
void PrintBoardOnly() {
    std::vector<std::vector<char>> board = GetBoard();
    for(int x = 1; x <= 10; x++) {
        std::cout<<x<<" ";
    }
    std::cout<<"\n";
    int r = 1;
    for(std::vector<char> row: board) {
        std::cout<<r<<" ";
        for(char x: row) {
            std::cout<<x<<" ";
        }
        std::cout<<"\n";
        r++;
    }

}
void PrintBoard() {
    PrintBoardOnly();
    std::cout<<"\n";
    std::vector<std::string>words = GetWords();
    int count = 1;
    for(std::string word: words) {
        std::cout<<word<<" ";
        if (count % 4 == 0) {
            std::cout<<"\n";
        }
        count++;
    }

}
void CheckHoz(int row_first, int col_first, int col_last, int& tracker, std::map<std::string, bool>& words_tracker) {
    //check if we need to go forwards
    std::string created_word;
    std::vector<std::vector<char>> board = GetBoard();
    std::vector<std::string> words = GetWords();
    if (col_first < col_last) { //we know we need to go in forwards direction
        for (int x = col_first - 1; x < col_last; x++) {
            created_word += board.at(row_first - 1).at(x);
        }
    }
    else if (col_first > col_last) { //Go in backwards direction
        for (int x = col_first - 1; x >= col_last - 1; x--) {
            created_word += board.at(row_first - 1).at(x);
        }

        
    }
    else {
        created_word = board.at(row_first - 1).at(col_first - 1);
    }
    //redundant code below put in function 
    CheckWord(created_word, tracker, words_tracker);
}
void CheckVert(int col_first, int row_first, int row_last, int& tracker, std::map<std::string, bool>& words_tracker) {
    std::string created_word;
    std::vector<std::vector<char>> board = GetBoard();
    std::vector<std::string> words = GetWords();

    if (row_first < row_last) { //we know we need to go in forwards direction
        for (int x = row_first - 1; x < row_last; x++) {
            created_word += board.at(x).at(col_first - 1);
        }
    }
    else if (row_first > row_last) { //We need to make sure that two col values not equal 
        for (int x = row_first - 1; x >= row_last - 1; x--) {
            created_word += board.at(x).at(col_first - 1);
        }
    }
    CheckWord(created_word, tracker, words_tracker);

}
void CheckTopDiag(int row_first, int row_last, int col_first, int col_last, int& tracker, std::map<std::string, bool>& words_tracker) {
    //Two cases for top diagonal 
    //#1 Up and Right
    std::string created_word;
    std::vector<std::vector<char>> board = GetBoard();
    std::vector<std::string> words = GetWords();
    if (col_last > col_first) {
        for (int x = col_first - 1; x < col_last; x++) {
            if (row_first > 0) { //prevents out of bounds error
                created_word += board.at(row_first - 1).at(x);
                row_first--;
            }
        }
    }
    else { //up and left
        for (int x = col_first - 1; x >= col_last - 1; x--) {
            created_word += board.at(row_first - 1).at(x);
            if (row_first > 0) { //prevents out of bounds error
                created_word += board.at(row_first - 1).at(x);
                row_first--;
            }
        }

    }
    CheckWord(created_word, tracker, words_tracker);
}
void CheckBottomDiag(int row_first, int row_last, int col_first, int col_last, int& tracker, std::map<std::string, bool>& words_tracker) {
    std::string created_word;
    std::vector<std::vector<char>> board = GetBoard();
    std::vector<std::string> words = GetWords();
    if (col_first > col_last) { //right to left
        for (int x = row_first - 1; x < row_last; x++) {
            created_word += board.at(x).at(col_first - 1);
            col_first--;
        }
    }
    else { //left to right
        for (int x = row_first - 1; x < row_last; x++) {
            created_word += board.at(x).at(col_first - 1);
            col_first++;
        }
    }
    CheckWord(created_word, tracker, words_tracker);
}

void CheckWord(std::string created_word, int& tracker, std::map<std::string, bool>& words_tracker) {
    bool find = false;
    for (std::string w: GetWords()) {
        if (w == created_word) {
            find = true;
            if (!words_tracker[w]) { //Found word once
                words_tracker[w] = true;
                std::cout<<"\nYou succesfully found the word "<<created_word<<std::endl;
                tracker++;
                if (tracker < 11) {
                    std::cout<<"You have "<<12-tracker<<" words left to find"<<std::endl;
                }
                else if (tracker == 11) {
                    std::cout<<"You have only "<<12-tracker<<" word left to find"<<std::endl;
                }
                else {
                    std::cout<<"You finally found all the words! Congratulations"<<std::endl;
                }
            }
            else { //Trying to find same word twice.
                std::cout<<"\nYou already found "<<created_word<<". Try finding another word."<<std::endl;
                std::cout<<"You still have "<<12-tracker<<" words left to find."<<std::endl;
            }
        }
    }
    if (!find) { //User didn't find any word
        std::cout<<"\nUnfortunately, you didn't find a word from the list of words. Keep on trying.\nYou still have "<<12-tracker<<" words left to find."<<std::endl;

    }
}
void Undo(std::string direction, std::string pos, int& num) {
    std::string input;
    std::cout<<"Enter c to continue or u to undo: ";
    std::cin>>input;
    while(input != "c" && input != "u") {
        std::cout<<"Error! Enter c to continue or u to undo: ";
        std::cin>>input;
    }
    while (input == "u") {
        if (pos == "first") {
            if (direction == "row") {
                std::cout<<"Renter in the row of where you think the first letter of that word lies: ";
            }
            else {
                std::cout<<"Renter in the column of where you think the first letter of that word lies: ";
            }
        }
        else {
             if (direction == "row") {
                std::cout<<"Renter in the row of where you think the last letter of that word lies: ";
            }
            else {
                std::cout<<"Renter in the column of where you think the last letter of that word lies: ";
            }
        }
        std::cin>> num;
        while((num < 1 || num > 10) && (num != 99)) {
            std::cout<<"Error! Enter in a valid row from 1 through 10 or enter 99 to give up: ";
            std::cin>>num;
        }
        std::cout<<"Enter c to continue or u to undo: ";
        std::cin>>input;
        while(input != "c" && input != "u") {
            std::cout<<"Error! Enter c to continue or u to undo: ";
            std::cin>>input;
        }

    }
}
    

