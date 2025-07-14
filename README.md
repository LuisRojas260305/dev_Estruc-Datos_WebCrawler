# 🚀 Proyecto WebCrawler

## 👥 Desarrolladores

| Nombre          | Cédula de Identidad |
|-----------------|---------------------|
| **Luis Rojas**  |     30931891        |
| **Daniel Reyna**|     29989066        |
| **Nicole Sereno**|    31275411        |
| **Paola Peña**  |     31152816        |

---

## 📝 Descripción del programa

El programa es un Web Crawler que explora recursivamente sitios web desde una URL inicial hasta una profundidad especificada. Su función principal es:

1-Rastrear enlaces en páginas web.

2-Clasificar enlaces como internos/externos.

3-Detectar enlaces rotos.

4-Generar estadísticas (total de enlaces, profundidad máxima, etc.).

5-Buscar palabras clave en el contenido.

6-Exportar resultados en formato de árbol.

---

## Funciones principales

| Clase | Funcion clave | Descripción |
|-----------------|---------------------|-----------------|
| **WebCrawler** | ExploracionRecursiva() | Rastrea enlaces recursivamente y construye el árbol de navegación. |
| **Http_client** | dowladUrl() | Descarga contenido HTML de una URL usando cURL. |
| **Html_parser** | extraerLinks() | Extrae enlaces de HTML usando regex y convierte URLs relativas a absolutas. |
| **ExportarArchivo** | exportar() | Exporta el árbol de navegación a un archivo de texto con indentación. | 
| **ConsolaUi** | MostrarMenu(), UrlyProfundidad(), MostrarEstadisticas() | Interfaz interactiva para controlar el crawler y mostrar resultados.
 |

## Funcionamiento de la Interfaz de Consola

**Inicio:**

Solicita URL inicial y profundidad máxima.
Valida la URL con regex.

**Menú Principal:**

==================  Menu princial  ==================  
1.- Mostrar estadísticas.  
2.- Buscar palabra clave.  
3.- Exportar árbol.  
4.- Salir.  

**Opciones:**

Estadísticas: Muestra total de enlaces, internos/externos y profundidad máxima.

Buscar palabra: Retorna profundidad donde se encontró la palabra (o -1 si no existe).

Exportar: Guarda el árbol en Busqueda.txt.

## Tablas de Clases
```mermaid
classDiagram
    class NodoArbol {
        -string Url
        -int Profundidad
        -bool isExternal
        -bool isBroken
        -string contenido
        -vector<NodoArbol*> Hijos
        +NodoArbol(string, int)
        +insertar(NodoArbol*)
        +getUrl() string
        +getProfundidad() int
        +getIsExternal() bool
        +getIsBroken() bool
        +getContenido() string
        +getNodos() vector<NodoArbol*>
        +setIsExternal(bool)
        +setIsBroken(bool)
        +setContent(string)
    }
```

```mermaid
classDiagram
    class WebCrawler {
        -NodoArbol* raiz
        -int Profundidad
        -string url
        -TablaHash urlVisitada
        +WebCrawler(string, int)
        +~WebCrawler()
        +Explorar()
        +getStats() Estadisticas
        +PalabraClave(string) int
        +getBrokenLinks() vector<string>
        +exportTree(string)
        -ExploracionRecursiva(NodoArbol*, int) NodoArbol*
        -ExtraerLinks(string, string) vector<string>
        -descargarUrl(string) string
        +getDominio(string) string
    }
```

```mermaid
classDiagram
    class Estadisticas {
        -int LinksTotales
        -int LinksInternos
        -int LinksExternos
        -int ProfundidadMax
        +Estadisticas()
        +IncrementarTotal()
        +IncrementarInternos()
        +IncrementarExternos()
        +setProfundidadMax(int)
        +getTotalLinks() int
        +getInternalLinks() int
        +getExternalLinks() int
        +getProfundidadMax() int
    }
```

