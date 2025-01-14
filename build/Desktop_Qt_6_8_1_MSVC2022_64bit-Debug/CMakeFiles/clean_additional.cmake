# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\network_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\network_autogen.dir\\ParseCache.txt"
  "network_autogen"
  )
endif()
