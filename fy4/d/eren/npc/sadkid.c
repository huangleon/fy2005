inherit NPC;
#include <ansi.h>
inherit INQUIRY_MSG;
int give_mission();
int give_flower();

void create()
{
        set_name("���Ʋ��ֵ�С��", ({ "sad kid","kid" }) );
        set("gender", "����");
        set("age", 12);
        set("long",	"һ��ʮ�������С�������Ʋ��ֵ������﹡�ϡ�\n"	);
		set("chat_chance", 1);
        set("chat_msg", ({
        	"С��˵��С����ô�����ˣ�û�˺���һ�����ˡ�\n",	
        }) );
		set("inquiry", ([
        	"С��" : (: give_mission :),
        	"xiaoyan" : (: give_mission :),
        	"��֦һҶ��":	(: give_flower :),
   		]));


		set("combat_exp",5000);
        setup();
		carry_object("/obj/armor/cloth")->wear();
}

int give_mission()	{
	object ob;
	ob=this_player();
	command("say С�����ҵĺ����ѣ��ղ����ǻ������ֱ߶������棬һ�ξͲ����ˡ�");
	if (!REWARD_D->riddle_check(ob,"˾��С��"))
		REWARD_D->riddle_set(ob,"˾��С��",1);
	
	return 1;
	
}	


int accept_object(object me, object obj){
	if (obj->query("24dao")) {
		command("ack");
		command("say �⻭�ϵľ���С�̰�������һ��Ҫ�ҵ�����");
		REWARD_D->riddle_set(me,"˾��С��",2);		// yeh, step 1 is not necessary.
	}
	
	if (obj->query("24dao_ren")) {
		command("cry");
		command("say �����С�̵����˶�����ƽʱ����������������һ���ǳ������ˡ�");
		REWARD_D->riddle_set(me,"˾��С��",2);
	}	
	return 0;
}

int give_flower() {
	
	object me, flower;
	me = this_player();
	
	if (!REWARD_D->check_m_success(me,"˾��С��")) {
		command("say �Ƕ仨���������ô����Ҳ��֪����������������
С�̸���͸��ҵģ��Ұ����غ��ˣ��ɲ��������ˡ�");
		return 1;
	}
	
	if (REWARD_D->check_m_success(me,"С����ҽ")) {
		command("say �ҵĻ����Ѿ��͸������ˡ�");
		return 1;
	}
	
	if (me->query_temp("marks/eren/7flower")) {
		command("say �Ҳ����Ѿ�������ô��");
		return 1;
	}
			
	command("sob");
	command("say С�̸�����ˣ���Ҳ��������ˡ�");	
	command("say ��仨������һ���ڵ��ģ����˾����ģ�����ȥ�ɡ�");
	flower=new(__DIR__"obj/flower");
	message_vision(CYN"$N����һ�仨��\n"NOR,this_object());
	me->set_temp("marks/eren/7flower",1);
	flower->move(me);	
	return 1;
}

