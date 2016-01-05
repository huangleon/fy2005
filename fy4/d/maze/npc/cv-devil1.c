#include <ansi.h>
inherit MAZE_NPC;


void generate_name();
void create()
{	
	generate_name();
        set("race", "Ұ��");
        set("age", 10 + random(20));
        set("long", "���������������Ĺ����֪��ô���䵽�������ϡ��Ź֡�\n");
        set("maze","cave");
		set("target_name","��������");
        if (!random(10))	set("attitude","aggressive");
                
        set("chat_combat_chance", 30);
        set("chat_combat_msg", ({
//              this_object()->name()+"����ֽ���һЩ���������Ļ���\n",
        }) );
	
	set("pursuer",1);
	        
	set("combat_exp", 1000000+random(100000));
	
	set_skill("unarmed",500+random(100));
	set_skill("dodge", 500+random(100));
	set_skill("move", 400+random(100));
	
	setup();
}


void generate_name(){
	string *color = ({HIB, CYN, BLU, WHT, YEL, RED, HIM});
	string *number = ({"��", "��", "��","��",HIW"��", "��", "ʮ��", "��", "��"});
	string *part = ({"β", "ͷ", "��","��","��","��","��", "צ"});
	string *race = ({"����", "��","��Ϻ","��ѻ", "����", "Ы��", "�з", "����","����",
	 "�ڻ�", "����","̫��","����","����","��Ƥ","��","���","��è"});
	set_name( (color[random(sizeof(color))])+(number[random(sizeof(number))]) 
		   + (part[random(sizeof(part))])
		   + "С"
		   + (race[random(sizeof(race))])
		   + NOR, ({ "alchemy devil", "devil" }) );
	
}

int heal_up()
{
	if(environment() && !is_fighting() 
		&& query("startroom") 
		&& file_name(environment()) != query("startroom")) {
		return_home(query("startroom"));
		return 1;
	}
	return ::heal_up() + 1;
}