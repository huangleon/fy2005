// 8����NPC������4������99.9%�����˺�������chi you��chi you����ʱ��busy 30+...

#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("��", ({ "blue","zhan lan" }) );
        set("gender", "Ů��");
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
		set("no_fly",1);
		set("no_arrest",1);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(100) :),    
        }) );

	auto_npc_setup("neon",300,220,0,"/obj/weapon/","fighter_w","chillblade",4);
       setup();    
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/blade/glacier")->wield();
	carry_object("/questnpc/obj/leaf");
	setup();
}

/*
update here;clone /d/bashan/npc/yawnboy;update /adm/daemons/smartd;update /std/char/npc_041;update /d/bashan/npc/chillblade;clone;call blue->ccommand(kill sinny)
*/
/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
