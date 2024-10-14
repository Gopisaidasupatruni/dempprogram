#include "../unity/unity.h"
#include "../src/task1.h"
#include <stdio.h>
#include <string.h>

void setUp() {}
void tearDown() {}

void testreadPerson(void)
{
    /* Initialize test data */
    ST s1[3] = {
        {"Sai",  25, 5},
        {"Gopi",  30, 6},
        {"Rakesh",  35, 7}
    };
    FILE *fp = fopen("file", "w");
    TEST_ASSERT_NOT_NULL(fp); 

    for (int i = 0; i < 3; i++) {
        fprintf(fp, "%s %d %f\n", s1[i].sName, s1[i].iAge, s1[i].fSalary);
    }
    fclose(fp);

    fp = fopen("file", "r");
    TEST_ASSERT_NOT_NULL(fp); 


    char buffer[200];
    fgets(buffer, sizeof(buffer), fp);
    TEST_ASSERT_EQUAL_STRING("Sai 25 5.000000\n", buffer);

    fgets(buffer, sizeof(buffer), fp);
    TEST_ASSERT_EQUAL_STRING("Gopi 30 6.000000\n", buffer);

    fgets(buffer, sizeof(buffer), fp);
    TEST_ASSERT_EQUAL_STRING("Rakesh 35 7.000000\n", buffer);

    fclose(fp);
}

void test_notpass()
{
  FILE *fp;

    fp = fopen("file", "r");
    TEST_ASSERT_NOT_NULL(fp); 


    char buffer[200];
    fgets(buffer, sizeof(buffer), fp);
    TEST_ASSERT_EQUAL_STRING("sai 25 5.000000\n", buffer);

}
int main()
{
    UNITY_BEGIN();

    RUN_TEST(testreadPerson);  
    RUN_TEST(test_notpass);     

    UNITY_END();

    return 0;
}

