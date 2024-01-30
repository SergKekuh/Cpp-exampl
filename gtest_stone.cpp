#include "stonewt.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(TestGroupName, increment_by_pds_left)
{
  // Arrange
  Stonewt mc(144.5);

  // Act
  double value = mc.show_pds_left();  

  // Assert
  ASSERT_EQ(value, 4.5); // строки сравнивают с _STREQ
}
TEST(TestGroupName, increment_by_pounds)
{
  // Arrange
  Stonewt mc(21.5);

  // Act
  double value = mc.show_pounds();

  // Assert
  ASSERT_EQ(value, 21.5); // строки сравнивают с _STREQ
}
//----------------------------------------------
TEST(TestGroupName, increment_by_2pds_left)
{
  // Arrange
  Stonewt mc(4, 144.5);

  // Act
  double value = mc.show_pds_left();  

  // Assert
  ASSERT_EQ(value, 144.5); // строки сравнивают с _STREQ
}
TEST(TestGroupName, increment_by_2pounds)
{
  // Arrange
  Stonewt mc(4, 21.5);

  // Act
  double value = mc.show_pounds();

  // Assert
  ASSERT_EQ(value, 77.5); // строки сравнивают с _STREQ
}
//--------------------------------------------
TEST(TestGroupName, increment_by_stone)
{
  // Arrange
  Stonewt mc(144.5);

  // Act
  int value = mc.show_stone();  

  // Assert
  ASSERT_EQ(value, 10); // строки сравнивают с _STREQ
}
TEST(TestGroupName, increment_by_2stone)
{
  // Arrange
  Stonewt mc(4, 21.5);

  // Act
  int value = mc.show_stone();

  // Assert
  ASSERT_EQ(value, 4); // строки сравнивают с _STREQ
}
//---------------------------------------------------
TEST(TestGroupName, increment_by_stone_1)
{
  // Arrange
  Stonewt mc;

  // Act
  int value = mc.show_stone();  

  // Assert
  ASSERT_EQ(value, 0); // строки сравнивают с _STREQ
}
TEST(TestGroupName, increment_by_pds_left_1)
{
  // Arrange
  Stonewt mc;

  // Act
  double value = mc.show_pds_left();

  // Assert
  ASSERT_EQ(value, 0); // строки сравнивают с _STREQ
}
TEST(TestGroupName, increment_by_pounds_1)
{
  // Arrange
  Stonewt mc;

  // Act
  double value = mc.show_pounds();

  // Assert
  ASSERT_EQ(value, 0); // строки сравнивают с _STREQ
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}
