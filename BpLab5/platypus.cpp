#include "platypus.h"

Mammal_B1::Mammal_B1(const string &region) : region(region) {
    cout << "����������� B1: ������� ������������� � ������ ��������: " << region << endl;
};

Bird_B2::Bird_B2(const string &beakSize) : beakSize(beakSize) {
    cout << "����������� B2: ������� ����� � �������� �����: " << beakSize << " ��" << endl;
}

Reptile_B3::Reptile_B3() { cout << "����������� B3: ������� �������� � " << eggNumber << endl; }

Plat_D1::Plat_D1(const string &region, const string &beakSize, const string &eggNumber, const string &weight)
    : Reptile_B3(), Mammal_B1(region), Bird_B2(beakSize), weight(weight) {
    Reptile_B3::setEggNumber(eggNumber);
    cout << "����������� D1: ������ ������� � �����: " << weight << " ��" << endl;
}

MythPlat_D3::MythPlat_D3(const string &eggNumber, const string &cult) : Reptile_B3(), cult(cult) {
    Reptile_B3::setEggNumber(eggNumber);
    cout << "����������� D3: ������ �������������� ������� ��������: " << cult << endl;
}

FictPlat_D2::FictPlat_D2(const string &region, const string &beakSize, const string &eggNumber,
                         const string &weight, const string &fictType, const string &cult)
    : Plat_D1(region, beakSize, eggNumber, weight), MythPlat_D3(eggNumber, cult), fictType(fictType) {
    cout << "����������� D2: ������ ����������� ������� �� ���������: " << fictType << endl;
}

CartPlat_D4::CartPlat_D4(const string &region, const string &beakSize, const string &eggNumber,
                         const string &weight, const string &fictType, const string &nickname,
                         const string &cult)
    : FictPlat_D2(region, beakSize, eggNumber, weight, fictType, cult), nickname(nickname) {
    cout << "����������� D4: ������ ������� �� ��������� � �������: " << nickname << endl;
}

Mammal_B1::~Mammal_B1() { cout << "���������� B1: ������������� �������" << endl; };

Bird_B2::~Bird_B2() { cout << "���������� B2: ����� �������" << endl; }

Reptile_B3::~Reptile_B3() { cout << "���������� B3: �������� �������" << endl; }

Plat_D1::~Plat_D1() { cout << "���������� D1: ������� ������" << endl; }

FictPlat_D2::~FictPlat_D2() { cout << "���������� D2: ����������� ������� ������" << endl; }

MythPlat_D3::~MythPlat_D3() { cout << "���������� D3: �������������� ������� ������" << endl; }

CartPlat_D4::~CartPlat_D4() { cout << "���������� D4: ������� �� ��������� ������" << endl; }

void Mammal_B1::show() {
    cout << "== B1 show == ";
    cout << "������������� � ����� ��������� ����� ��������: " << region << endl;
}

void Bird_B2::show() {
    cout << "== B2 show == ";
    cout << "����� ��� ������ ������� " << beakSize << " ��" << endl;
}

void Reptile_B3::show() {
    cout << "== B3 show == ";
    cout << "�������� ����������� " << eggNumber << " ��� �� ���� ���" << endl;
}

void Plat_D1::show() {
    cout << "== D1 show == ";
    cout << "������� ����� " << weight << " ��" << endl;
    Mammal_B1::show();
    Bird_B2::show();
    Reptile_B3::show();
}

void FictPlat_D2::show() {
    cout << "== D2 show == ";
    cout << "�����������, " << fictType << " ��� �������� - ��� ����� ���������" << endl;
    Plat_D1::show();
    MythPlat_D3::show();
}

void MythPlat_D3::show() {
    cout << "== D3 show == ";
    cout << "� �������� " << cult << " ������� ��������� �������� ��������� � ����������" << endl;
    Reptile_B3::show();
}

void CartPlat_D4::show() {
    cout << "== D4 show == ";
    cout << "����, � ��� " << nickname << " ?" << endl;
    FictPlat_D2::show();
}

void Reptile_B3::setEggNumber(const string &eggNumber) { this->eggNumber = eggNumber; }