/* ******************************************************************************************* *
 *                                         header files                                        *
 * ******************************************************************************************* */
#include <cstdio>
#include "mylib1-defs.h"
#include "mylib1.h"

/* ******************************************************************************************* *
 *                                        MyLibo implementation                                *
 * ******************************************************************************************* */
void MyLib1::Info() const {
  std::printf("[mylib1] [%s] %s\n", __PRETTY_FUNCTION__, kMyLib1Message);
}
