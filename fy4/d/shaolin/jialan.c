// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "٤����");
        set("long", @LONG
�ഫ���ֵ��ӱ����ɳ����ֿ�ʼ������٤�������޺��ã���ĦԺ�ļ����ܳ�Ϊ
���֡��������򵥣����й�����������һ����Ϊ���ֹ���֮�档����������׳
ɮ�ˣ��ֳֳ��������ڴ������ա������ڹ�ɮ��粨������ҹ����������������
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"neiyuan3",
  "east" : __DIR__"xueye",
  "west" : __DIR__"chanding",
  "north" : __DIR__"luohan",
]));
        set("objects", ([
                __DIR__"npc/master_20" : 1,
       ]) );
	set("coor/x",0);
	set("coor/y",70);
	set("coor/z",20);
	set("valid_startroom", 1);
	setup();

}
