add_executable(${SSG_PROJECT_NAME}
	${SSG_SRC_DIR}/main.cpp
	${SSG_SRC_DIR}/sitetree.cpp
	${SSG_SRC_DIR}/XMLNode.cpp)

target_include_directories(${SSG_PROJECT_NAME} PUBLIC
	${SSG_INC_DIR})
