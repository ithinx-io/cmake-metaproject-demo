/* ******************************************************************************************* *
 *                                         header files                                        *
 * ******************************************************************************************* */
#include <memory>
#include <cstdlib>
#include "mylib0.h"
#include "myapp.h"

/* ******************************************************************************************* *
 *                                        main definition                                      *
 * ******************************************************************************************* */
int main(int argc, char** argv, char** envp)
{
  (void)envp;

  // Involve Cpp STL to test indexing
  auto const app = std::make_unique<MyApp>();
  auto const lib0 = std::make_unique<MyLib0>();

  // Initial message from local component
  app->Info();

  // Call info from mylib0 (which calls info from mylib1 internally)
  lib0->Info();

  return EXIT_SUCCESS;
}
