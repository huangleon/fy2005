//Created by justdoit at June 2001 
//All Rights Reserved ^_^

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�����" , ({ "big white shark" , "big shark" , "shark" }) );
	set("nickname", HIW "����ħ"NOR);
	set("race", "����");
	set("age", 10);
	set("long", "����һֻ�����ޱȵ����˴���衣\n");
	
	set("bellicosity", 3000 );
	set("combat_exp", 1000000+random(1000000));
	
        set("attitude", "aggressive");
	
	set_temp("apply/attack", 300);
	set_temp("apply/armor",  200);
	set_temp("apply/dodge",  300);
	set_temp("apply/damage", 50);
	setup();
}


void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) ) 
	  {
	    kill_ob(ob);
          }
}


void die()
{
	object killer;
	if ( objectp(killer = query_temp("last_damage_from")) )
	     killer->set("marks/killed_shark", 1);
	::die();
}	