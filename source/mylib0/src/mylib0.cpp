/* ******************************************************************************************* *
 *                                         header files                                        *
 * ******************************************************************************************* */
#include <cstdio>
#include <memory>
#include "mylib1.h"
#include "mylib0-defs.h"
#include "mylib0.h"

/* ******************************************************************************************* *
 *                                        MyLib0 implementation                                *
 * ******************************************************************************************* */
void MyLib0::Info() const {
  auto const lib1 = std::make_unique<MyLib1>();
  std::printf("[mylib0] [%s] %s\n", __PRETTY_FUNCTION__, kMyLib0Message);
  lib1->Info();
}
