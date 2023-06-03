#include "Vect2D.h"

Vect2D::Vect2D()
	: Vect2D( 0.0, 0.0)
{
}

Vect2D::Vect2D(double x, double y)
	: mX{ x }
	, mY{ y }
{
}

Vect2D::~Vect2D()
{
	// ne fait rien
}

double Vect2D::x() const
{
	return this->mX; // explicite
}

double Vect2D::y() const
{
	return mY; // implicite ***
}

void Vect2D::setX(double x)
{
	mX = x;
}

void Vect2D::setY(double y)
{
	mY = y;
}

void Vect2D::set(double x, double y)
{
	this->setX(x); // explicite
	setY(y); // implicite ***
}

double Vect2D::dot(Vect2D const& other) const
{
	return mX * other.mX + mY * other.mY;
}

bool Vect2D::operator==(Vect2D const & rhs) const
{
	return mX == rhs.mX && mY == rhs.mY;
}

bool Vect2D::operator!=(Vect2D const& rhs) const
{
	return !(*this == rhs);
	//return !operator==(other);
	//return mX != other.mX || mY != other.mY;
}

Vect2D Vect2D::operator+(Vect2D rhs) const
{
	rhs.mX += mX;
	rhs.mY += mY;
	return rhs;
}

Vect2D Vect2D::operator-(Vect2D rhs) const
{
	rhs.mX = mX - rhs.mX;
	rhs.mY = mY - rhs.mY;
	return rhs;
}

Vect2D Vect2D::operator-() const
{
	return Vect2D(-mX, -mY);
}

Vect2D Vect2D::operator*(double rhs) const
{
	return Vect2D(mX * rhs, mY * rhs);
}

Vect2D Vect2D::operator/(double rhs) const
{
	return Vect2D(mX / rhs, mY / rhs);
}

Vect2D& Vect2D::operator+=(Vect2D const& rhs)
{
	mX += rhs.mX;
	mY += rhs.mY;
	return *this;
}

Vect2D& Vect2D::operator-=(Vect2D const& rhs)
{
	mX -= rhs.mX;
	mY -= rhs.mY;
	return *this;
}

Vect2D& Vect2D::operator*=(double rhs)
{
	mX *= rhs;
	mY *= rhs;
	return *this;
}

Vect2D& Vect2D::operator/=(double rhs)
{
	mX /= rhs;
	mY /= rhs;
	return *this;
}

Vect2D operator*(double lhs, Vect2D const& rhs)
{
	return rhs * lhs;
}

Vect2D operator/(double lhs, Vect2D const & rhs)
{
	return Vect2D(lhs / rhs.mX, lhs / rhs.mY);
}

std::ostream& operator<<(std::ostream& lhs, Vect2D const& rhs)
{
	lhs << "(" << rhs.mX << ", " << rhs.mY << ")";
	return lhs;
}
