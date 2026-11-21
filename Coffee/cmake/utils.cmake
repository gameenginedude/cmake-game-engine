macro(coffee_target_debug_compile_defs targetName scopeType)
  set(targetNameUpper ${targetName})
  string(TOUPPER targetName targetNameUpper)

  target_compile_definitions(
    ${targetName}
    ${scopeType}
      $<$<AND:$<CONFIG:Debug>,$<BOOL:${COFFEE_${targetNameUpper}_DEBUG}>>:COFFEE_DEBUG>
  )
endmacro()
