package adversary;

simple Adversary {
 
  parameters:
    bool collectTraceInfo = default (false);
    bool evaluateAttacks = default (false);

  gates:
    output toGlobalFilter;
    input fromGlobalFilter;
}
