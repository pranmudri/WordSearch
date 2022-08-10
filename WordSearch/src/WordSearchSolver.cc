#include "WordSearchSolver.hpp"
WordSearchSolver::WordSearchSolver(std::vector<std::vector<char>> board, std::vector<std::string> words) {
    board_ = board;
    words_ = words;
}
std::map<std::string,std::vector<int>> WordSearchSolver::HozWords() {
    std::map<std::string,std::vector<int>> words_info;
    for (std::string word: words_) { //loop through each word
        for (size_t row = 0; row < board_.size(); row++) { //loop through board
            for (size_t col = 0; col < board_.at(0).size(); col++) {
                int temp_col = col;
                std::string created_word; 
                while(temp_col < col + word.size() && temp_col < board_.at(0).size()) { //Forms a word starting from column goes till end of size of word //need to make sure in bounds
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

std::map<std::string,std::vector<int>> WordSearchSolver::ReverseHozWords() {
    std::map<std::string,std::vector<int>> words_info;
    for (std::string word: words_) {
        for (size_t row = 0; row < board_.size(); row++) {
            for (size_t col = board_.at(0).size() - 1; col != std::numeric_limits<size_t>::max(); col--) {
                int temp_col = col;
                std::string created_word; 
                while (temp_col > col - word.length() && temp_col >= 0) {
                    created_word += board_.at(row).at(temp_col);
                    temp_col--;
                }
                if (created_word == word) {
                    std::vector<int>positions;
                    positions.push_back(row + 1); //start row 
                    positions.push_back(col + 1); //start col
                    positions.push_back(row + 1); //end row
                    positions.push_back(col - word.size() +2) ; //end col
                    words_info[word] = positions;

                }
            }
        }
    }
    return words_info;

}
std::map<std::string,std::vector<int>> WordSearchSolver::VertWords() {
    //std::cout<<"Entered"<<std::endl;
    std::map<std::string,std::vector<int>> words_info;
    for (std::string word: words_) {
        for (size_t col = 0; col < board_.at(0).size() ; col++) {
            for (size_t row = 0; row < board_.size(); row++) {
                int temp_row = row;
                std::string created_word;
                while (temp_row < row + word.length() && temp_row < board_.size()) {
                    created_word += board_.at(temp_row).at(col);
                    temp_row++;
                }
                if (created_word == word) {
                    std::vector<int>positions;
                    positions.push_back(row + 1); //start row 
                    positions.push_back(col + 1); //start col
                    positions.push_back(row + word.length()); //end row
                    positions.push_back(col + 1) ; //end col
                    words_info[word] = positions;
                }
            }

        }
    }

    return words_info;
}
std::map<std::string,std::vector<int>> WordSearchSolver::ReverseVertWords() {
    std::map<std::string,std::vector<int>> words_info;
    for (std::string word: words_) {
        for (size_t col = 0; col < board_.at(0).size() ; col++) {
            for (size_t row = board_.size() - 1; row != std::numeric_limits<size_t>::max(); row--) {
                int temp_row = row;
                std::string created_word;
                while (temp_row > row - word.length() && temp_row >= 0) {
                    created_word += board_.at(temp_row).at(col);
                    temp_row--;
                }
                if (created_word == word) {
                    std::vector<int>positions;
                    positions.push_back(row + 1); //start row 
                    positions.push_back(col + 1); //start col
                    positions.push_back(row - word.length() + 2); //end row
                    positions.push_back(col + 1) ; //end col
                    words_info[word] = positions;
                }
            }
        }
    }

    return words_info;

}
std::map<std::string,std::vector<int>> WordSearchSolver::TopDiagWords() {
    std::map<std::string,std::vector<int>> words_info;
    for (std::string word: words_) {
        for (size_t row = 0; row < board_.size() ; row++) {
            for (size_t col = 0; col < board_.at(0).size(); col++) {
                int temp_row = row;
                int temp_col = col;
                std::string created_word;
                while ((temp_row < row + word.length()) && (temp_col < col + word.length()) 
                && (temp_row < board_.size()) && (temp_col < board_.at(0).size())) {
                    created_word += board_.at(temp_row).at(temp_col);
                    temp_row++;
                    temp_col++;
                }
                if (created_word == word) {
                    std::vector<int>positions;
                    positions.push_back(row + 1); //start row 
                    positions.push_back(col + 1); //start col
                    positions.push_back(row + word.length()); //end row
                    positions.push_back(col + word.length()) ; //end col
                    words_info[word] = positions;
                }
            }
        }
    }
    return words_info;
    

}
std::map<std::string,std::vector<int>> WordSearchSolver::TopDiagReverseWords() {
    std::map<std::string,std::vector<int>> words_info;
    for (std::string word: words_) {
        for (size_t row = 0; row < board_.size() ; row++) {
            for (size_t col = board_.at(0).size() - 1; col != std::numeric_limits<size_t>::max(); col--) {
                int temp_row = row;
                int temp_col = col;
                std::string created_word;
                while ((temp_row < row + word.length()) && (temp_col > col - word.length()) 
                && (temp_row < board_.size()) && (temp_col >= 0)) {
                    created_word += board_.at(temp_row).at(temp_col);
                    temp_row++;
                    temp_col--;
                }
                if (created_word == word) {
                    std::vector<int>positions;
                    positions.push_back(row + 1); //start row 
                    positions.push_back(col + 1); //start col
                    positions.push_back(row + word.length()); //end row
                    positions.push_back(col - word.size() +2) ; //end col
                    words_info[word] = positions;
                }
            }
        }
    }

    return words_info;

}
std::map<std::string,std::vector<int>> WordSearchSolver::BottomDiagWords() {
    std::map<std::string,std::vector<int>> words_info;
    for (std::string word: words_) {
        for (size_t col = 0; col < board_.at(0).size() ; col++) {
            for (size_t row = board_.size() - 1; row != std::numeric_limits<size_t>::max(); row--) {
                int temp_row = row;
                int temp_col = col;
                std::string created_word;
                while (temp_row > row - word.length() && temp_row >= 0 && temp_col < col + word.length() && temp_col < board_.at(0).size()) {
                    created_word += board_.at(temp_row).at(temp_col);
                    temp_row--;
                    temp_col++;
                }
                if (created_word == word) {
                    std::vector<int>positions;
                    positions.push_back(row + 1); //start row 
                    positions.push_back(col + 1); //start col
                    positions.push_back(row - word.length() + 2); //end row
                    positions.push_back(col + word.size()) ; //end col
                    words_info[word] = positions;
                }
            }
        }
    }
    return words_info;
}
std::map<std::string,std::vector<int>> WordSearchSolver::BottomDiagReverseWords() {
    std::map<std::string,std::vector<int>> words_info;
    for (std::string word: words_) {
        for (int row = board_.size() - 1; row >= 0; row--) {
            for (int col = board_.at(0).size() - 1; col >= 0; col--) {
                int temp_row = row;
                int temp_col = col;
                std::string created_word;
                while ((temp_row > row - word.length()) && (temp_row >= 0) && (temp_col > col - word.length()) && (temp_col >= 0)) {
                    created_word += board_.at(temp_row).at(temp_col);
                    temp_row--;
                    temp_col--;
                }
                if (created_word == word) {
                    std::vector<int>positions;
                    positions.push_back(row + 1); //start row 
                    positions.push_back(col + 1); //start col
                    positions.push_back(row - word.length() + 2); //end row
                    positions.push_back(col - word.size() +2) ; //end col
                    words_info[word] = positions;
                }
            }
        }
    }
    return words_info;
}
void WordSearchSolver::PrintInfo(int num_words) {
    std::cout<<"\nIt seems as you decided to give up. Here are the solutions along with board."<<std::endl;
    std::cout<<"\n   ";
    for(int x = 1; x <= board_.size(); x++) {
        if (x < 10) {
            std::cout<<x<<"  ";
        }
        else {
            std::cout<<x<<" ";
        }
    }
    std::cout<<"\n";
    for (size_t r =0; r < board_.size(); r++) {
        std::cout<<r+1<<" ";
        for(size_t x = 0; x < board_.size(); x++) {
            if (x == 0 && r < 9) { //Used to make the board look neater whenever we print the first column and row val > 9 format looks slightly off
                std::cout<<" ";
            }
            std::cout<<board_.at(r).at(x)<<"  ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    std::vector<std::map<std::string,std::vector<int>>> words_info; //Each element of this vector represents a map where the first element (key) is the word and the second element (value) is a vector of key positions
    words_info.push_back(HozWords());
    words_info.push_back(ReverseHozWords());
    words_info.push_back(VertWords());
    words_info.push_back(ReverseVertWords());
    words_info.push_back(TopDiagWords());
    words_info.push_back(TopDiagReverseWords());
    words_info.push_back(BottomDiagWords());
    words_info.push_back(BottomDiagReverseWords());
    for (std::map<std::string,std::vector<int>> map : words_info) {
        for (auto x : map) {
        std::cout<<x.first<<" ";
        for (int p : x.second) {
            std::cout<<p<<" ";
        }
        std::cout<<"\n";
        }
    }
    std::cout<<"\nFirst Column = Words"<<std::endl;
    std::cout<<"Second Column = Starting Row Index"<<std::endl;
    std::cout<<"Third Column = Starting Column Index"<<std::endl;
    std::cout<<"Fourth Column = Ending Row Index"<<std::endl;
    std::cout<<"Fifth Column = Ending Column Index"<<std::endl;
    if (num_words == 0) {
        std::cout<<"\nYou weren't able to find any words."<<std::endl;
    }
    else if (num_words == 1) {
        std::cout<<"\nYou were only able to find one word."<<std::endl;
    }
    else if (num_words == words_.size() - 1) {
        std::cout<<"You were very close. You only had to find one more word."<<std::endl;
    }
    else {
        std::cout<<"\nYou were only available to find "<<num_words<<" words."<<std::endl;
    }
}