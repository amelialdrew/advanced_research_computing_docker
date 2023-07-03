#include <gtest/gtest.h>

#include "../src/harmonic/harmonic.hpp"

TEST(harmonic, basic_operations){

    EXPECT_EQ(harmonic::harm_add(20e0, 5e0), 4e0) << "Harmonic add failed basic operation";    
    EXPECT_EQ(harmonic::harm_add(5e0, 20e0), harmonic::harm_add(20e0, 4e0)) << "Harmonic add does not commute";    
 
}