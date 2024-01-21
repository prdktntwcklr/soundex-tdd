class Soundex {

};

#include "gtest/gtest.h"

TEST(SoundexTest, BasicAssertions)
{
    EXPECT_STRNE("hello", "world");

    EXPECT_EQ(7 * 6, 42);
}

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{ 
   Soundex soundex;
}
