#include <ansi.h>
inherit SMART_NPC;
int showpower();
int wieldblade();
void create()
{
        set_name("����", ({ "ding peng","ding" }) );
        set("gender", "����");
		set("age",35);
        set("combat_exp", 9000000);
        set("reward_npc", 1);
		set("difficulty", 10);
        set("long","
�����Ѿ����ˣ��Ѿ�������ǰ�Ǹ��嶯��֪�������ˡ����ڲ���
��������أ����Ҵ����ֳ�Խһ�е����š�\n"
	);
	
		set_skill("move",100);
        set_skill("parry", 250);
		set_skill("blade",250);
		set_skill("dodge",250);
		set_skill("moon-blade",100);
		set_skill("perception",250);
		
		map_skill("blade","moon-blade");
		map_skill("parry","moon-blade");
		map_skill("dodge","moon-blade");
	        
        set("chat_chance", 1);
		set("arrive_msg","ʩʩȻ�߹���");
		set("leave_msg","���߳���Զ����������������������һ˲������߳���Զ");
        set("chat_msg", ({
			(: random_move :),
			(: showpower :)
        }) );

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
            (: wieldblade  :),
        }) );

        set_temp("marks/disarmed",9999999999);
        setup();
		carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/wandao")->wield();
}


int showpower()
{
	tell_object(environment(this_object()),"������ѵ��ѳ��ʡ�����һ����
	����������Ļ��ȣ���·�ߵ���ʯ������ȥ���ǿ鿴���ȸ���
	��Ӳ����ʯ����Ȼ�ڵ����±��������룡\n");
	set_temp("marks/disarmed",time()+ 3600);		// �������ٱ�disarm�˰�
	return 1;
}

int wieldblade()
{
	if (query_weapon())
		perform_action("blade.mingyue");
	return 1;
}
