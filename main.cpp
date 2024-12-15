/*
 * AbstractFactory.cpp
 *
 * Fachvortrag Software Engineering
 *
 * Authoren: Eric Ruppert, David Rudolph, Theresa Rohatsch
 */

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

//Die Klasse AbstractFactory agiert als Interface für den Client um entweder Stuhl-, Tisch- oder Bettobjekte zu erstellen
//Die Abstrakten Methoden werden dann von den tatsächlichen Fabriken überschrieben
class AbstractFactory {
    public:
    virtual Stuhl *createStuhl() const = 0;
    virtual Tisch *createTisch() const = 0;
    virtual Bett *createBett() const = 0;
};

//Die Klasse AlteFactory erbt von AbstractFactory und überschreibt die Methoden um alte Objekte zu erstellen
class AlteFactory : public AbstractFactory {
    //Die drei abstrakten Methoden der "AbstractFactory" Klasse werden überschrieben
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

//Die Klasse ModerneFactory erbt von AbstractFactory und überschreibt die Methoden um Mmoderne Objekte zu erstellen
class ModerneFactory : public AbstractFactory {
    //Die drei abstrakten Methoden der "AbstractFactory" Klasse werden überschrieben
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

//Die Klasse AntikeFactory erbt von AbstractFactory und überschreibt die Methoden um antike Objekte zu erstellen
class AntikeFactory : public AbstractFactory {
    public:
    //Die drei abstrakten Methoden der "AbstractFactory" Klasse werden überschrieben
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
    //Die drei Produkte werden nach der Gewünschten Variante erzeugt
    const Stuhl *produkt_a = factory.createStuhl();
    const Tisch *produkt_b = factory.createTisch();
    const Bett *produkt_c = factory.createBett();
    //Die "getName" Methode wird auf jedes objekt aufgerufen
    std::cout << produkt_a->getName() << std::endl;
    std::cout << produkt_b->getName() << std::endl;
    std::cout << produkt_c->getName() << std::endl;
    //Die Produkte werden gelöscht
    delete produkt_a;
    delete produkt_b;
    delete produkt_c;
}

//Die main-Methode erstellt alle 3 Fabriken und gibt die Namen der Objekte gruppiert aus
int main() {
    //Gibt die Objekte der Familie "AlteFactory" aus
    std::cout << "Client: Test für die AlteFactory: ";
    std::cout << std::endl;
    //Neuer Zeiger auf AlteFactory wird erstellt
    AlteFactory *f1 = new AlteFactory();
    //Der Zeiger wird dem Client übergeben
    Client (*f1);
    //Die Fabrik wird gelöscht
    delete f1;
    std::cout << std::endl;
    //Gibt die Objekte der Familie "NeueFactory" aus
    std::cout << "Client: Test für die ModerneFactory";
    std::cout << std::endl;
    //Neuer Zeiger auf NeueFactory wird erstellt
    ModerneFactory *f2 = new ModerneFactory();
    //Der Zeiger wird dem Client übergeben
    Client(*f2);
    //Die Fabrik wird gelöscht
    delete f2;
    //Gibt die Objekte der Familie "AntikeFactory" aus
    std::cout << std::endl;
    std::cout << "Client: Test für die AntikeFactory: ";
    std::cout << std::endl;
    //Neuer Zeiger auf AntikeFactory wird erstellt
    AntikeFactory *f3 = new AntikeFactory();
    //Der Zeiger wird dem Client übergeben
    Client (*f3);
    //Die Fabrik wird gelöscht
    delete f3;
    //String für die Eingabe wird deklariert
    std::string input;
    //Ausgabe von Strings für den Nutzer
    std::cout << std::endl;
    std::cout << "Bitte zwischen den verfügbaren Möbelsets auswählen:";
    std::cout << std::endl;
    std::cout << "Antik";
    std::cout << std::endl;
    std::cout << "Alt";
    std::cout << std::endl;
    std::cout << "Modern";
    std::cout << std::endl;
    //Eingabe des Nutzers
    std::getline(std::cin, input);
    std::cout << std::endl;
    //Der String wird mit den Strings "Antik", "Alt", und "Modern" verglichen und
    //die Objekte der jeweiligen Gruppe ausgegeben
    if (input == "Antik"){
        std::cout << "Zur Gruppe \"Antik\" gehören diese Möbelstücke:";
        std::cout << std::endl;
        AntikeFactory *f4 = new AntikeFactory();
        Client (*f4);
        delete f4;
    }
    else {
        if (input == "Alt") {
            std::cout << "Zur Gruppe \"Alt\" gehören diese Möbelstücke:";
            std::cout << std::endl;
            AlteFactory *f5 = new AlteFactory();
            Client (*f5);
            delete f5;
        }
        else {
            if (input == "Modern") {
                std::cout << "Zur Gruppe \"Modern\" gehören diese Möbelstücke:";
                std::cout << std::endl;
                ModerneFactory *f6 = new ModerneFactory();
                Client (*f6);
                delete f6;
            }
            else {
                //Sollte der Input keine der 3 Auswahlmöglichkeiten sein wird eine
                //Fehlermeldung ausgegeben
                std::cout << input << " ist keine Auswahlmöglichkeit!" << std::endl;
            }
        }
    }
    //Programmende
    return 0;
}