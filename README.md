# Sistema de Gestión SICUE

Sistema de gestión de inscripciones y planes de convalidación universitarios basado en el programa SICUE. Este programa permite gestionar los planes de convalidación de estudiantes y profesores, así como realizar solicitudes de inscripción.

---

## 📄 Descripción del Proyecto

El sistema está orientado a **tres tipos de usuarios**:
1. **Administrador**: Puede crear planes de convalidación.
2. **Estudiante**: Puede solicitar inscripciones a planes de convalidación.
3. **Profesor**: Puede solicitar inscripciones a planes de convalidación asociados a departamentos.

La información se almacena y gestiona mediante **ficheros binarios**.

---

## ⭐ Características Principales

- **Crear Planes de Convalidación**:
  - Administrador puede crear planes para **estudiantes** y **profesores**.
  - Los planes incluyen detalles como universidad, facultad, departamento, duración, y asignaturas.

- **Solicitar Inscripción**:
  - **Estudiantes** seleccionan planes de convalidación disponibles para su grado.
  - **Profesores** seleccionan planes asociados a su departamento.

- **Almacenamiento Persistente**:
  - Los datos se guardan en ficheros binarios y se pueden recuperar en ejecuciones futuras.

---

## 🛠 Requisitos del Sistema

- Sistema Operativo: Linux o Windows con terminal compatible.
- **Compilador**: g++ (GCC) versión 11 o superior.
- **Herramientas**: 
  - Makefile para automatizar la compilación.

---

## 💽 Estructura del Proyecto

La estructura de directorios es la siguiente:

```
proyecto_sicue/
│
├── build/               # Contiene el Makefile y ejecutables
├── data/                # Ficheros de datos (binarios)
│   ├── planes_alumno.dat
│   ├── planes_profesor.dat
│   ├── solicitud_estudiante.dat
│   ├── solicitud_profesor.dat
│   ├── alumnos.dat
│   ├── profesores.dat
│
├── src/                 # Código fuente
│   ├── main.cc
│   ├── administrador.h
│   ├── administrador.cc
│   ├── alumno.h
│   ├── alumno.cc
│   ├── profesor.h
│   ├── profesor.cc
│   ├── planAlumno.h
│   ├── planAlumno.cc
│   ├── planProfesor.h
│   ├── planProfesor.cc
│   ├── utilidades.cc    # Funciones auxiliares (e.g., obtenerFechaActual)
│
└── README.md            # Este archivo
```

---

## ⚙️ Instrucciones de Compilación y Ejecución

1. Clona el repositorio:

   ```bash
   git clone https://github.com/usuario/proyecto_sicue.git
   cd proyecto_sicue/build
   ```

2. Compila el proyecto usando **Makefile**:

   ```bash
   make
   ```

3. Ejecuta el programa:

   ```bash
   ./sistema_sicue
   ```

---

## 🚀 Funcionamiento del Programa

1. **Menú Principal**:
   Al iniciar el programa, se selecciona el tipo de usuario:
   ```
   1. Administrador
   2. Profesor
   3. Alumno
   0. Salir
   ```

2. **Vista del Administrador**:
   - Crear Plan de Convalidación.
   - Los planes pueden ser para **estudiantes** o **profesores**.

3. **Vista del Profesor**:
   - Solicitar inscripción seleccionando planes asociados a su departamento.

4. **Vista del Alumno**:
   - Solicitar inscripción seleccionando planes de convalidación correspondientes a su grado.
   - Los planes se pueden ordenar por prioridad.

---

## 👥 Autores

- **Rafael Martín Victorio**
- **Pedro Medina Becerra**  
  Proyecto desarrollado para la asignatura de Ingeniería del Software, Universidad de Córdoba.
