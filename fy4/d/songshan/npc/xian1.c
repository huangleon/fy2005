inherit NPC;
#include <ansi.h>

void create()
{
	object armor;
	set_name("�޺���", ({ "wu hensheng","wu"}) );
	set("gender", "����" );
	set("title",HIW"��������"NOR);
	set("nickname",HIR"�޼�����"NOR);
	set("age", 70+random(10));
	set("class","lama");        
	set("long",
		"һ��������������ò��Զ�������\n"
		);
	set("class","shaolin");
        set("combat_exp", 7600000);
        set("score", random(90000));
        set("reward_npc", 1);
	set("difficulty",5);
	
	set("attitude","friendly");
	set("chat_chance", 1);
        set("chat_msg", ({
                "�޺���������ǧɽ��ѩ����ɳ����Ϊ��ϯΪ�ң���ϡ�������ѱ档������\n",
                }) );
        
        set_skill("perception",200);
	set_skill("iron-cloth", 200);
  	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("lingxi-zhi", 200);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("five-steps",200);
	set_skill("move",200);
	set_skill("dodge",200);
	set_skill("dual-attack",300);
	set_temp("apply/haste",300);
	
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "bolomiduo");
    	map_skill("dodge","five-steps");
    	map_skill("move","five-steps");
    	
        add_temp("apply/iron-cloth", 200);
	
	setup();
        armor=new("/obj/armor/cloth");
	armor->set_name("һ����Ⱦ�İ���",({"cloth"}) );
	armor->move(this_object());
	armor->wear();
}
