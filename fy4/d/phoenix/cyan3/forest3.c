// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", YEL"������"NOR);
    set("long", @LONG
������խ��ɽ�죬ӭ�������һƬ���ص����֡���δ�����ĸ��ֲ����ľ
��������ں�����������Ų��þ�Ȼ����ԶԶ��ȥ������ī���ϻ�δ������
ľ�塣��ͷ������������������ľҶ����һƬ�Ա̣���������ǳǳ�Ķ�ƣ�
֦����ƽ�ߣ�����Ϊһ��������ܵ�������
    ��֪���ļ��ڣ�΢�硣
    ��ɫ�Ĺ��ߴ�������ǳǳ��͸��������
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "path4",
  		"southdown" : "forest2",
  		"eastup" : "path5",
	]) );
	set("area","cyan3");

	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",50);

	setup();
}



void init()
{
	object ob;
	object me = this_player();
	::init();

	if (!userp(me))
		return;

	if (REWARD_D->riddle_check(me,"���Ļ���") ==1) 
	{
		ob=new(__DIR__"npc/li");
//		ob->move(this_object());
		me->set_temp("disable_inputs",1);
		call_out("do_ggyy3",1,me,ob,0);

	}
	
	return;


}



int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (dir == "southdown")
		return notify_fail("ʱ���ϲ����ˣ��ͱ𵽴��һ��˰ɣ�\n");

	return ::valid_leave(who,dir);
}







void do_ggyy2(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
CYN"�����������½��Ͱ��Σ��������ɴ������һ�������а��Ծ�����΢Ц������л��"NOR,
CYN"����׿���ţ���һ�������������ߡ�"NOR,
});

	if (!me || !target)
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	msg = event_msg[count];

	message_vision(CYN+msg+"\n\n"NOR,me,target);
	me->set_temp("disable_inputs",1);

	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy2",1,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("disable_inputs",0);
		target->ccommand("follow mu seoguang");
		me->stop_busy();
		return;
	}
	return;
}



void do_ggyy3(object me,object target,int count)
{
	string msg;
	object ob;
	string *event_msg = ({
WHT"��ֻ������ľҶһ����������ա�\n�������ǽ�������խ������΢�����ȣ����࿪�棬���ǵ���\n\n��孽��͵Ĺ��ñ�����̫����\n",
HIR"������䣬���������һ����б���߳ߣ�ȴ���ñ���һ����Х������ʿ�ڶ������ѳ���\n���Ƽ�����ң�����������ǧ����ſ�֮����"NOR,
HIY"�㰵��һ�������һ����������������ȥ�������ţ�\n"
HIW"��ǰ�İ׻���Ȼһ����һ���ӻƹ�â�������б����������������ʿ�ؿ����һ��Ѫ\nȪ������һ����Х���¡�������������������",
"Ĩһ���亹���������и�������������û������\n�������쳣���ᣬ��Įƽ���������д�һ��ǳ����ֵĹ°���\n",
});

	if (!me || !target)
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	if ( me->is_fighting() || target->is_fighting())
	{
		if (me)
			me->set_temp("annie/no_leave",0);
		if (target)
			destruct(target);
		return;
	}
	msg = event_msg[count];

	message_vision(CYN+msg+"\n\n"NOR,me,target);

	if (count==0)
	{
		target->move(this_object());
		ob=new(__DIR__"obj/corpse2");
		ob->move(this_object());
		ob=new(__DIR__"obj/corpse3");
		ob->move(this_object());

	}


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy3",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("disable_inputs",0);
		call_out("do_ggyy2",10,me,target,0);	
		me->perform_busy(60);
		REWARD_D->riddle_set(me,"���Ļ���",2);
		return;
	}
	return;
}


				




/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


