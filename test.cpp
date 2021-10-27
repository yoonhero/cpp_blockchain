#include <iostream>
#include <openssl/sha.h>

using namespace std;

int main()
{
  char text[] = "Hello World";
  unsigned char digest[SHA256_DIGEST_LENGTH];
  char string[] = "Hello World";

  cout << string << endl;

  SHA256((unsigned char *)&string, strlen(string), (unsigned char *)&digest);

  char mdString[SHA256_DIGEST_LENGTH * 2 + 1];

  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    sprintf(&mdString[i * 2], "%02x", (unsigned int)digest[i]);

  printf("SHA256 digest: %s\n", mdString);

  return 0;
}
