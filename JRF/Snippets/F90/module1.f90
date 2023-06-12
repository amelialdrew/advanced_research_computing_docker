MODULE keep_count 
    IMPLICIT NONE

    INTEGER, SAVE, PRIVATE :: count

    PUBLIC get_count, increment

    CONTAINS

        FUNCTION get_count()
            IMPLICIT NONE
            INTEGER get_count
            get_count = count
        END FUNCTION get_count

        SUBROUTINE increment(amount)
            IMPLICIT NONE
            INTEGER, INTENT(IN) :: amount
            count = count+amount
        END SUBROUTINE increment

        SUBROUTINE reset()
            IMPLICIT NONE
            count = 0
        END SUBROUTINE reset

END MODULE keep_count