#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ر�ʿ��", ({ "wulapo garrison", "garrison" }) );
        set("title","������");
        set("long","
���Ǹ�����ִ���س������ֵ�ڱ�����Ȼ��������������������ֵ�ڱ��ǵ�
�书ʵ��ƽ����������������֯���м��ɵ�սʿ��˭Ҳ�����׵��������ǡ�\n"
"[31m�����Ҳ��Ҫ�������ǡ� [32m\n");
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("cor", 40);
        set("combat_exp", 5000000+random(2000000));
        
        set("max_kee",30000);
        set("max_sen",30000);
        set("max_gin",30000);
        set("boss",1);
        
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                "ֵ�ڱ��ȵ�������������������־͸���\n",
                "ֵ�ڱ��ȵ����󵨵��񾹸Ҿܲ������ˣ����ˣ�\n",
		(: perform_action, "spear.suomengchanhun" :),
        }) );
        
        set_skill("unarmed", 300);
        set_skill("spear", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("duanhun-spear",200);
	set_skill("move",500);
	set_skill("puti-steps",200);
	set_skill("changquan",200);

	map_skill("spear","duanhun-spear");
	map_skill("parry","duanhun-spear");
	map_skill("move","puti-steps");
	map_skill("dodge","puti-steps");
	
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        setup();
        carry_object(AREA_FYWALL"npc/obj/longdagger")->wield();
        carry_object(AREA_FYWALL"npc/obj/kiujia")->wear();
}


int do_killing(string arg)
{
    	object player, victim;
    	string id,id_class;
    	player = this_player();
    	if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
    	if(!objectp(victim))
		return notify_fail("����û������ˡ�\n");
    	if(living(victim))
    	{
       		if(userp(victim)&& victim!=player)
        	{
	            	message_vision(HIW"$N����$n�ȵ����󵨿�ͽ,����������ɱ��,����������־͸�!\n"NOR, this_object(), player);
	            	this_object()->kill_ob(player);
	            	player->kill_ob(this_object());
	            	player->start_busy(2);
	            	return 0;
	       	} 
    	}
    return 0;
}


