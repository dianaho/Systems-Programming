#include "test.h"
#include "pa3.h"
#include <strings.h>
#include <stdio.h>

test_findAnagrams() {
  struct anagramInfo info;
  makeAnagramTable("four_anagrams.txt", &info);

  struct anagram anagram = {"STOP", "opst"};
  struct anagramMatches am;
  struct anagram *iter;
  int anagramsFound;

  am.word = anagram;
  am.first = NULL;
  am.last = NULL;
  anagramsFound = findAnagrams(&info, &am);

  TEST(anagramsFound == 4);
  TEST(am.first != NULL);
  TEST(am.last != NULL);

  iter = am.first;

  TEST(strcmp(iter->word, "post") == 0);
  ++iter;
  TEST(strcmp(iter->word, "spot") == 0);
  ++iter;
  TEST(strcmp(iter->word, "stop") == 0);
  ++iter;
  TEST(strcmp(iter->word, "tops") == 0);
}

int main(int argc, char *argv[]) {
  (void) fprintf(stderr, "Starting test_findAnagrams\n");

  test_findAnagrams();

  (void) fprintf(stderr, "Done.\n");

  return 0;
}
