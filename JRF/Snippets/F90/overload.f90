MODULE overload
    IMPLICIT NONE

    TYPE fraction
        INTEGER :: numerator
        INTEGER :: denominator
    END TYPE fraction

    INTERFACE OPERATOR (+)
        MODULE PROCEDURE frac_add
    END INTERFACE

    CONTAINS

    SUBROUTINE reduce(frac1)
        IMPLICIT NONE
        TYPE(fraction), INTENT(INOUT) :: frac1
        INTEGER :: a,b

        a = frac1%numerator
        b = frac1%denominator

        DO WHILE (b/=0)
            a = b
            b = MOD(a,b)
        END DO

        frac1%numerator = frac1%numerator/a
        frac1%denominator = frac1%denominator/a

    END SUBROUTINE reduce

    FUNCTION frac_add(frac1,frac2)
        IMPLICIT NONE
        TYPE(fraction), INTENT(IN) :: frac1, frac2 ! needed for overloading
        TYPE(fraction) :: frac_add

        frac_add%numerator = frac1%numerator * frac2%denominator + frac2%numerator * frac1%denominator
        frac_add%denominator = frac1%denominator * frac2%denominator

        CALL reduce(frac_add)
        
    END FUNCTION frac_add

END MODULE overload