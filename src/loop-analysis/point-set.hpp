/* Copyright (c) 2019, NVIDIA CORPORATION. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of NVIDIA CORPORATION nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <cassert>

#define POINT_SET_GENERIC_SLOW 1
#define POINT_SET_GENERIC_FAST 2
#define POINT_SET_4D           3
#define POINT_SET_AAHR         4
#define POINT_SET_AAHR_SET     5
#define POINT_SET_ISL          6

#define POINT_SET_IMPL POINT_SET_ISL

#if POINT_SET_IMPL == POINT_SET_ISL
#include "point-set-isl.hpp"
typedef ISLPointSet PointSet;

#elif POINT_SET_IMPL == POINT_SET_AAHR_SET
#include "point-set-aahr-set.hpp"
typedef AAHRSet PointSet;

#elif POINT_SET_IMPL == POINT_SET_AAHR
#include "point-set-aahr.hpp"
typedef AxisAlignedHyperRectangle PointSet;

#elif POINT_SET_IMPL == POINT_SET_GENERIC_SLOW
#error fix API error with PointSetGenericSlow
#include "point-set-generic-slow.hpp"
typedef PointSetGenericSlow PointSet;

#elif POINT_SET_IMPL == POINT_SET_4D
#error fix API error with PointSet4D
#include "point-set-4d.hpp"

#elif POINT_SET_IMPL == POINT_SET_GENERIC_FAST
#error fix API error with PointSetGenericFast
#include "point-set-generic-fast.hpp"

#else
#error illegal point set implementation
#endif
