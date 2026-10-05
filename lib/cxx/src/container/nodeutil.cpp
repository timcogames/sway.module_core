#include <sway/core/container/node.hpp>
#include <sway/core/container/nodeindex.hpp>
#include <sway/core/container/nodeutil.hpp>

namespace sway::core {

void NodeUtil::addChainLinks(NodeSharedPtr_t node, NodeIndex parent) {
  auto chain = node->getNodeIndex().getChain();
  auto parentChain = parent.getChain();

  chain.insert(chain.begin() + 1, parentChain.begin() + 1, parentChain.end());
  node->setNodeIndex(chain, NODEIDX_NEGATIVE);

  for (auto &item : node->getChildNodes()) {
    addChainLinks(item, node->getNodeIndex());
  }
}

void NodeUtil::remChainLinks(NodeSharedPtr_t node, NodeIndex parent) {
  if (!parent.chainEqual({NODEIDX_NEGATIVE})) {
    auto chain = node->getNodeIndex().getChain();
    if (parent.getDepth() >= static_cast<int>(chain.size())) {
      return;
    }

    chain.erase(chain.begin(), chain.begin() + parent.getDepth());
    if (chain.empty()) {
      return;
    }

    chain.at(0) = NODEIDX_ROOT;
    node->setNodeIndex(chain, NODEIDX_NEGATIVE);
  }

  for (auto &item : node->getChildNodes()) {
    remChainLinks(item, parent);
  }
}

void NodeUtil::breakTies(NodeSharedPtr_t node) {
  auto parentOpt = node->getParentNode();
  if (!parentOpt.has_value()) {
    return;
  }

  auto parentIdx = parentOpt.value()->getNodeIndex();
  for (auto item : node->getChildNodes()) {
    NodeUtil::remChainLinks(item, parentIdx);
  }

  node->setParentNode(NodeWeakPtr_t());
  node->setAsRoot();
}

}  // namespace sway::core