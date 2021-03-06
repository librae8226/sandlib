function simple_5() {
canvas = document.getElementById("simple_5");
ctx = canvas.getContext("2d");
// Reinitialize mouse tracking and zoom for this particular plot
if ((typeof(gnuplot.active_plot) == "undefined" || gnuplot.active_plot != simple_5)  &&  typeof(gnuplot.mouse_update) != "undefined") {
  gnuplot.active_plot_name = "simple_5";
  gnuplot.active_plot = simple_5;
  canvas.onmousemove = gnuplot.mouse_update;
  canvas.onmouseup = gnuplot.zoom_in;
  canvas.onmousedown = gnuplot.saveclick;
  canvas.onkeypress = gnuplot.do_hotkey;
  if (canvas.attachEvent) {canvas.attachEvent('mouseover', simple_5);}
  else if (canvas.addEventListener) {canvas.addEventListener('mouseover', simple_5, false);} 
  gnuplot.zoomed = false;
  gnuplot.zoom_axis_width = 0;
  gnuplot.zoom_in_progress = false;
  gnuplot.polar_mode = false;
  ctx.clearRect(0,0,600,400);
}
// Gnuplot version 4.6.0
// short forms of commands provided by gnuplot_common.js
function DT  (dt)  {gnuplot.dashtype(dt);};
function DS  (x,y) {gnuplot.dashstart(x,y);};
function DL  (x,y) {gnuplot.dashstep(x,y);};
function M   (x,y) {if (gnuplot.pattern.length > 0) DS(x,y); else gnuplot.M(x,y);};
function L   (x,y) {if (gnuplot.pattern.length > 0) DL(x,y); else gnuplot.L(x,y);};
function Dot (x,y) {gnuplot.Dot(x,y);};
function Pt  (N,x,y,w) {gnuplot.Pt(N,x,y,w);};
function R   (x,y,w,h) {gnuplot.R(x,y,w,h);};
function T   (x,y,fontsize,justify,string) {gnuplot.T(x,y,fontsize,justify,string);};
function TR  (x,y,angle,fontsize,justify,string) {gnuplot.TR(x,y,angle,fontsize,justify,string);};
function bp  (x,y) {gnuplot.bp(x,y);};
function cfp () {gnuplot.cfp();};
function cfsp() {gnuplot.cfsp();};

ctx.lineCap = "butt"; ctx.lineJoin = "miter";
CanvasTextFunctions.enable(ctx);
ctx.strokeStyle = "rgb(215,215,215)";
ctx.lineWidth = 1;

ctx.lineWidth = 1;
ctx.strokeStyle = "rgb(000,000,000)";
ctx.beginPath();
M(520,3800);
L(620,3800);
M(5759,3800);
L(5659,3800);
ctx.stroke();
ctx.closePath();
T(440,3850,10.0,"Right","-1");
ctx.beginPath();
M(520,3469);
L(620,3469);
M(5759,3469);
L(5659,3469);
ctx.stroke();
ctx.closePath();
T(440,3519,10.0,"Right","-0.5");
ctx.beginPath();
M(520,3138);
L(620,3138);
M(5759,3138);
L(5659,3138);
ctx.stroke();
ctx.closePath();
T(440,3188,10.0,"Right"," 0");
ctx.beginPath();
M(520,2808);
L(620,2808);
M(5759,2808);
L(5659,2808);
ctx.stroke();
ctx.closePath();
T(440,2858,10.0,"Right"," 0.5");
ctx.beginPath();
M(520,2477);
L(620,2477);
M(5759,2477);
L(5659,2477);
ctx.stroke();
ctx.closePath();
T(440,2527,10.0,"Right"," 1");
ctx.beginPath();
M(520,2146);
L(620,2146);
M(5759,2146);
L(5659,2146);
ctx.stroke();
ctx.closePath();
T(440,2196,10.0,"Right"," 1.5");
ctx.beginPath();
M(520,1815);
L(620,1815);
M(5759,1815);
L(5659,1815);
ctx.stroke();
ctx.closePath();
T(440,1865,10.0,"Right"," 2");
ctx.beginPath();
M(520,1484);
L(620,1484);
M(5759,1484);
L(5659,1484);
ctx.stroke();
ctx.closePath();
T(440,1534,10.0,"Right"," 2.5");
ctx.beginPath();
M(520,1153);
L(620,1153);
M(5759,1153);
L(5659,1153);
ctx.stroke();
ctx.closePath();
T(440,1203,10.0,"Right"," 3");
ctx.beginPath();
M(520,823);
L(620,823);
M(5759,823);
L(5659,823);
ctx.stroke();
ctx.closePath();
T(440,873,10.0,"Right"," 3.5");
ctx.beginPath();
M(520,492);
L(620,492);
M(5759,492);
L(5659,492);
ctx.stroke();
ctx.closePath();
T(440,542,10.0,"Right"," 4");
ctx.beginPath();
M(520,161);
L(620,161);
M(5759,161);
L(5659,161);
ctx.stroke();
ctx.closePath();
T(440,211,10.0,"Right"," 4.5");
ctx.beginPath();
M(520,3800);
L(520,3700);
M(520,161);
L(520,261);
ctx.stroke();
ctx.closePath();
T(520,3950,10.0,"Center","-10");
ctx.beginPath();
M(1830,3800);
L(1830,3700);
M(1830,161);
L(1830,261);
ctx.stroke();
ctx.closePath();
T(1830,3950,10.0,"Center","-5");
ctx.beginPath();
M(3139,3800);
L(3139,3700);
M(3139,161);
L(3139,261);
ctx.stroke();
ctx.closePath();
T(3139,3950,10.0,"Center"," 0");
ctx.beginPath();
M(4449,3800);
L(4449,3700);
M(4449,161);
L(4449,261);
ctx.stroke();
ctx.closePath();
T(4449,3950,10.0,"Center"," 5");
ctx.beginPath();
M(5759,3800);
L(5759,3700);
M(5759,161);
L(5759,261);
ctx.stroke();
ctx.closePath();
T(5759,3950,10.0,"Center"," 10");
ctx.beginPath();
M(520,161);
L(520,3800);
L(5759,3800);
L(5759,161);
L(520,161);
ctx.closePath();
ctx.stroke();
ctx.beginPath();
M(600,386);
L(600,261);
L(2940,261);
L(2940,386);
L(600,386);
ctx.closePath();
ctx.stroke();
if (typeof(gnuplot.hide_simple_5_plot_1) == "undefined"|| !gnuplot.hide_simple_5_plot_1) {
ctx.strokeStyle = "rgb(255,000,000)";
ctx.strokeStyle = "rgb(148,000,211)";
ctx.strokeStyle = "rgb(000,000,000)";
T(2360,373,10.0,"Right","real(sin(x)**besj0(x))");
ctx.strokeStyle = "rgb(255,000,000)";
ctx.strokeStyle = "rgb(148,000,211)";
ctx.beginPath();
M(2440,323);
L(2860,323);
M(520,2370);
L(533,2356);
L(546,2340);
L(559,2322);
L(573,2303);
L(586,2281);
L(599,2255);
L(612,2224);
L(625,2184);
L(638,2130);
L(651,2042);
L(664,1816);
L(678,2069);
L(691,2258);
L(704,2332);
L(717,2374);
L(730,2401);
L(743,2420);
L(756,2433);
L(769,2443);
L(783,2451);
L(796,2456);
L(809,2461);
L(822,2465);
L(835,2468);
L(848,2471);
L(861,2474);
L(875,2477);
L(888,2481);
L(901,2485);
L(914,2489);
L(927,2494);
L(940,2500);
L(953,2506);
L(966,2513);
L(980,2521);
L(993,2530);
L(1006,2540);
L(1019,2550);
L(1032,2561);
L(1045,2573);
L(1058,2585);
L(1071,2598);
L(1085,2611);
L(1098,2624);
L(1111,2638);
L(1124,2651);
L(1137,2665);
L(1150,2678);
L(1163,2691);
L(1177,2704);
L(1190,2717);
L(1203,2728);
L(1216,2739);
L(1229,2750);
L(1242,2760);
L(1255,2769);
L(1268,2777);
L(1282,2784);
L(1295,2791);
L(1308,2796);
L(1321,2802);
L(1334,2806);
L(1347,2810);
L(1360,2813);
L(1373,2816);
L(1387,2819);
L(1400,2822);
L(1413,2826);
L(1426,2830);
L(1439,2836);
L(1452,2845);
L(1465,2858);
L(1479,2884);
L(1492,2967);
L(1505,2798);
L(1518,2727);
L(1531,2679);
L(1544,2643);
L(1557,2613);
L(1570,2588);
L(1584,2566);
L(1597,2548);
L(1610,2532);
L(1623,2519);
L(1636,2508);
L(1649,2498);
L(1662,2490);
L(1675,2484);
L(1689,2478);
L(1702,2474);
L(1715,2471);
L(1728,2469);
L(1741,2468);
L(1754,2467);
L(1767,2467);
L(1781,2468);
L(1794,2469);
L(1807,2470);
L(1820,2471);
L(1833,2472);
L(1846,2473);
L(1859,2475);
L(1872,2476);
L(1886,2476);
L(1899,2477);
L(1912,2477);
L(1925,2476);
L(1938,2475);
L(1951,2474);
L(1964,2471);
L(1977,2468);
L(1991,2464);
L(2004,2459);
L(2017,2454);
L(2030,2447);
L(2043,2439);
L(2056,2430);
L(2069,2420);
L(2083,2408);
L(2096,2395);
L(2109,2381);
L(2122,2364);
L(2135,2346);
L(2148,2325);
L(2161,2303);
L(2174,2277);
L(2188,2249);
L(2201,2217);
L(2214,2181);
L(2227,2139);
L(2240,2089);
L(2253,2030);
L(2266,1954);
L(2279,1850);
L(2293,1686);
L(2306,1330);
L(2319,1526);
L(2332,2213);
L(2345,2343);
L(2358,2401);
L(2371,2432);
L(2385,2449);
L(2398,2458);
L(2411,2463);
L(2424,2465);
L(2437,2465);
L(2450,2465);
L(2463,2465);
L(2476,2467);
L(2490,2469);
L(2503,2473);
L(2516,2480);
L(2529,2490);
L(2542,2503);
L(2555,2519);
L(2568,2539);
L(2581,2563);
L(2595,2591);
L(2608,2623);
L(2621,2659);
L(2634,2700);
L(2647,2744);
L(2660,2793);
L(2673,2844);
L(2687,2898);
L(2700,2954);
L(2713,3012);
L(2726,3071);
L(2739,3129);
L(2752,3187);
L(2765,3244);
L(2778,3298);
L(2792,3349);
L(2805,3397);
L(2818,3440);
L(2831,3478);
L(2844,3510);
L(2857,3537);
L(2870,3558);
L(2883,3573);
L(2897,3583);
L(2910,3586);
L(2923,3584);
L(2936,3577);
L(2949,3565);
L(2962,3548);
L(2975,3528);
L(2989,3505);
L(3002,3479);
L(3015,3450);
L(3028,3420);
L(3041,3388);
L(3054,3356);
L(3067,3323);
L(3080,3289);
L(3094,3255);
L(3107,3222);
L(3120,3188);
L(3133,3155);
L(3146,3122);
L(3159,3088);
L(3172,3055);
L(3185,3021);
L(3199,2988);
L(3212,2954);
L(3225,2920);
L(3238,2887);
L(3251,2854);
L(3264,2822);
L(3277,2790);
L(3290,2759);
L(3304,2730);
L(3317,2702);
L(3330,2675);
L(3343,2650);
L(3356,2626);
L(3369,2604);
L(3382,2584);
L(3396,2566);
L(3409,2550);
L(3422,2535);
L(3435,2523);
L(3448,2512);
L(3461,2502);
L(3474,2495);
L(3487,2489);
L(3501,2484);
L(3514,2480);
L(3527,2478);
L(3540,2477);
L(3553,2477);
L(3566,2477);
L(3579,2478);
L(3592,2480);
L(3606,2482);
L(3619,2484);
L(3632,2486);
L(3645,2488);
L(3658,2490);
L(3671,2492);
L(3684,2493);
L(3698,2493);
L(3711,2492);
L(3724,2491);
L(3737,2489);
L(3750,2485);
L(3763,2480);
L(3776,2473);
L(3789,2464);
L(3803,2453);
L(3816,2439);
L(3829,2422);
L(3842,2400);
L(3855,2374);
L(3868,2342);
L(3881,2301);
L(3894,2249);
L(3908,2179);
L(3921,2082);
L(3934,1932);
L(3947,1647);
L(3960,375);
L(3973,2149);
L(3986,2394);
L(4000,2519);
L(4013,2605);
L(4026,2670);
L(4039,2722);
L(4052,2764);
L(4065,2799);
L(4078,2827);
L(4091,2850);
L(4105,2868);
L(4118,2882);
L(4131,2893);
L(4144,2900);
L(4157,2904);
L(4170,2906);
L(4183,2905);
L(4196,2901);
L(4210,2895);
L(4223,2888);
L(4236,2878);
L(4249,2867);
L(4262,2854);
L(4275,2839);
L(4288,2823);
L(4302,2806);
L(4315,2787);
L(4328,2768);
L(4341,2748);
L(4354,2727);
L(4367,2706);
L(4380,2684);
L(4393,2662);
L(4407,2640);
L(4420,2619);
L(4433,2598);
L(4446,2578);
L(4459,2559);
L(4472,2541);
L(4485,2525);
L(4498,2511);
L(4512,2498);
L(4525,2488);
L(4538,2481);
L(4551,2476);
L(4564,2474);
L(4577,2475);
L(4590,2478);
L(4604,2485);
L(4617,2495);
L(4630,2508);
L(4643,2524);
L(4656,2543);
L(4669,2564);
L(4682,2589);
L(4695,2616);
L(4709,2646);
L(4722,2679);
L(4735,2715);
L(4748,2757);
L(4761,2805);
L(4774,2870);
L(4787,2915);
L(4800,2797);
L(4814,2752);
L(4827,2722);
L(4840,2698);
L(4853,2678);
L(4866,2661);
L(4879,2644);
L(4892,2629);
L(4906,2615);
L(4919,2602);
L(4932,2590);
L(4945,2578);
L(4958,2567);
L(4971,2557);
L(4984,2547);
L(4997,2538);
L(5011,2529);
L(5024,2521);
L(5037,2514);
L(5050,2508);
L(5063,2502);
L(5076,2497);
L(5089,2492);
L(5102,2488);
L(5116,2485);
L(5129,2482);
L(5142,2480);
L(5155,2479);
L(5168,2478);
L(5181,2477);
L(5194,2477);
L(5208,2477);
L(5221,2477);
L(5234,2478);
L(5247,2479);
L(5260,2480);
L(5273,2481);
L(5286,2482);
L(5299,2482);
L(5313,2483);
L(5326,2484);
L(5339,2484);
L(5352,2484);
L(5365,2483);
L(5378,2482);
L(5391,2480);
L(5404,2477);
L(5418,2474);
L(5431,2469);
L(5444,2463);
L(5457,2456);
L(5470,2447);
L(5483,2436);
L(5496,2422);
L(5510,2406);
L(5523,2386);
L(5536,2360);
L(5549,2327);
L(5562,2284);
L(5575,2222);
L(5588,2121);
L(5601,1881);
L(5615,2034);
L(5628,2239);
L(5641,2326);
L(5654,2382);
L(5667,2425);
L(5680,2460);
L(5693,2490);
L(5706,2515);
L(5720,2538);
L(5733,2557);
L(5746,2574);
L(5759,2588);
ctx.stroke();
ctx.closePath();
} // End simple_5_plot_1 
ctx.lineWidth = 1;
ctx.strokeStyle = "rgb(000,000,000)";
ctx.beginPath();
M(520,161);
L(520,3800);
L(5759,3800);
L(5759,161);
L(520,161);
ctx.closePath();
ctx.stroke();

// plot boundaries and axis scaling information for mousing 
gnuplot.plot_term_xmax = 600;
gnuplot.plot_term_ymax = 400;
gnuplot.plot_xmin = 52.0;
gnuplot.plot_xmax = 575.9;
gnuplot.plot_ybot = 380.0;
gnuplot.plot_ytop = 16.1;
gnuplot.plot_width = 523.9;
gnuplot.plot_height = 363.9;
gnuplot.plot_axis_xmin = -10;
gnuplot.plot_axis_xmax = 10;
gnuplot.plot_axis_ymin = -1;
gnuplot.plot_axis_ymax = 4.5;
gnuplot.plot_axis_x2min = "none"
gnuplot.plot_axis_y2min = "none"
gnuplot.plot_logaxis_x = 0;
gnuplot.plot_logaxis_y = 0;
gnuplot.plot_axis_width = gnuplot.plot_axis_xmax - gnuplot.plot_axis_xmin;
gnuplot.plot_axis_height = gnuplot.plot_axis_ymax - gnuplot.plot_axis_ymin;
gnuplot.plot_timeaxis_x = "";
}
