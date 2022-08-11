#ifndef WORD_SEARCH_HPP
#define WORD_SEARCH_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "WordSearchSolver.hpp"
std::vector<std::vector<char>> GetBoard();
std::vector<std::string> GetWords();
void PrintBoardOnly();
void PrintBoard();
void CheckHoz(int row_first, int col_first, int col_last, int& tracker, std::map<std::string, bool>& words_tracker, std::vector<std::vector<char>> board, std::vector<std::string> words);
void CheckVert(int col_first, int row_first, int row_last, int& tracker, std::map<std::string, bool>& words_tracker, std::vector<std::vector<char>> board, std::vector<std::string> words);
void CheckTopDiag(int row_first, int row_last, int col_first, int col_last, int& tracker, std::map<std::string, bool>& words_tracker, std::vector<std::vector<char>> board, std::vector<std::string> words);
void CheckBottomDiag(int row_first, int row_last, int col_first, int col_last, int& tracker, std::map<std::string, bool>& words_tracker, std::vector<std::vector<char>> board, std::vector<std::string> words);
void CheckWord(std::string created_word, int& tracker, std::map<std::string, bool>& words_tracker, std::vector<std::string> words);
void Undo(std::string direction, std::string pos, int& num, int rows);
void PrintInfo(std::string choice);
void Undo(std::string& choice);
#endif