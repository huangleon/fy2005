// annie 07.2003
// dancing_faery@hotmail.com

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
������޵����ԣ����������䣬����������Ħ������ۿɣ�����ɮ�ӣ�
������ţ�������̣���������������й��������������Ϊ�����泯��������
����ǽ�ڻ�����������ɮ����ȷ�Ƿ�ұ��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"liuzu",
]));
        set("objects", ([
                __DIR__"npc/xin_qian" : 1,
       ]) );
	set("coor/x",-20);
	set("coor/y",-50);
	set("coor/z",-10);
	setup();

}
