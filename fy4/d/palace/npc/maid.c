// CYNGIRL.C
inherit NPC;
#include <ansi.h>
void create()
{       
        object armor;
        set_name("����Ѿ��", ({ "maid" }) );
        set("nickname",HIR "������" NOR);
        set("long", "�������������С��ȹ���������ϸ��˵�����Ѿ�ߡ�\n");
        set("age", 16);
        set("per",20);
        set("cps",40);
        set("gender", "Ů��");
        set("attitude", "friendly");
        set("combat_exp", 3500000);  
	
        set_skill("ill-quan",170);
        set_skill("unarmed",200);
        set_skill("force",150);
        set_skill("jiayiforce",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("tie-steps",150);
	set_skill("sword",150);
	set_skill("fy-sword",150);
	  
        map_skill("force","jiayiforce");
        map_skill("dodge","tie-steps");
        map_skill("unarmed","ill-quan");                         
        map_skill("sword","fy-sword");
        map_skill("parry","fy-sword");
        map_skill("move","tie-steps");
        
        set("no_busy",4);

        setup();
        
        armor=new("/obj/armor/cloth");
	armor->set_name(RED"С��ȹ"NOR,({"skirt"}) );
	armor->move(this_object());
	armor->wear();
        carry_object("/obj/weapon/sword")->wield();

}
