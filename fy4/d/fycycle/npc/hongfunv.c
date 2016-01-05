inherit NPC;
#include <ansi.h>
#include <combat.h>
void create()
{
        set_name("������Ů", ({ "redcloth girl","girl" }) );
        set("gender", "Ů��" );
        set("long", "һ������ȥ��ʮ�������Ů������ͤͤ�������ݣ�
���վ�ã������з糾֮ɫ����һ��Ӣ��������Ľ���ѡ�\n");

        set("class", "legend" );
        set("age", 21);
        set("per", 40);
        
        set("max_kee", 2500);
        set("max_gin", 2000);
        set("max_sen", 2000);

        set("force_factor", 30);
        set("no_arrest", 1);
        set("attitude", "friendly");
		set("combat_exp", 300000);        

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 50);
        
        set("chat_chance", 1);
        set("chat_msg", ({
    		"������Ů����������ͷ��һ�Բ�����\n",
        }) );
        
        set_skill("spring-water", 1);
        set_skill("fall-steps", 120);
        set_skill("diesword", 70);
        set_skill("sword", 120);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("iron-cloth", 10);
        set_skill("parry",120);
        
        map_skill("parry","diesword");
        map_skill("sword","diesword");
		map_skill("iron-cloth","spring-water");
      	map_skill("dodge","fall-steps");
                
        setup();
        carry_object("/d/fugui/npc/obj/redcloth")->wear();
        carry_object("/obj/weapon/sword_l")->wield();
}

void win_enemy(object obj){
	object qiuran;
	qiuran = present("qiuran han", environment(this_object()));

	if (obj->query_temp("marks/fight_hongfunv"))	{
		obj->delete_temp("marks/fight_hongfunv");
		if(objectp(qiuran)){
			qiuran->win_fight(obj);
		}	
	}
}

void lose_enemy(object obj){
	object qiuran;
	qiuran = present("qiuran han", environment(this_object()));
			
	if (obj->query_temp("marks/fight_hongfunv")) {
		obj->delete_temp("marks/fight_hongfunv");
		if(objectp(qiuran)){
			qiuran->lose_fight(obj);
		}		
	}
}

int accept_fight(object me){
	if(this_object()->is_fighting()){
		message_vision("$N����$nһ�ۣ�΢΢һЦ�����ٴ�Ƭ�̡�\n", this_object(), me);
		return 0;
	}
	if(me->query_temp("marks/fight_hongfunv")) {
		message_vision("$Ņ��ͷ������$nһ�ۣ����˸��򸣵����룡\n", this_object(), me);
    		full_me();
    		return 1;
	} else {
		return 0;
	}
}

void die()
{
    	object me;
    
    	if(objectp(me = query_temp("last_damage_from")) && !query("leaving")){
	    	message_vision("$N�������Ծȥ��΢һ��������ɫ�ָֻ��˺���\n",this_object(),me);
    	} 
    	full_me();
}


void unconcious()
{
        die();
}
