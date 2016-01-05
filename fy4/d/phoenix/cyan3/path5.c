// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "ɽ��");
    set("long", @LONG
�����ɽ�������ɽ�������������ɽ϶��ǡ��Щ����·���м������
���Ǽ�Ӳ�Ļ��ң�Ω��һ˿΢���Ĺ�â��ͷ����ʯ����©�¡�����΢�⣬����
�ɿ���խ�������������Ҷ��ҷ�������ʯ���ڽ����ߣ���֪ͨ��η���
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/cliff":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westdown" : "forest3",
  		"eastup" : "peak1",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",60);
	setup();
}

int	valid_leave(object who, string dir)
{
	if (dir == "westup")
		return ::valid_leave(who,dir);
	return notify_fail("�ͱ𵽴��һ��˰ɣ�\n");
}




void init()
{
	object ob;
	object me = this_player();
	::init();

	if (!userp(me))
		return;

	if (REWARD_D->riddle_check(me,"���Ļ���") ==2) 
	{
		ob=new(__DIR__"npc/shi");
		ob->move(this_object());
		me->set_temp("disable_inputs",1);
		call_out("do_ggyy3",4,me,ob,0);
	}
	
	return;
}

object fob()
{
	object *inv=all_inventory(this_object());
	int i;
	for (i=0; i<sizeof(inv);i++ )
		if (userp(inv[i]))
			return inv[i];
	return 0;
}

void c()
{
	object me = fob();
	object ob = present("li qingzhuo",this_object());
	if (!me || !ob)
		return;
	me->set_temp("disable_inputs",1);
	call_out("do_ggyy4",4,me,ob,0);

}

void do_ggyy4(object me,object target,int count)
{
	string msg;
	object ob,l;
	string *event_msg = ({
YEL"�콥��������ȥ�����׹����������Ρ����ַ��У�һɽľҶ�������죬��Ҷ������ɱ��",
"����׿ȡ��һ�������������ȥ����Ѫ�����ս����ʣ�����������",
MAG"û�뵽���˶������Ѹ�٣��źõ�����������ʱ���ң������ֲ��ɱ�¶��ݣ�ֻ�������ҿ�����������ˡ�\n"CYN"���������мƽϣ�������׿���ͷ�����ߣ���",
"���ߡ���",
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


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy4",4,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("disable_inputs",0);
		REWARD_D->riddle_set(me,"���Ļ���",4);
		delete("exits");
		set("exits/westup","peak3");
		return;
	}
	return;
}




void do_ggyy3(object me,object target,int count)
{
	string msg;
	object ob,l;
	string *event_msg = ({
"�ϵ�ɽ��������һ��������ͦ�����Ľ��������潹���������ⲽ��һ����ȥһ���૵�����ô��",
"�ǽ���һ������׿�����̱�ӭ����������ʦ�ܣ�ʦ��˵�������ţ���\nʯδΡ�����һ�ۣ�������ֹ��",
"����׿����������˵����",
"ʯδΡ��ɫһ�࣬�������������б䡣ԭ��ħ�����������ᣬ�罫���ǵĶ��������һ�������\nؤ��ɸ봫�ţ���孺�˾��ʮս��ǰҹ�ѵ��ٶ�������Ⱥ������ӵ����ϼ���ƻ�����ԭ����һ��\n����",
"����׿΢΢һЦ����ֻ��û��ô���ס���",
"��ʦ��˵��ֻ���ǰ��������ɲ��ع˼ɣ���ħ�̴˷������㳲��������˵�졢ҹ���̡�����̳\n̳���˴������ϼ��ħ����˾Ҳ���������������ǻ����ᣬ����������л���ֻ�£�������",
MAG" (�����а����Ծ���������֮ʱ�������֪������ʦ������������٣���������Щ�������ŵ�֪��\n�����������)"NOR,
"����ħ̳������������׿����˵�������붫�������д���֮�𣬲��ص��ġ���",
"ʯδΡ����üͷ������δ�ţ�����������ʦ���ϼ�֮�����������·���䵱����ǰȥ�t��̨��\n��������ֹ������ɽ������������ɽ��С����ɽ���Ƶ����ܱ�������ǣ�������",
WHT"����δ�䣬���������Ӱ��ɽ�����Ӷ�����������֮����\nʯδΡ����һ�����ȵ�����������ô�죮�����ҵ�ȥ�ϱ����ţ�ʦ�����������������",
WHT"��Ӱת˲��������ǰ������׿����һ����������ˮ�������Ľ������Ѷ������Ӱնȥ��\n"
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


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy3",4,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("disable_inputs",0);
		REWARD_D->riddle_set(me,"���Ļ���",3);
		destruct(target);

		if (present("li qingzhuo",this_object()))
			l=present("li qingzhuo",this_object());

		ob = new(__DIR__"npc/j1");
		ob->move(this_object());
		ob->kill_ob(me);
		me->kill_ob(ob);
		if (l)
			l->kill_ob(ob);
		ob->add_hate(me,900000);


		ob = new(__DIR__"npc/j2");
		ob->move(this_object());
		ob->kill_ob(me);
		me->kill_ob(ob);
		if (l)
			l->kill_ob(ob);
		ob->add_hate(me,900000);


			
		ob = new(__DIR__"npc/j3");
		ob->move(this_object());
		ob->kill_ob(me);
		me->kill_ob(ob);
		if (l)
			l->kill_ob(ob);
		ob->add_hate(me,900000);



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


