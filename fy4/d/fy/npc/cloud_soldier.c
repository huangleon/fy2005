#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "fengyun garrison", "garrison" }) );
        set("long","
���Ǹ�����ִ���س���������䣬��Ȼ�������������������������ǵ�
�书ʵ��ƽ����������������֯���м��ɵ�սʿ��˭Ҳ�����׵��������ǡ�\n"
"[31m�����Ҳ��Ҫ�������ǡ� [32m\n");
        set("attitude", "heroism");
	set("class", "shaolin");
        set("vendetta_mark", "authority");
        set("cor", 40);
        set("combat_exp", 5000000+random(2000000));
        
        set("max_kee",30000);
        set("max_sen",30000);
        set("max_gin",30000);
        set("boss",1);
        
        set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                "����ȵ�������������������־͸���\n",
                "����ȵ����󵨵��񾹸Ҿܲ������ˣ����ˣ�\n",
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

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/spear")->wield();
}

void init() {
	object ob;
	::init();
	if(interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
//	add_action("do_killing", "kill");
}

void greeting(object ob) {
	if(!ob || environment(ob) != environment()) {
		return;
	}
	switch( random(10)){
		case 0:
			say("�����������µش�����һ�����ֺ�ǽ�����Ĺٸ�ͨ�����˶ԣ������ֹ�������������ˣ�\n");
			break;
		case 1:
			say("���俴����һ�ۣ������ֹ�������������һ���������\n");
			break;
		case 2:
			say("��������ȵ���վס����������̧������\n");
			break;
	}
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

int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 100000 ) {
                        say("����Ǻǵ�Ц������˵����˵��������\n");
                        who->set("vendetta/authority", 0);
                        who->remove_all_killer();
                        this_object()->command("follow none");
                        return 1;
                } else {
                    say("����˵�������Ǯ��������ү�ȾƵ��أ�\n");
                        return 0;
                }
        return 0;
} 

