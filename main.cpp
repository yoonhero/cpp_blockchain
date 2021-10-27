#include <iostream>
#include <vector>

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
  }

  // constructor function - Generate Block
  Block(string aPrevHash, int aIndex, int aTargetDiff)
  {
    PrevHash = aPrevHash;
    index = aIndex;
    TargetDifficulty = aTargetDiff;
    mine();
  };
};

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

  Blockchain()
  {
    Height = 0;
    NewestHash = "";
    CurrentDifficulty = 3;
  };
};

int main()
{
  Block blocks[10] = {} Blockchain Blockchain;
  Block NewBlock(Blockchain.NewestHash, Blockchain.Height);

  Blockchain.updateBlockchain(NewBlock.Hash, NewBlock.Difficulty);
  blocks[Blockchain.Height] = NewBlock;

  cout << "successful create block" << endl;

  return 0;
}
