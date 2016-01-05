#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����ǰ");
        set("long", @LONG
�ϴ�ĳ����ߣ���������������������ǰ�������ż�����ִ��꣬���лԻ�
����ʿ���������������ʱ������ӯ�������ͻ��ֵ�Ц����������ִ����������
ʿ��Ŀ��ȴ��ӥһ��������
LONG
        );
        set("exits", ([ 
	  	"enter" : __DIR__"d_tentin",
	  	"west": __DIR__"d_oasis",
			]));
	set("objects", ([
		__DIR__"npc/g_wushi":	4,
	]));
	set("item_desc",([
		
	]));
        set("outdoors", "zangbei");
        set("coor/x",-60);
	set("coor/y",310);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

void init(){
	add_action("do_look","look");
}

int do_look(string arg){
	if (arg=="enter") {
		tell_object(this_player(),"���ŵʹ������������ڵĶ�����ֻ���������Ⱦ�����֮����\n");
		return 1;
	}
	return 0;
}

int valid_leave(object me, string dir){
	
	object *inv, soldier,*pros;
	int i;
	
	if (!soldier=present("soldier",this_object()))
		return 1;
	
	if (dir == "enter") {
		if (REWARD_D->check_m_success(me,"����֮��"))	return 1;
				
		if (!me->query("zangbei/����_͵���ɹ�")) {
			return notify_fail("ִ����ʿ�����г���һ�᣺����������ͣ����˲������ڣ�\n");
		} else {
			me->delete_temp("last_damage_from");
			message_vision(HIR"$N��Ҫ�����п�������������$N������˹�������ӧ�������綾�߳�Ѩ��\n\n"NOR,me);
			
			inv = all_inventory(this_object());
			for (i=0;i<sizeof(inv);i++) {
				if (inv[i]->query("group_1")!="guizi") continue;
				COMBAT_D->do_attack(inv[i], me, inv[i]->query_temp("weapon"));	
			}
			if (me->query_temp("last_damage_from")) {
				tell_object(me,HIG"\n����ңң����������Ц������������������ϵĹ��򡣡�������\n\n"NOR);
				me->set("zangbei/����_����ʧ��",time());
				me->start_busy(1);
				return notify_fail ("");
			}
			
			message_vision(HIG"\n����ңң����������Ц���������ܶ�ù���һ�����������ǵļα��ˡ���\n\n"NOR,me);
			if (!REWARD_D->riddle_check(me,"����֮��"))
				REWARD_D->riddle_set(me,"����֮��",1);
			me->delete("zangbei/����_����ʧ��");
			return 1;
		}
	}
	return 1;
}