#ifndef WORD_SEARCH_HPP
#define WORD_SEARCH_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
std::vector<std::vector<char>> GetBoard();
std::vector<std::string> GetWords();
void PrintBoardOnly();
void PrintBoard();
void CheckHoz(int row_first, int col_first, int col_last, int& tracker, std::map<std::string, bool>& words_tracker);
void CheckVert(int col_first, int row_first, int row_last, int& tracker, std::map<std::string, bool>& words_tracker);
void CheckTopDiag(int row_first, int row_last, int col_first, int col_last, int& tracker, std::map<std::string, bool>& words_tracker);
void CheckBottomDiag(int row_first, int row_last, int col_first, int col_last, int& tracker, std::map<std::string, bool>& words_tracker);
void CheckWord(std::string created_word, int& tracker, std::map<std::string, bool>& words_tracker);
void Undo(std::string direction, std::string pos, int& num);
void PrintInfo(std::string choice);
void Undo(std::string& choice);
#endif