inherit NPC;
#include <ansi.h>

int do_create(string arg);

void create()
{
        set_name(HIW"���ܹ�����������"NOR, ({ "ke" }) );
        set("title",YEL"̽��¥"NOR);
        set("long", "���ܹ����������ģ�ʹ��make��list���\n");
        set("gender", "����" );
        
        set("age", 132);
        set("NO_KILL","ɱ���ã�\n");
        set("no_fly",1);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );	
        set("inquiry", ([

        ]));
        set("combat_exp", 10000000);
        set("attitude", "friendly");
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init() {
		add_action("do_create","make");
		add_action("do_list", "list");
}

int do_list(string arg){
	string *npc_list = ({ "npc_bas", "npc_mid", "npc_adv", "npc_041", "npc_ann" });
	object me;
	int num, i;
	mapping *npclist;
		
	me = this_player();
	
	if (!arg || sscanf(arg, "%d", num)!=1) {
		tell_object(me, "NPC�����̶ȣ�pick 1-5 ��only 1 has been tested so far��\n");
		return 1;
	}
	
	if (num <1 || num>5) {
		tell_object(me, "pick 1-5 \n");
		return 1;
	}
	num--;
	
	write (" Listing NPC " + npc_list[num] + "\n");

	npclist = ("/std/char/"+npc_list[num])->npclist();
	
	for (i = 0; i< sizeof (npclist);i++) 
		write(sprintf("%s  ",npclist[i]["npc"]));
	
	write(WHT" TOTAL NPC IN THIS LIST IS " + sizeof(npclist) + "\n"NOR);
	
	return 1;
}
	


int do_create(string arg){
	object me, another;
	int basic, special, level, exp, chance;
	string char_type, my_char;
	
	me=this_player();
	
	if (!wizardp(me)) {
		message_vision("$N˵��С���Ӳ�Ҫ���ʡ�\n",this_object());
		return 1;
	}

	if (!arg) {
		tell_object(me,"format is make exp(k):basic_skill_level:special_skill_level:char_group:char_name:difficulty:perform_chance\n");
		return 1;
	}
	if (sscanf(arg, "%d:%d:%d:%s:%s:%d:%d", exp, basic, special, char_type, my_char, level, chance) !=7) {
			tell_object(me,"format is make exp(k):basic_skill_level:special_skill_level:char_group:char_name:difficulty:perform_chance\n");
		return 1;
	}
	write ( "experience sets to "+ exp*1000 +"\n");
	write ( "basic skill set to " + basic + "\n");
	write ( "special skill set to " + special + "\n");
	write ( "char_type (fighter/caster) is " + char_type + "\n");
	write ( "char_specified_type is " + my_char + "\n");
	write (	" my perform chance is " + chance + "\n");
	write ( " NPC is picked from List " + level + "\n\n\n");
	    
    another = new(__DIR__"fighter1");	
	another->move(environment(this_object()));
    
    another->set("combat_exp", exp*1000);
    
    
/*	string name:	NPC id
	basic:		basic skill level			
	special:	special skill level
	auto_weapon:	1: auto find weapon, 0: will be set in NPC file
	weapon_dir:	auto_weapon directory
	char_type:	figher/caster/
	my_char:	exact name of the NPC, the name refers to the one in npclist
	level:		which npclist we should choose
*/
    
    SMART_D->auto_npc_setup(another, "�޺����м�", 
					basic, special, 
					1, "/obj/weapon/", 
					char_type, my_char, 
					level); 
    
    another->set("name", another->query("myname"));
    another->set("fight_chance", chance);
    "/feature/nada"->reset_npc(another);
    another->full_me();
      	
	message("vision",another->query("name")+CYN"˵��:�������ӵܽ���־�������������ʱ�������룬��������һ
Щ������������ݱ�����Ҳ�ã���Ҫ�ѽ��������������ǻ�����֪���ǲ���
�õ���������������ʮ����֮"+another->query("name")
+ "("+ another->query("npc")+ ")"+CYN"��ֻ���ʦ�ͽ̣�һ����Ը����\n\n"NOR,environment(this_object()));              	
	return 1;
}


