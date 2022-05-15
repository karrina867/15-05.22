#include "game.h"
#include "sattings.h"
Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE),
	p1{ new Platform(0,WINDOW_HEIGHT - 50.f, WINDOW_WIDTH, 50.f) },
	p2{ new Platform(0,WINDOW_HEIGHT * 2 / 3,WINDOW_WIDTH / 3,50.f) },
	p3{ new Platform(WINDOW_WIDTH*2 /3, WINDOW_HEIGHT / 3, WINDOW_WIDTH / 3, 50.f) }
{
	window.setFramerateLimit(FPS);
	size_t desktop_width = sf::VideoMode::getDesktopMode().width;
	window.setPosition(sf::Vector2i((desktop_width - WINDOW_WIDTH) / 2, 0));
	platforms.push_bask
}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}
void  Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
	}
	
}
void Game::update() {
	player.update();
	for (auto it = platforms.begin(); it != platforms.end(); it++) {
		(*it)->update();
}
}
void Game::draw() {
	window.clear();
	player.draw(window);
	window.display();
	for (auto it = platforms.begin(); it != platforms.end(); it++) {
		(*it)->draw();
	}
}
void Game::check_collisions() {
	if(player.getSpeed().y >0)
		for(auto it = platforms.begin)
	if (player.getHitBox().intersects(p1.getHitBox())) {
		player.resetVerticalSpeed();
		player.setVerticalPosition(p1.getPosition().y - player.getHitBox().height);
		player.resetIsJump();
	}
	if (player.getHitBox().intersects(p2.getHitBox())) {
		player.resetVerticalSpeed();
		player.setVerticalPosition(p2.getPosition().y - player.getHitBox().height);
		player.resetIsJump();
	}
}