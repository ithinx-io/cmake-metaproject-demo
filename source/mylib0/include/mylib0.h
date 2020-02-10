#ifndef MYLIB0_MYLIB0_H_
#define MYLIB0_MYLIB0_H_

#include "mylib0_export.h"

class MYLIB0_EXPORT MyLib0 {
 public:
  explicit MyLib0() = default;

  ~MyLib0() = default;

  void Info() const;
};

#endif // MYLIB0_MYLIB0_H_
