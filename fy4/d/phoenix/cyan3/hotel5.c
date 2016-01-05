// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "�����");
    set("long", "����һ�����ͨ��ССľ�ݣ����ŵ��ӣ�һ��С�����Աߵ���ױ̨��Եб
б����������ɽҰ���洦�ɼ��ĵ���ɫ�����ǻ����ܼ򵥵İ��裬ȴ��������
��״�����ʸо���Ψһ����ͻأ�ı�������֮��������һ��"WHT"�Ҷ�"NOR"����������
��ɱ���������֣��ʷ����м��ᣬ���ǳ���Ů��֮�֡�
"NOR
        );
	set("objects", ([
	__DIR__"obj/scroll":1,

	]));
	set("item_desc", ([
	
	]) );
	set("exits",([
  		"east" : "bridge",
	]) );
	set("area","cyan3");


	set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",80);
	setup();
}


int do_nothhing()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	else
		return 1;
}

int do_a1()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	me->delete_temp("annie/answer");
	me->set_temp("disable_inputs",1);
	call_out("do_ggyy3",2,me,present("su ruo"),0);
	return 1;
}

int do_a2()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	me->delete_temp("annie/answer");
	me->set_temp("disable_inputs",1);
	call_out("do_ggyy2",2,me,present("su ruo"),0);
	return 1;
}


int do_g(string arg)
{
	object me=this_player(),l;
	if (arg != "all from �Ҷ�" && arg != "pill from �Ҷ�")
		return 0;
	if (query("al"))
		return 0;
	message_vision("$N���Ҷ����ȡ��һ��"HIR"��ת���굤��"NOR,me);
	l=new("/d/shenshui/obj/medicine");
	l->move(me);
	set("al",1);
	REWARD_D->riddle_done(me,"ɱ�������ҩ��",0,1);
	return 1;
}

void init() {

	object ob;
	object me = this_player();
	::init();

	if (!userp(me))
		return;

	if (query("c"))
		return;

	set("c",1);

	
	if(!wizardp(this_player()))
			add_action("do_nothhing", "");
	add_action("do_a1","1");
	add_action("do_a2", "2");
	add_action("do_g", "get");



	if (REWARD_D->check_m_success(me,"����") 
		|| REWARD_D->check_m_success(me,"����")
		|| REWARD_D->check_m_success(me,"���")) 
	{

		ob=new(__DIR__"npc/ruo");
		ob->move(this_object());

//		input_to( (: call_other, __FILE__, "select_main", me,ob :));
//		"/cmds/std/look"->look_room(this_player(),this_object());
		

		me->set_temp("disable_inputs",1);

		call_out("do_ggyy",2,me,ob,0);

		return;
	}
	ob = new(__DIR__"obj/letter");
	ob->move(this_object());
	return;


}





void do_ggyy2(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"��Ů����˫�֣�ƫͷ¶��һĨ��Ƥ�ɰ�����Ц�������һ����������˺�Ҳ�ƿ��ա�",
"����Ȼ��Ҫ����̳�������㣬���������Ķ�˯����ѽ��������գգ�ۣ�����Ȼ��ʦ��\nҪ�ұ�ͬ���ߵ�̫���ء���",
MAG"�������ת��ȴ��ôҲ�벻������ʱ�����ҹħ̳����",
"���������ϻ����£�����Ů���������һ�ۣ������˵��أ��˼Һ����ײſ��޳���ˮ\n���꣬��һ���Ӿͱ���ٵ�ǬǬ��������",
"���Ǹ���������",
"�����ӡ���������һ��Ц����������ȥæ��İգ��һ��������أ��ɲ��Ǵ�Ҷ�ͬ��\nһ�����ֺ��С���


��������ӻ����е�ľ�ѣ���һ����������ӹ�����ʧ�����С�",
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
		call_out("do_ggyy2",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		destruct(target);
		me->set_temp("disable_inputs",0);
		if (present("su ruo"))
			destruct(present("su ruo"));
		
		REWARD_D->riddle_done(me,"����",0,1);
		return;
	}
	return;
}




void do_ggyy3(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"\n�������Ż��������ɽ���ϣ��˵ú��ص������أ���������ͷ��������ƺ��������㣮������",
"��Ů����һ�٣�������Ⱦ���˵����İ�������㣮�����ܿ�������������������
ʱ��������Ҫ��������¥�ˡ��Ƕ������ĸ�ĸ����֪Ů������֢����ò�����
ô���������ǣ�����",
"���������̾�˿�����",
"����������������û��Ц���ġ���ħ̳����������Ϊ�˱�������ɣ����ܾ��÷���
����ȼ���Լ��������أ��ܾ�����һ�죬�������ô����ȥ��������",
WHT"���Ҽž���",
"��Ů���ͷ����Ū�����е�ľ�ѣ������˵������ʱ���Ҿ����Լ���ĺ����ˣ�����
�������ô�Ҹ���������",
"һ����Х���·���ɽ���д���������һ������һ�������������˹�ȥ����ʧ����
֮�С�",
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
		call_out("do_ggyy3",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		destruct(target);
		me->set_temp("disable_inputs",0);
		if (present("su ruo"))
			destruct(present("su ruo"));
		
		REWARD_D->riddle_done(me,"����",0,1);
		return;
	}
	return;
}



void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"ɽ�紩��������ľ������ǰ��Ů����Ķ̷�����ʱ��ķ��Ʒ���\n������������ĽŲ������µ���Ů��ת��ͷ������¶���貵�Ц�ݡ�\n",
WHT"����ү����������ϡ�Ͱ�����ʲô����㴵�˹�����\n\n"NOR"����("HIW"1"NOR CYN")"HIY"�ɼ������ģ�\n"NOR CYN"����("HIW"2"NOR CYN")"HIY"���������"NOR CYN"",
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


	message_vision(CYN+msg+"\n"NOR,me,target);


	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",2,me,target,count+1);
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


