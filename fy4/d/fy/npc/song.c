
inherit NPC;
#include <ansi.h>


void create()
{
        set_name("��������", ({ "gu song","song" }) );
        set("title", HIG "�꺮����"NOR);
        set("long",     "
����ī���廨���ۣ�ͷ������ƽ�߹ڵ����ˣ�������̵����󻤷�֮һ��\n");
        set("gender", "����" );
        set("age", 66);
        set("str", 6);
		set("per", 27);
             
        set("reward_npc", 1);
        set("difficulty", 2);
		set("fly_target",1);
		set("intellgent",1);
        set("attitude", "peaceful");
	        
        set("chat_chance", 3);
        set("chat_msg", ({
//                (: random_move :),
				"����������Ц������ɽͼ��ʧ�Ѿã�û�а�ɽͼ��ָ����������Щ��������
Ҳ�Ҳ�����С��ɽ��̳��\n",
        }) );
	
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.dimo" :),
		(: perform_action, "unarmed.renmo" :),
		(: perform_action, "unarmed.tianmo" :),
		(: exert_function, "mihun" :),
        }) );

        
        set("combat_exp", 999999);

        set_skill("unarmed", 120);
        set_skill("throwing", 100);
		set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("demon-force", 100);
        set_skill("demon-strike", 80);
        set_skill("demon-steps", 100);
		set_skill("parry",100);
	
		set_skill("meihua-biao",100);
		map_skill("parry","meihua-biao");
		map_skill("throwing", "meihua-biao");
	    map_skill("unarmed", "demon-strike");
        map_skill("dodge", "demon-steps");
		map_skill("force","demon-force");

        setup();

        carry_object(__DIR__"obj/stone")->wield();
        carry_object(__DIR__"obj/highhat")->wear();
        carry_object(__DIR__"obj/greenrobe")->wear();
}

void init()
{
        object me;
        me = this_player();
        
        ::init();
        if( REWARD_D->riddle_check( me, "��ȡ��ɲ"))
        {
        	remove_call_out("chase_him");
        	call_out("chase_him", 1,me );
		}

}

void chase_him(object me)
{
		if (!me || environment(me) != environment()) return;
			
        message_vision("$N��$n�ȵ�������͵�����̵���ɲ�ƣ�������\n",this_object(),me);
        kill_ob(me);
        me->kill_ob(this_object());
		return;
}

int accept_object(object who, object obj)
{
	if( (string) obj->query("name") == "��ɲ��")
	{
    	if (REWARD_D->riddle_check(who,"��ȡ��ɲ") !=5)
    	{
    		command("say ԭ������͵����ɲ�ƣ��������ɣ�");
    		kill_ob(who);
    		who->kill_ob(this_object());
    		return 0;
    	}
    	
    	if (obj->query("fake"))
    	{
    		command("say �󵨣������üٻ���ƭ�Ϸ�");
    		kill_ob(who);
    		who->kill_ob(this_object());
    		return 0;
    	}
    		
    	message_vision("$N��$n�����������ǵ�ǰ�Ӿ�Թ��һ��赣�������\n",this_object(),who);
		who->remove_all_killer();
    	REWARD_D->riddle_done(who, "��ȡ��ɲ", 20,1);
		return 1;		
	}
		
	return 0;
}
