# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build

# Include any dependencies generated for this target.
include CMakeFiles/exampleB1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/exampleB1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/exampleB1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exampleB1.dir/flags.make

CMakeFiles/exampleB1.dir/exampleB1.cc.o: CMakeFiles/exampleB1.dir/flags.make
CMakeFiles/exampleB1.dir/exampleB1.cc.o: ../exampleB1.cc
CMakeFiles/exampleB1.dir/exampleB1.cc.o: CMakeFiles/exampleB1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exampleB1.dir/exampleB1.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB1.dir/exampleB1.cc.o -MF CMakeFiles/exampleB1.dir/exampleB1.cc.o.d -o CMakeFiles/exampleB1.dir/exampleB1.cc.o -c /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/exampleB1.cc

CMakeFiles/exampleB1.dir/exampleB1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB1.dir/exampleB1.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/exampleB1.cc > CMakeFiles/exampleB1.dir/exampleB1.cc.i

CMakeFiles/exampleB1.dir/exampleB1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB1.dir/exampleB1.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/exampleB1.cc -o CMakeFiles/exampleB1.dir/exampleB1.cc.s

CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.o: CMakeFiles/exampleB1.dir/flags.make
CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.o: ../src/B1ActionInitialization.cc
CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.o: CMakeFiles/exampleB1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.o -MF CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.o.d -o CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.o -c /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1ActionInitialization.cc

CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1ActionInitialization.cc > CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.i

CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1ActionInitialization.cc -o CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.s

CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.o: CMakeFiles/exampleB1.dir/flags.make
CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.o: ../src/B1DetectorConstruction.cc
CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.o: CMakeFiles/exampleB1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.o -MF CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.o.d -o CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.o -c /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1DetectorConstruction.cc

CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1DetectorConstruction.cc > CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.i

CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1DetectorConstruction.cc -o CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.s

CMakeFiles/exampleB1.dir/src/B1EventAction.cc.o: CMakeFiles/exampleB1.dir/flags.make
CMakeFiles/exampleB1.dir/src/B1EventAction.cc.o: ../src/B1EventAction.cc
CMakeFiles/exampleB1.dir/src/B1EventAction.cc.o: CMakeFiles/exampleB1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/exampleB1.dir/src/B1EventAction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB1.dir/src/B1EventAction.cc.o -MF CMakeFiles/exampleB1.dir/src/B1EventAction.cc.o.d -o CMakeFiles/exampleB1.dir/src/B1EventAction.cc.o -c /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1EventAction.cc

CMakeFiles/exampleB1.dir/src/B1EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB1.dir/src/B1EventAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1EventAction.cc > CMakeFiles/exampleB1.dir/src/B1EventAction.cc.i

CMakeFiles/exampleB1.dir/src/B1EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB1.dir/src/B1EventAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1EventAction.cc -o CMakeFiles/exampleB1.dir/src/B1EventAction.cc.s

CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.o: CMakeFiles/exampleB1.dir/flags.make
CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.o: ../src/B1PrimaryGeneratorAction.cc
CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.o: CMakeFiles/exampleB1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.o -MF CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.o.d -o CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.o -c /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1PrimaryGeneratorAction.cc

CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1PrimaryGeneratorAction.cc > CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.i

CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1PrimaryGeneratorAction.cc -o CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.s

CMakeFiles/exampleB1.dir/src/B1RunAction.cc.o: CMakeFiles/exampleB1.dir/flags.make
CMakeFiles/exampleB1.dir/src/B1RunAction.cc.o: ../src/B1RunAction.cc
CMakeFiles/exampleB1.dir/src/B1RunAction.cc.o: CMakeFiles/exampleB1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/exampleB1.dir/src/B1RunAction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB1.dir/src/B1RunAction.cc.o -MF CMakeFiles/exampleB1.dir/src/B1RunAction.cc.o.d -o CMakeFiles/exampleB1.dir/src/B1RunAction.cc.o -c /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1RunAction.cc

CMakeFiles/exampleB1.dir/src/B1RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB1.dir/src/B1RunAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1RunAction.cc > CMakeFiles/exampleB1.dir/src/B1RunAction.cc.i

CMakeFiles/exampleB1.dir/src/B1RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB1.dir/src/B1RunAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1RunAction.cc -o CMakeFiles/exampleB1.dir/src/B1RunAction.cc.s

CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.o: CMakeFiles/exampleB1.dir/flags.make
CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.o: ../src/B1SteppingAction.cc
CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.o: CMakeFiles/exampleB1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.o -MF CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.o.d -o CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.o -c /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1SteppingAction.cc

CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1SteppingAction.cc > CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.i

CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/src/B1SteppingAction.cc -o CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.s

# Object files for target exampleB1
exampleB1_OBJECTS = \
"CMakeFiles/exampleB1.dir/exampleB1.cc.o" \
"CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.o" \
"CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.o" \
"CMakeFiles/exampleB1.dir/src/B1EventAction.cc.o" \
"CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.o" \
"CMakeFiles/exampleB1.dir/src/B1RunAction.cc.o" \
"CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.o"

