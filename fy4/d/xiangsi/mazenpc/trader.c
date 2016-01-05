inherit NPC;
inherit F_BANKOWNER;
inherit F_PAWNOWNER;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("С��", ({ "xiao kuangdao","kuangdao" }) );
        set("gender", "����" );
        set("age", 31);
        set("title", CYN"�����λ�"NOR);
		set("nickname",HIY"�Ұ�С����"NOR);
		set("long",CYN"\nС��˵������ӭ���������̵ꡣ
С��˵�������������ԣ�
��Ϣ(Buy incense from geese)
����ҩ��(Buy herb from geese)
��������(Buy weapon from geese)
�䵱��Ʒ(Pawn/Redeem)
���ۻ���(Sell)
��ȡ��Ǯ(Deposit/Withdraw)
���浵��(Save)\n\n"NOR);
        set("combat_exp", 5000000);
        set("attitude", "friendly");
		set("class","moon");
        set("per",30);
        set("vendor_goods", ([
		
		__DIR__"obj/incense" : 10,
/*		"/obj/medicine/herb_annie_buff1" : 30,
		"/obj/medicine/herb_annie_buff2" : 30,
		"/obj/medicine/herb_annie_buff3" : 30,
		"/obj/medicine/herb_annie_buff4" : 30,
		"/obj/medicine/herb_annie_buff5" : 30,*/
		
		]) );
        set_skill("unarmed",1);
        set_skill("dodge",1);
        set_skill("parry",1);
        set_skill("lingxi-zhi",300);
        set_skill("stormdance",261);

        set_skill("force",200);
        set_skill("snowforce",200);

		map_skill("force","snowforce");
		map_skill("unarmed","lingxi-zhi");
		map_skill("dodge","stormdance");

        setup();
}

int	is_ghost() { return 1;}

void init()
{
	::init();
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
	add_action("do_sell", "sell");
	add_action("do_redeem", "redeem");
	add_action("do_vendor_list","list");
	add_action("do_loan","loan");
	add_action("do_convert", "convert");
	add_action("do_deposit", "deposit");
	add_action("do_balance", "balance");
	add_action("do_withdraw", "withdraw");
}



void reset()
{
        set("vendor_goods", ([
		__DIR__"obj/incense" : 10,
		"/obj/medicine/herb_annie_buff1" : 30,
		"/obj/medicine/herb_annie_buff2" : 30,
		"/obj/medicine/herb_annie_buff3" : 30,
		"/obj/medicine/herb_annie_buff4" : 30,
		"/obj/medicine/herb_annie_buff5" : 30,
        ]) );
	set("richness",5000000);
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
