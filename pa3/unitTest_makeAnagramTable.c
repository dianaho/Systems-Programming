#include "test.h"
#include "pa3.h"
#include <strings.h>
#include <stdio.h>

test_makeAnagramTable() {
  struct anagramInfo info;
  unsigned long errors;

  errors = makeAnagramTable("four_anagrams.txt", &info);

  TEST(errors == 0);
  TEST(info.numOfAnagrams == 4);
  TEST(strcmp(info.anagramPtr[0].word, "post") == 0);
  TEST(strcmp(info.anagramPtr[1].word, "spot") == 0);
  TEST(strcmp(info.anagramPtr[2].word, "stop") == 0);
  TEST(strcmp(info.anagramPtr[3].word, "tops") == 0);

  TEST(strcmp(info.anagramPtr[0].sorted, "opst") == 0);
  TEST(strcmp(info.anagramPtr[1].sorted, "opst") == 0);
  TEST(strcmp(info.anagramPtr[2].sorted, "opst") == 0);
  TEST(strcmp(info.anagramPtr[3].sorted, "opst") == 0);

  errors = makeAnagramTable("invalid_filename.txt", &info);
  TEST(errors != 0);
}

int main(int argc, char *argv[]) {
  (void) fprintf(stderr, "Starting test_makeAnagramTable\n");

  test_makeAnagramTable();

  (void) fprintf(stderr, "Done.\n");

  return 0;
}
