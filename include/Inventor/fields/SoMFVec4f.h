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

#ifndef __SOMFVEC4F_H__
#define __SOMFVEC4F_H__

#include <Inventor/fields/SoMField.h>
#include <Inventor/SbVec4f.h>

#if defined(COIN_EXCLUDE_SOMFVEC4F)
#error "Configuration settings not respected, should not include this file!"
#endif // COIN_EXCLUDE_SOMFVEC4F


class SoMFVec4f : public SoMField {
  typedef SoMField inherited;

//$ BEGIN TEMPLATE MField(SoMFVec4f, SbVec4f, const SbVec4f &)
private:
  static SoType classTypeId;

public:
  static void * createInstance(void);
  static SoType getClassTypeId(void);
  virtual SoType getTypeId(void) const;

  static void initClass(void);

  virtual void copyFrom(const SoField & field);
  const SoMFVec4f & operator = (const SoMFVec4f & field);
  virtual SbBool isSame(const SoField & field) const;
public:
  SoMFVec4f(void);
  virtual ~SoMFVec4f(void);
private:
  virtual SbBool read1Value(SoInput * in, int idx);
  virtual void write1Value(SoOutput * out, int idx) const;
public:
  /*! Returns the element at the \a idx position. */
  const SbVec4f & operator [] (const int idx) const
    { this->evaluate(); return this->values[idx]; }
  /*! Returns a pointer to an array of element starting at the \a start position. */
  const SbVec4f * getValues(const int start) const
    { this->evaluate(); return (const SbVec4f *)(this->values + start); }
  int find(const SbVec4f & value, SbBool addIfNotFound = FALSE);
  void setValues(const int start, const int num, const SbVec4f * values);
  void set1Value(const int idx, const SbVec4f & value);
  void setValue(const SbVec4f & value);
  /*! Make field contain a just the single value \a val. */
  const SbVec4f & operator = (const SbVec4f & val)
    { this->setValue(val); return val; }
  SbBool operator == (const SoMFVec4f & field) const;
  /*! Returns \a TRUE if this field is \e not equal to \a field. */
  SbBool operator != (const SoMFVec4f & field) const
    { return ! operator == (field); }
  /*! Returns a pointer to the array of values for editing. \e Must be matched
      with a call to finishEditing() upon completion. */
  SbVec4f * startEditing(void)
    { this->evaluate(); return this->values; }
  /*! Call this method to notify Coin that you're through editing the data. */
  void finishEditing(void)
    { this->valueChanged(); }

protected:
  virtual void deleteAllValues(void);
  virtual void copyValue(int to, int from);
  virtual int fieldSizeof(void) const;
  virtual void * valuesPtr(void);
  virtual void setValuesPtr(void * ptr);

  /*! Pointer to array of values. */
  SbVec4f * values;
//$ END TEMPLATE MField

public:
  void setValues(const int start, const int num, const float xyzw[][4]);
  void set1Value(const int idx,
		 const float x, const float y, const float z, const float w);
  void set1Value(const int idx, const float xyzw[4]);
  void setValue(const float x, const float y, const float z, const float w);
  void setValue(const float xyzw[4]);

private:
  virtual void convertTo(SoField * dest) const;
};

#endif // !__SOMFVEC4F_H__
