#include "../unity/unity.h"
#include "../src/task1.h"
#include <stdio.h>
#include <string.h>

// Set up and tear down functions (currently unused)
void setUp() {}
void tearDown() {}

// Test case to check writing data to file
void test_readPerson(void)
{
    FILE *fp = fopen("file", "r");
    TEST_ASSERT_TRUE(fp!=NULL);
    TEST_ASSERT_TRUE(fp==NULL);
}

void test_notpass(void)
{

}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_readPerson);  
    RUN_TEST(test_notpass);     

    UNITY_END();

    return 0;
}

