#------------------------------------------------------------------------------#
#                              PROJECT VARIABLES                               #
#------------------------------------------------------------------------------#

# Executable name
NAME	=	cub3D

# Arguments to call the executable with by default
ARGS	= ./levels/map_3.cub
#./levels/map_3.cub
# Directory names
SRCDIR		=	src/
OBJDIR		=	bin/
TSTDIR		=	tests/
SUBDIRS		=	\

# Source file names (prefix their subdir if needed)
FILES	=	actions \
			casters \
			checkers \
			coorders \
			debugers \
			flooders \
			freeers \
			getters \
			hookers \
			initializers \
			main \
			maths \
			readers \
			slicers \
			textures \
			tilers \

# Libraries (.a files) to include for compilation
LIBS	=	./Libft42/libft.a \
			./MLX42/build/libmlx42.a \

LIBX	=	-lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/"
