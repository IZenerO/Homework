class Singleton {
public:
  static Singleton& getInstance();
  int add(int value);
  void show () const;
private:
  Singleton() {};
  Singleton(const Singleton& ms) = delete;
  Singleton& operator=(const Singleton& ms) = delete;
  ~Singleton() {};

  static const unsigned ARRAY_SIZE = 255;
  int array[ARRAY_SIZE] {};
  int position = 0;

};