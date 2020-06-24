// RUN: %check_clang_tidy %s misc-sort-constructor-initializers %t

struct NeedFix
{
  NeedFix();
  
  int n0;
  int n1;
  int n2;
};

NeedFix::NeedFix()
:n1(1),n2(2),n0(0)
// CHECK-MESSAGES: [[@LINE-1]]:2: warning: Member initializers are not sorted: n1(1),n2(2),n0(0) [misc-sort-constructor-initializers]
// CHECK-FIXES: n0(0),n1(1),n2(2)
{
}

struct Base
{
    Base(int n){}
};

struct NeedFixWithBase : Base
{
  NeedFixWithBase();
  
  int n0;
  int n1;
  int n2;
};

NeedFixWithBase::NeedFixWithBase()
:Base(0),n1(1),n2(2),n0(0)
// CHECK-MESSAGES: [[@LINE-1]]:10: warning: Member initializers are not sorted: n1(1),n2(2),n0(0) [misc-sort-constructor-initializers]
// CHECK-FIXES: n0(0),n1(1),n2(2)
{
}

struct NoFixes
{
  NoFixes();
  
  int n0;
  int n1;
  int n2;
};

NoFixes::NoFixes()
:n0(0)
,n1(1)
,n2(2)
{
}