PROGRAM main 
    IMPLICIT NONE

    TYPE :: my_type
        INTEGER :: moons 
        REAL :: coord_x, coord_y
        CHARACTER(30) :: name
    END TYPE my_type

    TYPE(my_type) :: planets(8)
    REAL :: vector1(8)
    REAL :: x

    planets(1)%moons = 0
    planets(1)%name = "Mercury"
    planets(1)%coord_x = 58e6
    planets(1)%coord_y = 0e0

    planets(3) = (/1,152e6,0e0,"Earth"/)

    vector1 = planets%coord_x
    x = SUM(planets%moons)

END PROGRAM