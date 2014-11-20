#include <cstdlib>
#include <string>
#include <functional>

template<typename NodePayload>
class Graph {
public:
    typedef int NodeHandle;
    typedef int EdgeHandle;
    typedef std::function<void(NodeHandle const &)> NodeVisitor;
    typedef std::function<void(NodeHandle const &)> EdgeVisitor;
public:
    Graph();
    ~Graph();
    void loadFromFile(std::string const & filename);
    void saveToFile(std::string const & filename);
    NodeHandle addNode();
    void addEdge(NodeHandle const & a, NodeHandle const & b);
    void forEachNode(std::function<void(NodeHandle const &)> const & visitor) const;
    size_t getNodesCount() const;
    void forEachEdge(NodeHandle const & source, EdgeVisitor const & visitor);
    NodeHandle move(NodeHandle const & origin, EdgeHandle const & edge);
    NodePayload & operator[](NodeHandle const & node);
    void dfs(NodeVisitor const & startNode, NodeVisitor const & endNode, NodeVisitor const & discoverNode);
};
