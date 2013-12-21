#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
#include <cassert>
#include <cmath>

#define DEBUG

typedef std::vector< std::vector<int> > matrix;
typedef std::vector< std::vector<double> > pmatrix;
const int psh = 25, psw = 10;
const std::pair <int,int> patternSize(psh, psw);
std::vector < pmatrix > patterns(10, pmatrix(psh, pmatrix::value_type(psw, 0.0)));

double patternArray[][psh][psw] = {{{0, 0.00107181, 0.00643087, 0.00643087, 0.00857449, 0.00857449, 0.00643087, 0.00643087, 0.00214362, 0}
, {0, 0.00321543, 0.00643087, 0.00750268, 0.0096463, 0.0096463, 0.00750268, 0.00643087, 0.00428725, 0.00107181}
, {0.00321543, 0.00321543, 0.00428725, 0.00750268, 0.00643087, 0.00643087, 0.00643087, 0.00428725, 0.00321543, 0.00321543}
, {0.00643087, 0.00535906, 0.00535906, 0.00535906, 0.00214362, 0.00107181, 0.00535906, 0.00535906, 0.00535906, 0.00321543}
, {0.00643087, 0.00535906, 0.00643087, 0.00535906, 0.00214362, 0.00107181, 0.00535906, 0.00643087, 0.00535906, 0.00321543}
, {0.00643087, 0.00857449, 0.00643087, 0.00214362, 0, 0, 0.00107181, 0.00535906, 0.00857449, 0.00428725}
, {0.00750268, 0.00857449, 0.00428725, 0.00107181, 0, 0, 0, 0.00214362, 0.00750268, 0.00750268}
, {0.0096463, 0.00857449, 0.00214362, 0, 0, 0, 0, 0, 0.00750268, 0.0096463}
, {0.0096463, 0.00857449, 0.00107181, 0, 0, 0, 0, 0, 0.00750268, 0.0096463}
, {0.0096463, 0.00750268, 0, 0, 0, 0, 0, 0, 0.00750268, 0.0096463}
, {0.0096463, 0.00750268, 0, 0, 0, 0, 0, 0, 0.00750268, 0.0096463}
, {0.0096463, 0.00750268, 0, 0, 0, 0, 0, 0, 0.00750268, 0.0096463}
, {0.0096463, 0.00750268, 0, 0, 0, 0, 0, 0, 0.00750268, 0.0096463}
, {0.0096463, 0.00750268, 0, 0, 0, 0, 0, 0, 0.00750268, 0.0096463}
, {0.0096463, 0.00750268, 0, 0, 0, 0, 0, 0, 0.00750268, 0.0096463}
, {0.0096463, 0.00750268, 0, 0, 0, 0, 0, 0, 0.00750268, 0.0096463}
, {0.0096463, 0.00750268, 0, 0, 0, 0, 0, 0, 0.00750268, 0.0096463}
, {0.0096463, 0.00750268, 0, 0, 0, 0, 0, 0, 0.00750268, 0.0096463}
, {0.00750268, 0.00750268, 0.00214362, 0, 0, 0, 0.00214362, 0.00214362, 0.00750268, 0.00750268}
, {0.00535906, 0.00857449, 0.00428725, 0, 0, 0, 0.00321543, 0.00321543, 0.00750268, 0.00750268}
, {0.00321543, 0.00857449, 0.00535906, 0.00321543, 0, 0.00321543, 0.00321543, 0.00321543, 0.00428725, 0.00643087}
, {0.00321543, 0.00750268, 0.00535906, 0.00321543, 0.00107181, 0.00321543, 0.00214362, 0.00214362, 0.00428725, 0.00535906}
, {0.00214362, 0.00321543, 0.00750268, 0.00643087, 0.00643087, 0.00643087, 0.00321543, 0.00321543, 0.00214362, 0.00107181}
, {0, 0.00428725, 0.00750268, 0.00857449, 0.0096463, 0.00750268, 0.00643087, 0.00643087, 0.00214362, 0}
, {0, 0.00214362, 0.00643087, 0.00857449, 0.0096463, 0.00643087, 0.00643087, 0.00428725, 0.00107181, 0}
}
, {{0.00114025, 0.00342075, 0.00684151, 0.00570125, 0.00342075, 0.00570125, 0.00684151, 0.00684151, 0.00570125, 0.00114025}
, {0.0022805, 0.00684151, 0.0102623, 0.00912201, 0.00684151, 0.00684151, 0.00912201, 0.00684151, 0.00570125, 0.00114025}
, {0.00570125, 0.00912201, 0.00912201, 0.00912201, 0.00684151, 0.00912201, 0.0102623, 0.00684151, 0.00570125, 0.00114025}
, {0.00114025, 0.00342075, 0.00342075, 0.004561, 0.00342075, 0.00342075, 0.00570125, 0.00342075, 0.00342075, 0.00114025}
, {0.00114025, 0.00342075, 0.00342075, 0.00342075, 0.00342075, 0.00342075, 0.00570125, 0.00342075, 0.00342075, 0}
, {0.00114025, 0.00342075, 0.00342075, 0.00342075, 0.00342075, 0.00342075, 0.00570125, 0.00342075, 0.00342075, 0}
, {0.00114025, 0.00342075, 0.00342075, 0.00342075, 0.00342075, 0.00342075, 0.00570125, 0.00342075, 0.00342075, 0}
, {0, 0.0022805, 0.00342075, 0.00342075, 0.00342075, 0.00342075, 0.00570125, 0.004561, 0.0022805, 0}
, {0, 0.0022805, 0.00342075, 0.00342075, 0.00342075, 0.00342075, 0.00570125, 0.004561, 0.0022805, 0}
, {0, 0.0022805, 0.00342075, 0.00342075, 0.00342075, 0.00342075, 0.00684151, 0.004561, 0.0022805, 0}
, {0, 0.0022805, 0.00342075, 0.00342075, 0.00342075, 0.004561, 0.00798176, 0.004561, 0.0022805, 0}
, {0, 0.0022805, 0.00342075, 0.00342075, 0.00342075, 0.00570125, 0.00798176, 0.00342075, 0.0022805, 0}
, {0, 0.0022805, 0.00342075, 0.00342075, 0.004561, 0.00684151, 0.00684151, 0.00342075, 0.0022805, 0}
, {0, 0.0022805, 0.00342075, 0.00342075, 0.00570125, 0.00684151, 0.00684151, 0.00342075, 0.0022805, 0}
, {0, 0.0022805, 0.00342075, 0.004561, 0.00684151, 0.00570125, 0.00570125, 0.00342075, 0.0022805, 0}
, {0, 0.0022805, 0.00342075, 0.00570125, 0.00684151, 0.00570125, 0.00570125, 0.00342075, 0.0022805, 0}
, {0, 0.0022805, 0.004561, 0.00684151, 0.00684151, 0.00570125, 0.00570125, 0.00342075, 0.0022805, 0}
, {0, 0.0022805, 0.00570125, 0.00684151, 0.00684151, 0.00570125, 0.00570125, 0.00342075, 0.0022805, 0}
, {0, 0.00342075, 0.00570125, 0.00684151, 0.00684151, 0.00570125, 0.00570125, 0.00342075, 0.0022805, 0}
, {0, 0.00342075, 0.00684151, 0.00684151, 0.00684151, 0.00570125, 0.00570125, 0.00342075, 0.0022805, 0}
, {0, 0.004561, 0.00684151, 0.00684151, 0.00684151, 0.00570125, 0.00570125, 0.00342075, 0.0022805, 0}
, {0, 0.004561, 0.00684151, 0.00684151, 0.00684151, 0.00570125, 0.00570125, 0.00342075, 0.0022805, 0}
, {0, 0.004561, 0.00684151, 0.00684151, 0.00684151, 0.00570125, 0.00570125, 0.00342075, 0.0022805, 0}
, {0, 0.004561, 0.00912201, 0.00798176, 0.00684151, 0.00570125, 0.00570125, 0.00570125, 0.004561, 0}
, {0.00342075, 0.00684151, 0.00912201, 0.0102623, 0.00684151, 0.00684151, 0.00684151, 0.00684151, 0.00684151, 0.004561}
}
, {{0.000662252, 0.00198675, 0.000662252, 0.00264901, 0.00596026, 0.00596026, 0.00596026, 0.00198675, 0.00264901, 0}
, {0.000662252, 0.00198675, 0.00529801, 0.00529801, 0.00397351, 0.00397351, 0.00397351, 0.00794702, 0.00529801, 0.000662252}
, {0.000662252, 0.00397351, 0.00596026, 0.00397351, 0.00264901, 0.00264901, 0.00463576, 0.00794702, 0.00927152, 0.0013245}
, {0.000662252, 0.00662252, 0.00529801, 0.00331126, 0.00198675, 0.00331126, 0.00397351, 0.00596026, 0.00927152, 0.00198675}
, {0.00264901, 0.00728477, 0.00463576, 0.00331126, 0.0013245, 0.00264901, 0.00331126, 0.00529801, 0.00860927, 0.00463576}
, {0.00397351, 0.00794702, 0.00397351, 0.00397351, 0.0013245, 0.00198675, 0.0013245, 0.00463576, 0.00728477, 0.00596026}
, {0.00331126, 0.00662252, 0.00596026, 0.00397351, 0.00264901, 0.000662252, 0.0013245, 0.00529801, 0.00662252, 0.00596026}
, {0.00198675, 0.00463576, 0.00596026, 0.00397351, 0.00198675, 0, 0.00264901, 0.00463576, 0.00662252, 0.00596026}
, {0.000662252, 0.00198675, 0.00397351, 0.00264901, 0.000662252, 0, 0.00264901, 0.00463576, 0.00728477, 0.00596026}
, {0, 0.00198675, 0.00331126, 0.00198675, 0.000662252, 0.000662252, 0.00397351, 0.00596026, 0.00728477, 0.00397351}
, {0, 0.000662252, 0.00198675, 0.0013245, 0.000662252, 0.00198675, 0.00397351, 0.00662252, 0.00728477, 0.00198675}
, {0, 0, 0.0013245, 0.0013245, 0.000662252, 0.00331126, 0.00331126, 0.00728477, 0.00662252, 0.000662252}
, {0, 0, 0.0013245, 0.0013245, 0.00264901, 0.00331126, 0.00529801, 0.00728477, 0.00529801, 0}
, {0, 0, 0.0013245, 0.0013245, 0.00331126, 0.00331126, 0.00728477, 0.00662252, 0.00331126, 0}
, {0, 0, 0.0013245, 0.00331126, 0.00264901, 0.00596026, 0.00662252, 0.00463576, 0.0013245, 0}
, {0, 0, 0.00198675, 0.00463576, 0.00397351, 0.00728477, 0.00529801, 0.00198675, 0.0013245, 0.0013245}
, {0, 0.000662252, 0.00264901, 0.00463576, 0.00529801, 0.00596026, 0.00397351, 0.00198675, 0.0013245, 0.00198675}
, {0, 0.0013245, 0.00463576, 0.00662252, 0.00596026, 0.00397351, 0.00198675, 0.00198675, 0.0013245, 0.00198675}
, {0, 0.00264901, 0.00662252, 0.00728477, 0.00662252, 0.0013245, 0, 0, 0.000662252, 0.00198675}
, {0, 0.00529801, 0.00927152, 0.00794702, 0.00596026, 0.00331126, 0.00264901, 0.00264901, 0.00397351, 0.00463576}
, {0.000662252, 0.00794702, 0.00860927, 0.00728477, 0.00529801, 0.00596026, 0.00397351, 0.00463576, 0.00596026, 0.00728477}
, {0.00331126, 0.00860927, 0.00728477, 0.00463576, 0.00529801, 0.00463576, 0.00397351, 0.00397351, 0.00596026, 0.00596026}
, {0.00596026, 0.00927152, 0.00596026, 0.00596026, 0.00662252, 0.00662252, 0.00662252, 0.00794702, 0.00860927, 0.00529801}
, {0.00927152, 0.00860927, 0.00794702, 0.00794702, 0.00728477, 0.00662252, 0.00728477, 0.00860927, 0.00860927, 0.00596026}
, {0.00860927, 0.00794702, 0.00794702, 0.00794702, 0.00728477, 0.00596026, 0.00596026, 0.00728477, 0.00794702, 0.00596026}
}
, {{0, 0, 0.00198413, 0.00396825, 0.00992063, 0.0119048, 0.00992063, 0.00793651, 0, 0}
, {0, 0, 0.00595238, 0.00992063, 0.00992063, 0.00595238, 0.00992063, 0.0119048, 0.00198413, 0}
, {0, 0.00396825, 0.00992063, 0.00992063, 0.00198413, 0.00198413, 0.00595238, 0.0119048, 0.00992063, 0}
, {0, 0.00595238, 0.00992063, 0.00396825, 0, 0, 0, 0.00992063, 0.0119048, 0}
, {0, 0.00793651, 0.00793651, 0, 0, 0, 0, 0.00595238, 0.0119048, 0.00396825}
, {0.00396825, 0.00992063, 0.00595238, 0, 0, 0, 0, 0.00595238, 0.0119048, 0.00595238}
, {0, 0.00595238, 0.00396825, 0, 0, 0, 0, 0.00793651, 0.00992063, 0.00396825}
, {0, 0.00396825, 0.00396825, 0, 0, 0, 0.00198413, 0.00793651, 0.00992063, 0.00396825}
, {0, 0.00396825, 0.00396825, 0, 0.00198413, 0.00198413, 0.00396825, 0.00793651, 0.00595238, 0.00198413}
, {0, 0.00198413, 0.00595238, 0.00198413, 0.00198413, 0, 0.00595238, 0.00793651, 0.00396825, 0}
, {0, 0, 0.00396825, 0.00595238, 0.00396825, 0.00595238, 0.00992063, 0.00793651, 0.00396825, 0}
, {0, 0, 0, 0, 0.00595238, 0.0119048, 0.0119048, 0.0119048, 0.00198413, 0}
, {0, 0, 0, 0, 0.00992063, 0.00595238, 0.00793651, 0.0119048, 0.00992063, 0}
, {0, 0, 0, 0.00198413, 0.00198413, 0, 0.00198413, 0.00992063, 0.0119048, 0.00198413}
, {0, 0, 0, 0, 0, 0, 0, 0.00396825, 0.0119048, 0.00793651}
, {0, 0, 0, 0, 0, 0, 0, 0.00198413, 0.0119048, 0.00992063}
, {0, 0, 0, 0, 0, 0, 0, 0.00396825, 0.00992063, 0.00992063}
, {0, 0, 0, 0, 0, 0, 0, 0.00396825, 0.00992063, 0.00992063}
, {0.00595238, 0.00595238, 0, 0, 0, 0, 0, 0.00595238, 0.00992063, 0.00793651}
, {0.00992063, 0.0119048, 0.00396825, 0, 0, 0, 0, 0.00595238, 0.0119048, 0.00793651}
, {0.00793651, 0.0119048, 0.00396825, 0, 0, 0, 0.00198413, 0.00793651, 0.00992063, 0.00396825}
, {0.00595238, 0.0119048, 0.00396825, 0, 0, 0, 0.00396825, 0.00992063, 0.00793651, 0.00198413}
, {0.00396825, 0.00992063, 0.00793651, 0.00396825, 0.00198413, 0.00396825, 0.00992063, 0.00992063, 0.00396825, 0}
, {0, 0.00793651, 0.00992063, 0.00595238, 0.00595238, 0.00992063, 0.00992063, 0.00595238, 0, 0}
, {0, 0, 0.00793651, 0.00992063, 0.0119048, 0.0119048, 0.00396825, 0.00198413, 0, 0}
}
, {{0.00160858, 0.00268097, 0.00321716, 0.00536193, 0.00536193, 0.00536193, 0.00321716, 0.00482574, 0.00268097, 0.00214477}
, {0.00160858, 0.00268097, 0.00375335, 0.00536193, 0.00536193, 0.00643432, 0.00428954, 0.00536193, 0.00268097, 0.00214477}
, {0.00160858, 0.00268097, 0.00321716, 0.00536193, 0.00589812, 0.00482574, 0.00482574, 0.00482574, 0.00268097, 0.00214477}
, {0.00160858, 0.00321716, 0.00268097, 0.00536193, 0.00697051, 0.00428954, 0.00536193, 0.00375335, 0.00268097, 0.00160858}
, {0.00160858, 0.00321716, 0.00375335, 0.00589812, 0.00589812, 0.00482574, 0.00536193, 0.00375335, 0.00268097, 0.00107239}
, {0.00160858, 0.00375335, 0.00321716, 0.00643432, 0.00589812, 0.00428954, 0.00697051, 0.00428954, 0.00268097, 0.00107239}
, {0.000536193, 0.00160858, 0.00268097, 0.00536193, 0.00428954, 0.00375335, 0.0080429, 0.00589812, 0.00214477, 0.00107239}
, {0.000536193, 0.00160858, 0.00482574, 0.00536193, 0.00268097, 0.00589812, 0.00965147, 0.00643432, 0.00214477, 0.00107239}
, {0.00107239, 0.00160858, 0.00536193, 0.00428954, 0.00268097, 0.00697051, 0.00965147, 0.00697051, 0.00160858, 0.00107239}
, {0.00107239, 0.00160858, 0.00643432, 0.00428954, 0.00214477, 0.00697051, 0.00911528, 0.00697051, 0.00160858, 0.00107239}
, {0.00160858, 0.00214477, 0.00643432, 0.00268097, 0.00268097, 0.00697051, 0.00911528, 0.00643432, 0.00107239, 0.00107239}
, {0.00160858, 0.00268097, 0.00697051, 0.00214477, 0.00214477, 0.00697051, 0.00857909, 0.00643432, 0.00107239, 0.00107239}
, {0.00214477, 0.00536193, 0.00643432, 0.00321716, 0.00268097, 0.00697051, 0.0101877, 0.00643432, 0.00214477, 0.00214477}
, {0.00214477, 0.00589812, 0.00643432, 0.00482574, 0.00321716, 0.00697051, 0.0101877, 0.00697051, 0.00375335, 0.00268097}
, {0.00321716, 0.00589812, 0.00482574, 0.00428954, 0.00375335, 0.00643432, 0.00911528, 0.00643432, 0.00375335, 0.00160858}
, {0.00268097, 0.00482574, 0.00428954, 0.00375335, 0.00321716, 0.00589812, 0.00857909, 0.00589812, 0.00268097, 0.00107239}
, {0.00428954, 0.00589812, 0.00697051, 0.00697051, 0.00643432, 0.00697051, 0.00857909, 0.0080429, 0.00428954, 0.00107239}
, {0.00321716, 0.00375335, 0.00536193, 0.00536193, 0.00482574, 0.00697051, 0.0080429, 0.00536193, 0.00536193, 0.00268097}
, {0.00375335, 0.00375335, 0.00589812, 0.00536193, 0.00428954, 0.00857909, 0.0080429, 0.00536193, 0.00536193, 0.00321716}
, {0.000536193, 0.000536193, 0.00268097, 0.00214477, 0.00160858, 0.00643432, 0.0075067, 0.00428954, 0.00321716, 0.00214477}
, {0.000536193, 0.00107239, 0.00268097, 0.00160858, 0.00160858, 0.00589812, 0.0075067, 0.00428954, 0.00107239, 0.00107239}
, {0.000536193, 0.00160858, 0.00268097, 0.00214477, 0.00214477, 0.00589812, 0.0075067, 0.00428954, 0.00107239, 0.00107239}
, {0.000536193, 0.00107239, 0.00214477, 0.00214477, 0.00321716, 0.00697051, 0.0075067, 0.00536193, 0.00107239, 0.00107239}
, {0.000536193, 0.000536193, 0.00160858, 0.00160858, 0.00321716, 0.00536193, 0.00536193, 0.00482574, 0.00214477, 0.00107239}
, {0.000536193, 0.000536193, 0.00107239, 0.000536193, 0.00428954, 0.00643432, 0.00482574, 0.00536193, 0.00482574, 0.00160858}
}
, {{0, 0.00277874, 0.00521014, 0.00625217, 0.00694686, 0.00764154, 0.00694686, 0.00555749, 0.00625217, 0.00347343}
, {0.000347343, 0.00382077, 0.00625217, 0.00764154, 0.00868357, 0.00833623, 0.00868357, 0.00833623, 0.00833623, 0.00312609}
, {0.000347343, 0.00451546, 0.00625217, 0.00903091, 0.00903091, 0.00694686, 0.00764154, 0.00903091, 0.00764154, 0.00208406}
, {0.00104203, 0.00521014, 0.0048628, 0.00659951, 0.00625217, 0.00555749, 0.0048628, 0.00555749, 0.00451546, 0.00138937}
, {0.00104203, 0.0048628, 0.00416811, 0.00555749, 0.00555749, 0.00451546, 0.00312609, 0.00208406, 0.00382077, 0.000694686}
, {0.00104203, 0.00555749, 0.00416811, 0.00590483, 0.00382077, 0.0024314, 0.000694686, 0.000694686, 0.00138937, 0.000694686}
, {0.00138937, 0.00555749, 0.0048628, 0.00555749, 0.0024314, 0.00138937, 0, 0, 0.000694686, 0.000347343}
, {0.00138937, 0.00555749, 0.00521014, 0.00659951, 0.00312609, 0.0024314, 0.00104203, 0.000347343, 0.000347343, 0.000347343}
, {0.00277874, 0.00590483, 0.00798889, 0.00798889, 0.00590483, 0.00625217, 0.00521014, 0.00208406, 0, 0.000347343}
, {0.00312609, 0.00625217, 0.00833623, 0.0100729, 0.00833623, 0.0072942, 0.00625217, 0.00521014, 0.00138937, 0.000694686}
, {0.0024314, 0.00347343, 0.00451546, 0.00625217, 0.00590483, 0.00625217, 0.00868357, 0.00764154, 0.00416811, 0.000694686}
, {0.00138937, 0.00312609, 0.00451546, 0.00521014, 0.0048628, 0.00347343, 0.00555749, 0.00798889, 0.00659951, 0.00208406}
, {0.00138937, 0.00312609, 0.00416811, 0.0048628, 0.00277874, 0.0024314, 0.00416811, 0.00659951, 0.00798889, 0.00382077}
, {0.00138937, 0.0024314, 0.00382077, 0.00347343, 0.00104203, 0.00138937, 0.00277874, 0.00521014, 0.00764154, 0.00625217}
, {0.000694686, 0.00104203, 0.00173671, 0.00104203, 0.00138937, 0.00173671, 0.00104203, 0.00416811, 0.00694686, 0.00798889}
, {0.000694686, 0.00104203, 0.00173671, 0.00104203, 0.00173671, 0.000694686, 0, 0.00382077, 0.00659951, 0.00798889}
, {0.000347343, 0.00104203, 0.00104203, 0.00138937, 0.00208406, 0, 0.000347343, 0.00416811, 0.00659951, 0.00798889}
, {0.00173671, 0.00173671, 0.0024314, 0.00173671, 0.00173671, 0, 0.000347343, 0.00416811, 0.0072942, 0.0072942}
, {0.00416811, 0.00451546, 0.00382077, 0.0024314, 0.00104203, 0, 0.000694686, 0.0048628, 0.00764154, 0.00521014}
, {0.00416811, 0.00625217, 0.00451546, 0.00277874, 0.00104203, 0.000347343, 0.00208406, 0.00590483, 0.00798889, 0.00382077}
, {0.00416811, 0.00694686, 0.00416811, 0.00347343, 0.00173671, 0.00173671, 0.0048628, 0.00625217, 0.00764154, 0.00173671}
, {0.00208406, 0.00764154, 0.00590483, 0.00416811, 0.00312609, 0.00416811, 0.00590483, 0.00625217, 0.00590483, 0.000347343}
, {0.00173671, 0.00590483, 0.00659951, 0.00451546, 0.0048628, 0.0048628, 0.00659951, 0.00694686, 0.00277874, 0}
, {0.000694686, 0.00347343, 0.00764154, 0.00798889, 0.00764154, 0.00694686, 0.00625217, 0.00451546, 0, 0}
, {0.0024314, 0.00277874, 0.00416811, 0.00625217, 0.00798889, 0.00694686, 0.00416811, 0.000694686, 0, 0}
}
, {{0, 0, 0.00240096, 0.00240096, 0, 0.00360144, 0.0060024, 0.00360144, 0.00240096, 0}
, {0, 0.00120048, 0.00240096, 0.00240096, 0.00240096, 0.00360144, 0.00720288, 0.00480192, 0.00480192, 0.00120048}
, {0, 0.00240096, 0.00360144, 0.00120048, 0.00360144, 0.00480192, 0.00240096, 0, 0, 0}
, {0, 0.00360144, 0.0060024, 0.00240096, 0.00360144, 0.00240096, 0.00120048, 0, 0, 0}
, {0, 0.0060024, 0.0060024, 0.00120048, 0.00360144, 0.00120048, 0.00120048, 0, 0, 0}
, {0.00120048, 0.0060024, 0.00360144, 0.00240096, 0.00240096, 0, 0.00120048, 0, 0, 0}
, {0.00120048, 0.0060024, 0.00360144, 0.00360144, 0.00120048, 0, 0.00360144, 0.00360144, 0.00120048, 0}
, {0.00360144, 0.00720288, 0.00480192, 0.00360144, 0, 0, 0.00240096, 0.00120048, 0.00360144, 0}
, {0.00360144, 0.0060024, 0.0060024, 0.00240096, 0, 0, 0.00120048, 0.00120048, 0.00360144, 0.00120048}
, {0.0060024, 0.00720288, 0.0060024, 0.00720288, 0.00240096, 0.00240096, 0.00480192, 0.00360144, 0.00360144, 0.00120048}
, {0.00720288, 0.00840336, 0.00840336, 0.00360144, 0.00360144, 0.00480192, 0.0060024, 0.00720288, 0.00720288, 0.00240096}
, {0.00840336, 0.00960384, 0.00840336, 0.00120048, 0.00240096, 0.00360144, 0.00480192, 0.00840336, 0.00960384, 0.00480192}
, {0.00840336, 0.0108043, 0.0060024, 0.00120048, 0.00240096, 0.00480192, 0.00360144, 0.00480192, 0.0108043, 0.00720288}
, {0.00840336, 0.00960384, 0.0060024, 0.00120048, 0.00120048, 0.00240096, 0.00360144, 0.00480192, 0.0108043, 0.00960384}
, {0.00960384, 0.00840336, 0.0060024, 0.00120048, 0.00120048, 0.00120048, 0.00240096, 0.00480192, 0.00960384, 0.00960384}
, {0.00960384, 0.00840336, 0.0060024, 0.00120048, 0.00120048, 0.00120048, 0.00120048, 0.00480192, 0.00840336, 0.00960384}
, {0.00840336, 0.00840336, 0.0060024, 0.00240096, 0.00120048, 0.00120048, 0.00120048, 0.00480192, 0.00840336, 0.00960384}
, {0.00840336, 0.00840336, 0.0060024, 0.00360144, 0.00120048, 0.00120048, 0, 0.00480192, 0.00840336, 0.00960384}
, {0.0060024, 0.00840336, 0.0060024, 0.00360144, 0.00240096, 0.00120048, 0, 0.00360144, 0.00840336, 0.00840336}
, {0.00360144, 0.00960384, 0.0060024, 0.00360144, 0.00360144, 0.00120048, 0, 0.00360144, 0.00960384, 0.00480192}
, {0.00240096, 0.0108043, 0.0060024, 0.00360144, 0.00480192, 0.00240096, 0.00120048, 0.00480192, 0.00840336, 0.00360144}
, {0, 0.00840336, 0.0060024, 0.00360144, 0.00480192, 0.00480192, 0.00360144, 0.00480192, 0.00720288, 0.00240096}
, {0, 0.0060024, 0.00840336, 0.0060024, 0.00480192, 0.00480192, 0.0060024, 0.00480192, 0.0060024, 0}
, {0, 0.00240096, 0.00720288, 0.00840336, 0.00480192, 0.00480192, 0.0060024, 0.00360144, 0.00480192, 0}
, {0, 0.00120048, 0.00360144, 0.00720288, 0.00720288, 0.00480192, 0.00480192, 0.00360144, 0.00120048, 0}
}
, {{0.0121528, 0.0121528, 0.0104167, 0.0104167, 0.0104167, 0.0104167, 0.0104167, 0.0104167, 0.0104167, 0.0104167}
, {0.0121528, 0.015625, 0.0138889, 0.0138889, 0.0138889, 0.0138889, 0.0138889, 0.0138889, 0.0138889, 0.0138889}
, {0.00868056, 0.0121528, 0.0121528, 0.0121528, 0.0121528, 0.0121528, 0.0121528, 0.0121528, 0.015625, 0.015625}
, {0.00347222, 0.00694444, 0.00520833, 0.00520833, 0.00520833, 0.00520833, 0.00520833, 0.00694444, 0.015625, 0.00868056}
, {0.00520833, 0.00173611, 0, 0, 0, 0, 0, 0.00694444, 0.0121528, 0.00173611}
, {0.00347222, 0, 0, 0, 0, 0, 0.00347222, 0.0104167, 0.00868056, 0}
, {0.00347222, 0, 0, 0, 0, 0, 0.00694444, 0.0138889, 0.00173611, 0}
, {0.00173611, 0, 0, 0, 0, 0.00347222, 0.0121528, 0.0104167, 0, 0}
, {0, 0, 0, 0, 0, 0.00694444, 0.0138889, 0.00694444, 0, 0}
, {0, 0, 0, 0, 0, 0.00868056, 0.0138889, 0.00173611, 0, 0}
, {0, 0, 0, 0, 0.00347222, 0.0121528, 0.0121528, 0, 0, 0}
, {0, 0, 0, 0, 0.00520833, 0.0138889, 0.00868056, 0, 0, 0}
, {0, 0, 0, 0, 0.00868056, 0.015625, 0.00173611, 0, 0, 0}
, {0, 0, 0, 0, 0.0121528, 0.0138889, 0.00173611, 0, 0, 0}
, {0, 0, 0, 0.00520833, 0.0138889, 0.00694444, 0, 0, 0, 0}
, {0, 0, 0, 0.00694444, 0.0138889, 0.00694444, 0, 0, 0, 0}
, {0, 0, 0.00173611, 0.0104167, 0.0121528, 0.00173611, 0, 0, 0, 0}
, {0, 0, 0.00173611, 0.0121528, 0.0121528, 0, 0, 0, 0, 0}
, {0, 0, 0.00347222, 0.0121528, 0.0121528, 0, 0, 0, 0, 0}
, {0, 0, 0.00347222, 0.0121528, 0.0104167, 0, 0, 0, 0, 0}
, {0, 0, 0.00520833, 0.0121528, 0.00868056, 0, 0, 0, 0, 0}
, {0, 0, 0.00868056, 0.015625, 0.00347222, 0, 0, 0, 0, 0}
, {0, 0, 0.00868056, 0.015625, 0.00173611, 0, 0, 0, 0, 0}
, {0, 0, 0.00868056, 0.015625, 0.00173611, 0, 0, 0, 0, 0}
, {0, 0, 0.00868056, 0.015625, 0.00173611, 0, 0, 0, 0, 0}
}
, {{0.000498008, 0.000498008, 0.000498008, 0.00298805, 0.00547809, 0.00796813, 0.00747012, 0.00348606, 0.00298805, 0.00199203}
, {0.000498008, 0.000498008, 0.00348606, 0.00697211, 0.00448207, 0.0064741, 0.00846614, 0.00747012, 0.00448207, 0.00199203}
, {0.000498008, 0.00149402, 0.00547809, 0.00448207, 0.00398406, 0.00348606, 0.00448207, 0.0064741, 0.0059761, 0.00249004}
, {0.000498008, 0.00348606, 0.00498008, 0.00398406, 0.00498008, 0.00348606, 0.00348606, 0.00498008, 0.00747012, 0.00199203}
, {0.000498008, 0.00448207, 0.00448207, 0.00498008, 0.00348606, 0.00298805, 0.00298805, 0.00348606, 0.0064741, 0.00199203}
, {0.00149402, 0.00498008, 0.00498008, 0.00448207, 0.00249004, 0.00199203, 0.00298805, 0.00448207, 0.0059761, 0.00249004}
, {0.00149402, 0.00747012, 0.00498008, 0.00398406, 0.00348606, 0.00149402, 0.00348606, 0.00448207, 0.00547809, 0.00249004}
, {0.000996016, 0.0064741, 0.00547809, 0.00348606, 0.00398406, 0.00149402, 0.00398406, 0.00448207, 0.00498008, 0.000996016}
, {0.000996016, 0.00697211, 0.0059761, 0.00448207, 0.00348606, 0.00298805, 0.00298805, 0.00448207, 0.00448207, 0.000996016}
, {0.000498008, 0.0064741, 0.00697211, 0.00547809, 0.00298805, 0.0059761, 0.00348606, 0.0064741, 0.00298805, 0.000996016}
, {0.000498008, 0.00398406, 0.00796813, 0.0059761, 0.00498008, 0.00448207, 0.00697211, 0.00547809, 0.00149402, 0.000996016}
, {0.000498008, 0.000996016, 0.00697211, 0.00846614, 0.0059761, 0.00498008, 0.00697211, 0.00498008, 0.00199203, 0.000996016}
, {0.000498008, 0.000498008, 0.00448207, 0.00896414, 0.00747012, 0.0059761, 0.00498008, 0.00747012, 0.00348606, 0.000996016}
, {0.000498008, 0.00149402, 0.00448207, 0.00846614, 0.00846614, 0.0059761, 0.00547809, 0.0059761, 0.00547809, 0.00149402}
, {0.000498008, 0.00448207, 0.0059761, 0.00398406, 0.00498008, 0.0059761, 0.00498008, 0.00547809, 0.0064741, 0.00348606}
, {0.00199203, 0.00547809, 0.00498008, 0.00249004, 0.00199203, 0.00498008, 0.00448207, 0.00498008, 0.0059761, 0.00448207}
, {0.00348606, 0.0059761, 0.00398406, 0.00149402, 0.00199203, 0.00348606, 0.00398406, 0.00448207, 0.00547809, 0.00498008}
, {0.00448207, 0.0064741, 0.00348606, 0.000996016, 0.00199203, 0.00249004, 0.00348606, 0.00398406, 0.00547809, 0.00498008}
, {0.00448207, 0.00498008, 0.00249004, 0.000996016, 0.00149402, 0.00249004, 0.00348606, 0.00298805, 0.00448207, 0.00448207}
, {0.00498008, 0.0059761, 0.00249004, 0.00149402, 0.000996016, 0.00199203, 0.00398406, 0.00398406, 0.00398406, 0.00448207}
, {0.00547809, 0.00697211, 0.00348606, 0.00199203, 0.00199203, 0.00149402, 0.00398406, 0.00398406, 0.00498008, 0.00398406}
, {0.00348606, 0.00796813, 0.00398406, 0.00348606, 0.00298805, 0.00199203, 0.00398406, 0.00249004, 0.00498008, 0.00249004}
, {0.00199203, 0.00747012, 0.00747012, 0.00448207, 0.00298805, 0.00298805, 0.00547809, 0.00398406, 0.00498008, 0.000996016}
, {0.00149402, 0.00448207, 0.00796813, 0.00796813, 0.00547809, 0.0059761, 0.0059761, 0.00547809, 0.00249004, 0.000996016}
, {0.000996016, 0.00249004, 0.00448207, 0.0064741, 0.0064741, 0.0064741, 0.0059761, 0.00249004, 0.000996016, 0.000996016}
}
, {{0, 0, 0.00099552, 0.00547536, 0.00547536, 0.0049776, 0.00647088, 0.00049776, 0.00099552, 0}
, {0, 0, 0.00547536, 0.00597312, 0.0049776, 0.00447984, 0.00597312, 0.00298656, 0.00398208, 0}
, {0, 0.00348432, 0.0049776, 0.00597312, 0.0074664, 0.00647088, 0.00547536, 0.00647088, 0.00597312, 0.00099552}
, {0.00199104, 0.00597312, 0.0074664, 0.00398208, 0.00547536, 0.00447984, 0.00398208, 0.00796416, 0.00696864, 0.00099552}
, {0.00398208, 0.00895968, 0.00597312, 0.00298656, 0.00348432, 0.00199104, 0.00298656, 0.00597312, 0.00796416, 0.0024888}
, {0.00547536, 0.00895968, 0.00547536, 0.00149328, 0.00149328, 0, 0.00099552, 0.00547536, 0.00796416, 0.0024888}
, {0.00597312, 0.00895968, 0.00447984, 0.00049776, 0.00149328, 0.00149328, 0, 0.00447984, 0.00895968, 0.00398208}
, {0.00597312, 0.00895968, 0.00348432, 0.00099552, 0.00149328, 0.00149328, 0.00049776, 0.00348432, 0.00895968, 0.00597312}
, {0.00597312, 0.00846192, 0.00348432, 0.00099552, 0.00149328, 0.00149328, 0.00099552, 0.00348432, 0.00895968, 0.00647088}
, {0.00796416, 0.00796416, 0.00348432, 0.00099552, 0.00149328, 0.00149328, 0.00099552, 0.00348432, 0.00895968, 0.00696864}
, {0.0074664, 0.00696864, 0.0049776, 0.00099552, 0.00149328, 0.00149328, 0.00149328, 0.00398208, 0.00895968, 0.00696864}
, {0.0049776, 0.00597312, 0.00696864, 0.00199104, 0.00099552, 0.00099552, 0.0024888, 0.0074664, 0.00846192, 0.00696864}
, {0.00298656, 0.00647088, 0.00846192, 0.00447984, 0.00199104, 0.00199104, 0.0049776, 0.00796416, 0.00796416, 0.00796416}
, {0.00149328, 0.00597312, 0.00647088, 0.00846192, 0.0074664, 0.0074664, 0.00846192, 0.00796416, 0.00796416, 0.00796416}
, {0.00099552, 0.00348432, 0.0049776, 0.00597312, 0.00796416, 0.00696864, 0.00398208, 0.00647088, 0.00796416, 0.00796416}
, {0.00099552, 0.00149328, 0.00348432, 0.00398208, 0.00647088, 0.00398208, 0.00199104, 0.00447984, 0.00846192, 0.00796416}
, {0.00049776, 0.00149328, 0.00149328, 0.00149328, 0.00348432, 0.00199104, 0.00049776, 0.00447984, 0.00846192, 0.00696864}
, {0, 0.00149328, 0.00149328, 0.00049776, 0.00149328, 0.00149328, 0.00049776, 0.00447984, 0.00895968, 0.00547536}
, {0.00199104, 0.0024888, 0.00199104, 0, 0.00149328, 0.00149328, 0.00049776, 0.00398208, 0.00895968, 0.00447984}
, {0.00348432, 0.00547536, 0.00348432, 0, 0.00149328, 0.00149328, 0.00099552, 0.00696864, 0.00895968, 0.00398208}
, {0.0024888, 0.00547536, 0.00447984, 0, 0.00049776, 0.00099552, 0.00099552, 0.00547536, 0.00796416, 0.00298656}
, {0.00149328, 0.00597312, 0.0049776, 0.00099552, 0.00099552, 0.00099552, 0.00298656, 0.0074664, 0.0049776, 0.00298656}
, {0.00149328, 0.00597312, 0.00398208, 0.00298656, 0.00298656, 0.00298656, 0.00348432, 0.00547536, 0.00298656, 0.00298656}
, {0, 0.00447984, 0.00348432, 0.00298656, 0.00298656, 0.00348432, 0.00547536, 0.00298656, 0.00298656, 0.00199104}
, {0, 0.00099552, 0.00298656, 0.00447984, 0.00447984, 0.00398208, 0.00199104, 0.00199104, 0.00099552, 0}
}
};

