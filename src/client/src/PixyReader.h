#include <stdio.h>
#include "pixy.h"

using namespace boost::python;

class PixyReader
{
public:
  PixyReader(void);
  int Initialize(void);
  list GetBlocks(int maxBlocks);

 private:
  bool _initialized;
  Block _blocks[128];
  
  int Read(int maxBlocks, Block* blocks);

};

