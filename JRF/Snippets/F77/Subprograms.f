      PROGRAM main 
      IMPLICIT NONE

      INTEGER i,j,k
      INTEGER add
      
      i=1, j=2
      k = add(i,j)
      WRITE(*,*) k

      CALL rotate(i,j,k)
      WRITE(*,*) i,j,k

      STOP
      END
    
      INTEGER FUNCTION add(i,j)
      IMPLICIT NONE
      INTEGER i,j
      add = i+j
      RETURN
      END
    
      SUBROUTINE rotate(i,j,k)
      IMPLICIT NONE
      INTEGER i,j,k,n
      n=i 
      i=j
      j=k
      k=n
      RETURN
      END