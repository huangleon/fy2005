#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIY"����ʯ��"NOR);
    set("long", @LONG
̫���ź󳤴������ɵ�����ʯ��ֱ��̫�ͽ�ʯ������������������צ��
�����쳣��ʯ��������������ֻ�޴����ͭ�޶���������أ��������¡�̫������
�࣬�������ѵ¡�����������š����Ų���һ�����η��������Ʋ�����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"nwind3",
	"north" : __DIR__"hall",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/dtz": 2,
      ]) );
    set("coor/x",0);
    set("coor/y",200);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    replace_program(ROOM);
}

