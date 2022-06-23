#ifndef RANDOM_HPP
#define RANDOM_HPP
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
class Random {
public:
    Random(std::string difficulty);
    void Game();
    std::vector<std::vector<char>> GenerateRandomBoard(std::vector<std::string>& words);
    void Print(std::vector<std::vector<char>> board);
    void AddHozWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words);
    void AddVertWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words);
    void HozHelper(std::vector<std::vector<char>> board, std::vector<std::string> words, int row);


private:
    std::string difficulty_;
    int num_words;
    int cols;
    int rows;
    int hoz_words;
    int vert_words;
};




#endif

