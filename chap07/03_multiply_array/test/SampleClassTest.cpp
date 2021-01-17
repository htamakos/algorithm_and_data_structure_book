#include <gtest/gtest.h>

#include <iterator>
#include <utility>
#include <vector>

#include "SampleClass.hpp"

TEST(calc, normal) {
  std::vector<long long> a{0, 1, 3, 8, 11, 7, 12};
  std::vector<long long> b{1, 2, 8, 8, 10, 5, 2};

  auto result = min_count<decltype(std::begin(a)), long long>(
      std::begin(a), std::begin(b), a.size());
  ASSERT_EQ(21, result);
}

INSERT INTO user_sdo_geom_metadata
    VALUES('T_HOGE', 'H',
           SDO_DIM_ARRAY(SDO_DIM_ELEMENT('Longitude', -180, 180, 0.5),
                         SDO_DIM_ELEMENT('Latitude', -90, 90, 0.5)),
           8307);

EID					   NOT NULL NUMBER
SVID					   NOT NULL NUMBER
DVID					   NOT NULL NUMBER
EL						    NVARCHAR2(3100)
K						    NVARCHAR2(3100)
T						    NUMBER(38)
V						    NVARCHAR2(15000)
VN						    NUMBER
VT						    TIMESTAMP(6) WITH TIME ZONE
SL						    NUMBER
VTS						    DATE
VTE						    DATE
FE						    NVARCHAR2(4000)



col table_name for a20
col column_name for a20

select
   USER_CONS_COLUMNS.TABLE_NAME
   ,USER_CONS_COLUMNS.COLUMN_NAME
   ,USER_TAB_COLUMNS.DATA_TYPE
   ,USER_TAB_COLUMNS.DATA_LENGTH
   ,USER_CONSTRAINTS.CONSTRAINT_TYPE 
from
    USER_CONS_COLUMNS
    left  join USER_TAB_COLUMNS on USER_CONS_COLUMNS.COLUMN_NAME = USER_TAB_COLUMNS.COLUMN_NAME
    inner join USER_CONSTRAINTS on USER_CONS_COLUMNS.CONSTRAINT_NAME = USER_CONSTRAINTS.CONSTRAINT_NAME 
    and USER_CONSTRAINTS.CONSTRAINT_TYPE = 'P'
where  1=1 and user_cons_columns.table_name like 'ACT_GRAPH%'
order by 1,2,3
