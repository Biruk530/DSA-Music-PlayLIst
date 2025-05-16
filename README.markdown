### Playlist Manager

## Overview

The Playlist Manager is a console-based application designed to manage and play music playlists. It provides essential functionality for creating, modifying, and navigating through song collections with features like adding songs, playback control, shuffling, and repeat mode.

## Table of Contents

- How It Works
- Why It's Needed
- Features
- Implementation Details
- Pros and Cons
- Installation
- Usage
- Future Improvements
- Contributing
- License

## How It Works

The application uses a doubly-linked list data structure to manage the playlist, allowing efficient traversal in both directions (forward and backward). Songs are persistently stored in a text file (`playlist.txt`) using a pipe-delimited format. The program loads this file at startup and saves changes automatically when modifications are made.

Key components:

- **Data Storage**: Songs are stored with unique IDs, titles, and artists
- **Navigation**: Users can move forward/backward through the playlist
- **Playback Modes**: Includes normal and repeat modes
- **Shuffling**: Randomizes song order using Fisher-Yates algorithm

## Why It's Needed

This project addresses several needs:

1. **Simple Playlist Management**: Provides basic CRUD operations for songs
2. **Offline Functionality**: Works without internet connection
3. **Lightweight Solution**: Minimal resource requirements compared to GUI applications
4. **Educational Value**: Demonstrates fundamental data structures and file I/O operations

## Features

- **Song Management**:
  - Add single or multiple songs
  - Automatic ID generation
  - Persistent storage
- **Playback Control**:
  - Play next/previous songs
  - Repeat mode toggle
- **Playlist Operations**:
  - View entire playlist
  - Shuffle songs
- **User Interface**:
  - Console-based menu system
  - Clear status messages

## Implementation Details

### Data Structures

- **Doubly-Linked List**: Used for storing and navigating songs
  - `Node` struct contains pointers to previous and next nodes
  - Global `head`, `tail`, and `current` pointers for list management

### Algorithms

- **Fisher-Yates Shuffle**: For randomizing playlist order
- **Linear Search**: For finding nodes during operations

### File Handling

- **Format**: Pipe-delimited text (ID|Title|Artist)
- **Operations**:
  - Automatic loading at startup
  - Automatic saving after modifications

### Memory Management

- Dynamic allocation for songs and nodes
- Proper cleanup on program exit

## Pros and Cons

### Advantages

1. **Efficient Navigation**: Doubly-linked list allows O(1) next/previous operations
2. **Persistent Storage**: Playlist survives between program runs
3. **Simple Interface**: Easy-to-use console menu
4. **Lightweight**: Minimal dependencies and resource usage
5. **Modular Design**: Components can be easily extended

### Limitations

1. **Console-Based**: No graphical interface
2. **Basic Features**: Lacks advanced functionality like searching or deleting songs
3. **No Error Handling**: Minimal input validation
4. **Fixed File Format**: Uses simple text file without versioning
5. **Global Variables**: Uses global state which may complicate scaling

## Installation

### Requirements

- C++ compiler (g++ recommended)
- Standard Library support
- POSIX-compliant system (for file operations)

### Steps

1. Clone the repository or download source files
2. Compile all components:

   ```bash
   g++ playlist_io.cpp playlist_display.cpp playlist_add.cpp playlist_playback.cpp playlist_shuffle.cpp main.cpp -o playlist_manager
   ```
3. Run the executable:

   ```bash
   ./playlist_manager
   ```

## Usage

1. **Starting Up**: The program automatically loads `playlist.txt` if it exists
2. **Main Menu**:

   ```
   1. Add Single Song
   2. Add Multiple Songs
   3. Play Next
   4. Play Previous
   5. Show Playlist
   6. Shuffle
   7. Toggle Repeat
   8. Exit
   ```
3. **Adding Songs**: Follow prompts to enter title and artist
4. **Navigation**: Use options 3 and 4 to move through playlist
5. **Shuffling**: Randomizes song order while preserving current song
6. **Exiting**: Automatically saves changes to file

## Future Improvements

1. **Enhanced Features**:
   - Song deletion capability
   - Playlist searching/filtering
   - Playlist statistics (total duration, etc.)
2. **Improved UI**:
   - Color coding
   - More detailed playback information
3. **Advanced Functionality**:
   - Multiple playlists support
   - Import/export options
   - Sorting capabilities
4. **Technical Improvements**:
   - Error handling and input validation
   - Configuration options
   - Unit testing framework

## Contributing

Contributions are welcome! Please follow these guidelines:

1. Fork the repository
2. Create a feature branch
3. Submit a pull request with:
   - Clear description of changes
   - Updated documentation if needed
   - Appropriate test cases

## License

This project is licensed under the MIT License - see the LICENSE file for details.

---

**Note**: This is an educational project demonstrating fundamental programming concepts. It's not intended for production use without significant enhancements to error handling and security.
