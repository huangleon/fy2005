// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "������");
        set("long", @LONG
һ�ô�������
LONG
        );
 	set("objects", ([
		__DIR__"obj/musicbird": 1,
	]) );
	set("exits", ([
		"down" : __DIR__"yard",
	]));
    	set("no_magic",1);
    	set("no_fly",1);
    	set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-35);
	set("coor/z",40);
	setup();
}

void reset()
{
	object bird;

	::reset();
	if(bird=present("music bird",this_object()))
		bird->delete("idling");
}

void init()
{
	object me,bird;


	if(userp(me=this_player())&&bird=present("music bird",this_object()))
	{
		remove_call_out("idling");
		call_out("idling",30,bird);
	}
	add_action("do_catch","catch");
}

void idling(object bird)
{
	if(!objectp(bird) || bird->query("idling")) {
		return ;
	}
	bird->set("idling",1);
	message_vision(HIG"��ɤ��������˼��������񶣶���Ȫˮת��ɽ�ҡ�
��ɤ�̷���һ������ٴ�Ľ�����������һ������Ϥ�����ӡ�
��Ȼ������ߴ���������Ů�Ľ�Ц������һ������ϸ��ʱ����Χ��û���ˡ� \n"NOR,bird);
	return ;
}



int catch_bird(object me,object bird)
{
	int gin,kee,sen;
	if(me->query_temp("mbescape"))
	{
		message_vision("$Nҧ��ҧ����������֦��ʼ��������Ҫ����ɤ����׽������
��Ȼ�������ꡱһ����$N���µ���֦���ˣ�
$N��æ������ŵ������ɣ�ƫƫ������̦�ϣ�\n",me);
		message_vision("\n���䡱��һ����$Nˤ��������
$Nˤ�ú��أ������������ˡ� \n",me);
		me->start_busy(10);
		gin=me->query("max_gin")*5/100;
		kee=me->query("max_kee")*5/100;
		sen=me->query("max_sen")*5/100;
		me->set("eff_gin",gin);
		me->set("eff_kee",kee);
		me->set("eff_sen",sen);
		me->set("gin",gin);
		me->set("kee",kee);
		me->set("sen",sen);
		me->set("marks/�޻�",2);
		if(bird)
	me->start_call_out( (: call_other, bird, "event3", me, 0 :), 1);
		me->delete_temp("mbescape");
		me->move("/d/huangshan/yard");
		bird->move("/d/huangshan/yard");
		return 1;
	}


/*	if(random(5))
	{
		message_vision("$N���������һ�ߣ�һչ��򣬺��ķ����ˡ� \n",this_object());
		destruct(this_object());
		return 1;
	}
*/
	message_vision(HIY"$N������ŵ�����ȥ����׽$n��
$n���ڵ�ͷ������ë��û��ע��$N��$Nһ����ǰ����$nץ����� \n"NOR,me,bird);
	bird->move(me);
	me->start_call_out( (: call_other, bird, "event1", me, 0 :), 1);
}

int do_catch(string arg)
{
	object ob,me,bird;

	me=this_player();
	bird=present("music bird",this_object());

	if(!arg)
		return 0;
	ob=present(arg,this_object());
	if(!ob)
		return 0;
	if(ob!=bird)
		return 0;
	if(!bird->query("idling"))
	{
		message_vision("$N������ŵ�����ȥ����׽$n�� \n",me,bird);
		message_vision("$N���������һ�ߣ�һչ��򣬺��ķ����ˡ� \n",bird);
		destruct(bird);
	}
	else
		catch_bird(me,bird);
	return 1;
}

int invalid_leave(object me)
{
	object bird;

	if(bird=present("music bird",me))
	{
		message_vision(HIR"$N��Ȼ��$n������һ�ģ�$nֻ����ʹ���ģ����ɵ÷ſ���$N��\n"NOR,bird,me);
		message_vision(HIG"$N��������һ���Ӿͷɵ���Ӱ�����ˡ�\n"NOR,bird);
		destruct(bird);
	}

}

int valid_leave(object me,string dir)
{
	object bird;

	if(dir!="down")
		return 0;
	if(bird=present("music bird",this_object()))
	if(me->query_temp("mbescape"))
	{
		message_vision("$N��Ȼ����ɤ�̵Ļ������ǲ�û�к�ڣ�ת��������ȥ�� \n",me);
		me->start_call_out( (: call_other, bird, "event4", me :), 1);
		me->set("marks/�޻�",1);
		me->delete_temp("mbescape");
	}
	return 1;
}
				