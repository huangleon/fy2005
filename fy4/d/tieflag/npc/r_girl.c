// REDe.c
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(RED"���¹�Ů"NOR, ({ "red lady","lady" }) );
        set("long", "������ɴ��˿��������˪����˿Ʈ�\n");
        set("nickname",WHT"�������"NOR);
        set("age", 26);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("combat_exp", 4400000);  
        
        set_skill("force", 180);
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
	set_skill("parry",200);
	set_skill("move", 200);
	set_skill("lingxi-zhi",161);
	set_skill("tie-steps",160);
	set_skill("perception",220);
	
	map_skill("unarmed","lingxi-zhi");
	map_skill("dodge","tie-steps");
	map_skill("move","tie-steps");

        setup();
        armor=new(__DIR__"obj/corclot");
	armor->set_name(RED"��˿��"NOR,({"red cloth","cloth"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corclasp");
	armor->set_name(RED"��˿��"NOR,({"red bangle","bangle"}) );
	armor->move(this_object());
	armor->wear();	
	armor=new(__DIR__"obj/corgirt");
	armor->set_name(RED"��˿��"NOR,({"red belt","belt"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corhat");
	armor->set_name(RED"��˿ñ"NOR,({"red hat","hat"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corboot");
	armor->set_name(RED"��˿Ь"NOR,({"red boot","boot"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corribb");
	armor->set_name(RED"��˿��"NOR,({"red ribbon","ribbon"}) );
	armor->move(this_object());
	armor->wear();
}

