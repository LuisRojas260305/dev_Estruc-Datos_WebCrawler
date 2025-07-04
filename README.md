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