inline double calcCellCoef(int index, double start, double stop)
{
	return 1.0 -((index == floor(start)) ? start-floor(start) : 0.0) 
			   -((index == ceil(stop)-1)   ? ceil(stop)-stop : 0.0)  ;
}

matrix resizeMatrix( const matrix& matr, std::pair<int, int> newsize )
{
	if (matr.empty())
		return matrix();

	matrix newmatr(newsize.first, matrix::value_type(newsize.second, 0));
	double coefX = double(matr.size())/double(newsize.first); 
	double coefY = double(matr[0].size())/double(newsize.second); 
	for (int i=0; i<newsize.first; ++i) {
		for (int j=0; j<newsize.second; ++j) {
			double sum = 0; // sum in cell
			double coef = 0; // coeficient for average
			double startI = i*coefX;
			double finI = (i+1)*coefX;
			double startJ = j*coefY;
			double finJ = (j+1)*coefY;
			for (int si = floor(startI); si < ceil(finI) && si < matr.size(); ++si) {
				for (int sj = floor(startJ); sj < ceil(finJ) && sj < matr[0].size(); ++sj) {
					double cellCoef = calcCellCoef(si, startI, finI) * calcCellCoef(sj, startJ, finJ);
					sum += cellCoef * matr[si][sj];
					coef += cellCoef;
				}
			}
			newmatr[i][j] = round(sum/coef);
		}
	}

	return newmatr;
}

