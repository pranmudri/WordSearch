#include <iostream>
#include <vector>
#include <string>
void RandomWordSearch() {
    std::string input;
    std::cout<<"Do you want to create your own word search puzzle and solve it? (y/n) ";
    std::cin>>input;
    while(input != "y" && input != "n") {
        std::cout<<"Invalid Answer! Enter y for yes or n for no ";
        std::cin>>input;
    }
    if (input == "y") {
        int words;
        std::cout<<"How many words would you like to have in your word search puzzle?\nEnter a number between 6-12: ";
        std::cin>>words;
        while(words < 6 || words > 12) {
            std::cout<<"Invalid Number. Enter a number between 6-12:  ";
            std::cin>>words;
        }
        std::vector<std::string>indexes = {"st","nd","rd"};
        for (int x = 4; x <= words; x++) {
            indexes.push_back("th");
        }

        for (int x = 1; x <= words; x++) {
            std::string individual_word;
            std::vector<std::string>user_words;
            std::cout<<"Enter in the "<<x<<indexes.at(x - 1)<<" word: ";
            std::cin>>individual_word;
            user_words.push_back(individual_word);
        }

    }

}