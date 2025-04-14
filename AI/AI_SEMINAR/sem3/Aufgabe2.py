import numpy as np #represent map as a matrice
import matplotlib.pyplot as plt

def plot_map(m,path_dfs=None,path_astar=None):
    nrows,ncols=m.shape  #nr rows+nr col from matrice
    fig,ax=plt.subplots() #create a figure and an ax system

