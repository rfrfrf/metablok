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

// Standard includes
#include "MetaBlok.h"

// Include header
#include "NetworkSetup.h"

// DirectX GUI controls
using namespace DirectX::GUI;

// --------------------------------------------------------
//	Creates the GUI display panel and associated resources.
// --------------------------------------------------------
void NetworkSetup::startup( )
{	
	// Grab handle to manager object
	m_manager = DirectX::Manager::instance( );

	// Register this object as a controller
	m_manager->addController( this );

	// Load background sprite
	m_backdropImg.create( L"Images/Menu.bmp" );

	// Get default window style from engine
	m_style = DirectX::EngineManager::instance( )->getWindowStyle( );

	// Create user interface display panel
	m_displayPanel = &DisplayPanel::create( ).size( 1024, 768 );

	// Create backdrop graphic
	int sh = m_manager->getDisplayHeight( ); int sw = sh * 4 / 3;
	int px = ( m_manager->getDisplayWidth( ) - sw ) / 2;
	m_backdrop = &Graphic::create( &m_backdropImg, m_displayPanel )
		.size( sw, sh ).pos( px, 0 );

	// Proceed to run
	m_state = RUNNING;
}
// 
// --------------------------------------------------------
//  Repositions GUI elements when the screen dimensions 
//  are changed.
// --------------------------------------------------------
void NetworkSetup::onDeviceReset( )
{
	// Update background graphic position
	int sh = m_manager->getDisplayHeight( ); int sw = sh * 4 / 3;
	int px = ( m_manager->getDisplayWidth( ) - sw ) / 2;
	m_backdrop->size( sw, sh ).pos( px, 0 );
}
//
// --------------------------------------------------------
//  Handle state changes on menu button selection.
// --------------------------------------------------------
void NetworkSetup::onGuiEvent( DirectX::GUI::Control* control, unsigned int message, void* data )
{
}
//
// --------------------------------------------------------
//	Deletes the GUI panel and releases graphics resources.
// --------------------------------------------------------
void NetworkSetup::shutdown( )
{
	// Delete GUI panel
	delete m_displayPanel;

	// Delete this object as a controller
	m_manager->deleteController( this );

	// Release images
	m_backdropImg.release( );
}