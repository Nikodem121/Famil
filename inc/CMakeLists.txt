# Add header files
target_sources(Famil PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Game.h
    ${CMAKE_CURRENT_LIST_DIR}/Question.h
    ${CMAKE_CURRENT_LIST_DIR}/Team.h
    ${CMAKE_CURRENT_LIST_DIR}/UI.h
    ${CMAKE_CURRENT_LIST_DIR}/RoundManager.h
    ${CMAKE_CURRENT_LIST_DIR}/famil_types.h
)
target_include_directories(Famil PUBLIC ${CMAKE_CURRENT_LIST_DIR})
