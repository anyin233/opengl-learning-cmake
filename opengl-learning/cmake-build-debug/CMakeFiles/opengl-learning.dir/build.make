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
include CMakeFiles\opengl-learning.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\opengl-learning.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\opengl-learning.dir\flags.make

CMakeFiles\opengl-learning.dir\main.cpp.obj: CMakeFiles\opengl-learning.dir\flags.make
CMakeFiles\opengl-learning.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\backup\opengl-learning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opengl-learning.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\opengl-learning.dir\main.cpp.obj /FdCMakeFiles\opengl-learning.dir\ /FS -c E:\backup\opengl-learning\main.cpp
<<

CMakeFiles\opengl-learning.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl-learning.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\opengl-learning.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\backup\opengl-learning\main.cpp
<<

CMakeFiles\opengl-learning.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl-learning.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\opengl-learning.dir\main.cpp.s /c E:\backup\opengl-learning\main.cpp
<<

# Object files for target opengl-learning
opengl__learning_OBJECTS = \
"CMakeFiles\opengl-learning.dir\main.cpp.obj"

# External object files for target opengl-learning
opengl__learning_EXTERNAL_OBJECTS =

opengl-learning.exe: CMakeFiles\opengl-learning.dir\main.cpp.obj
opengl-learning.exe: CMakeFiles\opengl-learning.dir\build.make
opengl-learning.exe: shader\ShaderFunc.lib
opengl-learning.exe: F:\vcpkg\installed\x86-windows\debug\lib\glad.lib
opengl-learning.exe: F:\vcpkg\installed\x86-windows\debug\lib\glfw3dll.lib
opengl-learning.exe: CMakeFiles\opengl-learning.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\backup\opengl-learning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opengl-learning.exe"
	C:\Users\cydia2001\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.6397.106\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\opengl-learning.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\opengl-learning.dir\objects1.rsp @<<
 /out:opengl-learning.exe /implib:opengl-learning.lib /pdb:E:\backup\opengl-learning\cmake-build-debug\opengl-learning.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  shader\ShaderFunc.lib F:\vcpkg\installed\x86-windows\debug\lib\glad.lib F:\vcpkg\installed\x86-windows\debug\lib\glfw3dll.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	powershell -noprofile -executionpolicy Bypass -file F:/vcpkg/scripts/buildsystems/msbuild/applocal.ps1 -targetBinary E:/backup/opengl-learning/cmake-build-debug/opengl-learning.exe -installedDir F:/vcpkg/installed/x86-windows/debug/bin -OutVariable out

# Rule to build all files generated by this target.
CMakeFiles\opengl-learning.dir\build: opengl-learning.exe

.PHONY : CMakeFiles\opengl-learning.dir\build

CMakeFiles\opengl-learning.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\opengl-learning.dir\cmake_clean.cmake
.PHONY : CMakeFiles\opengl-learning.dir\clean

CMakeFiles\opengl-learning.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\backup\opengl-learning E:\backup\opengl-learning E:\backup\opengl-learning\cmake-build-debug E:\backup\opengl-learning\cmake-build-debug E:\backup\opengl-learning\cmake-build-debug\CMakeFiles\opengl-learning.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\opengl-learning.dir\depend

