// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ǧ���");
        set("long", @LONG
������¬�󣬵����൱���£����������С�����ʥ�ˡ������ң���ǰ��̨����
ʯ�������������е������������¬ͭ�����ڶ���������ϣ���а�������
�����ӷ�һ�����ܱڻ���������������עĿ���ǵ��ϵ���ʮ�˸����ݵ�[33m�ſ�[32m��
LONG
        );
        set("exits", ([ 
  "northdown" : __DIR__"neimen",
  "southdown" : __DIR__"lishi",
  "east" : __DIR__"baiyi",
  "west" : __DIR__"dizang",
]));
        set("objects", ([
                BOOKS"dodge_50" : 1,
       ]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",20);
	setup();

}
