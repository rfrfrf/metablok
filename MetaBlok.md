# MetaBlok #



# Introduction #

The goal of this project is to develop an effective AI player for the board game Blokus. Blokus is a purely deterministic strategy game released in 2000 by Bernard Tavitian. The project was originally started as a class project for an Introductory AI course at the University of Minnesota and was moved here for continued development.

# Rules #

In the beginning of the game, all players receive the same set of pieces. These consist of 1 to 5 tile polyominoes of a given color in every possible configuration. Players take turns placing these pieces onto a 14x14 or 20x20 grid, abiding by the following set of guidelines:

  * Each player's first piece must cover a specified starting tile, which varies depending on the mode of play.
  * Each subsequent piece placed on the board must be placed in such a way that:
    1. No two pieces of the same color share a common edge
    1. Each piece must touch another piece of the same color along one or more of its corners
    1. No two pieces of any color may overlap on the board

Players take turns placing pieces, skipping turns only if required, until no player has a legal move available.

The game is ruled based on score. Every covered tile on the board increases the a player's score by 1, but additional bonus points can be achieved by placing all 21 pieces of one color (+15 points) or placing all 21 pieces and playing the monomino on the last move (+20 points). The player, or in cooperative games the team, with the highest score wins the game. This is the standard rule format used for online play and while other sources give slightly different scoring models this does not affect the overall outcome (winner) of the match.

# AI Players #

There are currently 4 AI players which feature several different playing techniques. Information on the implementation of these players is available on the respective wiki pages:

  * [RandomPlayer](RandomPlayer.md)
  * [MinimaxPlayer](MinimaxPlayer.md)
  * [BeamPlayer](BeamPlayer.md)
  * [MontePlayer](MontePlayer.md)

# Playing Strategies #

Several playing strategies have been formulated as an aid in developing AI players. These strategies represent the most common elements of play which are emphasized by the AI player board evaluation heuristics.

## Formations ##

Developing stable piece formations on the board throughout game play is one of the most important principles of Blokus. Particularly in closed matches, a stable formation allows the player to prevent leaks and reduce the other players access to the holes which inevitably develop during the placement of certain pieces. Often times it is even better to cede territory to the other player in an effort to make a piece placement which better maintains the stability of a formation, such as in the situation depicted in figure 1. It is clear that Red could best expand their territory by attempting to cover the two liberties in the third row created by Blue's N5 piece. A greedy attempt to do so however would leave Red's liberty in row 5 open. This would enable Blue to use its next turn to take advantage of the leak at ( 11, 5 ) to destabilize Red's formation. A better move

> Figure 1: Stable Formation

would be to use Red's W5 or N5 piece to cover both of the Red liberties and the rightmost
Blue liberty, closing the potential leak at ( 11, 5 ) while still expanding Red's territory.

## Blocking ##

In Blokus Duo, oensive play is key to establishing a large territory. Even more so for Red during the opening play, restricting mobility for the other player by blocking moves prevents them from establishing large territories without risking the stability of their formations. Selecting moves which prevent the other player from blocking forward liberties is also key to expanding one's territory. By establishing a formation far enough from enemy liberties, a player can ensure the availability of forward liberties at a location on subsequent turns.

> Figure 2: WF Opening

A classic example of this principle appears in the uncommon W opening depicted in figure 2. Although it may appear to be a strong move to novice players, Blue's only forward liberty can be easily blocked. Red can place the F5 piece, establishing forward liberties for development on each side of the W5 while blocking Blue's forward mobility.

## Leaks ##

Preventing leaks in a Blokus game is essential to maintaining a good board formation. Leaks establish enemy forays into otherwise stable regions of player territory. On the other hand, advancing leaks into the other players territory provides an excellent opportunity to delay their development while acquiring territory. Except in open play, where leaks are a common occurrence, most well played games will feature none to 1 or 2 leaks per player. Instead, potential leaks are a factor in piece placement decisions for both players. An opening leak can easily sway the outcome the game, perhaps more so than any other common board
formation.

## Holes ##

Holes are a consideration in Blokus matches primarily because of their endgame value. A hole which contains on of its players liberties and is of sufficient size to accommodate a piece which provides an automatic endgame placement opportunity. A player might take into consideration the
holes created by their own pieces as they play to prevent "chaining", or series of connected
holes which provide a large number of placement opportunities for the other player. Certain pieces such as the long I pieces create large holes by design and are often played making considerations for the accessibility of their holes to the opponent.

# Terminology #

Due to the lack of widespread Blokus research, there are as of yet few localized terminology sets for the game Blokus. We define several terms here to serve both as an aid in communication of game concepts and as a database of recommended terminology for developer documentation.

**Square** One of the 196 to 400 locations on the game grid. These are often classied based on their characteristics, such as a 'covered' or 'free' square. They are indexed using a tuple ( x, y ) specifying the number of tiles to the right and down from the top left corner of the grid in standard orientation.

**Covered** A property of a Square. A square is said to be covered for a given player if it is covered by a section of a polyominoe belonging to the given player. A square is simply said to be covered if it is covered by either player.

**Free** A property of a Square. A square is said to be free for a given player if it is not covered and is not directly adjacent to a square covered by the specified player.

**Liberty** A property of a Square. A square is said to be a liberty of a specified player if it is diagonally adjacent to another square covered by the same player. Additionally, a square which is not free for a given player cannot be a liberty for that player. Liberties are categorized based on how they are positioned. Liberties of a given player which are covered by that player to their lower left for example have the LL quality. This applies to each cardinal diagonal: Upper Right (UR), Upper Left (UL), Lower Left (LL), Lower Right (LR).

**Dead Liberty** A property of a Liberty. A liberty is said to be dead if there are no valid moves which can be made by the owning player that would cover the liberty.

**Fighting Liberty** A property of a Liberty. A liberty is said to be fighting if there is a connected set of less than a specified number of squares which are not covered and form a path between the given liberty and any liberty owned by another team's player.

**Territory** A set of squares on the game board characterized by being more in the control of one player than the other. Often times characterized by a wall of one player's pieces preventing placement of the other players pieces in the opposite region of the board.

**Hand** A player's hand is the set of available polyominoes which have not already been placed on the board by the player.

**Leak** A property of a Liberty. A liberty is said to be a leak if it is located in a tile which would otherwise be considered within the other players territory. This typically involves the liberties source tile being bordered on the two closest sides by colors owned by other teams or players.

**Hole** A collection of adjacent squares free for a given player but not free for the other player. This collection of squares must be accessible to the player and must denote a region of the board upon which a piece remaining in the players hand may be played in a valid configuration.

**Leak Hole** A Leak which is a members of a set of squares which falls within the definition of a hole. These denote sets of tiles in the other players territory which have been made available to the player through a leak.

**Open Play** A form of gameplay featuring a distinct and unusually high incidence rate of leaks for both players. This form of play more commonly develops in amateur or one sided matches where players develop structures on the game board which are prone to leaks.

**Closed Play** A form of gameplay featuring a few or no leaks by either player. The goal of such matches is to develop territories outward from existing territory in order to close o the largest possible region of the board from the other player.

**Half-Open** A form of gameplay which may ambiguously fall under the definitions of open and closed play. There may be one or two leaks per player but the underlying structures on the board form relatively well-developed territories.