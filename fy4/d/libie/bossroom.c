#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
	set("short", "С��");

	set("long", @LONG
һ��������۵�С�ݣ��ݶ���Ƭ���ƣ������궼�Ѿ��ֵ���ס������
LONG);

	set("type","road");
	set("exits",([
    "northwest":__DIR__"stoneroad4",
	]) );
	//}}
    set("outdoors", "libie");
	set("coor/x",40);
	set("coor/y",-40);
	set("coor/z",0);

	setup();
	set("no_fly", 1);
	set("max_lv",55);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"stoneroad4");
	if (!exitroom)
		exitroom = load_object(__DIR__"stoneroad4");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"�㷽Ҫ�ٲ���һ������ĸо�ͻȻϮ����ͷ������\n"NOR);
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

