project (cppmart)

add_subdirectory(cmake-asm-dom-wrapper)

set(GCCX_GEN_TARGET gccx-store)

gccx(${GCCX_GEN_TARGET} 
     ${CMAKE_CURRENT_SOURCE_DIR}/main.cpx 
     ${CMAKE_CURRENT_BINARY_DIR}/generated
)

add_executable(cppmart 
  # Generated location
  ${CMAKE_CURRENT_BINARY_DIR}/generated/main.cpp
)
# depend on the GCCX_GEN_TARGET to ensure main.cpp has been generated
add_dependencies(cppmart ${GCCX_GEN_TARGET})
target_link_libraries(cppmart 
  PRIVATE 
    asm-dom
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/products/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/products/)
configure_file(
  index.html
  ${CMAKE_CURRENT_BINARY_DIR}/index.html
)

configure_file(
  styles.css
  ${CMAKE_CURRENT_BINARY_DIR}/styles.css
)