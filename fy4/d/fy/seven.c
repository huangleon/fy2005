#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"С��̯"NOR);
    set("long", @LONG
�����������õ����Σ�һյҡҡ�λεĹµƣ������һ�Է���Ȼ�������꣬
ȴ�Ѿ������Ǳ��������۵����ơ�����ɪ�˵ĺ����ӹ�������ı�ø��䣬�̲�ס
��Ҫ���£���һ�������ڵ���ʳ��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"lssquare1",
      ]));
    set("no_fly",1);	// no,dont fly here.
    set("outdoors", "fengyun");
    set("objects", ([
	__DIR__"npc/seller1": 1,
	__DIR__"npc/seller2": 1,
	__DIR__"npc/ass1": 1,
	__DIR__"npc/ass2": 1,
	__DIR__"npc/ass3": 1,
      ]) );

    set("coor/x",110);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}




int	valid_leave(object who, string dir)
{
    if (!present("spiced beef",who) && !present("stewed pork",who) && !present("pork noodles",who) && !present("pork noodles",who))
	return ::valid_leave(who,dir);

    write("�����ȰѶ����Թ����߰ɡ�\n");
    return notify_fail("");
}


// ���p��dancing_faery@hotmail.com

