set(MOVIE_SRCS
  nge_movie.c
  )

add_our_library(nge_movie STATIC ${MOVIE_SRCS})
target_link_libraries(nge_movie nge2_orig)

install(TARGETS nge_movie DESTINATION lib)
install(FILES nge_movie.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
