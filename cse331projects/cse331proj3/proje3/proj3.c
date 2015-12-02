
/******************************************************************************
 Project #3 skeleton
 ******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal,
              Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
 Function "simnet"   -- test bed for student circuits
 ******************************************************************************/

void simnet()
{
    Signal w, x, y, z, P, a, b, c, d, e, f, g;
    
    // Code to generate four input signals
    
    Signal Strobe (1);   // Counter strobe input
    Signal ResetA (1);   // Counter reset signal (before complemented)
    Signal ResetB (1);   // Counter reset signal (after complemented)
    // A pulser is used to generate a temporary value of "One" on a specified
    // signal line (signal value:  Zero ==> One ==> Zero)
    
    Pulser ((SD("3a"), "R -- Reset Counter"),  ResetA, 'r', 10000);
    Pulser ((SD("4a"), "S -- Strobe Counter"), Strobe, 's', 10000);
    
    // Complement the reset signal (counter reset is active low)
    
    Not (SD("3b"), ResetA, ResetB);
    
    Counter ((SD("3c-4c"), "4-bit Counter"), (ResetB, Strobe), (w,x,y,z));
    
    // Code to generate four input signals
    
    circuits( SD("2d-5d"), w, x, y, z, P, a, b, c, d, e, f, g);
    
    // Code to display eight output signals
    
    Probe ( (SD("1f-1h"), "P"), P );
    Probe ( (SD("2f-2h"), "a"), a );
    Probe ( (SD("2h-4h"), "b"), b );
    Probe ( (SD("4h-6h"), "c"), c );
    Probe ( (SD("6f-6h"), "d"), d );
    Probe ( (SD("4f-6f"), "e"), e );
    Probe ( (SD("2f-4f"), "f"), f );
    Probe ( (SD("4f-4h"), "g"), g );
}

/******************************************************************************
 Function "circuits" -- implementation of student circuits
 Do not alter the interface -- function "circuits" must receive four
 signals as inputs and return eight signals as outputs.
 ******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z,
              Signal P, Signal a, Signal b, Signal c, Signal d, Signal e,
              Signal f, Signal g )
{
    Module( (sd, "Circuits"), (w, x, y, z), (P, a, b, c, d, e, f, g) );
    
    // Declarations for any auxiliary Signals
    Signal notw, notx, noty, notz, and1, and2, and3, and4, and5, and6, and7, and8, and9, and10;
    
    // Circuit implementation (Not, And, Or gates)
    Not ( SD(sd, "1b"), w, notw);
    Not ( SD(sd, "2b"), x, notx);
    Not ( SD(sd, "3b"), y, noty);
    Not ( SD(sd, "4b"), z, notz);
    
    And ( SD(sd, "2c"), (notx, noty, z), and1);
    And ( SD(sd, "3c"), (notw, notx, z), and2);
    And ( SD(sd, "4c"), (notw, x, notz), and3);
    And ( SD(sd, "5c"), (notw, x, noty), and4);
    And ( SD(sd, "6c"), (w, notx, y, notz), and5);
    And ( SD(sd, "7c"), (x, z), and6);
    And ( SD(sd, "8c"), (noty, notz), and7);
    And ( SD(sd, "9c"), (y, notz), and8);
    And ( SD(sd, "7c"), (notw, y), and9);
    And ( SD(sd, "7c"), (w, z), and10);
    
    Or ( SD(sd, "21"), (and1, and2, and3, and4, and5), P);
    Or ( SD(sd, "22"), (w, y, and6), a);
    Or ( SD(sd, "23"), (notx,and7), b);
    Or ( SD(sd, "24"), (w, x, y, z, notw, notx,noty,notz), c);
    Or ( SD(sd, "25"), (and9, and10, and6), d);
    Or ( SD(sd, "26"), (and8), e);
    Or ( SD(sd, "27"), (w, x), f);
    Or ( SD(sd, "28"), (w, x, y), g);
}