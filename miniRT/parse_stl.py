# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parse_stl.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/07 20:39:23 by pablo             #+#    #+#              #
#    Updated: 2021/02/16 17:15:17 by ptorres          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

  
import sys
import struct

class STLVec3:
    def __init__(self, x_coord, y_coord, z_coord):
        self.x = x_coord
        self.y = y_coord
        self.z = z_coord

class STLTriangle:
    def __init__(self, normal, v0, v1, v2, attributes):
        self.normal = normal
        self.v0 = v0
        self.v1 = v1
        self.v2 = v2
        self.attributes = attributes

class STLData:
    def __init__(self, header, tris):
        self.header = header
        self.tris = tris

def readFloat(f):
    float_bytes = f.read(4)
    return struct.unpack('f', float_bytes)[0]

def readVec3(f):
    x = readFloat(f)
    y = readFloat(f)
    z = readFloat(f)

    return STLVec3(x, y, z)
    
def readUnsignedInt(f):
    uint_bytes = f.read(4)
    return struct.unpack('I', uint_bytes)[0]

def readUINT16(f):
    uint16_bytes = f.read(2)
    return struct.unpack('H', uint16_bytes)[0]

def readTriangle(f):
    norm = readVec3(f)
    v0 = readVec3(f)
    v1 = readVec3(f)
    v2 = readVec3(f)
    attributes = readUINT16(f)

    return STLTriangle(norm, v0, v1, v2, attributes)

def printVec3(v,f):
    print '(', v.x, ', ', v.y, ', ', v.z, ')'

def parseSTL(file_name):
    f = open(file_name, "rb")

    header = f.read(80)

    print "STL HEADER = ", header

    num_tris = readUnsignedInt(f)

    tris = []

    for i in range(num_tris):
        tris.append(readTriangle(f))

    stlData = STLData(header, tris)

    return stlData

stlData = parseSTL(sys.argv[1])
f=open("kk.rt","w")

for triangle in stlData.tris:
    f.write("tr ")
    a = " "+str(triangle.v0.x) + ","+str(triangle.v0.y)+","+str(triangle.v0.z)
    f.write(a)
    a = " "+str(triangle.v1.x) + ","+str(triangle.v1.y)+","+str(triangle.v1.z)
    f.write(a)
    a = " "+str(triangle.v2.x) + ","+str(triangle.v2.y)+","+str(triangle.v2.z)
    f.write(a)
    f.write(' 40,20,100 1 1')
    f.write('\n')

    
   
   

