#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("���ǵ���", ({ "huilang dizi", "dizi"}) );
        set("title",WHT"������� "NOR);
        set("gender", "����" );
        set("group","demon");
        set("age", 22);
        set("long", "
������̸��ֽ���������������ϣ��Ľ�գ�����ͭ�����廤����
�ְַ׸롢���ǡ���Ȯ�������ֶ档����Ȯ������׷�٣������ǡ�
����ɱ�����׸롱�����񣬾��Ǹ����̽���ݸ�·����Ϣ��\n");
        set("combat_exp", 2300000);
        set("attitude", "friendly");
                        
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
     }) ); 		

	
	auto_npc_setup("wang",170,140,1,"/obj/weapon/","fighter_w","assassin-hammer",1);
	setup();
	carry_object("/obj/armor/cloth",([	
    						"name":  "��ɫ�̷�",
    						"long": "������̽��ڵķ��Ρ�\n",
    						 ]))->wear();
}
