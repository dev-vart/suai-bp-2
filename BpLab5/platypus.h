#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Mammal_B1 {
   protected:
    string region{};

   public:
    explicit Mammal_B1(const string &region = "");
    ~Mammal_B1();
    virtual void show();
};

class Bird_B2 {
   protected:
    string beakSize{};

   public:
    explicit Bird_B2(const string &beakSize = "");
    ~Bird_B2();
    void show();
};

class Reptile_B3 {
   protected:
    string eggNumber{};

   public:
    Reptile_B3();
    ~Reptile_B3();
    virtual void show();
    void setEggNumber(const string &eggNumber);
};

class Plat_D1 : private Mammal_B1, public Bird_B2, virtual protected Reptile_B3 {
   protected:
    string weight{};

   public:
    explicit Plat_D1(const string &region = "", const string &beakSize = "", const string &eggNumber = "",
                     const string &weight = "");
    ~Plat_D1();
    void show() override;
};

class MythPlat_D3 : virtual public Reptile_B3 {
   protected:
    string cult{};

   public:
    explicit MythPlat_D3(const string &eggNumber = "", const string &cult = "");
    ~MythPlat_D3();
    void show() override;
};

class FictPlat_D2 : public Plat_D1, private MythPlat_D3 {
   protected:
    string fictType{};

   public:
    explicit FictPlat_D2(const string &region = "", const string &beakSize = "", const string &eggNumber = "",
                         const string &weight = "", const string &fictType = "", const string &cult = "");
    ~FictPlat_D2();
    void show() override;
};

class CartPlat_D4 : protected FictPlat_D2 {
   protected:
    string nickname{};

   public:
    explicit CartPlat_D4(const string &region = "", const string &beakSize = "", const string &eggNumber = "",
                         const string &weight = "", const string &fictType = "", const string &nickname = "",
                         const string &cult = "");
    ~CartPlat_D4();
    void show() override;
};
