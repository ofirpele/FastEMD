#ifndef _EMD_HAT_SIGNATURE_INTERFACE_HXX
#define _EMD_HAT_SIGNATURE_INTERFACE_HXX

#include "EMD_DEFS.hpp"

//=============================================================================
// This interface is similar to Rubner's interface. See:
// http://www.cs.duke.edu/~tomasi/software/emd.htm
// With the following changes;
// 1. Weights of signature should be of type NUM_T (see EMD_DEFS.hxx)
// 2. Return value of the distance function (func) should be of type NUM_T (see EMD_DEFS.hxx)
// 3. Return value of the emd_hat_signature_interface function is NUM_T (see EMD_DEFS.hxx)
// 4. The function does not return a flow (I may add this in future, if needed)
// 5. The function also gets the penalty for extra mass - if you want metric property
//    should be at least half the diameter of the space (maximum possible distance
//    between any two points). In Rubner's code this is implicitly 0. 
// 6. The result is not normalized with the flow.
//
// To get the same results as Rubner's code you should set extra_mass_penalty to 0,
// and divide by the minimum of the sum of the two signature's weights. However, I
// suggest not to do this as you lose the metric property and more importantly, in my
// experience the performance is better with emd_hat. for more on the difference
// between emd and emd_hat, see the paper:
//  A Linear Time Histogram Metric for Improved SIFT Matching
//  Ofir Pele, Michael Werman
//  ECCV 2008
//
// To get shorter running time, set the ground distance function (func) to
// be a thresholded distance. For example: min( L2, T ). Where T is some threshold.
// Note that the running time is shorter with smaller T values. Note also that
// thresholding the distance will probably increase accuracy. Finally, a thresholded
// metric is also a metric. See paper:
//  Fast and Robust Earth Mover's Distances
//	Ofir Pele, Michael Werman
//  ICCV 2009
//
// If you use this code, please cite the papers.
//=============================================================================

/*****************************************************************************/
/* feature_tt SHOULD BE MODIFIED BY THE USER TO REFLECT THE FEATURE TYPE      */
typedef NUM_T feature_tt;
/*****************************************************************************/

typedef struct
{
  int n;                /* Number of features in the signature */
  feature_tt* Features; /* Pointer to the features vector */
  NUM_T* Weights;         /* Pointer to the weights of the features (Changed from Rubner's)*/
} signature_tt;

/// Similar to Rubner's emd interface.
/// extra_mass_penalty - it's alpha*maxD_ij in my ECCV paper. If you want metric property
///                      should be at least half the diameter of the space (maximum possible distance
///                      between any two points). In Rubner's code this is implicitly 0.
///                      Default value is -1 which means 1*max_distance_between_bins_of_singnatures
NUM_T emd_hat_signature_interface(signature_tt* Signature1, signature_tt* Signature2,
                                  NUM_T (*func)(feature_tt*, feature_tt*),
                                  NUM_T extra_mass_penalty);

#endif

// Copyright (2009-2010), The Hebrew University of Jerusalem.
// All Rights Reserved.

// Created by Ofir Pele
// The Hebrew University of Jerusalem

// This software is being made available for individual non-profit research use only.
// Any commercial use of this software requires a license from the Hebrew University
// of Jerusalem.

// For further details on obtaining a commercial license, contact Ofir Pele
// (ofirpele@cs.huji.ac.il) or Yissum, the technology transfer company of the
// Hebrew University of Jerusalem.

// THE HEBREW UNIVERSITY OF JERUSALEM MAKES NO REPRESENTATIONS OR WARRANTIES OF
// ANY KIND CONCERNING THIS SOFTWARE.

// IN NO EVENT SHALL THE HEBREW UNIVERSITY OF JERUSALEM BE LIABLE TO ANY PARTY FOR
// DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST
// PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF
// THE THE HEBREW UNIVERSITY OF JERUSALEM HAS BEEN ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE. THE HEBREW UNIVERSITY OF JERUSALEM SPECIFICALLY DISCLAIMS ANY
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE SOFTWARE PROVIDED
// HEREUNDER IS ON AN "AS IS" BASIS, AND THE HEBREW UNIVERSITY OF JERUSALEM HAS NO
// OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR
// MODIFICATIONS.
