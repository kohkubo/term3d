#!/usr/bin/python3.6

'''
This program is a modified version of "minirt_mesh_converter" by matboivin, which can be found at the link below.
This program is licensed under a Creative Commons Attribution-NonCommercial 4.0 International License.

https://github.com/matboivin/minirt_mesh_converter
'''

import os
import sys


def get_triangle(line, d):
    i = line.split(' ')
    triangle = []
    i1 = i[1].split('/')[0]
    i2 = i[2].split('/')[0]
    i3 = i[3].split('/')[0]
    vertex1 = ','.join((d[i1]['x'], d[i1]['y'], d[i1]['z']))
    vertex2 = ','.join((d[i2]['x'], d[i2]['y'], d[i2]['z']))
    vertex3 = ','.join((d[i3]['x'], d[i3]['y'], d[i3]['z']))
    triangle.append(' '.join((vertex1, vertex2, vertex3)) + ' ')
    # if a face line has more than 5 params then its a quad not a tris therefor
    # we transform the quad into a tris.. still have to implement other polyons.
    # 4-------3
    # |      /|
    # |    /  |
    # |  /    |
    # |/      |
    # 1-------2
    # 1 2 3 4 into 1 2 3 and 1 3 4
    if len(i) >= 5:
        i4 = i[4].split('/')[0]
        vertex4 = ','.join((d[i4]['x'], d[i4]['y'], d[i4]['z']))
        triangle.append('\n')
        triangle.append(' '.join((vertex1, vertex3, vertex4)) + ' ')
    return triangle


def parse_polygons(filename, obj_file, d):
    with open(filename, 'w') as out:
        for line in obj_file:
            if line[:2] == 'f ':
                triangle = get_triangle(line, d)
                for t in triangle:
                    out.write(t)
                out.write("\n")


def parse_vertices(obj_file, d):
    count = 1
    for line in obj_file:
        if line[:2] == 'v ':
            coord = line.split(' ')
            d[str(count)] = {'x': coord[1], 'y': coord[2], 'z': coord[3][:-1]}
            count += 1
    return d


def convert_to_tri(filepath):
    d = dict()
    outname = os.path.dirname(filepath) + "/" + os.path.splitext(os.path.basename(filepath))[0] + ".tri"
    with open(filepath, 'r') as f:
        obj_file = f.readlines()
    d = parse_vertices(obj_file, d)
    parse_polygons(outname, obj_file, d)
    print('created .tri file in ' + outname)


if len(sys.argv) != 2:
    print('Usage: python term3d_converter.py <file.obj>')
else:
    filepath = os.path.join(sys.argv[1])
    convert_to_tri(filepath)
