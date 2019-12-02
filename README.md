# Itsy_Bitsy_Spider_Maze
INTRODUCTION:

This program will take in any matrix int the format of

number of mazes

maze_floors maze_rows maze_columns

start_floor start_row start_column

end_floor end_row end_column

followed by each individual cells data in the directions you can traverse from that spot in this order:
    North, East, South, West, Up, Down
with 1 being it can move in that direction.

you then repeat that format above for each maze(you only need the number of mazes at the top once);

make sure the input file that you want to use for this program is in the same folder as Main.cpp and that it is titled "input.txt"

TO COMPILE:

    g++ -o matrix Main.cpp
    
    ./matrix.exe
