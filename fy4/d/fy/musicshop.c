#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "��ɽ��");
    set("long", @LONG
���װ�κ������������ƺ�һҹ֮��ͳ����ˡ��������к�Ȼ����ǰ�˵���
��--��إ��������ҹ����ֻ��ϧ��������֮������ǽ�Ļ�����һһ���еĶ��ǵ�
���������������Ĺ��٣����ã�����������в���֮�硣
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"swind32",
	"up" : __DIR__"musicshop2",
      ]));

    set("objects", ([
	__DIR__"npc/gou" : 1,
      ]) );


    set("indoors", "fengyun");
    set("coor/x",-20);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}

