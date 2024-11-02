#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "lib.c"

// Very small test helpers
int failed = 0;
#define TEST(name) void name()
#define RUN_TEST(name)                     \
    printf("\n\033[1m%s\n\033[0m", #name); \
    name()
#define ASSERT(expr)                                  \
    if (!(expr))                                      \
    {                                                 \
        failed = 1;                                   \
        printf("\033[0;31mFAIL: %s\n\033[0m", #expr); \
    }                                                 \
    else                                              \
    {                                                 \
        printf("\033[0;32mPASS: %s\n\033[0m", #expr); \
    }
#define ASSERT_STR_EQ(str1, str2)                                 \
    if (!(strcmp(str1, str2) == 0))                               \
    {                                                             \
        failed = 1;                                               \
        printf("\033[0;31mFAIL: %s === %s\n\033[0m", str1, str2); \
    }                                                             \
    else                                                          \
    {                                                             \
        printf("\033[0;32mPASS: %s === %s\n\033[0m", str1, str2); \
    }
// End of test helpers

#define BUFLEN 1000

void resetBuffer(char *buffer)
{
    buffer[0] = '\0';
}

TEST(test_wordinator)
{
    char buffer[BUFLEN] = "";

    wordinator(buffer, 1);
    ASSERT_STR_EQ(buffer, "one");

    resetBuffer(buffer);
    wordinator(buffer, 13);
    ASSERT_STR_EQ(buffer, "thirteen");

    resetBuffer(buffer);
    wordinator(buffer, 20);
    ASSERT_STR_EQ(buffer, "twenty");

    resetBuffer(buffer);
    wordinator(buffer, 73);
    ASSERT_STR_EQ(buffer, "seventythree");

    resetBuffer(buffer);
    wordinator(buffer, 92);
    ASSERT_STR_EQ(buffer, "ninetytwo");

    resetBuffer(buffer);
    wordinator(buffer, 100);
    ASSERT_STR_EQ(buffer, "one hundred");

    resetBuffer(buffer);
    wordinator(buffer, 102);
    ASSERT_STR_EQ(buffer, "one hundred and two");

    resetBuffer(buffer);
    wordinator(buffer, 147);
    ASSERT_STR_EQ(buffer, "one hundred and fortyseven");

    resetBuffer(buffer);
    wordinator(buffer, 499);
    ASSERT_STR_EQ(buffer, "four hundred and ninetynine");
}

int main()
{
    RUN_TEST(test_wordinator);
    return failed;
}
