Code for emd_hat
----------------
Ofir Pele\
Contact: ofirpele@gmail.com\
Version: 4, July 2023

This directory contains the source code for computing emd_hat or Rubner's emd efficiently. 

Please cite these papers if you use this code:\

 A Linear Time Histogram Metric for Improved SIFT Matching\
 Ofir Pele, Michael Werman\
 ECCV 2008
```latex
@INPROCEEDINGS{Pele-eccv2008,
author = {Ofir Pele and Michael Werman},
title = {A Linear Time Histogram Metric for Improved SIFT Matching},
booktitle = {ECCV},
year = {2008}
}
```

Fast and Robust Earth Mover's Distances\
Ofir Pele, Michael Werman\
ICCV 2009
```latex
@INPROCEEDINGS{Pele-iccv2009,
author = {Ofir Pele and Michael Werman},
title = {Fast and Robust Earth Mover's Distances},
booktitle = {ICCV},
year = {2009}
}
```

New lemon version
-----------------
lemon_thresholded_emd.hpp is a very efficient FastEMD C++ implementation based on the lemon
library which can be downloaded from here:\
https://lemon.cs.elte.hu/trac/lemon/wiki/Downloads\
There is no other language option for this option currently.
Note that the old versions are significantly slower to compute.

Python wrapper
--------------
A python wrapper was published by William Mayner: https://github.com/wmayner/pyemd

It does not use the lemon version. 

Old easy startup
----------------
Within Matlab:

```Matlab
demo_FastEMD1 % 1d histograms
demo_FastEMD2 % 3d histograms
demo_FastEMD3 % 2d histograms
demo_FastEMD4/demo_FastEMD4 %5d sparse histograms of different size
demo_FastEMD_non_symmetric
demo_FastEMD_non_equal_size_histograms  
```

Old compiling (the folder contains compiled binaries, thus you might not have to compile)
-------------------------------------------------------------------------------------
Within Matlab:

```Matlab
compile_FastEMD
```

In a linux shell:

```bash
make
```

Old usage within Matlab
------------------- 
Type "help emd_hat_gd_metric_mex" or "emd_hat_mex" in Matlab.

Old usage within C++
----------------
See "emd_hat_gd_metric.hxx" and "emd_hat.hxx".\
Note that Matlab demo scripts are good examples for emd usage.

Old usage within Java
-----------------
See "java/emd_hat.java" and "java/javadoc/index.html". Note that Matlab demo scripts are good examples for emd usage.

Tips
----
* The speed increases with smaller thresholds. In my experience the performance usually increases with
the threshold until a maximum and then it starts to decrease.
* It seems that setting alpha in emd_hat to 1 which is equivalent to setting extra_mass_penalty to
the maximum possible ground distance gives best results. This is the default in all functions.

Computing Rubner's EMD
----------------------
You'll need to set extra_mass_penalty to 0 and to divide the result by the minimum of the sums of
the histograms. I do not recommend to do it as the accuracy usually decreases.
Also, the resulting distance is not guaranteed to be a metric.
