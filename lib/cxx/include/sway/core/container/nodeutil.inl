namespace sway::core {

template <typename TYPE>
auto NodeUtil::cast(NodeSharedPtr_t ptr) -> std::shared_ptr<TYPE> {
  return std::static_pointer_cast<TYPE>(ptr);
}

template <typename TYPE>
auto NodeUtil::cast(NodeOptionalSharedPtr_t ptr) -> std::shared_ptr<TYPE> {
  return std::static_pointer_cast<TYPE>(ptr.value());
}

}  // namespace sway::core
