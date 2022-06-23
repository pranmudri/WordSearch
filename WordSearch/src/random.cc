
#include "random.hpp"
Random::Random(std::string difficulty) {
    difficulty_ = difficulty;
    if (difficulty_ == "e") {
        num_words = 6;
        rows = 8;
        cols = 8;
        hoz_words = 2;
        vert_words = 2;
    }
    else if (difficulty_ == "m") {
        num_words = 12;
        rows = 14;
        cols = 14;
        hoz_words = 4;
        vert_words = 4;
    }
    else {
        num_words = 16;
        rows = 20;
        cols = 20;
        hoz_words = 4;
        vert_words = 4;
    }
}
void Random::Game() {
    std::vector<std::string>positions = {"st","nd","rd"};
    int num_th = num_words - 3;
    int x = 0;
    while(x < num_th) {
        positions.push_back("th");
        x++;
    }
    std::vector<std::string>words;
    for (size_t x = 0; x < positions.size(); x++) {
        std::string word;
        std::cout<<"Enter in the "<< x + 1<<positions.at(x)<<" word: ";
        std::cin>>word;
        
        while(word.length() > rows) {
            std::cout<<"You can't enter in a word that has beyond "<<rows<<" letters\n"<< word <<" has "<<word.length()<<" letters."<<std::endl;
            std::cout<<"Enter in a different word: ";
            std::cin>>word;
        }
        while (std::find(words.begin(), words.end(), word) != words.end()) {
            std::cout<<"You already entered that word in. Enter in a different word: ";
            std::cin>>word;
        }
        words.push_back(word);
    }
    std::cout<<"\n";
    std::vector<std::vector<char>> board = GenerateRandomBoard(words);
    //std::cout<<"After Modified"<<std::endl;
    //Print(board);
    std::cout<<"\n";
}
std::vector<std::vector<char>> Random::GenerateRandomBoard(std::vector<std::string>& words) { //Just creates 2D vector of random chars at each position
    std::cout<<"\n";
    unsigned seed = time(0);
    srand(seed);
    std::vector<std::vector<char>>board;
    for (size_t r =0; r < rows; r++) {
        std::vector<char>one_d_board;
        for(size_t x = 0; x < cols; x++) {
            one_d_board.push_back('a' + rand()%26);
        }
        board.push_back(one_d_board);
    }
    std::cout<<"Prior to adding any hoz words";
    std::cout<<"\n";
    Print(board);
    AddHozWords(board,words);
    AddVertWords(board,words);
    return board;
}
void Random::AddHozWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    //Make sure to delete the word from the words vector after using it
    int x = 0;
    int max = num_words;
    std::vector<size_t>row_positions;
    unsigned seed = time(0);
    srand(seed);
    while(x < hoz_words) {
        size_t key_row = (rand() % 8);
        std::cout<<"\nrandom row: "<<key_row<<std::endl;
        while (std::find(row_positions.begin(), row_positions.end(), key_row) != row_positions.end()) {
            std::cout<<"Need to generate a new random row"<<std::endl;
            key_row = (rand() % 8);
            std::cout<<"random row: "<<key_row<<std::endl;
        }
        row_positions.push_back(key_row);
        size_t key_col = (rand() % 8);
        size_t random_word_index = (rand() % max); //note this isn't fix variable (when word removed indicies of the vector chage)
        std::cout<<"\nrandom row: "<<key_row<<std::endl;
        std::cout<<"random start col: "<<key_col<<std::endl;
        while (key_col + words.at(random_word_index).length() > cols) { //Makes sure the word can fit on the board
            std::cout<<"Need to generate a new random start col."<<std::endl;
            key_col = (rand() % 8);
            std::cout<<"random start col: "<<key_col<<std::endl;
        }
        std::string key_word = words.at(random_word_index);
        std::cout<<"random word to chose from: "<<key_word<<std::endl;
        std::cout<<"\n";
        for (size_t r = 0; r < rows; r++) { //Starting here hoz words get added
            for (size_t c = 0; c < cols; c++) {
                if (r == key_row && c == key_col) {
                    size_t temp_col = key_col;
                    size_t index = 0;
                    while(temp_col < key_col + key_word.length()) {
                        board.at(key_row).at(temp_col) = key_word.at(index);
                        temp_col++;
                        index++;
                    }
                }
            }
        }
        std::cout<<"\n";
        words.erase(words.begin() + random_word_index);
        std::cout<<"After adding "<<(x+1)<<" hoz word";
        std::cout<<"\n";
        Print(board);
        std::cout<<"\nwords to choose from\n";
        for (std::string w: words) {
            std::cout<<w<<std::endl;
        }
        x++;
        max--;
    }
}
 
 void Random::AddVertWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    int x = 0;
    int max = num_words;
    std::vector<size_t>col_positions;
    unsigned seed = time(0);
    srand(seed);
    while(x < vert_words) {
        size_t key_col = (rand() % 8); //generates random col
        std::cout<<"\nrandom col: "<<key_col<<std::endl;
        while (std::find(col_positions.begin(), col_positions.end(), key_col) != col_positions.end()) { //sees if that col has already been generated
            std::cout<<"Need to generate a new random col"<<std::endl;
            key_col = (rand() % 8);
            std::cout<<"random col: "<<key_col<<std::endl;
        }
        col_positions.push_back(key_col);
        size_t key_row = (rand() % 8);
        size_t random_word_index = (rand() % max); //note this isn't fix variable (when word removed indicies of the vector chage)
        std::cout<<"random start row: "<<key_row<<std::endl;
        while (key_row + words.at(random_word_index).length() > rows) { //Makes sure the word can fit on the board
            std::cout<<"Need to generate a new random start row."<<std::endl;
            key_row = (rand() % 8);
            std::cout<<"random start row: "<<key_row<<std::endl;
        }
        std::string key_word = words.at(random_word_index);
        std::cout<<"random word to chose from: "<<key_word<<std::endl;
        std::cout<<"\n";
        for (size_t c = 0; c < cols; c++) { //Starting here vert words get added
            for (size_t r = 0; r < rows; r++) {
                if (c == key_col && r == key_row) {
                    size_t temp_row = key_row;
                    size_t index = 0;
                    while(temp_row < key_row + key_word.length()) {
                        board.at(temp_row).at(key_col) = key_word.at(index);
                        temp_row++;
                        index++;
                    }
                }
            }
        }
        std::cout<<"\n";
        words.erase(words.begin() + random_word_index);
        std::cout<<"After adding "<<(x+1)<<" vert word";
        std::cout<<"\n";
        Print(board);
        std::cout<<"\nwords to choose from\n";
        for (std::string w: words) {
            std::cout<<w<<std::endl;
        }
        x++;
        max--;
    }


 }
void Random::Print(std::vector<std::vector<char>> board) {
    std::cout<<"  ";
    for (int x = 1; x <= 8; x++) {
        std::cout<<x<<" ";
    }
    std::cout<<"\n";
    for (size_t r =0; r < rows; r++) {
        std::cout<<r+1<<" ";
        for(size_t x = 0; x < cols; x++) {
            std::cout<<board.at(r).at(x)<<" ";
        }
        std::cout<<"\n";
    }

}