#ifdef DEBUG
	
	
template <class T>
	std::ostream& operator << (std::ostream& os, const std::vector<T>& vec)
	{
		os << '{';
		bool comma = false;
		for (typename std::vector<T>::const_iterator it = vec.begin(); it!=vec.end(); ++it) {
			if (comma)
				os << ", ";
			os << *it;
			comma = true;
		}
		os << '}' << std::endl;
	}

template<>
	std::ostream& operator << (std::ostream& os, const std::vector<int>& vec)
	{
		os << '{';
		bool comma = false;
		for (std::vector<int>::const_iterator it = vec.begin(); it!=vec.end(); ++it) {
			//*it>3 ? os << *it : os << ' ';
			*it>0.1 ? os << 'X' : os << ' ';
			comma = true;
		}
		os << '}' << std::endl;
	}
#endif

matrix getSymbol(const matrix& matr, std::pair<int,int> start, std::vector< std::vector<bool> >& W)
{
	static const int dirs[8][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}  };
	
	std::list < std::pair<int, int> > moves;
	moves.push_back(start);
	std::list < std::pair<int,int> >::iterator head = moves.begin();
	std::pair<int,int> rangeRow = std::make_pair(matr.size(), 0); // max and min
	std::pair<int,int> rangeCol = std::make_pair(matr[0].size(), 0); // max and min
	while (head != moves.end()) {
		std::pair<int,int> v = *head;
		for (int i=0; i<8; ++i) {
			std::pair<int,int> next = std::make_pair(v.first+dirs[i][0], v.second+dirs[i][1]);

			if (next.first>=0 && next.second>=0 && next.first<matr.size() && next.second<matr[0].size()) {
				if (W[next.first][next.second] && matr[next.first][next.second]) {
					moves.push_back(next);
					rangeRow.first = std::min(rangeRow.first, next.first);
					rangeRow.second = std::max(rangeRow.second, next.first);
					rangeCol.first = std::min(rangeCol.first, next.second);
					rangeCol.second = std::max(rangeCol.second, next.second);
				}
				W[next.first][next.second] = false;
			}
		}
		++head;
	}
	
	matrix outmatr(rangeRow.second - rangeRow.first + 1 , matrix::value_type(rangeCol.second-rangeCol.first + 1, 0));
	for (std::list < std::pair<int,int> >::iterator it = moves.begin(); it != moves.end(); ++it) {
		outmatr[ it->first - rangeRow.first ][ it->second - rangeCol.first ] = matr[it->first][it->second];
	}

	return outmatr;
}

