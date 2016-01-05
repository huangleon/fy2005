// banker.c

#include <ansi.h>

inherit NPC;
inherit F_BANKOWNER;

void create()
{
        set_name("�Ϲ�ʮ����", ({ "shisi" }) );
        set("title", RED "Ǯׯ����"NOR);
        set("gender", "����" );
        set("age", 22);
        set("richness",5000000);
        set("no_arrest",1);
        set("long",
                
                "��ԭ�Ϲ����ң��Ҳ���ᣬ��ҵ����ʤ�����Ϲ�ʮ������Ǯׯ���١�\n");

        set("combat_exp", 2000000);
        set("attitude", "friendly");
		
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("doomstrike", 150);
        set_skill("doomsteps", 150);
        
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps");
        
        set("inquiry", ([
                "����" : "����ɽ���������������������Ӱ��ȥ���٣�\n",
                "rob" : "����ɽ���������������������Ӱ��ȥ���٣�\n",
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
	add_action("do_transfer","transfer");
}

void reset(){
	set("richness",5000000);
}