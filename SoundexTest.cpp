#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Soundex.hpp"

class SoundexEncoding : public testing::Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{ 
    ASSERT_EQ(soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, PadsWithZeroToEnsureThreeDigits)
{
    ASSERT_EQ(soundex.encode("I"), "I000");
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
    ASSERT_EQ(soundex.encode("Ac"), "A200");
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics)
{
    ASSERT_EQ(soundex.encode("A#"), "A000");
}

TEST_F(SoundexEncoding, ReplacesMultipleConstantsWithDigits)
{
    ASSERT_EQ(soundex.encode("Acdl"), "A234");
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters)
{
    ASSERT_EQ(soundex.encode("Dcdlb").length(), 4U);
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters)
{
    ASSERT_EQ(soundex.encode("BaAeEiIoOuUhHyYcdl"), "B234");
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings)
{
    ASSERT_EQ(soundex.encodedDigit('b'), soundex.encodedDigit('f'));
    ASSERT_EQ(soundex.encodedDigit('c'), soundex.encodedDigit('g'));
    ASSERT_EQ(soundex.encodedDigit('d'), soundex.encodedDigit('t'));

    ASSERT_EQ(soundex.encode("Abfcgdt"), "A123");
}

TEST_F(SoundexEncoding, UppercaseFirstLetter)
{
    ASSERT_THAT(soundex.encode("abcd"), testing::StartsWith("A"));
}

TEST_F(SoundexEncoding, IngoresCaseWhenEncodingConsonants)
{
    ASSERT_EQ(soundex.encode("BCDL"), soundex.encode("Bcdl"));
}
