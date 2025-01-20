#pragma once

#ifndef CROSS_H
#define CROSS_H

#include "line.h"
#include "shape.h"

// Крест
class Cross : public virtual Shape {
   protected:
    Line* _first;
    Line* _second;

   public:
    Cross(const Point& left, const Point& top);
    virtual void draw(Screen* screen) const override;
    virtual void move(Point p) override;
    Point getLeftTop() const override;
    Point getRightTop() const override;
    Point getLeftBottom() const override;
    Point getRightBottom() const override;
    virtual ~Cross();
};

Cross::Cross(const Point& left, const Point& top) {
    Point p1, p2;
    Point p3, p4;
    p1 = left;
    p2 = Point(top.getX() + top.getX() - left.getX(), left.getY());
    p3 = top;
    p4 = Point(top.getX(), left.getY() - top.getY() + left.getY());
    _first = new Line(p1, p2);
    _second = new Line(p3, p4);
}

void Cross::draw(Screen* screen) const {
    _first->draw(screen);
    _second->draw(screen);
}

void Cross::move(Point p) {
    _first->move(p);
    _second->move(p);
}

Point Cross::getLeftTop() const { return _first->getLeftTop(); }

Point Cross::getRightTop() const { return _second->getRightTop(); }

Point Cross::getLeftBottom() const { return _second->getLeftBottom(); }

Point Cross::getRightBottom() const { return _first->getRightBottom(); }

Cross::~Cross() {
    delete _first;
    delete _second;
}

#endif  // CROSS_H
