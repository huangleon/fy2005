#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ·������ˣ�Ժ�ӱ�ֲ������ȴ�ѵ��㣬������ϡ�Σ����������ġ����ֻ
�л��㣬ֻ�г�����Ī˵������Ӱ����������û�У������ĸ��������ƽ�����մ�
�ྶͥ��̧ͷ��ȥ������һ�������εĴ���ɹ�������������������
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"corridor2",
		"west": __DIR__"garden",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("coor/x",-90);
	set("coor/y",-40);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


int valid_leave(object me, string dir) {
	object man;
	if( userp(me) && REWARD_D->riddle_check(me,"�Ѫ����")== 9
		&& ( me->query_temp("marks/parrot/reject_sanye") || me->query_temp("marks/parrot/answer_sanye")
		&& !me->query_temp("marks/parrot/sanye_ass"))) {
		if (man=present("middle age man",this_object())) 
				return ::valid_leave(me,dir);
		man = new(__DIR__"npc/assassin");
		if (man) {
			
			message_vision(HIG"��Ȼ���Ž�Ҷ����һ���������̵��������ְ���Ҷ�������߳���\n"NOR, me);
			man->move(this_object());
			message_vision("$N̾��һ��������������һ��Ҫ����������Ҳû�а취����\n",man);
			man->kill_ob(me);
			me->kill_ob(man);
			me->perform_busy(1);
			me->set_temp("marks/parrot/sanye_ass",1);
		}	
	}
	return ::valid_leave(me, dir);
}	

