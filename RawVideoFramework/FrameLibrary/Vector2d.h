#pragma once


#include <vector>
using std::vector;


template<T>
class Vector2d : public vector<T> {
private:
  /*
  ** Height, width.
  */
  vector<T>::size_type h, w;


public:
  /*
  ** Constructor.
  */
  Vector2d(vector<T>::size_type height, vector<T>::size_type width) :
    h(height),
    w(width),
    vector(width*height) {
  }

  /*
  ** Getter for height.
  */
  unsigned int height() const {
    return h;
  }

  /*
  ** Getter for width.
  */
  unsigned int width() const {
    return w;
  }

  /*
  ** Resize the vector.
  */
  void resize(vector<T>::size_type height, vector<T>::size_type width) {
    h = height;
    w = width;
    vector::resize(h*w);
  }

  /*
  ** Elemental access.
  */
  T& operator(vector<T>::size_type x, vector<T>::size_type y) {
    return vector::at(y * h + x);
  }

  /*
  ** Constant elemental access.
  */
  const T& operator(vector<T>::size_type x, vector<T>::size_type y) const {
    return vector::at(y * h + x);
  }
};
