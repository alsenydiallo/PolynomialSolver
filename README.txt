Name: Alseny Diallo
email: Alsenidiallo@live.com

Included file:
--------------
- main.c

About the program:
------------------
The following program implimment the algorithm of Dirand kerner for solving the nth root of any polinomial of nth degree.

compile:
--------
gcc -Wall -std=c99 -D_GNU_SOURCE -DREGURGITATE main.c -o dk-skeleton -lm

 run:
 ----
 create a .txt file with root coeficient
 ex:
 5
 6
 9
 and run the program with your .txt as input file
   ./dk-skeleton < filename
