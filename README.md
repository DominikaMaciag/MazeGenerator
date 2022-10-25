# MazeGenerator
Maze Generator is a application that I created using SFML library for my C++ final project.
I used depth first search algorithm to generate random mazes.

To make your life easier here I linked some helpful material 
how to use SFML library on Windows:

      To compile and run application (in my case) I used following commands: 
      $ g++ -c labirynt.cpp -I"C:\SFML-2.5.1\include"
      $ g++ labirynt.o -o sfml-app -L"C:\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
      & ./sfml-app

      Tutorial that shows how download and use sfml library: 
      https://www.youtube.com/watch?v=rZE700aaT5I&t=4s&ab_channel=BoostMyTool

You need to make sure that your version of SFML matches compiler that you use! 
You also need to change paths in commands that I listed.

