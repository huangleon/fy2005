#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��Թ����", ({ "sad woman","woman" }) );
        set("gender", "Ů��" );
        set("long",
                "һ����ü�����������ѻ��ĸ��ˡ�\n"
                );
        set("title", WHT"���Ĺ���"NOR);
        set("attitude", "peaceful");
    	set("age", 25);
        set("per", 20);
        set("combat_exp", 1200000);
        
        set_temp("apply/damage", 50);

        set("chat_chance", 1);
        set("chat_msg", ({
                "��Թ������������֪��,֪��Ӧ���̷ʺ��ݣ�\n",
                }) );

        set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
    	set_skill("doomstrike", 100);
    	set_skill("doomsteps", 100);
    	
    	map_skill("unarmed", "doomstrike");
    	map_skill("dodge", "doomsteps");
        
        
        setup();
        carry_object("/d/qianfo/npc/obj/lady_dress")->wear();
}

