#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void create()
{

		set_name("����",({"tie hen","tie"}));
    	set("nickname","��������");
    	set("title",WHT"�Ĵ�����"NOR);
    	set("long", "
һ�����ӱ�ǹ���ͦ�ĺ����ˣ���Į�������п��������������������Ĵ���
���еġ��������顱�����޵����ҳ����ӣ�����С�ˡ������������������Ƶľް���
�Ѳ�֪�ж��١���\n");
		set("age",47);
		set("combat_exp", 7000000);
        set("attitude", "friendly");	
	
		set("inquiry", ([
        		"������" : 	"�������Ƕ���һ�ԣ�����ǰ��Ȼ����ɱ�ˡ�\n",
             	"����" :	"����������ǰ̫ƽ�������鱦ʧ��һ�����ӵ��ֵܣ�������׷������\n",
             	"long wang" : 	"�������Ƕ���һ�ԣ�����ǰ��Ȼ����ɱ�ˡ�\n",
             	"guo yi" :	"����������ǰ���������鱦ʧ��һ�����ӵ��ֵܣ�������׷������\n",
             	"̫ƽ��" :	"̫ƽ����������һ��С��\n",
             	"Τ����":	"����Τ�������ҵĺ��ѣ���˵���Ѿ�����̫ƽ��\n",
             	"Ѫ����":	"action����Ũü��������Ѫ���ģ���˵��̫ƽ����һ���йء�\n",
             	"�ص�":		"��׷�ٹ��׵��˱�ʧ����Ӱ��ȴ������ɱ�ֳ��֡�\n",
             	"�س�":		"��׷�ٹ��׵��˱�ʧ����Ӱ��ȴ������ɱ�ֳ��֡�\n",
             	"����ɱ��":		"��׷�ٹ��׵��˱�ʧ����Ӱ��ȴ������ɱ�ֳ��֡�\n",
             	
   		]));
	
    	set("reward_npc",1);
    	set("difficulty",10);
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(40) :),    
        }) );
		
		auto_npc_setup("xuebin",250,190,0,"/obj/weapon/","fighter_w","dragonstrike",1);
		setup();
		carry_object(__DIR__"obj/blackcloth")->wear();
		carry_object(__DIR__"obj/jade");
}


