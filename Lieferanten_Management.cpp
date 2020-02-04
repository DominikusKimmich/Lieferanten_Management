#include <iostream>
#include <string>
#include <memory>

// Produkt
class Mahlzeit {
};

// konkretes Produkt
class Pizza : public Mahlzeit {
public:
	Pizza() {
		std::cout << "Pizza gebacken." << std::endl;
	}
};

// noch ein konkretes Produkt
class Rostwurst : public Mahlzeit {
public:
	Rostwurst(const std::string& beilage) {
		std::cout << "Rostwurst gebraten." << std::endl;
		if (!beilage.empty()) {
			std::cout << "Serviert mit " << beilage << std::endl;
		}
	}
};

// Erzeuger
class Restaurant {
protected:
	std::shared_ptr<Mahlzeit> mahlzeit;

	// Die abstrakte Factory-Methode, die von Erzeugern implementiert werden muss.
	virtual void MahlzeitZubereiten() = 0;

	virtual void BestellungAufnehmen() {
		std::cout << "Ihre Bestellung bitte!" << std::endl;
	}

	virtual void MahlzeitServieren() {
		std::cout << "Hier Ihre Mahlzeit. Guten Appetit!" << std::endl;
	}

public:
	// Diese Methode benutzt die Factory-Methode.
	void MahlzeitLiefern() {
		BestellungAufnehmen();
		MahlzeitZubereiten(); // Aufruf der Factory-Methode
		MahlzeitServieren();
	}
};

// konkreter Erzeuger für konkretes Produkt "Pizza"
class Pizzeria : public Restaurant {
public:
	// Implementierung der abstrakten Methode der Basisklasse
	virtual void MahlzeitZubereiten() {
		mahlzeit = std::make_shared<Pizza>();
	}
};

// konkreter Erzeuger für konkretes Produkt "Rostwurst"
class Rostwurstbude : public Restaurant {
public:
	// Implementierung der abstrakten Methode der Basisklasse
	virtual void MahlzeitZubereiten() {
		mahlzeit = std::make_shared<Rostwurst>("Pommes und Ketchup");
	}
};

int main() {
	Pizzeria daToni;
	daToni.MahlzeitZubereiten();

	Rostwurstbude brunosImbiss;
	brunosImbiss.MahlzeitZubereiten();
}