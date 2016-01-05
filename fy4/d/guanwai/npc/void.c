// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
	set_name("����", ({ "void" }) );
	set("class","bat");
	set("gender", "����" );
	set("age", 24);
	set("per", 50);
	set("int", 40);
	set("str", 4);
    create_family("��ң��", 1, "��һ����ʦ");
	set("score",-10000);
	set("title",HIY"�����޵�"NOR);
	set("combat_exp",0);
	set("eff_kee",1);
	set("kee",1);
	set("attitude", "friendly");
	set("long","����������������ȴ����ຮ֮�ز��Ŵ��ơ�\n");
	set("void",1);
	set("chat_chance", 1);
	set("chat_msg", ({
		"����̾�������������Ϧ���������ţ����˺η���\n",
	}) );
	set("no_arrest",1);
	set("no_heal",1);
	set("NO_KILL","��ͻȻ����һ��������������ס���֡�\n");
	setup();
	set_temp("apply/attack",-999);
	set_temp("apply/dodge",-999);
	set_temp("apply/parry",-999);
}

void init()
{	
	object ob;
	::init();
	add_action("do_accept", "answer");
	add_action("do_listskill","skills");
	add_action("do_say","say");
	if( interactive(ob = this_player()) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void do_say(string arg)
{
	object me = this_player();
	if (arg != "��÷�Ѳ����ܻ�ͷ�ˣ�����Ե���Ѿ�")
		return;
	if ( REWARD_D->riddle_check( me, "��Ϧ����")!=2)
	{
		message_vision("��������˵�������������ܵģ���һ������ƭ�ң�\n", me);
		return;
	}
//	if (me->query("annie/void") != 2)
//		return 0;
	if (query("ggyying"))
	{
		tell_object( me, "�������ڳ���û��������˵ʲô��\n");
		return;
	}
	set("ggyying",1);
	me->start_busy(12);
	call_out("do_ggyy",1,this_object(),me,0);
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ( REWARD_D->riddle_check(ob,"��Ϧ����"))
		if (!query("ggyying"))
			message_vision(CYN"����һ��$N��ӭ����ȥ����λ"+ RANK_D->query_respect(ob)
				+ "�����Ѿ���������ô��\n"NOR,ob);
}

int do_listskill(string arg)
{
	object me = this_player();
	if (!arg || present(arg,environment()) != this_object())
		return 0;
	write("����Ŀǰ��ѧ��ʮһ�ּ��ܣ�\n\n  �������� (blade)                         - "HIW"��ɲ�"NOR" 400/    0\n  ��Ծ����֮�� (dodge)                     - "HIW"��ɲ�"NOR" 400/    0\n  �ڹ��ķ� (force)                         - "HIW"��ɲ�"NOR" 400/    0\n���������� (god-dance)                     - "HIW"��ɲ�"NOR" 400/    0\n��ڤ�缱ն (hellblade)                     - "HIW"��ɲ�"NOR" 400/    0\n  ������ (iron-cloth)                      - "HIW"��ɲ�"NOR" 400/    0\n  �����Ṧ (move)                          - "HIW"��ɲ�"NOR" 400/    0\n���������� (nullforce)                     - "HIW"��ɲ�"NOR" 400/    0\n  �˻���֮�� (unarmed)                   - "HIW"��ɲ�"NOR" 400/    0\n���������� (void-shield)                   - "HIW"��ɲ�"NOR" 400/    0\n��Ϣ��Ǭ�� (worldstrike)                   - "HIW"��ɲ�"NOR" 400/    0\n\n");
	return 1;
}

void attempt_apprentice(object me)
{
	
	if ( me->query("annie/void") + 86400 < time())		// �Ѿ�����ԭ������Ϧ�ˣ���û�����������һ�� 
	if ( REWARD_D->riddle_check(me,"��Ϧ����") == 1) {
		me->delete("riddle/��Ϧ����");
	}
	
	if (!REWARD_D->riddle_check(me, "��Ϧ����") 
		&& !REWARD_D->check_m_success(me,"��Ϧ����")
		&& !query("ggyying"))
//	if (!me->query("annie/void") && !query("ggyying"))
	{
		message_vision(CYN"\n$n����$Nһ�ۣ�Ŀ��ͻȻ��¶����˼֮ɫ��\n"NOR,me,this_object());
		message_vision(CYN"$n��$N˵������λ"+RANK_D->query_respect(me)+"��Ը����һ��æ��\n"NOR,me,this_object());
		message_vision(HIW"("HIY"answer yes"HIW"/"HIY"no"HIW")\n"NOR,me,this_object());
		me->set_temp("annie/void",1);
	} else
		message_vision(CYN"�����ƺ����������£����㲻�Ų��ʡ�\n"NOR, me);
	
}

int do_accept(string arg)
{
	object me = this_player();
	object ob;
	
	if (arg == "��÷�Ѳ����ܻ�ͷ�ˣ�����Ե���Ѿ�")		{
		do_say(arg);
		return 1;
	}
	
	if (me->query_temp("annie/void")  && !query("ggyying"))
	{
		if (arg == "yes")
		{
			me->delete_temp("annie/void");
			message_vision(CYN"$n��Ŀ����Ʈ�ƶ����ʣ�����Ʈ��������ڿ��л��죺���Ǻܶ�ܶ���ǰ�ˣ�����\n"NOR,me,this_object());
			message_vision(CYN"$nҡ��ҡͷ������̾�����쳾������ָͬ��ɰ������ӯӯ��������ģ���֪�������©����ȥ��\n"NOR,me,this_object());
			message_vision(CYN"$n΢΢Ц����������Ե���뽫��ֻС���͸���ԭ�������ˣ������û�����Ե�֣���Ҳ����ǿ���ˡ�\n"NOR,me,this_object()); // lazy annie
			message_vision(CYN"\n$n����$Nһֻֽ��С����\n\n"NOR,me,this_object());
			message_vision(CYN"$n����һ̾���������������޵У���Ϊ�����ĸ��֣��Ҹ�����̫�ߵĴ��ۣ��ο������ο�����\n"NOR,me,this_object());
			me->set("annie/void", time());
			ob = new(__DIR__"obj/paperboat");
			if (ob->move(me))
				REWARD_D->riddle_set(me,"��Ϧ����",1);			
//				me->set("annie/void",1);
			else
				destruct(ob);
			return 1;
		}
		else if (arg == "no")
		{
			me->delete_temp("annie/void");
			ccommand("sigh");
			ccommand("flook");
			return 1;
		}
	}

	return 0;
}


void do_ggyy(object me,object target,int count)
{
	int i,j;
	object item;
	string msg;
	string *event_msg = ({
"\n����һ������ɫ����תΪһƬ�԰ף�����������˼�����",
"����������ɽ�±��ϣ��૵���Ե�֣���Ե���Ѿ�����",
"�������˺��ۣ���Ц����û���㣬���ǵ�����������Σ�",
"�����³�һ����Ѫ��������𣬴ӻ����ͳ�һ��С���ӣ�������$n��ȥ��$n��æ\n��סС�ᣬ��̧�۴���ֻ��ɽ��ϰϰ������ȴ���ﻹ��������Ӱ�ӣ�",
});
	if (!me || !target)
		return;
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
		return;
	msg = event_msg[count];
	message_vision(CYN+msg+"\n"NOR,me,target);
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",1+count+random(count),me,target,count+1);
	else
	{
		set("ggyying",0);
		target->add("annie/void",1);
		i = random(100);
		// L120 unarmed/parry/dodge/move/literate/force
		// L120 chanting/foreknowledge/perception/iron-cloth	
		if (i<99)		
			j=1+random(10);
		else							// L170 zensword
			j=12;
		if (!target->query("class"))	// L50 demosword
			j=13;
//		item = new("/obj/specials/moon/book" + j);
		item = new("/obj/book/moon/book" + j);
		item->move(target);
		target->set("annie/7cbook","book"+j);
		CHANNEL_D->do_sys_channel(
			"sys", sprintf("%s(%s)����Ϧ�����еõ���һ��%s��\n",
	                target->query("name"),target->query("id"),item->query("name")));

		log_file("riddle/annie_log", sprintf("[%s] %s(%s)����Ϧ�����еõ���һ��%s��\n",
			ctime(time()), target->query("name"),target->query("id"),item->query("name")));

		REWARD_D->riddle_done(target,"��Ϧ����",20,1);


		destruct(this_object());
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

