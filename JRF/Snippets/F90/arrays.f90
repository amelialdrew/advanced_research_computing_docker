PROGRAM main 
    IMPLICIT NONE

    ! Fixed size at compile
    INTEGER i,j,k
    INTEGER                 :: vector1(5)
    INTEGER                 :: array1(5,5)
    INTEGER, DIMENSION(5,5) :: array2
    ! Dynamic allocation
    INTEGER, ALLOCATABLE                    :: vector2(:)
    INTEGER, ALLOCATABLE                    :: array3(:,:)
    INTEGER, DIMENSION(:,:), ALLOCATABLE    :: array4
    INTEGER, POINTER                        :: array5(:,:)
    INTEGER, DIMENSION(:,:), POINTER        :: array6

    ALLOCATE(array3(5,5))
    IF (ALLOCATED(array3)) THEN
        WRITE(*,*) 'Array 3 allocated'
        WRITE(*,*) "array size", SIZE(array3,1), " X ", SIZE(array3,2)
    END IF

    ALLOCATE(array4(-5:3,0:4))  ! indicies can range from anything to anything else, default is 3 -> 1,2,3
    
    ALLOCATE(array5(5,5))
    ALLOCATE(array6(3,3))

    array1 = 0 ! whole array assignment
    array1(2,2) = 7 ! element assignment
    vector1 = (/1,2,3,4,5/) ! all elements in one go
    vector1 = (/(i**2,i=1,5)/) ! via a constructor rule
    array1(1,:) = 5 ! row assignment
    array1(3,1:5:2) = 3 ! assignment with step size -> (3,1), (3,3), (3,5) = 3

    array2 = 5*array1 + 6 ! supports whole array element-wise calcuations (most functions too!)

    array5 = 1
    array6 = array5(2:4,2:4) ! assiging from sub-array

    ! Intrinsic array operations
    
    i = SUM(array1) ! add all elements together
    j = PRODUCT(array1) ! multiply all elements together
    k = MAXVAL(array1) ! find the maximum
    k = MAXVAL(array1, MASK = (MOD(array1,2)>0)) ! find the maximum odd number
    vector1 = MAXVAL(array1, DIM=1) ! find the maximum in each row
    i = SIZE(SHAPE(array1))
    ALLOCATE(vector2(i))
    vector2 = MAXLOC(array1) ! find the location of the maximum

    array5 = MATMUL(array1,array2)
    array1 = TRANSPOSE(array1)

    !  Cool syntax for conditional array modification 
    WHERE (array1/=0)
        array1 = -array1
    ELSEWHERE
        array1 = 5
    END WHERE

    ! NEED TO DEALLOCATE ALLOCATABLE ARRAYS AFTER USE!!
    DEALLOCATE(array3)

END PROGRAM