#ifndef APPLE_H_
#define APPLE_H_
#include <string>
#include <vector>

using namespace std;

class Apple {
  public:
    string get_apple();
    int sum_apples(vector<int>& apples_on_shelves);
  private:
};

#endif /* APPLE_H_ */
