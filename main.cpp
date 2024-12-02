#include <iostream>

class Stuhl {
public:
    virtual ~Stuhl(){};
    virtual std::string getName() const = 0;
};

class AlterStuhl : public Stuhl {
    public:
    std::string getName() const override {
        return "AlterStuhl";
    }
};

class NeuerStuhl : public Stuhl {
    public:
    std::string getName() const override {
        return "NeuerStuhl";
    }
};

class Tisch {
    public:
    virtual ~Tisch(){};
    virtual std::string getName() const = 0;
};

class AlterTisch : public Tisch {
    public:
    std::string getName() const override {
        return "AlterTisch";
    }
};

class NeuerTisch : public Tisch {
    public:
    std::string getName() const override {
        return "NeuerTisch";
    }
};

class Bett {
    public:
    virtual ~Bett(){};
    virtual std::string getName() const = 0;
};

class AltesBett : public Bett {
    public:
    std::string getName() const override {
        return "AltesBett";
    }
};

class NeuesBett : public Bett {
    public:
    std::string getName() const override {
        return "NeuesBett";
    }
};

class
class AbstractFactory {
    public:
    virtual Stuhl *createStuhl() const = 0;
    virtual Tisch *createTisch() const = 0;
    virtual Bett *createBett() const = 0;
};

class AlteFactory : public AbstractFactory {
public:
    Stuhl *createStuhl() const override {
        return new AlterStuhl();
    }
    Tisch *createTisch() const override {
        return new AlterTisch();
    }
    Bett *createBett() const override {
        return new AltesBett();
    }
};

class NeueFactory : public AbstractFactory {
    public:
    Stuhl *createStuhl() const override {
        return new NeuerStuhl();
    }
    Tisch *createTisch() const override {
        return new NeuerTisch();
    }
    Bett *createBett() const override {
        return new NeuesBett();
    }
};

void Client(const AbstractFactory &factory) {
    const Stuhl *produkt_a = factory.createStuhl();
    const Tisch *produkt_b = factory.createTisch();
    const Bett *produkt_c = factory.createBett();
    std::cout << produkt_a->getName() << std::endl;
    std::cout << produkt_b->getName() << std::endl;
    std::cout << produkt_c->getName() << std::endl;
    delete produkt_a;
    delete produkt_b;
    delete produkt_c;
}

int main() {
    std::cout << "Client: Test für die AlteFactory: " << std::endl;
    AlteFactory *f1 = new AlteFactory();
    Client (*f1);
    delete f1;
    std::cout << std::endl;
    std::cout << "Client: Test für die NeueFactory: " << std::endl;
    NeueFactory *f2 = new NeueFactory();
    Client(*f2);
    delete f2;
    return 0;
}