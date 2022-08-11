
#include "Random.hpp"
Random::Random(std::string difficulty) {

    difficulty_ = difficulty;
    if (difficulty_ == "e") {
        num_words = 6;
        rows = 10;
        cols = 10;
        hoz_words = 3;
        vert_words = 3;
    }
    else {
        num_words = 12;
        rows = 20; //Figure out best number by running program over and over and changing numbers 
        cols = 20;
        hoz_words = 6;
        vert_words = 6;
    }
}
void Random::Start() { //Starts the game (Creates a random set of words as well as generates a board)
    std::vector<std::string>words = GetRandomSetWords();
    std::vector<std::string>copy_words;
    copy_words = words; //Note the words in the original words vector get deleted so I coppied the words from original to copy_words
    std::vector<std::vector<char>> board = GenerateRandomBoard(words); //Issue with board getting generated
    WordSearchSolver w1(board, copy_words);
    Game(board, copy_words, w1); //Main Game Loop
}
std::vector<std::string> Random::GetRandomSetWords() {
    //Note the below set is only for the easy level words. If the user selected a higher level difficulty we need a different words_list
    std::vector<std::string> easy_words_list = {"apples","orange", "pencil", "fruits", "papers", "grapes", "abroad","barely", "better", "carbon", "direct", "ending",
                                            "garden", "inside", "hardly", "legacy", "water", "latest", "lawyer", "market", "medium", "native", "people", "obtain",
                                            "notice", "search", "second", "timely", "yellow", "sky", "blue", "first", "victim", "twenty", "update", "writer",
                                            "actual","action","backed", "pink", "border", "bottle", "camera", "direct", "escape", "export", "formal", "notes",
                                            "book", "brown", "health", "global", "island","jersey", "league","sound", "lights", "marine", "manage", "nature",
                                            "prison", "window", "worker", "visual", "teapot", "green", "volume", "winner","stove","mouse", "relief", "region",
                                            "reward", "return", "seize", "serve", "album", "alive", "began", "class", "fleet","guard", "ship", "horse",
                                            "mayor", "layer", "pan", "thin", "shirt", "silk", "metal", "artist", "coffee", "beans", "phone", "board",
                                            "budget", "sofa", "laptop", "video","plant", "center", "comfort", "trash", "laser", "level", "motor", "press",
                                            "steam","usage", "tower", "title", "yield", "height", "school", "ticket", "vendor", "grant", "grass", "peace",
                                            "sharp", "unique", "vegan", "resort","pursue", "palace", "rarely", "holder", "expert", "expand", "dollar", "desire",
                                            "desert", "defeat", "client", "agenda", "agency", "castle", "memory", "luxury", "strain", "meat", "suffer", "winter",
                                            "table", "spent", "suite", "super","zoo" , "voice", "valid", "trial", "jurry", "power", "sector", "leaves",
                                            "robust", "saying", "square", "string", "wholly", "whale", "tennis", "theory","plenty", "mostly", "filing", "famous",
                                            "figure", "degree", "sudden", "status","module", "invest", "fiscal", "golden", "foster", "afraid", "aspect", "bishop"};
    //8 letters or under 
    std::vector<std::string>hard_words_list = {"absolute", "baseball", "capacity", "definite", "emphasis", "facility", "guidance", "internal", "keyboard", "junction", "power", "marginal", "maximize", "opponent", "pleasant",
                                                  "persuade", "politics", "quantity", "publicly", "question", "shortage", "cellular", "takeover", "teaching", "tendency", "triangle", "ultimate", "umbrella", "universe", "woodland",
                                                  "abstract", "adjusted", "bachelor", "birthday", "casualty", "disabled", "discount", "exchange", "learning", "ability", "account", "archive", "bedroom", "channel", "decline",
                                                  "counsel", "defence", "feeling", "formula", "fortune", "founder", "gateway", "illegal", "housing", "license", "liberty", "machine", "learning", "million", "officer",
                                                  "pointed", "picking", "picture", "radical", "session", "aviation", "bulletin", "constant", "confused", "dynamics", "estimate", "innocent", "internal", "chairman", "database",
                                                  "academic", "advisory", "bathroom", "computer", "designer", "dominant", "fraction", "notebook", "renowned", "sporting", "taxpayer", "workshop", "wildlife", "withdraw","training",
                                                  "victory", "telecom", "theatre", "vehicle", "supreme", "mask", "surplus", "food", "monkey", "tension", "surgey", "stretch", "respond", "retired", "publish",
                                                  "protein", "reality", "premium", "poverty", "outlook", "optical", "illusion", "nursing", "mystery", "listing", "hearing", "heavily", "genetic", "failure", "explore",
                                                  "fiction", "expense", "faculty", "thread", "table", "counter","violet", "indigo", "laptop", "factory", "gallery", "finance", "expand", "horizon", "envelope",
                                                  "fitness", "symbolic", "survival", "relative", "recovery", "reliable", "practice", "position", "ocassion", "official", "numerous", "northern", "majority", "graduate", "deadline",
                                                  "diameter","customer", "lamp", "bulb", "screen", "time", "criminal", "decrease", "increase", "detailed","dividend", "doctrine", "document", "frontier", "friendly",
                                                  "grateful", "formerly", "goodwill", "humanity", "handling", "genomics", "graphics", "industry", "ink", "integral", "heritage", "merchant", "preserve", "possible", "voided", "null",
                                                  "whole", "methods", "vertical", "valuable", "turnover", "football", "together", "college", "warranty", "princess", "prince", "priority", "optional", "fishing", "eventual",
                                                  "movement", "glasses", "backpack", "breeding", "attorney", "approval", "campaign", "cautious", "window", "present", "heatwave", "bycicle", "recycle", "browser","bananna",
                                                  "facebook", "calendar", "autonomy", "boundary", "flexible", "foothill", "guardian", "pancake", "hurdle", "sweeping", "taxation", "prospect", "recruit", "overcome", "disposal","carpets"};
    
    std::vector<std::string>key_words_list;
    if (difficulty_ == "e") {
        key_words_list = easy_words_list;
    }
    else {
        key_words_list = hard_words_list;
    }
    //Now we need to generate 6 random indicies keep track of them so that way we can regenerate an index if there's a repeat
    unsigned seed = time(0);
    srand(seed);
    std::vector<size_t>indicies;
    for (int x = 0; x < num_words; x++) { //loop runs six times so this we way we generate 6 random indicies. However this varies based on difficulty of game 
        size_t index = (rand() % key_words_list.size()); //changed it from 180 to this since the number of words varries
        //Check to see if that index already exists within indicies
        while (std::find(indicies.begin(), indicies.end(), index) != indicies.end()) { //If we don't reach end then that means we know that we found the index, so we need to regnerate
            index = (rand() %  key_words_list.size());
        }
        indicies.push_back(index);
    }
    //Now use the indicies to get the specific words
    std::vector<std::string>key_words;
    for (size_t i : indicies) {
        key_words.push_back(key_words_list.at(i));
    }
    return key_words;
}
void Random::Game(std::vector<std::vector<char>> board, std::vector<std::string>copy_words, WordSearchSolver w1) { //Function takes in the board, the words, and a solver to use in the game 
    int tracker = 0;
    std::map<std::string,bool>words_tracker;
    for (std::string w: copy_words) {
        words_tracker[w] = false;
    }
    std::cout<<"Here is the board and the words you need to find "<<std::endl;
    while (tracker < num_words) { //Note this is no longer six since we changed the difficulty level
        std::cout<<"\n";
        Print(board);
        std::cout<<"\n";
        int count = 1;
        for(std::string word: copy_words) {
            std::cout<<word<<"  ";
            if (count % 3 == 0) {
                std::cout<<"\n";
            }
            count++;
        }
        int row_first;
        int col_first;
        std::cout<<"\nThink of a word from the provided list of words. \nNow enter in the row of where you think the first letter of that word lies. \nIf you feel that this word search is too difficult for you and want to see the solutions hit 99 at any time: ";
        std::cin>>row_first;
        while((row_first < 1 || row_first > rows) && (row_first != 99)) { //Note I changed 10 to rows to account for change in adding difficulty
            std::cout<<"Error! Enter in a valid row from 1 through "<<rows<<" or enter 99 to give up: ";
            std::cin>>row_first;
        }
        Undo("row","first",row_first, rows);
        if (row_first != 99) {
                std::cout<<"\nEnter in the column of where you think the first letter of that word lies: ";
                std::cin>>col_first;
                while((col_first < 1 || col_first > cols) && (col_first != 99)) { //Note I changed 10 to cols to account for change in adding difficulty
                    std::cout<<"Error! Enter in a valid column from 1 through "<<cols<<" or enter 99 to give up:  ";
                    std::cin>>col_first;
                }
                Undo("column","first",col_first, rows);
                if (col_first != 99) {
                    int row_last;
                    int col_last;
                    std::cout<<"\nEnter in the row of where you think the last letter of that word lies: ";
                    std::cin>>row_last;
                    while((row_last < 1 || row_last > rows) && (row_last != 99)) { //Note I changed 10 to rows to account for change in adding difficulty
                        std::cout<<"Error! Enter in a valid row from 1 through "<<rows<<" or enter 99 to give up:  ";
                        std::cin>>row_last;
                    }
                    Undo("row","last",row_last, rows);
                    if (row_last != 99) {
                        std::cout<<"\nEnter in the column of where you think the last letter of that word lies: ";
                        std::cin>>col_last;
                        while((col_last < 1 || col_last > cols) && (col_last != 99))  { //Note I changed 10 to cols to account for change in adding difficulty
                            std::cout<<"Error! Enter in a valid column from 1 through "<<cols<<" or enter 99 to give up:  ";
                            std::cin>>col_last;
                        }
                        Undo("row","last",col_last, rows);
                        if (col_last != 99) {
                            if (row_first == row_last) { 
                                CheckHoz(row_first, col_first, col_last, tracker, words_tracker, board, copy_words);
                            }
                            else if (col_first == col_last) { 
                                CheckVert(col_first, row_first, row_last, tracker, words_tracker, board, copy_words);
                            }
                            else if (row_first > row_last) {
                                CheckTopDiag(row_first,row_last,col_first,col_last, tracker, words_tracker, board, copy_words);
                            } 
                            else {
                                CheckBottomDiag(row_first,row_last,col_first,col_last, tracker, words_tracker, board, copy_words);
                            }
                        } 
                        else {
                           w1.PrintInfo(tracker);
                           tracker = num_words; //Note we need this line to succesfully break out the loop
                        }
                    }
                    else {
                        w1.PrintInfo(tracker);
                        tracker = num_words;
                    }
                }
                else {
                    w1.PrintInfo(tracker);
                    tracker = num_words;
                } 
            }
            else {
                w1.PrintInfo(tracker);
                tracker = num_words;
            }
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
        std::cout<<"\n";
        board.push_back(one_d_board);
    }
    
    std::vector<std::pair<size_t, size_t>> occupied_spots;
    AddHozWords(board,words,occupied_spots);
    //Up to here code doesn't crash
    AddVertWords(board,words, occupied_spots); //Issue with adding Vert Words
    return board;
}
void Random::AddHozWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words, std::vector<std::pair<size_t, size_t>>& occupied_spots) {
    //Make sure to delete the word from the words vector after using it
    //what if we were to generate horizontal words in the reverse direction as well?
    int x = 0;
    int max = num_words;
    std::vector<size_t>row_positions;
    unsigned seed = time(0);
    srand(seed);
    while(x < hoz_words) { //Want to place a certain number of words horizontally depending on the difficulty level
        size_t key_row = (rand() % rows); //Generate a random row (max - min + 1) + min (max = 9, min = 0 9-0 + 1 = 10 -> rows) The example I listed is for easy
        while (std::find(row_positions.begin(), row_positions.end(), key_row) != row_positions.end()) {
            key_row = (rand() % rows); //changed 10 to rows
        }
        row_positions.push_back(key_row); //What we are doing here is basically keeping track of what rows words have been added so we don't repeat rows
        size_t key_col = (rand() % cols); //Generate a col for the row we selected changed 10 to cols since we now have varying difficulty 
        size_t random_word_index = (rand() % max); //note this isn't fix variable (when word removed indicies of the vector chage) We select a random word from the list to put in horizontally on the board
        std::string key_word = words.at(random_word_index);
        while (key_col + words.at(random_word_index).length() > cols) { //Makes sure the word can fit on the board or else generate a new col
            key_col = (rand() % cols); //changed 10 to cols to account varying difficulty
        } 
        size_t index = 0;
        for (size_t temp_col = key_col; temp_col < key_col + key_word.length(); temp_col++) { //Note since the we know and the row will be fixed when adding horizontal words we can just use one loop
            board.at(key_row).at(temp_col) = key_word.at(index);
            std::pair<size_t,size_t> pos;
            pos.first = key_row;
            pos.second = temp_col;
            occupied_spots.push_back(pos);
            index++;
        }    
        words.erase(words.begin() + random_word_index); //Removes word once it gets added on the board
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
        size_t key_col = (rand() % cols); //generates random col
        size_t random_word_index = (rand() % max);
        std::string random_word = words.at(random_word_index);
        while (std::find(col_positions.begin(), col_positions.end(), key_col) != col_positions.end() || LongestConsecSeq(occupied_spots, key_col).size() < random_word.size())  { //sees if that col has already been generated or can't fit within boundary
            key_col = (rand() % cols);
        }
        col_positions.push_back(key_col);
        std::vector<size_t> longest_seq = LongestConsecSeq(occupied_spots, key_col);
        int start = longest_seq.at(0); 
        int index = 0;
        for (size_t row = start; row < start + random_word.length(); row++) {
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
    for (std::pair<size_t, size_t> pair : occupied_spots) { //Based on a random col that was generated, I'm trying to add all the rows within that column that are occupied 
        if (pair.second == key_col) {
            occupied_rows.push_back(pair.first);
        }
    }
    std::vector<size_t> unoccupied_rows;
    for (size_t x = 0; x < rows; x++) { //Changed from 10 to rows to accomdate for the varrying difficulty
        if (std::find(occupied_rows.begin(), occupied_rows.end(), x) == occupied_rows.end()) { //Can that specific row number not be found in occupied rows vector? If so add that specific number to the unoccupied rows vector
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
    std::cout<<"   ";
    for (int x = 1; x <= cols; x++) {
        //To have consitency in spaces what we should do is if x < 10 (single digit put two spaces between) but if it's double digit then single space in between
        if (x < 10) {
             std::cout<<x<<"  ";
        }
        else {
            std::cout<<x<<" ";
        }
    }
    std::cout<<"\n";
    for (size_t r =0; r < rows; r++) {
        std::cout<<r+1<<" ";
        for(size_t x = 0; x < cols; x++) {
            if (x == 0 && r < 9) { //Used to make the board look neater whenever we print the first column and row val > 9 format looks slightly off
                std::cout<<" ";
            }
            std::cout<<board.at(r).at(x)<<"  ";
        }
        std::cout<<"\n";
    }
}
