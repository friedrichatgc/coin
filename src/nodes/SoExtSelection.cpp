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

/*!
  \class SoExtSelection SoExtSelection.h Inventor/nodes/SoExtSelection.h
  \brief The SoExtSelection class ...
  \ingroup nodes

  FIXME: write class doc
*/


#include <Inventor/nodes/SoExtSelection.h>


/*!
  \enum SoExtSelection::LassoType
  FIXME: write documentation for enum
*/
/*!
  \var SoExtSelection::LassoType SoExtSelection::NOLASSO
  FIXME: write documentation for enum definition
*/
/*!
  \var SoExtSelection::LassoType SoExtSelection::LASSO
  FIXME: write documentation for enum definition
*/
/*!
  \var SoExtSelection::LassoType SoExtSelection::RECTANGLE
  FIXME: write documentation for enum definition
*/

/*!
  \enum SoExtSelection::LassoPolicy
  FIXME: write documentation for enum
*/
/*!
  \var SoExtSelection::LassoPolicy SoExtSelection::FULL_BBOX
  FIXME: write documentation for enum definition
*/
/*!
  \var SoExtSelection::LassoPolicy SoExtSelection::PART_BBOX
  FIXME: write documentation for enum definition
*/
/*!
  \var SoExtSelection::LassoPolicy SoExtSelection::FULL
  FIXME: write documentation for enum definition
*/
/*!
  \var SoExtSelection::LassoPolicy SoExtSelection::PART
  FIXME: write documentation for enum definition
*/


/*!
  \var SoSFEnum SoExtSelection::lassoType
  FIXME: write documentation for field
*/
/*!
  \var SoSFEnum SoExtSelection::lassoPolicy
  FIXME: write documentation for field
*/

// *************************************************************************

SO_NODE_SOURCE(SoExtSelection);

/*!
  Constructor.
*/
SoExtSelection::SoExtSelection()
{
  SO_NODE_CONSTRUCTOR(SoExtSelection);

  SO_NODE_ADD_FIELD(lassoType, (SoExtSelection::NOLASSO));
  SO_NODE_ADD_FIELD(lassoPolicy, (SoExtSelection::FULL_BBOX));

  SO_NODE_DEFINE_ENUM_VALUE(LassoType, NOLASSO);
  SO_NODE_DEFINE_ENUM_VALUE(LassoType, LASSO);
  SO_NODE_DEFINE_ENUM_VALUE(LassoType, RECTANGLE);
  SO_NODE_SET_SF_ENUM_TYPE(lassoType, LassoType);

  SO_NODE_DEFINE_ENUM_VALUE(LassoPolicy, FULL_BBOX);
  SO_NODE_DEFINE_ENUM_VALUE(LassoPolicy, PART_BBOX);
  SO_NODE_DEFINE_ENUM_VALUE(LassoPolicy, FULL);
  SO_NODE_DEFINE_ENUM_VALUE(LassoPolicy, PART);
  SO_NODE_SET_SF_ENUM_TYPE(lassoPolicy, LassoPolicy);
}

/*!
  Destructor.
*/
SoExtSelection::~SoExtSelection()
{
}

/*!
  Does initialization common for all objects of the
  SoExtSelection class. This includes setting up the
  type system, among other things.
*/
void
SoExtSelection::initClass(void)
{
  SO_NODE_INTERNAL_INIT_CLASS(SoExtSelection);
}


/*!
  FIXME: write doc
 */
void
SoExtSelection::useOverlay(SbBool /* flg */)
{
  assert(0 && "FIXME: not implemented");
}

/*!
  FIXME: write doc
 */
SbBool
SoExtSelection::isUsingOverlay(void)
{
  assert(0 && "FIXME: not implemented");
  return FALSE;
}

/*!
  FIXME: write doc
 */
SoSeparator *
SoExtSelection::getOverlaySceneGraph(void)
{
  assert(0 && "FIXME: not implemented");
  return NULL;
}

/*!
  FIXME: write doc
 */
void
SoExtSelection::setOverlayLassoColorIndex(int /* index */)
{
  assert(0 && "FIXME: not implemented");
}

/*!
  FIXME: write doc
 */
int
SoExtSelection::getOverlayLassoColorIndex(void)
{
  assert(0 && "FIXME: not implemented");
  return 0;
}

/*!
  FIXME: write doc
 */
void
SoExtSelection::setLassoColor(SbColor /* c */)
{
  assert(0 && "FIXME: not implemented");
}

/*!
  FIXME: write doc
 */
SbColor
SoExtSelection::getLassoColor(void)
{
  assert(0 && "FIXME: not implemented");
  static SbColor col;
  return col;
}

/*!
  FIXME: write doc
 */
void
SoExtSelection::setLassoWidth(float /* width */)
{
  assert(0 && "FIXME: not implemented");
}

/*!
  FIXME: write doc
 */
float
SoExtSelection::getLassoWidth(void)
{
  assert(0 && "FIXME: not implemented");
  return 0.0f;
}

/*!
  FIXME: write doc
 */
void
SoExtSelection::setOverlayLassoPattern(unsigned short /* pattern */)
{
  assert(0 && "FIXME: not implemented");
}

/*!
  FIXME: write doc
 */
unsigned short
SoExtSelection::getOverlayLassoPattern(void)
{
  assert(0 && "FIXME: not implemented");
  return 0;
}

/*!
  FIXME: write doc
 */
void
SoExtSelection::animateOverlayLasso(SbBool /* flg */)
{
  assert(0 && "FIXME: not implemented");
}

/*!
  FIXME: write doc
 */
SbBool
SoExtSelection::isOverlayLassoAnimated(void)
{
  assert(0 && "FIXME: not implemented");
  return FALSE;
}
