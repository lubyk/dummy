# --------------------------------------------------------------
#  dummy
#
#  provides:
#    dummy.lua
#    dummy/core.so
# --------------------------------------------------------------
set(MODULE_NAME dummy)

include_directories(include)

# --------------------------------------------------------------
#  dummy
# --------------------------------------------------------------
add_custom_target(${MODULE_NAME} true)

# --------------------------------------------------------------
#  dummy_core
# --------------------------------------------------------------
add_subdirectory(src)

# --------------------------------------------------------------
#  module_bind                                   
# --------------------------------------------------------------
file(GLOB MODULE_HEADERS include/${MODULE_NAME}/*.h)
add_custom_target("${MODULE_NAME}_bind"
  COMMAND lua bind.lua
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  DEPENDS ${MODULE_HEADERS} bind.lua)

# --------------------------------------------------------------
#  install                                     
# --------------------------------------------------------------
install(DIRECTORY lib
  DESTINATION ${LUBYK_LIB}
)
