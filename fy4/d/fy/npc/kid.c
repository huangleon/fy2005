#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name("С����", ({ "opera waiter" }) );
	set("gender", "����" );
	set("cor",10);
	set("age", 12);
    set("title", CYN"��԰����"NOR);
	set("long",
		"һ����û���ɵ�С���ͣ�����ϷԺ�ﵱ�ࡣ\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	set("rank_info/respect", "С�ϵ�");
	set("vendor_goods", ([
		__DIR__"obj/peanut" : 50,
		__DIR__"obj/tea" : 50,
	]) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	::init();
	add_action("do_vendor_list", "list");
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
