import matplotlib as mpl
import matplotlib.pyplot as heatplot
import pandas as pd
import sys
import os


for i in range(1,len(sys.argv)):
	filepath = os.path.realpath(".".join((sys.argv[i],"csv")))
	CPlane=pd.read_csv(filepath,names=list('xyz'))

	pivotdata=CPlane.pivot('y','x','z')
	heatplot.xlabel('X')
	heatplot.ylabel('Y')

	xval, yval= pivotdata.columns.values, pivotdata.index.values

	xt= [xval[0],xval[-1]]
	yt= [yval[0],yval[-1]]

	heatplot.xticks([0,len(xval)-1],xt) 
	heatplot.yticks([0,len(yval)-1],yt)
	heatplot.imshow(pivotdata.values)
	heatplot.gca().invert_yaxis()
	heatplot.savefig(".".join((sys.argv[i],"jpg")))
