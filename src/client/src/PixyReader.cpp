#include <boost/python.hpp>
#include <stdint.h>

#include "PixyReader.h"

using namespace boost::python;

PixyReader::PixyReader(void) : _initialized(false)
{
}

int PixyReader::Initialize(void)
{
  int rc;

  rc = pixy_init();
  if (rc != 0) 
    {
      printf("pixy_init() : ");
      pixy_error(rc);
      return rc;
    }

  uint16_t M, m, b;
  rc = pixy_get_firmware_version(&M, &m, &b);
  if (rc < 0) {
    printf("get_fw_vers(): ");
    pixy_error(rc);
    return rc;
  }
  printf("FW: %d %d %d\n", M, m, b);

  _initialized = true;

  return 0;
}

list PixyReader::GetBlocks(int maxBlocks)
{
  int numCopied = 0;
  list blockList;

  memset(_blocks, 0, 128 * sizeof(Block));
  numCopied = Read(maxBlocks, _blocks);
  if (numCopied < 0)
    return blockList;
  else
    {
      for (int i = 0; i < numCopied; ++i)
	blockList.append(boost::ref(_blocks[i]));
    }
  return blockList;
}

int PixyReader::Read(int maxBlocks, Block* blocks)
{
  int blocks_copied = 0;
  // Wait for new blocks to be available //
  while(!pixy_blocks_are_new()); 

  // Get blocks from Pixy //
  blocks_copied = pixy_get_blocks(maxBlocks, &blocks[0]);
  printf("blocks copied: %d\n", blocks_copied);
  if(blocks_copied < 0) {
    // Error: pixy_get_blocks //
    printf("pixy_get_blocks(): ");
    pixy_error(blocks_copied);
  }

  return blocks_copied;

}


BOOST_PYTHON_MODULE(PixyBlockReader)
{
  class_<Block>("Block")
    .def("toString", &Block::toString)
    .def_readonly("type", &Block::type)
    .def_readonly("signature", &Block::signature)
    .def_readonly("x", &Block::x)
    .def_readonly("y", &Block::y)
    .def_readonly("width", &Block::width)
    .def_readonly("height", &Block::height)
    .def_readonly("angle", &Block::angle)
     ;
  
  class_<PixyReader>("PixyReader")
    .def("Initialize", &PixyReader::Initialize)
    .def("GetBlocks", &PixyReader::GetBlocks)
    ;
}
