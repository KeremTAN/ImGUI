#include"Application.hpp"
#include<iostream>
#include"DrawableShapes.hpp"
#include "imgui.h"
#include <imgui-SFML.h>


Application::Application()
{

}

void Application::built(const int& width, const int& height)
{
	m_window.createWindow(width, height, "SFML");
	m_stage.start();
	m_grid.start();
	m_grid.set(width, 20);

	m_window.addMouseMoveFunc(
		std::bind(&Application::mouseMoved, this, std::placeholders::_1)
	);

	// ??
	m_window.addMouseClickedFunc(
		std::bind(&Application::mouseClicked, this, std::placeholders::_1)
	);
	//--

	m_window.addMouseReleasedFunc(
		std::bind(&Application::mouseReleased, this, std::placeholders::_1)
	);

	m_window.addKeyPressFunc(
		std::bind(&Application::keyPressed, this, std::placeholders::_1)
	);
	m_window.addKeyReleaseFunc(
		std::bind(&Application::keyReleased, this, std::placeholders::_1)
	);
}

void Application::start(int fps)
{
	float tmpFps = 1.0f / fps;
	m_timeOfFrame = sf::seconds(tmpFps);

	m_passingTime = m_clock.restart();
	while (m_window.isOpen())
	{
		m_window.processEvent();
		m_passingTime += m_clock.getElapsedTime();
		if (m_passingTime >= m_timeOfFrame)
		{
			createFrame();
			m_passingTime = m_passingTime - m_timeOfFrame;
			m_clock.restart();
		}
		else {
			sf::sleep(m_passingTime - m_timeOfFrame);
		}
	}
	m_window.close();
}

void Application::drawGuiPanel()
{
}

void Application::createFrame()
{
	stageUpdate();
	draw();
}

void Application::draw()
{
	m_window.clearScreen();
	m_grid.draw(m_window);
	m_stage.draw(m_window);

	drawGuiPanel();

	m_window.showShape();
}

void Application::stageUpdate()
{
	m_stage.update(m_timeOfFrame);
	m_grid.update(m_timeOfFrame);
	m_window.update(m_timeOfFrame);
}

void Application::keyPressed(sf::Keyboard::Key key)
{
	//if (key == sf::Keyboard::Left || key == sf::Keyboard::A)

	//if (key == sf::Keyboard::Right || key == sf::Keyboard::D)

	//if (key == sf::Keyboard::Up || key == sf::Keyboard::W)

	//if (key == sf::Keyboard::Down || key == sf::Keyboard::S)
}

void Application::keyReleased(sf::Keyboard::Key key)
{
}

void Application::mouseMoved(sf::Event::MouseMoveEvent e)
{
	m_stage.setCircleLastPosition((sf::Vector2f(e.x, e.y)));
}

void Application::mouseClicked(sf::Event::MouseButtonEvent e)
{
	m_stage.setCircleOrigin(sf::Vector2f(e.x,e.y));
}

void Application::mouseReleased(sf::Event::MouseButtonEvent e)
{
	m_stage.isCircleFinished(true);
}
