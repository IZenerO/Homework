class Array {
 public:
  int add(int value);
  void show() const;
  int replace(uint32_t pos1, int value);
  int swap(uint32_t pos1, uint32_t pos2);
  
 private:
  static const unsigned ARRAY_SIZE = 255;
  int array[ARRAY_SIZE] {};
  int position = 0;
};
