inherit NPC;
#include <ansi.h>

void create()
{
    	object armor;
    	set_name( "С���" , ({ "ni gu" }) );
    	set("gender", "Ů��");
    	set("title", "�ɹ���");
    	set("nickname", "��������");
    
    	set("age", 18);
    	set("per",45);
    	set("long", "һ��С������ļ�����ã�ò���绨��\n");
    	set("combat_exp", 2300000);
    	set("score", 200);
    	set("class", "huangshan");

    	set("no_busy",4);
    	set("fly_target",1);
    
       	set("atman", 1000);
    	set("max_atman", 1000);
    	

    	set_skill("force", 180);
    	set_skill("move", 100);
    	set_skill("unarmed", 150);
    	set_skill("tenderzhi",150);
    	set_skill("parry", 140);
    	set_skill("dodge", 150);
    	set_skill("lotusforce", 120);
    	set_skill("liuquan-steps", 120);
    	
    	map_skill("unarmed", "tenderzhi");
    	map_skill("force", "lotusforce");
    	map_skill("dodge", "liuquan-steps");

    	setup();
    	armor=new("/obj/armor/cloth");
		armor->set_name(WHT"��ɫ������"NOR,({"cloth"}) );
		armor->move(this_object());
		armor->wear();
}


