#pragma once

#include <cstdint>


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
  virtual int height() const = 0;

  /*
  ** Gets the width of the frame.
  */
  virtual int width() const = 0;


protected:
  /*
  ** Gets individual pixel component values in a specified data type.
  */
  virtual uint8_t    getInt8(Component c, int x, int y) const = 0;
  virtual uint16_t  getInt16(Component c, int x, int y) const = 0;
  virtual float     getFloat(Component c, int x, int y) const = 0;
  virtual double   getDouble(Component c, int x, int y) const = 0;


public:
  /*
  ** Copy assignment.
  */
  virtual Frame& operator=(Frame&) = default;

  /*
  ** Unary negation.
  */
  virtual Frame& operator-() = 0;

  /*
  ** Addition assignment.
  */
  virtual Frame& operator+=(int)    = 0;
  virtual Frame& operator+=(double) = 0;
  virtual Frame& operator+=(Frame&) = 0;

  /*
  ** Subtraction assignment.
  */
  Frame& operator-=(int    i) { return *this += -i; }
  Frame& operator-=(double x) { return *this += -x; }
  Frame& operator-=(Frame& f) { return *this += -f; }

  /*
  ** Base classes should always have virtual destructors.
  */
  virtual ~Frame() = default;


public:
  /*
  ** PSNR calculation.
  */
  static double psnr(const Frame& a, const Frame& b) {
    
  }
};
