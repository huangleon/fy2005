// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����վʮ�ֵļ�ª����������Ҳ���Ǻܺá�����Ψһ����ɫ���Ϲϡ������
��ǽ���ƺ��кܶ���Ӱ�ڻζ���
LONG
        );
        set("exits", ([
                "north" : AREA_QUICKSAND"huangyie1",
        ]) );
	set("NONPC",1);
        set("objects", ([
		__DIR__"npc/waiter" : 1,
		__DIR__"npc/ghost" : 5,
        ]) );
        set("item_desc", ([
                "��ǽ": "һ�������������ǽ�����ƺ�����Խ������裩��ȥ��\n",
                "wall" : "һ�������������ǽ�����ƺ�����Խ������裩��ȥ��\n"
        ]) );
	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_dash","dash");
}
 
int do_dash()
{
object me;
object room1,room2;
	me = this_player();
	room1 = load_object(__DIR__"aihe2");
	room2 = load_object(__DIR__"storage");
	message_vision("$N����ǽ��һԽ�Ͳ����ˡ�\n\n",me);
	if(me->query_temp("can_pass_wall"))
	{
		me->move(room1);
		me->delete_temp("can_pass_wall");
	}
	else
		me->move(room2);
	return 1;
}
