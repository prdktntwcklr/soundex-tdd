#include "gtest/gtest.h"

#include "Soundex.hpp"

class SoundexEncoding : public testing::Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{ 
   EXPECT_EQ(soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, PadsWithZeroToEnsureThreeDigits)
{
    EXPECT_EQ(soundex.encode("I"), "I000");
}
