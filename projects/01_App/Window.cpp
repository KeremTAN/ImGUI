#include "Window.hpp"
#include "imgui.h"
#include <imgui-SFML.h>

Window::Window()
{
}

void Window::createWindow(const unsigned int& width, const unsigned int& height, const sf::String& title) {
	window.create(sf::VideoMode(width, height), title);
	ImGui::SFML::Init(window);
	//window.setPosition({ 5,5 });
}

void Window::draw(sf::Drawable& shape)
{
	window.draw(shape);
}

void Window::processEvent() {
	sf::Event check;
	while (window.pollEvent(check))
	{
		ImGui::SFML::ProcessEvent(check);

		if (check.type == sf::Event::Closed)
			window.close();

		if (check.type == sf::Event::KeyPressed)
			for (const auto& keyFuncs : m_keyPressFuncList)
				keyFuncs(check.key.code);

		if (check.type == sf::Event::KeyReleased)
			for (const auto& keyFuncs : m_keyReleaseFuncList)
				keyFuncs(check.key.code);

		if (check.type == sf::Event::MouseMoved)
			for (const auto& mouseFuncs : m_mouseMoveFuncList)
				mouseFuncs(check.mouseMove);

		if (check.type == sf::Event::MouseButtonReleased)
			for (const auto& mouseFuncs : m_mouseReleasedFuncList)
				mouseFuncs(check.mouseButton);

		if (check.type == sf::Event::MouseButtonPressed)
			for (const auto& mouseFuncs : m_mouseClickFuncList)
				mouseFuncs(check.mouseButton);
	}
}

void Window::close()
{
	if(window.isOpen())
		window.close();

	ImGui::SFML::Shutdown();

}

bool Window::isOpen()
{
	return window.isOpen();
}

void Window::clearScreen()
{
	window.clear();
}

void Window::showShape()
{
	ImGui::SFML::Render(window);
	window.display();
}

void Window::update(const sf::Time& dt)
{
	ImGui::SFML::Update(window, dt);
}

void Window::addKeyPressFunc(KeyboardFunction newFunction)
{
	m_keyPressFuncList.push_back(newFunction);
}

void Window::addKeyReleaseFunc(KeyboardFunction newFunction)
{
	m_keyReleaseFuncList.push_back(newFunction);
}

void Window::addMouseMoveFunc(MouseMove newFunction)
{
	m_mouseMoveFuncList.push_back(newFunction);
}

void Window::addMouseClickedFunc(MouseClick newFunction)
{
	m_mouseClickFuncList.push_back(newFunction);
}

void Window::addMouseReleasedFunc(MouseClick newFunction)
{
	m_mouseReleasedFuncList.push_back(newFunction);
}

void Window::setTitle(const int& score)
{
	sf::String info = "Your Score : " + std::to_string(score);
	window.setTitle(info);
}
