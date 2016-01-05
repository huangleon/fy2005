// devil.c

#include <ansi.h>

inherit NPC;
void emerge(object, int);
void generate_name();
void create()
{	
	generate_name();
        set("race", "Ұ��");
        set("age", 10 + random(20));
        set("long", "һֻϡ��Źֵ����Σ�����������ʲô������\n");
        set("max_kee", 800);
        set("max_qin", 800);
        set("max_sen", 200);
		set("str", 20 + random(40));
		set("cor",50);
        set("limbs", ({ "ͷ��", "����", "β��","צ��" }) );
        set("verbs", ({ "bite","claw"}) );
                set("attitude","heroism");
                
        set("chat_combat_chance", 30);
        set("chat_combat_msg", ({
                this_object()->name()+"����ֽ���һЩ���������Ļ���\n",
        }) );


	set("combat_exp", 1100000);
	set_skill("unarmed", 30);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("move", 50);

	setup();


}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	
	message("vision",
         name() + "������һ���ҽУ��굽ʲô�����ﲻ���ˡ�\n" , environment(),
		this_object() );
  
	destruct(this_object());
}

void emerge(object who, int level)
{
	set_skill("unarmed", 100 + random(level));
	set_skill("parry", 100 + random(level));
	set_skill("dodge", 100 + random(level));
	set_skill("move", 100 + random(level));
	set("combat_exp", 10000 + random(level*level*level));
		
	kill_ob(who);
	who->kill_ob(this_object());
	set("possessed",who);
}

void generate_name(){
	string *color = ({HIB, CYN, BLU, WHT, YEL, RED, HIM});
	string *number = ({"��", "��", "��","��",HIW"��", "��", "ʮ��", "��", "��"});
	string *part = ({"β", "ͷ", "��","��","��","��","��", "צ"});
	string *race = ({"����", "��","��Ϻ","��ѻ", "����", "Ы��", "�з", "����","����",
	 "�ڻ�", "����","̫��","����","����","��Ƥ","��","���","��è"});
	set_name( (color[random(sizeof(color))])+(number[random(sizeof(number))]) 
		   + (part[random(sizeof(part))])
		   + (race[random(sizeof(race))])
		   + NOR, ({ "alchemy devil", "devil" }) );
	
}
