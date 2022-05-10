# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\lab_03_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\lab_03_autogen.dir\\ParseCache.txt"
  "implementation\\CMakeFiles\\implementation_autogen.dir\\AutogenUsed.txt"
  "implementation\\CMakeFiles\\implementation_autogen.dir\\ParseCache.txt"
  "implementation\\implementation_autogen"
  "lab_03_autogen"
  )
endif()
