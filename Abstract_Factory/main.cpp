#include <iostream>
using namespace std;

class Herbivore{
    int weight;
public:
    Herbivore(){
        weight = 0;
    }
    ~Herbivore(){
        delete this;
    }
    void EatGrass(){
        cout << "Eating grass...";
        weight += 10;
    }
    int GetWeight(){
        return weight;
    }
};

class Carnivore{
    int power;
public:
    Carnivore(){
        power = 0;
    }
    ~Carnivore(){
        delete this;
    }
    void Eat(Herbivore* h){
        cout << "Eating herbifore...";
    }
    void AddPower(int p){
        power += p;
    }
    int GetPower(){
        return power;
    }
};

class Wildebeast : public Herbivore{
    int weight;
    bool life;
public:
    Wildebeast(){
        weight = 200;
        life = true;
    }
};

class Bison : public Herbivore{
    int weight;
    bool life;
public:
    Bison(){
        weight = 700;
        life = true;
    }
};

class Elk : public Herbivore{
    int weight;
    bool life;
public:
    Elk(){
        weight = 500;
        life = true;
    }
};

class Lion : public Carnivore{
public:
    Lion(){
        this->AddPower(1000);
    }
    void Eat(Herbivore* h){
        if (this->GetPower() > h->GetWeight()){
            cout << "Eating heibifore...";
            this->AddPower(10);
        }
        else this->AddPower(-10);
    }
};

class Wolf : public Carnivore{
public:
    Wolf(){
        this->AddPower(700);
    }
    void Eat(Herbivore* h){
        if (this->GetPower() > h->GetWeight()){
            cout << "Eating heibifore...";
            this->AddPower(10);
        }
        else this->AddPower(-10);
    }
};

class Tiger : public Carnivore{
public:
    Tiger(){
        this->AddPower(1500);
    }
    void Eat(Herbivore* h){
        if (this->GetPower() > h->GetWeight()){
            cout << "Eating heibifore...";
            this->AddPower(10);
        }
        else this->AddPower(-10);
    }
};

class Continent{
public:
    ~Continent(){
        delete this;
    }
    Herbivore* CreateHerbivore(){
        return new Herbivore;
    }
    Carnivore* CreateCarnivore(){
        return new Carnivore;
    }
};

class Africa : public Continent{
public:
    Herbivore* CreateHerbivore(){
        return new Wildebeast;
    }
    Carnivore* CreateCarnivore(){
        return new Lion;
    }
};

class NorthAmerica : public Continent{
public:
    Herbivore* CreateHerbivore(){
        return new Bison;
    }
    Carnivore* CreateCarnivore(){
        return new Wolf;
    }
};

class Euroasia : public Continent{
public:
    Herbivore* CreateHerbivore(){
        return new Elk;
    }
    Carnivore* CreateCarnivore(){
        return new Tiger;
    }
};

class AnimalWorld{
    Continent* c;
public:
    AnimalWorld(Continent* c){
        this->c = c;
    }
    ~AnimalWorld(){
        delete c;
    }
    void MealsHerbivores(){
        c->CreateHerbivore()->EatGrass();
    }
    void NutritionCarnivores(){
        c->CreateCarnivore()->Eat(c->CreateHerbivore());
    }
};

int main() {
    Continent* c = new Africa;
    AnimalWorld aw(c);
    aw.MealsHerbivores();
    aw.NutritionCarnivores();
}
