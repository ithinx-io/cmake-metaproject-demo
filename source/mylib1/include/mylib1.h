#ifndef MYLIB1_MYLIB1_H_
#define MYLIB1_MYLIB1_H_

#include "mylib1_export.h"

class MYLIB1_EXPORT MyLib1 {
 public:
  explicit MyLib1() = default;

  ~MyLib1() = default;

  void Info() const;
};

#endif // MYLIB1_MYLIB1_H_
