inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ");
        set("long", @LONG
����һ��޴�İ�ɫɽʯ����Լ�����������߸��ˡ�ʯͷ�ı����쳣ƽ������
�˾������ʯ���ϵļ���[30m��ɫӡ��[32m����֪����Ȼ���ɣ�������Ϊ�ĺۼ�����������
���Կ��������ĺ�ˮ����������ֻ�������������ƣ���֪���ж�߲Żᵽ����
LONG
        );
    	set("item_desc", ([
        	"��ɫӡ��" : "�������˵���ӡ���С��Ҳ����������Ų�һ�ȣ�step����\n",
     	]));

		set("outdoors","fengyun");
		set("coor/x",-50);
		set("coor/y",60);
		set("coor/z",20);
		setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_step", "step");
}

int do_step(string arg)
{
	object me= this_player();
	if(!arg || arg != "��ɫӡ��" )
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision(YEL"$Nһ�Ų���ʯ���ϵĺ�ɫӡ�ۣ�ֻ������֨ѽ��һ����
�±����ѿ���һ���Ż���\n"NOR, this_player());
	set("exits/enter", __DIR__"holeopen2");
    REWARD_D->riddle_done(me,"�ɹ���ʯ",10,1);
	if (QUESTS_D->verify_quest(me,"�ɹ���ʯ"))
		QUESTS_D->special_reward(me,"�ɹ���ʯ");
	return 1;
}

int do_climb(string arg)
{
        object 	me;
	int	mlvl;

	if(!arg || (arg != "up" && arg != "down")) {
		write("��Ҫ���ϻ�������\n");
		return 1;
	}
	me = this_player();
	if( arg == "up") {
		message_vision(HIY "\n$NС�������������ȥ�������������������ڡ�\n"NOR, me);
		message_vision(HIR "\n$N����һ��ûץ�ȣ���Σ���ϵ�����ȥ��\n"NOR, me);
		me->move(__DIR__"yadi");
                me->receive_damage("kee", 150);
                me->receive_damage("sen", 150);
                me->receive_damage("gin", 150);
		message_vision(HIR "\n$N��Σ���ϵ������������ص�ˤ���˵��ϣ�\n"NOR, me);
		me->set_temp("last_damage_from","�ڵ�����׹��������\n");
		
	}
	else {
		message_vision(HIY "$NС�������������ȥ�������������������ڡ�"NOR, me);
		me->move(__DIR__"yadi");
	}
	return 1;
}

int reset(){
	delete("exits/enter");
	::reset();
}