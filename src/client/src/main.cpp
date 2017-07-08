#include "PixyReader.h"

#define MAX_BLOCKS 128

int main(int argc, char** argv)
{
  PixyReader _reader;
  Block _blocks[MAX_BLOCKS];
  char blockPrintBuf[128];
  int frameIndex, availableBlocks  = 0;
  
  if (_reader.Initialize() != 0)
    {
      printf("Main(): initialize returned %d\n");
      return -1;
    }

  printf("Detecting blocks...\n");
  while(1)
  {
    // Display received blocks //
    printf("frame %d:\n", frameIndex);
    availableBlocks = _reader.GetBlocks(MAX_BLOCKS, _blocks);
    for(int i = 0; i != availableBlocks; ++i) {
       _blocks[i].print(blockPrintBuf);
       printf("  %s\n", blockPrintBuf);
    }
    frameIndex++;
  }
}
		