void init() {
	
		object ob;
		::init();
		add_action("do_answer","answer");
		if( interactive(ob = this_player()) && !is_fighting()) {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
	call_out("ask_question_1",1,ob);

}

int ask_question_1(object who)
{
	
	if (REWARD_D->check_m_success(who,"�Ѫ����"))	return 1;
	
	if (REWARD_D->riddle_check(who,"�Ѫ����")>4 ||who->query_temp("marks/parrot/��̫ƽ��"))	{
		message_vision(CYN"$N��$n˵������ô��������������ô����\n"NOR,this_object(),who);
		return 1;
	}
	
	// This one is just a temp mark.. to prove players' value.	
	if (!who->query_temp("marks/parrot/t_question_1") 
			&& REWARD_D->riddle_check(who,"�Ѫ����")<3) {
		tell_object(who, CYN"���޿�����һ��˵����˵����������һ��ʮ�ˣ���Ȼ��һҹ֮�����øɸɾ�����
���º�����û�й�ϵ��\n"NOR);
    	who->set_temp("marks/parrot/t_answer_person",1);
		return 1;
	}
	
	if (REWARD_D->riddle_check(who,"�Ѫ����")<=1)	{
		tell_object(who, YEL"����Ũü����������Զ���ķصأ�һ�ﲻ����\n"NOR);
		return 1;
	}
	
	if ( REWARD_D->riddle_check(who,"�Ѫ����")==2 && who->query_temp("marks/parrot/t_question_1")) {
		tell_object(who, CYN"���޿�����һ��˵�������ڵ�������ǰ���������鱦ʧ��һ�������ӵ��ֵܹ���
��˵Ǳ���ڴ˷ص�֮�䣬���Ƿ������\n"NOR);
		who->set_temp("marks/parrot/t_answer_person",2);
		return 1;
	}
	
	if ( (REWARD_D->riddle_check(who,"�Ѫ����")== 3 
			|| REWARD_D->riddle_check(who,"�Ѫ����")==4)
			&& !who->query_temp("marks/parrot/��̫ƽ��") ) {
		tell_object(who,CYN"\n���޹��ֵ�������������ʿ��������һ��ð�����󣬲�֪�ɷ�\n"NOR);
		who->set_temp("marks/parrot/t_answer_person",3);
		return 1;
	}
}

int do_answer(string arg)
{
	object who,*inv,jade;
	int i, gotit;
	
	who=this_player();
	
	if(!who->query_temp("marks/parrot/t_answer_person")) return 0;
		
	if (who->query_temp("marks/parrot/t_answer_person")==1) {
		if(arg=="yes" || arg == "��" || arg == "��" || arg == "����ɱ��")
		{
			who->ccommand("nod");
			if (!who->query("m_killer/������")) {
				tell_object(who, CYN"������Ц������Ȼ��ˣ��㻹���Լ�ȥͶ���ɡ�\n"NOR);
				who->delete_temp("marks/parrot/t_answer_person");
				return 1;
			}
			tell_object(who,CYN"���޻��Ƶ���ɱ��ɱ���ˣ�ɱ��ȡ���ģ������\n"NOR);
			who->delete_temp("marks/parrot/t_answer_person");
			who->set_temp("marks/parrot/t_question_1",1);
			call_out("ask_question_1",1,who);
			return 1;	
		}
		if(arg=="no" || arg == "û��"){
			message_vision(CYN"$N�Ͻ�ҡ��ҡͷ��\n"NOR,who);
			tell_object(who,CYN"����˵��������׷���׷���������ͺá�\n"NOR);
			who->delete_temp("marks/parrot/t_answer_person");
			return 1;
	        }
	}
	
	if (who->query_temp("marks/parrot/t_answer_person")==2) {
		if(arg=="yes" || arg == "��" || arg == "��" || arg == "����")
		{
			who->ccommand("nod");
			tell_object(who,CYN"���޵����ã�����Ȼ��������Ӳ����ˣ�\n");
			who->delete_temp("marks/parrot/t_answer_person");
			REWARD_D->riddle_set(who, "�Ѫ����", 3);
			call_out("ask_question_1",1,who);
			return 1;	
		}	
		if(arg=="no" || arg == "û��"){
			message_vision(CYN"\n$N�Ͻ�ҡ��ҡͷ��\n\n"NOR,who);
			tell_object(who,CYN"���޺ȵ����󵨣���Ȼ�Һ�ƭ���ң����ҵ�������ȥ˵����\n"NOR);
			who->delete_temp("marks/parrot/t_answer_person");
			this_object()->kill_ob(who);
			who->kill_ob(this_object());
			return 1;
	    }
	}
	
	
	if (who->query_temp("marks/parrot/t_answer_person")==3) {
		if(arg=="yes" || arg == "sure" || arg == "��Ȼ" || arg == "��" || arg == "��")
		{
			message_vision(CYN"$N�������¶�����ͷ�����ĳ������Ѿã��Ҳ�������\n"NOR,who);
			command("spank "+this_player()->get_id());
			tell_object(who,CYN"
���޵����ܺã���׷��̫ƽ����һ���������꣬����ǰ���������ڰ��ж���ʧ��
���鱦���Ѿ��Ļ���������������ʱ��ȴͻȻ���������������������ġ����֡���
����������Դ������һ������̫ƽ��ĵط�����������˿��׷�����ˣ�ȴ����
�������˼��ӽ�ɱ���ҿ�����ɱ���ߺ�ɽׯ������������������֮ʱ���Ѿ�֪��
����һ������Ľ��ͣ���������������һ��֮�����ȵ�̫ƽ�򿱲飬���Ҵ򷢵���
��֮���������ϡ�̫ƽ����С�������ѷ֣����账��С�ģ��������¡�\n"NOR);
			
			jade=new(__DIR__"obj/jade");
			if (!jade->move(this_player()))
				jade->move(environment(who));
			tell_object(who,"���޵ݸ���һ��������ƾ�˱���ȥ��һ����Τ�����Ů�ӣ�
����������ǰ����Ǳ��̫ƽ���̽�����\n");
			
			who->delete_temp("marks/parrot/t_answer_person");
			REWARD_D->riddle_set(who, "�Ѫ����", 4);
			
//	finish with �س� riddle, 
//	If the player loses the jade, relogin can get another one
			who->set_temp("marks/parrot/��̫ƽ��",1);
			return 1;	
		}
		if(arg=="no" || arg == "��" ){
			message_vision(CYN"$N��ԥ������ҡ��ҡͷ��\n"NOR,who);
			tell_object(who, CYN"����ʧ����̾�˿���˵���˸���־���Ҳ���ǿ��\n"NOR);
			who->delete_temp("marks/parrot/t_answer_person");
			return 1;
	     }
	}
	return 0;
}

