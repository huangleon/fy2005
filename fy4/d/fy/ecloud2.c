inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", HIG"������"NOR);
    set("long", @LONG
���������ĺ����ݻ���ԣ������·����������ͨͨ����ӣ����̾���������
���ӣ��ϲ�ԭ�Ƿ��Ƴ�����ǰ�����ž�ַ������ʯʨ���Ѿ�����һ˫����������
����ǰ�ð׷�д�ˡ����ַ������֡�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"ecloud3",
	"west" : __DIR__"ecloud1",
	"south": __DIR__"manhome",
      ]));
    set("objects", ([
	__DIR__"npc/fatman" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",120);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}

