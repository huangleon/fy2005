// 8����NPC������4������99.9%�����˺�������chi you��chi you����ʱ��busy 30+...

#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("��", ({ "neon","foxgirl" }) );
        set("gender", "Ů��");
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
		set("no_fly",1);
		set("no_arrest",1);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );

	auto_npc_setup("neon",400,200,1,"/obj/weapon/","fighter_w","thunderwhip",1);
       setup();    
	carry_object("/obj/armor/cloth")->wear();
	setup();
}

/*
call neon->ccommand(kill chi you);call neon 2->ccommand(kill chi you);call neon 3->ccommand(kill chi you);call neon 4->ccommand(kill chi you);call neon 5->ccommand(kill chi you);call neon 6->ccommand(kill chi you);call neon 8->ccommand(kill chi you);call neon 7->ccommand(kill chi you);
*/
/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
