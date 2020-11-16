project (cppmart)

add_subdirectory(cmake-asm-dom-wrapper)

set(GCCX_GEN_TARGET gccx-store)

set(CPX_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/ProductCard.cpx
  ${CMAKE_CURRENT_SOURCE_DIR}/ProductDetail.cpx
  ${CMAKE_CURRENT_SOURCE_DIR}/Navbar.cpx
  ${CMAKE_CURRENT_SOURCE_DIR}/Home.cpx
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpx
)

gccx(${GCCX_GEN_TARGET} 
  "${CPX_SRCS}"
  ${CMAKE_CURRENT_BINARY_DIR}/generated
)

add_executable(cppmart 
  # Generated location
  ${CMAKE_CURRENT_BINARY_DIR}/generated/main.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/ProductCard.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/ProductDetail.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/Navbar.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/generated/Home.cpp
)
# depend on the GCCX_GEN_TARGET to ensure main.cpp has been generated
add_dependencies(cppmart ${GCCX_GEN_TARGET})
target_link_libraries(cppmart 
  PRIVATE 
    asm-dom
)
target_include_directories(cppmart 
  PRIVATE 
    .
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