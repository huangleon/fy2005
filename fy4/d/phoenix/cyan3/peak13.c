// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit "/d/phoenix/ann_door_room.c";
string look_stone();

void create()
{
	set("short", "���¹ʾ�");
    set("long", @LONG
���ٵ����������գ�ĺɫ�е�ССľ��ֻ����ؼ�һĨ��ɫ�����Ǽ���
�������������ƣ�ת�����ɻ��������Գ��ص�һʱ������绪��ǣ�ӻ��ǣ���
�����롣ֻ������󣬷��������������һ����ҷ��Ҳ�ż�ɢȥ��ֻ���
�����գ�����ɡ� 

������Ƭʯ���ƿ�ɫ�࣬�����������ġ�

LONG
NOR









        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"southdown" : "peak12",
	]) );
	set("area","cyan3");

    create_door("southdown","rock","��ʯ","northup",DOOR_CLOSED);

	set("outdoors","cyan");

	set("coor/x",10);
	set("coor/y",60);
	set("coor/z",50);
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
	call_out("do_ggyy2",2,me,present("su ruo"),0);
	return 1;
}


int do_a2()
{
	object me = this_player();
	if (!me->query_temp("annie/answer"))
		return 0;
	me->delete_temp("annie/answer");
		message_vision(CYN"$n�����ת��ֻ������������һ�����ѿ��ƵĹؽڣ�ȴ��û���κ�ͷ�����ٶٽ�ת����ȥ��\n"NOR,me,me);

		open_door("southdown",0);
		me->ccommand("southdown");
		REWARD_D->riddle_done(me,"����",0,1);

		if (present("su ruo"))
			destruct(present("su ruo"));
		return 1;
}


void init() {

	object ob;
	object me = this_player();
	::init();

	if (!userp(me))
		return;


	
	if(!wizardp(this_player()))
	{
			add_action("do_nothhing", "");
			add_action("do_a1","1");
			add_action("do_a2", "2");
	}


	if (REWARD_D->riddle_check(me,"���Ļ���") <=6 && !REWARD_D->check_m_success(me,"����") && !REWARD_D->check_m_success(me,"����") && !REWARD_D->check_m_success(me,"���") && NATURE_D->getTime(time())[1] >7 && NATURE_D->getTime(time())[1] <11) 
	{

		ob=new(__DIR__"npc/ruo");
		
		ob->move(this_object());

//		input_to( (: call_other, __FILE__, "select_main", me,ob :));
//		"/cmds/std/look"->look_room(this_player(),this_object());
		

		me->set_temp("disable_inputs",1);

		call_out("do_ggyy",2,me,ob,0);

		return;
	}
	if (REWARD_D->riddle_check(me,"���Ļ���") <=6 && !REWARD_D->check_m_success(me,"����") && !REWARD_D->check_m_success(me,"����") && !REWARD_D->check_m_success(me,"���") ) 
	{
		ob=new(__DIR__"npc/ruo");
		
		ob->move(this_object());



		me->set_temp("disable_inputs",1);

		call_out("do_ggyy3",2,me,ob,0);

		


	}
	
	return;


}


void select_main(object me, object ob,string arg)
{
	if (arg != "1" && arg != "2")
	{
		input_to( (: call_other, __FILE__, "select_main", me, ob :));
		return;
	}
	if (arg == "1")
	{
		me->set_temp("disable_inputs",1);
		call_out("do_ggyy2",2,me,ob,0);
	}
	else
	{
		message_vision(CYN"$n�����ת��ֻ������������һ�����ѿ��ƵĹؽڣ�ȴ��û���κ�ͷ�����ٶٽ�ת����ȥ��\n"NOR,me,me);

		open_door("southdown",0);
		me->ccommand("southdown");
		REWARD_D->riddle_done(me,"����",0,1);

		destruct(ob);
	}
	return;

}



