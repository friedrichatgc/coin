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

#ifndef __SOTEXT2_H__
#define __SOTEXT2_H__

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoShape.h>
#include <Inventor/fields/SoMFString.h>
#include <Inventor/fields/SoSFFloat.h>
#include <Inventor/fields/SoSFEnum.h>

#if defined(COIN_EXCLUDE_SOTEXT2)
#error Configuration settings disrespected -- do not include this file!
#endif // COIN_EXCLUDE_SOTEXT2

// *************************************************************************

class SoText2 : public SoShape {
  typedef SoShape inherited;

  SO_NODE_HEADER(SoText2);

public:
  static void initClass(void);
  SoText2(void);

  enum Justification {
    LEFT = 1,
    RIGHT,
    CENTER,
  };
  
  SoMFString string;
  SoSFFloat spacing;
  SoSFEnum justification;

#if !defined(COIN_EXCLUDE_SOGLRENDERACTION)
  virtual void GLRender(SoGLRenderAction * action);
#endif // !COIN_EXCLUDE_SOGLRENDERACTION
#if !defined(COIN_EXCLUDE_SORAYPICKACTION)
  virtual void rayPick(SoRayPickAction * action);
#endif // !COIN_EXCLUDE_SORAYPICKACTION
#if !defined(COIN_EXCLUDE_SOGETPRIMITIVECOUNTACTION)
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);
#endif // !COIN_EXCLUDE_SOGETPRIMITIVECOUNTACTION

protected:
  virtual ~SoText2();

#if !defined(COIN_EXCLUDE_SOACTION)
  virtual void generatePrimitives(SoAction * action);
#endif // !COIN_EXCLUDE_SOACTION
#if !defined(COIN_EXCLUDE_SOGETBOUNDINGBOXACTION)
  virtual void computeBBox(SoAction * action, SbBox3f & box, SbVec3f & center);
#endif // !COIN_EXCLUDE_SOGETBOUNDINGBOXACTION
};

#endif // !__SOTEXT2_H__
