       PROGRAM main 
       IMPLICIT NONE

       INTEGER i,j,k
       REAL x,y,z1,z2,z3,z4
       DOUBLE PRECISION d1, d2
       COMPLEX c1
       LOGICAL bool1, bool2, bool3, bool4
       CHARACTER str*8
       REAL arr(4,5,6)
       
       i = 2
       j = 3
       x = 2.0
       y = 3.0
       c1 = (1,3)
       str = 'hello'

       z1 = x+y
       z2 = x*y
       z3 = y/x
       z4 = y**x
       WRITE(*,*) z1,z2,z3,z4

       bool1 = i .LT. j
       bool2 = i .GE. j
       bool3 = i .EQ. j
       bool4 = i .NE. j
       WRITE(*,*) bool1,bool2,bool3,bool4

       STOP
       END