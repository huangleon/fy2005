#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", WHT"С��"NOR);
        set("long", @LONG
����Ļ�ɳ�У�����С��ͻȻ����Ӱ����֡�С���ǰ�ɫ�ģ���ɫ����ǽ����
ɫ���Ŵ�����ɫ�����ߣ���Ȼ��Ⱦ��ɳ��������һ������Ʈ���ɴ��ٲȻ������Ů
��ľ�ɫŮ�ӣ����¹�����һ��СС�ķ��������ȵķٷ�����ҡ���죬��������
�����˼�������˳���ĺ��Ľ��ϣ�����
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"desert_ambush",
		]));
	set("objects", ([
		
	]));
	set("outdoors", "zangbei");
        set("coor/x",-90);
	set("coor/y",280);
	set("coor/z",0);
	setup();
	set("no_fly", 1);
	set("max_lv",50);	
}


int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"desert_cabin");
	if (!exitroom)
		exitroom = load_object(__DIR__"desert_cabin");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,YEL"���߽�С�ݣ���ǰ��Ȼһ����������ɫ�ķ��Ӻ���ǰ��ɫ����Ӱ˲����ʧ��\n������Ǽ����ưܵ�ľ�ݣ�Ī�Ǹղ�������һ�ж�ֻ�����Ǻ�����¥���ѣ�\n"NOR);
	}
}

