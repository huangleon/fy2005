#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("�׸����", ({ "baige dizi", "dizi"}) );
        set("title",WHT"������� "NOR);
        set("gender", "����" );
        set("age", 22);
        set("long", "
������̸��ֽ���������������ϣ��Ľ�գ�����ͭ�����廤����
�ְַ׸롢���ǡ���Ȯ�������ֶ档����Ȯ������׷�٣������ǡ�
����ɱ�����׸롱�����񣬾��Ǹ����̽���ݸ�·����Ϣ��\n");
        set("combat_exp", 250000);
        set("attitude", "friendly");
                        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
	
	setup();
	auto_npc_setup("wang",100,65,1,"/obj/weapon/","fighter_w","demon-blade",2);
	carry_object("/obj/armor/cloth",([	
    						"name":  "��ɫ�̷�",
    						"long": "������̽��ڵķ��Ρ�\n",
    						 ]))->wear();
}