void do_ggyy2(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"��������Ծ������ľ�߶��£�˫���ỷ����������Ů���������ڱ���֮�䣬������Ȼ���ԣ��·����֮ǰ���й���㾭�顣",
"ι������������������ɢ����Ů�԰׵������Ͻ����ظ�����Σ��촽΢�������㻳�е͵�������",
"��һʱ����Գ������Ҫ����ͷȥ��ȴ����Ů���������۾�����ͫ�������ɵ������㡣",
"�������ϳ���������ݣ����ǣ������һ��������΢Ц�����ѹ⣮�����ֺ��ң�����",
"һ��ַ���Ǿ������ֻ������һ�ᣬ������Ů������һ�����̵�Ӱ�ӻ��С�\n��Ӱ��˲���䴩�ֶ�ȥ���������������һ�侯��������ߣ�����ħ̳��С�ӣ��´����������µ��ӣ���\nĪ�����ﲻ�����ǳ�ʦ���������������㣡��",
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
		call_out("do_ggyy2",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		destruct(target);
		me->set_temp("disable_inputs",0);
		if (present("su ruo"))
			destruct(present("su ruo"));

		if (present("demon drug",me))
			if (present("demon drug",me)->query_amount()>=2)
				present("demon drug",me)->add_amount(-2);
		
		REWARD_D->riddle_done(me,"����",0,1);
		return;
	}
	return;
}



void do_ggyy3(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"������Ц����ѽ���Ҹ�Ҫȥ���㣬����ү�����Լ������ˣ�",
"�����������е�һ������ż���Ц����̳��Ҫ��ȥ��ʲô��զ�ӵĴ�᲻�ǣ���������Ѿ��������������",
"����˫ָһ��������䵽�㻳�У�����ƮȻ��ȥ���������һ��������Ц��������ү���ɼǵ�����Ƿ��һ�������ޡ�",
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
		call_out("do_ggyy3",2,me,target,count+1);
	else
	{
		set("ggyying",0);
		me->set_temp("annie/no_leave",0);
		destruct(target);
		me->set_temp("disable_inputs",0);
		if (present("su ruo"))
			destruct(present("su ruo"));

		target=new(__DIR__"obj/letter1");
		target->move(me);

		REWARD_D->riddle_done(me,"���",0,1);


	tell_object(me,HIY"�������ı��ˣ�\n"NOR);

	me->set("quest/short", WHT"ȥ"CYN"���ƶ�"WHT"�μ���Ѫƽ�ܴ��"NOR);
	me->set("quest/location", "somewhere");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());


		return;
	}
	return;
}




void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({

"���յ�Ϧ��бб������Сľ��ǰ�������ϣ�΢��������ɽ��ľҶ�������죬��ؼ���ת�������Ľ�ơ�",
"������Ů�п�����Ժ��һ����ľ���ϴ��ᰴ���е�ľ�ѣ�����������׽��������Ʈ�����ɡ�",
"�����������ӣ������ǰ�û������ְ�쵾����ƺ�һ���������Ѷ������ȴ�ֿ��������ɼ���",
"���ڽ����θߣ�һʱ���׾�ת��ü������ң��ڼ��޿��ܴﵽ�ĸ߶�������������������ǧ��Ķ��壬\n��������ʾ�������������޵Ŀ��顣",
HIR"����������ؿ��伱���������������澭�������������ֺ��޹��ɣ�һ������������ԴԴ������ӿ������\n����һ���������д�������������ף��ȵ�����������",
HIR"�����������Ȼ��ֹ����Ů�����ػ�����ǰ���˸����ģ�ž�ؽ����е�ľ���������أ���һ�����һ���\n��Ѫ�˵��ڵء�",
"��ֻ���ⳡ�����Ƿ�����Ϥ��һʱ��ͷ���ң���֪�Ǹ�("HIW"1"NOR CYN")"HIY"��ǰ����"NOR CYN"����("HIW"2"NOR CYN")"HIY"������ȥ"NOR CYN"��",
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


