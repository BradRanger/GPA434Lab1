#pragma once
#ifndef VECT2D_H
#define VECT2D_H

#include <iostream>

class Vect2D
{
	friend Vect2D operator/(double, Vect2D const&);
	friend std::ostream& operator<<(std::ostream& lhs, Vect2D const& rhs);

public:
	Vect2D();
	Vect2D(double x, double y);
	~Vect2D();
	
	// accesseurs
	double x() const;
	double y() const;

	// mutateurs
	void setX(double x);
	void setY(double y);
	void set(double x, double y);

	// fonctions spécialisées
	double dot(Vect2D const& other) const;

	// surcharges d'opérateur
	bool operator==(Vect2D const & rhs) const;
	bool operator!=(Vect2D const & rhs) const;
	// vect2d + vect2d = retourne un vect 2d
	Vect2D operator+(Vect2D rhs) const;
	Vect2D operator-(Vect2D rhs) const;
	Vect2D operator-() const;
	//quand tes dans la classe, operator est un mot réservé
	//quand tas un objet de vect2d multiplié par un double, on retourne un vect2d
	//pas besoin davoir 2 parametres pcq avec le mot operator
	//c'est défini que le premier mot va entrer en interaction avec le seul parametre passé
	Vect2D operator*(double rhs) const;
	Vect2D operator/(double rhs) const;

	Vect2D& operator+=(Vect2D const& rhs);
	Vect2D& operator-=(Vect2D const& rhs);
	Vect2D& operator*=(double rhs);
	Vect2D& operator/=(double rhs);

private:
	double mX;
	double mY;
};


// À L'EXTÉRIEUR DE LA CLASSE VECT2D
//because left operand cannot be modified by us
Vect2D operator*(double lhs, Vect2D const& rhs);
Vect2D operator/(double lhs, Vect2D const& rhs);

std::ostream& operator<<(std::ostream& lhs, Vect2D const& rhs);




#endif // VECT2D_H