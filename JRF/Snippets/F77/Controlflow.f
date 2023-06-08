       PROGRAM main 
       IMPLICIT NONE

       INTEGER i,j,k
       INTEGER n,m

       n=0
       m=1

       IF (n .EQ. m) THEN
           WRITE(*,*) "same"
       ELSE IF (n .GT. m)
           WRITE(*,*) "larger"
       ELSE 
           WRITE(*,*) "smaller"
       END IF

       DO 99 i=1,10
           n = n+i
 99    CONTINUE
       WRITE(*,*) n

 88    IF(m .GT. 10) THEN
           WRITE(*,*) m
           m = m+1
           GOTO 88
       END IF
       WRITE(*,*) m
       
       STOP
       END