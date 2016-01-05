#include <ansi.h>
inherit NPC;

int do_answer(string arg);
int lixia();
int gother();

void create()
{
        set_name("������", ({ "lan huzi", "lan" }) );
        set("long","�������������ķ��Ĵ��ϰ壮\n");
        set("attitude", "heroism");
		set("title", HIB "�����ķ����ϰ�"NOR);
		set("age",33);
		set("per", 30);
        set("combat_exp", 100000);
        set("chat_chance", 1);
        
        set("inquiry",	([
            	"��ɲ��":"��ɲ������������ɲ�����֮����������������ң�ȴ��������͵���ˡ�\n",
            	"��ɲ":	 "��ɲ������������ɲ�����֮����������������ң�ȴ��������͵���ˡ�\n",	
        		"����":	"�������ĸ��أ�������һ����\n",
        		"��ϼ":	 (: lixia () :),
        		"����":	 (: gother() :),
        ]));
        				
        set("chat_msg", ({
				"������̾������ɲ��ʧ�ԣ������ô���ˣ�\n",
        }) );

        set_skill("unarmed", 170);
        set_skill("sword", 170);
        set_skill("parry", 170);
        set_skill("dodge", 170);
        set_skill("move", 100);

        set_temp("apply/attack", 70);
		set_temp("apply/dodge", 70);
		set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        
        setup();
        carry_object(__DIR__"obj/yincloth")->wear();
}


int lixia(){
	
	object who, ob;
	
	who = this_player();
	ob = this_object();
	
	if (REWARD_D->riddle_check(who,"��ȡ��ɲ")< 1)
	{
		command("shake");
		command("say ��Ȱ�㻹�ǲ�Ҫ�����˻�ˮ�ĺã�");
		return 1;
	}
	
	command("say ��ϼ�����������͵�����ҵ���ɲ�ƣ���֪�����Ķ�ȥ�ˣ�");
	return 1;

}

void init(){
	::init();
	add_action("do_answer","answer");
}


int do_answer(string arg){
	if (arg!="����") {
		command("doubt");
		return 1;
	}
	
	gother();
	return 1;
}



int gother(){
	
	object who, ob;
	
	who = this_player();
	ob = this_object();
	
	if (REWARD_D->riddle_check( who,"��ȡ��ɲ")< 1)
	{
		command("hmm");
		command("say ���ݣ����ݣ�����ĳ�������ϰ���");
		return 1;
	}
	
	command("say ԭ������˶��������ȥ����������˵�������������ɲ�ƣ�
��ɱ���Ŀɲ�ֻ���������ӣ�");
	if (REWARD_D->riddle_check(who,"��ȡ��ɲ") ==1) 
		REWARD_D->riddle_set(who,"��ȡ��ɲ",2);
	return 1;

}
			