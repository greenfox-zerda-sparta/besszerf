#ifndef CAR_H_
#define CAR_H_

using namespace std;

class Car{
  private:
    string type;
    int km;
  public:
    Car(string type, int km);
    void run(int km);
    const int get_km();
};

#endif /* CAR_H_ */