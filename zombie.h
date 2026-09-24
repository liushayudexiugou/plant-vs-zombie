#pragma oncegit
#include <iostream>
#include <string>

using namespace std;

class Zombie
{
    public:
        Zombie(string n, int h, int a, int mS, int aS) //创建信息
            : name_(n)
            , hp_(h)
            , attack_(a)
            , moveSpeed_(mS)
            , atkSpeed_(aS) { };

        virtual void attack(Zombie& target) = 0; //攻击，因僵尸不同，为保证实际血量减少，采用虚拟

        void takeDamage(int damage) {
            hp_ -= damage;
        };//受伤

        virtual void showInfo()//展示信息
        { cout << "[" << name_ << "] hp:" << hp_ << "attak:" << attack_ << " moveSpeed:" << moveSpeed_ << endl; };

        virtual ~Zombie() { };//虚析构

    protected:
        string name_;
        int hp_;
        int attack_;
        int moveSpeed_;
        int atkSpeed_;
};

//创建新僵尸继承父类
//普通僵尸
class NormalZombie : public Zombie{
public:
    NormalZombie(string n, int h, int a, int mS, int aS)
        : Zombie(n, h, a, mS, aS) //继承赋值新僵尸
    { };

    void attack(Zombie& zombie) override {
        zombie.takeDamage(attack_);//僵尸攻击
    }

};

//路障僵尸
class ConeheadZombie : public Zombie
{
public:
    ConeheadZombie(string n, int h, int a, int mS, int aS)
        : Zombie(n, h, a, mS, aS)
    { }

    void attack(Zombie& zombie) override {
        zombie.takeDamage(attack_);
    }
};
