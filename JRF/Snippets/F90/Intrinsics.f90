PROGRAM main 
    IMPLICIT NONE

    INTEGER     :: i
    REAL        :: x
    COMPLEX     :: c
    LOGICAL     :: bool
    CHARACTER   :: a
    CHARACTER(len=180) :: string

    ! values can be assigned at creation (could do this in 77 but it was odd)
    REAL            :: y=3.5
    REAL, PARAMETER :: pi=3.1415927

    ! change allocation size
    INTEGER(KIND=2) :: int_short
    INTEGER(KIND=4) :: int_normal
    INTEGER(KIND=8) :: int_long  ! not always available

    REAL(KIND=4) :: real_normal
    REAL(KIND=8) :: real_long ! also DOUBLE PRECISION
    REAL(KIND=16) :: real_quad ! not always available

    COMPLEX(KIND=4) :: cmpx_normal
    COMPLEX(KIND=8) :: cmpx_long

END PROGRAM