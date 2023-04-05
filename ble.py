'''import bpy'''
import numpy as np
import pandas as pd

cppdata = read_csv('graphen_cuted.csv')
cppdata.loc[1,'posx']

'''
for item in bpy.data.objects:
    bpy.data.objects.remove(item)
for item in bpy.data.meshes:
    bpy.data.meshes.remove(item)
for item in bpy.data.materials:
    bpy.data.materials.remove(item)

bpy.ops.mesh.primitive_cylinder_add(vertices=16, radius=5.0, depth=1.0, end_fill_type='NGON', calc_uvs=True, enter_editmode=False, align='WORLD', location=(0.0,0.0,0.0), rotation=(0.0,0.0,0.0), scale=(1.0, 1.0, 1.0))
'''