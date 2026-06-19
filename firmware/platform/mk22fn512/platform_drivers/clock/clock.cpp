// | State | C1.CLKS | C6.PLLS | S.CLKST | S.IREFST | S.PLLST | S.LOCK0 |
// | ----- | ------- | ------- | ------- | -------- | ------- | ------- |
// | FEI   | 00      | 0       | 00      | 1        | 0       | 0       |
// | FBE   | 10      | 0       | 10      | 0        | 0       | 0       |
// | PBE   | 10      | 1       | 10      | 0        | 1       | 1       |
// | PEE   | 00      | 1       | 11      | 0        | 1       | 1       |

// // FEI State: FLL Engaged Internal
// MCG->C2->RANGE=01 // High frequency range selected for the crystal oscillator
// MCG->C2->EREFS0=1 // Oscillator requested.
// MCG->C2->HGO0=0 // Configure crystal oscillator for low-power operation
// MCG->C1->CLKS=10 // External reference clock is selected -> transition FEI to FBE
// MCG->C1->IREFS=0 // External reference clock is selected.
// MCG->S->OSCINIT0=1 // permits to be sure OSC Initialization is done => 8MHz crystal is stable
// MCG->S->IREFST=0 // permits to be sure Source of FLL reference clock is the external reference clock
// MCG->S->CLKST=10 // permits to be sure External reference clock is selected.
// // FBE State: FLL Bypassed External
// // DIVIDE THE CLOCK BEFORE TO ENABLE PLL (DON'T FORGET FREQUENCY LIMITATIONS)
// SIM->CLKDIV1->OUTDIV1=0000 // 0000 => divide by 1, core clock = 120MHz
// SIM->CLKDIV1->OUTDIV2=0001 // 0001 => divide by 2, bus clock = 60MHz
// SIM->CLKDIV1->OUTDIV3=0001 // 0001 => divide by 2, flexbus clock = 60MHz
// SIM->CLKDIV1->OUTDIV4=0100 // 0100 => divide by 5, flash clock = 24MHz
// MCG->C5->PRDIV0=00011 // 00011 => 4, 8/4= 2MHz
// MCG->C6->VDIV0=01100 // 01100 => 36, (VDIV0 + 24) * 2MHz = 120MHz, see SystemCoreClockUpdate (void)
// MCG->C6->PLLS=1 // activate PLL -> transition FBE to PBE
// MCG->S->PLLST=1 // permits to be sure Source of PLLS clock is PLL output clock.
// MCG->S->LOCK0=1 // permits to be sure PLL is locked
// // PBE State: PLL Bypassed External
// MCG->C1->CLKS=00 // Output of FLL or PLL is selected -> transition PBE to PEE
// MCG->S->CLKST=11 // permits to be sure PLL is selected
// // PEE State: PLL Engaged External

