
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�����", ({ "li qingfeng","li" }) );
        set("gender", "����" );
        set("age", 65);
	set("title", HIG "������ն������׷��׽��ˮ��Ʈ"NOR);
        set("long",     "����ʮ���������������ֽ���ɾ��������������Ķ��д����\n");
        
        set("per", 27);
        set("attitude", "peaceful");
        set("combat_exp", 999999);
	set("pursuer",1);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );

             
        set_skill("unarmed", 120);
        set_skill("throwing", 100);
	set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("demon-force", 100);
        set_skill("demon-strike", 100);
        set_skill("demon-steps", 100);
        set_skill("tanzhi-shentong",100);
        
        map_skill("throwing","tanzhi-shentong");
        map_skill("dodge","demon-steps");
        map_skill("move", "demon-steps");
        map_skill("unarmed","demon-strike");
        map_skill("force","demon-force");
        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
        	(: perform_action, "dodge.lianhuanbabu" :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/yinwan")->wield();
        carry_object("/obj/armor/cloth")->wear();
}


void init()
{
	object me;
	add_action("do_answer","answer");
	me = this_player();
	if(interactive(me) 
	&& !me->query_temp("friend_to_xiao")) call_out("ask_him", 1,me );
	::init();

} 
int ask_him(object me)
{
	if(me && environment(me) == environment())
	{
	tell_object(me,name()+"�ȵ������ǲ�����ʮһ�ɵ����ѣ���answer yes/no��\n");
	me->set_temp("asked_yes_no",1);
	};
	return 1;
}

int do_answer(string arg)
{
	object me;
	me =this_player();
	if(!me->query_temp("asked_yes_no")) return 0;
	me->delete_temp("asked_yes_no");
	me->set_temp("friend_to_xiao","no");
	if(!arg || arg != "yes")
	return notify_fail(name()+"������ʮһ������Ϊ�书���µ�һ��ר����裬ΪһŮ����ɱ�޹���
	�������������Ҷ�Ҫɱ��\n");
	command("say �ã���Ȼ�����������ѣ��ҾͲ�����ɱһ����\n");
	kill_ob(me);
	me->kill_ob(this_object());
	me->set_temp("friend_to_xiao","yes");
	return 1;
}


int heal_up()
{
	if(environment() && !is_fighting() && !is_busy()
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}