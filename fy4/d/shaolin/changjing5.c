#include <ansi.h>
inherit ROOM;
void create()
{
	object ob1,ob2,con;
        set("short", "�ؾ�����");
        set("long", @LONG
����վ�ڲؾ����Գ���ʯ���Ƶ������ϣ�����
����û���κεĳ�·����������Ҫ�뿪ֻ��ð���Ը�Ծ��(jumpdown)�ˡ�
LONG
        );
        set("exits", ([ 
//  		"enter" : __DIR__"changjing3",
	]));
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",100);
	set("no_lu_letter",1);
	setup();

}

void call_thief(object me)
{
	object th,here=this_object();
	if (!userp(me))
		return;
	if (REWARD_D->riddle_check(me,"����֮��") == 3 && REWARD_D->riddle_check(me,"�ؾ�¥") == 3 && !present("mysterious figure",here))
	{

		message_vision(HIR BLK"���Ƶ����ܵ�����һ�ߣ���Ȼ���ֺ�������վ�ڽ��ϣ���׼��������Ծ��\n\n"NOR,me);

		th=new(__DIR__"npc/master_17_8");
		if (me->query("combat_exp")*10/10> th->query("combat_exp"))  // add by ldb ԭΪ *11/10 ��Ϊ�������¥ 
			th->set("combat_exp", me->query("combat_exp")*10/10);  // add by ldb ԭΪ *11/10 ��Ϊ�������¥ 
		"/feature/nada"->reset_npc(th);
		th->full_me();
		th->move(here);
		REWARD_D->riddle_set(me,"�ؾ�¥",4);
	}
	return;
}


void init()
{
	object ob;

        if( interactive(ob = this_player()) ) {
			add_action("do_jumpout","jumpdown");

                remove_call_out("call_thief");
                call_out("call_thief", 1, ob);
        }

	// ������100 move���������quest.
}

int do_jumpout(string arg)
{
	object me;
	int i;
	object room;
   	me = this_player();
	i = me->query_skill("move",1);

	message_vision("\n$N��������˿������Է��ܱ�һԾ���£�\n",me);
	room = find_object(__DIR__"changjing");
	if (!objectp(room)) room = load_object(__DIR__"changjing");
	tell_object(me,HIW"��������������������������\n"NOR);


		me->add_temp("block_msg/all",1);
		me->move(room);
		message_vision(HIY"\n����ǰһ����һ����Ӱ�Ӳؾ�¥�Ϸ�׹���£�"NOR,me);

		if (i <= random(100))	// 100 move��ȷ����ȫ
		{
			message_vision(HIR"ˤ�˸��Դ�������\n"NOR,me);
			me->delete("timer/lifesave");	// �仨��ˮһ��ȥ:p
			me->add_temp("block_msg/all",-1);
			me->set_temp("last_damage_from","�벻���Ӳؾ�������¥�Ծ��ˡ�");
			// �ţ�ͨ��һ��....
			me->die();
			return 1;
		}
		else
		{
			message_vision(HIW"ˤ�˸��߻���أ��赹������ǰ��\n"NOR,me);
			me->add_temp("block_msg/all",-1);
			me->unconcious();
			return 1;
		}
	return 1;
}



/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/


