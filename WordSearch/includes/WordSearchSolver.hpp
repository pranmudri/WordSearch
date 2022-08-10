#ifndef WordSearchSolver_HPP
#define WordSearchSolver_HPP
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cstddef>
#include <limits>
class WordSearchSolver {
public:
    WordSearchSolver(std::vector<std::vector<char>> board, std::vector<std::string> words);
    std::map<std::string,std::vector<int>> HozWords();
    std::map<std::string,std::vector<int>> ReverseHozWords();
    std::map<std::string,std::vector<int>> VertWords();
    std::map<std::string,std::vector<int>> ReverseVertWords();
    std::map<std::string,std::vector<int>> TopDiagWords();
    std::map<std::string,std::vector<int>> TopDiagReverseWords();
    std::map<std::string,std::vector<int>> BottomDiagWords();
    std::map<std::string,std::vector<int>> BottomDiagReverseWords();
    void PrintInfo(int num_words);

private:
    std::vector<std::vector<char>> board_;
    std::vector<std::string> words_;

};

#endif