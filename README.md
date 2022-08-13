# WordSearch
Table of Contents

Description/Features of My Project

Motivation for Project


Difficulties Ran Into

How to Run Project in VS Code on local Machine

Images of My Project


Additional Features to Add Later 

Description/Features of My Project

	This is my word search project. I did this project in C++. In this project, the user can choose to solve a word search puzzle I found off the internet or choose to solve a randomly generated word search puzzle based on varying difficulty. Whichever word puzzle they choose to solve, they'll be asked at first to think of a word from the list of words shown. Then they'll be asked to enter in the row and the column of where they think the first letter of that word lies as well as the row and column of where the last letter of that word lies. After entering each number in, they’ll be asked to continue or undo in the event that they accidentally typed in the wrong row or column number. The program then takes these numbers to create a word out of them. For example if the user believes the first letter of a specific word lies in row 3 and column 1 and the last letter lies in row 3 and column 6, the letters between these coordinates would get added together to form a word. Then this created word is scanned through a vector of the words needed to be found in the word search puzzle. If the word was able to be found in the vector, then the user successfully found a word. The game continues until the user finds all the words.
	The game starts off by asking the user if they want to solve the word search puzzle I found off the internet. Following this the user is asked if they want to solve a randomly generated word search puzzle or resolve the same word search puzzle again. If the user decides to solve a randomly generated word search puzzle. The user would be asked if they want an easy search to solve or a hard one to solve. If they choose an easy word search to solve then they’ll be given a random list of 6 words to find, all of which have 6 letters or less, on a 10 by 10 board. These words are positioned horizontally and vertically. If they choose a hard word search to solve they will be provided a list of 12 words to find, all of which have 8 letters or less, on a 20 by 20 board. Once they’ve finished solving a random word search puzzle, they’ll be asked if they want to solve another one. The game continues until at the end of a round, the user says no that they no longer want to continue solving word search puzzles.
	Additionally, if the user feels that the word search is too difficult for them they can hit 99 anytime to quit and then they will be provided the solutions of where the words are located. I created a solver component that takes in a word search board, and vector of words. It uses these two things to figure where the words lie. 

Motivation for Project

	What motivated me to work on this project was that I was looking for projects to work on over summer break. As I was researching, I came across creating a Tic Tac Toe game. After working on the Tic Tac Toe project, I thought of working on a project similar to Tic Tac Toe but more extensive. I eventually decided to work on creating a Connect 4 game. Following the Connect 4 project, I wanted to again work on a similar but more extensive project, and that’s when I decided to work on a WordSearch puzzle game project. At first I thought I’ll just find a word search puzzle off the internet and get the user to solve it. Then I decided to create a solver feature to be used as a tool for the user in case the user is unable to find where all the words are. After that I wondered if it would be possible to randomly place a set of words on a board as well as randomly generate that set. 

Difficulties Ran Into

	One of the biggest hurdles I ran into was generating a random board of words. What made it difficult was the fact that if I placed the word randomly in horizontal direction and then vertically, the word placed vertically could interfere with the horizontally placed word causing some letters of the horizontal word to be removed. At first I thought this was an impossible problem to solve. However, later I realized that I could place certain constraints such as limiting how many letters each word can have as well as the number of words to be placed in each direction, depending on the difficulty level. Additionally, I decided I’ll work adding words horizontally and then adding words vertically. As I added each word horizontally, I kept track of the positions that were occupied on the board. Using those positions, whenever I generated a random column number to add words vertically, I would try to find the longest consecutive occurrence of unoccupied spots for the randomly generated column number. Using the longest consecutive sequence, I tried to see if the word can fit within that sequence. If not, I would continue to generate a different column until the word can fit in the sequence. Furthermore, I tried to ensure that only one word can be placed in a specific row for horizontal words or one word can be placed in a specific column for vertical words. This would enhance the difficulty of the game.

	Another difficulty I ran into was making sure that the program doesn’t count a word the user has already found more than once. For example, if the user found the word apple by typing in the key indices, and they decided again to type in the key indices for apple, the program would notify the user that they already found that word and that they needed to find another one. At first I was stuck on how I should go about doing this. I then realized I could have a map where the key represents the word and the value represents boolean value. All the values would be set to false in the beginning. Whenever the user found a word, the value of the word in the map would be set to true. Then I used this info to print out a message telling the user they already found a speific word and that they should look for other words. 




How to run program in VS Code
	Type in the terminal clang++ -std=c++20 -Iincludes ./src/main.cc ./src/random.cc ./src/wordsearch.cc ./src/WordSearchSolver.cc. 
Then type in ./a.out


ScreenShots of Program
	



<img width="864" alt="Screen Shot 2022-08-10 at 7 03 16 PM" src="https://user-images.githubusercontent.com/87880723/184257865-8309a94c-74dd-4620-8b09-276f39b6dcd0.png">


This represents the starting screen of the game. 








<img width="856" alt="Screen Shot 2022-08-10 at 7 03 59 PM" src="https://user-images.githubusercontent.com/87880723/184257357-db92bfc5-b8e0-43ec-9d12-41973bad764a.png">


This image represents when the user successfully found a word by typing in the key indices of a specific word.










<img width="842" alt="Screen Shot 2022-08-10 at 7 04 59 PM" src="https://user-images.githubusercontent.com/87880723/184257401-339e5539-ea58-45b7-8144-7fd35d76b8c7.png">

In this image the user wasn’t able to find a certain word since they didn’t type in the right indices









<img width="1122" alt="Screen Shot 2022-08-11 at 4 59 10 PM" src="https://user-images.githubusercontent.com/87880723/184257469-6d5df9ba-292c-4eac-925d-d71cb1ad866e.png">


This image represents when the user was able to find all the words in the first word search puzzle and decides to solve an easy random word search puzzle







<img width="986" alt="Screen Shot 2022-08-11 at 5 00 52 PM" src="https://user-images.githubusercontent.com/87880723/184257528-99de4cd1-87b0-4b87-9ccf-83fa8019dfae.png">


Whenever the user finds all the words in a random word search puzzle, they’re asked if they want to solve another one. 







<img width="845" alt="Screen Shot 2022-08-11 at 5 01 16 PM" src="https://user-images.githubusercontent.com/87880723/184257544-f8b0b5fd-46b1-47ba-a805-2581d570cbe1.png">

This image represents the board of a random hard level word search puzzle since the user answered yes ro solving another random word search puzzle and wanted to solve a hard one. 








<img width="858" alt="Screen Shot 2022-08-11 at 5 01 48 PM" src="https://user-images.githubusercontent.com/87880723/184257567-9b0f3b54-5363-4b7d-b5c7-77cf073394b5.png">

This image depicts the solutions to the word search puzzle formatted in a table since the user decided to quit.








<img width="497" alt="Screen Shot 2022-08-11 at 5 02 03 PM" src="https://user-images.githubusercontent.com/87880723/184257581-601b457f-840d-4e9c-85f7-98949d3881b6.png">


This image shows a description of what each column signifies in the solution table as well as the number of words the user found. (Note I found where the triangle lies, that’s why it says I found 1 word). Additionally, whenever the user is asked if they want to solve another random word search puzzle after solving one and they answer no, the game ends.



Additional Features to Work on Later
In the future I hope to be able to have the words be placed in reverse horizontal and vertical direction as well as have words be placed diagonally on the board
I also hope to be able to create some sort of hint feature to better assist the user in being able to find the words
