
#include "random.hpp"
Random::Random(std::string difficulty) {

    difficulty_ = difficulty;
    if (difficulty_ == "e") {
        num_words = 6;
        rows = 10;
        cols = 10;
        hoz_words = 3;
        vert_words = 3;
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
void Random::Game() { //Main Game Loop 
    std::vector<std::string>words;
    words.push_back("apples");
    words.push_back("orange");
    words.push_back("pencil");
    words.push_back("fruits");
    words.push_back("papers");
    words.push_back("grapes");
    std::cout<<"\n";
    std::vector<std::vector<char>> board = GenerateRandomBoard(words); 
    Print(board);
    std::cout<<"\n";
    int count = 1;
    for(std::string word: words) {
        std::cout<<word<<" ";
        if (count % 3 == 0) {
            std::cout<<"\n";
        }
        count++;
    }
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
    std::vector<std::pair<size_t, size_t>> occupied_spots;
    AddHozWords(board,words,occupied_spots);
    AddVertWords(board,words, occupied_spots);
    return board;
}
void Random::AddHozWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words, std::vector<std::pair<size_t, size_t>>& occupied_spots) {
    //Make sure to delete the word from the words vector after using it
    int x = 0;
    int max = num_words;
    std::vector<size_t>row_positions;
    unsigned seed = time(0);
    srand(seed);
    while(x < hoz_words) { //Want to add 3 hoz words
        size_t key_row = (rand() % 10); //Generate a random row (max - min + 1) + min
        while (std::find(row_positions.begin(), row_positions.end(), key_row) != row_positions.end()) {
            key_row = (rand() % 10);
        }
        row_positions.push_back(key_row); //What we are doing here is basically keeping track of what rows words have been added so we don't repeat rows
        size_t key_col = (rand() % 10); //Generate a col for the row we selected 
        size_t random_word_index = (rand() % max); //note this isn't fix variable (when word removed indicies of the vector chage) We select a random word from the list to put in horizontally on the board
        std::string key_word = words.at(random_word_index);
        while (key_col + words.at(random_word_index).length() > cols) { //Makes sure the word can fit on the board
            key_col = (rand() % 10);
        }
        for (size_t r = 0; r < rows; r++) { //Starting here hoz words get added
            for (size_t c = 0; c < cols; c++) {
                if (r == key_row && c == key_col) {
                    size_t temp_col = key_col;
                    size_t index = 0; //We have index variable so that we can use it to copy each letter from a word
                    while(temp_col < key_col + key_word.length()) {
                        board.at(key_row).at(temp_col) = key_word.at(index);
                        std::pair<size_t,size_t> pos;
                        pos.first = key_row;
                        pos.second = temp_col;
                        occupied_spots.push_back(pos);
                        temp_col++;
                        index++;
                    }
                }
            }
        }
        words.erase(words.begin() + random_word_index); 
        x++;
        max--;
    }
}
 
 void Random::AddVertWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words, std::vector<std::pair<size_t, size_t>>& occupied_spots) {
    int x = 0;
    int max = num_words / 2;
    std::vector<size_t>col_positions;
    unsigned seed = time(0);
    srand(seed);
    while(x < vert_words) {
        size_t key_col = (rand() % 10); //generates random col
        size_t random_word_index = (rand() % max);
        std::string random_word = words.at(random_word_index);
        while (std::find(col_positions.begin(), col_positions.end(), key_col) != col_positions.end() || LongestConsecSeq(occupied_spots, key_col).size() < random_word.size())  { //sees if that col has already been generated or can't fit within boundary
            key_col = (rand() % 10);
        }
        col_positions.push_back(key_col);
        std::vector<size_t> longest_seq = LongestConsecSeq(occupied_spots, key_col);
        int start = longest_seq.at(0);
        int index = 0;
        for (int row = start; row < start + random_word.length(); row++) {
            board.at(row).at(key_col) = random_word.at(index);
            std::pair<size_t,size_t> pos;
            pos.first = row;
            pos.second = key_col;
            occupied_spots.push_back(pos);
            index++;
        }
        words.erase(words.begin() + random_word_index);
        x++;
        max--;
    }

 }

 std::vector<size_t> Random::LongestConsecSeq(std::vector<std::pair<size_t, size_t>>& occupied_spots, size_t key_col) {
    std::vector<size_t> occupied_rows;
    for (std::pair<size_t, size_t> pair : occupied_spots) {
        if (pair.second == key_col) {
            occupied_rows.push_back(pair.first);
        }
    }
    std::vector<size_t> unoccupied_rows;
    for (size_t x = 0; x < 10; x++) {
        if (std::find(occupied_rows.begin(), occupied_rows.end(), x) == occupied_rows.end()) { //Can that specific row number not be found in occupied rows vector? If so add that specific number
            unoccupied_rows.push_back(x);
        }
    }
    std::vector<size_t> consec;
    std::vector<std::vector<size_t>> all_patterns;
    consec.push_back(unoccupied_rows.at(0));
    for (size_t x = 1; x < unoccupied_rows.size(); x++) {
        if (unoccupied_rows.at(x) - unoccupied_rows.at(x - 1) == 1) {
            consec.push_back(unoccupied_rows.at(x));
        }
        else {
            all_patterns.push_back(consec);
            consec.clear();
            consec.push_back(unoccupied_rows.at(x));
        }
    }
    all_patterns.push_back(consec);
    std::vector<size_t>longest_seq = all_patterns.at(0);
    for (std::vector<size_t> vect: all_patterns) {
        if (vect.size() >= longest_seq.size()) {
            longest_seq = vect;
        }
    }
    return longest_seq;
 }


void Random::Print(std::vector<std::vector<char>> board) {
    std::cout<<"  ";
    for (int x = 1; x <= 10; x++) {
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
