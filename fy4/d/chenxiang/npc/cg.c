
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�سǹٱ�", ({ "chenxiang garrison", "garrison" }) );
        set("long","
���Ǹ�����ִ���س�����ķ������Ȼ���������������������ٱ��ǵ��书
ʵ��ƽ����������������֯���м��ɵ�սʿ��˭Ҳ�����׵��������ǡ�\n"
"[31m�����Ҳ��Ҫ�������ǡ� [32m\n");
        set("attitude", "heroism");
        set("pursuer", 1);
        set("vendetta_mark", "authority");
        set("combat_exp", 4000000+random(4000000));
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                "�ٱ��ȵ�������������������־͸���\n",
                "�ٱ��ȵ����󵨵��񾹸Ҿܲ������ˣ����ˣ�\n",
                (: perform_action, "spear.suomengchanhun" :),
        }) );

        set_skill("unarmed", 200);
        set_skill("spear", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("move", 200);
        set_skill("changquan",200);
        set_skill("puti-steps",200);
	set_skill("duanhun-spear",151);
	
	map_skill("dodge","puti-steps");
	map_skill("move","puti-steps");
	map_skill("parry","duanhun-spear");
	map_skill("unarmed","changquan");
	map_skill("spear","duanhun-spear");
	
        
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(AREA_FY"npc/obj/spear")->wield();
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


void init()
{	
	::init();
//	add_action("do_killing", "kill");

}


int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
//		command("say ok");
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}

