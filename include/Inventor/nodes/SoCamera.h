/**************************************************************************\
 * 
 *  Copyright (C) 1998-1999 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 22114160 Fax: +47 67172912
 *
\**************************************************************************/

#ifndef __SOCAMERA_H__
#define __SOCAMERA_H__

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoNode.h>
#include <Inventor/SbViewportRegion.h>
#include <Inventor/SbViewVolume.h>
#include <Inventor/fields/SoSFRotation.h>
#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/fields/SoSFVec3f.h>
#include <Inventor/fields/SoSFFloat.h>

#include <Inventor/SbVec3f.h>
#include <Inventor/SbBox3f.h>

#if defined(COIN_EXCLUDE_SOCAMERA)
#error Configuration settings disrespected -- do not include this file!
#endif // COIN_EXCLUDE_SOCAMERA

#define SO_ASPECT_SQUARE        1.0f
#define SO_ASPECT_VIDEO         (4.0f/3.0f)
#define SO_ASPECT_35mm_ACADEMY  1.371
#define SO_ASPECT_16mm          1.369
#define SO_ASPECT_35mm_FULL     1.33333
#define SO_ASPECT_70mm          2.287
#define SO_ASPECT_CINEMASCOPE   2.35
#define SO_ASPECT_HDTV          (16.0f/9.0f)
#define SO_ASPECT_PANAVISION    2.361
#define SO_ASPECT_35mm          (3.0f/2.0f)
#define SO_ASPECT_VISTAVISION   2.301

class SoPath;

// *************************************************************************

class SoCamera : public SoNode {
  typedef SoNode inherited;

  SO_NODE_ABSTRACT_HEADER(SoCamera);

public:
  static void initClass(void);

  enum ViewportMapping {
    CROP_VIEWPORT_FILL_FRAME,
    CROP_VIEWPORT_LINE_FRAME,
    CROP_VIEWPORT_NO_FRAME,
    ADJUST_CAMERA,
    LEAVE_ALONE
  };

  SoSFEnum viewportMapping;
  SoSFVec3f position;
  SoSFRotation orientation; 
  SoSFFloat aspectRatio;
  SoSFFloat nearDistance;
  SoSFFloat farDistance;
  SoSFFloat focalDistance;

  void pointAt(const SbVec3f & targetPoint);
  virtual void scaleHeight(float scaleFactor) = 0;
  virtual SbViewVolume getViewVolume(float useAspectRatio = 0.0f) const = 0;
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION)
  void viewAll(SoNode * const sceneRoot, 
	       const SbViewportRegion & vpRegion, 
	       const float slack = 1.0f);
  void viewAll(SoPath * const path, 
	       const SbViewportRegion & vpRegion, 
	       const float slack = 1.0f);
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION
  SbViewportRegion getViewportBounds(const SbViewportRegion & region) const;

#if !defined(COIN_EXCLUDE_SOACTION)
  virtual void doAction(SoAction * action);
#endif // !COIN_EXCLUDE_SOACTION
#if !defined(COIN_EXCLUDE_SOCALLBACKACTION)
  virtual void callback(SoCallbackAction * action);
#endif // !COIN_EXCLUDE_SOCALLBACKACTION
#if !defined(COIN_EXCLUDE_SOGLRENDERACTION)
  virtual void GLRender(SoGLRenderAction * action);
#endif // !COIN_EXCLUDE_SOGLRENDERACTION
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION)
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION
#if !defined(COIN_EXCLUDE_SOHANDLEEVENTACTION)
  virtual void handleEvent(SoHandleEventAction * action);
#endif // !COIN_EXCLUDE_SOHANDLEEVENTACTION
#if !defined(COIN_EXCLUDE_SORAYPICKACTION)
  virtual void rayPick(SoRayPickAction * action);
#endif // !COIN_EXCLUDE_SORAYPICKACTION
#if !defined(COIN_EXCLUDE_SOGETPRIMITIVECOUNTACTION)
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);
#endif // !COIN_EXCLUDE_SOGETPRIMITIVECOUNTACTION

protected:
  SoCamera(void);
  virtual ~SoCamera();

  virtual void viewBoundingBox(const SbBox3f & box,
			       float aspect, float slack) = 0;
  virtual void jitter(int numPasses, int curPass,
		      const SbViewportRegion & vpReg,
		      SbVec3f & jitterAmount) const;
  
  
};

#endif // !__SOCAMERA_H__
