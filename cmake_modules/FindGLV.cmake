FIND_PATH(GLV_INCLUDE_DIR glv.h /usr/include/GL /usr/local/include/GL)

FIND_LIBRARY(GLV_LIBRARY NAMES glv PATH /usr/lib64 /usr/local/lib64 /usr/lib /usr/local/lib) 

IF (GLV_INCLUDE_DIR AND GLV_LIBRARY)
   SET(GLV_FOUND TRUE)
ENDIF (GLV_INCLUDE_DIR AND GLV_LIBRARY)

IF (GLV_FOUND)
   IF (NOT GLV_FIND_QUIETLY)
      MESSAGE(STATUS "Found GLV: ${GLV_LIBRARY}")
   ENDIF (NOT GLV_FIND_QUIETLY)
ELSE (GLV_FOUND)
   IF (GLV_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find GLV")
   ENDIF (GLV_FIND_REQUIRED)
ENDIF (GLV_FOUND)
