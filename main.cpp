#include <iostream>
#include <vector>
#include <openssl/sha.h>
#include <ctime>
#include <string>

using namespace std;

class Block
{
private:
  int index;

public:
  string Hash, PrevHash;
  int TargetDifficulty;
  int Difficulty, Nonce;
  int Timestamp;

  void mine()
  {
    string target = string(TargetDifficulty, '0');
    Nonce = 1;
    string newHash;
    do
    {
      string str = PrevHash + to_string(Nonce) + to_string(Timestamp);
      int n = str.length();

      // declaring character array
      char string[n + 1];

      // copying the contents of the
      // string to char array
      strcpy(string, str.c_str());

      unsigned char digest[SHA256_DIGEST_LENGTH];

      SHA256((unsigned char *)&string, strlen(string), (unsigned char *)&digest);

      char mdString[SHA256_DIGEST_LENGTH * 2 + 1];

      for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(&mdString[i * 2], "%02x", (unsigned int)digest[i]);

      newHash = mdString;

      cout << Nonce << "th mining ... "
           << " target: " << target << " hash: " << newHash << endl;
      time_t t = time(0);
      Timestamp = t;
      if (newHash.substr(0, TargetDifficulty) == target)
      {
        Hash = newHash;
        cout << "Mine Finish..." << endl;
        break;
      }
      else
      {
        Nonce++;
      }
    } while (newHash.substr(0, TargetDifficulty) != target);
  }

  // constructor function - Generate Block
  Block(string aPrevHash, int aIndex, int aTargetDiff);
};

Block::Block(string aPrevHash, int aIndex, int aTargetDiff)
{
  PrevHash = aPrevHash;
  index = aIndex;
  TargetDifficulty = aTargetDiff;
  mine();
}

class Blockchain
{
public:
  string NewestHash;
  int Height;
  int CurrentDifficulty;

  void UpdateBlockchain(string aNewestHash, int aDifficulty)
  {
    Height++;
    NewestHash = aNewestHash;
    CurrentDifficulty = aDifficulty;
  }

  Blockchain();
};

Blockchain::Blockchain()
{
  Height = 0;
  NewestHash = "";
  CurrentDifficulty = 3;
}

int main()
{
  // Block blocks[10];
  Blockchain Blockchain;
  Block NewBlock(Blockchain.NewestHash, Blockchain.Height, Blockchain.CurrentDifficulty);

  Blockchain.UpdateBlockchain(NewBlock.Hash, NewBlock.Difficulty);
  // blocks[Blockchain.Height] = NewBlock;

  cout << "successful create block" << endl;

  return 0;
}

// string sha256(char string[])
// {
//   unsigned char digest[SHA256_DIGEST_LENGTH];

//   SHA256((unsigned char *)&string, strlen(string), (unsigned char *)&digest);

//   char mdString[SHA256_DIGEST_LENGTH * 2 + 1];

//   for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
//     sprintf(&mdString[i * 2], "%02x", (unsigned int)digest[i]);

//   return mdString;
// }