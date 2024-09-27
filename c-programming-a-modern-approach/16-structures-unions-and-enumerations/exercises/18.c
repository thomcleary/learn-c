/*
(a) Each square of a chessboard can hold one piece:
a pawn, knight, bishop, rook, queen or king,
or it may be empty.

Each piece is either black or white.

Define 2 enumerated types:
- Piece, which has seven possible values (one of which is empty)
- Color which has two
*/

typedef enum Piece
{
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
} Piece;

typedef enum Color
{
    BLACK,
    WHITE,
} Color;

/*
(b) Using the types from part (a),
define a structure type named Square that can store both the typ of piece and its color
*/

typedef struct Square
{
    Piece piece;
    Color color;
} Square;

/*
(c) Using the Square type from part (b),
declare an 8 x 8 array named board that can store the entire contents of a chessboard

(d) Add an initializer to the declaration in part (c) so that that board's initial value corresponds
to the usual arrangement of pices at the start of a chess game.
A sqaure that's not occupied by a piece should have an empty piece value and the color black
*/

Square chessboard[8][8] = {
    {
        {ROOK, WHITE},
        {KNIGHT, WHITE},
        {BISHOP, WHITE},
        {QUEEN, WHITE},
        {KING, WHITE},
        {BISHOP, WHITE},
        {KNIGHT, WHITE},
        {ROOK, WHITE},
    },
    {
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
    },
    {
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
    },
    {
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
    },
    {
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
    },
    {
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
    },
    {
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
    },
    {
        {ROOK, BLACK},
        {KNIGHT, BLACK},
        {BISHOP, BLACK},
        {QUEEN, BLACK},
        {KING, BLACK},
        {BISHOP, BLACK},
        {KNIGHT, BLACK},
        {ROOK, BLACK},
    }};
