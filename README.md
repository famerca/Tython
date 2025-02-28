# Tython Compiler

¡Bienvenido al proyecto Tython! Tython es un lenguaje de programación que combina la sintaxis y la simplicidad de Python con un sistema de tipos estáticos inspirado en TypeScript. Este proyecto es un compilador que traduce código Tython a Python estándar, permitiendo a los desarrolladores disfrutar de las ventajas de la tipificación estática mientras mantienen la elegancia de Python.

[Documentación del lenguaje](https://docs.google.com/document/d/1Df3-vDP0FzC4vGEwYxyu77usp58RyxJmNA0vjTvJ3tw/edit?usp=sharing)

## Características principales

- **Tipado estático**: Define tipos para variables y funciones utilizando la sintaxis `identificador: Tipo` para variables y `-> Tipo` para funciones.
- **Compatibilidad con Python**: El código generado es Python estándar, lo que permite su ejecución en cualquier entorno Python.
- **Sintaxis familiar**: Mantiene la sintaxis limpia y legible de Python, con añadidos para la tipificación.

## Sintaxis de Tython

### Variables tipadas

En Tython, puedes declarar variables con tipos específicos:

```tython
nombre: String = "Juan"
edad: Int = 25
es_estudiante: Float = 3.5
```
## Uso

```bash
$ make
$ ./scanner.out example.ty
```