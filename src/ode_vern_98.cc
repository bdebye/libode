//! \file ode_vern_98.cc

#include "ode_vern_98.h"

OdeVern98::OdeVern98 (unsigned long neq) :
    OdeEmbedded (neq, false, 8),
    OdeRK (neq, 16),
    OdeERK (neq) {

    method_ = "Vern98";

    /*
    coefficients copied from:
        http://people.math.sfu.ca/~jverner/
        http://people.math.sfu.ca/~jverner/RKV98.IIa.Efficient.000000349.081209.CoeffsOnlyFLOAT6040
    */

    c2 =  0.03462;
    c3 =  0.09702435063878044594828361677100617517633;
    c4 =  0.1455365259581706689224254251565092627645;
    c5 =  0.561;
    c6 =  0.2290079115904850126662751771814700052182;
    c7 =  0.5449920884095149873337248228185299947818;
    c8 =  0.645;
    c9 =  0.48375;
    c10 = 0.06757;
    c11 = 0.2500;
    c12 = 0.6590650618730998549405331618649220295334;
    c13 = 0.8206;
    c14 = 0.9012;
    c15 = 1.0;
    c16 = 1.0;

    a21 = c2;

    a31 = -0.0389335438857287327017042687229284478532;
    a32 = 0.1359578945245091786499878854939346230295;

    a41 =  0.03638413148954266723060635628912731569111;
    a43 =  0.1091523944686280016918190688673819470733;

    a51 =  2.025763914393969636805657604282571047511;
    a53 = -7.638023836496292020387602153091964592952;
    a54 =  6.173259922102322383581944548809393545442;

    a61 =  0.05112275589406060872792270881648288397197;
    a64 =  0.1770823794555021537929910813839068684087;
    a65 =  0.00080277624092225014536138698108025283759;

    a71 =  0.1316006357975216279279871693164256985334;
    a74 = -0.2957276252669636417685183174672273730699;
    a75 =  0.0878137803564295237421124704053886667082;
    a76 =  0.62130529752252747743214350056394300261;

    a81 =  0.07166666666666666666666666666666666666667;
    a86 =  0.3305533578915319409260346730051472207728;
    a87 =  0.2427799754418013924072986603281861125606;

    a91 =  0.071806640625;
    a96 =  0.3294380283228177160744825466257672816401;
    a97 =  0.1165190029271822839255174533742327183599;
    a98 = -0.034013671875;

    a101 =  0.04836757646340646986611287718844085773549;
    a106 =  0.03928989925676163974333190042057047002852;
    a107 =  0.1054740945890344608263649267140088017604;
    a108 = -0.02143865284648312665982642293830533996214;
    a109 = -0.1041229174627194437759832813847147895623;

    a111 = -0.02664561487201478635337289243849737340534;
    a116 =  0.03333333333333333333333333333333333333333;
    a117 = -0.1631072244872467239162704487554706387141;
    a118 =  0.03396081684127761199487954930015522928244;
    a119 =  0.1572319413814626097110769806810024118077;
    a1110 =  0.2152267478031879552303534778794770376960;

    a121 =  0.03689009248708622334786359863227633989718;
    a126 = -0.1465181576725542928653609891758501156785;
    a127 =  0.2242577768172024345345469822625833796001;
    a128 =  0.02294405717066072637090897902753790803034;
    a129 = -0.0035850052905728761357394424889330334334;
    a1210 =  0.08669223316444385506869203619044453906053;
    a1211 =  0.4383840651968337846196219974168630120572;

    a131 = -0.4866012215113340846662212357570395295088;
    a136 = -6.304602650282852990657772792012007122988;
    a137 = -0.281245618289472564778284183790118418111;
    a138 = -2.679019236219849057687906597489223155566;
    a139 =  0.518815663924157511565311164615012522024;
    a1310 =  1.365353187603341710683633635235238678626;
    a1311 =  5.885091088503946585721274891680604830712;
    a1312 =  2.802808786272062889819965117517532194812;

    a141 =  0.4185367457753471441471025246471931649633;
    a146 =  6.724547581906459363100870806514855026676;
    a147 = -0.425444280164611790606983409697113064616;
    a148 =  3.343279153001265577811816947557982637749;
    a149 =  0.617081663117537759528421117507709784737;
    a1410 = -0.929966123939932833937749523988800852013;
    a1411 = -6.099948804751010722472962837945508844846;
    a1412 = -3.002206187889399044804158084895173690015;
    a1413 =  0.2553202529443445472336424602988558373637;

    a151 = -0.779374086122884664644623040843840506343;
    a156 = -13.93734253810777678786523664804936051203;
    a157 =  1.252048853379357320949735183924200895136;
    a158 = -14.69150040801686878191527989293072091588;
    a159 = -0.494705058533141685655191992136962873577;
    a1510 =  2.242974909146236657906984549543692874755;
    a1511 =  13.36789380382864375813864978592679139881;
    a1512 =  14.39665048665068644512236935340272139005;
    a1513 = -0.7975813331776800379127866056663258667437;
    a1514 =  0.4409353709534277758753793068298041158235;

    a161 =  2.058051337466886442151242368989994043993;
    a166 =  22.35793772796803295519317565842520212899;
    a167 =  0.90949810997556332745009198137971890783;
    a168 =  35.89110098240264104710550686568482456493;
    a169 = -3.442515027624453437985000403608480262211;
    a1610 = -4.865481358036368826566013387928704014496;
    a1611 = -18.90980381354342625688427480879773032857;
    a1612 = -34.26354448030451782929251177395134170515;
    a1613 =  1.264756521695642578827783499806516664686;

    b1 =  0.01461197685842315252051541915018784713459;
    b8 = -0.3915211862331339089410228267288242030810;
    b9 =  0.2310932500289506415909675644868993669908;
    b10 =  0.1274766769992852382560589467488989175618;
    b11 =  0.2246434176204157731566981937082069688984;
    b12 =  0.5684352689748512932705226972873692126743;
    b13 =  0.05825871557215827200814768021863420902155;
    b14 =  0.1364317403482215641609022744494239843327;
    b15 =  0.03057013983082797397721005067920369646664;

    d1 =  0.01996996514886773085518508418098868756464;
    d8 =  2.191499304949330054530747099310837524864;
    d9 =  0.08857071848208438030833722031786358862953;
    d10 =  0.1140560234865965622484956605091432032674;
    d11 =  0.2533163805345107065564577734569651977347;
    d12 = -2.056564386240941011158999594595981300493;
    d13 =  0.3408096799013119935160094894224543812830;
    d16 =  0.04834231373823958314376726739772871714902;
}