std::vector <matrix> getSymbols(const matrix& matr)
{
	if (matr.empty())
		return std::vector<matrix>();

	std::vector <matrix> results;
	std::vector< std::vector<bool> > W(matr.size(), std::vector<bool>(matr[0].size(), true));
	for (int col = 0; col<matr[0].size(); ++col) {
		for (int row = 0; row<matr.size(); ++row) {
			if (W[row][col] && matr[row][col]) {
				results.push_back( matrix() );
				matrix mask = getSymbol(matr, std::make_pair(row, col), W);
				results.back().swap(mask);
			}
		}
	}

	return results;
}

void addPattern(const matrix& pattern, int digit)
{
	for (int i=0; i<pattern.size(); ++i) {
		for (int j=0; j<pattern[0].size(); ++j)
			patterns[digit][i][j] += pattern[i][j];
	}
}

template <class T>
	inline T sqr(T x) {return x*x;}

double getPatternMatch(const matrix& symb, int digit)
{
	double sum = 0;
	for (int i=0; i<patterns[digit].size(); ++i) {
		for (int j=0; j<patterns[digit][0].size(); ++j) {
			sum += sqr(symb[i][j] - patterns[digit][i][j]);
		}
	}
	return sqrt(sum/(patternSize.first * patternSize.second));
}

