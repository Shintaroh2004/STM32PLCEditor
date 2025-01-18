cmake_minimum_required(VERSION 3.8)

project(
	STM32PLCEditor
	VERSION 0.0.0
	DESCRIPTION "PLC editor linked with STM32CubeIDE for WindowsOS."
	LANGUAGES CXX
)

if(WIN32)

	add_library(lib_ui STATIC "src/InitLayout.cpp" "src/InitMenu.cpp")
	target_include_directories(lib_ui PUBLIC "./include")
	
	add_library(lib_handler STATIC "src/CommandHandle.cpp" "src/NotifyHandle.cpp")
	target_include_directories(lib_handler PUBLIC "./include")
	
	add_executable(${PROJECT_NAME} WIN32 "main.cpp")
	target_link_libraries(${PROJECT_NAME} PRIVATE lib_ui lib_handler)

else()

	message(SEND_ERROR "Platforms that don't match. Please build on Windows.")

endif()