# External object files for target exampleB1
exampleB1_EXTERNAL_OBJECTS =

exampleB1: CMakeFiles/exampleB1.dir/exampleB1.cc.o
exampleB1: CMakeFiles/exampleB1.dir/src/B1ActionInitialization.cc.o
exampleB1: CMakeFiles/exampleB1.dir/src/B1DetectorConstruction.cc.o
exampleB1: CMakeFiles/exampleB1.dir/src/B1EventAction.cc.o
exampleB1: CMakeFiles/exampleB1.dir/src/B1PrimaryGeneratorAction.cc.o
exampleB1: CMakeFiles/exampleB1.dir/src/B1RunAction.cc.o
exampleB1: CMakeFiles/exampleB1.dir/src/B1SteppingAction.cc.o
exampleB1: CMakeFiles/exampleB1.dir/build.make
exampleB1: /usr/lib/libG4Tree.so
exampleB1: /usr/lib/libG4FR.so
exampleB1: /usr/lib/libG4GMocren.so
exampleB1: /usr/lib/libG4visHepRep.so
exampleB1: /usr/lib/libG4RayTracer.so
exampleB1: /usr/lib/libG4VRML.so
exampleB1: /usr/lib/libG4OpenGL.so
exampleB1: /usr/lib/libG4OpenInventor.so
exampleB1: /usr/lib/libG4ToolsSG.so
exampleB1: /usr/lib/libG4vis_management.so
exampleB1: /usr/lib/libG4modeling.so
exampleB1: /usr/lib/libG4interfaces.so
exampleB1: /usr/lib/libG4persistency.so
exampleB1: /usr/lib/libG4error_propagation.so
exampleB1: /usr/lib/libG4readout.so
exampleB1: /usr/lib/libG4physicslists.so
exampleB1: /usr/lib/libG4tasking.so
exampleB1: /usr/lib/libG4parmodels.so
exampleB1: /usr/lib/libG4gl2ps.so
exampleB1: /usr/lib/libSoQt.so.1.6.0
exampleB1: /usr/lib/libCoin.so.4.0.1
exampleB1: /usr/lib/libOpenGL.so
exampleB1: /usr/lib/libGLX.so
exampleB1: /usr/lib/libSM.so
exampleB1: /usr/lib/libICE.so
exampleB1: /usr/lib/libX11.so
exampleB1: /usr/lib/libXext.so
exampleB1: /usr/lib/libXi.so
exampleB1: /usr/lib/libXmu.so
exampleB1: /usr/lib/libXext.so
exampleB1: /usr/lib/libXm.so
exampleB1: /usr/lib/libXt.so
exampleB1: /usr/lib/libICE.so
exampleB1: /usr/lib/libSM.so
exampleB1: /usr/lib/libX11.so
exampleB1: /usr/lib/libGL.so
exampleB1: /usr/lib/libQt5OpenGL.so.5.15.3
exampleB1: /usr/lib/libQt5PrintSupport.so.5.15.3
exampleB1: /usr/lib/libQt5Widgets.so.5.15.3
exampleB1: /usr/lib/libQt5Gui.so.5.15.3
exampleB1: /usr/lib/libQt5Core.so.5.15.3
exampleB1: /usr/lib/libxerces-c.so
exampleB1: /usr/lib/libG4run.so
exampleB1: /usr/lib/libG4event.so
exampleB1: /usr/lib/libG4tracking.so
exampleB1: /usr/lib/libG4processes.so
exampleB1: /usr/lib/libG4analysis.so
exampleB1: /usr/lib/libG4tools.so
exampleB1: /usr/lib/libz.so
exampleB1: /usr/lib/libexpat.so
exampleB1: /usr/lib/libG4digits_hits.so
exampleB1: /usr/lib/libG4track.so
exampleB1: /usr/lib/libG4particles.so
exampleB1: /usr/lib/libG4geometry.so
exampleB1: /usr/lib/libG4materials.so
exampleB1: /usr/lib/libG4graphics_reps.so
exampleB1: /usr/lib/libG4intercoms.so
exampleB1: /usr/lib/libG4global.so
exampleB1: /usr/lib/libG4clhep.so
exampleB1: /usr/lib/libG4ptl.so.0.0.2
exampleB1: CMakeFiles/exampleB1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable exampleB1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exampleB1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exampleB1.dir/build: exampleB1
.PHONY : CMakeFiles/exampleB1.dir/build

CMakeFiles/exampleB1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exampleB1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exampleB1.dir/clean

CMakeFiles/exampleB1.dir/depend:
	cd /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5 /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5 /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build /home/apricot/Documents/GraduationProject/Geant4Work/scatteringRate/initNum0409/7mud5/build/CMakeFiles/exampleB1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exampleB1.dir/depend

