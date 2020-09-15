# BattleShipsGame-UCP-
This is a Basic BattleShips Game that I made using C language. 

Game.c :
This is the Brain of the game, the purpose of this file is to use the data that was read by FileReading.c and manipulate that data into a functioning game. In this file, I turn the
data that was read into a graphical version, so that the player can visualise the game without losing track of anything related to the game. My graphical version is quite different to the one that was mentioned in the assignment due to some technical difficulties, but they both work the same under same regulations. So what I did was instead of changing the colour of the ‘X’ and ‘0’ inside the graph itself, I printed out a statement saying “Enemy DOWWN” which a green colour as an expression of “0” which is supposed to be inside the graph.

![alt text]https://imgur.com/b281cyQ)

FIleReading.c :
The is the Heart of the game, the purpose of this file is to Read the data from a file that was provided by the user, then allocating them into a suitable Data Structure. I have provided 2 separate Logics in this file and they were mainly for Reading and Writing the data. For the reading, I automatically read the lines and allocate them straight into an array for the Ships and LinkedList for the Missiles. There were a lot of poor Data Structure decisions made while making this Reading Function. One of them was using an array to allocate the data which then led me to create an another double array inside Game.c so I can make a graphical version out of it. With 1D array, there was no choice for me to make a working Gui so I had to make another double array which then stores the value of the 1D array just to make a fully functioning Graphical UserInterface for the game.

LinkedList.c
The purpose of this file is Store the Missiles that was read from the File. I store the missiles as void* due to the missiles names having “-“ between names so with void* I can just read anything into it and then throw some exception after reading the objects. There was only one function in this file “addtoList()” which reads in the missiles into the linked list.

Menu.c
This is the Vision of the game, the purpose of this file is to bring the life of all the files I have mentioned above. So this file basically display the user with a menu so the user can choose whatever he/she desires but before the Player execute the Menu.c it has to input two file names in the order of “boardFile MissileFile” to run the program. Instead of using the if statements for the userInputs I end up using switch cases which I think is the most suitable way to implement in this situation.
