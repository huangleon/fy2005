#include <ansi.h>
inherit F_VENDOR;
inherit NPC;
void create()
{
        set_name("�ϰ���", ({ "pretty woman","woman" }) );
        set("gender", "Ů��" );
        set("title", "�����ȴ�");
        set("nickname",HIR"��Ư����"NOR);
        set("age", 37);
        set("long", 
"˵������Ư�����ϰ���������ţ�����ȷ�Ǹ��ǳ�����Ů�ˣ�����
��ü�������۾����촽��������������������Ǹ���͸�˵�ˮ��
�ң�����˭�������̲�ס��ҧһ�ڡ�\n");
        set("combat_exp", 350000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "�ϰ���ԳԵ�һЦ��û�м���½С����ˣ�����ôҲ�����뵽��������üë
��Ȼ�ǳ������ϵġ�\n",
        "�ϰ���޺޵�����ǰЩ���Ӻ�������üë�ڷ���������ƣ����Ǹ�����Ȼ
����ʲô��û�У�ʲô�׶����ԣ��������ˡ�\n",
        "�ϰ�������һЦ������������쵰�����£��ҷǵ�һ��Ҳ��������ֱ��Խ
��Խ��Ϳ��\n",
	}) );
        set("attitude", "friendly");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("zhaixin-claw",50);
        set_skill("anxiang-steps",50);
        set_skill("parry",50);
        
        map_skill("unarmed","zhaixin-claw");
        map_skill("dodge","anxiang-steps");
        
			set("vendor_goods", ([
			"/obj/generate/commonweapon/30/axe":20,
			"/obj/generate/commonweapon/30/blade":20,
			"/obj/generate/commonweapon/30/fist":20,
			"/obj/generate/commonweapon/30/hammer":20,
			"/obj/generate/commonweapon/30/spear":20,
			"/obj/generate/commonweapon/30/staff":20,
			"/obj/generate/commonweapon/30/sword":20,
			"/obj/generate/commonweapon/30/throwing":20,
			"/obj/generate/commonweapon/30/whip":20,
			]) );
        setup();
        carry_object("/d/fugui/npc/obj/w_skirt3")->wear();
}
int accept_fight(object me)
{
        command("say СŮ�����е���������ǧ�����⣬СŮ�Ӹ�����Ҿ������ǡ�\n");
        return 0;
}

void init()
{
    ::init();
    add_action("do_vendor_list", "list");
}

void reset()
{
	set("vendor_goods", ([
	"/obj/generate/commonweapon/30/axe":20,
	"/obj/generate/commonweapon/30/blade":20,
	"/obj/generate/commonweapon/30/fist":20,
	"/obj/generate/commonweapon/30/hammer":20,
	"/obj/generate/commonweapon/30/spear":20,
	"/obj/generate/commonweapon/30/staff":20,
	"/obj/generate/commonweapon/30/sword":20,
	"/obj/generate/commonweapon/30/throwing":20,
	"/obj/generate/commonweapon/30/whip":20,
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

