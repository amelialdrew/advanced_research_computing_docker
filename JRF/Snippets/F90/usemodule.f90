PROGRAM main 

    USE keep_count
    USE constants, ONLY : speed_of_light => c 

    IMPLICIT NONE

    INTEGER :: i

    CALL reset()

    DO i=10,99
        IF (MOD(i,7)==0) THEN
            CALL increment(1)
        END IF
    END DO

    WRITE(*,*) 'number of 2 digit numbers divisible by 7 is: ', get_count()
    WRITE(*,*) 'speed of light is: ', speed_of_light

END PROGRAM