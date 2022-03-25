// 19-02-2021

/*
DECIMAL NUMBER SYSTEM : 
    Numbers are divided in the power of 10.
    1000    100     10      1
    Example = 1234;
    1234 = 1X1000 + 2X100 + 3X10 + 4X1;

BINARY NUMBER SYSTEM :  
    Numbers are divided in the power of 2.
    32      16      8       4       2       1
    Example = 45;
    45 = 1X32 + 0X16 + 1X8 + 1X4 + 0X2 + 1X1;
*/

/*
      N       (N%2)     (N/2)
      45        1        22
      22        0        11
      11        1        5   
      5         1        2
      2         0        1
      1         1        0

    Answer is reverse of the column (N%2)
    45 = 101101.
*/

