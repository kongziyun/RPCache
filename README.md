PLCache
=======

This is a term project of EECS 573.


Experiment
===============================

1. Performance tests:
       
    i. Performance Benchmarks:

        We need to run these performance benchmarks on two cores, one with 
          unchanged cache, and the other with PLCache. Both caches should 
          have same configurations, like the cacheline size, total cache size,
          cache associativity. However, in this tests, we do not lock any 
          cacheline. Thus, the performance drop will be the time spent on 
          comparing pid.

    ii. Secure Programs (e.g, AES_Encrypt)

        We need to run multiple programs in one core at the same time (by
          enabling smt on gem5), and now we modify one of the programs to let
          it lock some cachelines. In this case, other programs running 
          concurrently cannot get access to those cachelines, so potentially
          the available cache size reduces. Three test groups, one core with 
          unchanged cache, one core with PLCache but original secure programs, 
          the other core with PLCache but modified secure programs.

        * Modify AES_Encrypt function is kinda complicated, so we can simplify
          it by write some programs that will lock certain amount of cachelines
          just like what AES encryption function is gonna do.

2. Correctness tests:
    
  We need to write a testcase.

    1). setpid(1) and lock some cachelines
    2). setpid(-1) and access the locked cachelines, record the cycle count
    3). setpid(2) and access the locked cachelines owned by other pid, record 
        the cycle count
    4). lock some other cachelines
    5). setpid(1) and access its own cachelines and also the cachelines locked 
        by pid == 2, record the cycle count
    6). unsetpid(1), unsetpid(2)
    7). setpid(-1) and access the released cachelines twice, record the cycle 
        count. First time should be cache miss and second time should be hit.

