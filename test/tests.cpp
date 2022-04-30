// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(task1, test1) {
    MarkovGenerator gen = MarkovGenerator("input.txt", NPREF);
    int result = gen.getPrefixSize();
    EXPECT_EQ(2, result);
}

TEST(task2, test2) {
  MarkovGenerator gen = MarkovGenerator("input.txt", NPREF);
  std::deque<std::string> newPrefixes {"никак", "не"};
  std::string newSuffix = gen.getSuffix(newPrefixes);
  EXPECT_EQ("успевали", newSuffix);
}

TEST(task3, test3) {
  MarkovGenerator gen = MarkovGenerator("input.txt", NPREF);
  std::deque<std::string> newPrefixes {"Тут", "соседи"};
  std::string newSuffix = gen.getSuffix(newPrefixes);
  EXPECT_EQ("беспокоить", newSuffix);
}

TEST(task4, test4) {
  MarkovGenerator gen = MarkovGenerator("input.txt", NPREF);
  std::deque<std::string> newPrefixes {"Царь", "скопца"};
  std::string newSuffix = gen.getSuffix(newPrefixes);
  EXPECT_TRUE(newSuffix == "благодарит" || newSuffix == "зауважал");
}

TEST(task5, test5) {
  MarkovGenerator gen = MarkovGenerator("input.txt", NPREF);
  std::deque<std::string> newPrefixes {"вот", "проходит"};
  std::string newSuffix = gen.getSuffix(newPrefixes);
  EXPECT_TRUE(newSuffix == "восемь" || newSuffix == "сорок");
}

TEST(task6, test6) {
  MarkovGenerator gen = MarkovGenerator("input.txt", NPREF);
  std::string text = gen.getText(MAXGEN);
  int count = 0;
  for (int i = 0; i < text.size(); i++) {
      if (text[i] == ' ') count++;
  }
  EXPECT_LE(count, MAXGEN + 1);
}
