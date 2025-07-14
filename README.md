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

##Tablas de Clases
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

##Diagrama de clases

```mermaid
    classDiagram
    class TreeNode {
        -string url
        -int depth
        -bool isExternal
        -bool isBroken
        -string content
        -vector<TreeNode*> children
        +TreeNode(string url, int depth)
        +~TreeNode()
        +void addChild(TreeNode* child)
        +string getUrl()
        +int getDepth()
        +bool getIsExternal()
        +void setIsExternal(bool external)
        +bool getIsBroken()
        +void setIsBroken(bool broken)
        +string getContent()
        +void setContent(string content)
        +vector<TreeNode*> getChildren()
    }

    class HashTable {
        -int size
        -vector<list<string>> table
        -int hashFunction(string key)
        +HashTable(int size = 1000)
        +void insert(string key)
        +bool contains(string key)
        +void remove(string key)
    }

    class WebCrawler {
        -TreeNode* root
        -int maxDepth
        -string domain
        -HashTable visitedUrls
        -vector<string> extractLinks(string html, string baseUrl)
        -string downloadUrl(string url)
        +WebCrawler(string rootUrl, int maxDepth)
        +~WebCrawler()
        +void crawl()
        +Stats getStats()
        +int findKeyword(string keyword)
        +vector<string> getBrokenLinks()
        +void exportTree(string filename)
        -TreeNode* crawlRecursive(TreeNode* node, int currentDepth)
    }

    class Stats {
        -int totalLinks
        -int internalLinks
        -int externalLinks
        -int maxDepth
        +Stats()
        +void incrementTotal()
        +void incrementInternal()
        +void incrementExternal()
        +void setMaxDepth(int depth)
        +int getTotalLinks()
        +int getInternalLinks()
        +int getExternalLinks()
        +int getMaxDepth()
    }

    class FileExporter {
        +static void exportToFile(TreeNode* root, string filename)
    }

    class ConsoleUI {
        -WebCrawler* crawler
        +void start()
        -void displayMenu()
        -void handleInput()
        -void promptForRootUrlAndDepth()
        -void displayStats()
        -void searchKeyword()
        -void exportTree()
    }

    class HTTPClient {
        +static string downloadUrl(string url)
    }

    class HTMLParser {
        +static vector<string> extractLinks(string html, string baseUrl)
    }

    WebCrawler *-- TreeNode : Composition
    WebCrawler *-- HashTable : Composition
    WebCrawler --> Stats : Creates
    WebCrawler --> FileExporter : Uses
    WebCrawler --> HTTPClient : Uses
    WebCrawler --> HTMLParser : Uses
    ConsoleUI --> WebCrawler : Creates and Controlsv
```
