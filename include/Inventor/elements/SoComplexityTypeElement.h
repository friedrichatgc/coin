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

#ifndef __SOCOMPLEXITYTYPEELEMENT_H__
#define __SOCOMPLEXITYTYPEELEMENT_H__

#include <Inventor/confdep.h>
#if defined(COIN_EXCLUDE_SOCOMPLEXITYTYPEELEMENT)
#error "Configuration settings disable this class!"
#endif // COIN_EXCLUDE_SOCOMPLEXITYTYPEELEMENT

#include <Inventor/elements/SoInt32Element.h>

class SoComplexityTypeElement : public SoInt32Element {
  typedef SoInt32Element inherited;

//$ BEGIN TEMPLATE ElementHeader(SoComplexityTypeElement)
public:
  static SoType classTypeId;
  static SoType getClassTypeId(void);
  static void * createInstance(void);
public:
  static int getClassStackIndex(void);
  virtual ~SoComplexityTypeElement(void);

  static void initClass(void);

protected:
  SoComplexityTypeElement(void);
  static int classStackIndex;
//$ END TEMPLATE ElementHeader

public:
// constants:
  enum Type {
    OBJECT_SPACE,
    SCREEN_SPACE,
    BOUNDING_BOX
  };

  virtual void init(SoState * state);
  
  static  void set(SoState * const state, SoNode * const node,
		   const Type type);
  static  void set(SoState * const state, const Type type);
  static  Type get(SoState * const state);
  static  Type getDefault();

};

#endif // !__SOCOMPLEXITYTYPEELEMENT_H__
