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

    resetBuffer(buffer);
    wordinator(buffer, 1000);
    ASSERT_STR_EQ(buffer, "one thousand");

    resetBuffer(buffer);
    wordinator(buffer, 3333);
    ASSERT_STR_EQ(buffer, "three thousand, three hundred and thirtythree");

    resetBuffer(buffer);
    wordinator(buffer, 6029);
    ASSERT_STR_EQ(buffer, "six thousand, twentynine");

    resetBuffer(buffer);
    wordinator(buffer, 6209);
    ASSERT_STR_EQ(buffer, "six thousand, two hundred and nine");

    resetBuffer(buffer);
    wordinator(buffer, 10209);
    ASSERT_STR_EQ(buffer, "ten thousand, two hundred and nine");

    resetBuffer(buffer);
    wordinator(buffer, 102209);
    ASSERT_STR_EQ(buffer, "one hundred and two thousand, two hundred and nine");

    resetBuffer(buffer);
    wordinator(buffer, 600209);
    ASSERT_STR_EQ(buffer, "six hundred thousand, two hundred and nine");

    resetBuffer(buffer);
    wordinator(buffer, 1600209L);
    ASSERT_STR_EQ(buffer, "one million, six hundred thousand, two hundred and nine");

    resetBuffer(buffer);
    wordinator(buffer, 20000209L);
    ASSERT_STR_EQ(buffer, "twenty million, two hundred and nine");

    resetBuffer(buffer);
    wordinator(buffer, 321600209L);
    ASSERT_STR_EQ(buffer, "three hundred and twentyone million, six hundred thousand, two hundred and nine");

    resetBuffer(buffer);
    wordinator(buffer, 1321600209L);
    ASSERT_STR_EQ(buffer, "one billion, three hundred and twentyone million, six hundred thousand, two hundred and nine");

    resetBuffer(buffer);
    wordinator(buffer, 611321600209L);
    ASSERT_STR_EQ(buffer, "six hundred and eleven billion, three hundred and twentyone million, six hundred thousand, two hundred and nine");
}

int main()
{
    RUN_TEST(test_wordinator);
    return failed;
}
