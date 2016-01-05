#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���������", ({ "dragon dizi","dizi" }) );
        set("long",
                "����һλ������ר�ŵ��ο���֮��ĵ��ӡ�\n");
        set("attitude", "aggressive");
      
        set("combat_exp", 1200000);
        set_skill("sword", 150);
        set_skill("parry", 170);
        set_skill("dodge", 170);
        set_skill("move",  150);
        set_skill("huanhua-sword",120);
        set_skill("huanhua-steps",120);
        
        map_skill("sword","huanhua-sword");
        map_skill("parry","huanhua-sword");
        map_skill("dodge","huanhua-steps");
        
        setup();
        carry_object("obj/armor/cloth")->wear();
        carry_object("obj/weapon/sword")->wield();
}

