macro(coffee_target_debug_compile_defs targetName)
  set(targetNameUpper ${targetName})
  string(TOUPPER targetName targetNameUpper)

  target_compile_definitions(
    ${targetName}
    PUBLIC
      $<$<AND:$<CONFIG:Debug>,$<BOOL:${COFFEE_${targetNameUpper}_DEBUG}>>:COFFEE_DEBUG>
  )
endmacro()
