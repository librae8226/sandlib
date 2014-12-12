function simple_6() {
canvas = document.getElementById("simple_6");
ctx = canvas.getContext("2d");
// Reinitialize mouse tracking and zoom for this particular plot
if ((typeof(gnuplot.active_plot) == "undefined" || gnuplot.active_plot != simple_6)  &&  typeof(gnuplot.mouse_update) != "undefined") {
  gnuplot.active_plot_name = "simple_6";
  gnuplot.active_plot = simple_6;
  canvas.onmousemove = gnuplot.mouse_update;
  canvas.onmouseup = gnuplot.zoom_in;
  canvas.onmousedown = gnuplot.saveclick;
  canvas.onkeypress = gnuplot.do_hotkey;
  if (canvas.attachEvent) {canvas.attachEvent('mouseover', simple_6);}
  else if (canvas.addEventListener) {canvas.addEventListener('mouseover', simple_6, false);} 
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
M(360,3234);
L(460,3234);
M(5759,3234);
L(5659,3234);
ctx.stroke();
ctx.closePath();
T(280,3284,10.0,"Right","-4");
ctx.beginPath();
M(360,2551);
L(460,2551);
M(5759,2551);
L(5659,2551);
ctx.stroke();
ctx.closePath();
T(280,2601,10.0,"Right","-2");
ctx.beginPath();
M(360,1868);
L(460,1868);
M(5759,1868);
L(5659,1868);
ctx.stroke();
ctx.closePath();
T(280,1918,10.0,"Right"," 0");
ctx.beginPath();
M(360,1185);
L(460,1185);
M(5759,1185);
L(5659,1185);
ctx.stroke();
ctx.closePath();
T(280,1235,10.0,"Right"," 2");
ctx.beginPath();
M(360,502);
L(460,502);
M(5759,502);
L(5659,502);
ctx.stroke();
ctx.closePath();
T(280,552,10.0,"Right"," 4");
ctx.beginPath();
M(482,3575);
L(482,3475);
M(482,161);
L(482,261);
ctx.stroke();
ctx.closePath();
T(482,3725,10.0,"Center","-15");
ctx.beginPath();
M(1341,3575);
L(1341,3475);
M(1341,161);
L(1341,261);
ctx.stroke();
ctx.closePath();
T(1341,3725,10.0,"Center","-10");
ctx.beginPath();
M(2200,3575);
L(2200,3475);
M(2200,161);
L(2200,261);
ctx.stroke();
ctx.closePath();
T(2200,3725,10.0,"Center","-5");
ctx.beginPath();
M(3060,3575);
L(3060,3475);
M(3060,161);
L(3060,261);
ctx.stroke();
ctx.closePath();
T(3060,3725,10.0,"Center"," 0");
ctx.beginPath();
M(3919,3575);
L(3919,3475);
M(3919,161);
L(3919,261);
ctx.stroke();
ctx.closePath();
T(3919,3725,10.0,"Center"," 5");
ctx.beginPath();
M(4778,3575);
L(4778,3475);
M(4778,161);
L(4778,261);
ctx.stroke();
ctx.closePath();
T(4778,3725,10.0,"Center"," 10");
ctx.beginPath();
M(5637,3575);
L(5637,3475);
M(5637,161);
L(5637,261);
ctx.stroke();
ctx.closePath();
T(5637,3725,10.0,"Center"," 15");
ctx.beginPath();
M(360,161);
L(360,3575);
L(5759,3575);
L(5759,161);
L(360,161);
ctx.closePath();
ctx.stroke();
ctx.beginPath();
M(879,3900);
L(879,3775);
L(5239,3775);
L(5239,3900);
L(879,3900);
ctx.closePath();
ctx.stroke();
if (typeof(gnuplot.hide_simple_6_plot_1) == "undefined"|| !gnuplot.hide_simple_6_plot_1) {
ctx.strokeStyle = "rgb(255,000,000)";
ctx.strokeStyle = "rgb(148,000,211)";
ctx.strokeStyle = "rgb(000,000,000)";
T(2479,3887,10.0,"Right","real(tan(x)/atan(x))");
ctx.strokeStyle = "rgb(255,000,000)";
ctx.strokeStyle = "rgb(148,000,211)";
ctx.beginPath();
M(2559,3837);
L(2979,3837);
M(360,1868);
L(374,1886);
L(387,1904);
L(401,1923);
L(414,1942);
L(428,1962);
L(441,1984);
L(455,2007);
L(468,2033);
L(482,2063);
L(495,2096);
L(509,2135);
L(522,2182);
L(536,2241);
L(549,2317);
L(563,2421);
L(577,2575);
L(590,2829);
L(604,3338);
L(606,3575);
M(655,161);
L(658,470);
L(671,938);
L(685,1178);
L(698,1325);
L(712,1426);
L(725,1500);
L(739,1558);
L(752,1604);
L(766,1642);
L(779,1675);
L(793,1704);
L(807,1730);
L(820,1754);
L(834,1775);
L(847,1796);
L(861,1815);
L(874,1834);
L(888,1852);
L(901,1870);
L(915,1888);
L(928,1906);
L(942,1925);
L(955,1945);
L(969,1965);
L(982,1988);
L(996,2012);
L(1010,2038);
L(1023,2068);
L(1037,2102);
L(1050,2143);
L(1064,2191);
L(1077,2252);
L(1091,2332);
L(1104,2441);
L(1118,2604);
L(1131,2877);
L(1145,3439);
L(1146,3575);
M(1195,161);
L(1199,517);
L(1212,956);
L(1226,1186);
L(1240,1329);
L(1253,1428);
L(1267,1501);
L(1280,1558);
L(1294,1604);
L(1307,1643);
L(1321,1675);
L(1334,1704);
L(1348,1730);
L(1361,1754);
L(1375,1776);
L(1388,1796);
L(1402,1816);
L(1415,1835);
L(1429,1853);
L(1443,1872);
L(1456,1890);
L(1470,1909);
L(1483,1928);
L(1497,1948);
L(1510,1969);
L(1524,1992);
L(1537,2017);
L(1551,2044);
L(1564,2075);
L(1578,2111);
L(1591,2153);
L(1605,2204);
L(1618,2268);
L(1632,2352);
L(1645,2468);
L(1659,2643);
L(1673,2940);
L(1686,3570);
L(1686,3575);
M(1735,161);
L(1740,545);
L(1754,962);
L(1767,1185);
L(1781,1326);
L(1794,1424);
L(1808,1497);
L(1821,1554);
L(1835,1601);
L(1848,1639);
L(1862,1673);
L(1876,1702);
L(1889,1728);
L(1903,1752);
L(1916,1775);
L(1930,1796);
L(1943,1816);
L(1957,1836);
L(1970,1855);
L(1984,1874);
L(1997,1893);
L(2011,1912);
L(2024,1933);
L(2038,1954);
L(2051,1976);
L(2065,2000);
L(2078,2026);
L(2092,2055);
L(2106,2088);
L(2119,2127);
L(2133,2172);
L(2146,2227);
L(2160,2296);
L(2173,2387);
L(2187,2515);
L(2200,2709);
L(2214,3045);
L(2224,3575);
M(2277,161);
L(2281,520);
L(2295,931);
L(2309,1157);
L(2322,1300);
L(2336,1401);
L(2349,1476);
L(2363,1535);
L(2376,1584);
L(2390,1624);
L(2403,1659);
L(2417,1690);
L(2430,1718);
L(2444,1744);
L(2457,1768);
L(2471,1791);
L(2484,1813);
L(2498,1834);
L(2511,1855);
L(2525,1877);
L(2539,1898);
L(2552,1920);
L(2566,1944);
L(2579,1968);
L(2593,1995);
L(2606,2024);
L(2620,2056);
L(2633,2092);
L(2647,2133);
L(2660,2182);
L(2674,2240);
L(2687,2312);
L(2701,2404);
L(2714,2527);
L(2728,2703);
L(2742,2974);
L(2755,3455);
L(2757,3575);
M(2827,161);
L(2836,528);
L(2850,812);
L(2863,992);
L(2877,1116);
L(2890,1207);
L(2904,1277);
L(2917,1331);
L(2931,1375);
L(2944,1410);
L(2958,1439);
L(2972,1463);
L(2985,1482);
L(2999,1497);
L(3012,1509);
L(3026,1518);
L(3039,1523);
L(3053,1526);
L(3066,1526);
L(3080,1523);
L(3093,1518);
L(3107,1509);
L(3120,1497);
L(3134,1482);
L(3147,1463);
L(3161,1439);
L(3175,1410);
L(3188,1375);
L(3202,1331);
L(3215,1277);
L(3229,1207);
L(3242,1116);
L(3256,992);
L(3269,812);
L(3283,528);
L(3292,161);
M(3362,3575);
L(3364,3455);
L(3377,2974);
L(3391,2703);
L(3405,2527);
L(3418,2404);
L(3432,2312);
L(3445,2240);
L(3459,2182);
L(3472,2133);
L(3486,2092);
L(3499,2056);
L(3513,2024);
L(3526,1995);
L(3540,1968);
L(3553,1944);
L(3567,1920);
L(3580,1898);
L(3594,1877);
L(3608,1855);
L(3621,1834);
L(3635,1813);
L(3648,1791);
L(3662,1768);
L(3675,1744);
L(3689,1718);
L(3702,1690);
L(3716,1659);
L(3729,1624);
L(3743,1584);
L(3756,1535);
L(3770,1476);
L(3783,1401);
L(3797,1300);
L(3810,1157);
L(3824,931);
L(3838,520);
L(3842,161);
M(3895,3575);
L(3905,3045);
L(3919,2709);
L(3932,2515);
L(3946,2387);
L(3959,2296);
L(3973,2227);
L(3986,2172);
L(4000,2127);
L(4013,2088);
L(4027,2055);
L(4041,2026);
L(4054,2000);
L(4068,1976);
L(4081,1954);
L(4095,1933);
L(4108,1912);
L(4122,1893);
L(4135,1874);
L(4149,1855);
L(4162,1836);
L(4176,1816);
L(4189,1796);
L(4203,1775);
L(4216,1752);
L(4230,1728);
L(4243,1702);
L(4257,1673);
L(4271,1639);
L(4284,1601);
L(4298,1554);
L(4311,1497);
L(4325,1424);
L(4338,1326);
L(4352,1185);
L(4365,962);
L(4379,545);
L(4384,161);
M(4433,3575);
L(4433,3570);
L(4446,2940);
L(4460,2643);
L(4474,2468);
L(4487,2352);
L(4501,2268);
L(4514,2204);
L(4528,2153);
L(4541,2111);
L(4555,2075);
L(4568,2044);
L(4582,2017);
L(4595,1992);
L(4609,1969);
L(4622,1948);
L(4636,1928);
L(4649,1909);
L(4663,1890);
L(4676,1872);
L(4690,1853);
L(4704,1835);
L(4717,1816);
L(4731,1796);
L(4744,1776);
L(4758,1754);
L(4771,1730);
L(4785,1704);
L(4798,1675);
L(4812,1643);
L(4825,1604);
L(4839,1558);
L(4852,1501);
L(4866,1428);
L(4879,1329);
L(4893,1186);
L(4907,956);
L(4920,517);
L(4924,161);
M(4973,3575);
L(4974,3439);
L(4988,2877);
L(5001,2604);
L(5015,2441);
L(5028,2332);
L(5042,2252);
L(5055,2191);
L(5069,2143);
L(5082,2102);
L(5096,2068);
L(5109,2038);
L(5123,2012);
L(5137,1988);
L(5150,1965);
L(5164,1945);
L(5177,1925);
L(5191,1906);
L(5204,1888);
L(5218,1870);
L(5231,1852);
L(5245,1834);
L(5258,1815);
L(5272,1796);
L(5285,1775);
L(5299,1754);
L(5312,1730);
L(5326,1704);
L(5340,1675);
L(5353,1642);
L(5367,1604);
L(5380,1558);
L(5394,1500);
L(5407,1426);
L(5421,1325);
L(5434,1178);
L(5448,938);
L(5461,470);
L(5464,161);
M(5513,3575);
L(5515,3338);
L(5529,2829);
L(5542,2575);
L(5556,2421);
L(5570,2317);
L(5583,2241);
L(5597,2182);
L(5610,2135);
L(5624,2096);
L(5637,2063);
L(5651,2033);
L(5664,2007);
L(5678,1984);
L(5691,1962);
L(5705,1942);
L(5718,1923);
L(5732,1904);
L(5745,1886);
L(5759,1868);
ctx.stroke();
ctx.closePath();
} // End simple_6_plot_1 
if (typeof(gnuplot.hide_simple_6_plot_2) == "undefined"|| !gnuplot.hide_simple_6_plot_2) {
ctx.lineWidth = 1;
ctx.strokeStyle = "rgb(000,171,000)";
ctx.strokeStyle = "rgb(000,158,115)";
ctx.strokeStyle = "rgb(000,000,000)";
T(4659,3887,10.0,"Right","1/x");
ctx.strokeStyle = "rgb(000,171,000)";
ctx.strokeStyle = "rgb(000,158,115)";
ctx.beginPath();
M(4739,3837);
L(5159,3837);
M(360,1890);
L(374,1890);
L(387,1890);
L(401,1890);
L(414,1890);
L(428,1890);
L(441,1890);
L(455,1891);
L(468,1891);
L(482,1891);
L(495,1891);
L(509,1891);
L(522,1891);
L(536,1891);
L(549,1891);
L(563,1892);
L(577,1892);
L(590,1892);
L(604,1892);
L(617,1892);
L(631,1892);
L(644,1892);
L(658,1892);
L(671,1893);
L(685,1893);
L(698,1893);
L(712,1893);
L(725,1893);
L(739,1893);
L(752,1893);
L(766,1894);
L(779,1894);
L(793,1894);
L(807,1894);
L(820,1894);
L(834,1894);
L(847,1895);
L(861,1895);
L(874,1895);
L(888,1895);
L(901,1895);
L(915,1895);
L(928,1896);
L(942,1896);
L(955,1896);
L(969,1896);
L(982,1896);
L(996,1896);
L(1010,1897);
L(1023,1897);
L(1037,1897);
L(1050,1897);
L(1064,1897);
L(1077,1898);
L(1091,1898);
L(1104,1898);
L(1118,1898);
L(1131,1898);
L(1145,1899);
L(1158,1899);
L(1172,1899);
L(1185,1899);
L(1199,1900);
L(1212,1900);
L(1226,1900);
L(1240,1900);
L(1253,1900);
L(1267,1901);
L(1280,1901);
L(1294,1901);
L(1307,1901);
L(1321,1902);
L(1334,1902);
L(1348,1902);
L(1361,1903);
L(1375,1903);
L(1388,1903);
L(1402,1903);
L(1415,1904);
L(1429,1904);
L(1443,1904);
L(1456,1905);
L(1470,1905);
L(1483,1905);
L(1497,1906);
L(1510,1906);
L(1524,1906);
L(1537,1907);
L(1551,1907);
L(1564,1907);
L(1578,1908);
L(1591,1908);
L(1605,1908);
L(1618,1909);
L(1632,1909);
L(1645,1909);
L(1659,1910);
L(1673,1910);
L(1686,1911);
L(1700,1911);
L(1713,1912);
L(1727,1912);
L(1740,1912);
L(1754,1913);
L(1767,1913);
L(1781,1914);
L(1794,1914);
L(1808,1915);
L(1821,1915);
L(1835,1916);
L(1848,1916);
L(1862,1917);
L(1876,1918);
L(1889,1918);
L(1903,1919);
L(1916,1919);
L(1930,1920);
L(1943,1921);
L(1957,1921);
L(1970,1922);
L(1984,1923);
L(1997,1923);
L(2011,1924);
L(2024,1925);
L(2038,1925);
L(2051,1926);
L(2065,1927);
L(2078,1928);
L(2092,1929);
L(2106,1930);
L(2119,1930);
L(2133,1931);
L(2146,1932);
L(2160,1933);
L(2173,1934);
L(2187,1935);
L(2200,1936);
L(2214,1937);
L(2227,1939);
L(2241,1940);
L(2254,1941);
L(2268,1942);
L(2281,1943);
L(2295,1945);
L(2309,1946);
L(2322,1948);
L(2336,1949);
L(2349,1951);
L(2363,1952);
L(2376,1954);
L(2390,1956);
L(2403,1957);
L(2417,1959);
L(2430,1961);
L(2444,1963);
L(2457,1965);
L(2471,1968);
L(2484,1970);
L(2498,1972);
L(2511,1975);
L(2525,1978);
L(2539,1981);
L(2552,1984);
L(2566,1987);
L(2579,1990);
L(2593,1994);
L(2606,1997);
L(2620,2001);
L(2633,2006);
L(2647,2010);
L(2660,2015);
L(2674,2020);
L(2687,2026);
L(2701,2032);
L(2714,2038);
L(2728,2045);
L(2742,2053);
L(2755,2061);
L(2769,2070);
L(2782,2080);
L(2796,2090);
L(2809,2102);
L(2823,2116);
L(2836,2131);
L(2850,2148);
L(2863,2167);
L(2877,2189);
L(2890,2215);
L(2904,2245);
L(2917,2281);
L(2931,2324);
L(2944,2378);
L(2958,2446);
L(2972,2535);
L(2985,2656);
L(2999,2832);
L(3012,3107);
L(3025,3575);
M(3094,161);
L(3107,629);
L(3120,904);
L(3134,1080);
L(3147,1201);
L(3161,1290);
L(3175,1358);
L(3188,1412);
L(3202,1455);
L(3215,1491);
L(3229,1521);
L(3242,1547);
L(3256,1569);
L(3269,1588);
L(3283,1605);
L(3296,1620);
L(3310,1634);
L(3323,1646);
L(3337,1656);
L(3350,1666);
L(3364,1675);
L(3377,1683);
L(3391,1691);
L(3405,1698);
L(3418,1704);
L(3432,1710);
L(3445,1716);
L(3459,1721);
L(3472,1726);
L(3486,1730);
L(3499,1735);
L(3513,1739);
L(3526,1742);
L(3540,1746);
L(3553,1749);
L(3567,1752);
L(3580,1755);
L(3594,1758);
L(3608,1761);
L(3621,1764);
L(3635,1766);
L(3648,1768);
L(3662,1771);
L(3675,1773);
L(3689,1775);
L(3702,1777);
L(3716,1779);
L(3729,1780);
L(3743,1782);
L(3756,1784);
L(3770,1785);
L(3783,1787);
L(3797,1788);
L(3810,1790);
L(3824,1791);
L(3838,1793);
L(3851,1794);
L(3865,1795);
L(3878,1796);
L(3892,1797);
L(3905,1799);
L(3919,1800);
L(3932,1801);
L(3946,1802);
L(3959,1803);
L(3973,1804);
L(3986,1805);
L(4000,1806);
L(4013,1806);
L(4027,1807);
L(4041,1808);
L(4054,1809);
L(4068,1810);
L(4081,1811);
L(4095,1811);
L(4108,1812);
L(4122,1813);
L(4135,1813);
L(4149,1814);
L(4162,1815);
L(4176,1815);
L(4189,1816);
L(4203,1817);
L(4216,1817);
L(4230,1818);
L(4243,1818);
L(4257,1819);
L(4271,1820);
L(4284,1820);
L(4298,1821);
L(4311,1821);
L(4325,1822);
L(4338,1822);
L(4352,1823);
L(4365,1823);
L(4379,1824);
L(4392,1824);
L(4406,1824);
L(4419,1825);
L(4433,1825);
L(4446,1826);
L(4460,1826);
L(4474,1827);
L(4487,1827);
L(4501,1827);
L(4514,1828);
L(4528,1828);
L(4541,1828);
L(4555,1829);
L(4568,1829);
L(4582,1829);
L(4595,1830);
L(4609,1830);
L(4622,1830);
L(4636,1831);
L(4649,1831);
L(4663,1831);
L(4676,1832);
L(4690,1832);
L(4704,1832);
L(4717,1833);
L(4731,1833);
L(4744,1833);
L(4758,1833);
L(4771,1834);
L(4785,1834);
L(4798,1834);
L(4812,1835);
L(4825,1835);
L(4839,1835);
L(4852,1835);
L(4866,1836);
L(4879,1836);
L(4893,1836);
L(4907,1836);
L(4920,1836);
L(4934,1837);
L(4947,1837);
L(4961,1837);
L(4974,1837);
L(4988,1838);
L(5001,1838);
L(5015,1838);
L(5028,1838);
L(5042,1838);
L(5055,1839);
L(5069,1839);
L(5082,1839);
L(5096,1839);
L(5109,1839);
L(5123,1840);
L(5137,1840);
L(5150,1840);
L(5164,1840);
L(5177,1840);
L(5191,1840);
L(5204,1841);
L(5218,1841);
L(5231,1841);
L(5245,1841);
L(5258,1841);
L(5272,1841);
L(5285,1842);
L(5299,1842);
L(5312,1842);
L(5326,1842);
L(5340,1842);
L(5353,1842);
L(5367,1843);
L(5380,1843);
L(5394,1843);
L(5407,1843);
L(5421,1843);
L(5434,1843);
L(5448,1843);
L(5461,1844);
L(5475,1844);
L(5488,1844);
L(5502,1844);
L(5515,1844);
L(5529,1844);
L(5542,1844);
L(5556,1844);
L(5570,1845);
L(5583,1845);
L(5597,1845);
L(5610,1845);
L(5624,1845);
L(5637,1845);
L(5651,1845);
L(5664,1845);
L(5678,1846);
L(5691,1846);
L(5705,1846);
L(5718,1846);
L(5732,1846);
L(5745,1846);
L(5759,1846);
ctx.stroke();
ctx.closePath();
} // End simple_6_plot_2 
ctx.lineWidth = 1;
ctx.strokeStyle = "rgb(000,000,000)";
ctx.beginPath();
M(360,161);
L(360,3575);
L(5759,3575);
L(5759,161);
L(360,161);
ctx.closePath();
ctx.stroke();

// plot boundaries and axis scaling information for mousing 
gnuplot.plot_term_xmax = 600;
gnuplot.plot_term_ymax = 400;
gnuplot.plot_xmin = 36.0;
gnuplot.plot_xmax = 575.9;
gnuplot.plot_ybot = 357.5;
gnuplot.plot_ytop = 16.1;
gnuplot.plot_width = 539.9;
gnuplot.plot_height = 341.4;
gnuplot.plot_axis_xmin = -15.708;
gnuplot.plot_axis_xmax = 15.708;
gnuplot.plot_axis_ymin = -5;
gnuplot.plot_axis_ymax = 5;
gnuplot.plot_axis_x2min = "none"
gnuplot.plot_axis_y2min = "none"
gnuplot.plot_logaxis_x = 0;
gnuplot.plot_logaxis_y = 0;
gnuplot.plot_axis_width = gnuplot.plot_axis_xmax - gnuplot.plot_axis_xmin;
gnuplot.plot_axis_height = gnuplot.plot_axis_ymax - gnuplot.plot_axis_ymin;
gnuplot.plot_timeaxis_x = "";
}