// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
inherit F_LEVEL;

void create()
{
	set("short", "����С��");
    set("long", @LONG
������ӳ�������ϵ�С���ϣ����ܼž�������һ������Ҷ�ͷ׵ĸߴ���ľ
��һ���Ǹ��Ž���«έ��ƽ���޲��ĺ�ˮ��̤����ӯ�ĽŲ������𽥵س�����
����������ÿһ�ڿ�������ô������ˬ��Ʈ��������ˮ�㡣
LONG
NOR
        );
	set("objects", ([

	]));
	set("exits",([
  		"eastup" : "peak11",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-40);
	set("coor/y",40);
	set("coor/z",-70);
	setup();

	set("no_fly", 1);
}

int do_nothhing()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	else
		return 1;
}

int do_a2()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	me->delete_temp("annie/answer");
	me->set_temp("disable_inputs",1);
	call_out("do_ggyy2",2,me,present("feng minxin"),0);
	return 1;
}


int do_a1()
{
	object me = this_player();
	object target;
	if (!me->query_temp("annie/answer"))
		return 0;
	me->delete_temp("annie/answer");

		message_vision(CYN"\n��Ů������ȥ����˳�ص��˵�ͷ���Գ���������һ���ʺ�ɫ�����˫\nָ����һ����������������ƽƽ���������\n\n"WHT"��̽�ֽ�סȾ��������������������̧��ʱ����һϮѩɴ����Ů��\nȻ��ʧ������\n"NOR,me,me);

		REWARD_D->riddle_done(me,"�������",0,1);

		if (present("feng minxin"))
			destruct(present("feng minxin"));

		if (present("mayuri"))
			destruct(present("mayuri"));


		target=new(__DIR__"obj/letter2");
		target->move(me);


		return 1;
}


void init() {

	object ob;
	object me = this_player();
	::init();

	if (!userp(me))
		return;


	if (REWARD_D->riddle_check(me,"���Ļ���") <=6 && !REWARD_D->check_m_success(me,"����") && !REWARD_D->check_m_success(me,"�������") ) 
	{
			ob=new(__DIR__"npc/pet");
		
		ob->move(this_object());

		ob=new(__DIR__"npc/feng");
		
		ob->move(this_object());

//	if(!wizardp(this_player()))
//	{
			add_action("do_nothhing", "");
			add_action("do_a1","1");
			add_action("do_a2", "2");
//	}
		me->set_temp("disable_inputs",1);

		call_out("do_ggyy3",2,me,ob,0);

	}
	
	return;


}


void do_ggyy2(object me,object target,int count)
{
	string msg;
	string *event_msg = ({

"\n��Ů��ɫ�������Ϸ���һ�㵭���ĺ��Σ���ҧ���´�������һ��������\n��ȥ��\n\n",

"�����ģ��������㲽����Ů��ߣ���һ�������ƻõ������ͻ�������ӵ\nסѩɴ�����������������\n\n",

"��Ů�������ף�������Ľ�ë΢΢��������������������˫�ֻ�����ס\n����˿������ǰ������ɢ��\n\n",

"��������Ƶ�ʽ����ӿ죬����Ů����������������س���������������\n���ضС���Ů���㻳��һ����̧��ͷ�����㣬�峺���������е�����ˮ\n����ת��\n\n",

"���������������ѩ��ϸ�¹⻬�ļ�����������������ĵ����ڣ�����\n����һֻ�ܾ���С���һ������������������һֱ���ε��ص���ɴ��\n\n",

"��Ůһ���ᴭ������ͷ�������ؿڣ���ҧ����������������������\n���ڵ���֮�����ۣ�̽������ס���Ľ�������̧�٣��ͻ����������ģ�\n������\n\n",

HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",
HIR BLK "��",

"\n\n�������������۾��������Լ�б����С���Ҳ��һ�ѿݲ�֮�ϣ������\n���˼���ֻ�ǱǶ��д����������������㡣\n\n",

"һ�س��Ƶ�ѩɴ�����ڿݲݱ��ϣ���Ŀ���ĵ���ӡ��һĨ���졣�㶢��\n��һĨѩɴ������ļ���צ��������ʹ����㱼���������ʱ����������\n����������\n\n"CYN"����һ�Ρ�\n\n",

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


	message_vision(WHT+msg+NOR,me,target);


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy2",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		destruct(target);
		me->set_temp("disable_inputs",0);

		if (present("feng minxin"))
			destruct(present("feng minxin"));

		if (present("mayuri"))
			destruct(present("mayuri"));

		REWARD_D->riddle_done(me,"����",0,1);
		return;
	}
	return;
}



void do_ggyy3(object me,object target,int count)
{
	string msg;
	string *event_msg = ({



HIR BLK"\n��һ·��ɫ���ף�é����ҡ��ǳ��ɫ����վ�����������΢����������\n����С������һͷ��ֱ������һͷ��"NOR,
WHT"��һϮѩɫ��ɴ����Ӱ����С�����������һֻ�������Ĵ���һ\n���ںڵĳ�����к�ڵء�\n\n����ż�䷲������顣"NOR,
"�㲻�������ɿ��˽��ճ��޵��֣���һ�Ƶ�Ц���ĵ����ϴ��࣬�ỽ��\nһ��������һ�����������֣����ġ�",
"��Ů����̧��˫���������۾������ī��������͸��Ө��\n���ع⣬����������΢΢��Ц���ֻ��������ع⡣��",
"���Ǿ����ض�����������ӯ�������Ե���������ֻ��������������Ů��\n������ƫ��ͷ����ش��������ǣ��̶�һ�����ĳ�����չ����ȥ����\n��������һ��ϸ���"HIY"��ɫ���"NOR CYN"�����Ĺ켣��",
"\n"HIW"1"NOR CYN")"HIY"��������ʦ�������ң�����"NOR CYN"\n"HIW"2"NOR CYN")"HIY"���ģ�����������"NOR CYN"",
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



	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy3",4,me,target,count+1);
	else
	{
		set("ggyying",0);
//		me->set_temp("annie/no_leave",0);
//		destruct(target);
		me->set_temp("disable_inputs",0);
//		if (present("su ruo"))
//			destruct(present("su ruo"));
		me->set_temp("annie/answer",1);
//		input_to( (: call_other, __FILE__, "select_main", me, target :));
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



/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/


