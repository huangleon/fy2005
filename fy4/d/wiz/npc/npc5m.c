inherit NPC;
#include <ansi.h> 

void create()
{
        set_name("���פ���������", ({"wu"}));
        set("long", "һ�������ܸɣ��书��ǿ���ͷ���������\n");
        set("gender","����");
				set("title",  "��Ǯ��"HIR" �ͷ�������"NOR);
        set("class", "legend");   
           
        set("combat_exp", 6000000);
	
	set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry",200);
        set_skill("blade", 200);
        set_skill("shortsong-blade",200);
        set_skill("force", 150);
        set_skill("qidaoforce", 170);
        set_skill("fall-steps", 150);
        set_skill("move",200);
	set_skill("iron-cloth", 150);
	set_skill("xisui", 80);
	
	
	map_skill("iron-cloth", "xisui");
	map_skill("blade","shortsong-blade");
	map_skill("parry", "shortsong-blade");
        map_skill("unarmed", "qidaoforce");
        map_skill("dodge", "fall-steps");
	map_skill("force","qidaoforce");
	map_skill("move","fall-steps");

	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
		(: perform_action, "blade.duangechangmeng" :),
        }) );

        setup();
        carry_object("/obj/armor/cloth",([	
    						"name":  HIY"���ƽ���"NOR,
    						"long": "һ���ƶг��ۣ������Ƿ���\n",
    						 ]))->wear();    
	carry_object("/obj/weapon/blade",([	
    						"base_damage":  100,
    						 ]))->wield();    
}
