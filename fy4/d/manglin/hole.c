#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "������");
        set("long", @LONG
�������������ɢ����һ��ҩζ�����ϵĻ�Ҷ�а�����񣬲���ȥ����ɳɳ��
���죬��ϸ��ȥ����Χż�������׻𣬲�֪����ʲô����Ĺ�ͷ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  			"up" : __DIR__"groupn2",

]));
        set("outdoors", "manglin");
		set("coor/x",60);
		set("coor/y",-50);
		set("coor/z",0);
		set("no_fly", 1);
		set("max_lv",45);	
		setup();

}




int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"groupn2");
	if (!exitroom)
		exitroom = load_object(__DIR__"groupn2");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"�������ֳ��ֺڣ�����ý�ȥ̫ʧ����ˡ�\n"NOR);
	}
}







