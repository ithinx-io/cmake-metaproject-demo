/* ******************************************************************************************* *
 *                                         header files                                        *
 * ******************************************************************************************* */
#include <cstdio>
#include "myapp.h"

/* ******************************************************************************************* *
 *                                        MyLib0 implementation                                *
 * ******************************************************************************************* */
void MyApp::Info() const {
  std::printf("[myapp] [%s] %s\n", __PRETTY_FUNCTION__, kMyAppMessage);
}
