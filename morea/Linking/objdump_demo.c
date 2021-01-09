int global_variable =66;

int function_defined_here(int argument) {
  int local_variable;

  local_variable = function_defined_elsewhere();

  return (argument + local_variable + 42); 
}
 

