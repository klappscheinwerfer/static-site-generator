add_executable(Test
	${SSG_TEST_DIR}/sitetree_test.cpp)

target_include_directories(${SSG_PROJECT_NAME} PUBLIC
	${SSG_INC_DIR})
