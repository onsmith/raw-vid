#pragma once

#include <cstdint>

#include <iostream>
using std::istream;
using std::ostream;


/*
** Abstract class representing a raw frame of video.
*/
class Frame {
public:
  /*
  ** Enumerates the component types supported by this class.
  */
  enum class Component {
    Y  = 0,
    U  = 1,
    V  = 2,
    R  = 3,
    G  = 4,
    B  = 5,
    Cr = 1,
    Cb = 2,
  };


public:
  /*
  ** Gets the height of the frame.
  */
  virtual size_t height() const = 0;

  /*
  ** Gets the width of the frame.
  */
  virtual size_t width() const = 0;


protected:
  /*
  ** Gets individual pixel component values in a specified data type.
  */
  virtual uint8_t    getInt8(Component c, size_t x, size_t y) const = 0;
  virtual uint16_t  getInt16(Component c, size_t x, size_t y) const = 0;
  virtual float     getFloat(Component c, size_t x, size_t y) const = 0;
  virtual double   getDouble(Component c, size_t x, size_t y) const = 0;


public:
  /*
  ** Copy assignment.
  */
  virtual Frame& operator=(const Frame&) = default;

  /*
  ** Addition assignment.
  */
  //virtual Frame& operator+=(int)          = 0;
  //virtual Frame& operator+=(double)       = 0;
  //virtual Frame& operator+=(const Frame&) = 0;

  /*
  ** Subtraction assignment.
  */
  //        Frame& operator-=(int i)          { return *this += -i; }
  //        Frame& operator-=(double x)       { return *this += -x; }
  //virtual Frame& operator-=(const Frame& f) = 0;

  /*
  ** Read from a stream.
  */
  virtual void readFrom(istream&) = 0;

  /*
  ** Write to a stream.
  */
  virtual void writeTo(ostream&) const = 0;

  /*
  ** Base classes should always have virtual destructors.
  */
  virtual ~Frame() = default;
};
