# drone-agricole
# Agricultural Drone Simulation (DroneAgricole)

A C++ implementation of an agricultural drone system for automated field monitoring and analysis.

## 📋 Project Overview

This project simulates an agricultural drone capable of:
- Monitoring crop health in a 5x5 agricultural field
- Measuring soil humidity levels
- Detecting diseased plants
- Performing systematic field traversal using boustrophedon (zigzag) patterns
- Cross-line scanning for detailed analysis

## 🚀 Features

- **Field Monitoring**: Real-time analysis of plant health and soil conditions
- **Smart Navigation**: Multiple traversal patterns including:
  - Boustrophedon (zigzag) complete field coverage
  - Cross-line alternating pattern for detailed scanning
- **Data Collection**: Automated counting of diseased plants
- **Random Field Generation**: Simulates realistic field conditions
- **Professional C++ Structure**: Separated header and implementation files

## 📁 Project Structure

```
drone-agricole/
├── README.md              # Project documentation
├── DroneAgricole.h        # Class declaration and interface
├── DroneAgricole.cpp      # Class implementation
├── main.cpp              # Main program and testing functions
└── Makefile              # Build automation (optional)
```

## 🛠️ Compilation and Usage

### Prerequisites
- C++ compiler supporting C++11 or later (g++, clang++)
- Standard C++ libraries

### Quick Start
```bash
# Clone the repository
git clone https://github.com/Mohamed-FARHAOUI/drone-agricole.git
cd drone-agricole

# Compile the project
g++ -std=c++11 -Wall -o drone main.cpp DroneAgricole.cpp

# Run the simulation
./drone
```

### Alternative Compilation Methods

**Method 1: Single command**
```bash
g++ -std=c++11 -Wall -o drone main.cpp DroneAgricole.cpp
```

**Method 2: Separate compilation**
```bash
g++ -std=c++11 -Wall -c DroneAgricole.cpp  # Creates DroneAgricole.o
g++ -std=c++11 -Wall -c main.cpp           # Creates main.o
g++ -o drone main.o DroneAgricole.o        # Link object files
```

**Method 3: Using Makefile (if provided)**
```bash
make          # Compile
make clean    # Clean object files
```

## 🎮 How to Use

1. **Run the program**: `./drone`
2. **Select monitoring line**: Enter a number between 0-3 for the primary surveillance line
3. **View results**: The drone will:
   - Display the current field conditions
   - Perform cross-line scanning
   - Execute complete field traversal
   - Report total diseased plants found

### Sample Output
```
=== Test du Drone Agricole ===
Entrez la ligne principale que le drone devra surveiller (0-3): 2

=== État du champ ===
Humidité du sol:
 45  78  23  91  56 
 67  12  89  34  77 
 ...

=== Parcours ligne croisée (ligne 2) ===
Position (2,0) - Humidité: 67% - Plante: Saine
...

=== Résultat final ===
Nombre total de plantes malades dans la parcelle: 8
```

## 🏗️ Class Architecture

### DroneAgricole Class
- **Private Members**:
  - `nom`: Drone identifier
  - `x, y`: Current position coordinates
  - `ligneChoisie`: Selected surveillance line
  - `humidite[5][5]`: Static humidity matrix (0-100%)
  - `etatPlante[5][5]`: Static plant health matrix
  - `champInitialise`: Field initialization flag

- **Key Methods**:
  - `initialiserChamp()`: Generates random field data
  - `deplacer(int i, int j)`: Moves drone to specified position
  - `analyserCase()`: Analyzes current position
  - `parcourirParcelleCompleteBoustrophedon()`: Complete zigzag traversal
  - `parcourirLigneCroisee()`: Alternating line pattern
  - `compterPlantesMalades()`: Counts diseased plants

## 🔬 Technical Details

- **Field Size**: Fixed 5x5 grid representing agricultural parcels
- **Data Types**: 
  - Humidity: Integer values 0-100 (percentage)
  - Plant Health: Boolean (true=healthy, false=diseased)
- **Navigation Patterns**:
  - **Boustrophedon**: Alternating left-to-right and right-to-left traversal
  - **Cross-line**: Alternates between primary line and adjacent line
- **Memory Management**: Dynamic allocation with proper cleanup

## 🎯 Educational Objectives

This project demonstrates:
- Object-oriented programming principles in C++
- Static class members and methods
- Dynamic memory allocation
- File organization and professional project structure
- Algorithm implementation (traversal patterns)
- Real-world application simulation

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

Created as part of a C++ programming course focusing on object-oriented design and agricultural technology simulation.

## 🐛 Known Issues

- Field size is currently fixed at 5x5 (future enhancement: configurable size)
- Drone movement validation could be enhanced with boundary checking
- Consider adding more sophisticated plant disease modeling

## 🚀 Future Enhancements

- [ ] Configurable field dimensions
- [ ] Multiple drone coordination
- [ ] Advanced pathfinding algorithms
- [ ] GUI interface for visualization
- [ ] Data export functionality
- [ ] Weather condition simulation
- [ ] Crop type differentiation

---

**Happy coding! 🌾🚁**
