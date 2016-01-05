#include <ansi.h>
inherit NPC;
inherit F_BANKOWNER;
void create()
{
        set_name("�Ϲ�ʮ����", ({ "shier" }) );
        set("title",RED"Ǯׯ����"NOR);
        set("gender", "����" );
        set("age", 22);
        set("richness",5000000);
       
        set("no_arrest",1);
        set("fly_target",1);
        set("long","��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����Ϲ�ʮ������Ǯׯ���١�\n");

        set("combat_exp", 1000000);
        set("attitude", "friendly");

        set("max_atman", 1000);
        set("atman", 1000);             
		set("max_mana", 1000);
        set("mana", 1000);              
	
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("doomstrike", 120);
        set_skill("doomforce", 100);
        set_skill("doomsteps", 120);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");
        
        set("inquiry", ([
                "����" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
                "rob" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
        ]) );

        setup();
        
        carry_object("/obj/armor/cloth")->wear();
}


void init()
{
	::init();
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
	add_action("do_loan","loan");
	add_action("do_show","show");
}

void reset(){
	set("richness",5000000);
}