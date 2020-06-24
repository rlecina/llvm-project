.. title:: clang-tidy - misc-sort-constructor-initializers

misc-sort-constructor-initializers
==================================

Finds not properly sorted member initializer list on constructors.
This will allow a codebase to enable `-Wreoder`

.. code-block:: c++

  struct Test
  {
    Test();

    int n0;
    int n1;
    int n2;     
  };
    
  Test::Test()
  :n1(1)
  ,n2(2)
  ,n0(0)
  {}

  // becomes

  Test::Test()
  :n0(0)
  ,n1(1)
  ,n2(2)
  {}
