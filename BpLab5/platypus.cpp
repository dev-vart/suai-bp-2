#include "platypus.h"

Mammal_B1::Mammal_B1(const string &region) : region(region) {
    cout << "Конструктор B1: Создано Млекопитающее с местом обитания: " << region << endl;
};

Bird_B2::Bird_B2(const string &beakSize) : beakSize(beakSize) {
    cout << "Конструктор B2: Создана Птица с размером клюва: " << beakSize << " см" << endl;
}

Reptile_B3::Reptile_B3() { cout << "Конструктор B3: Создана Рептилия с " << eggNumber << endl; }

Plat_D1::Plat_D1(const string &region, const string &beakSize, const string &eggNumber, const string &weight)
    : Reptile_B3(), Mammal_B1(region), Bird_B2(beakSize), weight(weight) {
    Reptile_B3::setEggNumber(eggNumber);
    cout << "Конструктор D1: Создан Утконос с весом: " << weight << " кг" << endl;
}

MythPlat_D3::MythPlat_D3(const string &eggNumber, const string &cult) : Reptile_B3(), cult(cult) {
    Reptile_B3::setEggNumber(eggNumber);
    cout << "Конструктор D3: Создан Мифологический утконос культуры: " << cult << endl;
}

FictPlat_D2::FictPlat_D2(const string &region, const string &beakSize, const string &eggNumber,
                         const string &weight, const string &fictType, const string &cult)
    : Plat_D1(region, beakSize, eggNumber, weight), MythPlat_D3(eggNumber, cult), fictType(fictType) {
    cout << "Конструктор D2: Создан Вымышленный утконос из источника: " << fictType << endl;
}

CartPlat_D4::CartPlat_D4(const string &region, const string &beakSize, const string &eggNumber,
                         const string &weight, const string &fictType, const string &nickname,
                         const string &cult)
    : FictPlat_D2(region, beakSize, eggNumber, weight, fictType, cult), nickname(nickname) {
    cout << "Конструктор D4: Создан утконос из мультиков с кличкой: " << nickname << endl;
}

Mammal_B1::~Mammal_B1() { cout << "Деструктор B1: Млекопитающее удалено" << endl; };

Bird_B2::~Bird_B2() { cout << "Деструктор B2: Птица удалена" << endl; }

Reptile_B3::~Reptile_B3() { cout << "Деструктор B3: Рептилия удалена" << endl; }

Plat_D1::~Plat_D1() { cout << "Деструктор D1: Утконос удален" << endl; }

FictPlat_D2::~FictPlat_D2() { cout << "Деструктор D2: Вымышленный утконос удален" << endl; }

MythPlat_D3::~MythPlat_D3() { cout << "Деструктор D3: Мифологический утконос удален" << endl; }

CartPlat_D4::~CartPlat_D4() { cout << "Деструктор D4: Утконос из мультиков удален" << endl; }

void Mammal_B1::show() {
    cout << "== B1 show == ";
    cout << "Млекопитающее в своей привычной среде обитания: " << region << endl;
}

void Bird_B2::show() {
    cout << "== B2 show == ";
    cout << "Птица ест клювом размера " << beakSize << " см" << endl;
}

void Reptile_B3::show() {
    cout << "== B3 show == ";
    cout << "Рептилия откладывает " << eggNumber << " яиц за один раз" << endl;
}

void Plat_D1::show() {
    cout << "== D1 show == ";
    cout << "Утконос весит " << weight << " кг" << endl;
    Mammal_B1::show();
    Bird_B2::show();
    Reptile_B3::show();
}

void FictPlat_D2::show() {
    cout << "== D2 show == ";
    cout << "Оказывается, " << fictType << " про утконоса - это очень интересно" << endl;
    Plat_D1::show();
    MythPlat_D3::show();
}

void MythPlat_D3::show() {
    cout << "== D3 show == ";
    cout << "В культуре " << cult << " утконос считается символом созидания и творчества" << endl;
    Reptile_B3::show();
}

void CartPlat_D4::show() {
    cout << "== D4 show == ";
    cout << "Стоп, а где " << nickname << " ?" << endl;
    FictPlat_D2::show();
}

void Reptile_B3::setEggNumber(const string &eggNumber) { this->eggNumber = eggNumber; }