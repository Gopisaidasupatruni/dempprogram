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
    // Initialize test data
    ST s1[3] = {
        {"Alice",  25, 50000.0},
        {"Bob",  30, 60000.0},
        {"Charlie",  35, 70000.0}
    };
    FILE *fp = fopen("file", "w");
    TEST_ASSERT_NOT_NULL(fp);  // Ensure file opened correctly

    for (int i = 0; i < 3; i++) {
        fprintf(fp, "%s %d %f\n", s1[i].sName, s1[i].iAge, s1[i].fSalary);
    }
    fclose(fp);

    // Check the file contents
    fp = fopen("file", "r");
    TEST_ASSERT_NOT_NULL(fp);  // Ensure file opened correctly


    char buffer[200];
    fgets(buffer, sizeof(buffer), fp);
    TEST_ASSERT_EQUAL_STRING("Alice 25 50000.000000\n", buffer);

    fgets(buffer, sizeof(buffer), fp);
    TEST_ASSERT_EQUAL_STRING("Bob 30 60000.000000\n", buffer);

    fgets(buffer, sizeof(buffer), fp);
    TEST_ASSERT_EQUAL_STRING("Charlie 35 70000.000000\n", buffer);

    fclose(fp);
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

