import PixyBlockReader

# class Block:
#     ''' 
#     bytes 0, 1 : sync 0xaa55 (normal) 0xaa56 (color)
#     bytes 2, 3 : checksum of bytes 4-13
#     bytes 4, 5 : signature
#     bytes 6, 7 : x center
#     bytes 8, 9 : y center
#     bytes 10, 11 : width
#     bytes 12, 13 : height
# '''
#     def __init__(self):
#         self.rawBytes = bytearray([0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00])

#     def addEm(self, arg1, arg2):
#         return (arg1 << 8) + arg2

#     def getSum(self):
#         return addEm(self.rawBytes[2], self.rawBytes[3])
    
#     def getSignature(self):
#         return addEm(self.rawBytes[4], self.rawBytes[5])
    
#     def getXCenter(self):
#         return addEm(self.rawBytes[6], self.rawBytes[7])
    
#     def getYCenter(self):
#         return addEm(self.rawBytes[8], self.rawBytes[9])
    
#     def getWidth(self):
#         return addEm(self.rawBytes[10], self.rawBytes[11])
    
#     def getHeight(self):
#         return addEm(self.rawBytes[12], self.rawBytes[13])

#     def printMe(self):
#         print("Sig: %d\txCenter: %d\tyCenter: %d\tWidth: %d\tHeight: %d\n" % (getSignature(), getXCenter(), getYCenter(), getWidth(), getHeight()))


reader = PixyBlockReader.PixyReader()

rc = reader.Initialize()
if rc < 0:
    print "init error %d\n" % rc

print 'detect blocks...\n'
frameIndex = 0

# blocks = []
MAX_BLOCKS = 128
# for i in range(MAX_BLOCKS):
#     blocks.append(Block())
    
while(True):
    print 'frame %d\n' % frameIndex
    newBlocks = reader.GetBlocks(MAX_BLOCKS)
    for i in range(len(newBlocks)):
        newBlocks[i].toString()
        print newBlocks[i].x
    frameIndex+=1

