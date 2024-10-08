#include "../unity/unity.h"  
#include "../src/task1.h"
void setUp() {}

void tearDown() {}

void test_pass(void)
{
	    ST s1[3] = {
        {"Prit", "Rajkot"},
        {"Yash", "V V Nagar"},
        {"Yogi", "Anand"}
    };

    char *result = searchTown(s1, "Prit");
    TEST_ASSERT_EQUAL_STRING("Rajkot", result);

    

    result = searchTown(s1, "Yash");
    TEST_ASSERT_EQUAL_STRING("V V Nagar", result);
}

void test_notpass(void)
{
	          ST s1[3] = {
        {"Prit", "Rajkot"},
        {"Yash", "V V Nagar"},
        {"Yogi", "Anand"}
    };
	  //char *result = searchTown(s1, "Yash");
	  char *result = searchTown(s1, "Gopi");
    TEST_ASSERT_NULL(result);
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_pass);
    RUN_TEST(test_notpass);
    

    UNITY_END();

    return 0;
}

