/* ===========================================================================

	Project: MetaBlok

	Description: Simulates Blokus board game matches against AI players

    Copyright (C) 2011 Lucas Sherman, David Gloe, Mary Southern, Tobias Gulden

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

// Memory leak detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// Include game header
#include "MetaBlok.h"

// Application entry point
int CALLBACK WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	// Enable exit-time memory leak detection with c-runtime library
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	// Instance pointer to engine
	Shear::ShearManager* ShearEngine = Shear::ShearManager::instance( );

	// Initialize the shear engine
	ShearEngine->startUp( hInstance );

	// Initialize the state stack
	MainMenu* menu = new MainMenu( );
	ShearEngine->pushState( menu );

	// Initialize windows message
	MSG msg; PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE );

	// Main loop
	while( ShearEngine->isRunning( ) )
	{
		// Recieve windows messages
        while( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
			{ TranslateMessage(&msg); DispatchMessage(&msg); }

		// Perform engine processes
		ShearEngine->main( );
	}

	// Shutdown the engine
	ShearEngine->shutDown( );

	// Return to windows
	return 0;
}