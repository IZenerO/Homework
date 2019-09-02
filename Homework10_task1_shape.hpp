#pragma once
class Shape {
  public:
    virtual void calc_area ();
    virtual void draw() const;
};

class Square : public Shape {
  public:
    void calc_area();
    void draw() const;
};

class Rectangle : public Shape {
  public:
    void calc_area();
    void draw() const;
};

class Triangle : public Shape {
  public:
    void calc_area();
    void draw() const;
};
