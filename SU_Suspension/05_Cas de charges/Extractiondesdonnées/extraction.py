# -*- coding: utf-8 -*-
"""
Created  2021

@author: RCT
"""
"""
L'objectif de ce code simple est d'extraire des tableaux MECAmaster, des tableaux copie-collage dans un excel.
Pour avoir une utilisation optimale, je vous suggère de ne garde que les lignes nécessaire même si cela n'aura pas d'impact sur la réalisation du code.
En revanche, il se peux que si la dernière ligne de votre fichier .txt n'est pas une ligne vide, cela pourrait bugger.

"""
import numpy as np

nomdufichier="Max Speed"+".txt" 

lu=open(nomdufichier,'r')
copie=open("AA_extrait"+nomdufichier,'w')

l=lu.readline() #lecture de la ligne
#print(l)
#print(l[2:4]+'\t'+l[5:23]+'\t'+l[23:41]+'\t'+l[41:50]+'\t'+l[52:60]+'\t'+l[60:70]+'\n')

while l!="":
    copie.write(l[2:4]+'\t'+l[5:23]+'\t'+l[23:41]+'\t'+l[41:50]+'\t'+l[52:60]+'\t'+l[60:70]+'\n')
    l=lu.readline()

lu.close()
copie.close()