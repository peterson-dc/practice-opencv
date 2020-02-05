# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/davis/GitHub/practice-opencv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/davis/GitHub/practice-opencv/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/EdgeDetection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EdgeDetection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EdgeDetection.dir/flags.make

CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.o: CMakeFiles/EdgeDetection.dir/flags.make
CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.o: ../edgeDetection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/davis/GitHub/practice-opencv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.o -c /Users/davis/GitHub/practice-opencv/edgeDetection.cpp

CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/davis/GitHub/practice-opencv/edgeDetection.cpp > CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.i

CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/davis/GitHub/practice-opencv/edgeDetection.cpp -o CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.s

# Object files for target EdgeDetection
EdgeDetection_OBJECTS = \
"CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.o"

# External object files for target EdgeDetection
EdgeDetection_EXTERNAL_OBJECTS =

EdgeDetection: CMakeFiles/EdgeDetection.dir/edgeDetection.cpp.o
EdgeDetection: CMakeFiles/EdgeDetection.dir/build.make
EdgeDetection: /usr/local/lib/libopencv_gapi.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_stitching.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_aruco.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_bgsegm.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_bioinspired.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_ccalib.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_dnn_objdetect.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_dpm.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_face.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_freetype.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_fuzzy.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_hfs.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_img_hash.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_line_descriptor.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_quality.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_reg.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_rgbd.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_saliency.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_sfm.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_stereo.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_structured_light.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_superres.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_surface_matching.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_tracking.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_videostab.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_xfeatures2d.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_xobjdetect.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_xphoto.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_shape.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_datasets.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_plot.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_text.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_dnn.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_highgui.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_ml.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_phase_unwrapping.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_optflow.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_ximgproc.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_video.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_videoio.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_imgcodecs.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_objdetect.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_calib3d.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_features2d.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_flann.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_photo.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_imgproc.4.1.1.dylib
EdgeDetection: /usr/local/lib/libopencv_core.4.1.1.dylib
EdgeDetection: CMakeFiles/EdgeDetection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/davis/GitHub/practice-opencv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable EdgeDetection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EdgeDetection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EdgeDetection.dir/build: EdgeDetection

.PHONY : CMakeFiles/EdgeDetection.dir/build

CMakeFiles/EdgeDetection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EdgeDetection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EdgeDetection.dir/clean

CMakeFiles/EdgeDetection.dir/depend:
	cd /Users/davis/GitHub/practice-opencv/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/davis/GitHub/practice-opencv /Users/davis/GitHub/practice-opencv /Users/davis/GitHub/practice-opencv/cmake-build-debug /Users/davis/GitHub/practice-opencv/cmake-build-debug /Users/davis/GitHub/practice-opencv/cmake-build-debug/CMakeFiles/EdgeDetection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EdgeDetection.dir/depend

