#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "����ʯ��");

	set("long", @LONG
ɽ���������ƣ�С·���Ѷ��ϣ�һ�ԴԲ�֪����С����ɽ����ҡҷ����ֵ����
ʱ�ڣ�бб��ʯ�����仨�ͷס�̤���仨����ɳɳ��֮���ڼž���ɽ�����ƺ�����
����������Ҳ�����˸���ľҶ�Ͱٻ��ķҷ���������Զɽ��䡣
LONG);

	set("type","road");
	set("exits",([
        "westdown":__DIR__"fogpath3",
	]) );
        set("objects", ([
                __DIR__"obj/dropflower" : 1,
       ]) );
	set("coor/x",60);
	set("coor/y",-40);
	set("coor/z",20);
       set("outdoors", "wolfmount");

	setup();

	set("no_fly", 1);
	set("max_lv",85);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"fogpath3");
	if (!exitroom)
		exitroom = load_object(__DIR__"fogpath3");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"�˴���ȥ����ɽ�д�ǰ��Ͷ��֮�˵ĵط������ǲ�ȥΪ�ϡ�\n"NOR);
	}
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

