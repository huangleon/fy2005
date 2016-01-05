#include <ansi.h>
inherit NPC;

void create()
{

		set_name("Ѳ���ڹ�", ({ "patrolling officer" }) );
		set("long","���ܹܷ��Ƴ�����ΰ�,ר�žв��������˵Ĵ�ͽ��\n");
        set("attitude", "heroism");
        set("class","fighter");
        set("combat_exp", 12000000+random(3000000));
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
			(: perform_action, "sword.hunranyijian" :),
        }) );

        set_skill("unarmed", 200+random(100));
        set_skill("sword", 200+random(50));
        set_skill("parry", 200+random(100));
        set_skill("dodge", 200+random(100));
        set_skill("move", 600+random(100));
        set_skill("doomsteps",200);
		set_skill("doomsword",200);
		set_skill("doomstrike",200);
	
		map_skill("sword","doomsword");
		map_skill("dodge","doomsteps");
        map_skill("parry","doomsword");
        map_skill("move","doomsteps");
        map_skill("unarmed","doomstrike");
        
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/move", 100);
        setup();
		carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}



int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIW + name() + "�ȵ�����ʲô�����ٿ�����һ��ץ������\n"
		+ name() + "һת�������ǵ��뿪�ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
