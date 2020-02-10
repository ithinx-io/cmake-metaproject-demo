#ifndef MYAPP_MYAPP_H_
#define MYAPP_MYAPP_H_

constexpr auto kMyAppMessage{"Hello from myapp :-)"};

class MyApp {
 public:
  explicit MyApp() = default;

  ~MyApp() = default;

  void Info() const;
};

#endif // MYAPP_MYAPP_H_
