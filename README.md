# Tython Compiler

¡Bienvenido al proyecto Tython! Tython es un lenguaje de programación que combina la sintaxis y la simplicidad de Python con un sistema de tipos estáticos inspirado en TypeScript. Este proyecto es un compilador que traduce código Tython a Python estándar, permitiendo a los desarrolladores disfrutar de las ventajas de la tipificación estática mientras mantienen la elegancia de Python.

## Características principales

- **Tipado estático**: Define tipos para variables y funciones utilizando la sintaxis `identificador: Tipo` para variables y `-> Tipo` para funciones.
- **Compatibilidad con Python**: El código generado es Python estándar, lo que permite su ejecución en cualquier entorno Python.
- **Sintaxis familiar**: Mantiene la sintaxis limpia y legible de Python, con añadidos para la tipificación.

## Sintaxis de Tython

### Variables tipadas

En Tython, puedes declarar variables con tipos específicos:

```tython
nombre: str = "Juan"
edad: int = 25
es_estudiante: bool = True