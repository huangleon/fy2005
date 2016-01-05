// banker.c

#include <ansi.h>

inherit NPC;
inherit F_BANKOWNER;

void create()
{
        set_name("�Ϲ�ʮһ��", ({ "nangong shiyi","nangong","shiyi" }) );
        set("title", RED "Ǯׯ����"NOR);
        set("gender", "����" );
	set("class", "fighter");
        set("age", 22);
        set("richness",5000000);
	set("fly_target",1);
        set("no_arrest",1);
        set("long",
                
                "��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����Ϲ�ʮһ����Ǯׯ����\n");

        set("combat_exp", 1000000);
        set("attitude", "friendly");

        set("max_atman", 1000); 
        set("atman", 1000);             
        set("max_mana", 1000);          
        set("mana", 1000);              

        set("chat_chance", 3 );
        set("chat_msg", ({
        }) );

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({

        }) );

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("doomstrike", 100);
        set_skill("doomforce", 100);
        set_skill("doomsteps", 100);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");
        
        set("inquiry", ([
                "����" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
                "rob" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
        ]) );

        setup();
        
        carry_object(__DIR__"obj/jinzhuang")->wear();

}

void init()
{
	::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
	add_action("do_loan","loan");
	add_action("do_transfer","transfer");
}

void reset(){
	set("richness",5000000);
}