/* ===========================================================================

	Project: MetaBlok - NetworkSetup

	Description: Networked match waiting screen and settings options menu.

    Copyright (C) 2011 Lucas Sherman

	Lucas Sherman, email: LucasASherman@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

=========================================================================== */

// Begin definition
#ifndef NETWORK_SETUP_H
#define NETWORK_SETUP_H

// Splash screen
class NetworkSetup : public DirectX::GameState
{
public:
	// Privatized Construction
	NetworkSetup( ) { m_state = WAITING; }

	// Primary methods
	void startup( );
	void shutdown( );

	// DirectX controller functions
	void onKeyboardEvent( UINT message, WPARAM wParam, LPARAM lParam ) { }
	void onGuiEvent( DirectX::GUI::Control* control, unsigned int message, void* data );
	void onMouseEvent( UINT message, WPARAM wParam, LPARAM lParam ) { }
	void onDeviceReset( );

	// Message passing interface
	void messagePump( UINT message, WPARAM wParam, LPARAM lParam );

private:
	// Graphics manager
	DirectX::Manager* m_manager;

	// User interface display panel
	DirectX::GUI::WindowStyle* m_style;
	DirectX::GUI::DisplayPanel* m_displayPanel;

	// Backdrop graphic
	DirectX::Image m_backdropImg;
	DirectX::GUI::Graphic* m_backdrop;

	// Player selection combo boxes
	DirectX::GUI::ComboBox* m_players[4];

	// Blokus variant selection
	// :TODO:

	// Primary button panel
	DirectX::GUI::Button* m_buttonCancel;
	DirectX::GUI::Button* m_buttonServer;
	DirectX::GUI::Button* m_buttonConnect;
	DirectX::GUI::Button* m_buttonStart;

	// Network connection handles
	//Connection m_clientConnections[4];
	//Connection m_serverConnection;
	//bool m_isHost;
};

// End definition
#endif