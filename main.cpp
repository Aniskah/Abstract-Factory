#include <iostream>

//Die Klasse Stuhl definiert das abstrakte Objekt "Stuhl" und die abstrakte Methode "getName"
class Stuhl {
public:
    virtual ~Stuhl(){}; //Abstraktes Object
    virtual std::string getName() const = 0; //Gibt den Namen des Objekts aus
};

//Die Klasse AlterStuhl überschreibt die geerbte abstrakten Methode und erbt von Stuhl
class AlterStuhl : public Stuhl {
    public:
    std::string getName() const override {
        return "AlterStuhl";
    }
};

//Die Klasse ModernerStuhl überschreibt die geerbte abstrakten Methode und erbt von Stuhl
class ModernerStuhl : public Stuhl {
    public:
    std::string getName() const override {
        return "ModernerStuhl";
    }
};

//Die Klasse AntikerStuhl überschreibt die geerbte abstrakten Methode und erbt von Stuhl
class AntikerStuhl : public Stuhl {
    public:
    std::string getName() const override {
        return "AntikerStuhl";
    }
};

//Die Klasse Tisch definiert das abstrakte Objekt "Tisch" und die abstrakte Methode "getName"
class Tisch {
    public:
    virtual ~Tisch(){};//Abstraktes Object
    virtual std::string getName() const = 0;//Gibt den Namen des Objekts aus
};

//Die Klasse AlterTisch überschreibt die geerbte abstrakten Methode und erbt von Tisch
class AlterTisch : public Tisch {
    public:
    std::string getName() const override {
        return "AlterTisch";
    }
};

//Die Klasse ModernerTisch überschreibt die geerbte abstrakten Methode und erbt von Tisch
class ModernerTisch : public Tisch {
    public:
    std::string getName() const override {
        return "ModernerTisch";
    }
};

//Die Klasse AntikerTisch überschreibt die geerbte abstrakten Methode und erbt von Tisch
class AntikerTisch : public Tisch {
public:
    std::string getName() const override {
        return "AntikerTisch";
    }
};

//Die Klasse Bett definiert das abstrakte Objekt "Bett" und die abstrakte Methode "getName"
class Bett {
    public:
    virtual ~Bett(){};//Abstraktes Object
    virtual std::string getName() const = 0;//Gibt den Namen des Objekts aus
};

//Die Klasse AltesBett überschreibt die geerbte abstrakten Methode und erbt von Bett
class AltesBett : public Bett {
    public:
    std::string getName() const override {
        return "AltesBett";
    }
};

//Die Klasse ModernesBett überschreibt die geerbte abstrakten Methode und erbt von Bett
class ModernesBett : public Bett {
    public:
    std::string getName() const override {
        return "ModernesBett";
    }
};

//Die Klasse AntikesBett überschreibt die geerbte abstrakten Methode und erbt von Bett
class AntikesBett : public Bett {
    public:
    std::string getName() const override {
        return "AntikerBett";
    }
};

//Die klasse AbstractFactory agiert als Interface für den Client um entweder Stuhl-, Tisch- oder Bettobjekte zu erstellen
//Die Abstrakten Methoden werden dann von den tatsächlichen Fabriken überschrieben
class AbstractFactory {
    public:
    virtual Stuhl *createStuhl() const = 0;
    virtual Tisch *createTisch() const = 0;
    virtual Bett *createBett() const = 0;
};

//Die Klasse AlteFactory erbt von AbstractFactory und überschreibt die Methoden um Alte Objekte zu erstellen
class AlteFactory : public AbstractFactory {
    //Die Drei abstrakten Methoden der "AbstractFactory" Klasse werden überschrieben
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

//Die Klasse NeueFactory erbt von AbstractFactory und überschreibt die Methoden um Neue Objekte zu erstellen
class NeueFactory : public AbstractFactory {
    //Die Drei abstrakten Methoden der "AbstractFactory" Klasse werden überschrieben
    public:
    Stuhl *createStuhl() const override {
        return new ModernerStuhl();
    }
    Tisch *createTisch() const override {
        return new ModernerTisch();
    }
    Bett *createBett() const override {
        return new ModernesBett();
    }
};

//Die Klasse AntikeFactory erbt von AbstractFactory und überschreibt die Methoden um Antike Objekte zu erstellen
class AntikeFactory : public AbstractFactory {
    public:
    //Die Drei abstrakten Methoden der "AbstractFactory" Klasse werden überschrieben
    Stuhl *createStuhl() const override {
        return new AntikerStuhl();
    }
    Tisch *createTisch() const override {
        return new AntikerTisch();
    }
    Bett *createBett() const override {
        return new AntikesBett();
    }
};

//Der Client übernimmt ein AbstractFactory-Objekt und erstellt die Gefragten Objekte einer Familie
void Client(const AbstractFactory &factory) {
    //Die Drei Produkte werden nach der Gewünschten Variante erzeugt
    const Stuhl *produkt_a = factory.createStuhl();
    const Tisch *produkt_b = factory.createTisch();
    const Bett *produkt_c = factory.createBett();
    //Die "getName" Methode wird auf jedes objekt aufgerufen
    std::cout << produkt_a->getName() << std::endl;
    std::cout << produkt_b->getName() << std::endl;
    std::cout << produkt_c->getName() << std::endl;
    delete produkt_a;
    delete produkt_b;
    delete produkt_c;
}

//Die main-Methode erstellt alle 3 Fabriken und gibt die Namen der Objekte gruppiert aus
int main() {
    //Gibt Die Objekte der Familie "AlteFactory" aus
    std::cout << "Client: Test für die AlteFactory: " << std::endl;
    AlteFactory *f1 = new AlteFactory();
    Client (*f1);
    delete f1;
    std::cout << std::endl;
    //Gibt Die Objekte der Familie "NeueFactory" aus
    std::cout << "Client: Test für die NeueFactory: " << std::endl;
    NeueFactory *f2 = new NeueFactory();
    Client(*f2);
    delete f2;
    //Gibt Die Objekte der Familie "AntikeFactory" aus
    std::cout << std::endl;
    std::cout << "Client: Test für die AntikeFactory: " << std::endl;
    AntikeFactory *f3 = new AntikeFactory();
    Client (*f3);
    delete f3;
    return 0;
}