```mermaid
classDiagram
    class ConsolaUi {
        -WebCrawler* crawler
        +ConsolaUi()
        +~ConsolaUi()
        +start()
        -UrlValida(string) bool
        -MostrarMenu()
        -UrlyProfundidad()
        -MostrarEstadisticas()
        -BuscarPalabraClave()
        -ExportarArbol()
        -limpiarConsola()
        -pausarConsola()
    }
```

## Diagrama de clases

```mermaid
    classDiagram
    class Http_client {
        +dowladUrl(string url) string
    }

    class Html_parser {
        +extraerLinks(string html, string url) vector~string~
    }

    class NodoArbol {
        -string Url
        -int Profundidad
        -bool isExternal
        -bool isBroken
        -string contenido
        -vector~NodoArbol*~ Hijos
        +NodoArbol(string, int)
        +insertar(NodoArbol*)
        // ... getters y setters
    }

    class TablaHash {
        -vector~list~string~~ tabla
        -int Tamaño
        +insertar(string)
        +existe(string) bool
        -hashFunction(string) int
    }

    class WebCrawler {
        -NodoArbol* raiz
        -int Profundidad
        -string url
        -TablaHash urlVisitada
        +WebCrawler(string, int)
        +Explorar()
        +getStats() Estadisticas
        +PalabraClave(string) int
        +getBrokenLinks() vector~string~
        +exportTree(string)
        -ExploracionRecursiva(NodoArbol*, int) NodoArbol*
        -descargarUrl(string) string
        +getDominio(string) string
    }

    class Estadisticas {
        -int LinksTotales
        -int LinksInternos
        -int LinksExternos
        -int ProfundidadMax
        +Estadisticas()
        +IncrementarTotal()
        +IncrementarInternos()
        +IncrementarExternos()
        +setProfundidadMax(int)
        // ... getters
    }

    class ExportarArchivo {
        +exportar(NodoArbol*, string)
    }

    class ConsolaUi {
        -WebCrawler* crawler
        +ConsolaUi()
        +~ConsolaUi()
        +start()
        -UrlValida(string) bool
        -MostrarMenu()
        -UrlyProfundidad()
        -MostrarEstadisticas()
        -BuscarPalabraClave()
        -ExportarArbol()
        -limpiarConsola()
        -pausarConsola()
    }

    class main {
        +main()
    }

    WebCrawler --> NodoArbol : contiene
    WebCrawler --> TablaHash : contiene
    WebCrawler --> Http_client : usa
    WebCrawler --> Html_parser : usa
    WebCrawler --> Estadisticas : retorna
    WebCrawler --> ExportarArchivo : usa
    ConsolaUi --> WebCrawler : usa
    main --> ConsolaUi : usa
    ExportarArchivo --> NodoArbol : usa
```
## Diagrama de secuencia

```mermaid
sequenceDiagram
    participant Usuario
    participant ConsolaUi
    participant WebCrawler
    participant Http_client
    participant Html_parser
    participant TablaHash
    participant NodoArbol

    Usuario->>ConsolaUi: Ingresa URL y profundidad
    ConsolaUi->>WebCrawler: new(url, profundidad)
    WebCrawler->>TablaHash: insertar(url)
    loop Exploración recursiva
        WebCrawler->>Http_client: dowladUrl(url)
        Http_client-->>WebCrawler: HTML
        WebCrawler->>Html_parser: extraerLinks(HTML)
        Html_parser-->>WebCrawler: Lista de links
        loop Para cada link
            WebCrawler->>TablaHash: existe(link)?
            TablaHash-->>WebCrawler: sí/no
            alt Link nuevo
                WebCrawler->>NodoArbol: new(link)
                WebCrawler->>NodoArbol: insertar(nuevo)
                WebCrawler->>TablaHash: insertar(link)
            end
        end
    end
    Usuario->>ConsolaUi: Selecciona "Buscar palabra"
    ConsolaUi->>WebCrawler: PalabraClave("ejemplo")
    WebCrawler->>NodoArbol: Buscar en contenido
    NodoArbol-->>WebCrawler: Profundidad (3)
    WebCrawler-->>ConsolaUi: 3
    ConsolaUi->>Usuario: Muestra resultado
```

