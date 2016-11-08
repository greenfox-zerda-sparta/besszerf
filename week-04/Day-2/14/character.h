#ifndef CHARACTER_H_
#define CHARACTER_H_

using namespace std;

class Character{
  private:
    string name;
    bool type; // 0 - player / 1 - monster;
    int health_points;
    int attacking_force;
    int defending_power;
    int calculate_result_of_attack(Character& enemy);

  public:
    Character(string name, int health_points, int attacking_force, int defending_power, bool type = 0);
    void attack(Character& enemy);
    const string get_name();
    const int get_health_points();
    const int get_defending_power();
    void set_health_points(int);
    const void print_character();
};

#endif /* CHARACTER_H_ */
