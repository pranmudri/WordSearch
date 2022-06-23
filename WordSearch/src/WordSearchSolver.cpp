#include "WordSearchSolver.hpp"
WordSearchSolver::WordSearchSolver(std::vector<std::vector<char>> board, std::vector<std::string> words) {
    board_ = board;
    words_ = words;
}
std::map<std::string,std::vector<int>> WordSearchSolver::HozWords() {
    std::map<std::string,std::vector<int>> words_info;
    for (std::string word: words_) { //loop through each word
        for (int row = 0; row < board_.size(); row++) { //loop through board
            for (int col = 0; col < board_.at(0).size(); col++) {
                int temp_col = col;
                std::string created_word; 
                while(temp_col < col + word.size()) { //Forms a word starting from column goes till end of size of word //need to make sure in bounds
                    created_word += board_.at(row).at(temp_col);
                    temp_col++;
                }
                if (created_word == word) { //we found word and we need to note the key positions from the board 
                    std::vector<int>positions;
                    positions.push_back(row + 1); //start row 
                    positions.push_back(col + 1); //start col
                    positions.push_back(row + 1); //end row
                    positions.push_back(col + word.size()); //end col
                    words_info[word] = positions;
                }
            }
        }
    }
    return words_info;
}
std::map<std::string,std::vector<int>> WordSearchSolver::VertWords() {
    

}
std::map<std::string,std::vector<int>> WordSearchSolver::TopDiagWords() {
    

}
std::map<std::string,std::vector<int>> WordSearchSolver::BottomDiagWords() {
    

}