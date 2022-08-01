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
	m_grid.set(width, 20);
	m_window.addMouseMoveFunc(
		std::bind(&Application::mouseMoved, this, std::placeholders::_1)
	);
	// ??
	m_window.addMouseClickedFunc(
		std::bind(&Application::mouseClicked, this, std::placeholders::_1)
	);
	//--

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

void Application::createFrame()
{
	stageUpdate();
	draw();
}

void Application::draw()
{
	float x = 0.0f;
	m_window.clearScreen();
	m_grid.draw(m_window);
	ImGui::Begin("First Panel");
	ImGui::Text("Hello");
	if (ImGui::Button("Click Me")) {
		///
	}
	ImGui::SliderFloat(" : X", &x, -10, 10);
	ImGui::End();
	m_window.showShape();
}

void Application::stageUpdate()
{
	m_window.update(m_timeOfFrame);
}

void Application::keyPressed(sf::Keyboard::Key key)
{
	//if (key == sf::Keyboard::Left || key == sf::Keyboard::A)
	//
	//if (key == sf::Keyboard::Right || key == sf::Keyboard::D)
	//
	//if (key == sf::Keyboard::Up || key == sf::Keyboard::W)

	//if (key == sf::Keyboard::Down || key == sf::Keyboard::S)
}

void Application::keyReleased(sf::Keyboard::Key key)
{
}

void Application::mouseMoved(sf::Event::MouseMoveEvent e)
{
}

void Application::mouseClicked(sf::Event::MouseButtonEvent e)
{
}