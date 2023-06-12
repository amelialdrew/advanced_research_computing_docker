PROGRAM main 
    IMPLICIT NONE

    INTEGER :: i
    REAL :: x
    INTEGER :: fileunit
    CHARACTER(180) :: filename
    REAL, DIMENSION(:,:), ALLOCATABLE :: array1

    fileunit = 99

    i = 4000
    x = 2.45e3
    ALLOCATE(array1(10,10))
    array1 = 5.67
    filename = "test.out"

    90101 FORMAT('The output is: ',I5,'	',E13.5E3)

    OPEN(UNIT=fileunit, FILE=filename)
    WRITE(UNIT=fileunit,FMT=90101) i,x
    CLOSE(UNIT=fileunit)

    ! for arrays use this:
    OPEN(UNIT=fileunit, FILE=filename, STATUS='REPLACE', FORM='UNFORMATTED', ACCESS='STREAM')
    WRITE(fileunit,*) array1
    CLOSE(fileunit)

    OPEN(UNIT=fileunit, FILE=filename, STATUS='OLD', FORM='UNFORMATTED', ACCESS='STREAM')
    READ(fileunit,*) array1
    CLOSE(fileunit)
    
END PROGRAM