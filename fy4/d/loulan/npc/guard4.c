#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("������", ({ "wang xiaqi","wang" }) );
        set("gender", "����" );
        create_family("�����", 1, "���������");
        set("long",
"��������������ļ�����ʮ�����ս���꣬������һ�а١�������֯����װ��\n��ǰ����һ����ͭ���ľ���Ψ�о��Ͽ̵��ֲ�ͬ�����Ͽ��š��ġ��֡� \n"  
                );
        set("attitude", "peaceful");
	set("class","bat");
		set("perform_busy_d", "bat/dodge/meng-steps/huanyinqianchong");
		set("perform_weapon_attack","bat/blade/bat-blade/shiwanshenmo");
		
		set("chat_chance_combat", 20);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
	set("age", 25);
        set("combat_exp", 650000);

        set("chat_chance", 2);
        set("chat_msg", ({
                "�����������бƳ����һ�ۡ�\n",
                }) );

        set_skill("unarmed", 80);
        set_skill("blade", 100);
        set_skill("bat-blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("meng-steps", 100);
        map_skill("dodge", "meng-steps");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                
        setup();
	carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/doupeng4")->wear();
	carry_object(__DIR__"obj/huxinjing4")->wear();
	carry_object("/obj/weapon/blade")->wield();
}

void init()
{	
	object me;
	::init();
	me = this_player();
	if( interactive(me) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 0, me);
	}
}

void greeting(object me)
{
	object *inv;
	int i;
	object ob;
	ob = this_object();
	
	if (environment(me) != environment(ob))		return;
	if( userp(me) )
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if(inv[i]->query("item_owner")=="������" && (int)inv[i]->query("equipped"))
			{
				message_vision(HIY"$N��ȵ���������˴󵨣�����ð�䱾�\n"NOR,ob);
				ob->kill_ob(me);
				me->kill_ob(ob);
			}
		}
	}
}