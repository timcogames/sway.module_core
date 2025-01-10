# group `data` {#d1/d69/group__data}

Here are a few simple classes that help in storage and viewing data. For example, the Table templates allow to use not only arrays of objects (for which one might want to use the std::vector class), but also two-dimensional (rectangular) tables of arbitrary objects, as well as higher-order analogs up to tables with (presently) seven indices.

Similarly, the VectorSlice function is a primitive that takes anything that has an interface that resembles a vector (for example the deal.II Vector or the std::vector classes) and presents a view on it as if it were a vector in itself.

## Summary

 Members | Descriptions 
:---|---

