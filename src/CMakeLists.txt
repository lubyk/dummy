# --------------------------------------------------------------
#  Dummy_core
#  
#  expects:
#    MODULE_NAME defined in the CMakeLists for the module
#
#  provides:
#    dummy/core.so
# --------------------------------------------------------------
set(target "${MODULE_NAME}_core")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB CORE_SOURCES dub/*.cpp *.cpp ${PLAT}/*.cpp ${PLAT}/*.mm)

add_library(${target} MODULE ${CORE_SOURCES})
set_target_properties(${target}
  PROPERTIES OUTPUT_NAME core
  LINK_FLAGS ${PLAT_OBJ_FLAGS}
  PREFIX ""
  SUFFIX ".so"
)  

add_dependencies(${MODULE_NAME} ${target})

# --------------------------------------------------------------
#  install                                     
# --------------------------------------------------------------
install(TARGETS ${target}
  DESTINATION lib/lubyk/${MODULE_NAME}
)
