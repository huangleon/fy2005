// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("һ��", ({ "master yi", "master"}) );
        set("nickname", HIM "�ؾ�¥����" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "����" );
        set("class","shaolin");
        set("reward_npc", 1);
        set("difficulty", 15);
        
        set("age", 64);
	set("agi",30);
	set("per", 35);
        set("int",30);
        set("str",55);
        set("fle",60);
        
        
        set("resistance/kee",60);
        set("resistance/gin",60);
        set("resistance/sen",70);
	set("attitude","friendly");
        set("max_force", 1200);
        set("force", 1200);
        set("max_mana",1500);
        set("mana",1500);
        set("force_factor",110);
        
        set("long",
"
���ֲؾ�¥��������ʮ����δ�²ؾ�¥һ��\n"
	);
        create_family("������", 18, "����");
        
        set("combat_exp", 12000000);
	set_temp("apply/damage",200);
	
        set_skill("move", 250);
        set_skill("dodge", 250);
	set_skill("unarmed",200);
	set_skill("puti-steps",200);
	set_skill("xiaochengforce",150);
	set_skill("parry",200);
	set_skill("yizhichan",160);
	set_skill("perception",200);
	set_skill("force",200);
	
        map_skill("dodge", "puti-steps");
        map_skill("move","puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("unarmed", "yizhichan");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.nianhua" :),
        }) );

	
        setup();
        
        carry_object(__DIR__"obj/monk_cloth")->wear();

}
void init()
{
	add_action("do_whisper","whisper");
	::init();
}


int do_whisper(string arg)
{
if (!arg || arg != "�����ˣ�") return 0;
message_vision(HIG"$N�����㼸��˵:��ǰ���и���ʮ���ļһ����ôƭ���ҡ���������\n"NOR,this_object());
message_vision(HIG"$NЦЦ��������Ȼ��Ϳ���ɲ�������������ˣ�\n"NOR,this_object());
this_object()->kill_ob(this_player());
return 1;
}

