#include <gtest/gtest.h>
#include <sequences/sequence.h>

using namespace sequence;
using namespace std;

TEST(SequencesTests, GetNElemTest) {
    // Arrange
    ArifProgression s(1,1,1);
    ArifProgression s2(3, 3, 5);

    // Assert
    EXPECT_EQ(s.get_n_elem(3), 3);
    EXPECT_EQ(s2.get_n_elem(4), 12);

}
TEST(SequencesTests, GetNElemTest2) {
    // Arrange
    GeomProgression s(1, 5, 4);
    GeomProgression s2(3, 3, 5);

    // Assert
    EXPECT_EQ(s.get_n_elem(3), 5);
    EXPECT_EQ(s2.get_n_elem(3), 27);
}

TEST(SequencesTests, GetSum) {
    // Arrange
    SequencePtr pr = make_shared<ArifProgression>(3, 0, 5);
    SequencePtr pr2 = make_shared<ArifProgression>(4, 1, 1);
    // Assert
    EXPECT_EQ(pr->get_sum(4), 18);
    EXPECT_EQ(pr2->get_sum(3), 15);
}

TEST(SequencesTests, GetSum2) {
    // Arrange
    SequencePtr pr = make_shared<GeomProgression>(1, 3, 5);
    SequencePtr pr2 = make_shared<GeomProgression>(4, 1, 1);
    // Assert
    EXPECT_EQ(pr->get_sum(4), 12);
    EXPECT_EQ(pr2->get_sum(3), 21);
}

TEST(SequencesTests, EqualsCheck) {
    // Arrange
    SequencePtr pr = make_shared<ArifProgression>(1, 1, 5);
    SequencePtr pr2 = make_shared<GeomProgression>(1, 1, 5);
    // Assert
    EXPECT_EQ( pr2->equals(pr), false);
}

TEST(SequencesTests, EqualsCheck2) {
    // Arrange
    SequencePtr pr = make_shared<ArifProgression>(1, 1, 5);
    SequencePtr pr2 = make_shared<ArifProgression>(1, 1, 5);
    // Assert
    EXPECT_EQ(pr2->equals(pr), true);
}
TEST(SequencesTests, EqualsCheck3) {
    // Arrange
    SequencePtr pr = make_shared<ArifProgression>(1, 2, 5);
    SequencePtr pr2 = make_shared<ArifProgression>(1, 1, 5);
    // Assert
    EXPECT_EQ(pr2->equals(pr), false);
}



TEST(SequencesTests, ErrorTest) {
    EXPECT_ANY_THROW(make_shared<GeomProgression>(0, 1, 3));
}