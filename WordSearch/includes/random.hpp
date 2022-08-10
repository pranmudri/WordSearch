#ifndef RANDOM_HPP
#define RANDOM_HPP
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>
#include "wordsearch.hpp"
class Random {
public:
    Random(std::string difficulty);
    void Start();
    void Game(std::vector<std::vector<char>> board, std::vector<std::string>copy_words, WordSearchSolver w1);
    std::vector<std::vector<char>> GenerateRandomBoard(std::vector<std::string>& words);
    void Print(std::vector<std::vector<char>> board);
    void AddHozWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words, std::vector<std::pair<size_t, size_t>>& occupied_spots);
    void AddVertWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words, std::vector<std::pair<size_t, size_t>>& occupied_spots);
    std::vector<size_t> LongestConsecSeq(std::vector<std::pair<size_t, size_t>>& occupied_spots, size_t key_col);
    void HozHelper(std::vector<std::vector<char>> board, std::vector<std::string> words, int row);
    std::vector<std::string> GetRandomSetWords();
    


private:
    std::string difficulty_;
    int num_words;
    int cols;
    int rows;
    int hoz_words;
    int vert_words;
};




#endif

