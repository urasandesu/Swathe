// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#ifndef URASANDESU_SWATHE_SWATHEDEPENDSON_H
#include <Urasandesu/Swathe/SwatheDependsOn.h>
#endif

#include <boost/assign/std/list.hpp>
#include <boost/assign/std/vector.hpp>
#include <boost/detail/atomic_count.hpp>
#include <boost/foreach.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/range/algorithm_ext.hpp>
#include <boost/timer.hpp>

#ifndef CPPANONYMTEST_H
#include "CppAnonymTest.h"
#endif

#ifndef ATOMICCOUNTER_H
#include "AtomicCounter.h"
#endif

#ifndef BASICCOUNTER_H
#include "BasicCounter.h"
#endif

#ifndef SURVIVALCOUNTER_H
#include "SurvivalCounter.h"
#endif

#ifndef COUNTERWITHVALUE1_H
#include "CounterWithValue1.h"
#endif

#ifndef ACTIONCOUNER_H
#include "ActionCouner.h"
#endif

#ifndef COUNTERWITHACTION1_H
#include "CounterWithAction1.h"
#endif
