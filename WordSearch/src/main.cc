
#include "WordSearchSolver.hpp"
#include "random.hpp"

int main() {
    std::string input;
    WordSearchSolver w1(GetBoard(), GetWords()); //Not these functions are specifcally for the original word search 
    std::cout<<"Hello There. \nDo you want to solve a word search puzzle. I found it of the internet? (y/n) ";
    std::cin>>input;
    while(input != "y" && input != "n") {
        std::cout<<"Invalid Answer! Enter y for yes or n for no ";
        std::cin>>input;
    }
    while (input == "y") {
        int tracker = 0;
        std::map<std::string,bool>words_tracker;
        for (std::string w: GetWords()) {
            words_tracker[w] = false;
        }
        std::cout<<"\nHere is the board and the words you need to find "<<std::endl;
        while (tracker < 12) {
            std::cout<<"\n";
            std::cout<<"  ";
            PrintBoard();
            int row_first;
            int col_first;
            std::cout<<"\nThink of a word from the provided list of words. \nNow enter in the row of where you think the first letter of that word lies. \nIf you feel that this word search is too difficult for you and want to see the solutions hit 99 at any time: ";
            std::cin>>row_first;
            while((row_first < 1 || row_first > 10) && (row_first != 99)) {
                std::cout<<"Error! Enter in a valid row from 1 through 10 or enter 99 to give up: ";
                std::cin>>row_first;
            }
            Undo("row","first",row_first, 10);
            if (row_first != 99) {
                std::cout<<"\nEnter in the column of where you think the first letter of that word lies: ";
                std::cin>>col_first;
                while((col_first < 1 || col_first > 10) && (col_first != 99)) {
                    std::cout<<"Error! Enter in a valid column from 1 through 10 or enter 99 to give up:  ";
                    std::cin>>col_first;
                }
                Undo("column","first",col_first, 10);
                if (col_first != 99) {
                    int row_last;
                    int col_last;
                    std::cout<<"\nEnter in the row of where you think the last letter of that word lies: ";
                    std::cin>>row_last;
                    while((row_last < 1 || row_last > 10) && (row_last != 99)) {
                        std::cout<<"Error! Enter in a valid row from 1 through 10 or enter 99 to give up:  ";
                        std::cin>>row_last;
                    }
                    Undo("row","last",row_last, 10);
                    if (row_last != 99) {
                        std::cout<<"\nEnter in the column of where you think the last letter of that word lies: ";
                        std::cin>>col_last;
                        while((col_last < 1 || col_last > 10) && (col_last != 99))  {
                            std::cout<<"Error! Enter in a valid column from 1 through 10 or enter 99 to give up:  ";
                            std::cin>>col_last;
                        }
                        Undo("row","last",col_last, 10);
                        if (col_last != 99) {
                            if (row_first == row_last) {
                                //The paramters for checking each direction involve a board and a list of words
                                // GetBoard() and GetWords() are specifically used for the main word search (the one I got on the internet)
                                //When I call Check Hoz within the random class, I won't call GetBoard and GetWords.
                                CheckHoz(row_first, col_first, col_last, tracker, words_tracker, GetBoard(), GetWords()); 
                            }
                            else if (col_first == col_last) { 
                                CheckVert(col_first, row_first, row_last, tracker, words_tracker, GetBoard(), GetWords());
                            }
                            else if (row_first > row_last) {
                                CheckTopDiag(row_first,row_last,col_first,col_last, tracker, words_tracker, GetBoard(), GetWords());
                            } 
                            else {
                                CheckBottomDiag(row_first,row_last,col_first,col_last, tracker, words_tracker, GetBoard(), GetWords());
                            }
                        } 
                        else {
                            w1.PrintInfo(tracker);
                            tracker = 12;
                        }
                    }
                    else {
                        w1.PrintInfo(tracker);
                        tracker = 12;
                    }
                }
                else {
                    w1.PrintInfo(tracker);
                    tracker = 12;
                } 
            }
            else {
                w1.PrintInfo(tracker);
                tracker = 12;
            } 
        }
        std::cout<<"\nWould you like to solve this wordsearch puzzle again? (y/n) "; //Would people want to resolve same word search?
        std::cin>>input;
        while(input != "y" && input != "n") {
            std::cout<<"Invalid Answer! Enter y for yes or n for no ";
            std::cin>>input;
        }
    }
    std::cout<<"Do you want to solve a random word search puzzle? You'll be provided a random set of words and they will be placed randomly on the board? (y/n) ";
    std::cin>>input;
    while(input != "y" && input != "n") {
        std::cout<<"Invalid Answer! Enter y for yes or n for no ";
        std::cin>>input;
    }
    while (input == "y") {
        std::string difficulty;
        std::cout<<"What level of difficulty would you like your word search to be. Enter e for easy or h for hard: ";
        std::cin>>difficulty;
        while(difficulty != "e" &&  difficulty != "h") {
            std::cout<<"Error! Enter e for easy or h for hard: ";
            std::cin>>difficulty;
        }
        PrintInfo(difficulty); //Method exists within WordSearch Class
        Undo(difficulty); //Method exists within WordSearch Class
        Random r1(difficulty);
        r1.Start();
        std::cout<<"Would you like to solve another random word search puzzle? (y/n): ";
        std::cin>>input;
        while(input != "y" && input != "n") {
            std::cout<<"Invalid Answer! Enter y for yes or n for no ";
            std::cin>>input;
        }
    }
    std::cout<<"Goodbye!"<<std::endl;
    // std::cout<<"9 10 11 12"<<std::endl;
    // std::cout<<"a b  c  d"<<std::endl;
}

