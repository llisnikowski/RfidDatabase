#include <gtest/gtest.h>

#if defined(unit_main2)
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#elif defined(arduino_main2)
void setup()
{
    ::testing::InitGoogleTest();
    int a = RUN_ALL_TESTS();
}

void loop(){}
#endif