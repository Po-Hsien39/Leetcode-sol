#include <iostream>
#include <vector>

using namespace std;

class MyHashMap
{
private:
  vector<int> maps;

public:
  MyHashMap()
  {
    maps.resize(1000001, -1);
  }

  void put(int key, int value)
  {
    maps[key] = value;
  }

  int get(int key)
  {
    return maps[key];
  }

  void remove(int key)
  {
    maps[key] = -1;
  }
};