int bestMatch(const matrix& matr)
{
	double bdiff = patternSize.first * patternSize.second;
	int bi = -1;
	for (int i=0; i<patterns.size(); ++i) {
		double diff = getPatternMatch(matr, i);
#ifdef DEBUG
		std::cerr << "Diff^2 for " << i << " = " << diff << std::endl;
#endif
		if (bdiff > diff) {
			bdiff = diff;
			bi = i;
		}
	}
	std::cerr << "Best match " << bi << " with " << bdiff << std::endl;
	return bi;
}

void normalizePattern(pmatrix& pattern)
{
	double sum = 0;
	for (int i=0; i<pattern.size(); ++i) {
		for (int j=0; j<pattern[0].size(); ++j) {
			sum += pattern[i][j];
		}
	}
	
	for (int i=0; i<pattern.size(); ++i) {
		for (int j=0; j<pattern[0].size(); ++j) {
			pattern[i][j] = double(pattern[i][j])/sum;
		}
	}
}

pmatrix getNormalizedMatrix(pmatrix& pattern)
{
	double sum;
	pmatrix res(pattern.size(), pmatrix::value_type(pattern[0].size()));
	for (int i=0; i<pattern.size(); ++i) {
		for (int j=0; j<pattern[0].size(); ++j) {
			sum += pattern[i][j];
		}
	}

	for (int i=0; i<pattern.size(); ++i) {
		for (int j=0; j<pattern[0].size(); ++j) {
			res[i][j] = double(pattern[i][j])/sum;
		}
	}
}


