# CMakeList.txt: проект CMake для l1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.20)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("l1")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (l1 "l1.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
add_custom_command(TARGET l1 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Copying executable from remote machine to local machine"
	COMMAND rsync -avz ${CMAKE_SOURCE_DIR}/out/build/linux-debug/l1 /mnt/b/it/c++/DUMSCPP/l1/out/bin/
	VERBATIM
)