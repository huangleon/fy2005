// BLUGIRL.C
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(BLU"������Ů"NOR, ({ "blue girl","girl" }) );
        set("long", "������ɴ��˿��������˪����˿Ʈ�\n");
        set("age", 16);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("combat_exp", 500000);  
	
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("move",100);
	set_skill("ill-quan",70);
	set_skill("tie-steps",70);
	set_skill("unarmed",100);
	
	map_skill("dodge","tie-steps");
	map_skill("unarmed","ill-quan");
	
        setup();
        armor=new(__DIR__"obj/corclot");
	armor->set_name(BLU"����"NOR,({"blue cloth","cloth"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corclasp");
	armor->set_name(BLU"����"NOR,({"blue bangle","bangle"}) );
	armor->move(this_object());
	armor->wear();	
	armor=new(__DIR__"obj/corgirt");
	armor->set_name(BLU"����"NOR,({"blue belt","belt"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corhat");
	armor->set_name(BLU"��ñ"NOR,({"blue hat","hat"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corboot");
	armor->set_name(BLU"��Ь"NOR,({"blue boot","boot"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corribb");
	armor->set_name(BLU"����"NOR,({"blue ribbon","ribbon"}) );
	armor->move(this_object());
	armor->wear();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
   	mixed foo;
   	object *inv;
   	object dress; 
   	int i; 
     	if (random(victim->query("combat_exp"))<100000) 
        {  
           inv = all_inventory(victim);
           if (sizeof(inv)==0) return;
           for (i=0;i<sizeof(inv);i++){
             dress=inv[i];
             if ((string)dress->query("equipped")=="worn" ) break;
            }
           if ((string)dress->query("equipped")=="worn" )
           {
		dress->unequip();
              victim->set_temp("mark/striped",1);     
              return victim->name()+YEL "���ϵ�"+dress->name()+"��$N����������\n"NOR;
           } 
          };   
        return;
}

