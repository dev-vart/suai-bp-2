#include <iostream>
#include <memory>
#include <vector>

#include "cross.h"
#include "line.h"
#include "screen.h"
#include "square.h"

int main() {
    auto screen = std::make_unique<Screen>(50, 35);

    std::vector<std::shared_ptr<Shape>> shapes;

    shapes.emplace_back(std::make_shared<Square>(Point(15, 3), Point(32, 12)));  // Создаем Шляпу

    // Вычисляем координаты Линии под шляпой
    Point p1 = shapes[shapes.size() - 1]->getLeftBottom();
    p1.setX(p1.getX() - 2);
    p1.setY(p1.getY() + 1);
    Point p2 = shapes[shapes.size() - 1]->getRightBottom();
    p2.setX(p2.getX() + 2);
    p2.setY(p2.getY() + 1);

    shapes.emplace_back(std::make_shared<Line>(p1, p2));  // Создаем Линию под шляпой

    // Вычисляем координаты Головы
    p1 = shapes[shapes.size() - 1]->getLeftBottom();
    p1.setX(p1.getX() + 1);
    p1.setY(p1.getY() + 1);
    p2 = shapes[shapes.size() - 1]->getRightBottom();
    p2.setX(p2.getX() - 1);
    p2.setY(p2.getY() + 10);

    shapes.emplace_back(std::make_shared<Square>(p1, p2));  // Создаем Голову

    // Вычисляем координаты Левого глаза
    Point eyeLeft = shapes[shapes.size() - 1]->getLeftTop();
    eyeLeft.setX(eyeLeft.getX() + 2);
    eyeLeft.setY(eyeLeft.getY() + 2);
    Point eyeRight = Point(eyeLeft.getX() + 2, eyeLeft.getY());

    shapes.emplace_back(std::make_shared<Line>(eyeLeft, eyeRight));  // Создаем Левый глаз

    // Вычисляем координаты Правого глаза
    eyeRight = shapes[shapes.size() - 2]->getRightTop();
    eyeRight.setX(eyeRight.getX() - 2);
    eyeRight.setY(eyeRight.getY() + 2);
    eyeLeft = Point(eyeRight.getX() - 2, eyeRight.getY());

    shapes.emplace_back(std::make_shared<Line>(eyeLeft, eyeRight));  // Создаем Правый глаз

    // Вычисляем координаты Носа
    std::shared_ptr<Shape> leftEye = shapes[shapes.size() - 2];
    std::shared_ptr<Shape> rightEye = shapes[shapes.size() - 1];
    Point nose = Point(
        leftEye->getRightTop().getX() + (rightEye->getLeftTop().getX() - leftEye->getRightTop().getX()) / 2,
        leftEye->getRightTop().getY() + 2);

    shapes.emplace_back(std::make_shared<Line>(nose, nose));  // Создаем Нос

    // Вычисляем координаты Рта
    std::shared_ptr<Shape> head = shapes[shapes.size() - 4];
    p1 = head->getLeftBottom();
    p1.setX(p1.getX() + 2);
    p1.setY(p1.getY() - 2);
    p2 = head->getRightBottom();
    p2.setX(p2.getX() - 2);
    p2.setY(p2.getY() - 2);

    shapes.emplace_back(std::make_shared<Line>(p1, p2));  // Создаем Рот

    // Создаем Линию костюма
    auto costume = std::make_shared<Line>(Point(p1.getX(), p1.getY() + 10), Point(p2.getX(), p2.getY() + 10));
    shapes.emplace_back(costume);

    // Вычисляем координаты левой точки
    p1 = Point(costume->getLeftBottom().getX(), costume->getLeftBottom().getY() + 1);
    auto leftDot = std::make_shared<Line>(p1, p1);

    shapes.emplace_back(leftDot);  // Создаем Левую точку

    // Вычисляем координаты правой точки
    p1 = Point(costume->getRightBottom().getX(), costume->getRightBottom().getY() + 1);
    auto rightDot = std::make_shared<Line>(p1, p1);

    shapes.emplace_back(rightDot);  // Создаем Правую точку

    // Вычисляем координаты левой Серьги-креста
    p1 = Point(leftEye->getLeftTop().getX() - 6, leftEye->getLeftTop().getY() + 2);
    p2 = Point(leftEye->getLeftTop().getX() - 5, leftEye->getLeftTop().getY() + 1);

    shapes.emplace_back(std::make_shared<Cross>(p1, p2));  // Создаем Левую Серьгу-крест

    // Вычисляем координаты левой Серьги-креста
    p1 = Point(rightEye->getRightTop().getX() + 6, rightEye->getRightTop().getY() + 2);
    p2 = Point(rightEye->getRightTop().getX() + 5, rightEye->getRightTop().getY() + 1);

    shapes.emplace_back(std::make_shared<Cross>(p1, p2));  // Создаем Правую Серьгу-крест

    for (auto shape : shapes) shape->draw(screen.get());
    screen->draw();

    return 0;
}
