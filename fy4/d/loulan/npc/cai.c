#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("������", ({ "jin wuwang","jin" }) );
        set("gender", "����" );
        set("long",
"һϮ���£����ޱ��飬�����ɽһ�㡣��Ŀ��ת��֮�䣬�������˵����ϡ�
�˿����������ʹ֮��ʹ��רΪ������Ѽ����ڲƱ���\n");

        create_family("�����", 1, "��ʹ");
        set("attitude", "peaceful");
		
		set("perform_busy_u", "bat/dodge/meng-steps/huanyinqianchong");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
		set("age", 34);
        set("combat_exp", 1000000);

        
        set("chat_chance", 1);
        set("chat_msg", ({
        	"������˫Ŀ΢�أ��ݷ���ɮ�붨��һ��������\n",
        }) );

        set_skill("unarmed", 160);
        set_skill("blade", 160);
        set_skill("bat-blade", 130);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("move", 200);
        set_skill("meng-steps", 150);
        set_skill("nine-moon-claw", 140);
        
        map_skill("dodge", "meng-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                
        setup();
        carry_object(__DIR__"obj/foxcloth")->wear();
}


int accept_object(object who, object obj)
{	
		mapping all;
		
		if (REWARD_D->check_m_success(who,"��ɫ����"))	return 0;
			
		if( (int) obj->value() >= 20 * 10000)
		{
			message_vision("$N���������$n���˵�ͷ��\n",this_object(),this_player());
			REWARD_D->riddle_set(who, "��ɫ����/cai", 1);
			tell_object(who, WHT"������ˡ���ɫ�������еġ��ơ�\n"NOR);
			all = who->query("riddle/��ɫ����");
			if (mapp(all) && sizeof(all) == 4)
				REWARD_D->riddle_done(who,"��ɫ����",50,1);			
			return 1;
		}
		else
		{
			message_vision("$N������ү��ϲ�£�û�ж�ʮ�����ӾͲ��س������������ˡ�\n",this_object());
			return 0;
		}
}
