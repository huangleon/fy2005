#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;
void create()
{
        set("short", "��լԺ��¥");
        set("long", @LONG
Ϊ�˰ﳯ�к��Ѷ�����Ц��æ�������ÿ͵�Τ�ÿ�������˵������˵����С��
����ͬһ�����ӳ������ȴ����һ��������Ľ����ˮĽ�ݹ�������̫ƽ��Ϊ
���д���λ��ϲ�ɾ��ĺ�ү��Τ�ÿͻ���������Ľ����ǰ������Ͱ��ˮ����լԺ��
�����������ػس���ʮ��֮�ࡣ
LONG
        );
        set("exits", ([ 
		"west":	__DIR__"house3a",
	]));
	set("objects", ([
        ]) );

        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",10);
	set("map","taiping");
	setup();
	set("no_fly", 1);
	set("max_lv",137);	
}

int init()
{
	object me = this_player();
	object exitroom = find_object(__DIR__"house3a");
	if (!exitroom)
		exitroom = load_object(__DIR__"house3a");
	if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
	{
		me->add_temp("block_msg/all",1);
		me->move(exitroom);
		me->add_temp("block_msg/all",-1);
		tell_object(me,MAG"���Ȼ����Ľ����ˮһ��ϲ�������еĸ��֣�����ֹס�Ų���\n"NOR);
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

