# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\cydia2001\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.6397.106\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\cydia2001\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.6397.106\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\backup\opengl-learning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\backup\opengl-learning\cmake-build-debug

# Include any dependencies generated for this target.
include shader\CMakeFiles\ShaderFunc.dir\depend.make

# Include the progress variables for this target.
include shader\CMakeFiles\ShaderFunc.dir\progress.make

# Include the compile flags for this target's objects.
include shader\CMakeFiles\ShaderFunc.dir\flags.make

shader\CMakeFiles\ShaderFunc.dir\shader.cpp.obj: shader\CMakeFiles\ShaderFunc.dir\flags.make
shader\CMakeFiles\ShaderFunc.dir\shader.cpp.obj: ..\shader\shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\backup\opengl-learning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object shader/CMakeFiles/ShaderFunc.dir/shader.cpp.obj"
	cd E:\backup\opengl-learning\cmake-build-debug\shader
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ShaderFunc.dir\shader.cpp.obj /FdCMakeFiles\ShaderFunc.dir\ShaderFunc.pdb /FS -c E:\backup\opengl-learning\shader\shader.cpp
<<
	cd E:\backup\opengl-learning\cmake-build-debug

shader\CMakeFiles\ShaderFunc.dir\shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ShaderFunc.dir/shader.cpp.i"
	cd E:\backup\opengl-learning\cmake-build-debug\shader
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\ShaderFunc.dir\shader.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\backup\opengl-learning\shader\shader.cpp
<<
	cd E:\backup\opengl-learning\cmake-build-debug

shader\CMakeFiles\ShaderFunc.dir\shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ShaderFunc.dir/shader.cpp.s"
	cd E:\backup\opengl-learning\cmake-build-debug\shader
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ShaderFunc.dir\shader.cpp.s /c E:\backup\opengl-learning\shader\shader.cpp
<<
	cd E:\backup\opengl-learning\cmake-build-debug

# Object files for target ShaderFunc
ShaderFunc_OBJECTS = \
"CMakeFiles\ShaderFunc.dir\shader.cpp.obj"

# External object files for target ShaderFunc
ShaderFunc_EXTERNAL_OBJECTS =

shader\ShaderFunc.lib: shader\CMakeFiles\ShaderFunc.dir\shader.cpp.obj
shader\ShaderFunc.lib: shader\CMakeFiles\ShaderFunc.dir\build.make
shader\ShaderFunc.lib: shader\CMakeFiles\ShaderFunc.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\backup\opengl-learning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ShaderFunc.lib"
	cd E:\backup\opengl-learning\cmake-build-debug\shader
	$(CMAKE_COMMAND) -P CMakeFiles\ShaderFunc.dir\cmake_clean_target.cmake
	cd E:\backup\opengl-learning\cmake-build-debug
	cd E:\backup\opengl-learning\cmake-build-debug\shader
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /lib /nologo /machine:X86 /out:ShaderFunc.lib @CMakeFiles\ShaderFunc.dir\objects1.rsp 
	cd E:\backup\opengl-learning\cmake-build-debug

# Rule to build all files generated by this target.
shader\CMakeFiles\ShaderFunc.dir\build: shader\ShaderFunc.lib

.PHONY : shader\CMakeFiles\ShaderFunc.dir\build

shader\CMakeFiles\ShaderFunc.dir\clean:
	cd E:\backup\opengl-learning\cmake-build-debug\shader
	$(CMAKE_COMMAND) -P CMakeFiles\ShaderFunc.dir\cmake_clean.cmake
	cd E:\backup\opengl-learning\cmake-build-debug
.PHONY : shader\CMakeFiles\ShaderFunc.dir\clean

shader\CMakeFiles\ShaderFunc.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\backup\opengl-learning E:\backup\opengl-learning\shader E:\backup\opengl-learning\cmake-build-debug E:\backup\opengl-learning\cmake-build-debug\shader E:\backup\opengl-learning\cmake-build-debug\shader\CMakeFiles\ShaderFunc.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : shader\CMakeFiles\ShaderFunc.dir\depend