void OdeVern98::step_ (double dt) {

    unsigned long i;

    //------------------------------------------------------------------
    ode_fun_(sol_, k_[0]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*a21*k_[0][i];
    ode_fun_(soltemp_, k_[1]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a31*k_[0][i]
                                                     + a32*k_[1][i]);
    ode_fun_(soltemp_, k_[2]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a41*k_[0][i]
                                                     + a43*k_[2][i]);
    ode_fun_(soltemp_, k_[3]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a51*k_[0][i]
                                                     + a53*k_[2][i]
                                                     + a54*k_[3][i]);
    ode_fun_(soltemp_, k_[4]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a61*k_[0][i]
                                                     + a64*k_[3][i]
                                                     + a65*k_[4][i]);
    ode_fun_(soltemp_, k_[5]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a71*k_[0][i]
                                                     + a74*k_[3][i]
                                                     + a75*k_[4][i]
                                                     + a76*k_[5][i]);
    ode_fun_(soltemp_, k_[6]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a81*k_[0][i]
                                                     + a86*k_[5][i]
                                                     + a87*k_[6][i]);
    ode_fun_(soltemp_, k_[7]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a91*k_[0][i]
                                                     + a96*k_[5][i]
                                                     + a97*k_[6][i]
                                                     + a98*k_[7][i]);
    ode_fun_(soltemp_, k_[8]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a101*k_[0][i]
                                                     + a106*k_[5][i]
                                                     + a107*k_[6][i]
                                                     + a108*k_[7][i]
                                                     + a109*k_[8][i]);
    ode_fun_(soltemp_, k_[9]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a111*k_[0][i]
                                                     + a116*k_[5][i]
                                                     + a117*k_[6][i]
                                                     + a118*k_[7][i]
                                                     + a119*k_[8][i]
                                                     + a1110*k_[9][i]);
    ode_fun_(soltemp_, k_[10]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a121*k_[0][i]
                                                     + a126*k_[5][i]
                                                     + a127*k_[6][i]
                                                     + a128*k_[7][i]
                                                     + a129*k_[8][i]
                                                     + a1210*k_[9][i]
                                                     + a1211*k_[10][i]);
    ode_fun_(soltemp_, k_[11]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a131*k_[0][i]
                                                     + a136*k_[5][i]
                                                     + a137*k_[6][i]
                                                     + a138*k_[7][i]
                                                     + a139*k_[8][i]
                                                     + a1310*k_[9][i]
                                                     + a1311*k_[10][i]
                                                     + a1312*k_[11][i]);
    ode_fun_(soltemp_, k_[12]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a141*k_[0][i]
                                                     + a146*k_[5][i]
                                                     + a147*k_[6][i]
                                                     + a148*k_[7][i]
                                                     + a149*k_[8][i]
                                                     + a1410*k_[9][i]
                                                     + a1411*k_[10][i]
                                                     + a1412*k_[11][i]
                                                     + a1413*k_[12][i]);
    ode_fun_(soltemp_, k_[13]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a151*k_[0][i]
                                                     + a156*k_[5][i]
                                                     + a157*k_[6][i]
                                                     + a158*k_[7][i]
                                                     + a159*k_[8][i]
                                                     + a1510*k_[9][i]
                                                     + a1511*k_[10][i]
                                                     + a1512*k_[11][i]
                                                     + a1513*k_[12][i]
                                                     + a1514*k_[13][i]);
    ode_fun_(soltemp_, k_[14]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) soltemp_[i] = sol_[i] + dt*(a161*k_[0][i]
                                                     + a166*k_[5][i]
                                                     + a167*k_[6][i]
                                                     + a168*k_[7][i]
                                                     + a169*k_[8][i]
                                                     + a1610*k_[9][i]
                                                     + a1611*k_[10][i]
                                                     + a1612*k_[11][i]
                                                     + a1613*k_[12][i]);
    ode_fun_(soltemp_, k_[15]);

    //------------------------------------------------------------------
    for (i=0; i<neq_; i++) {
        solemb_[i] = sol_[i] + dt*(d1*k_[0][i]
                                 + d8*k_[7][i]
                                 + d9*k_[8][i]
                                 + d10*k_[9][i]
                                 + d11*k_[10][i]
                                 + d12*k_[11][i]
                                 + d13*k_[12][i]
                                 + d16*k_[15][i]);
        sol_[i] = sol_[i] + dt*(b1*k_[0][i]
                              + b8*k_[7][i]
                              + b9*k_[8][i]
                              + b10*k_[9][i]
                              + b11*k_[10][i]
                              + b12*k_[11][i]
                              + b13*k_[12][i]
                              + b14*k_[13][i]
                              + b15*k_[14][i]);
    }
}