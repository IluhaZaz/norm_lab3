#include <gtest/gtest.h>
#include <sequences/sequence.h>
#include <stdexcept>
#include <iostream>
using namespace sequence;
using namespace std;
TEST(SequencesListTests, AddAndOperatorCheck) {
    
    // Arrange
    SequenceList s;
    SequencePtr pr = make_shared<ArifProgression>(1, 2, 5);
    SequencePtr pr2 = make_shared<ArifProgression>(2, 1, 5);
    // Act
    s.add_progression(pr);
    s.add_progression(pr2);
    // Assert
    EXPECT_EQ(s[1], pr2);
}

TEST(SequencesListTests, InsertCheck) {
    // Arrange
    SequenceList s;
    SequencePtr pr = make_shared<GeomProgression>(1, 2, 5);
    SequencePtr pr2 = make_shared<ArifProgression>(2, 1, 5);    
    SequencePtr pr3 = make_shared<GeomProgression>(2, 1, 5);
    // Act
    s.add_progression(pr);
    s.add_progression(pr2);
    s.insert(0, pr3);
    // Assert
    EXPECT_EQ(s[0], pr3);
    EXPECT_EQ(s[1], pr);
    EXPECT_EQ(s[2], pr2);
}

TEST(SequencesListTests,RemoveCheck) {
    // Arrange
    SequenceList s;
    SequencePtr pr = make_shared<GeomProgression>(1, 2, 5);
    SequencePtr pr2 = make_shared<ArifProgression>(2, 1, 5);
    SequencePtr pr3 = make_shared<GeomProgression>(2, 1, 5);
    // Act
    s.add_progression(pr);
    s.add_progression(pr2);
    s.add_progression(pr3);
    s.remove(1);
    // Assert
    EXPECT_EQ(s[0], pr);
    EXPECT_EQ(s[1], pr3);
}

TEST(SequencesListTests, DeepCopyCheck) {
    // Arrange
    SequenceList s;
    SequencePtr pr = make_shared<GeomProgression>(1, 2, 5);
    SequencePtr pr2 = make_shared<ArifProgression>(2, 1, 5);
    s.add_progression(pr);
    s.add_progression(pr2);
    SequenceList s2(s);
    EXPECT_FALSE(s[0].get() == s2[0].get());
    EXPECT_EQ(s[0]->equals(s2[0]), true);

}

TEST(SequencesListTests, OverwriteCheck) {
    // Arrange
    SequenceList s;
    SequencePtr pr = make_shared<GeomProgression>(1, 2, 5);
    SequencePtr pr2 = make_shared<ArifProgression>(2, 1, 5);
    s.add_progression(pr);
    s.add_progression(pr2);
    s.overwrite(0, pr2);
    EXPECT_EQ(s[1]->equals(pr2), true);
    EXPECT_EQ(s[0]->equals(pr2), true);

}