void normalizePatterns()
{
	for (int i=0; i<patterns.size(); ++i)
		normalizePattern(patterns[i]);
}

int chrtoint(char c)
{
	switch (c) {
		case '.': return 0;
		case '%': return 1;
		case '#': return 2;
		case '@': return 3;
		default:  return -1;
	}
}

void initPatternsFromPatternArray()
{
	for (int k=0; k<patterns.size(); ++k)
		for (int i=0; i<patterns[k].size(); ++i)
			for (int j=0; j<patterns[k][i].size(); ++j)
				patterns[k][i][j] = patternArray[k][i][j];
}

int main(int argc, char** argv)
{
	initPatternsFromPatternArray();
	
	if (argc == 2) {
		while (std::cin) {
			matrix inmatr;
			std::string row;
			std::cout << "Enter number: " << std::endl;
			std::string snum;
			std::cin >> snum;

			std::cin >> std::noskipws;
			char c;
			do {
				std::cin >> c;
			} while (c != '\n');
			std::cin >> std::skipws;

			std::cout << "Enter image: " << std::endl;
			while (std::getline(std::cin, row) && !row.empty()) {
				inmatr.push_back(matrix::value_type(row.size()));
				for (int i=0; i<row.size() && chrtoint(row[i])>=0; ++i) {
					inmatr.back()[i] = chrtoint(row[i]);
				}
			}

			std::cerr << "After " << snum << "\n";
			std::vector <matrix> symb = getSymbols(inmatr);
			for (int k=0; k<std::min(snum.size(), symb.size()); ++k) {
				matrix m = resizeMatrix(symb[k], patternSize);
				addPattern(m, snum[k]-'0');
			}

		}
		normalizePatterns();

		std::cerr << patterns << std::endl;
	}
	else {
		matrix inmatr;
		std::string row;
		while (std::getline(std::cin, row) && !row.empty()) {
			inmatr.push_back(matrix::value_type(row.size()));
			for (int i=0; i<row.size() && chrtoint(row[i])>=0; ++i) {
				inmatr.back()[i] = chrtoint(row[i]);
			}
		}
		std::vector <matrix> symb = getSymbols(inmatr);

		std::string ans;
		for (int i=0; i<symb.size(); ++i) {
			int match = bestMatch(symb[i]);
			if ( match>= 0) {
				ans += match + '0';
			}
		}

		std::cout << ans << std::endl;
	}
	
	return 0;
}
