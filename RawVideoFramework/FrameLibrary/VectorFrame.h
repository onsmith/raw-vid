#pragma once

#include "Frame.h"

#include <vector>
using std::vector;

#include <iostream>
using std::istream;
using std::ostream;

#include <stdint.h>


/*
** A vector-backed implementation of the Frame abstract class.
*/
template <Pixel>
class VectorFrame : Frame {
private:
  /*
  ** Internally manages a vector to store the frame data.
  */
  vector<Pixel> data;

  /*
  ** The frame's width.
  */
  size_t w;

  /*
  ** The frame's height.
  */
  size_t h;


public:
  /*
  ** Constructor.
  */
  VectorFrame(size_t width, size_t height, size_t size) :
    w(width),
    h(height),
    data(size) {
  }

  size_t width() const final {
    return w;
  }

  size_t height() const final {
    return h;
  }

  void readFrom(istream& s) final {
    s.read(reinterpret_cast<char*>(data.data()), data.size() * sizeof(Pixel));
  }

  void writeTo(ostream& s) const final {
    s.write(reinterpret_cast<const char*>(data.data()), data.size() * sizeof(Pixel));
  }
};
