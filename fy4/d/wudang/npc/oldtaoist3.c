#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;

	string tt;
	tt = "����";

        set_name(tt+"����", ({"taoist elder","taoist","elder"}) );
        set("gender", "����" );
		set("title","�䵱���");
		set("nickname",HIY"���"NOR);
		set("age",71);
		set("long","��ͯ�պ׷����ɷ���ǣ�һ��������˵�ģ����\n�����䵱�ɾò������ĳ������\n");
        set("combat_exp", 9000000);
        set("attitude", "peaceful");

		set("group","wudang");
			set("max_kee", 30000);
		set("max_gin", 30000);
		set("max_sen", 30000);
		
		set("no_fly",1);
		set("no_arrest",1);
       
	auto_npc_setup("wudang taoist",300,220,0,"/obj/weapon/","fighter_w","taiji-sword",2);

	setup();

     	tt=HIC+tt+"��"+NOR;
	   weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(tt, ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("���ȵ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();


}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
