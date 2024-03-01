# cub3D

Welcome to `cub3D`! This project is inspired by the 90's classic game "Wolfenstein 3D" and is designed to explore the technicalities of ray-casting. The program simulates a 3D walkthrough inside a maze, where you'll navigate through and experience the essence of graphical rendering.

## Project Overview

`cub3D` pays homage to the classic FPS genre and serves as a pedagogical challenge to delve into graphical design using ray-casting. The core objective is to render a dynamic 3D world from a two-dimensional map, offering an immersive player experience.

## Features

- Dynamic view inside a maze using ray-casting.
- Customizable map parsing from `.cub` configuration files.
- Texture mapping for walls based on their orientation.
- Configurable floor and ceiling colors.
- Smooth window management and event handling.

## Controls

- `W`, `A`, `S`, `D` for player movement.
- Left and Right Arrow keys for player rotation.
- `ESC` to exit the game.

## How to Run

Compile the program using the provided Makefile and then execute the binary with a `.cub` file as an argument:

```bash
make
./cub3D path/to/map.cub
```
## Configuration

The `.cub` file details the game's configuration, including map layout, textures, and color settings. The map should be enclosed by walls ('1') and use '0' for open spaces. Player's start position and orientation are denoted by 'N', 'S', 'E', or 'W'.

## Error Handling

Comprehensive error handling is included to ensure clarity and user-friendliness in case of configuration errors within the `.cub` file.

## Contribution

Contributions are welcome. Feel free to fork the project, push your changes, and submit a pull request.

## License

Distributed under the MIT License. See `LICENSE` for more information.
