#include "Draw.h"

Draw::~Draw() {

}

void Draw::TurnTo(double direction) {
	setDirection(direction);
}

void Draw::TurnBy(double direction) {
	setDirection(Direction + direction);
}


void Draw::MoveTo(int x, int y) {
	setX(x);
	setY(y);
}

void Draw::MoveBy(int distance) {
	setX(getX() + getXComponent(distance));
	setY(getY() + getYComponent(distance));
}

void Draw::DrawTo(SDL_Renderer* &renderer, int x, int y) {
	SDL_RenderDrawLine(renderer, getX(), getY(), x, y);
	setX(x);
	setY(y);
	SDL_RenderPresent(renderer);
}

void Draw::DrawBy(SDL_Renderer* &renderer, int distance) {
	SDL_RenderDrawLine(renderer, getX(), getY(), X + getXComponent(distance), Y + getYComponent(distance));
	setX(X + getXComponent(distance));
	setY(Y + getYComponent(distance));
	SDL_RenderPresent(renderer);
}

int Draw::getX() {
	return X;
}

void Draw::setX(int x) {
	this->X = x;
}

int Draw::getY() {
	return Y;
}

void Draw::setY(int y) {
	this->Y = y;
}

int Draw::getXComponent(int distance) {
	return distance * cos(getDirection() * PI / 180.0);
}

int Draw::getYComponent(int distance) {
	return distance * sin(getDirection() * PI / 180.0);
}

int Draw::getDirection() {
	return Direction;
}

void Draw::setDirection(double direction) {
//	this->Direction += fmod(direction, 360);
}
