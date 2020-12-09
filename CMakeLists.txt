cmake_minimum_required(VERSION 3.17)
project(raytrace C)

set(CMAKE_C_STANDARD 99)

add_executable(raytrace main.c vector_math.c draw.c keys_mac.c  sphere.c cylinder.c cone.c plane.c rt.h
        minilibx_macos/mlx.h parse.c  vector_math_dop.c lft/ft_min.c lft/ft_max.c lft/ft_clamp.c camera_rotation.c parse_input.c parse_ex.c intersects.c ex.c)
#target_link_libraries(raytrace "-I." "-I../lft/" mlx m ft Xext X11 "-L.." "-L../lft/")
target_link_libraries(raytrace "-I." "-I../lft/" mlx m ft "-L.." "-L../minilibx_macos/" "-L../lft/" "-framework OpenGL" "-framework AppKit")