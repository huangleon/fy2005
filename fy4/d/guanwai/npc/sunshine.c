inherit SMART_NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
    set_name("������", ({ "sunshine" }) );
    set("gender", "Ů��" );
    set("age", 17);
    set("title", HIY "��ɫ��"NOR);
    set("long",
      "һ�������Ů���ӣ����ϴ����·���������������Ⱥ�ˮ������\n��Ҳ��δ����������ʣ������������Ů���ӡ�\n");
    set("attitude", "friendly");
    set("class","legend");
    set("chat_chance", 1);
    set("chat_msg", ({
	"������ͻȻ������Ц�ݣ���Ȼ����ʥĸǡĸ���������ֻ��Ѫ�������ᣬ\n����ȥǰ����Ѫ����������Ů�������������\n",
	"����������һЦ�����Ǹ�С������ȥ�װͰ͵ģ��ı�����Ů�˻�Ҫ����\n",
      }) );
    set("per",30);
    set("combat_exp",4200000);
	set("vendor_goods", ([
	"/obj/generate/commonweapon/40/axe":20,
	"/obj/generate/commonweapon/40/blade":20,
	"/obj/generate/commonweapon/40/fist":20,
	"/obj/generate/commonweapon/40/hammer":20,
	"/obj/generate/commonweapon/40/spear":20,
	"/obj/generate/commonweapon/40/staff":20,
	"/obj/generate/commonweapon/40/sword":20,
	"/obj/generate/commonweapon/40/throwing":20,
	"/obj/generate/commonweapon/40/whip":20,
	]) );

    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	(: auto_smart_fight(20) :),
      }) );

    auto_npc_setup("wang",200,160,1,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
    setup();
    carry_object("/d/jinan/npc/obj/changbao")->wear();
}


void init()
{
    add_action("do_vendor_list", "list");
    ::init();
}


void reset()
{
	set("vendor_goods", ([
	"/obj/generate/commonweapon/40/axe":20,
	"/obj/generate/commonweapon/40/blade":20,
	"/obj/generate/commonweapon/40/fist":20,
	"/obj/generate/commonweapon/40/hammer":20,
	"/obj/generate/commonweapon/40/spear":20,
	"/obj/generate/commonweapon/40/staff":20,
	"/obj/generate/commonweapon/40/sword":20,
	"/obj/generate/commonweapon/40/throwing":20,
	"/obj/generate/commonweapon/40/whip":20,
	]) );
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

