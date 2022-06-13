#include "wordsearch.hpp"
int main() {
    std::string input;
    std::cout<<"Hello There. Do you want to solve a word search puzzle? (y/n) ";
    std::cin>>input;
    while(input != "y" && input != "n") {
        std::cout<<"Invalid Answer! Enter y for yes or n for no ";
        std::cin>>input;
    }
    while (input == "y") {
        // std::cout<<"\nHere is the board and the words you need to find "<<std::endl;
        // std::cout<<"\n";
        // std::cout<<"  ";
        // PrintBoard();
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
            std::cout<<"\nThink of a word from the provided list of words. Now enter in the row of where you think the first letter of that word lies: ";
            std::cin>>row_first;
            while(row_first < 1 || row_first > 10) {
                std::cout<<"Error! Enter in a valid row from 1 through 10: ";
                std::cin>>row_first;
            }
            std::cout<<"Enter in the column of where you think the first letter of that word lies: ";
            std::cin>>col_first;
            while(col_first < 1 || col_first > 10) {
                std::cout<<"Error! Enter in a valid column from 1 through 10: ";
                std::cin>>col_first;
            }
            int row_last;
            int col_last;
            std::cout<<"Enter in the row of where you think the last letter of that word lies: ";
            std::cin>>row_last;
            while(row_last < 1 || row_last > 10) {
                std::cout<<"Error! Enter in a valid row from 1 through 10: ";
                std::cin>>row_last;
            }
            std::cout<<"Enter in the column of where you think the last letter of that word lies: ";
            std::cin>>col_last;
            while(col_last < 1 || col_last > 10) {
                std::cout<<"Error! Enter in a valid column from 1 through 10: ";
                std::cin>>col_last;
            }
            if (row_first == row_last) { 
                CheckHoz(row_first, col_first, col_last, tracker, words_tracker);
            }
            else if (col_first == col_last) { 
                CheckVert(col_first, row_first, row_last, tracker, words_tracker);
            }
            else if (row_first > row_last) {
                CheckTopDiag(row_first,row_last,col_first,col_last, tracker, words_tracker);
            } 
            else {
                CheckBottomDiag(row_first,row_last,col_first,col_last, tracker, words_tracker);
            }
            //Reprint board and the words to find
            
            // std::cout<<"\n";
            // std::cout<<"  ";
            // PrintBoard();

            
            

        }
        
        std::cout<<"Would you like to play again? (y/n) ";
        std::cin>>input;
        while(input != "y" && input != "n") {
            std::cout<<"Invalid Answer! Enter y for yes or n for no ";
            std::cin>>input;
        }
        

    }
    
    std::cout<<"Goodbye!"<<std::endl;
    
    
    


}

